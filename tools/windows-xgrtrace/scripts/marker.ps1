param(
    [Parameter(Mandatory = $true, Position = 0)]
    [string]$Text,
    [string]$TraceRoot,
    [int]$ProcessId = 0
)

$marker = Join-Path $PSScriptRoot '..\xgrtrace-marker.exe'
if (-not (Test-Path -LiteralPath $marker)) {
    throw "Build xgrtrace-marker.exe first: $marker"
}
$arguments = @()
if ($TraceRoot) { $arguments += @('--trace-root', $TraceRoot) }
if ($ProcessId -gt 0) { $arguments += @('--pid', $ProcessId.ToString()) }
$arguments += $Text
& $marker @arguments
