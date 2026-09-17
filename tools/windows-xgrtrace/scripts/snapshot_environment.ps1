param(
    [Parameter(Mandatory = $true)]
    [string]$OutputPath,
    [int]$ProcessId = 0,
    [string]$XGameRuntimePath
)

function Get-PeMachine([string]$Path) {
    if (-not $Path -or -not (Test-Path -LiteralPath $Path)) { return $null }
    try {
        $bytes = [System.IO.File]::ReadAllBytes($Path)
        $peOffset = [BitConverter]::ToInt32($bytes, 0x3c)
        return ('0x{0:X4}' -f [BitConverter]::ToUInt16($bytes, $peOffset + 4))
    } catch { return $null }
}

function Get-SafeFileName([string]$Path) {
    if (-not $Path) { return $null }
    try { return [System.IO.Path]::GetFileName($Path) } catch { return $null }
}

$version = Get-ItemProperty 'HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion' -ErrorAction SilentlyContinue
$gamingServices = @(Get-AppxPackage -Name Microsoft.GamingServices -ErrorAction SilentlyContinue | ForEach-Object {
    [ordered]@{
        name = $_.Name
        version = [string]$_.Version
        architecture = [string]$_.Architecture
        install_location_name = Get-SafeFileName $_.InstallLocation
    }
})

$game = $null
$gameArchitecture = $null
$loadedRuntime = $null
if ($ProcessId -gt 0) {
    try {
        $process = Get-Process -Id $ProcessId -ErrorAction Stop
        $game = $process.Path
        $gameArchitecture = Get-PeMachine $game
        $module = @($process.Modules | Where-Object { $_.ModuleName -ieq 'xgameruntime.dll' } | Select-Object -First 1)
        if ($module) { $XGameRuntimePath = $module.FileName }
    } catch {}
}
if ($XGameRuntimePath -and (Test-Path -LiteralPath $XGameRuntimePath)) {
    $file = Get-Item -LiteralPath $XGameRuntimePath
    $hash = Get-FileHash -LiteralPath $XGameRuntimePath -Algorithm SHA256
    $loadedRuntime = [ordered]@{
        filename = $file.Name
        file_version = $file.VersionInfo.FileVersion
        sha256 = $hash.Hash.ToLowerInvariant()
    }
}

$snapshot = [ordered]@{
    schema_version = 1
    captured_utc = [DateTime]::UtcNow.ToString('o')
    # Host names and account-bearing paths are intentionally excluded from
    # snapshots that may be shared with upstream projects.
    computer = $null
    windows = [ordered]@{
        product_name = $version.ProductName
        display_version = $version.DisplayVersion
        current_build = $version.CurrentBuild
        ubr = $version.UBR
        os_version = [Environment]::OSVersion.VersionString
    }
    cpu_architecture = $env:PROCESSOR_ARCHITECTURE
    gaming_services = $gamingServices
    target_process = [ordered]@{
        pid = if ($ProcessId -gt 0) { $ProcessId } else { $null }
        executable = Get-SafeFileName $game
        architecture = $gameArchitecture
    }
    loaded_xgameruntime = $loadedRuntime
    repositories = [ordered]@{
        xgameruntime = '791710510d9ba0746bbd60754215eb321800e4f0'
        xodus = '0670e25aeb0e0e9f800f8f2f4968ae3b681842a7'
        xgameruntime_docs = '7090008692569aa6081e30dfdd9de58237741e24'
    }
    notes = @(
        $(if ($ProcessId -gt 0) { 'Snapshot captured with a target process.' } else { 'No game process was running during the baseline snapshot.' }),
        'x86-64 tracer scope only.'
    )
}

$parent = Split-Path -Parent $OutputPath
New-Item -ItemType Directory -Force -Path $parent | Out-Null
$snapshot | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath $OutputPath -Encoding UTF8
