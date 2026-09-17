// Generated file. Do not edit by hand; rerun scripts/generate_wrappers.py.
#include "xgrtrace_gdk_abi.h"
#include "wrappers.h"
#include "trace_core.h"

namespace xgrtrace::generated {

void CALLBACK xgrtrace_callback_XAppBroadcastMonitorCallback(void * context)
{
    auto original = reinterpret_cast<XAppBroadcastMonitorCallback *>(trace::ResolveCallback("XAppBroadcastMonitorCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XAppBroadcastMonitorCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context);
}

void CALLBACK xgrtrace_callback_XAppCaptureMetadataPurgedCallback(void * context)
{
    auto original = reinterpret_cast<XAppCaptureMetadataPurgedCallback *>(trace::ResolveCallback("XAppCaptureMetadataPurgedCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XAppCaptureMetadataPurgedCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context);
}

bool CALLBACK xgrtrace_callback_XErrorCallback(HRESULT hr, const char * msg, void * context)
{
    auto original = reinterpret_cast<XErrorCallback *>(trace::ResolveCallback("XErrorCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XErrorCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "hr", hr);
        trace::RecordCallbackArgument(callback_id, "msg", msg);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return FALSE;
    }
    return original(hr, msg, context);
}

void CALLBACK xgrtrace_callback_XGameActivationCallback(void * context, const XGameActivationInfo * activationInfo)
{
    auto original = reinterpret_cast<XGameActivationCallback *>(trace::ResolveCallback("XGameActivationCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameActivationCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "activationInfo", activationInfo);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, activationInfo);
}

void CALLBACK xgrtrace_callback_XGameInviteEventCallback(void * context, const char * inviteUri)
{
    auto original = reinterpret_cast<XGameInviteEventCallback *>(trace::ResolveCallback("XGameInviteEventCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameInviteEventCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "inviteUri", inviteUri);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, inviteUri);
}

void CALLBACK xgrtrace_callback_XGameProtocolActivationCallback(void * context, const char * protocolUri)
{
    auto original = reinterpret_cast<XGameProtocolActivationCallback *>(trace::ResolveCallback("XGameProtocolActivationCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameProtocolActivationCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "protocolUri", protocolUri);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, protocolUri);
}

bool CALLBACK xgrtrace_callback_XGameSaveBlobInfoCallback(const XGameSaveBlobInfo * info, void * context)
{
    auto original = reinterpret_cast<XGameSaveBlobInfoCallback *>(trace::ResolveCallback("XGameSaveBlobInfoCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameSaveBlobInfoCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "info", info);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return FALSE;
    }
    return original(info, context);
}

bool CALLBACK xgrtrace_callback_XGameSaveContainerInfoCallback(const XGameSaveContainerInfo * info, void * context)
{
    auto original = reinterpret_cast<XGameSaveContainerInfoCallback *>(trace::ResolveCallback("XGameSaveContainerInfoCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameSaveContainerInfoCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "info", info);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return FALSE;
    }
    return original(info, context);
}

void CALLBACK xgrtrace_callback_XGameStreamingClientPropertiesChangedCallback(void * context, XGameStreamingClientId client, UINT32 updatedPropertiesCount, XGameStreamingClientProperty * updatedProperties)
{
    auto original = reinterpret_cast<XGameStreamingClientPropertiesChangedCallback *>(trace::ResolveCallback("XGameStreamingClientPropertiesChangedCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameStreamingClientPropertiesChangedCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "client", client);
        trace::RecordCallbackArgument(callback_id, "updatedPropertiesCount", updatedPropertiesCount);
        trace::RecordCallbackArgument(callback_id, "updatedProperties", updatedProperties);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, client, updatedPropertiesCount, updatedProperties);
}

void CALLBACK xgrtrace_callback_XGameStreamingConnectionStateChangedCallback(void * context, XGameStreamingClientId client, XGameStreamingConnectionState state)
{
    auto original = reinterpret_cast<XGameStreamingConnectionStateChangedCallback *>(trace::ResolveCallback("XGameStreamingConnectionStateChangedCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameStreamingConnectionStateChangedCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "client", client);
        trace::RecordCallbackArgument(callback_id, "state", state);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, client, state);
}

void CALLBACK xgrtrace_callback_XGameUiShowAchievementsUiCallback(XGameUiCallbackHandle callbackHandle, XTaskQueueHandle queue, XUserHandle requestingUser, UINT32 titleId, void * context)
{
    auto original = reinterpret_cast<XGameUiShowAchievementsUiCallback *>(trace::ResolveCallback("XGameUiShowAchievementsUiCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameUiShowAchievementsUiCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue));
        trace::RecordCallbackArgument(callback_id, "callbackHandle", callbackHandle);
        trace::RecordCallbackArgument(callback_id, "queue", queue);
        trace::RecordCallbackArgument(callback_id, "requestingUser", requestingUser);
        trace::RecordCallbackArgument(callback_id, "titleId", titleId);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(callbackHandle, queue, requestingUser, titleId, context);
}

void CALLBACK xgrtrace_callback_XGameUiShowErrorDialogUiCallback(XGameUiCallbackHandle callbackHandle, XTaskQueueHandle queue, HRESULT errorCode, const char * serviceContext, void * context)
{
    auto original = reinterpret_cast<XGameUiShowErrorDialogUiCallback *>(trace::ResolveCallback("XGameUiShowErrorDialogUiCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameUiShowErrorDialogUiCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue));
        trace::RecordCallbackArgument(callback_id, "callbackHandle", callbackHandle);
        trace::RecordCallbackArgument(callback_id, "queue", queue);
        trace::RecordCallbackArgument(callback_id, "errorCode", errorCode);
        trace::RecordCallbackArgument(callback_id, "serviceContext", serviceContext);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(callbackHandle, queue, errorCode, serviceContext, context);
}

void CALLBACK xgrtrace_callback_XGameUiShowMessageDialogUiCallback(XGameUiCallbackHandle callbackHandle, XTaskQueueHandle queue, const char * titleText, const char * contentText, const char * firstButtonText, const char * secondButtonText, const char * thirdButtonText, XGameUiMessageDialogButton defaultButton, XGameUiMessageDialogButton cancelButton, void * context)
{
    auto original = reinterpret_cast<XGameUiShowMessageDialogUiCallback *>(trace::ResolveCallback("XGameUiShowMessageDialogUiCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameUiShowMessageDialogUiCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue));
        trace::RecordCallbackArgument(callback_id, "callbackHandle", callbackHandle);
        trace::RecordCallbackArgument(callback_id, "queue", queue);
        trace::RecordCallbackArgument(callback_id, "titleText", titleText);
        trace::RecordCallbackArgument(callback_id, "contentText", contentText);
        trace::RecordCallbackArgument(callback_id, "firstButtonText", firstButtonText);
        trace::RecordCallbackArgument(callback_id, "secondButtonText", secondButtonText);
        trace::RecordCallbackArgument(callback_id, "thirdButtonText", thirdButtonText);
        trace::RecordCallbackArgument(callback_id, "defaultButton", defaultButton);
        trace::RecordCallbackArgument(callback_id, "cancelButton", cancelButton);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(callbackHandle, queue, titleText, contentText, firstButtonText, secondButtonText, thirdButtonText, defaultButton, cancelButton, context);
}

void CALLBACK xgrtrace_callback_XGameUiShowMultiplayerActivityGameInviteUiCallback(XGameUiCallbackHandle callbackHandle, XTaskQueueHandle queue, XUserHandle requestingUser, void * context)
{
    auto original = reinterpret_cast<XGameUiShowMultiplayerActivityGameInviteUiCallback *>(trace::ResolveCallback("XGameUiShowMultiplayerActivityGameInviteUiCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameUiShowMultiplayerActivityGameInviteUiCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue));
        trace::RecordCallbackArgument(callback_id, "callbackHandle", callbackHandle);
        trace::RecordCallbackArgument(callback_id, "queue", queue);
        trace::RecordCallbackArgument(callback_id, "requestingUser", requestingUser);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(callbackHandle, queue, requestingUser, context);
}

void CALLBACK xgrtrace_callback_XGameUiShowPlayerPickerUiCallback(XGameUiCallbackHandle callbackHandle, XTaskQueueHandle queue, const XGameUiPlayerPickerInfo * info, void * context)
{
    auto original = reinterpret_cast<XGameUiShowPlayerPickerUiCallback *>(trace::ResolveCallback("XGameUiShowPlayerPickerUiCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameUiShowPlayerPickerUiCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue));
        trace::RecordCallbackArgument(callback_id, "callbackHandle", callbackHandle);
        trace::RecordCallbackArgument(callback_id, "queue", queue);
        trace::RecordCallbackArgument(callback_id, "info", info);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(callbackHandle, queue, info, context);
}

void CALLBACK xgrtrace_callback_XGameUiShowPlayerProfileCardUiCallback(XGameUiCallbackHandle callbackHandle, XTaskQueueHandle queue, XUserHandle requestingUser, UINT64 targetPlayer, void * context)
{
    auto original = reinterpret_cast<XGameUiShowPlayerProfileCardUiCallback *>(trace::ResolveCallback("XGameUiShowPlayerProfileCardUiCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameUiShowPlayerProfileCardUiCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue));
        trace::RecordCallbackArgument(callback_id, "callbackHandle", callbackHandle);
        trace::RecordCallbackArgument(callback_id, "queue", queue);
        trace::RecordCallbackArgument(callback_id, "requestingUser", requestingUser);
        trace::RecordCallbackArgument(callback_id, "targetPlayer", targetPlayer);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(callbackHandle, queue, requestingUser, targetPlayer, context);
}

void CALLBACK xgrtrace_callback_XGameUiShowSendGameInviteUiCallback(XGameUiCallbackHandle callbackHandle, XTaskQueueHandle queue, XUserHandle requestingUser, const char * sessionConfigurationId, const char * sessionTemplateName, const char * sessionId, const char * invitationText, const char * customActivationContext, void * context)
{
    auto original = reinterpret_cast<XGameUiShowSendGameInviteUiCallback *>(trace::ResolveCallback("XGameUiShowSendGameInviteUiCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameUiShowSendGameInviteUiCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue));
        trace::RecordCallbackArgument(callback_id, "callbackHandle", callbackHandle);
        trace::RecordCallbackArgument(callback_id, "queue", queue);
        trace::RecordCallbackArgument(callback_id, "requestingUser", requestingUser);
        trace::RecordCallbackArgument(callback_id, "sessionConfigurationId", sessionConfigurationId);
        trace::RecordCallbackArgument(callback_id, "sessionTemplateName", sessionTemplateName);
        trace::RecordCallbackArgument(callback_id, "sessionId", sessionId);
        trace::RecordCallbackArgument(callback_id, "invitationText", invitationText);
        trace::RecordCallbackArgument(callback_id, "customActivationContext", customActivationContext);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(callbackHandle, queue, requestingUser, sessionConfigurationId, sessionTemplateName, sessionId, invitationText, customActivationContext, context);
}

void CALLBACK xgrtrace_callback_XGameUiShowTextEntryUiCallback(XGameUiCallbackHandle callbackHandle, XTaskQueueHandle queue, const char * titleText, const char * descriptionText, const char * defaultText, XGameUiTextEntryInputScope inputScope, UINT32 maxTextLength, void * context)
{
    auto original = reinterpret_cast<XGameUiShowTextEntryUiCallback *>(trace::ResolveCallback("XGameUiShowTextEntryUiCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XGameUiShowTextEntryUiCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue));
        trace::RecordCallbackArgument(callback_id, "callbackHandle", callbackHandle);
        trace::RecordCallbackArgument(callback_id, "queue", queue);
        trace::RecordCallbackArgument(callback_id, "titleText", titleText);
        trace::RecordCallbackArgument(callback_id, "descriptionText", descriptionText);
        trace::RecordCallbackArgument(callback_id, "defaultText", defaultText);
        trace::RecordCallbackArgument(callback_id, "inputScope", inputScope);
        trace::RecordCallbackArgument(callback_id, "maxTextLength", maxTextLength);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(callbackHandle, queue, titleText, descriptionText, defaultText, inputScope, maxTextLength, context);
}

void CALLBACK xgrtrace_callback_XNetworkingConnectivityHintChangedCallback(void * context, const XNetworkingConnectivityHint * connectivityHint)
{
    auto original = reinterpret_cast<XNetworkingConnectivityHintChangedCallback *>(trace::ResolveCallback("XNetworkingConnectivityHintChangedCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XNetworkingConnectivityHintChangedCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "connectivityHint", connectivityHint);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, connectivityHint);
}

void CALLBACK xgrtrace_callback_XNetworkingPreferredLocalUdpMultiplayerPortChangedCallback(void * context, uint16_t preferredLocalUdpMultiplayerPort)
{
    auto original = reinterpret_cast<XNetworkingPreferredLocalUdpMultiplayerPortChangedCallback *>(trace::ResolveCallback("XNetworkingPreferredLocalUdpMultiplayerPortChangedCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XNetworkingPreferredLocalUdpMultiplayerPortChangedCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "preferredLocalUdpMultiplayerPort", preferredLocalUdpMultiplayerPort);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, preferredLocalUdpMultiplayerPort);
}

bool CALLBACK xgrtrace_callback_XPackageChunkAvailabilityCallback(void * context, const XPackageChunkSelector * selector, XPackageChunkAvailability availability)
{
    auto original = reinterpret_cast<XPackageChunkAvailabilityCallback *>(trace::ResolveCallback("XPackageChunkAvailabilityCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XPackageChunkAvailabilityCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "selector", selector);
        trace::RecordCallbackArgument(callback_id, "availability", availability);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return FALSE;
    }
    return original(context, selector, availability);
}

bool CALLBACK xgrtrace_callback_XPackageEnumerationCallback(void * context, const XPackageDetails * details)
{
    auto original = reinterpret_cast<XPackageEnumerationCallback *>(trace::ResolveCallback("XPackageEnumerationCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XPackageEnumerationCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "details", details);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return FALSE;
    }
    return original(context, details);
}

bool CALLBACK xgrtrace_callback_XPackageFeatureEnumerationCallback(void * context, const XPackageFeature * details)
{
    auto original = reinterpret_cast<XPackageFeatureEnumerationCallback *>(trace::ResolveCallback("XPackageFeatureEnumerationCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XPackageFeatureEnumerationCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "details", details);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return FALSE;
    }
    return original(context, details);
}

void CALLBACK xgrtrace_callback_XPackageInstallationProgressCallback(void * context, XPackageInstallationMonitorHandle monitor)
{
    auto original = reinterpret_cast<XPackageInstallationProgressCallback *>(trace::ResolveCallback("XPackageInstallationProgressCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XPackageInstallationProgressCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "monitor", monitor);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, monitor);
}

void CALLBACK xgrtrace_callback_XPackageInstalledCallback(void * context, const XPackageDetails * details)
{
    auto original = reinterpret_cast<XPackageInstalledCallback *>(trace::ResolveCallback("XPackageInstalledCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XPackageInstalledCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "details", details);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, details);
}

bool CALLBACK xgrtrace_callback_XSpeechSynthesizerInstalledVoicesCallback(const XSpeechSynthesizerVoiceInformation * information, void * context)
{
    auto original = reinterpret_cast<XSpeechSynthesizerInstalledVoicesCallback *>(trace::ResolveCallback("XSpeechSynthesizerInstalledVoicesCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XSpeechSynthesizerInstalledVoicesCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "information", information);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return FALSE;
    }
    return original(information, context);
}

void CALLBACK xgrtrace_callback_XStoreGameLicenseChangedCallback(void * context)
{
    auto original = reinterpret_cast<XStoreGameLicenseChangedCallback *>(trace::ResolveCallback("XStoreGameLicenseChangedCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XStoreGameLicenseChangedCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context);
}

void CALLBACK xgrtrace_callback_XStorePackageLicenseLostCallback(void * context)
{
    auto original = reinterpret_cast<XStorePackageLicenseLostCallback *>(trace::ResolveCallback("XStorePackageLicenseLostCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XStorePackageLicenseLostCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context);
}

bool CALLBACK xgrtrace_callback_XStoreProductQueryCallback(const XStoreProduct * product, void * context)
{
    auto original = reinterpret_cast<XStoreProductQueryCallback *>(trace::ResolveCallback("XStoreProductQueryCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XStoreProductQueryCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "product", product);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return FALSE;
    }
    return original(product, context);
}

void CALLBACK xgrtrace_callback_XSystemHandleCallback(XSystemHandle handle, XSystemHandleType type, XSystemHandleCallbackReason reason, void * context)
{
    auto original = reinterpret_cast<XSystemHandleCallback>(trace::ResolveCallback("XSystemHandleCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XSystemHandleCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "handle", handle);
        trace::RecordCallbackArgument(callback_id, "type", type);
        trace::RecordCallbackArgument(callback_id, "reason", reason);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(handle, type, reason, context);
}

void CALLBACK xgrtrace_callback_XTaskQueueCallback(void * context, bool canceled)
{
    auto original = reinterpret_cast<XTaskQueueCallback *>(trace::ResolveCallback("XTaskQueueCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XTaskQueueCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "canceled", canceled);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, canceled);
}

void CALLBACK xgrtrace_callback_XTaskQueueMonitorCallback(void * context, XTaskQueueHandle queue, XTaskQueuePort port)
{
    auto original = reinterpret_cast<XTaskQueueMonitorCallback *>(trace::ResolveCallback("XTaskQueueMonitorCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XTaskQueueMonitorCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue));
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "queue", queue);
        trace::RecordCallbackArgument(callback_id, "port", port);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, queue, port);
}

void CALLBACK xgrtrace_callback_XTaskQueueTerminatedCallback(void * context)
{
    auto original = reinterpret_cast<XTaskQueueTerminatedCallback *>(trace::ResolveCallback("XTaskQueueTerminatedCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XTaskQueueTerminatedCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context);
}

void CALLBACK xgrtrace_callback_XUserChangeEventCallback(void * context, XUserLocalId userLocalId, XUserChangeEvent event)
{
    auto original = reinterpret_cast<XUserChangeEventCallback *>(trace::ResolveCallback("XUserChangeEventCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XUserChangeEventCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "userLocalId", userLocalId);
        trace::RecordCallbackArgument(callback_id, "event", event);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, userLocalId, event);
}

void CALLBACK xgrtrace_callback_XUserDefaultAudioEndpointUtf16ChangedCallback(void * context, XUserLocalId user, XUserDefaultAudioEndpointKind defaultAudioEndpointKind, const WCHAR * endpointIdUtf16)
{
    auto original = reinterpret_cast<XUserDefaultAudioEndpointUtf16ChangedCallback *>(trace::ResolveCallback("XUserDefaultAudioEndpointUtf16ChangedCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XUserDefaultAudioEndpointUtf16ChangedCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "user", user);
        trace::RecordCallbackArgument(callback_id, "defaultAudioEndpointKind", defaultAudioEndpointKind);
        trace::RecordCallbackArgument(callback_id, "endpointIdUtf16", endpointIdUtf16);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, user, defaultAudioEndpointKind, endpointIdUtf16);
}

void CALLBACK xgrtrace_callback_XUserDeviceAssociationChangedCallback(void * context, const XUserDeviceAssociationChange * change)
{
    auto original = reinterpret_cast<XUserDeviceAssociationChangedCallback *>(trace::ResolveCallback("XUserDeviceAssociationChangedCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XUserDeviceAssociationChangedCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "change", change);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, change);
}

void CALLBACK xgrtrace_callback_XUserFindControllerForUserUiCallback(void * context, XUserHandle user)
{
    auto original = reinterpret_cast<XUserFindControllerForUserUiCallback *>(trace::ResolveCallback("XUserFindControllerForUserUiCallback", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XUserFindControllerForUserUiCallback", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "user", user);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, user);
}

void CALLBACK xgrtrace_callback_XUserPlatformRemoteConnectClosePromptEventHandler(void * context, UINT32 userIdentifier, XUserPlatformOperation operation)
{
    auto original = reinterpret_cast<XUserPlatformRemoteConnectClosePromptEventHandler *>(trace::ResolveCallback("XUserPlatformRemoteConnectClosePromptEventHandler", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XUserPlatformRemoteConnectClosePromptEventHandler", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "userIdentifier", userIdentifier);
        trace::RecordCallbackArgument(callback_id, "operation", operation);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, userIdentifier, operation);
}

void CALLBACK xgrtrace_callback_XUserPlatformRemoteConnectShowPromptEventHandler(void * context, UINT32 userIdentifier, XUserPlatformOperation operation, const char * url, const char * code, SIZE_T qrCodeSize, const void * qrCode)
{
    auto original = reinterpret_cast<XUserPlatformRemoteConnectShowPromptEventHandler *>(trace::ResolveCallback("XUserPlatformRemoteConnectShowPromptEventHandler", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XUserPlatformRemoteConnectShowPromptEventHandler", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "userIdentifier", userIdentifier);
        trace::RecordCallbackArgument(callback_id, "operation", operation);
        trace::RecordCallbackArgument(callback_id, "url", url);
        trace::RecordCallbackArgument(callback_id, "code", code);
        trace::RecordCallbackArgument(callback_id, "qrCodeSize", qrCodeSize);
        trace::RecordCallbackArgument(callback_id, "qrCode", qrCode);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, userIdentifier, operation, url, code, qrCodeSize, qrCode);
}

void CALLBACK xgrtrace_callback_XUserPlatformSpopPromptEventHandler(void * context, UINT32 userIdentifier, XUserPlatformOperation operation, const char * modernGamertag, const char * modernGamertagSuffix)
{
    auto original = reinterpret_cast<XUserPlatformSpopPromptEventHandler *>(trace::ResolveCallback("XUserPlatformSpopPromptEventHandler", reinterpret_cast<const void *>(context)));
    try {
        auto callback_id = trace::BeginCallbackInvocation("XUserPlatformSpopPromptEventHandler", reinterpret_cast<const void *>(original), reinterpret_cast<const void *>(context), nullptr);
        trace::RecordCallbackArgument(callback_id, "context", context);
        trace::RecordCallbackArgument(callback_id, "userIdentifier", userIdentifier);
        trace::RecordCallbackArgument(callback_id, "operation", operation);
        trace::RecordCallbackArgument(callback_id, "modernGamertag", modernGamertag);
        trace::RecordCallbackArgument(callback_id, "modernGamertagSuffix", modernGamertagSuffix);
        trace::EndCallbackInvocation(callback_id);
    } catch (...) {
        // Callback observation must never change the callback ABI.
    }
    if (!original) {
        return;
    }
    original(context, userIdentifier, operation, modernGamertag, modernGamertagSuffix);
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot3_XClosedCaptionGetProperties(void *self, XClosedCaptionProperties * props)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XClosedCaptionProperties * props)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 3, "XClosedCaptionGetProperties", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "props", reinterpret_cast<const void *>(props), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, props);
    try {
        trace::RecordOutputObject(call_id, "props", props, "XClosedCaptionProperties *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot4_XClosedCaptionSetEnabled(void *self, BOOLEAN enabled)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, BOOLEAN enabled)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 4, "XClosedCaptionSetEnabled", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "enabled", enabled);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, enabled);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot5_XHighContrastGetMode(void *self, XHighContrastMode * mode)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XHighContrastMode * mode)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 5, "XHighContrastGetMode", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "mode", reinterpret_cast<const void *>(mode), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, mode);
    try {
        trace::RecordOutputObject(call_id, "mode", mode, "XHighContrastMode *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot6_XSpeechToTextSetPositionHint(void *self, XSpeechToTextPositionHint position)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XSpeechToTextPositionHint position)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 6, "XSpeechToTextSetPositionHint", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "position", position);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, position);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot7_XSpeechToTextSendString(void *self, const char * speakerName, const char * content, XSpeechToTextType type)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * speakerName, const char * content, XSpeechToTextType type)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 7, "XSpeechToTextSendString", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "speakerName", speakerName, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "content", content, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "type", type);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, speakerName, content, type);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot8_XSpeechSynthesizerEnumerateInstalledVoices(void *self, void * context, XSpeechSynthesizerInstalledVoicesCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, void * context, XSpeechSynthesizerInstalledVoicesCallback * callback)>(trace::OriginalSlot(self, 8));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 8, "XSpeechSynthesizerEnumerateInstalledVoices", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, context, trace::WrapCallback<XSpeechSynthesizerInstalledVoicesCallback>(call_id, "XSpeechSynthesizerInstalledVoicesCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XSpeechSynthesizerInstalledVoicesCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot9_XSpeechSynthesizerCreate(void *self, XSpeechSynthesizerHandle * speechSynthesizer)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XSpeechSynthesizerHandle * speechSynthesizer)>(trace::OriginalSlot(self, 9));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 9, "XSpeechSynthesizerCreate", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "speechSynthesizer", reinterpret_cast<const void *>(speechSynthesizer), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, speechSynthesizer);
    try {
        trace::RecordOutputHandleObject(call_id, "speechSynthesizer", speechSynthesizer, "XSpeechSynthesizerHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot10_XSpeechSynthesizerCloseHandle(void *self, XSpeechSynthesizerHandle speechSynthesizer)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XSpeechSynthesizerHandle speechSynthesizer)>(trace::OriginalSlot(self, 10));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 10, "XSpeechSynthesizerCloseHandle", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "speechSynthesizer", speechSynthesizer, "XSpeechSynthesizerHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, speechSynthesizer);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot11_XSpeechSynthesizerSetDefaultVoice(void *self, XSpeechSynthesizerHandle speechSynthesizer)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XSpeechSynthesizerHandle speechSynthesizer)>(trace::OriginalSlot(self, 11));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 11, "XSpeechSynthesizerSetDefaultVoice", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "speechSynthesizer", speechSynthesizer, "XSpeechSynthesizerHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, speechSynthesizer);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot12_XSpeechSynthesizerSetCustomVoice(void *self, XSpeechSynthesizerHandle speechSynthesizer, const char * voiceId)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XSpeechSynthesizerHandle speechSynthesizer, const char * voiceId)>(trace::OriginalSlot(self, 12));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 12, "XSpeechSynthesizerSetCustomVoice", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "speechSynthesizer", speechSynthesizer, "XSpeechSynthesizerHandle");
        trace::RecordInputString(call_id, "voiceId", voiceId, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, speechSynthesizer, voiceId);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot13_XSpeechSynthesizerCreateStreamFromText(void *self, XSpeechSynthesizerHandle speechSynthesizer, const char * text, XSpeechSynthesizerStreamHandle * speechSynthesisStream)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XSpeechSynthesizerHandle speechSynthesizer, const char * text, XSpeechSynthesizerStreamHandle * speechSynthesisStream)>(trace::OriginalSlot(self, 13));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 13, "XSpeechSynthesizerCreateStreamFromText", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "speechSynthesizer", speechSynthesizer, "XSpeechSynthesizerHandle");
        trace::RecordInputString(call_id, "text", text, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "speechSynthesisStream", reinterpret_cast<const void *>(speechSynthesisStream), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, speechSynthesizer, text, speechSynthesisStream);
    try {
        trace::RecordOutputHandleObject(call_id, "speechSynthesisStream", speechSynthesisStream, "XSpeechSynthesizerStreamHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot14_XSpeechSynthesizerCloseStreamHandle(void *self, XSpeechSynthesizerStreamHandle speechSynthesisStream)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XSpeechSynthesizerStreamHandle speechSynthesisStream)>(trace::OriginalSlot(self, 14));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 14, "XSpeechSynthesizerCloseStreamHandle", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "speechSynthesisStream", speechSynthesisStream, "XSpeechSynthesizerStreamHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, speechSynthesisStream);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot15_XSpeechSynthesizerGetStreamDataSize(void *self, XSpeechSynthesizerStreamHandle speechSynthesisStream, SIZE_T * bufferSize)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XSpeechSynthesizerStreamHandle speechSynthesisStream, SIZE_T * bufferSize)>(trace::OriginalSlot(self, 15));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 15, "XSpeechSynthesizerGetStreamDataSize", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "speechSynthesisStream", speechSynthesisStream, "XSpeechSynthesizerStreamHandle");
        trace::RecordPointer(call_id, "bufferSize", reinterpret_cast<const void *>(bufferSize), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, speechSynthesisStream, bufferSize);
    try {
        trace::RecordOutputObject(call_id, "bufferSize", bufferSize, "SIZE_T *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot16_XSpeechSynthesizerGetStreamData(void *self, XSpeechSynthesizerStreamHandle speechSynthesisStream, SIZE_T bufferSize, void * buffer, SIZE_T * bufferUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XSpeechSynthesizerStreamHandle speechSynthesisStream, SIZE_T bufferSize, void * buffer, SIZE_T * bufferUsed)>(trace::OriginalSlot(self, 16));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 16, "XSpeechSynthesizerGetStreamData", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "speechSynthesisStream", speechSynthesisStream, "XSpeechSynthesizerStreamHandle");
        trace::RecordScalar(call_id, "bufferSize", bufferSize);
        trace::RecordPointer(call_id, "buffer", reinterpret_cast<const void *>(buffer), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "bufferUsed", reinterpret_cast<const void *>(bufferUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, speechSynthesisStream, bufferSize, buffer, bufferUsed);
    try {
        trace::RecordOutputBuffer(call_id, "buffer", reinterpret_cast<const void *>(buffer), (static_cast<std::size_t>(bufferSize)) * 1, reinterpret_cast<const void *>(bufferUsed), sizeof(*bufferUsed), 1, "void *", trace::OutputEncoding::Binary, false);
        trace::RecordOutputObject(call_id, "bufferUsed", bufferUsed, "SIZE_T *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot17_XSpeechToTextBeginHypothesisString(void *self, const char * speakerName, const char * content, XSpeechToTextType type, UINT32 * hypothesisId)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * speakerName, const char * content, XSpeechToTextType type, UINT32 * hypothesisId)>(trace::OriginalSlot(self, 17));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 17, "XSpeechToTextBeginHypothesisString", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "speakerName", speakerName, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "content", content, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "type", type);
        trace::RecordPointer(call_id, "hypothesisId", reinterpret_cast<const void *>(hypothesisId), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, speakerName, content, type, hypothesisId);
    try {
        trace::RecordOutputObject(call_id, "hypothesisId", hypothesisId, "UINT32 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot18_XSpeechToTextUpdateHypothesisString(void *self, UINT32 hypothesisId, const char * content)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, UINT32 hypothesisId, const char * content)>(trace::OriginalSlot(self, 18));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 18, "XSpeechToTextUpdateHypothesisString", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "hypothesisId", hypothesisId);
        trace::RecordInputString(call_id, "content", content, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, hypothesisId, content);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot19_XSpeechToTextFinalizeHypothesisString(void *self, UINT32 hypothesisId, const char * content)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, UINT32 hypothesisId, const char * content)>(trace::OriginalSlot(self, 19));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 19, "XSpeechToTextFinalizeHypothesisString", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "hypothesisId", hypothesisId);
        trace::RecordInputString(call_id, "content", content, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, hypothesisId, content);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot20_XSpeechToTextCancelHypothesisString(void *self, UINT32 hypothesisId)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, UINT32 hypothesisId)>(trace::OriginalSlot(self, 20));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 20, "XSpeechToTextCancelHypothesisString", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "hypothesisId", hypothesisId);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, hypothesisId);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAccessibilityImpl_slot21_XSpeechSynthesizerCreateStreamFromSsml(void *self, XSpeechSynthesizerHandle speechSynthesizer, const char * ssml, XSpeechSynthesizerStreamHandle * speechSynthesisStream)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XSpeechSynthesizerHandle speechSynthesizer, const char * ssml, XSpeechSynthesizerStreamHandle * speechSynthesisStream)>(trace::OriginalSlot(self, 21));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3e241977-6237-41e9-8559-102c2d9983f1", 21, "XSpeechSynthesizerCreateStreamFromSsml", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "speechSynthesizer", speechSynthesizer, "XSpeechSynthesizerHandle");
        trace::RecordInputString(call_id, "ssml", ssml, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "speechSynthesisStream", reinterpret_cast<const void *>(speechSynthesisStream), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, speechSynthesizer, ssml, speechSynthesisStream);
    try {
        trace::RecordOutputHandleObject(call_id, "speechSynthesisStream", speechSynthesisStream, "XSpeechSynthesizerStreamHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl_slot3_XAppCaptureTakeDiagnosticScreenshot(void *self, BOOLEAN gamescreenOnly, XAppCaptureScreenshotFormatFlag captureFlags, const char * filenamePrefix, XAppCaptureDiagnosticScreenshotResult * result)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, BOOLEAN gamescreenOnly, XAppCaptureScreenshotFormatFlag captureFlags, const char * filenamePrefix, XAppCaptureDiagnosticScreenshotResult * result)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("a4f1aee2-4bf1-4485-b008-a7c26d52ac27", 3, "XAppCaptureTakeDiagnosticScreenshot", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "gamescreenOnly", gamescreenOnly);
        trace::RecordScalar(call_id, "captureFlags", captureFlags);
        trace::RecordInputString(call_id, "filenamePrefix", filenamePrefix, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "result", reinterpret_cast<const void *>(result), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, gamescreenOnly, captureFlags, filenamePrefix, result);
    try {
        trace::RecordOutputObject(call_id, "result", result, "XAppCaptureDiagnosticScreenshotResult *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl_slot4_XAppCaptureRecordDiagnosticClip(void *self, time_t startTime, UINT32 durationInMs, const char * filenamePrefix, XAppCaptureRecordClipResult * result)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, time_t startTime, UINT32 durationInMs, const char * filenamePrefix, XAppCaptureRecordClipResult * result)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("a4f1aee2-4bf1-4485-b008-a7c26d52ac27", 4, "XAppCaptureRecordDiagnosticClip", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "startTime", startTime);
        trace::RecordScalar(call_id, "durationInMs", durationInMs);
        trace::RecordInputString(call_id, "filenamePrefix", filenamePrefix, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "result", reinterpret_cast<const void *>(result), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, startTime, durationInMs, filenamePrefix, result);
    try {
        trace::RecordOutputObject(call_id, "result", result, "XAppCaptureRecordClipResult *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl_slot5_XAppCaptureTakeScreenshot(void *self, XUserHandle requestingUser, XAppCaptureTakeScreenshotResult * result)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle requestingUser, XAppCaptureTakeScreenshotResult * result)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("a4f1aee2-4bf1-4485-b008-a7c26d52ac27", 5, "XAppCaptureTakeScreenshot", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
        trace::RecordPointer(call_id, "result", reinterpret_cast<const void *>(result), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, requestingUser, result);
    try {
        trace::RecordOutputObject(call_id, "result", result, "XAppCaptureTakeScreenshotResult *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl_slot6_XAppCaptureOpenScreenshotStream(void *self, const char * localId, XAppCaptureScreenshotFormatFlag screenshotFormat, XAppCaptureScreenshotStreamHandle * handle, UINT64 * totalBytes)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * localId, XAppCaptureScreenshotFormatFlag screenshotFormat, XAppCaptureScreenshotStreamHandle * handle, UINT64 * totalBytes)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("a4f1aee2-4bf1-4485-b008-a7c26d52ac27", 6, "XAppCaptureOpenScreenshotStream", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "localId", localId, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "screenshotFormat", screenshotFormat);
        trace::RecordPointer(call_id, "handle", reinterpret_cast<const void *>(handle), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "totalBytes", reinterpret_cast<const void *>(totalBytes), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, localId, screenshotFormat, handle, totalBytes);
    try {
        trace::RecordOutputHandleObject(call_id, "handle", handle, "XAppCaptureScreenshotStreamHandle *");
        trace::RecordOutputObject(call_id, "totalBytes", totalBytes, "UINT64 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl_slot7_XAppCaptureReadScreenshotStream(void *self, XAppCaptureScreenshotStreamHandle handle, UINT64 startPosition, UINT32 bytesToRead, UINT8 * buffer, UINT32 * bytesWritten)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAppCaptureScreenshotStreamHandle handle, UINT64 startPosition, UINT32 bytesToRead, UINT8 * buffer, UINT32 * bytesWritten)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("a4f1aee2-4bf1-4485-b008-a7c26d52ac27", 7, "XAppCaptureReadScreenshotStream", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "handle", handle, "XAppCaptureScreenshotStreamHandle");
        trace::RecordScalar(call_id, "startPosition", startPosition);
        trace::RecordScalar(call_id, "bytesToRead", bytesToRead);
        trace::RecordPointer(call_id, "buffer", reinterpret_cast<const void *>(buffer), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "bytesWritten", reinterpret_cast<const void *>(bytesWritten), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, handle, startPosition, bytesToRead, buffer, bytesWritten);
    try {
        trace::RecordOutputBuffer(call_id, "buffer", reinterpret_cast<const void *>(buffer), (static_cast<std::size_t>(bytesToRead)) * sizeof(*buffer), reinterpret_cast<const void *>(nullptr), 0, sizeof(*buffer), "UINT8 *", trace::OutputEncoding::Binary, false);
        trace::RecordOutputObject(call_id, "bytesWritten", bytesWritten, "UINT32 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl_slot8_XAppCaptureCloseScreenshotStream(void *self, XAppCaptureScreenshotStreamHandle handle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAppCaptureScreenshotStreamHandle handle)>(trace::OriginalSlot(self, 8));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("a4f1aee2-4bf1-4485-b008-a7c26d52ac27", 8, "XAppCaptureCloseScreenshotStream", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "handle", handle, "XAppCaptureScreenshotStreamHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, handle);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl_slot9_XAppCaptureEnableRecord(void *self)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self)>(trace::OriginalSlot(self, 9));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("a4f1aee2-4bf1-4485-b008-a7c26d52ac27", 9, "XAppCaptureEnableRecord", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl_slot10_XAppCaptureDisableRecord(void *self)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self)>(trace::OriginalSlot(self, 10));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("a4f1aee2-4bf1-4485-b008-a7c26d52ac27", 10, "XAppCaptureDisableRecord", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl2_slot11_XAppCaptureGetVideoCaptureSettings(void *self, XAppCaptureVideoCaptureSettings * userCaptureSettings)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAppCaptureVideoCaptureSettings * userCaptureSettings)>(trace::OriginalSlot(self, 11));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3a949778-772e-4799-bdea-0a6639e96baa", 11, "XAppCaptureGetVideoCaptureSettings", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "userCaptureSettings", reinterpret_cast<const void *>(userCaptureSettings), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, userCaptureSettings);
    try {
        trace::RecordOutputObject(call_id, "userCaptureSettings", userCaptureSettings, "XAppCaptureVideoCaptureSettings *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl2_slot12_XAppCaptureRecordTimespan(void *self, const SYSTEMTIME * startTimestamp, UINT64 durationInMilliseconds, XAppCaptureLocalResult * result)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const SYSTEMTIME * startTimestamp, UINT64 durationInMilliseconds, XAppCaptureLocalResult * result)>(trace::OriginalSlot(self, 12));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3a949778-772e-4799-bdea-0a6639e96baa", 12, "XAppCaptureRecordTimespan", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "startTimestamp", reinterpret_cast<const void *>(startTimestamp), trace::ArgumentKind::Pointer);
        trace::RecordScalar(call_id, "durationInMilliseconds", durationInMilliseconds);
        trace::RecordPointer(call_id, "result", reinterpret_cast<const void *>(result), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, startTimestamp, durationInMilliseconds, result);
    try {
        trace::RecordOutputObject(call_id, "result", result, "XAppCaptureLocalResult *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl2_slot13_XAppCaptureReadLocalStream(void *self, XAppCaptureLocalStreamHandle handle, SIZE_T startPosition, UINT32 bytesToRead, UINT8 * buffer, UINT32 * bytesWritten)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAppCaptureLocalStreamHandle handle, SIZE_T startPosition, UINT32 bytesToRead, UINT8 * buffer, UINT32 * bytesWritten)>(trace::OriginalSlot(self, 13));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3a949778-772e-4799-bdea-0a6639e96baa", 13, "XAppCaptureReadLocalStream", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "handle", handle, "XAppCaptureLocalStreamHandle");
        trace::RecordScalar(call_id, "startPosition", startPosition);
        trace::RecordScalar(call_id, "bytesToRead", bytesToRead);
        trace::RecordPointer(call_id, "buffer", reinterpret_cast<const void *>(buffer), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "bytesWritten", reinterpret_cast<const void *>(bytesWritten), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, handle, startPosition, bytesToRead, buffer, bytesWritten);
    try {
        trace::RecordOutputBuffer(call_id, "buffer", reinterpret_cast<const void *>(buffer), (static_cast<std::size_t>(bytesToRead)) * sizeof(*buffer), reinterpret_cast<const void *>(nullptr), 0, sizeof(*buffer), "UINT8 *", trace::OutputEncoding::Binary, false);
        trace::RecordOutputObject(call_id, "bytesWritten", bytesWritten, "UINT32 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl2_slot14_XAppCaptureCloseLocalStream(void *self, XAppCaptureLocalStreamHandle handle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAppCaptureLocalStreamHandle handle)>(trace::OriginalSlot(self, 14));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3a949778-772e-4799-bdea-0a6639e96baa", 14, "XAppCaptureCloseLocalStream", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "handle", handle, "XAppCaptureLocalStreamHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, handle);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl3_slot15_XAppCaptureStartUserRecord(void *self, XUserHandle requestingUser, UINT32 localIdBufferLength, char * localIdBuffer)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle requestingUser, UINT32 localIdBufferLength, char * localIdBuffer)>(trace::OriginalSlot(self, 15));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("2bbca60a-619c-4fe1-812e-fb5c1dbdcf51", 15, "XAppCaptureStartUserRecord", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
        trace::RecordScalar(call_id, "localIdBufferLength", localIdBufferLength);
        trace::RecordPointer(call_id, "localIdBuffer", reinterpret_cast<const void *>(localIdBuffer), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, requestingUser, localIdBufferLength, localIdBuffer);
    try {
        trace::RecordOutputBuffer(call_id, "localIdBuffer", reinterpret_cast<const void *>(localIdBuffer), (static_cast<std::size_t>(localIdBufferLength)) * sizeof(*localIdBuffer), reinterpret_cast<const void *>(nullptr), 0, sizeof(*localIdBuffer), "char *", trace::OutputEncoding::Ansi, false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl3_slot16_XAppCaptureStopUserRecord(void *self, const char * localId, XAppCaptureUserRecordingResult * result)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * localId, XAppCaptureUserRecordingResult * result)>(trace::OriginalSlot(self, 16));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("2bbca60a-619c-4fe1-812e-fb5c1dbdcf51", 16, "XAppCaptureStopUserRecord", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "localId", localId, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "result", reinterpret_cast<const void *>(result), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, localId, result);
    try {
        trace::RecordOutputObject(call_id, "result", result, "XAppCaptureUserRecordingResult *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureImpl4_slot17_XAppCaptureCancelUserRecord(void *self, const char * localId)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * localId)>(trace::OriginalSlot(self, 17));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("22e672d7-b4e3-406c-bd50-8f0d25236f9e", 17, "XAppCaptureCancelUserRecord", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "localId", localId, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, localId);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot3_XAppBroadcastIsAppBroadcasting(void *self)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 3, "XAppBroadcastIsAppBroadcasting", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot4_XAppBroadcastShowUI(void *self, XUserHandle requestingUser)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle requestingUser)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 4, "XAppBroadcastShowUI", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, requestingUser);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot5_XAppBroadcastGetStatus(void *self, XUserHandle requestingUser, XAppBroadcastStatus * appBroadcastStatus)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle requestingUser, XAppBroadcastStatus * appBroadcastStatus)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 5, "XAppBroadcastGetStatus", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
        trace::RecordPointer(call_id, "appBroadcastStatus", reinterpret_cast<const void *>(appBroadcastStatus), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, requestingUser, appBroadcastStatus);
    try {
        trace::RecordOutputObject(call_id, "appBroadcastStatus", appBroadcastStatus, "XAppBroadcastStatus *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot6_XAppBroadcastRegisterIsAppBroadcastingChanged(void *self, XTaskQueueHandle queue, void * context, XAppBroadcastMonitorCallback * appBroadcastMonitorCallback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XAppBroadcastMonitorCallback * appBroadcastMonitorCallback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 6, "XAppBroadcastRegisterIsAppBroadcastingChanged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "appBroadcastMonitorCallback", reinterpret_cast<const void *>(appBroadcastMonitorCallback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XAppBroadcastMonitorCallback>(call_id, "XAppBroadcastMonitorCallback", appBroadcastMonitorCallback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XAppBroadcastMonitorCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot7_XAppBroadcastUnregisterIsAppBroadcastingChanged(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 7, "XAppBroadcastUnregisterIsAppBroadcastingChanged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot8_XAppCaptureMetadataAddStringEvent(void *self, const char * name, const char * value, XAppCaptureMetadataPriority priority)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * name, const char * value, XAppCaptureMetadataPriority priority)>(trace::OriginalSlot(self, 8));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 8, "XAppCaptureMetadataAddStringEvent", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "name", name, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "value", value, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "priority", priority);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, name, value, priority);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot9_XAppCaptureMetadataAddInt32Event(void *self, const char * name, INT32 value, XAppCaptureMetadataPriority priority)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * name, INT32 value, XAppCaptureMetadataPriority priority)>(trace::OriginalSlot(self, 9));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 9, "XAppCaptureMetadataAddInt32Event", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "name", name, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "value", value);
        trace::RecordScalar(call_id, "priority", priority);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, name, value, priority);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot10_XAppCaptureMetadataAddDoubleEvent(void *self, const char * name, double value, XAppCaptureMetadataPriority priority)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * name, double value, XAppCaptureMetadataPriority priority)>(trace::OriginalSlot(self, 10));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 10, "XAppCaptureMetadataAddDoubleEvent", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "name", name, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "value", value);
        trace::RecordScalar(call_id, "priority", priority);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, name, value, priority);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot11_XAppCaptureMetadataStartStringState(void *self, const char * name, const char * value, XAppCaptureMetadataPriority priority)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * name, const char * value, XAppCaptureMetadataPriority priority)>(trace::OriginalSlot(self, 11));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 11, "XAppCaptureMetadataStartStringState", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "name", name, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "value", value, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "priority", priority);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, name, value, priority);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot12_XAppCaptureMetadataStartInt32State(void *self, const char * name, INT32 value, XAppCaptureMetadataPriority priority)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * name, INT32 value, XAppCaptureMetadataPriority priority)>(trace::OriginalSlot(self, 12));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 12, "XAppCaptureMetadataStartInt32State", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "name", name, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "value", value);
        trace::RecordScalar(call_id, "priority", priority);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, name, value, priority);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot13_XAppCaptureMetadataStartDoubleState(void *self, const char * name, double value, XAppCaptureMetadataPriority priority)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * name, double value, XAppCaptureMetadataPriority priority)>(trace::OriginalSlot(self, 13));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 13, "XAppCaptureMetadataStartDoubleState", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "name", name, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "value", value);
        trace::RecordScalar(call_id, "priority", priority);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, name, value, priority);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot14_XAppCaptureMetadataStopState(void *self, const char * name)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * name)>(trace::OriginalSlot(self, 14));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 14, "XAppCaptureMetadataStopState", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "name", name, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, name);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot15_XAppCaptureMetadataStopAllStates(void *self)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self)>(trace::OriginalSlot(self, 15));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 15, "XAppCaptureMetadataStopAllStates", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot16_XAppCaptureMetadataRemainingStorageBytesAvailable(void *self, UINT64 * value)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, UINT64 * value)>(trace::OriginalSlot(self, 16));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 16, "XAppCaptureMetadataRemainingStorageBytesAvailable", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "value", reinterpret_cast<const void *>(value), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, value);
    try {
        trace::RecordOutputObject(call_id, "value", value, "UINT64 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot17_XAppCaptureRegisterMetadataPurged(void *self, XTaskQueueHandle queue, void * context, XAppCaptureMetadataPurgedCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XAppCaptureMetadataPurgedCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 17));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 17, "XAppCaptureRegisterMetadataPurged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XAppCaptureMetadataPurgedCallback>(call_id, "XAppCaptureMetadataPurgedCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XAppCaptureMetadataPurgedCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXAppCaptureMetadataImpl_slot18_XAppCaptureUnRegisterMetadataPurged(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 18));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("186d5592-a72d-45fb-9560-11aed0e6647a", 18, "XAppCaptureUnRegisterMetadataPurged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

XDisplayHdrModeResult WINAPI xgrtrace_wrap_IXDisplayImpl_slot4_XDisplayTryEnableHdrMode(void *self, XDisplayHdrModePreference displayModePreference, XDisplayHdrModeInfo * displayHdrModeInfo)
{
    auto original = reinterpret_cast<XDisplayHdrModeResult (WINAPI *)(void *self, XDisplayHdrModePreference displayModePreference, XDisplayHdrModeInfo * displayHdrModeInfo)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return {};
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("35f07670-706e-4bfb-9476-090798c5ebf3", 4, "XDisplayTryEnableHdrMode", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "displayModePreference", displayModePreference);
        trace::RecordPointer(call_id, "displayHdrModeInfo", reinterpret_cast<const void *>(displayHdrModeInfo), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, displayModePreference, displayHdrModeInfo);
    try {
        trace::RecordOutputObject(call_id, "displayHdrModeInfo", displayHdrModeInfo, "XDisplayHdrModeInfo *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXErrorImpl_slot4_XErrorSetCallback(void *self, XErrorCallback * callback, void * context)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XErrorCallback * callback, void * context)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8ca467f7-22e8-4096-8456-bb8aa13f79d8", 4, "XErrorSetCallback", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, trace::WrapCallback<XErrorCallback>(call_id, "XErrorCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XErrorCallback), context);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

void WINAPI xgrtrace_wrap_IXErrorImpl_slot5_XErrorSetOptions(void *self, XErrorOptions optionsDebuggerPresent, XErrorOptions optionsDebuggerNotPresent)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XErrorOptions optionsDebuggerPresent, XErrorOptions optionsDebuggerNotPresent)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8ca467f7-22e8-4096-8456-bb8aa13f79d8", 5, "XErrorSetOptions", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "optionsDebuggerPresent", optionsDebuggerPresent);
        trace::RecordScalar(call_id, "optionsDebuggerNotPresent", optionsDebuggerNotPresent);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, optionsDebuggerPresent, optionsDebuggerNotPresent);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXGameActivationImpl_slot3_XGameActivationRegisterForEvent(void *self, XTaskQueueHandle queue, void * context, XGameActivationCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XGameActivationCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("2e4f76fe-0fc7-461e-ab4d-a4499434c3cf", 3, "XGameActivationRegisterForEvent", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XGameActivationCallback>(call_id, "XGameActivationCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XGameActivationCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXGameActivationImpl_slot4_XGameActivationUnregisterForEvent(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("2e4f76fe-0fc7-461e-ab4d-a4499434c3cf", 4, "XGameActivationUnregisterForEvent", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameActivationImpl_slot5_XGameActivationAcceptPendingInvite(void *self, const char * inviteUri)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * inviteUri)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("2e4f76fe-0fc7-461e-ab4d-a4499434c3cf", 5, "XGameActivationAcceptPendingInvite", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "inviteUri", inviteUri, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, inviteUri);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameEventImpl_slot3_XGameEventWrite(void *self, XUserHandle user, const char * serviceConfigId, const char * playSessionId, const char * eventName, const char * dimensionsJson, const char * measurementsJson)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, const char * serviceConfigId, const char * playSessionId, const char * eventName, const char * dimensionsJson, const char * measurementsJson)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("bbfbdcc7-bfe7-409b-a5ca-edf054960b4d", 3, "XGameEventWrite", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordInputString(call_id, "serviceConfigId", serviceConfigId, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "playSessionId", playSessionId, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "eventName", eventName, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "dimensionsJson", dimensionsJson, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "measurementsJson", measurementsJson, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, serviceConfigId, playSessionId, eventName, dimensionsJson, measurementsJson);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameImpl_slot3_XGameGetXboxTitleId(void *self, UINT32 * titleId)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, UINT32 * titleId)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("973a344e-24bf-4d0f-8457-56c534892b29", 3, "XGameGetXboxTitleId", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "titleId", reinterpret_cast<const void *>(titleId), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, titleId);
    try {
        trace::RecordOutputObject(call_id, "titleId", titleId, "UINT32 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXGameImpl2_slot4_XLaunchNewGame(void *self, const char * exePath, const char * args, XUserHandle defaultUser)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, const char * exePath, const char * args, XUserHandle defaultUser)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("50849859-0ad8-4f81-80e4-5bc78626f852", 4, "XLaunchNewGame", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "exePath", reinterpret_cast<const void *>(exePath), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "args", reinterpret_cast<const void *>(args), trace::ArgumentKind::Pointer);
        trace::RecordHandleArgumentValue(call_id, "defaultUser", defaultUser, "XUserHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, exePath, args, defaultUser);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXGameImpl3_slot5_XLaunchRestartOnCrash(void *self, const char * args, UINT32 reserved)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * args, UINT32 reserved)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("2549f142-6419-4a06-97b5-931aab7c2f34", 5, "XLaunchRestartOnCrash", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "args", reinterpret_cast<const void *>(args), trace::ArgumentKind::Pointer);
        trace::RecordScalar(call_id, "reserved", reserved);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, args, reserved);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameInviteImpl_slot3_XGameInviteRegisterForEvent(void *self, XTaskQueueHandle queue, void * context, XGameInviteEventCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XGameInviteEventCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0651aae2-4012-4077-bf84-8b9097090e2c", 3, "XGameInviteRegisterForEvent", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XGameInviteEventCallback>(call_id, "XGameInviteEventCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XGameInviteEventCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXGameInviteImpl_slot4_XGameInviteUnregisterForEvent(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0651aae2-4012-4077-bf84-8b9097090e2c", 4, "XGameInviteUnregisterForEvent", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameInviteImpl2_slot5_XGameInviteRegisterForPendingEvent(void *self, XTaskQueueHandle queue, void * context, XGameInviteEventCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XGameInviteEventCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("014d1cc3-bcfe-41ff-b2f0-e1ef07155828", 5, "XGameInviteRegisterForPendingEvent", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XGameInviteEventCallback>(call_id, "XGameInviteEventCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XGameInviteEventCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXGameInviteImpl2_slot6_XGameInviteUnregisterForPendingEvent(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("014d1cc3-bcfe-41ff-b2f0-e1ef07155828", 6, "XGameInviteUnregisterForPendingEvent", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameInviteImpl2_slot7_XGameInviteAcceptPendingInvite(void *self, const char * inviteUri)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * inviteUri)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("014d1cc3-bcfe-41ff-b2f0-e1ef07155828", 7, "XGameInviteAcceptPendingInvite", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "inviteUri", inviteUri, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, inviteUri);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameProtocolImpl_slot3_XGameProtocolRegisterForActivation(void *self, XTaskQueueHandle queue, void * context, XGameProtocolActivationCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XGameProtocolActivationCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("026b010c-06c3-4cdd-bbcb-43f229db1cff", 3, "XGameProtocolRegisterForActivation", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XGameProtocolActivationCallback>(call_id, "XGameProtocolActivationCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XGameProtocolActivationCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXGameProtocolImpl_slot4_XGameProtocolUnregisterForActivation(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("026b010c-06c3-4cdd-bbcb-43f229db1cff", 4, "XGameProtocolUnregisterForActivation", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXGameRuntimeFeatureImpl_slot3_XGameRuntimeIsFeatureAvailable(void *self, XGameRuntimeFeature feature)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XGameRuntimeFeature feature)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8836fe87-edb9-4fe3-8dad-05f0d2cd5b40", 3, "XGameRuntimeIsFeatureAvailable", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "feature", feature);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, feature);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot3_XGameSaveInitializeProvider(void *self, XUserHandle requestingUser, const char * configurationId, BOOLEAN syncOnDemand, XGameSaveProviderHandle * provider)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle requestingUser, const char * configurationId, BOOLEAN syncOnDemand, XGameSaveProviderHandle * provider)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 3, "XGameSaveInitializeProvider", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
        trace::RecordInputString(call_id, "configurationId", configurationId, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "syncOnDemand", syncOnDemand);
        trace::RecordPointer(call_id, "provider", reinterpret_cast<const void *>(provider), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, requestingUser, configurationId, syncOnDemand, provider);
    try {
        trace::RecordOutputHandleObject(call_id, "provider", provider, "XGameSaveProviderHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot4_XGameSaveInitializeProviderAsync(void *self, XUserHandle requestingUser, const char * configurationId, BOOLEAN syncOnDemand, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle requestingUser, const char * configurationId, BOOLEAN syncOnDemand, XAsyncBlock * async)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 4, "XGameSaveInitializeProviderAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
        trace::RecordInputString(call_id, "configurationId", configurationId, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "syncOnDemand", syncOnDemand);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, requestingUser, configurationId, syncOnDemand, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot5_XGameSaveInitializeProviderResult(void *self, XAsyncBlock * async, XGameSaveProviderHandle * provider)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XGameSaveProviderHandle * provider)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 5, "XGameSaveInitializeProviderResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "provider", reinterpret_cast<const void *>(provider), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, provider);
    try {
        trace::RecordOutputHandleObject(call_id, "provider", provider, "XGameSaveProviderHandle *");
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXGameSaveImpl_slot6_XGameSaveCloseProvider(void *self, XGameSaveProviderHandle provider)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XGameSaveProviderHandle provider)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 6, "XGameSaveCloseProvider", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "provider", provider, "XGameSaveProviderHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, provider);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot7_XGameSaveGetRemainingQuota(void *self, XGameSaveProviderHandle provider, INT64 * remainingQuota)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveProviderHandle provider, INT64 * remainingQuota)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 7, "XGameSaveGetRemainingQuota", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "provider", provider, "XGameSaveProviderHandle");
        trace::RecordPointer(call_id, "remainingQuota", reinterpret_cast<const void *>(remainingQuota), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, provider, remainingQuota);
    try {
        trace::RecordOutputObject(call_id, "remainingQuota", remainingQuota, "INT64 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot8_XGameSaveGetRemainingQuotaAsync(void *self, XGameSaveProviderHandle provider, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveProviderHandle provider, XAsyncBlock * async)>(trace::OriginalSlot(self, 8));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 8, "XGameSaveGetRemainingQuotaAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "provider", provider, "XGameSaveProviderHandle");
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, provider, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot9_XGameSaveGetRemainingQuotaResult(void *self, XAsyncBlock * async, INT64 * remainingQuota)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, INT64 * remainingQuota)>(trace::OriginalSlot(self, 9));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 9, "XGameSaveGetRemainingQuotaResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "remainingQuota", reinterpret_cast<const void *>(remainingQuota), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, remainingQuota);
    try {
        trace::RecordOutputObject(call_id, "remainingQuota", remainingQuota, "INT64 *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot10_XGameSaveDeleteContainer(void *self, XGameSaveProviderHandle provider, const char * containerName)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveProviderHandle provider, const char * containerName)>(trace::OriginalSlot(self, 10));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 10, "XGameSaveDeleteContainer", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "provider", provider, "XGameSaveProviderHandle");
        trace::RecordInputString(call_id, "containerName", containerName, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, provider, containerName);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot11_XGameSaveDeleteContainerAsync(void *self, XGameSaveProviderHandle provider, const char * containerName, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveProviderHandle provider, const char * containerName, XAsyncBlock * async)>(trace::OriginalSlot(self, 11));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 11, "XGameSaveDeleteContainerAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "provider", provider, "XGameSaveProviderHandle");
        trace::RecordInputString(call_id, "containerName", containerName, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, provider, containerName, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot12_XGameSaveDeleteContainerResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 12));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 12, "XGameSaveDeleteContainerResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot13_XGameSaveGetContainerInfo(void *self, XGameSaveProviderHandle provider, const char * containerName, void * context, XGameSaveContainerInfoCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveProviderHandle provider, const char * containerName, void * context, XGameSaveContainerInfoCallback * callback)>(trace::OriginalSlot(self, 13));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 13, "XGameSaveGetContainerInfo", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "provider", provider, "XGameSaveProviderHandle");
        trace::RecordInputString(call_id, "containerName", containerName, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, provider, containerName, context, trace::WrapCallback<XGameSaveContainerInfoCallback>(call_id, "XGameSaveContainerInfoCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XGameSaveContainerInfoCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot14_XGameSaveEnumerateContainerInfo(void *self, XGameSaveProviderHandle provider, void * context, XGameSaveContainerInfoCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveProviderHandle provider, void * context, XGameSaveContainerInfoCallback * callback)>(trace::OriginalSlot(self, 14));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 14, "XGameSaveEnumerateContainerInfo", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "provider", provider, "XGameSaveProviderHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, provider, context, trace::WrapCallback<XGameSaveContainerInfoCallback>(call_id, "XGameSaveContainerInfoCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XGameSaveContainerInfoCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot15_XGameSaveEnumerateContainerInfoByName(void *self, XGameSaveProviderHandle provider, const char * containerNamePrefix, void * context, XGameSaveContainerInfoCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveProviderHandle provider, const char * containerNamePrefix, void * context, XGameSaveContainerInfoCallback * callback)>(trace::OriginalSlot(self, 15));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 15, "XGameSaveEnumerateContainerInfoByName", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "provider", provider, "XGameSaveProviderHandle");
        trace::RecordInputString(call_id, "containerNamePrefix", containerNamePrefix, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, provider, containerNamePrefix, context, trace::WrapCallback<XGameSaveContainerInfoCallback>(call_id, "XGameSaveContainerInfoCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XGameSaveContainerInfoCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot16_XGameSaveCreateContainer(void *self, XGameSaveProviderHandle provider, const char * containerName, XGameSaveContainerHandle * containerContext)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveProviderHandle provider, const char * containerName, XGameSaveContainerHandle * containerContext)>(trace::OriginalSlot(self, 16));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 16, "XGameSaveCreateContainer", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "provider", provider, "XGameSaveProviderHandle");
        trace::RecordInputString(call_id, "containerName", containerName, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "containerContext", reinterpret_cast<const void *>(containerContext), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, provider, containerName, containerContext);
    try {
        trace::RecordOutputHandleObject(call_id, "containerContext", containerContext, "XGameSaveContainerHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXGameSaveImpl_slot17_XGameSaveCloseContainer(void *self, XGameSaveContainerHandle context)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XGameSaveContainerHandle context)>(trace::OriginalSlot(self, 17));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 17, "XGameSaveCloseContainer", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "context", context, "XGameSaveContainerHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, context);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot18_XGameSaveEnumerateBlobInfo(void *self, XGameSaveContainerHandle container, void * context, XGameSaveBlobInfoCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveContainerHandle container, void * context, XGameSaveBlobInfoCallback * callback)>(trace::OriginalSlot(self, 18));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 18, "XGameSaveEnumerateBlobInfo", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "container", container, "XGameSaveContainerHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, container, context, trace::WrapCallback<XGameSaveBlobInfoCallback>(call_id, "XGameSaveBlobInfoCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XGameSaveBlobInfoCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot19_XGameSaveEnumerateBlobInfoByName(void *self, XGameSaveContainerHandle container, const char * blobNamePrefix, void * context, XGameSaveBlobInfoCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveContainerHandle container, const char * blobNamePrefix, void * context, XGameSaveBlobInfoCallback * callback)>(trace::OriginalSlot(self, 19));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 19, "XGameSaveEnumerateBlobInfoByName", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "container", container, "XGameSaveContainerHandle");
        trace::RecordInputString(call_id, "blobNamePrefix", blobNamePrefix, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, container, blobNamePrefix, context, trace::WrapCallback<XGameSaveBlobInfoCallback>(call_id, "XGameSaveBlobInfoCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XGameSaveBlobInfoCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot20_XGameSaveReadBlobData(void *self, XGameSaveContainerHandle container, const char ** blobNames, UINT32 * countOfBlobs, SIZE_T blobsSize, XGameSaveBlob * blobData)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveContainerHandle container, const char ** blobNames, UINT32 * countOfBlobs, SIZE_T blobsSize, XGameSaveBlob * blobData)>(trace::OriginalSlot(self, 20));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 20, "XGameSaveReadBlobData", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "container", container, "XGameSaveContainerHandle");
        trace::RecordInputStringArrayFromCountPointer(call_id, "blobNames", reinterpret_cast<const void *>(blobNames), reinterpret_cast<const void *>(countOfBlobs), sizeof(*countOfBlobs), static_cast<std::size_t>(0), false, false);
        trace::RecordPointer(call_id, "countOfBlobs", reinterpret_cast<const void *>(countOfBlobs), trace::ArgumentKind::Pointer);
        trace::RecordScalar(call_id, "blobsSize", blobsSize);
        trace::RecordPointer(call_id, "blobData", reinterpret_cast<const void *>(blobData), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, container, blobNames, countOfBlobs, blobsSize, blobData);
    try {
        trace::RecordOutputObject(call_id, "countOfBlobs", countOfBlobs, "UINT32 *", false);
        trace::RecordOutputBuffer(call_id, "blobData", reinterpret_cast<const void *>(blobData), static_cast<std::size_t>(blobsSize), reinterpret_cast<const void *>(nullptr), 0, 1, "XGameSaveBlob *", trace::OutputEncoding::Binary, false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot21_XGameSaveReadBlobDataAsync(void *self, XGameSaveContainerHandle container, const char ** blobNames, UINT32 countOfBlobs, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveContainerHandle container, const char ** blobNames, UINT32 countOfBlobs, XAsyncBlock * async)>(trace::OriginalSlot(self, 21));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 21, "XGameSaveReadBlobDataAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "container", container, "XGameSaveContainerHandle");
        trace::RecordInputStringArray(call_id, "blobNames", reinterpret_cast<const void *>(blobNames), static_cast<std::size_t>(countOfBlobs), static_cast<std::size_t>(0), false, false);
        trace::RecordScalar(call_id, "countOfBlobs", countOfBlobs);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, container, blobNames, countOfBlobs, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot22_XGameSaveReadBlobDataResult(void *self, XAsyncBlock * async, SIZE_T blobsSize, XGameSaveBlob * blobData, UINT32 * countOfBlobs)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T blobsSize, XGameSaveBlob * blobData, UINT32 * countOfBlobs)>(trace::OriginalSlot(self, 22));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 22, "XGameSaveReadBlobDataResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "blobsSize", blobsSize);
        trace::RecordPointer(call_id, "blobData", reinterpret_cast<const void *>(blobData), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "countOfBlobs", reinterpret_cast<const void *>(countOfBlobs), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, blobsSize, blobData, countOfBlobs);
    try {
        trace::RecordOutputBuffer(call_id, "blobData", reinterpret_cast<const void *>(blobData), static_cast<std::size_t>(blobsSize), reinterpret_cast<const void *>(nullptr), 0, 1, "XGameSaveBlob *", trace::OutputEncoding::Binary, false);
        trace::RecordOutputObject(call_id, "countOfBlobs", countOfBlobs, "UINT32 *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot23_XGameSaveCreateUpdate(void *self, XGameSaveContainerHandle container, const char * containerDisplayName, XGameSaveUpdateHandle * updateContext)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveContainerHandle container, const char * containerDisplayName, XGameSaveUpdateHandle * updateContext)>(trace::OriginalSlot(self, 23));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 23, "XGameSaveCreateUpdate", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "container", container, "XGameSaveContainerHandle");
        trace::RecordInputString(call_id, "containerDisplayName", containerDisplayName, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "updateContext", reinterpret_cast<const void *>(updateContext), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, container, containerDisplayName, updateContext);
    try {
        trace::RecordOutputHandleObject(call_id, "updateContext", updateContext, "XGameSaveUpdateHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXGameSaveImpl_slot24_XGameSaveCloseUpdate(void *self, XGameSaveUpdateHandle context)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XGameSaveUpdateHandle context)>(trace::OriginalSlot(self, 24));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 24, "XGameSaveCloseUpdate", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "context", context, "XGameSaveUpdateHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, context);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot25_XGameSaveSubmitBlobWrite(void *self, XGameSaveUpdateHandle updateContext, const char * blobName, UINT8 * data, SIZE_T byteCount)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveUpdateHandle updateContext, const char * blobName, UINT8 * data, SIZE_T byteCount)>(trace::OriginalSlot(self, 25));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 25, "XGameSaveSubmitBlobWrite", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "updateContext", updateContext, "XGameSaveUpdateHandle");
        trace::RecordInputString(call_id, "blobName", blobName, trace::ArgumentKind::String);
        trace::RecordInputBuffer(call_id, "data", reinterpret_cast<const void *>(data), static_cast<std::size_t>(byteCount), "UINT8 *", false);
        trace::RecordScalar(call_id, "byteCount", byteCount);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, updateContext, blobName, data, byteCount);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot26_XGameSaveSubmitBlobDelete(void *self, XGameSaveUpdateHandle updateContext, const char * blobName)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveUpdateHandle updateContext, const char * blobName)>(trace::OriginalSlot(self, 26));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 26, "XGameSaveSubmitBlobDelete", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "updateContext", updateContext, "XGameSaveUpdateHandle");
        trace::RecordInputString(call_id, "blobName", blobName, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, updateContext, blobName);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot27_XGameSaveSubmitUpdate(void *self, XGameSaveUpdateHandle updateContext)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveUpdateHandle updateContext)>(trace::OriginalSlot(self, 27));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 27, "XGameSaveSubmitUpdate", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "updateContext", updateContext, "XGameSaveUpdateHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, updateContext);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot28_XGameSaveSubmitUpdateAsync(void *self, XGameSaveUpdateHandle updateContext, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameSaveUpdateHandle updateContext, XAsyncBlock * async)>(trace::OriginalSlot(self, 28));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 28, "XGameSaveSubmitUpdateAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "updateContext", updateContext, "XGameSaveUpdateHandle");
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, updateContext, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl_slot29_XGameSaveSubmitUpdateResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 29));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996fe2", 29, "XGameSaveSubmitUpdateResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl2_slot30_XGameSaveFilesGetFolderWithUiAsync(void *self, XUserHandle requestingUser, const char * configurationId, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle requestingUser, const char * configurationId, XAsyncBlock * async)>(trace::OriginalSlot(self, 30));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996ee2", 30, "XGameSaveFilesGetFolderWithUiAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
        trace::RecordInputString(call_id, "configurationId", configurationId, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, requestingUser, configurationId, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl2_slot31_XGameSaveFilesGetFolderWithUiResult(void *self, XAsyncBlock * async, SIZE_T folderSize, char * folderResult)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T folderSize, char * folderResult)>(trace::OriginalSlot(self, 31));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996ee2", 31, "XGameSaveFilesGetFolderWithUiResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "folderSize", folderSize);
        trace::RecordPointer(call_id, "folderResult", reinterpret_cast<const void *>(folderResult), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, folderSize, folderResult);
    try {
        trace::RecordOutputBuffer(call_id, "folderResult", reinterpret_cast<const void *>(folderResult), (static_cast<std::size_t>(folderSize)) * sizeof(*folderResult), reinterpret_cast<const void *>(nullptr), 0, sizeof(*folderResult), "char *", trace::OutputEncoding::Binary, false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameSaveImpl2_slot32_XGameSaveFilesGetRemainingQuota(void *self, XUserHandle userContext, const char * configurationId, INT64 * remainingQuota)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle userContext, const char * configurationId, INT64 * remainingQuota)>(trace::OriginalSlot(self, 32));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("704c3f58-e629-4cc2-b197-30511b996ee2", 32, "XGameSaveFilesGetRemainingQuota", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "userContext", userContext, "XUserHandle");
        trace::RecordInputString(call_id, "configurationId", configurationId, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "remainingQuota", reinterpret_cast<const void *>(remainingQuota), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, userContext, configurationId, remainingQuota);
    try {
        trace::RecordOutputObject(call_id, "remainingQuota", remainingQuota, "INT64 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot3_XGameStreamingInitialize(void *self)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 3, "XGameStreamingInitialize", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot4_XGameStreamingUninitialize(void *self)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 4, "XGameStreamingUninitialize", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

BOOLEAN WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot5_XGameStreamingIsStreaming(void *self)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 5, "XGameStreamingIsStreaming", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot6_XGameStreamingRegisterClientPropertiesChanged(void *self, XGameStreamingClientId client, XTaskQueueHandle queue, void * context, XGameStreamingClientPropertiesChangedCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameStreamingClientId client, XTaskQueueHandle queue, void * context, XGameStreamingClientPropertiesChangedCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 6, "XGameStreamingRegisterClientPropertiesChanged", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, client, queue, context, trace::WrapCallback<XGameStreamingClientPropertiesChangedCallback>(call_id, "XGameStreamingClientPropertiesChangedCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XGameStreamingClientPropertiesChangedCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot7_XGameStreamingUnregisterClientPropertiesChanged(void *self, XGameStreamingClientId client, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XGameStreamingClientId client, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 7, "XGameStreamingUnregisterClientPropertiesChanged", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, client, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot8_XGameStreamingGetStreamPhysicalDimensions(void *self, XGameStreamingClientId client, UINT32 * horizontalMm, UINT32 * verticalMm)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameStreamingClientId client, UINT32 * horizontalMm, UINT32 * verticalMm)>(trace::OriginalSlot(self, 8));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 8, "XGameStreamingGetStreamPhysicalDimensions", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
        trace::RecordPointer(call_id, "horizontalMm", reinterpret_cast<const void *>(horizontalMm), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "verticalMm", reinterpret_cast<const void *>(verticalMm), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, client, horizontalMm, verticalMm);
    try {
        trace::RecordOutputObject(call_id, "horizontalMm", horizontalMm, "UINT32 *", false);
        trace::RecordOutputObject(call_id, "verticalMm", verticalMm, "UINT32 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

UINT32 WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot9_XGameStreamingGetClientCount(void *self)
{
    auto original = reinterpret_cast<UINT32 (WINAPI *)(void *self)>(trace::OriginalSlot(self, 9));
    if (!original) {
        return {};
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 9, "XGameStreamingGetClientCount", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot10_XGameStreamingGetClients(void *self, UINT32 clientCount, XGameStreamingClientId * clients, UINT32 * clientsUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, UINT32 clientCount, XGameStreamingClientId * clients, UINT32 * clientsUsed)>(trace::OriginalSlot(self, 10));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 10, "XGameStreamingGetClients", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "clientCount", clientCount);
        trace::RecordPointer(call_id, "clients", reinterpret_cast<const void *>(clients), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "clientsUsed", reinterpret_cast<const void *>(clientsUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, clientCount, clients, clientsUsed);
    try {
        trace::RecordOutputBuffer(call_id, "clients", reinterpret_cast<const void *>(clients), (static_cast<std::size_t>(clientCount)) * sizeof(*clients), reinterpret_cast<const void *>(clientsUsed), sizeof(*clientsUsed), sizeof(*clients), "XGameStreamingClientId *", trace::OutputEncoding::Binary, false);
        trace::RecordOutputObject(call_id, "clientsUsed", clientsUsed, "UINT32 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

XGameStreamingConnectionState WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot11_XGameStreamingGetConnectionState(void *self, XGameStreamingClientId client)
{
    auto original = reinterpret_cast<XGameStreamingConnectionState (WINAPI *)(void *self, XGameStreamingClientId client)>(trace::OriginalSlot(self, 11));
    if (!original) {
        return {};
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 11, "XGameStreamingGetConnectionState", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, client);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot12_XGameStreamingRegisterConnectionStateChanged(void *self, XTaskQueueHandle queue, void * context, XGameStreamingConnectionStateChangedCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XGameStreamingConnectionStateChangedCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 12));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 12, "XGameStreamingRegisterConnectionStateChanged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XGameStreamingConnectionStateChangedCallback>(call_id, "XGameStreamingConnectionStateChangedCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XGameStreamingConnectionStateChangedCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot13_XGameStreamingUnregisterConnectionStateChanged(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 13));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 13, "XGameStreamingUnregisterConnectionStateChanged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot14_XGameStreamingGetStreamAddedLatency(void *self, XGameStreamingClientId client, UINT32 * averageInputLatencyUs, UINT32 * averageOutputLatencyUs, UINT32 * standardDeviationUs)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameStreamingClientId client, UINT32 * averageInputLatencyUs, UINT32 * averageOutputLatencyUs, UINT32 * standardDeviationUs)>(trace::OriginalSlot(self, 14));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 14, "XGameStreamingGetStreamAddedLatency", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
        trace::RecordPointer(call_id, "averageInputLatencyUs", reinterpret_cast<const void *>(averageInputLatencyUs), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "averageOutputLatencyUs", reinterpret_cast<const void *>(averageOutputLatencyUs), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "standardDeviationUs", reinterpret_cast<const void *>(standardDeviationUs), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, client, averageInputLatencyUs, averageOutputLatencyUs, standardDeviationUs);
    try {
        trace::RecordOutputObject(call_id, "averageInputLatencyUs", averageInputLatencyUs, "UINT32 *", false);
        trace::RecordOutputObject(call_id, "averageOutputLatencyUs", averageOutputLatencyUs, "UINT32 *", false);
        trace::RecordOutputObject(call_id, "standardDeviationUs", standardDeviationUs, "UINT32 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

SIZE_T WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot15_XGameStreamingGetServerLocationNameSize(void *self)
{
    auto original = reinterpret_cast<SIZE_T (WINAPI *)(void *self)>(trace::OriginalSlot(self, 15));
    if (!original) {
        return {};
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 15, "XGameStreamingGetServerLocationNameSize", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot16_XGameStreamingGetServerLocationName(void *self, SIZE_T serverLocationNameSize, char * serverLocationName)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, SIZE_T serverLocationNameSize, char * serverLocationName)>(trace::OriginalSlot(self, 16));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 16, "XGameStreamingGetServerLocationName", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "serverLocationNameSize", serverLocationNameSize);
        trace::RecordPointer(call_id, "serverLocationName", reinterpret_cast<const void *>(serverLocationName), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, serverLocationNameSize, serverLocationName);
    try {
        trace::RecordOutputBuffer(call_id, "serverLocationName", reinterpret_cast<const void *>(serverLocationName), (static_cast<std::size_t>(serverLocationNameSize)) * sizeof(*serverLocationName), reinterpret_cast<const void *>(nullptr), 0, sizeof(*serverLocationName), "char *", trace::OutputEncoding::Ansi, false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot17_XGameStreamingHideTouchControls(void *self)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self)>(trace::OriginalSlot(self, 17));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 17, "XGameStreamingHideTouchControls", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

void WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot18_XGameStreamingShowTouchControlLayout(void *self, const char * layout)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, const char * layout)>(trace::OriginalSlot(self, 18));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 18, "XGameStreamingShowTouchControlLayout", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "layout", layout, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, layout);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

void WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot19_XGameStreamingHideTouchControlsOnClient(void *self, XGameStreamingClientId client)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XGameStreamingClientId client)>(trace::OriginalSlot(self, 19));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 19, "XGameStreamingHideTouchControlsOnClient", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, client);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

void WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot20_XGameStreamingShowTouchControlLayoutOnClient(void *self, XGameStreamingClientId client, const char * layout)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XGameStreamingClientId client, const char * layout)>(trace::OriginalSlot(self, 20));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 20, "XGameStreamingShowTouchControlLayoutOnClient", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
        trace::RecordInputString(call_id, "layout", layout, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, client, layout);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot21_XGameStreamingIsTouchInputEnabled(void *self, XGameStreamingClientId client, BOOLEAN * touchInputEnabled)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameStreamingClientId client, BOOLEAN * touchInputEnabled)>(trace::OriginalSlot(self, 21));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 21, "XGameStreamingIsTouchInputEnabled", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
        trace::RecordPointer(call_id, "touchInputEnabled", reinterpret_cast<const void *>(touchInputEnabled), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, client, touchInputEnabled);
    try {
        trace::RecordOutputObject(call_id, "touchInputEnabled", touchInputEnabled, "BOOLEAN *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot22_XGameStreamingGetLastFrameDisplayed(void *self, XGameStreamingClientId client, D3D12XBOX_FRAME_PIPELINE_TOKEN * framePipelineToken)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameStreamingClientId client, D3D12XBOX_FRAME_PIPELINE_TOKEN * framePipelineToken)>(trace::OriginalSlot(self, 22));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 22, "XGameStreamingGetLastFrameDisplayed", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
        trace::RecordPointer(call_id, "framePipelineToken", reinterpret_cast<const void *>(framePipelineToken), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, client, framePipelineToken);
    try {
        trace::RecordOutputObject(call_id, "framePipelineToken", framePipelineToken, "D3D12XBOX_FRAME_PIPELINE_TOKEN *", true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot23_XGameStreamingGetAssociatedFrame(void *self, IGameInputReading * gamepadReading, D3D12XBOX_FRAME_PIPELINE_TOKEN * framePipelineToken)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, IGameInputReading * gamepadReading, D3D12XBOX_FRAME_PIPELINE_TOKEN * framePipelineToken)>(trace::OriginalSlot(self, 23));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 23, "XGameStreamingGetAssociatedFrame", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "gamepadReading", reinterpret_cast<const void *>(gamepadReading), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "framePipelineToken", reinterpret_cast<const void *>(framePipelineToken), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, gamepadReading, framePipelineToken);
    try {
        trace::RecordOutputObject(call_id, "framePipelineToken", framePipelineToken, "D3D12XBOX_FRAME_PIPELINE_TOKEN *", true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot24_XGameStreamingGetGamepadPhysicality(void *self, IGameInputReading * gamepadReading, XGameStreamingGamepadPhysicality * gamepadPhysicality)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, IGameInputReading * gamepadReading, XGameStreamingGamepadPhysicality * gamepadPhysicality)>(trace::OriginalSlot(self, 24));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 24, "XGameStreamingGetGamepadPhysicality", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "gamepadReading", reinterpret_cast<const void *>(gamepadReading), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "gamepadPhysicality", reinterpret_cast<const void *>(gamepadPhysicality), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, gamepadReading, gamepadPhysicality);
    try {
        trace::RecordOutputObject(call_id, "gamepadPhysicality", gamepadPhysicality, "XGameStreamingGamepadPhysicality *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot25_XGameStreamingUpdateTouchControlsState(void *self, SIZE_T operationCount, const XGameStreamingTouchControlsStateOperation * operations)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, SIZE_T operationCount, const XGameStreamingTouchControlsStateOperation * operations)>(trace::OriginalSlot(self, 25));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 25, "XGameStreamingUpdateTouchControlsState", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "operationCount", operationCount);
        trace::RecordHandleArgumentValue(call_id, "operations", operations, "const XGameStreamingTouchControlsStateOperation *");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, operationCount, operations);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot26_XGameStreamingUpdateTouchControlsStateOnClient(void *self, XGameStreamingClientId client, SIZE_T operationCount, const XGameStreamingTouchControlsStateOperation * operations)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameStreamingClientId client, SIZE_T operationCount, const XGameStreamingTouchControlsStateOperation * operations)>(trace::OriginalSlot(self, 26));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 26, "XGameStreamingUpdateTouchControlsStateOnClient", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
        trace::RecordScalar(call_id, "operationCount", operationCount);
        trace::RecordHandleArgumentValue(call_id, "operations", operations, "const XGameStreamingTouchControlsStateOperation *");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, client, operationCount, operations);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot27_XGameStreamingShowTouchControlsWithStateUpdate(void *self, const char * layout, SIZE_T operationCount, const XGameStreamingTouchControlsStateOperation * operations)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * layout, SIZE_T operationCount, const XGameStreamingTouchControlsStateOperation * operations)>(trace::OriginalSlot(self, 27));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 27, "XGameStreamingShowTouchControlsWithStateUpdate", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "layout", layout, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "operationCount", operationCount);
        trace::RecordHandleArgumentValue(call_id, "operations", operations, "const XGameStreamingTouchControlsStateOperation *");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, layout, operationCount, operations);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot28_XGameStreamingShowTouchControlsWithStateUpdateOnClient(void *self, XGameStreamingClientId client, const char * layout, SIZE_T operationCount, const XGameStreamingTouchControlsStateOperation * operations)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameStreamingClientId client, const char * layout, SIZE_T operationCount, const XGameStreamingTouchControlsStateOperation * operations)>(trace::OriginalSlot(self, 28));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 28, "XGameStreamingShowTouchControlsWithStateUpdateOnClient", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
        trace::RecordInputString(call_id, "layout", layout, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "operationCount", operationCount);
        trace::RecordHandleArgumentValue(call_id, "operations", operations, "const XGameStreamingTouchControlsStateOperation *");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, client, layout, operationCount, operations);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

SIZE_T WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot29_XGameStreamingGetTouchBundleVersionNameSize(void *self, XGameStreamingClientId client)
{
    auto original = reinterpret_cast<SIZE_T (WINAPI *)(void *self, XGameStreamingClientId client)>(trace::OriginalSlot(self, 29));
    if (!original) {
        return {};
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 29, "XGameStreamingGetTouchBundleVersionNameSize", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, client);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot30_XGameStreamingGetTouchBundleVersion(void *self, XGameStreamingClientId client, XVersion * version, SIZE_T versionNameSize, char * versionName)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameStreamingClientId client, XVersion * version, SIZE_T versionNameSize, char * versionName)>(trace::OriginalSlot(self, 30));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 30, "XGameStreamingGetTouchBundleVersion", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
        trace::RecordPointer(call_id, "version", reinterpret_cast<const void *>(version), trace::ArgumentKind::Out);
        trace::RecordScalar(call_id, "versionNameSize", versionNameSize);
        trace::RecordPointer(call_id, "versionName", reinterpret_cast<const void *>(versionName), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, client, version, versionNameSize, versionName);
    try {
        trace::RecordOutputObject(call_id, "version", version, "XVersion *", false);
        trace::RecordOutputBuffer(call_id, "versionName", reinterpret_cast<const void *>(versionName), (static_cast<std::size_t>(versionNameSize)) * sizeof(*versionName), reinterpret_cast<const void *>(nullptr), 0, sizeof(*versionName), "char *", trace::OutputEncoding::Ansi, false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl_slot31_XGameStreamingGetClientIPAddress(void *self, XGameStreamingClientId client, SIZE_T ipAddressSize, char * ipAddress)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameStreamingClientId client, SIZE_T ipAddressSize, char * ipAddress)>(trace::OriginalSlot(self, 31));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("8aff07f5-a1bf-4db8-80a5-31cca0de51b7", 31, "XGameStreamingGetClientIPAddress", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
        trace::RecordScalar(call_id, "ipAddressSize", ipAddressSize);
        trace::RecordPointer(call_id, "ipAddress", reinterpret_cast<const void *>(ipAddress), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, client, ipAddressSize, ipAddress);
    try {
        trace::RecordOutputBuffer(call_id, "ipAddress", reinterpret_cast<const void *>(ipAddress), (static_cast<std::size_t>(ipAddressSize)) * sizeof(*ipAddress), reinterpret_cast<const void *>(nullptr), 0, sizeof(*ipAddress), "char *", trace::OutputEncoding::Ansi, false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl2_slot32_XGameStreamingGetSessionId(void *self, XGameStreamingClientId client, SIZE_T sessionIdSize, char * sessionId, SIZE_T * sessionIdUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameStreamingClientId client, SIZE_T sessionIdSize, char * sessionId, SIZE_T * sessionIdUsed)>(trace::OriginalSlot(self, 32));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("5f5e5169-746c-4001-ad1c-da728d01c9eb", 32, "XGameStreamingGetSessionId", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
        trace::RecordScalar(call_id, "sessionIdSize", sessionIdSize);
        trace::RecordPointer(call_id, "sessionId", reinterpret_cast<const void *>(sessionId), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "sessionIdUsed", reinterpret_cast<const void *>(sessionIdUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, client, sessionIdSize, sessionId, sessionIdUsed);
    try {
        trace::RecordOutputBuffer(call_id, "sessionId", reinterpret_cast<const void *>(sessionId), (static_cast<std::size_t>(sessionIdSize)) * sizeof(*sessionId), reinterpret_cast<const void *>(sessionIdUsed), sizeof(*sessionIdUsed), sizeof(*sessionId), "char *", trace::OutputEncoding::Ansi, false);
        trace::RecordOutputObject(call_id, "sessionIdUsed", sessionIdUsed, "SIZE_T *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl3_slot33_XGameStreamingGetDisplayDetails(void *self, XGameStreamingClientId client, UINT32 maxSupportedPixels, float widestSupportedAspectRatio, float tallestSupportedAspectRatio, XGameStreamingDisplayDetails * displayDetails)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameStreamingClientId client, UINT32 maxSupportedPixels, float widestSupportedAspectRatio, float tallestSupportedAspectRatio, XGameStreamingDisplayDetails * displayDetails)>(trace::OriginalSlot(self, 33));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("57786622-6605-46d0-b917-0f22bbcd9c52", 33, "XGameStreamingGetDisplayDetails", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "client", client);
        trace::RecordScalar(call_id, "maxSupportedPixels", maxSupportedPixels);
        trace::RecordScalar(call_id, "widestSupportedAspectRatio", widestSupportedAspectRatio);
        trace::RecordScalar(call_id, "tallestSupportedAspectRatio", tallestSupportedAspectRatio);
        trace::RecordPointer(call_id, "displayDetails", reinterpret_cast<const void *>(displayDetails), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, client, maxSupportedPixels, widestSupportedAspectRatio, tallestSupportedAspectRatio, displayDetails);
    try {
        trace::RecordOutputObject(call_id, "displayDetails", displayDetails, "XGameStreamingDisplayDetails *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameStreamingImpl3_slot34_XGameStreamingSetResolution(void *self, UINT32 width, UINT32 height)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, UINT32 width, UINT32 height)>(trace::OriginalSlot(self, 34));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("57786622-6605-46d0-b917-0f22bbcd9c52", 34, "XGameStreamingSetResolution", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "width", width);
        trace::RecordScalar(call_id, "height", height);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, width, height);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot3_XGameUiShowMessageDialogAsync(void *self, XAsyncBlock * async, const char * titleText, const char * contentText, const char * firstButtonText, const char * secondButtonText, const char * thirdButtonText, XGameUiMessageDialogButton defaultButton, XGameUiMessageDialogButton cancelButton)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, const char * titleText, const char * contentText, const char * firstButtonText, const char * secondButtonText, const char * thirdButtonText, XGameUiMessageDialogButton defaultButton, XGameUiMessageDialogButton cancelButton)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 3, "XGameUiShowMessageDialogAsync", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordInputString(call_id, "titleText", titleText, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "contentText", contentText, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "firstButtonText", firstButtonText, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "secondButtonText", secondButtonText, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "thirdButtonText", thirdButtonText, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "defaultButton", defaultButton);
        trace::RecordScalar(call_id, "cancelButton", cancelButton);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, titleText, contentText, firstButtonText, secondButtonText, thirdButtonText, defaultButton, cancelButton);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot4_XGameUiShowMessageDialogResult(void *self, XAsyncBlock * async, XGameUiMessageDialogButton * resultButton)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XGameUiMessageDialogButton * resultButton)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 4, "XGameUiShowMessageDialogResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "resultButton", reinterpret_cast<const void *>(resultButton), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, resultButton);
    try {
        trace::RecordOutputObject(call_id, "resultButton", resultButton, "XGameUiMessageDialogButton *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot5_XGameUiShowSendGameInviteAsync(void *self, XAsyncBlock * async, XUserHandle requestingUser, const char * sessionConfigurationId, const char * sessionTemplateName, const char * sessionId, const char * invitationText, const char * customActivationContext)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XUserHandle requestingUser, const char * sessionConfigurationId, const char * sessionTemplateName, const char * sessionId, const char * invitationText, const char * customActivationContext)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 5, "XGameUiShowSendGameInviteAsync", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
        trace::RecordInputString(call_id, "sessionConfigurationId", sessionConfigurationId, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "sessionTemplateName", sessionTemplateName, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "sessionId", sessionId, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "invitationText", invitationText, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "customActivationContext", customActivationContext, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, requestingUser, sessionConfigurationId, sessionTemplateName, sessionId, invitationText, customActivationContext);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot6_XGameUiShowSendGameInviteResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 6, "XGameUiShowSendGameInviteResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot7_XGameUiShowPlayerProfileCardAsync(void *self, XAsyncBlock * async, XUserHandle requestingUser, UINT64 targetPlayer)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XUserHandle requestingUser, UINT64 targetPlayer)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 7, "XGameUiShowPlayerProfileCardAsync", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
        trace::RecordScalar(call_id, "targetPlayer", targetPlayer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, requestingUser, targetPlayer);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot8_XGameUiShowPlayerProfileCardResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 8));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 8, "XGameUiShowPlayerProfileCardResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot9_XGameUiShowAchievementsAsync(void *self, XAsyncBlock * async, XUserHandle requestingUser, UINT32 titleId)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XUserHandle requestingUser, UINT32 titleId)>(trace::OriginalSlot(self, 9));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 9, "XGameUiShowAchievementsAsync", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
        trace::RecordScalar(call_id, "titleId", titleId);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, requestingUser, titleId);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot10_XGameUiShowAchievementsResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 10));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 10, "XGameUiShowAchievementsResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot11_XGameUiShowPlayerPickerAsync(void *self, XAsyncBlock * async, XUserHandle requestingUser, const char * promptText, UINT32 selectFromPlayersCount, const UINT64 * selectFromPlayers, UINT32 preSelectedPlayersCount, UINT64 * preSelectedPlayers, UINT32 minSelectionCount, UINT32 maxSelectionCount)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XUserHandle requestingUser, const char * promptText, UINT32 selectFromPlayersCount, const UINT64 * selectFromPlayers, UINT32 preSelectedPlayersCount, UINT64 * preSelectedPlayers, UINT32 minSelectionCount, UINT32 maxSelectionCount)>(trace::OriginalSlot(self, 11));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 11, "XGameUiShowPlayerPickerAsync", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
        trace::RecordInputString(call_id, "promptText", promptText, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "selectFromPlayersCount", selectFromPlayersCount);
        trace::RecordInputBuffer(call_id, "selectFromPlayers", reinterpret_cast<const void *>(selectFromPlayers), (static_cast<std::size_t>(selectFromPlayersCount)) * sizeof(*selectFromPlayers), "const UINT64 *", false);
        trace::RecordScalar(call_id, "preSelectedPlayersCount", preSelectedPlayersCount);
        trace::RecordInputBuffer(call_id, "preSelectedPlayers", reinterpret_cast<const void *>(preSelectedPlayers), (static_cast<std::size_t>(preSelectedPlayersCount)) * sizeof(*preSelectedPlayers), "UINT64 *", false);
        trace::RecordScalar(call_id, "minSelectionCount", minSelectionCount);
        trace::RecordScalar(call_id, "maxSelectionCount", maxSelectionCount);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, requestingUser, promptText, selectFromPlayersCount, selectFromPlayers, preSelectedPlayersCount, preSelectedPlayers, minSelectionCount, maxSelectionCount);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot12_XGameUiShowPlayerPickerResultCount(void *self, XAsyncBlock * async, UINT32 * resultPlayersCount)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, UINT32 * resultPlayersCount)>(trace::OriginalSlot(self, 12));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 12, "XGameUiShowPlayerPickerResultCount", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "resultPlayersCount", reinterpret_cast<const void *>(resultPlayersCount), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, resultPlayersCount);
    try {
        trace::RecordOutputObject(call_id, "resultPlayersCount", resultPlayersCount, "UINT32 *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot13_XGameUiShowPlayerPickerResult(void *self, XAsyncBlock * async, UINT32 resultPlayersCount, UINT64 * resultPlayers, UINT32 * resultPlayersUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, UINT32 resultPlayersCount, UINT64 * resultPlayers, UINT32 * resultPlayersUsed)>(trace::OriginalSlot(self, 13));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 13, "XGameUiShowPlayerPickerResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "resultPlayersCount", resultPlayersCount);
        trace::RecordPointer(call_id, "resultPlayers", reinterpret_cast<const void *>(resultPlayers), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "resultPlayersUsed", reinterpret_cast<const void *>(resultPlayersUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, resultPlayersCount, resultPlayers, resultPlayersUsed);
    try {
        trace::RecordOutputBuffer(call_id, "resultPlayers", reinterpret_cast<const void *>(resultPlayers), (static_cast<std::size_t>(resultPlayersCount)) * sizeof(*resultPlayers), reinterpret_cast<const void *>(resultPlayersUsed), sizeof(*resultPlayersUsed), sizeof(*resultPlayers), "UINT64 *", trace::OutputEncoding::Binary, false);
        trace::RecordOutputObject(call_id, "resultPlayersUsed", resultPlayersUsed, "UINT32 *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot14_XGameUiShowErrorDialogAsync(void *self, XAsyncBlock * async, HRESULT errorCode, const char * context)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, HRESULT errorCode, const char * context)>(trace::OriginalSlot(self, 14));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 14, "XGameUiShowErrorDialogAsync", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "errorCode", errorCode);
        trace::RecordInputString(call_id, "context", context, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, errorCode, context);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot15_XGameUiShowErrorDialogResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 15));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 15, "XGameUiShowErrorDialogResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot16_XGameUiSetNotificationPositionHint(void *self, XGameUiNotificationPositionHint position)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameUiNotificationPositionHint position)>(trace::OriginalSlot(self, 16));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 16, "XGameUiSetNotificationPositionHint", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "position", position);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, position);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot17_XGameUiShowTextEntryAsync(void *self, XAsyncBlock * async, const char * titleText, const char * descriptionText, const char * defaultText, XGameUiTextEntryInputScope inputScope, UINT32 maxTextLength)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, const char * titleText, const char * descriptionText, const char * defaultText, XGameUiTextEntryInputScope inputScope, UINT32 maxTextLength)>(trace::OriginalSlot(self, 17));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 17, "XGameUiShowTextEntryAsync", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordInputString(call_id, "titleText", titleText, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "descriptionText", descriptionText, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "defaultText", defaultText, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "inputScope", inputScope);
        trace::RecordScalar(call_id, "maxTextLength", maxTextLength);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, titleText, descriptionText, defaultText, inputScope, maxTextLength);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot18_XGameUiShowTextEntryResultSize(void *self, XAsyncBlock * async, UINT32 * resultTextBufferSize)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, UINT32 * resultTextBufferSize)>(trace::OriginalSlot(self, 18));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 18, "XGameUiShowTextEntryResultSize", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "resultTextBufferSize", reinterpret_cast<const void *>(resultTextBufferSize), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, resultTextBufferSize);
    try {
        trace::RecordOutputObject(call_id, "resultTextBufferSize", resultTextBufferSize, "UINT32 *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot19_XGameUiShowTextEntryResult(void *self, XAsyncBlock * async, UINT32 resultTextBufferSize, char * resultTextBuffer, UINT32 * resultTextBufferUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, UINT32 resultTextBufferSize, char * resultTextBuffer, UINT32 * resultTextBufferUsed)>(trace::OriginalSlot(self, 19));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 19, "XGameUiShowTextEntryResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "resultTextBufferSize", resultTextBufferSize);
        trace::RecordPointer(call_id, "resultTextBuffer", reinterpret_cast<const void *>(resultTextBuffer), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "resultTextBufferUsed", reinterpret_cast<const void *>(resultTextBufferUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, resultTextBufferSize, resultTextBuffer, resultTextBufferUsed);
    try {
        trace::RecordOutputBuffer(call_id, "resultTextBuffer", reinterpret_cast<const void *>(resultTextBuffer), (static_cast<std::size_t>(resultTextBufferSize)) * sizeof(*resultTextBuffer), reinterpret_cast<const void *>(resultTextBufferUsed), sizeof(*resultTextBufferUsed), sizeof(*resultTextBuffer), "char *", trace::OutputEncoding::Binary, false);
        trace::RecordOutputObject(call_id, "resultTextBufferUsed", resultTextBufferUsed, "UINT32 *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot24_XGameUiShowWebAuthenticationAsync(void *self, XAsyncBlock * async, XUserHandle requestingUser, const char * requestUri, const char * completionUri)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XUserHandle requestingUser, const char * requestUri, const char * completionUri)>(trace::OriginalSlot(self, 24));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 24, "XGameUiShowWebAuthenticationAsync", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
        trace::RecordInputString(call_id, "requestUri", requestUri, trace::ArgumentKind::StringSensitive);
        trace::RecordInputString(call_id, "completionUri", completionUri, trace::ArgumentKind::StringSensitive);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, requestingUser, requestUri, completionUri);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot25_XGameUiShowWebAuthenticationResultSize(void *self, XAsyncBlock * async, SIZE_T * bufferSize)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T * bufferSize)>(trace::OriginalSlot(self, 25));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 25, "XGameUiShowWebAuthenticationResultSize", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "bufferSize", reinterpret_cast<const void *>(bufferSize), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, bufferSize);
    try {
        trace::RecordOutputObject(call_id, "bufferSize", bufferSize, "SIZE_T *", true);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot26_XGameUiShowWebAuthenticationResult(void *self, XAsyncBlock * async, SIZE_T bufferSize, void * buffer, XGameUiWebAuthenticationResultData ** ptrToBuffer, SIZE_T * bufferUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T bufferSize, void * buffer, XGameUiWebAuthenticationResultData ** ptrToBuffer, SIZE_T * bufferUsed)>(trace::OriginalSlot(self, 26));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 26, "XGameUiShowWebAuthenticationResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "bufferSize", bufferSize);
        trace::RecordPointer(call_id, "buffer", reinterpret_cast<const void *>(buffer), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "ptrToBuffer", reinterpret_cast<const void *>(ptrToBuffer), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "bufferUsed", reinterpret_cast<const void *>(bufferUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, bufferSize, buffer, ptrToBuffer, bufferUsed);
    try {
        trace::RecordOutputBuffer(call_id, "buffer", reinterpret_cast<const void *>(buffer), (static_cast<std::size_t>(bufferSize)) * 1, reinterpret_cast<const void *>(bufferUsed), sizeof(*bufferUsed), 1, "void *", trace::OutputEncoding::Binary, true);
        trace::RecordOutputPointeeValue(call_id, "ptrToBuffer", reinterpret_cast<const void *>(ptrToBuffer), sizeof(*ptrToBuffer), sizeof(**ptrToBuffer), "XGameUiWebAuthenticationResultData **", true);
        trace::RecordOutputObject(call_id, "bufferUsed", bufferUsed, "SIZE_T *", true);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl_slot27_XGameUiShowWebAuthenticationWithOptionsAsync(void *self, XAsyncBlock * async, XUserHandle requestingUser, const char * requestUri, const char * completionUri, XGameUiWebAuthenticationOptions options)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XUserHandle requestingUser, const char * requestUri, const char * completionUri, XGameUiWebAuthenticationOptions options)>(trace::OriginalSlot(self, 27));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("6eeaa73e-9669-43ad-a2c7-d0da4e1f50a1", 27, "XGameUiShowWebAuthenticationWithOptionsAsync", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
        trace::RecordInputString(call_id, "requestUri", requestUri, trace::ArgumentKind::StringSensitive);
        trace::RecordInputString(call_id, "completionUri", completionUri, trace::ArgumentKind::StringSensitive);
        trace::RecordScalar(call_id, "options", options);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, requestingUser, requestUri, completionUri, options);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl2_slot30_XGameUiShowMultiplayerActivityGameInviteAsync(void *self, XAsyncBlock * async, XUserHandle requestingUser)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XUserHandle requestingUser)>(trace::OriginalSlot(self, 30));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("36a03122-9ea3-4a3a-a8a4-899cfd85d7db", 30, "XGameUiShowMultiplayerActivityGameInviteAsync", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, requestingUser);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl2_slot31_XGameUiShowMultiplayerActivityGameInviteResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 31));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("36a03122-9ea3-4a3a-a8a4-899cfd85d7db", 31, "XGameUiShowMultiplayerActivityGameInviteResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl2_slot34_XGameUiTextEntryOpen(void *self, const XGameUiTextEntryOptions * options, UINT32 maxLength, const char * initialText, UINT32 initialCursorIndex, XGameUiTextEntryHandle * handle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XGameUiTextEntryOptions * options, UINT32 maxLength, const char * initialText, UINT32 initialCursorIndex, XGameUiTextEntryHandle * handle)>(trace::OriginalSlot(self, 34));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("36a03122-9ea3-4a3a-a8a4-899cfd85d7db", 34, "XGameUiTextEntryOpen", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "options", reinterpret_cast<const void *>(options), trace::ArgumentKind::Pointer);
        trace::RecordScalar(call_id, "maxLength", maxLength);
        trace::RecordInputString(call_id, "initialText", initialText, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "initialCursorIndex", initialCursorIndex);
        trace::RecordPointer(call_id, "handle", reinterpret_cast<const void *>(handle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, options, maxLength, initialText, initialCursorIndex, handle);
    try {
        trace::RecordOutputHandleObject(call_id, "handle", handle, "XGameUiTextEntryHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl2_slot35_XGameUiTextEntryClose(void *self, XGameUiTextEntryHandle handle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameUiTextEntryHandle handle)>(trace::OriginalSlot(self, 35));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("36a03122-9ea3-4a3a-a8a4-899cfd85d7db", 35, "XGameUiTextEntryClose", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "handle", handle, "XGameUiTextEntryHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, handle);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl2_slot36_XGameUiTextEntryGetState(void *self, XGameUiTextEntryHandle handle, XGameUiTextEntryChangeTypeFlags * changeType, UINT32 * cursorIndex, UINT32 * imeClauseStartIndex, UINT32 * imeClauseEndIndex, UINT32 bufferSize, char * buffer)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameUiTextEntryHandle handle, XGameUiTextEntryChangeTypeFlags * changeType, UINT32 * cursorIndex, UINT32 * imeClauseStartIndex, UINT32 * imeClauseEndIndex, UINT32 bufferSize, char * buffer)>(trace::OriginalSlot(self, 36));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("36a03122-9ea3-4a3a-a8a4-899cfd85d7db", 36, "XGameUiTextEntryGetState", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "handle", handle, "XGameUiTextEntryHandle");
        trace::RecordPointer(call_id, "changeType", reinterpret_cast<const void *>(changeType), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "cursorIndex", reinterpret_cast<const void *>(cursorIndex), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "imeClauseStartIndex", reinterpret_cast<const void *>(imeClauseStartIndex), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "imeClauseEndIndex", reinterpret_cast<const void *>(imeClauseEndIndex), trace::ArgumentKind::Out);
        trace::RecordScalar(call_id, "bufferSize", bufferSize);
        trace::RecordPointer(call_id, "buffer", reinterpret_cast<const void *>(buffer), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, handle, changeType, cursorIndex, imeClauseStartIndex, imeClauseEndIndex, bufferSize, buffer);
    try {
        trace::RecordOutputObject(call_id, "changeType", changeType, "XGameUiTextEntryChangeTypeFlags *", false);
        trace::RecordOutputObject(call_id, "cursorIndex", cursorIndex, "UINT32 *", false);
        trace::RecordOutputObject(call_id, "imeClauseStartIndex", imeClauseStartIndex, "UINT32 *", false);
        trace::RecordOutputObject(call_id, "imeClauseEndIndex", imeClauseEndIndex, "UINT32 *", false);
        trace::RecordOutputBuffer(call_id, "buffer", reinterpret_cast<const void *>(buffer), (static_cast<std::size_t>(bufferSize)) * sizeof(*buffer), reinterpret_cast<const void *>(nullptr), 0, sizeof(*buffer), "char *", trace::OutputEncoding::Binary, false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl2_slot37_XGameUiTextEntryGetExtents(void *self, XGameUiTextEntryHandle handle, XGameUiTextEntryExtents * extents)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameUiTextEntryHandle handle, XGameUiTextEntryExtents * extents)>(trace::OriginalSlot(self, 37));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("36a03122-9ea3-4a3a-a8a4-899cfd85d7db", 37, "XGameUiTextEntryGetExtents", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "handle", handle, "XGameUiTextEntryHandle");
        trace::RecordPointer(call_id, "extents", reinterpret_cast<const void *>(extents), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, handle, extents);
    try {
        trace::RecordOutputObject(call_id, "extents", extents, "XGameUiTextEntryExtents *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl2_slot38_XGameUiTextEntryUpdatePositionHint(void *self, XGameUiTextEntryHandle handle, XGameUiTextEntryPositionHint positionHint)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameUiTextEntryHandle handle, XGameUiTextEntryPositionHint positionHint)>(trace::OriginalSlot(self, 38));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("36a03122-9ea3-4a3a-a8a4-899cfd85d7db", 38, "XGameUiTextEntryUpdatePositionHint", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "handle", handle, "XGameUiTextEntryHandle");
        trace::RecordScalar(call_id, "positionHint", positionHint);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, handle, positionHint);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl2_slot39_XGameUiTextEntryUpdateVisibility(void *self, XGameUiTextEntryHandle handle, XGameUiTextEntryVisibilityFlags visibilityFlags)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameUiTextEntryHandle handle, XGameUiTextEntryVisibilityFlags visibilityFlags)>(trace::OriginalSlot(self, 39));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("36a03122-9ea3-4a3a-a8a4-899cfd85d7db", 39, "XGameUiTextEntryUpdateVisibility", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "handle", handle, "XGameUiTextEntryHandle");
        trace::RecordScalar(call_id, "visibilityFlags", visibilityFlags);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, handle, visibilityFlags);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl3_slot40_XGameUiShowStateShareAsync(void *self, XAsyncBlock * async, XUserHandle requestingUser, const char * linkToken)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XUserHandle requestingUser, const char * linkToken)>(trace::OriginalSlot(self, 40));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("ade7eba1-2093-42ce-a544-a523a66790e0", 40, "XGameUiShowStateShareAsync", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordHandleArgumentValue(call_id, "requestingUser", requestingUser, "XUserHandle");
        trace::RecordInputString(call_id, "linkToken", linkToken, trace::ArgumentKind::StringSensitive);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, requestingUser, linkToken);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl3_slot41_XGameUiShowStateShareResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 41));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("ade7eba1-2093-42ce-a544-a523a66790e0", 41, "XGameUiShowStateShareResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl4_slot42_XGameUiSetUiCallbacks(void *self, const XGameUiUiCallbacks * callbacks, BOOLEAN useSystemUiIfAvailable)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XGameUiUiCallbacks * callbacks, BOOLEAN useSystemUiIfAvailable)>(trace::OriginalSlot(self, 42));
    if (!original) {
        return E_FAIL;
    }
    XGameUiUiCallbacks callbacks_callback_copy{};
    bool callbacks_callback_copy_valid = false;
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("eaf669df-5542-4590-99a3-8dc061f837cc", 42, "XGameUiSetUiCallbacks", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "callbacks", reinterpret_cast<const void *>(callbacks), trace::ArgumentKind::Pointer);
        trace::RecordScalar(call_id, "useSystemUiIfAvailable", useSystemUiIfAvailable);
        callbacks_callback_copy_valid = trace::CopyFromTarget(callbacks, &callbacks_callback_copy);
        if (callbacks_callback_copy_valid) {
            callbacks_callback_copy.showPlayerProfileCardCallback = trace::WrapCallback<XGameUiShowPlayerProfileCardUiCallback>(call_id, "XGameUiShowPlayerProfileCardUiCallback", callbacks_callback_copy.showPlayerProfileCardCallback, reinterpret_cast<const void *>(callbacks_callback_copy.context), nullptr, &xgrtrace_callback_XGameUiShowPlayerProfileCardUiCallback);
            callbacks_callback_copy.showPlayerPickerCallback = trace::WrapCallback<XGameUiShowPlayerPickerUiCallback>(call_id, "XGameUiShowPlayerPickerUiCallback", callbacks_callback_copy.showPlayerPickerCallback, reinterpret_cast<const void *>(callbacks_callback_copy.context), nullptr, &xgrtrace_callback_XGameUiShowPlayerPickerUiCallback);
            callbacks_callback_copy.showSendGameInviteCallback = trace::WrapCallback<XGameUiShowSendGameInviteUiCallback>(call_id, "XGameUiShowSendGameInviteUiCallback", callbacks_callback_copy.showSendGameInviteCallback, reinterpret_cast<const void *>(callbacks_callback_copy.context), nullptr, &xgrtrace_callback_XGameUiShowSendGameInviteUiCallback);
            callbacks_callback_copy.showAchievementsCallback = trace::WrapCallback<XGameUiShowAchievementsUiCallback>(call_id, "XGameUiShowAchievementsUiCallback", callbacks_callback_copy.showAchievementsCallback, reinterpret_cast<const void *>(callbacks_callback_copy.context), nullptr, &xgrtrace_callback_XGameUiShowAchievementsUiCallback);
            callbacks_callback_copy.showMultiplayerActivityGameInviteCallback = trace::WrapCallback<XGameUiShowMultiplayerActivityGameInviteUiCallback>(call_id, "XGameUiShowMultiplayerActivityGameInviteUiCallback", callbacks_callback_copy.showMultiplayerActivityGameInviteCallback, reinterpret_cast<const void *>(callbacks_callback_copy.context), nullptr, &xgrtrace_callback_XGameUiShowMultiplayerActivityGameInviteUiCallback);
            callbacks_callback_copy.showMessageDialogCallback = trace::WrapCallback<XGameUiShowMessageDialogUiCallback>(call_id, "XGameUiShowMessageDialogUiCallback", callbacks_callback_copy.showMessageDialogCallback, reinterpret_cast<const void *>(callbacks_callback_copy.context), nullptr, &xgrtrace_callback_XGameUiShowMessageDialogUiCallback);
            callbacks_callback_copy.showErrorDialogCallback = trace::WrapCallback<XGameUiShowErrorDialogUiCallback>(call_id, "XGameUiShowErrorDialogUiCallback", callbacks_callback_copy.showErrorDialogCallback, reinterpret_cast<const void *>(callbacks_callback_copy.context), nullptr, &xgrtrace_callback_XGameUiShowErrorDialogUiCallback);
            callbacks_callback_copy.showTextEntryCallback = trace::WrapCallback<XGameUiShowTextEntryUiCallback>(call_id, "XGameUiShowTextEntryUiCallback", callbacks_callback_copy.showTextEntryCallback, reinterpret_cast<const void *>(callbacks_callback_copy.context), nullptr, &xgrtrace_callback_XGameUiShowTextEntryUiCallback);
        }
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, (callbacks_callback_copy_valid ? &callbacks_callback_copy : callbacks), useSystemUiIfAvailable);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl4_slot43_XGameUiSetMessageDialogUiResponse(void *self, XGameUiCallbackHandle callbackHandle, XGameUiMessageDialogButton response)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameUiCallbackHandle callbackHandle, XGameUiMessageDialogButton response)>(trace::OriginalSlot(self, 43));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("eaf669df-5542-4590-99a3-8dc061f837cc", 43, "XGameUiSetMessageDialogUiResponse", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "callbackHandle", callbackHandle, "XGameUiCallbackHandle");
        trace::RecordScalar(call_id, "response", response);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, callbackHandle, response);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl4_slot44_XGameUiSetPlayerPickerUiResponse(void *self, XGameUiCallbackHandle callbackHandle, UINT32 playerCount, const UINT64 * players)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameUiCallbackHandle callbackHandle, UINT32 playerCount, const UINT64 * players)>(trace::OriginalSlot(self, 44));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("eaf669df-5542-4590-99a3-8dc061f837cc", 44, "XGameUiSetPlayerPickerUiResponse", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "callbackHandle", callbackHandle, "XGameUiCallbackHandle");
        trace::RecordScalar(call_id, "playerCount", playerCount);
        trace::RecordInputBuffer(call_id, "players", reinterpret_cast<const void *>(players), (static_cast<std::size_t>(playerCount)) * sizeof(*players), "const UINT64 *", false);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, callbackHandle, playerCount, players);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl4_slot45_XGameUiSetTextEntryUiResponse(void *self, XGameUiCallbackHandle callbackHandle, const char * response)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameUiCallbackHandle callbackHandle, const char * response)>(trace::OriginalSlot(self, 45));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("eaf669df-5542-4590-99a3-8dc061f837cc", 45, "XGameUiSetTextEntryUiResponse", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "callbackHandle", callbackHandle, "XGameUiCallbackHandle");
        trace::RecordInputString(call_id, "response", response, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, callbackHandle, response);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl4_slot46_XGameUiSetPlayerProfileCardUiResponse(void *self, XGameUiCallbackHandle callbackHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameUiCallbackHandle callbackHandle)>(trace::OriginalSlot(self, 46));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("eaf669df-5542-4590-99a3-8dc061f837cc", 46, "XGameUiSetPlayerProfileCardUiResponse", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "callbackHandle", callbackHandle, "XGameUiCallbackHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, callbackHandle);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl4_slot47_XGameUiSetSendGameInviteUiResponse(void *self, XGameUiCallbackHandle callbackHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameUiCallbackHandle callbackHandle)>(trace::OriginalSlot(self, 47));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("eaf669df-5542-4590-99a3-8dc061f837cc", 47, "XGameUiSetSendGameInviteUiResponse", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "callbackHandle", callbackHandle, "XGameUiCallbackHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, callbackHandle);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl4_slot48_XGameUiSetAchievementsUiResponse(void *self, XGameUiCallbackHandle callbackHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameUiCallbackHandle callbackHandle)>(trace::OriginalSlot(self, 48));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("eaf669df-5542-4590-99a3-8dc061f837cc", 48, "XGameUiSetAchievementsUiResponse", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "callbackHandle", callbackHandle, "XGameUiCallbackHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, callbackHandle);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl4_slot49_XGameUiSetMultiplayerActivityGameInviteUiResponse(void *self, XGameUiCallbackHandle callbackHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameUiCallbackHandle callbackHandle)>(trace::OriginalSlot(self, 49));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("eaf669df-5542-4590-99a3-8dc061f837cc", 49, "XGameUiSetMultiplayerActivityGameInviteUiResponse", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "callbackHandle", callbackHandle, "XGameUiCallbackHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, callbackHandle);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXGameUiImpl4_slot50_XGameUiSetErrorDialogUiResponse(void *self, XGameUiCallbackHandle callbackHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XGameUiCallbackHandle callbackHandle)>(trace::OriginalSlot(self, 50));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("eaf669df-5542-4590-99a3-8dc061f837cc", 50, "XGameUiSetErrorDialogUiResponse", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "callbackHandle", callbackHandle, "XGameUiCallbackHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, callbackHandle);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXLauncherImpl_slot3_XLaunchUri(void *self, XUserHandle user, const char * uri)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, const char * uri)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("1b339674-328d-4283-a200-3171f18d3639", 3, "XLaunchUri", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordInputString(call_id, "uri", uri, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, uri);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXLauncherImpl_slot4_XDisplayAcquireTimeoutDeferral(void *self, XDisplayTimeoutDeferralHandle * handle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XDisplayTimeoutDeferralHandle * handle)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("1b339674-328d-4283-a200-3171f18d3639", 4, "XDisplayAcquireTimeoutDeferral", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "handle", reinterpret_cast<const void *>(handle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, handle);
    try {
        trace::RecordOutputHandleObject(call_id, "handle", handle, "XDisplayTimeoutDeferralHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXLauncherImpl_slot5_XDisplayCloseTimeoutDeferralHandle(void *self, XDisplayTimeoutDeferralHandle handle)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XDisplayTimeoutDeferralHandle handle)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("1b339674-328d-4283-a200-3171f18d3639", 5, "XDisplayCloseTimeoutDeferralHandle", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "handle", handle, "XDisplayTimeoutDeferralHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, handle);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl_slot3_XNetworkingQueryPreferredLocalUdpMultiplayerPort(void *self, UINT16 * preferredLocalUdpMultiplayerPort)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, UINT16 * preferredLocalUdpMultiplayerPort)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 3, "XNetworkingQueryPreferredLocalUdpMultiplayerPort", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "preferredLocalUdpMultiplayerPort", reinterpret_cast<const void *>(preferredLocalUdpMultiplayerPort), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, preferredLocalUdpMultiplayerPort);
    try {
        trace::RecordOutputObject(call_id, "preferredLocalUdpMultiplayerPort", preferredLocalUdpMultiplayerPort, "UINT16 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl_slot4_XNetworkingQueryPreferredLocalUdpMultiplayerPortAsync(void *self, XAsyncBlock * asyncBlock)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * asyncBlock)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 4, "XNetworkingQueryPreferredLocalUdpMultiplayerPortAsync", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, asyncBlock);
    try {
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl_slot5_XNetworkingQueryPreferredLocalUdpMultiplayerPortAsyncResult(void *self, XAsyncBlock * asyncBlock, UINT16 * preferredLocalUdpMultiplayerPort)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * asyncBlock, UINT16 * preferredLocalUdpMultiplayerPort)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 5, "XNetworkingQueryPreferredLocalUdpMultiplayerPortAsyncResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
        trace::RecordPointer(call_id, "preferredLocalUdpMultiplayerPort", reinterpret_cast<const void *>(preferredLocalUdpMultiplayerPort), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, asyncBlock, preferredLocalUdpMultiplayerPort);
    try {
        trace::RecordOutputObject(call_id, "preferredLocalUdpMultiplayerPort", preferredLocalUdpMultiplayerPort, "UINT16 *", false);
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl_slot6_XNetworkingRegisterPreferredLocalUdpMultiplayerPortChanged(void *self, XTaskQueueHandle queue, void * context, XNetworkingPreferredLocalUdpMultiplayerPortChangedCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XNetworkingPreferredLocalUdpMultiplayerPortChangedCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 6, "XNetworkingRegisterPreferredLocalUdpMultiplayerPortChanged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XNetworkingPreferredLocalUdpMultiplayerPortChangedCallback>(call_id, "XNetworkingPreferredLocalUdpMultiplayerPortChangedCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XNetworkingPreferredLocalUdpMultiplayerPortChangedCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXNetworkingImpl_slot7_XNetworkingUnregisterPreferredLocalUdpMultiplayerPortChanged(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 7, "XNetworkingUnregisterPreferredLocalUdpMultiplayerPortChanged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl_slot8_XNetworkingQuerySecurityInformationForUrlAsync(void *self, const char * url, XAsyncBlock * asyncBlock)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * url, XAsyncBlock * asyncBlock)>(trace::OriginalSlot(self, 8));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 8, "XNetworkingQuerySecurityInformationForUrlAsync", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "url", url, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, url, asyncBlock);
    try {
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl_slot9_XNetworkingQuerySecurityInformationForUrlAsyncResultSize(void *self, XAsyncBlock * asyncBlock, SIZE_T * securityInformationBufferByteCount)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * asyncBlock, SIZE_T * securityInformationBufferByteCount)>(trace::OriginalSlot(self, 9));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 9, "XNetworkingQuerySecurityInformationForUrlAsyncResultSize", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
        trace::RecordPointer(call_id, "securityInformationBufferByteCount", reinterpret_cast<const void *>(securityInformationBufferByteCount), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, asyncBlock, securityInformationBufferByteCount);
    try {
        trace::RecordOutputObject(call_id, "securityInformationBufferByteCount", securityInformationBufferByteCount, "SIZE_T *", false);
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl_slot10_XNetworkingQuerySecurityInformationForUrlAsyncResult(void *self, XAsyncBlock * asyncBlock, SIZE_T securityInformationBufferByteCount, SIZE_T * securityInformationBufferByteCountUsed, UINT8 * securityInformationBuffer, XNetworkingSecurityInformation ** securityInformation)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * asyncBlock, SIZE_T securityInformationBufferByteCount, SIZE_T * securityInformationBufferByteCountUsed, UINT8 * securityInformationBuffer, XNetworkingSecurityInformation ** securityInformation)>(trace::OriginalSlot(self, 10));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 10, "XNetworkingQuerySecurityInformationForUrlAsyncResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
        trace::RecordScalar(call_id, "securityInformationBufferByteCount", securityInformationBufferByteCount);
        trace::RecordPointer(call_id, "securityInformationBufferByteCountUsed", reinterpret_cast<const void *>(securityInformationBufferByteCountUsed), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "securityInformationBuffer", reinterpret_cast<const void *>(securityInformationBuffer), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "securityInformation", reinterpret_cast<const void *>(securityInformation), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, asyncBlock, securityInformationBufferByteCount, securityInformationBufferByteCountUsed, securityInformationBuffer, securityInformation);
    try {
        trace::RecordOutputObject(call_id, "securityInformationBufferByteCountUsed", securityInformationBufferByteCountUsed, "SIZE_T *", false);
        trace::RecordOutputObject(call_id, "securityInformationBuffer", securityInformationBuffer, "UINT8 *", false);
        trace::RecordOutputPointeeValue(call_id, "securityInformation", reinterpret_cast<const void *>(securityInformation), sizeof(*securityInformation), sizeof(**securityInformation), "XNetworkingSecurityInformation **", false);
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl_slot11_XNetworkingQuerySecurityInformationForUrlUtf16Async(void *self, const WCHAR * url, XAsyncBlock * asyncBlock)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const WCHAR * url, XAsyncBlock * asyncBlock)>(trace::OriginalSlot(self, 11));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 11, "XNetworkingQuerySecurityInformationForUrlUtf16Async", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "url", url, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, url, asyncBlock);
    try {
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl_slot12_XNetworkingQuerySecurityInformationForUrlUtf16AsyncResultSize(void *self, XAsyncBlock * asyncBlock, SIZE_T * securityInformationBufferByteCount)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * asyncBlock, SIZE_T * securityInformationBufferByteCount)>(trace::OriginalSlot(self, 12));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 12, "XNetworkingQuerySecurityInformationForUrlUtf16AsyncResultSize", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
        trace::RecordPointer(call_id, "securityInformationBufferByteCount", reinterpret_cast<const void *>(securityInformationBufferByteCount), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, asyncBlock, securityInformationBufferByteCount);
    try {
        trace::RecordOutputObject(call_id, "securityInformationBufferByteCount", securityInformationBufferByteCount, "SIZE_T *", false);
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl_slot13_XNetworkingQuerySecurityInformationForUrlUtf16AsyncResult(void *self, XAsyncBlock * asyncBlock, SIZE_T securityInformationBufferByteCount, SIZE_T * securityInformationBufferByteCountUsed, UINT8 * securityInformationBuffer, XNetworkingSecurityInformation ** securityInformation)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * asyncBlock, SIZE_T securityInformationBufferByteCount, SIZE_T * securityInformationBufferByteCountUsed, UINT8 * securityInformationBuffer, XNetworkingSecurityInformation ** securityInformation)>(trace::OriginalSlot(self, 13));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 13, "XNetworkingQuerySecurityInformationForUrlUtf16AsyncResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
        trace::RecordScalar(call_id, "securityInformationBufferByteCount", securityInformationBufferByteCount);
        trace::RecordPointer(call_id, "securityInformationBufferByteCountUsed", reinterpret_cast<const void *>(securityInformationBufferByteCountUsed), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "securityInformationBuffer", reinterpret_cast<const void *>(securityInformationBuffer), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "securityInformation", reinterpret_cast<const void *>(securityInformation), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, asyncBlock, securityInformationBufferByteCount, securityInformationBufferByteCountUsed, securityInformationBuffer, securityInformation);
    try {
        trace::RecordOutputObject(call_id, "securityInformationBufferByteCountUsed", securityInformationBufferByteCountUsed, "SIZE_T *", false);
        trace::RecordOutputObject(call_id, "securityInformationBuffer", securityInformationBuffer, "UINT8 *", false);
        trace::RecordOutputPointeeValue(call_id, "securityInformation", reinterpret_cast<const void *>(securityInformation), sizeof(*securityInformation), sizeof(**securityInformation), "XNetworkingSecurityInformation **", false);
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl_slot14_XNetworkingVerifyServerCertificate(void *self, void * requestHandle, const XNetworkingSecurityInformation * securityInformation)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, void * requestHandle, const XNetworkingSecurityInformation * securityInformation)>(trace::OriginalSlot(self, 14));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 14, "XNetworkingVerifyServerCertificate", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "requestHandle", reinterpret_cast<const void *>(requestHandle), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "securityInformation", reinterpret_cast<const void *>(securityInformation), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, requestHandle, securityInformation);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl_slot15_XNetworkingGetConnectivityHint(void *self, XNetworkingConnectivityHint * connectivityHint)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XNetworkingConnectivityHint * connectivityHint)>(trace::OriginalSlot(self, 15));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 15, "XNetworkingGetConnectivityHint", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "connectivityHint", reinterpret_cast<const void *>(connectivityHint), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, connectivityHint);
    try {
        trace::RecordOutputObject(call_id, "connectivityHint", connectivityHint, "XNetworkingConnectivityHint *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl_slot16_XNetworkingRegisterConnectivityHintChanged(void *self, XTaskQueueHandle queue, void * context, XNetworkingConnectivityHintChangedCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XNetworkingConnectivityHintChangedCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 16));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 16, "XNetworkingRegisterConnectivityHintChanged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XNetworkingConnectivityHintChangedCallback>(call_id, "XNetworkingConnectivityHintChangedCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XNetworkingConnectivityHintChangedCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXNetworkingImpl_slot17_XNetworkingUnregisterConnectivityHintChanged(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 17));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("37e56907-2f10-41e8-b72f-36edb185331a", 17, "XNetworkingUnregisterConnectivityHintChanged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl2_slot18_XNetworkingQueryConfigurationSetting(void *self, XNetworkingConfigurationSetting configurationSetting, UINT64 * value)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XNetworkingConfigurationSetting configurationSetting, UINT64 * value)>(trace::OriginalSlot(self, 18));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("bf2346b2-39af-4658-b5ea-44713c7e83b3", 18, "XNetworkingQueryConfigurationSetting", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "configurationSetting", configurationSetting);
        trace::RecordPointer(call_id, "value", reinterpret_cast<const void *>(value), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, configurationSetting, value);
    try {
        trace::RecordOutputObject(call_id, "value", value, "UINT64 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl2_slot19_XNetworkingSetConfigurationSetting(void *self, XNetworkingConfigurationSetting configurationParameter, UINT64 value)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XNetworkingConfigurationSetting configurationParameter, UINT64 value)>(trace::OriginalSlot(self, 19));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("bf2346b2-39af-4658-b5ea-44713c7e83b3", 19, "XNetworkingSetConfigurationSetting", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "configurationParameter", configurationParameter);
        trace::RecordScalar(call_id, "value", value);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, configurationParameter, value);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXNetworkingImpl2_slot20_XNetworkingQueryStatistics(void *self, XNetworkingStatisticsType statisticsType, XNetworkingStatisticsBuffer * statisticsBuffer)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XNetworkingStatisticsType statisticsType, XNetworkingStatisticsBuffer * statisticsBuffer)>(trace::OriginalSlot(self, 20));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("bf2346b2-39af-4658-b5ea-44713c7e83b3", 20, "XNetworkingQueryStatistics", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "statisticsType", statisticsType);
        trace::RecordPointer(call_id, "statisticsBuffer", reinterpret_cast<const void *>(statisticsBuffer), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, statisticsType, statisticsBuffer);
    try {
        trace::RecordOutputObject(call_id, "statisticsBuffer", statisticsBuffer, "XNetworkingStatisticsBuffer *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot3_XPackageGetCurrentProcessPackageIdentifier(void *self, SIZE_T bufferSize, char * buffer)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, SIZE_T bufferSize, char * buffer)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 3, "XPackageGetCurrentProcessPackageIdentifier", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "bufferSize", bufferSize);
        trace::RecordPointer(call_id, "buffer", reinterpret_cast<const void *>(buffer), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, bufferSize, buffer);
    try {
        trace::RecordOutputBuffer(call_id, "buffer", reinterpret_cast<const void *>(buffer), (static_cast<std::size_t>(bufferSize)) * sizeof(*buffer), reinterpret_cast<const void *>(nullptr), 0, sizeof(*buffer), "char *", trace::OutputEncoding::Binary, false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXPackageImpl_slot4_XPackageIsPackagedProcess(void *self)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 4, "XPackageIsPackagedProcess", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot5_XPackageCreateInstallationMonitor(void *self, const char * packageIdentifier, UINT32 selectorCount, XPackageChunkSelector * selectors, UINT32 minimumUpdateIntervalMs, XTaskQueueHandle queue, XPackageInstallationMonitorHandle * installationMonitor)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * packageIdentifier, UINT32 selectorCount, XPackageChunkSelector * selectors, UINT32 minimumUpdateIntervalMs, XTaskQueueHandle queue, XPackageInstallationMonitorHandle * installationMonitor)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 5, "XPackageCreateInstallationMonitor", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "selectorCount", selectorCount);
        trace::RecordInputBuffer(call_id, "selectors", reinterpret_cast<const void *>(selectors), (static_cast<std::size_t>(selectorCount)) * sizeof(*selectors), "XPackageChunkSelector *", false);
        trace::RecordScalar(call_id, "minimumUpdateIntervalMs", minimumUpdateIntervalMs);
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "installationMonitor", reinterpret_cast<const void *>(installationMonitor), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageIdentifier, selectorCount, selectors, minimumUpdateIntervalMs, queue, installationMonitor);
    try {
        trace::RecordOutputHandleObject(call_id, "installationMonitor", installationMonitor, "XPackageInstallationMonitorHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXPackageImpl_slot6_XPackageCloseInstallationMonitorHandle(void *self, XPackageInstallationMonitorHandle installationMonitor)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XPackageInstallationMonitorHandle installationMonitor)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 6, "XPackageCloseInstallationMonitorHandle", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "installationMonitor", installationMonitor, "XPackageInstallationMonitorHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, installationMonitor);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

void WINAPI xgrtrace_wrap_IXPackageImpl_slot7_XPackageGetInstallationProgress(void *self, XPackageInstallationMonitorHandle installationMonitor, XPackageInstallationProgress * progress)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XPackageInstallationMonitorHandle installationMonitor, XPackageInstallationProgress * progress)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 7, "XPackageGetInstallationProgress", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "installationMonitor", installationMonitor, "XPackageInstallationMonitorHandle");
        trace::RecordPointer(call_id, "progress", reinterpret_cast<const void *>(progress), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, installationMonitor, progress);
    try {
        trace::RecordOutputObject(call_id, "progress", progress, "XPackageInstallationProgress *", false);
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

BOOLEAN WINAPI xgrtrace_wrap_IXPackageImpl_slot8_XPackageUpdateInstallationMonitor(void *self, XPackageInstallationMonitorHandle installationMonitor)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XPackageInstallationMonitorHandle installationMonitor)>(trace::OriginalSlot(self, 8));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 8, "XPackageUpdateInstallationMonitor", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "installationMonitor", installationMonitor, "XPackageInstallationMonitorHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, installationMonitor);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot9_XPackageRegisterInstallationProgressChanged(void *self, XPackageInstallationMonitorHandle installationMonitor, void * context, XPackageInstallationProgressCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XPackageInstallationMonitorHandle installationMonitor, void * context, XPackageInstallationProgressCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 9));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 9, "XPackageRegisterInstallationProgressChanged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "installationMonitor", installationMonitor, "XPackageInstallationMonitorHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, installationMonitor, context, trace::WrapCallback<XPackageInstallationProgressCallback>(call_id, "XPackageInstallationProgressCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XPackageInstallationProgressCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXPackageImpl_slot10_XPackageUnregisterInstallationProgressChanged(void *self, XPackageInstallationMonitorHandle installationMonitor, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XPackageInstallationMonitorHandle installationMonitor, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 10));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 10, "XPackageUnregisterInstallationProgressChanged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "installationMonitor", installationMonitor, "XPackageInstallationMonitorHandle");
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, installationMonitor, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot11_XPackageGetUserLocale(void *self, SIZE_T localeSize, char * locale)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, SIZE_T localeSize, char * locale)>(trace::OriginalSlot(self, 11));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 11, "XPackageGetUserLocale", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "localeSize", localeSize);
        trace::RecordPointer(call_id, "locale", reinterpret_cast<const void *>(locale), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, localeSize, locale);
    try {
        trace::RecordOutputBuffer(call_id, "locale", reinterpret_cast<const void *>(locale), (static_cast<std::size_t>(localeSize)) * sizeof(*locale), reinterpret_cast<const void *>(nullptr), 0, sizeof(*locale), "char *", trace::OutputEncoding::Binary, false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot12_XPackageFindChunkAvailability(void *self, const char * packageIdentifier, UINT32 selectorCount, XPackageChunkSelector * selectors, XPackageChunkAvailability * availability)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * packageIdentifier, UINT32 selectorCount, XPackageChunkSelector * selectors, XPackageChunkAvailability * availability)>(trace::OriginalSlot(self, 12));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 12, "XPackageFindChunkAvailability", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "selectorCount", selectorCount);
        trace::RecordInputBuffer(call_id, "selectors", reinterpret_cast<const void *>(selectors), (static_cast<std::size_t>(selectorCount)) * sizeof(*selectors), "XPackageChunkSelector *", false);
        trace::RecordPointer(call_id, "availability", reinterpret_cast<const void *>(availability), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageIdentifier, selectorCount, selectors, availability);
    try {
        trace::RecordOutputObject(call_id, "availability", availability, "XPackageChunkAvailability *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot13_XPackageEnumerateChunkAvailability(void *self, const char * packageIdentifier, XPackageChunkSelectorType type, void * context, XPackageChunkAvailabilityCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * packageIdentifier, XPackageChunkSelectorType type, void * context, XPackageChunkAvailabilityCallback * callback)>(trace::OriginalSlot(self, 13));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 13, "XPackageEnumerateChunkAvailability", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "type", type);
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageIdentifier, type, context, trace::WrapCallback<XPackageChunkAvailabilityCallback>(call_id, "XPackageChunkAvailabilityCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XPackageChunkAvailabilityCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot14_XPackageChangeChunkInstallOrder(void *self, const char * packageIdentifier, UINT32 selectorCount, XPackageChunkSelector * selectors)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * packageIdentifier, UINT32 selectorCount, XPackageChunkSelector * selectors)>(trace::OriginalSlot(self, 14));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 14, "XPackageChangeChunkInstallOrder", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "selectorCount", selectorCount);
        trace::RecordInputBuffer(call_id, "selectors", reinterpret_cast<const void *>(selectors), (static_cast<std::size_t>(selectorCount)) * sizeof(*selectors), "XPackageChunkSelector *", false);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageIdentifier, selectorCount, selectors);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot15_XPackageInstallChunks(void *self, const char * packageIdentifier, UINT32 selectorCount, XPackageChunkSelector * selectors, UINT32 minimumUpdateIntervalMs, BOOLEAN suppressUserConfirmation, XTaskQueueHandle queue, XPackageInstallationMonitorHandle * installationMonitor)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * packageIdentifier, UINT32 selectorCount, XPackageChunkSelector * selectors, UINT32 minimumUpdateIntervalMs, BOOLEAN suppressUserConfirmation, XTaskQueueHandle queue, XPackageInstallationMonitorHandle * installationMonitor)>(trace::OriginalSlot(self, 15));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 15, "XPackageInstallChunks", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "selectorCount", selectorCount);
        trace::RecordInputBuffer(call_id, "selectors", reinterpret_cast<const void *>(selectors), (static_cast<std::size_t>(selectorCount)) * sizeof(*selectors), "XPackageChunkSelector *", false);
        trace::RecordScalar(call_id, "minimumUpdateIntervalMs", minimumUpdateIntervalMs);
        trace::RecordScalar(call_id, "suppressUserConfirmation", suppressUserConfirmation);
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "installationMonitor", reinterpret_cast<const void *>(installationMonitor), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageIdentifier, selectorCount, selectors, minimumUpdateIntervalMs, suppressUserConfirmation, queue, installationMonitor);
    try {
        trace::RecordOutputHandleObject(call_id, "installationMonitor", installationMonitor, "XPackageInstallationMonitorHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot16_XPackageInstallChunksAsync(void *self, const char * packageIdentifier, UINT32 selectorCount, XPackageChunkSelector * selectors, UINT32 minimumUpdateIntervalMs, BOOLEAN suppressUserConfirmation, XAsyncBlock * asyncBlock)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * packageIdentifier, UINT32 selectorCount, XPackageChunkSelector * selectors, UINT32 minimumUpdateIntervalMs, BOOLEAN suppressUserConfirmation, XAsyncBlock * asyncBlock)>(trace::OriginalSlot(self, 16));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 16, "XPackageInstallChunksAsync", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "selectorCount", selectorCount);
        trace::RecordInputBuffer(call_id, "selectors", reinterpret_cast<const void *>(selectors), (static_cast<std::size_t>(selectorCount)) * sizeof(*selectors), "XPackageChunkSelector *", false);
        trace::RecordScalar(call_id, "minimumUpdateIntervalMs", minimumUpdateIntervalMs);
        trace::RecordScalar(call_id, "suppressUserConfirmation", suppressUserConfirmation);
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageIdentifier, selectorCount, selectors, minimumUpdateIntervalMs, suppressUserConfirmation, asyncBlock);
    try {
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot17_XPackageInstallChunksResult(void *self, XAsyncBlock * asyncBlock, XPackageInstallationMonitorHandle * installationMonitor)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * asyncBlock, XPackageInstallationMonitorHandle * installationMonitor)>(trace::OriginalSlot(self, 17));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 17, "XPackageInstallChunksResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
        trace::RecordPointer(call_id, "installationMonitor", reinterpret_cast<const void *>(installationMonitor), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, asyncBlock, installationMonitor);
    try {
        trace::RecordOutputHandleObject(call_id, "installationMonitor", installationMonitor, "XPackageInstallationMonitorHandle *");
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot18_XPackageEstimateDownloadSize(void *self, const char * packageIdentifier, UINT32 selectorCount, XPackageChunkSelector * selectors, UINT64 * downloadSize, BOOLEAN * shouldPresentUserConfirmation)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * packageIdentifier, UINT32 selectorCount, XPackageChunkSelector * selectors, UINT64 * downloadSize, BOOLEAN * shouldPresentUserConfirmation)>(trace::OriginalSlot(self, 18));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 18, "XPackageEstimateDownloadSize", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "selectorCount", selectorCount);
        trace::RecordInputBuffer(call_id, "selectors", reinterpret_cast<const void *>(selectors), (static_cast<std::size_t>(selectorCount)) * sizeof(*selectors), "XPackageChunkSelector *", false);
        trace::RecordPointer(call_id, "downloadSize", reinterpret_cast<const void *>(downloadSize), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "shouldPresentUserConfirmation", reinterpret_cast<const void *>(shouldPresentUserConfirmation), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageIdentifier, selectorCount, selectors, downloadSize, shouldPresentUserConfirmation);
    try {
        trace::RecordOutputObject(call_id, "downloadSize", downloadSize, "UINT64 *", false);
        trace::RecordOutputObject(call_id, "shouldPresentUserConfirmation", shouldPresentUserConfirmation, "BOOLEAN *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot19_XPackageUninstallChunks(void *self, const char * packageIdentifier, UINT32 selectorCount, XPackageChunkSelector * selectors)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * packageIdentifier, UINT32 selectorCount, XPackageChunkSelector * selectors)>(trace::OriginalSlot(self, 19));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 19, "XPackageUninstallChunks", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "selectorCount", selectorCount);
        trace::RecordInputBuffer(call_id, "selectors", reinterpret_cast<const void *>(selectors), (static_cast<std::size_t>(selectorCount)) * sizeof(*selectors), "XPackageChunkSelector *", false);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageIdentifier, selectorCount, selectors);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXPackageImpl_slot22_XPackageUnregisterPackageInstalled(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 22));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 22, "XPackageUnregisterPackageInstalled", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot23_XPackageMount(void *self, const char * packageIdentifier, XPackageMountHandle * mount)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * packageIdentifier, XPackageMountHandle * mount)>(trace::OriginalSlot(self, 23));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 23, "XPackageMount", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "mount", reinterpret_cast<const void *>(mount), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageIdentifier, mount);
    try {
        trace::RecordOutputHandleObject(call_id, "mount", mount, "XPackageMountHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot24_XPackageGetMountPathSize(void *self, XPackageMountHandle mount, SIZE_T * pathSize)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XPackageMountHandle mount, SIZE_T * pathSize)>(trace::OriginalSlot(self, 24));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 24, "XPackageGetMountPathSize", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "mount", mount, "XPackageMountHandle");
        trace::RecordPointer(call_id, "pathSize", reinterpret_cast<const void *>(pathSize), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, mount, pathSize);
    try {
        trace::RecordOutputObject(call_id, "pathSize", pathSize, "SIZE_T *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot25_XPackageGetMountPath(void *self, XPackageMountHandle mount, SIZE_T pathSize, char * path)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XPackageMountHandle mount, SIZE_T pathSize, char * path)>(trace::OriginalSlot(self, 25));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 25, "XPackageGetMountPath", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "mount", mount, "XPackageMountHandle");
        trace::RecordScalar(call_id, "pathSize", pathSize);
        trace::RecordPointer(call_id, "path", reinterpret_cast<const void *>(path), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, mount, pathSize, path);
    try {
        trace::RecordOutputBuffer(call_id, "path", reinterpret_cast<const void *>(path), (static_cast<std::size_t>(pathSize)) * sizeof(*path), reinterpret_cast<const void *>(nullptr), 0, sizeof(*path), "char *", trace::OutputEncoding::Binary, false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXPackageImpl_slot26_XPackageCloseMountHandle(void *self, XPackageMountHandle mount)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XPackageMountHandle mount)>(trace::OriginalSlot(self, 26));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 26, "XPackageCloseMountHandle", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "mount", mount, "XPackageMountHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, mount);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot28_XPackageEnumeratePackages(void *self, XPackageKind kind, XPackageEnumerationScope scope, void * context, XPackageEnumerationCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XPackageKind kind, XPackageEnumerationScope scope, void * context, XPackageEnumerationCallback * callback)>(trace::OriginalSlot(self, 28));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 28, "XPackageEnumeratePackages", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "kind", kind);
        trace::RecordScalar(call_id, "scope", scope);
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, kind, scope, context, trace::WrapCallback<XPackageEnumerationCallback>(call_id, "XPackageEnumerationCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XPackageEnumerationCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot29_XPackageRegisterPackageInstalled(void *self, XTaskQueueHandle queue, void * context, XPackageInstalledCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XPackageInstalledCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 29));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 29, "XPackageRegisterPackageInstalled", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XPackageInstalledCallback>(call_id, "XPackageInstalledCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XPackageInstalledCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot30_XPackageGetWriteStats(void *self, XPackageWriteStats * writeStats)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XPackageWriteStats * writeStats)>(trace::OriginalSlot(self, 30));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 30, "XPackageGetWriteStats", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "writeStats", reinterpret_cast<const void *>(writeStats), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, writeStats);
    try {
        trace::RecordOutputObject(call_id, "writeStats", writeStats, "XPackageWriteStats *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot32_XPackageUninstallUWPInstance(void *self, const char * packageName)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * packageName)>(trace::OriginalSlot(self, 32));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 32, "XPackageUninstallUWPInstance", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageName", packageName, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageName);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl_slot33_XPackageEnumerateFeatures(void *self, const char * packageIdentifier, void * context, XPackageFeatureEnumerationCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * packageIdentifier, void * context, XPackageFeatureEnumerationCallback * callback)>(trace::OriginalSlot(self, 33));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 33, "XPackageEnumerateFeatures", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageIdentifier, context, trace::WrapCallback<XPackageFeatureEnumerationCallback>(call_id, "XPackageFeatureEnumerationCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XPackageFeatureEnumerationCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXPackageImpl_slot34_XPackageUninstallPackage(void *self, const char * packageIdentifier)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, const char * packageIdentifier)>(trace::OriginalSlot(self, 34));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("3720de07-e8e4-44a3-ad32-b359e8adbe55", 34, "XPackageUninstallPackage", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageIdentifier);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl2_slot35_XPackageEnumeratePackages(void *self, XPackageKind kind, XPackageEnumerationScope scope, void * context, XPackageEnumerationCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XPackageKind kind, XPackageEnumerationScope scope, void * context, XPackageEnumerationCallback * callback)>(trace::OriginalSlot(self, 35));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("f92d8712-2b27-4d8a-bf01-11a6f8e3eb42", 35, "XPackageEnumeratePackages", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "kind", kind);
        trace::RecordScalar(call_id, "scope", scope);
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, kind, scope, context, trace::WrapCallback<XPackageEnumerationCallback>(call_id, "XPackageEnumerationCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XPackageEnumerationCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl2_slot36_XPackageRegisterPackageInstalled(void *self, XTaskQueueHandle queue, void * context, XPackageInstalledCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XPackageInstalledCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 36));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("f92d8712-2b27-4d8a-bf01-11a6f8e3eb42", 36, "XPackageRegisterPackageInstalled", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XPackageInstalledCallback>(call_id, "XPackageInstalledCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XPackageInstalledCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl2_slot37_XPackageMountWithUiAsync(void *self, const char * packageIdentifier, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * packageIdentifier, XAsyncBlock * async)>(trace::OriginalSlot(self, 37));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("f92d8712-2b27-4d8a-bf01-11a6f8e3eb42", 37, "XPackageMountWithUiAsync", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageIdentifier, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl2_slot38_XPackageMountWithUiResult(void *self, XAsyncBlock * async, XPackageMountHandle * mount)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XPackageMountHandle * mount)>(trace::OriginalSlot(self, 38));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("f92d8712-2b27-4d8a-bf01-11a6f8e3eb42", 38, "XPackageMountWithUiResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "mount", reinterpret_cast<const void *>(mount), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, mount);
    try {
        trace::RecordOutputHandleObject(call_id, "mount", mount, "XPackageMountHandle *");
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl3_slot39_XPackageEnumeratePackages(void *self, XPackageKind kind, XPackageEnumerationScope scope, void * context, XPackageEnumerationCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XPackageKind kind, XPackageEnumerationScope scope, void * context, XPackageEnumerationCallback * callback)>(trace::OriginalSlot(self, 39));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("e2a4734b-2f4a-456d-aa8f-d065e04fb209", 39, "XPackageEnumeratePackages", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "kind", kind);
        trace::RecordScalar(call_id, "scope", scope);
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, kind, scope, context, trace::WrapCallback<XPackageEnumerationCallback>(call_id, "XPackageEnumerationCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XPackageEnumerationCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl3_slot40_XPackageRegisterPackageInstalled(void *self, XTaskQueueHandle queue, void * context, XPackageInstalledCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XPackageInstalledCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 40));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("e2a4734b-2f4a-456d-aa8f-d065e04fb209", 40, "XPackageRegisterPackageInstalled", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XPackageInstalledCallback>(call_id, "XPackageInstalledCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XPackageInstalledCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPackageImpl4_slot41_XPackageGetKind(void *self, const char * packageIdentifier, XPackageKind * kind)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * packageIdentifier, XPackageKind * kind)>(trace::OriginalSlot(self, 41));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0b9d556e-ab70-43f4-baa0-9999ac4cb040", 41, "XPackageGetKind", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "kind", reinterpret_cast<const void *>(kind), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageIdentifier, kind);
    try {
        trace::RecordOutputObject(call_id, "kind", kind, "XPackageKind *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPersistentLocalStorageImpl_slot3_XPersistentLocalStorageGetPathSize(void *self, SIZE_T * pathSize)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, SIZE_T * pathSize)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("f4faf4d4-2d04-4fce-b3e0-474a713a3e84", 3, "XPersistentLocalStorageGetPathSize", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "pathSize", reinterpret_cast<const void *>(pathSize), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, pathSize);
    try {
        trace::RecordOutputObject(call_id, "pathSize", pathSize, "SIZE_T *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPersistentLocalStorageImpl_slot4_XPersistentLocalStorageGetPath(void *self, SIZE_T pathSize, char * path, SIZE_T * pathUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, SIZE_T pathSize, char * path, SIZE_T * pathUsed)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("f4faf4d4-2d04-4fce-b3e0-474a713a3e84", 4, "XPersistentLocalStorageGetPath", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "pathSize", pathSize);
        trace::RecordPointer(call_id, "path", reinterpret_cast<const void *>(path), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "pathUsed", reinterpret_cast<const void *>(pathUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, pathSize, path, pathUsed);
    try {
        trace::RecordOutputBuffer(call_id, "path", reinterpret_cast<const void *>(path), (static_cast<std::size_t>(pathSize)) * sizeof(*path), reinterpret_cast<const void *>(pathUsed), sizeof(*pathUsed), sizeof(*path), "char *", trace::OutputEncoding::Ansi, false);
        trace::RecordOutputObject(call_id, "pathUsed", pathUsed, "SIZE_T *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPersistentLocalStorageImpl_slot5_XPersistentLocalStorageGetSpaceInfo(void *self, XPersistentLocalStorageSpaceInfo * info)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XPersistentLocalStorageSpaceInfo * info)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("f4faf4d4-2d04-4fce-b3e0-474a713a3e84", 5, "XPersistentLocalStorageGetSpaceInfo", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "info", reinterpret_cast<const void *>(info), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, info);
    try {
        trace::RecordOutputObject(call_id, "info", info, "XPersistentLocalStorageSpaceInfo *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPersistentLocalStorageImpl_slot6_XPersistentLocalStoragePromptUserForSpaceAsync(void *self, UINT64 requestedBytes, XAsyncBlock * asyncBlock)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, UINT64 requestedBytes, XAsyncBlock * asyncBlock)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("f4faf4d4-2d04-4fce-b3e0-474a713a3e84", 6, "XPersistentLocalStoragePromptUserForSpaceAsync", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "requestedBytes", requestedBytes);
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, requestedBytes, asyncBlock);
    try {
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPersistentLocalStorageImpl_slot7_XPersistentLocalStoragePromptUserForSpaceResult(void *self, XAsyncBlock * asyncBlock)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * asyncBlock)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("f4faf4d4-2d04-4fce-b3e0-474a713a3e84", 7, "XPersistentLocalStoragePromptUserForSpaceResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, asyncBlock);
    try {
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXPersistentLocalStorageImpl3_slot8_XPersistentLocalStorageMountForPackage(void *self, const char * packageIdentifier, XPackageMountHandle * mountHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * packageIdentifier, XPackageMountHandle * mountHandle)>(trace::OriginalSlot(self, 8));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("41a4e10c-5a7e-41d9-8c37-37bde62a07d6", 8, "XPersistentLocalStorageMountForPackage", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordPointer(call_id, "mountHandle", reinterpret_cast<const void *>(mountHandle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, packageIdentifier, mountHandle);
    try {
        trace::RecordOutputHandleObject(call_id, "mountHandle", mountHandle, "XPackageMountHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot3_XStoreCreateContext(void *self, const XUserHandle user, XStoreContextHandle * storeContextHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XUserHandle user, XStoreContextHandle * storeContextHandle)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 3, "XStoreCreateContext", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "const XUserHandle");
        trace::RecordPointer(call_id, "storeContextHandle", reinterpret_cast<const void *>(storeContextHandle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, storeContextHandle);
    try {
        trace::RecordOutputHandleObject(call_id, "storeContextHandle", storeContextHandle, "XStoreContextHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXStoreImpl_slot4_XStoreCloseContextHandle(void *self, XStoreContextHandle storeContextHandle)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XStoreContextHandle storeContextHandle)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 4, "XStoreCloseContextHandle", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "XStoreContextHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, storeContextHandle);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot5_XStoreQueryAssociatedProductsAsync(void *self, const XStoreContextHandle storeContextHandle, XStoreProductKind productKinds, UINT32 maxItemsToRetrievePerPage, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, XStoreProductKind productKinds, UINT32 maxItemsToRetrievePerPage, XAsyncBlock * async)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 5, "XStoreQueryAssociatedProductsAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordScalar(call_id, "productKinds", productKinds);
        trace::RecordScalar(call_id, "maxItemsToRetrievePerPage", maxItemsToRetrievePerPage);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, productKinds, maxItemsToRetrievePerPage, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot6_XStoreQueryAssociatedProductsResult(void *self, XAsyncBlock * async, XStoreProductQueryHandle * productQueryHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreProductQueryHandle * productQueryHandle)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 6, "XStoreQueryAssociatedProductsResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "productQueryHandle", reinterpret_cast<const void *>(productQueryHandle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, productQueryHandle);
    try {
        trace::RecordOutputHandleObject(call_id, "productQueryHandle", productQueryHandle, "XStoreProductQueryHandle *");
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot7_XStoreQueryProductsAsync(void *self, const XStoreContextHandle storeContextHandle, XStoreProductKind productKinds, const char ** storeIds, SIZE_T storeIdsCount, const char ** actionFilters, SIZE_T actionFiltersCount, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, XStoreProductKind productKinds, const char ** storeIds, SIZE_T storeIdsCount, const char ** actionFilters, SIZE_T actionFiltersCount, XAsyncBlock * async)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 7, "XStoreQueryProductsAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordScalar(call_id, "productKinds", productKinds);
        trace::RecordInputStringArray(call_id, "storeIds", reinterpret_cast<const void *>(storeIds), static_cast<std::size_t>(storeIdsCount), static_cast<std::size_t>(0), false, false);
        trace::RecordScalar(call_id, "storeIdsCount", storeIdsCount);
        trace::RecordInputStringArray(call_id, "actionFilters", reinterpret_cast<const void *>(actionFilters), static_cast<std::size_t>(actionFiltersCount), static_cast<std::size_t>(0), false, false);
        trace::RecordScalar(call_id, "actionFiltersCount", actionFiltersCount);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, productKinds, storeIds, storeIdsCount, actionFilters, actionFiltersCount, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot8_XStoreQueryProductsResult(void *self, XAsyncBlock * async, XStoreProductQueryHandle * productQueryHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreProductQueryHandle * productQueryHandle)>(trace::OriginalSlot(self, 8));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 8, "XStoreQueryProductsResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "productQueryHandle", reinterpret_cast<const void *>(productQueryHandle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, productQueryHandle);
    try {
        trace::RecordOutputHandleObject(call_id, "productQueryHandle", productQueryHandle, "XStoreProductQueryHandle *");
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot9_XStoreQueryEntitledProductsAsync(void *self, const XStoreContextHandle storeContextHandle, XStoreProductKind productKinds, UINT32 maxItemsToRetrievePerPage, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, XStoreProductKind productKinds, UINT32 maxItemsToRetrievePerPage, XAsyncBlock * async)>(trace::OriginalSlot(self, 9));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 9, "XStoreQueryEntitledProductsAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordScalar(call_id, "productKinds", productKinds);
        trace::RecordScalar(call_id, "maxItemsToRetrievePerPage", maxItemsToRetrievePerPage);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, productKinds, maxItemsToRetrievePerPage, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot10_XStoreQueryEntitledProductsResult(void *self, XAsyncBlock * async, XStoreProductQueryHandle * productQueryHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreProductQueryHandle * productQueryHandle)>(trace::OriginalSlot(self, 10));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 10, "XStoreQueryEntitledProductsResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "productQueryHandle", reinterpret_cast<const void *>(productQueryHandle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, productQueryHandle);
    try {
        trace::RecordOutputHandleObject(call_id, "productQueryHandle", productQueryHandle, "XStoreProductQueryHandle *");
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot11_XStoreQueryProductForCurrentGameAsync(void *self, const XStoreContextHandle storeContextHandle, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, XAsyncBlock * async)>(trace::OriginalSlot(self, 11));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 11, "XStoreQueryProductForCurrentGameAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot12_XStoreQueryProductForCurrentGameResult(void *self, XAsyncBlock * async, XStoreProductQueryHandle * productQueryHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreProductQueryHandle * productQueryHandle)>(trace::OriginalSlot(self, 12));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 12, "XStoreQueryProductForCurrentGameResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "productQueryHandle", reinterpret_cast<const void *>(productQueryHandle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, productQueryHandle);
    try {
        trace::RecordOutputHandleObject(call_id, "productQueryHandle", productQueryHandle, "XStoreProductQueryHandle *");
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot13_XStoreQueryProductForPackageAsync(void *self, const XStoreContextHandle storeContextHandle, XStoreProductKind productKinds, const char * packageIdentifier, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, XStoreProductKind productKinds, const char * packageIdentifier, XAsyncBlock * async)>(trace::OriginalSlot(self, 13));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 13, "XStoreQueryProductForPackageAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordScalar(call_id, "productKinds", productKinds);
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, productKinds, packageIdentifier, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot14_XStoreQueryProductForPackageResult(void *self, XAsyncBlock * async, XStoreProductQueryHandle * productQueryHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreProductQueryHandle * productQueryHandle)>(trace::OriginalSlot(self, 14));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 14, "XStoreQueryProductForPackageResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "productQueryHandle", reinterpret_cast<const void *>(productQueryHandle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, productQueryHandle);
    try {
        trace::RecordOutputHandleObject(call_id, "productQueryHandle", productQueryHandle, "XStoreProductQueryHandle *");
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot15_XStoreEnumerateProductsQuery(void *self, const XStoreProductQueryHandle productQueryHandle, void * context, XStoreProductQueryCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreProductQueryHandle productQueryHandle, void * context, XStoreProductQueryCallback * callback)>(trace::OriginalSlot(self, 15));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 15, "XStoreEnumerateProductsQuery", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "productQueryHandle", productQueryHandle, "const XStoreProductQueryHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, productQueryHandle, context, trace::WrapCallback<XStoreProductQueryCallback>(call_id, "XStoreProductQueryCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XStoreProductQueryCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXStoreImpl_slot16_XStoreProductsQueryHasMorePages(void *self, const XStoreProductQueryHandle productQueryHandle)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, const XStoreProductQueryHandle productQueryHandle)>(trace::OriginalSlot(self, 16));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 16, "XStoreProductsQueryHasMorePages", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "productQueryHandle", productQueryHandle, "const XStoreProductQueryHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, productQueryHandle);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot17_XStoreProductsQueryNextPageAsync(void *self, const XStoreProductQueryHandle productQueryHandle, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreProductQueryHandle productQueryHandle, XAsyncBlock * async)>(trace::OriginalSlot(self, 17));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 17, "XStoreProductsQueryNextPageAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "productQueryHandle", productQueryHandle, "const XStoreProductQueryHandle");
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, productQueryHandle, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot18_XStoreProductsQueryNextPageResult(void *self, XAsyncBlock * async, XStoreProductQueryHandle * productQueryHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreProductQueryHandle * productQueryHandle)>(trace::OriginalSlot(self, 18));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 18, "XStoreProductsQueryNextPageResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "productQueryHandle", reinterpret_cast<const void *>(productQueryHandle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, productQueryHandle);
    try {
        trace::RecordOutputHandleObject(call_id, "productQueryHandle", productQueryHandle, "XStoreProductQueryHandle *");
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXStoreImpl_slot19_XStoreCloseProductsQueryHandle(void *self, XStoreProductQueryHandle productQueryHandle)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XStoreProductQueryHandle productQueryHandle)>(trace::OriginalSlot(self, 19));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 19, "XStoreCloseProductsQueryHandle", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "productQueryHandle", productQueryHandle, "XStoreProductQueryHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, productQueryHandle);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot20_XStoreAcquireLicenseForPackageAsync(void *self, const XStoreProductQueryHandle productQueryHandle, const char * packageIdentifier, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreProductQueryHandle productQueryHandle, const char * packageIdentifier, XAsyncBlock * async)>(trace::OriginalSlot(self, 20));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 20, "XStoreAcquireLicenseForPackageAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "productQueryHandle", productQueryHandle, "const XStoreProductQueryHandle");
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, productQueryHandle, packageIdentifier, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot21_XStoreAcquireLicenseForPackageResult(void *self, XAsyncBlock * async, XStoreLicenseHandle * storeLicenseHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreLicenseHandle * storeLicenseHandle)>(trace::OriginalSlot(self, 21));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 21, "XStoreAcquireLicenseForPackageResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "storeLicenseHandle", reinterpret_cast<const void *>(storeLicenseHandle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, storeLicenseHandle);
    try {
        trace::RecordOutputHandleObject(call_id, "storeLicenseHandle", storeLicenseHandle, "XStoreLicenseHandle *");
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXStoreImpl_slot22_XStoreIsLicenseValid(void *self, const XStoreLicenseHandle storeLicenseHandle)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, const XStoreLicenseHandle storeLicenseHandle)>(trace::OriginalSlot(self, 22));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 22, "XStoreIsLicenseValid", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeLicenseHandle", storeLicenseHandle, "const XStoreLicenseHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeLicenseHandle);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXStoreImpl_slot23_XStoreCloseLicenseHandle(void *self, XStoreLicenseHandle storeLicenseHandle)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XStoreLicenseHandle storeLicenseHandle)>(trace::OriginalSlot(self, 23));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 23, "XStoreCloseLicenseHandle", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeLicenseHandle", storeLicenseHandle, "XStoreLicenseHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, storeLicenseHandle);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot24_XStoreCanAcquireLicenseForStoreIdAsync(void *self, const XStoreContextHandle storeContextHandle, const char * storeProductId, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char * storeProductId, XAsyncBlock * async)>(trace::OriginalSlot(self, 24));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 24, "XStoreCanAcquireLicenseForStoreIdAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputString(call_id, "storeProductId", storeProductId, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, storeProductId, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot25_XStoreCanAcquireLicenseForStoreIdResult(void *self, XAsyncBlock * async, XStoreCanAcquireLicenseResult * storeCanAcquireLicense)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreCanAcquireLicenseResult * storeCanAcquireLicense)>(trace::OriginalSlot(self, 25));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 25, "XStoreCanAcquireLicenseForStoreIdResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "storeCanAcquireLicense", reinterpret_cast<const void *>(storeCanAcquireLicense), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, storeCanAcquireLicense);
    try {
        trace::RecordOutputObject(call_id, "storeCanAcquireLicense", storeCanAcquireLicense, "XStoreCanAcquireLicenseResult *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot26_XStoreCanAcquireLicenseForPackageAsync(void *self, const XStoreContextHandle storeContextHandle, const char * packageIdentifier, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char * packageIdentifier, XAsyncBlock * async)>(trace::OriginalSlot(self, 26));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 26, "XStoreCanAcquireLicenseForPackageAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputString(call_id, "packageIdentifier", packageIdentifier, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, packageIdentifier, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot27_XStoreCanAcquireLicenseForPackageResult(void *self, XAsyncBlock * async, XStoreCanAcquireLicenseResult * storeCanAcquireLicense)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreCanAcquireLicenseResult * storeCanAcquireLicense)>(trace::OriginalSlot(self, 27));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 27, "XStoreCanAcquireLicenseForPackageResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "storeCanAcquireLicense", reinterpret_cast<const void *>(storeCanAcquireLicense), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, storeCanAcquireLicense);
    try {
        trace::RecordOutputObject(call_id, "storeCanAcquireLicense", storeCanAcquireLicense, "XStoreCanAcquireLicenseResult *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot28_XStoreQueryGameLicenseAsync(void *self, const XStoreContextHandle storeContextHandle, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, XAsyncBlock * async)>(trace::OriginalSlot(self, 28));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 28, "XStoreQueryGameLicenseAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot29_XStoreQueryGameLicenseResult(void *self, XAsyncBlock * async, XStoreGameLicense * license)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreGameLicense * license)>(trace::OriginalSlot(self, 29));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 29, "XStoreQueryGameLicenseResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "license", reinterpret_cast<const void *>(license), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, license);
    try {
        trace::RecordOutputObject(call_id, "license", license, "XStoreGameLicense *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot30_XStoreQueryAddOnLicensesAsync(void *self, const XStoreContextHandle storeContextHandle, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, XAsyncBlock * async)>(trace::OriginalSlot(self, 30));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 30, "XStoreQueryAddOnLicensesAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot31_XStoreQueryAddOnLicensesResultCount(void *self, XAsyncBlock * async, UINT32 * count)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, UINT32 * count)>(trace::OriginalSlot(self, 31));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 31, "XStoreQueryAddOnLicensesResultCount", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "count", reinterpret_cast<const void *>(count), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, count);
    try {
        trace::RecordOutputObject(call_id, "count", count, "UINT32 *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot32_XStoreQueryAddOnLicensesResult(void *self, XAsyncBlock * async, UINT32 count, XStoreAddonLicense * addOnLicenses)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, UINT32 count, XStoreAddonLicense * addOnLicenses)>(trace::OriginalSlot(self, 32));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 32, "XStoreQueryAddOnLicensesResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "count", count);
        trace::RecordPointer(call_id, "addOnLicenses", reinterpret_cast<const void *>(addOnLicenses), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, count, addOnLicenses);
    try {
        trace::RecordOutputBuffer(call_id, "addOnLicenses", reinterpret_cast<const void *>(addOnLicenses), (static_cast<std::size_t>(count)) * sizeof(*addOnLicenses), reinterpret_cast<const void *>(nullptr), 0, sizeof(*addOnLicenses), "XStoreAddonLicense *", trace::OutputEncoding::Binary, false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot33_XStoreQueryConsumableBalanceRemainingAsync(void *self, const XStoreContextHandle storeContextHandle, const char * storeProductId, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char * storeProductId, XAsyncBlock * async)>(trace::OriginalSlot(self, 33));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 33, "XStoreQueryConsumableBalanceRemainingAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputString(call_id, "storeProductId", storeProductId, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, storeProductId, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot34_XStoreQueryConsumableBalanceRemainingResult(void *self, XAsyncBlock * async, XStoreConsumableResult * consumableResult)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreConsumableResult * consumableResult)>(trace::OriginalSlot(self, 34));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 34, "XStoreQueryConsumableBalanceRemainingResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "consumableResult", reinterpret_cast<const void *>(consumableResult), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, consumableResult);
    try {
        trace::RecordOutputObject(call_id, "consumableResult", consumableResult, "XStoreConsumableResult *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot35_XStoreReportConsumableFulfillmentAsync(void *self, const XStoreContextHandle storeContextHandle, const char * storeProductId, UINT32 quantity, GUID trackingId, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char * storeProductId, UINT32 quantity, GUID trackingId, XAsyncBlock * async)>(trace::OriginalSlot(self, 35));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 35, "XStoreReportConsumableFulfillmentAsync", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "storeContextHandle", storeContextHandle);
        trace::RecordInputString(call_id, "storeProductId", storeProductId, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "quantity", quantity);
        trace::RecordScalar(call_id, "trackingId", trackingId);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, storeProductId, quantity, trackingId, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot36_XStoreReportConsumableFulfillmentResult(void *self, XAsyncBlock * async, XStoreConsumableResult * consumableResult)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreConsumableResult * consumableResult)>(trace::OriginalSlot(self, 36));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 36, "XStoreReportConsumableFulfillmentResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "consumableResult", reinterpret_cast<const void *>(consumableResult), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, consumableResult);
    try {
        trace::RecordOutputObject(call_id, "consumableResult", consumableResult, "XStoreConsumableResult *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot37_XStoreGetUserCollectionsIdAsync(void *self, const XStoreContextHandle storeContextHandle, const char * serviceTicket, const char * publisherUserId, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char * serviceTicket, const char * publisherUserId, XAsyncBlock * async)>(trace::OriginalSlot(self, 37));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 37, "XStoreGetUserCollectionsIdAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputString(call_id, "serviceTicket", serviceTicket, trace::ArgumentKind::StringSensitive);
        trace::RecordInputString(call_id, "publisherUserId", publisherUserId, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, serviceTicket, publisherUserId, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot38_XStoreGetUserCollectionsIdResultSize(void *self, XAsyncBlock * async, SIZE_T * size)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T * size)>(trace::OriginalSlot(self, 38));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 38, "XStoreGetUserCollectionsIdResultSize", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "size", reinterpret_cast<const void *>(size), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, size);
    try {
        trace::RecordOutputObject(call_id, "size", size, "SIZE_T *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot39_XStoreGetUserCollectionsIdResult(void *self, XAsyncBlock * async, SIZE_T size, char * result)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T size, char * result)>(trace::OriginalSlot(self, 39));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 39, "XStoreGetUserCollectionsIdResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "size", size);
        trace::RecordPointer(call_id, "result", reinterpret_cast<const void *>(result), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, size, result);
    try {
        trace::RecordOutputBuffer(call_id, "result", reinterpret_cast<const void *>(result), (static_cast<std::size_t>(size)) * sizeof(*result), reinterpret_cast<const void *>(nullptr), 0, sizeof(*result), "char *", trace::OutputEncoding::Ansi, false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot40_XStoreGetUserPurchaseIdAsync(void *self, const XStoreContextHandle storeContextHandle, const char * serviceTicket, const char * publisherUserId, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char * serviceTicket, const char * publisherUserId, XAsyncBlock * async)>(trace::OriginalSlot(self, 40));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 40, "XStoreGetUserPurchaseIdAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputString(call_id, "serviceTicket", serviceTicket, trace::ArgumentKind::StringSensitive);
        trace::RecordInputString(call_id, "publisherUserId", publisherUserId, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, serviceTicket, publisherUserId, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot41_XStoreGetUserPurchaseIdResultSize(void *self, XAsyncBlock * async, SIZE_T * size)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T * size)>(trace::OriginalSlot(self, 41));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 41, "XStoreGetUserPurchaseIdResultSize", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "size", reinterpret_cast<const void *>(size), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, size);
    try {
        trace::RecordOutputObject(call_id, "size", size, "SIZE_T *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot42_XStoreGetUserPurchaseIdResult(void *self, XAsyncBlock * async, SIZE_T size, char * result)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T size, char * result)>(trace::OriginalSlot(self, 42));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 42, "XStoreGetUserPurchaseIdResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "size", size);
        trace::RecordPointer(call_id, "result", reinterpret_cast<const void *>(result), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, size, result);
    try {
        trace::RecordOutputBuffer(call_id, "result", reinterpret_cast<const void *>(result), (static_cast<std::size_t>(size)) * sizeof(*result), reinterpret_cast<const void *>(nullptr), 0, sizeof(*result), "char *", trace::OutputEncoding::Ansi, false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot43_XStoreQueryLicenseTokenAsync(void *self, const XStoreContextHandle storeContextHandle, const char ** productIds, SIZE_T productIdsCount, const char * customDeveloperString, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char ** productIds, SIZE_T productIdsCount, const char * customDeveloperString, XAsyncBlock * async)>(trace::OriginalSlot(self, 43));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 43, "XStoreQueryLicenseTokenAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputStringArray(call_id, "productIds", reinterpret_cast<const void *>(productIds), static_cast<std::size_t>(productIdsCount), static_cast<std::size_t>(0), false, true);
        trace::RecordScalar(call_id, "productIdsCount", productIdsCount);
        trace::RecordInputString(call_id, "customDeveloperString", customDeveloperString, trace::ArgumentKind::StringSensitive);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, productIds, productIdsCount, customDeveloperString, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot44_XStoreQueryLicenseTokenResultSize(void *self, XAsyncBlock * async, SIZE_T * size)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T * size)>(trace::OriginalSlot(self, 44));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 44, "XStoreQueryLicenseTokenResultSize", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "size", reinterpret_cast<const void *>(size), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, size);
    try {
        trace::RecordOutputObject(call_id, "size", size, "SIZE_T *", true);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot45_XStoreQueryLicenseTokenResult(void *self, XAsyncBlock * async, SIZE_T size, char * result)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T size, char * result)>(trace::OriginalSlot(self, 45));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 45, "XStoreQueryLicenseTokenResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "size", size);
        trace::RecordPointer(call_id, "result", reinterpret_cast<const void *>(result), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, size, result);
    try {
        trace::RecordOutputBuffer(call_id, "result", reinterpret_cast<const void *>(result), (static_cast<std::size_t>(size)) * sizeof(*result), reinterpret_cast<const void *>(nullptr), 0, sizeof(*result), "char *", trace::OutputEncoding::Ansi, true);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot49_XStoreShowPurchaseUIAsync(void *self, const XStoreContextHandle storeContextHandle, const char * storeId, const char * name, const char * extendedJsonData, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char * storeId, const char * name, const char * extendedJsonData, XAsyncBlock * async)>(trace::OriginalSlot(self, 49));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 49, "XStoreShowPurchaseUIAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputString(call_id, "storeId", storeId, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "name", name, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "extendedJsonData", extendedJsonData, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, storeId, name, extendedJsonData, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot50_XStoreShowPurchaseUIResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 50));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 50, "XStoreShowPurchaseUIResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot51_XStoreShowRateAndReviewUIAsync(void *self, const XStoreContextHandle storeContextHandle, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, XAsyncBlock * async)>(trace::OriginalSlot(self, 51));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 51, "XStoreShowRateAndReviewUIAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot52_XStoreShowRateAndReviewUIResult(void *self, XAsyncBlock * async, XStoreRateAndReviewResult * result)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreRateAndReviewResult * result)>(trace::OriginalSlot(self, 52));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 52, "XStoreShowRateAndReviewUIResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "result", reinterpret_cast<const void *>(result), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, result);
    try {
        trace::RecordOutputObject(call_id, "result", result, "XStoreRateAndReviewResult *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot53_XStoreShowRedeemTokenUIAsync(void *self, const XStoreContextHandle storeContextHandle, const char * token, const char ** allowedStoreIds, SIZE_T allowedStoreIdsCount, BOOLEAN disallowCsvRedemption, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char * token, const char ** allowedStoreIds, SIZE_T allowedStoreIdsCount, BOOLEAN disallowCsvRedemption, XAsyncBlock * async)>(trace::OriginalSlot(self, 53));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 53, "XStoreShowRedeemTokenUIAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputString(call_id, "token", token, trace::ArgumentKind::StringSensitive);
        trace::RecordInputStringArray(call_id, "allowedStoreIds", reinterpret_cast<const void *>(allowedStoreIds), static_cast<std::size_t>(allowedStoreIdsCount), static_cast<std::size_t>(0), false, true);
        trace::RecordScalar(call_id, "allowedStoreIdsCount", allowedStoreIdsCount);
        trace::RecordScalar(call_id, "disallowCsvRedemption", disallowCsvRedemption);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, token, allowedStoreIds, allowedStoreIdsCount, disallowCsvRedemption, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot54_XStoreShowRedeemTokenUIResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 54));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 54, "XStoreShowRedeemTokenUIResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot55_XStoreQueryGameAndDlcPackageUpdatesAsync(void *self, const XStoreContextHandle storeContextHandle, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, XAsyncBlock * async)>(trace::OriginalSlot(self, 55));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 55, "XStoreQueryGameAndDlcPackageUpdatesAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot56_XStoreQueryGameAndDlcPackageUpdatesResultCount(void *self, XAsyncBlock * async, UINT32 * count)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, UINT32 * count)>(trace::OriginalSlot(self, 56));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 56, "XStoreQueryGameAndDlcPackageUpdatesResultCount", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "count", reinterpret_cast<const void *>(count), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, count);
    try {
        trace::RecordOutputObject(call_id, "count", count, "UINT32 *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot57_XStoreQueryGameAndDlcPackageUpdatesResult(void *self, XAsyncBlock * async, UINT32 count, XStorePackageUpdate * packageUpdates)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, UINT32 count, XStorePackageUpdate * packageUpdates)>(trace::OriginalSlot(self, 57));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 57, "XStoreQueryGameAndDlcPackageUpdatesResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "count", count);
        trace::RecordPointer(call_id, "packageUpdates", reinterpret_cast<const void *>(packageUpdates), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, count, packageUpdates);
    try {
        trace::RecordOutputBuffer(call_id, "packageUpdates", reinterpret_cast<const void *>(packageUpdates), (static_cast<std::size_t>(count)) * sizeof(*packageUpdates), reinterpret_cast<const void *>(nullptr), 0, sizeof(*packageUpdates), "XStorePackageUpdate *", trace::OutputEncoding::Binary, false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot58_XStoreDownloadPackageUpdatesAsync(void *self, const XStoreContextHandle storeContextHandle, const char ** packageIdentifiers, SIZE_T packageIdentifiersCount, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char ** packageIdentifiers, SIZE_T packageIdentifiersCount, XAsyncBlock * async)>(trace::OriginalSlot(self, 58));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 58, "XStoreDownloadPackageUpdatesAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputStringArray(call_id, "packageIdentifiers", reinterpret_cast<const void *>(packageIdentifiers), static_cast<std::size_t>(packageIdentifiersCount), static_cast<std::size_t>(0), false, false);
        trace::RecordScalar(call_id, "packageIdentifiersCount", packageIdentifiersCount);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, packageIdentifiers, packageIdentifiersCount, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot59_XStoreDownloadPackageUpdatesResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 59));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 59, "XStoreDownloadPackageUpdatesResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot60_XStoreDownloadAndInstallPackageUpdatesAsync(void *self, const XStoreContextHandle storeContextHandle, const char ** packageIdentifiers, SIZE_T packageIdentifiersCount, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char ** packageIdentifiers, SIZE_T packageIdentifiersCount, XAsyncBlock * async)>(trace::OriginalSlot(self, 60));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 60, "XStoreDownloadAndInstallPackageUpdatesAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputStringArray(call_id, "packageIdentifiers", reinterpret_cast<const void *>(packageIdentifiers), static_cast<std::size_t>(packageIdentifiersCount), static_cast<std::size_t>(0), false, false);
        trace::RecordScalar(call_id, "packageIdentifiersCount", packageIdentifiersCount);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, packageIdentifiers, packageIdentifiersCount, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot61_XStoreDownloadAndInstallPackageUpdatesResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 61));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 61, "XStoreDownloadAndInstallPackageUpdatesResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot62_XStoreDownloadAndInstallPackagesAsync(void *self, const XStoreContextHandle storeContextHandle, const char ** storeIds, SIZE_T storeIdsCount, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char ** storeIds, SIZE_T storeIdsCount, XAsyncBlock * async)>(trace::OriginalSlot(self, 62));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 62, "XStoreDownloadAndInstallPackagesAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputStringArray(call_id, "storeIds", reinterpret_cast<const void *>(storeIds), static_cast<std::size_t>(storeIdsCount), static_cast<std::size_t>(0), false, false);
        trace::RecordScalar(call_id, "storeIdsCount", storeIdsCount);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, storeIds, storeIdsCount, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot63_XStoreDownloadAndInstallPackagesResultCount(void *self, XAsyncBlock * async, UINT32 * count)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, UINT32 * count)>(trace::OriginalSlot(self, 63));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 63, "XStoreDownloadAndInstallPackagesResultCount", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "count", reinterpret_cast<const void *>(count), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, count);
    try {
        trace::RecordOutputObject(call_id, "count", count, "UINT32 *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot64_XStoreDownloadAndInstallPackagesResult(void *self, XAsyncBlock * async, UINT32 count, char ** packageIdentifiers)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, UINT32 count, char ** packageIdentifiers)>(trace::OriginalSlot(self, 64));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 64, "XStoreDownloadAndInstallPackagesResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "count", count);
        trace::RecordPointer(call_id, "packageIdentifiers", reinterpret_cast<const void *>(packageIdentifiers), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, count, packageIdentifiers);
    try {
        trace::RecordOutputStringArray(call_id, "packageIdentifiers", reinterpret_cast<const void *>(packageIdentifiers), static_cast<std::size_t>(count), static_cast<std::size_t>(33), false, false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot65_XStoreQueryPackageIdentifier(void *self, const char * storeId, SIZE_T size, char * packageIdentifier)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const char * storeId, SIZE_T size, char * packageIdentifier)>(trace::OriginalSlot(self, 65));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 65, "XStoreQueryPackageIdentifier", reinterpret_cast<const void *>(self));
        trace::RecordInputString(call_id, "storeId", storeId, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "size", size);
        trace::RecordPointer(call_id, "packageIdentifier", reinterpret_cast<const void *>(packageIdentifier), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeId, size, packageIdentifier);
    try {
        trace::RecordOutputBuffer(call_id, "packageIdentifier", reinterpret_cast<const void *>(packageIdentifier), (static_cast<std::size_t>(size)) * sizeof(*packageIdentifier), reinterpret_cast<const void *>(nullptr), 0, sizeof(*packageIdentifier), "char *", trace::OutputEncoding::Ansi, false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot66_XStoreRegisterGameLicenseChanged(void *self, XStoreContextHandle storeContextHandle, XTaskQueueHandle queue, void * context, XStoreGameLicenseChangedCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XStoreContextHandle storeContextHandle, XTaskQueueHandle queue, void * context, XStoreGameLicenseChangedCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 66));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 66, "XStoreRegisterGameLicenseChanged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "XStoreContextHandle");
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, queue, context, trace::WrapCallback<XStoreGameLicenseChangedCallback>(call_id, "XStoreGameLicenseChangedCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XStoreGameLicenseChangedCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXStoreImpl_slot67_XStoreUnregisterGameLicenseChanged(void *self, XStoreContextHandle storeContextHandle, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XStoreContextHandle storeContextHandle, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 67));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 67, "XStoreUnregisterGameLicenseChanged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "XStoreContextHandle");
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl_slot68_XStoreRegisterPackageLicenseLost(void *self, XStoreLicenseHandle licenseHandle, XTaskQueueHandle queue, void * context, XStorePackageLicenseLostCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XStoreLicenseHandle licenseHandle, XTaskQueueHandle queue, void * context, XStorePackageLicenseLostCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 68));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 68, "XStoreRegisterPackageLicenseLost", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "licenseHandle", licenseHandle, "XStoreLicenseHandle");
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, licenseHandle, queue, context, trace::WrapCallback<XStorePackageLicenseLostCallback>(call_id, "XStorePackageLicenseLostCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XStorePackageLicenseLostCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXStoreImpl_slot69_XStoreUnregisterPackageLicenseLost(void *self, XStoreLicenseHandle licenseHandle, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XStoreLicenseHandle licenseHandle, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 69));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("0dd112ac-7c24-448c-b92b-3960fb5bd30c", 69, "XStoreUnregisterPackageLicenseLost", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "licenseHandle", licenseHandle, "XStoreLicenseHandle");
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, licenseHandle, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXStoreImpl2_slot70_XStoreIsAvailabilityPurchasable(void *self, const XStoreAvailability availability)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, const XStoreAvailability availability)>(trace::OriginalSlot(self, 70));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("60b09f4e-1b85-45b1-826c-169118e230e1", 70, "XStoreIsAvailabilityPurchasable", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "availability", availability);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, availability);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl3_slot71_XStoreAcquireLicenseForDurablesAsync(void *self, const XStoreContextHandle storeContextHandle, const char * storeId, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char * storeId, XAsyncBlock * async)>(trace::OriginalSlot(self, 71));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("2d42fea5-e71d-4b76-97cd-c50afbb3ae5d", 71, "XStoreAcquireLicenseForDurablesAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputString(call_id, "storeId", storeId, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, storeId, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl3_slot72_XStoreAcquireLicenseForDurablesResult(void *self, XAsyncBlock * async, XStoreLicenseHandle * storeLicenseHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreLicenseHandle * storeLicenseHandle)>(trace::OriginalSlot(self, 72));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("2d42fea5-e71d-4b76-97cd-c50afbb3ae5d", 72, "XStoreAcquireLicenseForDurablesResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "storeLicenseHandle", reinterpret_cast<const void *>(storeLicenseHandle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, storeLicenseHandle);
    try {
        trace::RecordOutputHandleObject(call_id, "storeLicenseHandle", storeLicenseHandle, "XStoreLicenseHandle *");
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl4_slot73_XStoreShowAssociatedProductsUIAsync(void *self, const XStoreContextHandle storeContextHandle, const char * storeId, XStoreProductKind productKinds, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char * storeId, XStoreProductKind productKinds, XAsyncBlock * async)>(trace::OriginalSlot(self, 73));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("de3dbdd4-0b37-4bdb-a10e-acf3a354d06a", 73, "XStoreShowAssociatedProductsUIAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputString(call_id, "storeId", storeId, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "productKinds", productKinds);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, storeId, productKinds, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl4_slot74_XStoreShowAssociatedProductsUIResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 74));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("de3dbdd4-0b37-4bdb-a10e-acf3a354d06a", 74, "XStoreShowAssociatedProductsUIResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl4_slot75_XStoreShowProductPageUIAsync(void *self, const XStoreContextHandle storeContextHandle, const char * storeId, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char * storeId, XAsyncBlock * async)>(trace::OriginalSlot(self, 75));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("de3dbdd4-0b37-4bdb-a10e-acf3a354d06a", 75, "XStoreShowProductPageUIAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputString(call_id, "storeId", storeId, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, storeId, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl4_slot76_XStoreShowProductPageUIResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 76));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("de3dbdd4-0b37-4bdb-a10e-acf3a354d06a", 76, "XStoreShowProductPageUIResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl5_slot77_XStoreQueryAssociatedProductsForStoreIdAsync(void *self, const XStoreContextHandle storeContextHandle, const char * storeId, XStoreProductKind productKinds, UINT32 maxItemsToRetrievePerPage, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const XStoreContextHandle storeContextHandle, const char * storeId, XStoreProductKind productKinds, UINT32 maxItemsToRetrievePerPage, XAsyncBlock * async)>(trace::OriginalSlot(self, 77));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("5c48dedf-0b67-4492-a4b5-6829b8e796e1", 77, "XStoreQueryAssociatedProductsForStoreIdAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "const XStoreContextHandle");
        trace::RecordInputString(call_id, "storeId", storeId, trace::ArgumentKind::String);
        trace::RecordScalar(call_id, "productKinds", productKinds);
        trace::RecordScalar(call_id, "maxItemsToRetrievePerPage", maxItemsToRetrievePerPage);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, storeId, productKinds, maxItemsToRetrievePerPage, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl5_slot78_XStoreQueryAssociatedProductsForStoreIdResult(void *self, XAsyncBlock * async, XStoreProductQueryHandle * productQueryHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XStoreProductQueryHandle * productQueryHandle)>(trace::OriginalSlot(self, 78));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("5c48dedf-0b67-4492-a4b5-6829b8e796e1", 78, "XStoreQueryAssociatedProductsForStoreIdResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "productQueryHandle", reinterpret_cast<const void *>(productQueryHandle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, productQueryHandle);
    try {
        trace::RecordOutputHandleObject(call_id, "productQueryHandle", productQueryHandle, "XStoreProductQueryHandle *");
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl5_slot79_XStoreQueryPackageUpdatesAsync(void *self, XStoreContextHandle storeContextHandle, const char ** packageIdentifiers, SIZE_T packageIdentifiersCount, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XStoreContextHandle storeContextHandle, const char ** packageIdentifiers, SIZE_T packageIdentifiersCount, XAsyncBlock * async)>(trace::OriginalSlot(self, 79));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("5c48dedf-0b67-4492-a4b5-6829b8e796e1", 79, "XStoreQueryPackageUpdatesAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "XStoreContextHandle");
        trace::RecordInputStringArray(call_id, "packageIdentifiers", reinterpret_cast<const void *>(packageIdentifiers), static_cast<std::size_t>(packageIdentifiersCount), static_cast<std::size_t>(0), false, false);
        trace::RecordScalar(call_id, "packageIdentifiersCount", packageIdentifiersCount);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, packageIdentifiers, packageIdentifiersCount, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl5_slot80_XStoreQueryPackageUpdatesResultCount(void *self, XAsyncBlock * async, UINT32 * count)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, UINT32 * count)>(trace::OriginalSlot(self, 80));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("5c48dedf-0b67-4492-a4b5-6829b8e796e1", 80, "XStoreQueryPackageUpdatesResultCount", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "count", reinterpret_cast<const void *>(count), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, count);
    try {
        trace::RecordOutputObject(call_id, "count", count, "UINT32 *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl5_slot81_XStoreQueryPackageUpdatesResult(void *self, XAsyncBlock * async, UINT32 count, XStorePackageUpdate * packageUpdates)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, UINT32 count, XStorePackageUpdate * packageUpdates)>(trace::OriginalSlot(self, 81));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("5c48dedf-0b67-4492-a4b5-6829b8e796e1", 81, "XStoreQueryPackageUpdatesResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "count", count);
        trace::RecordPointer(call_id, "packageUpdates", reinterpret_cast<const void *>(packageUpdates), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, count, packageUpdates);
    try {
        trace::RecordOutputBuffer(call_id, "packageUpdates", reinterpret_cast<const void *>(packageUpdates), (static_cast<std::size_t>(count)) * sizeof(*packageUpdates), reinterpret_cast<const void *>(nullptr), 0, sizeof(*packageUpdates), "XStorePackageUpdate *", trace::OutputEncoding::Binary, false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl6_slot82_XStoreShowGiftingUIAsync(void *self, XStoreContextHandle storeContextHandle, const char * storeId, const char * name, const char * extendedJsonData, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XStoreContextHandle storeContextHandle, const char * storeId, const char * name, const char * extendedJsonData, XAsyncBlock * async)>(trace::OriginalSlot(self, 82));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("b09d803c-2414-4a05-82c6-66dfdc9e9a44", 82, "XStoreShowGiftingUIAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "storeContextHandle", storeContextHandle, "XStoreContextHandle");
        trace::RecordInputString(call_id, "storeId", storeId, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "name", name, trace::ArgumentKind::String);
        trace::RecordInputString(call_id, "extendedJsonData", extendedJsonData, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, storeContextHandle, storeId, name, extendedJsonData, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXStoreImpl6_slot83_XStoreShowGiftingUIResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 83));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("b09d803c-2414-4a05-82c6-66dfdc9e9a44", 83, "XStoreShowGiftingUIResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

XSystemAnalyticsInfo WINAPI xgrtrace_wrap_IXSystemAnalyticsImpl_slot3_XSystemGetAnalyticsInfo(void *self)
{
    auto original = reinterpret_cast<XSystemAnalyticsInfo (WINAPI *)(void *self)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return {};
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("b884675d-b738-4a9c-815d-9a9a1e0c6c9b", 3, "XSystemGetAnalyticsInfo", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXSystemImpl_slot3_XSystemGetConsoleId(void *self, INT32 consoleIdSize, char * consoleId, SIZE_T * consoleIdUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, INT32 consoleIdSize, char * consoleId, SIZE_T * consoleIdUsed)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("e349bd1a-fc20-4e40-b99c-4178cc6b409f", 3, "XSystemGetConsoleId", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "consoleIdSize", consoleIdSize);
        trace::RecordPointer(call_id, "consoleId", reinterpret_cast<const void *>(consoleId), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "consoleIdUsed", reinterpret_cast<const void *>(consoleIdUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, consoleIdSize, consoleId, consoleIdUsed);
    try {
        trace::RecordOutputBuffer(call_id, "consoleId", reinterpret_cast<const void *>(consoleId), (static_cast<std::size_t>(consoleIdSize)) * sizeof(*consoleId), reinterpret_cast<const void *>(consoleIdUsed), sizeof(*consoleIdUsed), sizeof(*consoleId), "char *", trace::OutputEncoding::Binary, false);
        trace::RecordOutputObject(call_id, "consoleIdUsed", consoleIdUsed, "SIZE_T *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXSystemImpl_slot4_XSystemGetXboxLiveSandboxId(void *self, INT32 sandboxIdSize, char * sandboxId, SIZE_T * sandboxIdUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, INT32 sandboxIdSize, char * sandboxId, SIZE_T * sandboxIdUsed)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("e349bd1a-fc20-4e40-b99c-4178cc6b409f", 4, "XSystemGetXboxLiveSandboxId", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "sandboxIdSize", sandboxIdSize);
        trace::RecordPointer(call_id, "sandboxId", reinterpret_cast<const void *>(sandboxId), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "sandboxIdUsed", reinterpret_cast<const void *>(sandboxIdUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, sandboxIdSize, sandboxId, sandboxIdUsed);
    try {
        trace::RecordOutputBuffer(call_id, "sandboxId", reinterpret_cast<const void *>(sandboxId), (static_cast<std::size_t>(sandboxIdSize)) * sizeof(*sandboxId), reinterpret_cast<const void *>(sandboxIdUsed), sizeof(*sandboxIdUsed), sizeof(*sandboxId), "char *", trace::OutputEncoding::Binary, false);
        trace::RecordOutputObject(call_id, "sandboxIdUsed", sandboxIdUsed, "SIZE_T *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXSystemImpl_slot5_XSystemGetAppSpecificDeviceId(void *self, INT32 appSpecificDeviceIdSize, char * appSpecificDeviceId, SIZE_T * appSpecificDeviceIdUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, INT32 appSpecificDeviceIdSize, char * appSpecificDeviceId, SIZE_T * appSpecificDeviceIdUsed)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("e349bd1a-fc20-4e40-b99c-4178cc6b409f", 5, "XSystemGetAppSpecificDeviceId", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "appSpecificDeviceIdSize", appSpecificDeviceIdSize);
        trace::RecordPointer(call_id, "appSpecificDeviceId", reinterpret_cast<const void *>(appSpecificDeviceId), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "appSpecificDeviceIdUsed", reinterpret_cast<const void *>(appSpecificDeviceIdUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, appSpecificDeviceIdSize, appSpecificDeviceId, appSpecificDeviceIdUsed);
    try {
        trace::RecordOutputBuffer(call_id, "appSpecificDeviceId", reinterpret_cast<const void *>(appSpecificDeviceId), (static_cast<std::size_t>(appSpecificDeviceIdSize)) * sizeof(*appSpecificDeviceId), reinterpret_cast<const void *>(appSpecificDeviceIdUsed), sizeof(*appSpecificDeviceIdUsed), sizeof(*appSpecificDeviceId), "char *", trace::OutputEncoding::Binary, false);
        trace::RecordOutputObject(call_id, "appSpecificDeviceIdUsed", appSpecificDeviceIdUsed, "SIZE_T *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXSystemImpl3_slot6_XSystemHandleTrack(void *self, XSystemHandleCallback callback, void * context)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XSystemHandleCallback callback, void * context)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("67ce4bfc-b1d1-4ac7-bc3a-cb9219a97a85", 6, "XSystemHandleTrack", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, trace::WrapCallbackValue<XSystemHandleCallback>(call_id, "XSystemHandleCallback", callback, reinterpret_cast<const void *>(context), nullptr, &xgrtrace_callback_XSystemHandleCallback), context);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXSystemImpl3_slot7_XSystemIsHandleValid(void *self, XSystemHandle handle)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XSystemHandle handle)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("67ce4bfc-b1d1-4ac7-bc3a-cb9219a97a85", 7, "XSystemIsHandleValid", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "handle", handle, "XSystemHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, handle);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXSystemImpl4_slot8_XSystemAllowFullDownloadBandwidth(void *self, BOOLEAN enable)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, BOOLEAN enable)>(trace::OriginalSlot(self, 8));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("dadc2895-34b0-4ef5-a83e-45114d629b80", 8, "XSystemAllowFullDownloadBandwidth", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "enable", enable);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, enable);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot3_XAsyncGetStatus(void *self, XAsyncBlock * asyncBlock, BOOLEAN wait)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * asyncBlock, BOOLEAN wait)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 3, "XAsyncGetStatus", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, asyncBlock, wait);
    try {
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot4_XAsyncGetResultSize(void *self, XAsyncBlock * asyncBlock, SIZE_T * bufferSize)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * asyncBlock, SIZE_T * bufferSize)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 4, "XAsyncGetResultSize", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
        trace::RecordPointer(call_id, "bufferSize", reinterpret_cast<const void *>(bufferSize), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, asyncBlock, bufferSize);
    try {
        trace::RecordOutputObject(call_id, "bufferSize", bufferSize, "SIZE_T *", false);
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXThreadingImpl_slot5_XAsyncCancel(void *self, XAsyncBlock * asyncBlock)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XAsyncBlock * asyncBlock)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 5, "XAsyncCancel", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, asyncBlock);
    try {
        trace::RecordAsyncCallEnd(call_id, asyncBlock, S_OK, false);
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot6_XAsyncRun(void *self, XAsyncBlock * asyncBlock, XAsyncWork * work)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * asyncBlock, XAsyncWork * work)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 6, "XAsyncRun", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
        trace::RecordPointer(call_id, "work", reinterpret_cast<const void *>(work), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, asyncBlock, work);
    try {
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot7_XAsyncBegin(void *self, XAsyncBlock * asyncBlock, void * context, const void * identity, const char * identityName, XAsyncProvider * provider)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * asyncBlock, void * context, const void * identity, const char * identityName, XAsyncProvider * provider)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 7, "XAsyncBegin", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "identity", reinterpret_cast<const void *>(identity), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "identityName", reinterpret_cast<const void *>(identityName), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "provider", reinterpret_cast<const void *>(provider), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, asyncBlock, context, identity, identityName, provider);
    try {
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot9_XAsyncSchedule(void *self, XAsyncBlock * asyncBlock, UINT32 delayInMs)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * asyncBlock, UINT32 delayInMs)>(trace::OriginalSlot(self, 9));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 9, "XAsyncSchedule", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
        trace::RecordScalar(call_id, "delayInMs", delayInMs);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, asyncBlock, delayInMs);
    try {
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXThreadingImpl_slot10_XAsyncComplete(void *self, XAsyncBlock * asyncBlock, HRESULT result, SIZE_T requiredBufferSize)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XAsyncBlock * asyncBlock, HRESULT result, SIZE_T requiredBufferSize)>(trace::OriginalSlot(self, 10));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 10, "XAsyncComplete", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
        trace::RecordScalar(call_id, "result", result);
        trace::RecordScalar(call_id, "requiredBufferSize", requiredBufferSize);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, asyncBlock, result, requiredBufferSize);
    try {
        trace::RecordAsyncCompletionResult(call_id, asyncBlock, result);
        trace::RecordAsyncCallEnd(call_id, asyncBlock, S_OK, false);
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot11_XAsyncGetResult(void *self, XAsyncBlock * asyncBlock, const void * identity, SIZE_T bufferSize, void * buffer, SIZE_T * bufferUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * asyncBlock, const void * identity, SIZE_T bufferSize, void * buffer, SIZE_T * bufferUsed)>(trace::OriginalSlot(self, 11));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 11, "XAsyncGetResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "asyncBlock", asyncBlock);
        trace::RecordPointer(call_id, "identity", reinterpret_cast<const void *>(identity), trace::ArgumentKind::Pointer);
        trace::RecordScalar(call_id, "bufferSize", bufferSize);
        trace::RecordPointer(call_id, "buffer", reinterpret_cast<const void *>(buffer), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "bufferUsed", reinterpret_cast<const void *>(bufferUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, asyncBlock, identity, bufferSize, buffer, bufferUsed);
    try {
        trace::RecordOutputBuffer(call_id, "buffer", reinterpret_cast<const void *>(buffer), (static_cast<std::size_t>(bufferSize)) * 1, reinterpret_cast<const void *>(bufferUsed), sizeof(*bufferUsed), 1, "void *", trace::OutputEncoding::Binary, false);
        trace::RecordOutputObject(call_id, "bufferUsed", bufferUsed, "SIZE_T *", false);
        trace::RecordAsyncCallEnd(call_id, asyncBlock, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot12_XTaskQueueCreate(void *self, XTaskQueueDispatchMode workDispatchMode, XTaskQueueDispatchMode completionDispatchMode, XTaskQueueHandle * queue)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueDispatchMode workDispatchMode, XTaskQueueDispatchMode completionDispatchMode, XTaskQueueHandle * queue)>(trace::OriginalSlot(self, 12));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 12, "XTaskQueueCreate", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "workDispatchMode", workDispatchMode);
        trace::RecordScalar(call_id, "completionDispatchMode", completionDispatchMode);
        trace::RecordPointer(call_id, "queue", reinterpret_cast<const void *>(queue), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, workDispatchMode, completionDispatchMode, queue);
    try {
        trace::RecordOutputHandleObject(call_id, "queue", queue, "XTaskQueueHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot13_XTaskQueueCreateComposite(void *self, XTaskQueuePortHandle workPort, XTaskQueuePortHandle completionPort, XTaskQueueHandle * queue)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueuePortHandle workPort, XTaskQueuePortHandle completionPort, XTaskQueueHandle * queue)>(trace::OriginalSlot(self, 13));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 13, "XTaskQueueCreateComposite", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "workPort", workPort, "XTaskQueuePortHandle");
        trace::RecordHandleArgumentValue(call_id, "completionPort", completionPort, "XTaskQueuePortHandle");
        trace::RecordPointer(call_id, "queue", reinterpret_cast<const void *>(queue), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, workPort, completionPort, queue);
    try {
        trace::RecordOutputHandleObject(call_id, "queue", queue, "XTaskQueueHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot14_XTaskQueueGetPort(void *self, XTaskQueueHandle queue, XTaskQueuePort port, XTaskQueuePortHandle * portHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, XTaskQueuePort port, XTaskQueuePortHandle * portHandle)>(trace::OriginalSlot(self, 14));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 14, "XTaskQueueGetPort", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordScalar(call_id, "port", port);
        trace::RecordPointer(call_id, "portHandle", reinterpret_cast<const void *>(portHandle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, port, portHandle);
    try {
        trace::RecordOutputHandleObject(call_id, "portHandle", portHandle, "XTaskQueuePortHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot15_XTaskQueueDuplicateHandle(void *self, XTaskQueueHandle queueHandle, XTaskQueueHandle * duplicatedHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queueHandle, XTaskQueueHandle * duplicatedHandle)>(trace::OriginalSlot(self, 15));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 15, "XTaskQueueDuplicateHandle", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queueHandle", queueHandle, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "duplicatedHandle", reinterpret_cast<const void *>(duplicatedHandle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queueHandle, duplicatedHandle);
    try {
        trace::RecordOutputHandleObject(call_id, "duplicatedHandle", duplicatedHandle, "XTaskQueueHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXThreadingImpl_slot16_XTaskQueueDispatch(void *self, XTaskQueueHandle queue, XTaskQueuePort port, UINT32 timeoutInMs)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueHandle queue, XTaskQueuePort port, UINT32 timeoutInMs)>(trace::OriginalSlot(self, 16));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 16, "XTaskQueueDispatch", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordScalar(call_id, "port", port);
        trace::RecordScalar(call_id, "timeoutInMs", timeoutInMs);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, port, timeoutInMs);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXThreadingImpl_slot17_XTaskQueueCloseHandle(void *self, XTaskQueueHandle queue)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XTaskQueueHandle queue)>(trace::OriginalSlot(self, 17));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 17, "XTaskQueueCloseHandle", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, queue);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot18_XTaskQueueSubmitCallback(void *self, XTaskQueueHandle queue, XTaskQueuePort port, void * callbackContext, XTaskQueueCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, XTaskQueuePort port, void * callbackContext, XTaskQueueCallback * callback)>(trace::OriginalSlot(self, 18));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 18, "XTaskQueueSubmitCallback", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordScalar(call_id, "port", port);
        trace::RecordPointer(call_id, "callbackContext", reinterpret_cast<const void *>(callbackContext), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, port, callbackContext, trace::WrapCallback<XTaskQueueCallback>(call_id, "XTaskQueueCallback", callback, reinterpret_cast<const void *>(callbackContext), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XTaskQueueCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot19_XTaskQueueSubmitDelayedCallback(void *self, XTaskQueueHandle queue, XTaskQueuePort port, UINT32 delayMs, void * callbackContext, XTaskQueueCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, XTaskQueuePort port, UINT32 delayMs, void * callbackContext, XTaskQueueCallback * callback)>(trace::OriginalSlot(self, 19));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 19, "XTaskQueueSubmitDelayedCallback", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordScalar(call_id, "port", port);
        trace::RecordScalar(call_id, "delayMs", delayMs);
        trace::RecordPointer(call_id, "callbackContext", reinterpret_cast<const void *>(callbackContext), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, port, delayMs, callbackContext, trace::WrapCallback<XTaskQueueCallback>(call_id, "XTaskQueueCallback", callback, reinterpret_cast<const void *>(callbackContext), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XTaskQueueCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot20_XTaskQueueRegisterWaiter(void *self, XTaskQueueHandle queue, XTaskQueuePort port, HANDLE waitHandle, void * callbackContext, XTaskQueueCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, XTaskQueuePort port, HANDLE waitHandle, void * callbackContext, XTaskQueueCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 20));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 20, "XTaskQueueRegisterWaiter", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordScalar(call_id, "port", port);
        trace::RecordHandleArgumentValue(call_id, "waitHandle", waitHandle, "HANDLE");
        trace::RecordPointer(call_id, "callbackContext", reinterpret_cast<const void *>(callbackContext), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken *");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, port, waitHandle, callbackContext, trace::WrapCallback<XTaskQueueCallback>(call_id, "XTaskQueueCallback", callback, reinterpret_cast<const void *>(callbackContext), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XTaskQueueCallback), token);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXThreadingImpl_slot21_XTaskQueueUnregisterWaiter(void *self, XTaskQueueHandle queue, XTaskQueueRegistrationToken token)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XTaskQueueHandle queue, XTaskQueueRegistrationToken token)>(trace::OriginalSlot(self, 21));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 21, "XTaskQueueUnregisterWaiter", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, queue, token);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), true);
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot22_XTaskQueueTerminate(void *self, XTaskQueueHandle queue, BOOLEAN wait, void * callbackContext, XTaskQueueTerminatedCallback * callback)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, BOOLEAN wait, void * callbackContext, XTaskQueueTerminatedCallback * callback)>(trace::OriginalSlot(self, 22));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 22, "XTaskQueueTerminate", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordScalar(call_id, "wait", wait);
        trace::RecordPointer(call_id, "callbackContext", reinterpret_cast<const void *>(callbackContext), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, wait, callbackContext, trace::WrapCallback<XTaskQueueTerminatedCallback>(call_id, "XTaskQueueTerminatedCallback", callback, reinterpret_cast<const void *>(callbackContext), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XTaskQueueTerminatedCallback));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot23_XTaskQueueRegisterMonitor(void *self, XTaskQueueHandle queue, void * callbackContext, XTaskQueueMonitorCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * callbackContext, XTaskQueueMonitorCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 23));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 23, "XTaskQueueRegisterMonitor", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "callbackContext", reinterpret_cast<const void *>(callbackContext), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, callbackContext, trace::WrapCallback<XTaskQueueMonitorCallback>(call_id, "XTaskQueueMonitorCallback", callback, reinterpret_cast<const void *>(callbackContext), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XTaskQueueMonitorCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXThreadingImpl_slot24_XTaskQueueUnregisterMonitor(void *self, XTaskQueueHandle queue, XTaskQueueRegistrationToken token)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XTaskQueueHandle queue, XTaskQueueRegistrationToken token)>(trace::OriginalSlot(self, 24));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 24, "XTaskQueueUnregisterMonitor", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, queue, token);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), true);
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

BOOLEAN WINAPI xgrtrace_wrap_IXThreadingImpl_slot25_XTaskQueueGetCurrentProcessTaskQueue(void *self, XTaskQueueHandle * queue)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueHandle * queue)>(trace::OriginalSlot(self, 25));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 25, "XTaskQueueGetCurrentProcessTaskQueue", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "queue", reinterpret_cast<const void *>(queue), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue);
    try {
        trace::RecordOutputHandleObject(call_id, "queue", queue, "XTaskQueueHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXThreadingImpl_slot26_XTaskQueueSetCurrentProcessTaskQueue(void *self, XTaskQueueHandle queue)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XTaskQueueHandle queue)>(trace::OriginalSlot(self, 26));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 26, "XTaskQueueSetCurrentProcessTaskQueue", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, queue);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXThreadingImpl_slot27_XThreadSetTimeSensitive(void *self, BOOLEAN isTimeSensitiveThread)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, BOOLEAN isTimeSensitiveThread)>(trace::OriginalSlot(self, 27));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 27, "XThreadSetTimeSensitive", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "isTimeSensitiveThread", isTimeSensitiveThread);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, isTimeSensitiveThread);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXThreadingImpl_slot29_XThreadAssertNotTimeSensitive(void *self)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self)>(trace::OriginalSlot(self, 29));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 29, "XThreadAssertNotTimeSensitive", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

BOOLEAN WINAPI xgrtrace_wrap_IXThreadingImpl_slot30_XThreadIsTimeSensitive(void *self)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self)>(trace::OriginalSlot(self, 30));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("073b7dcb-1fcf-4030-94be-e3c9eb623428", 30, "XThreadIsTimeSensitive", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserDeviceImpl_slot3_XUserFindForDevice(void *self, const APP_LOCAL_DEVICE_ID * deviceId, XUserHandle * handle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, const APP_LOCAL_DEVICE_ID * deviceId, XUserHandle * handle)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("7d824997-10dc-45ab-86b7-2737767c0bf1", 3, "XUserFindForDevice", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "deviceId", reinterpret_cast<const void *>(deviceId), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "handle", reinterpret_cast<const void *>(handle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, deviceId, handle);
    try {
        trace::RecordOutputHandleObject(call_id, "handle", handle, "XUserHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserDeviceImpl_slot4_XUserRegisterForDeviceAssociationChanged(void *self, XTaskQueueHandle queue, void * context, XUserDeviceAssociationChangedCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XUserDeviceAssociationChangedCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("7d824997-10dc-45ab-86b7-2737767c0bf1", 4, "XUserRegisterForDeviceAssociationChanged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XUserDeviceAssociationChangedCallback>(call_id, "XUserDeviceAssociationChangedCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XUserDeviceAssociationChangedCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXUserDeviceImpl_slot5_XUserUnregisterForDeviceAssociationChanged(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("7d824997-10dc-45ab-86b7-2737767c0bf1", 5, "XUserUnregisterForDeviceAssociationChanged", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserDeviceImpl_slot6_XUserGetDefaultAudioEndpointUtf16(void *self, XUserLocalId user, XUserDefaultAudioEndpointKind defaultAudioEndpointKind, SIZE_T endpointIdUtf16Count, WCHAR * endpointIdUtf16, SIZE_T * endpointIdUtf16Used)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserLocalId user, XUserDefaultAudioEndpointKind defaultAudioEndpointKind, SIZE_T endpointIdUtf16Count, WCHAR * endpointIdUtf16, SIZE_T * endpointIdUtf16Used)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("7d824997-10dc-45ab-86b7-2737767c0bf1", 6, "XUserGetDefaultAudioEndpointUtf16", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "user", user);
        trace::RecordScalar(call_id, "defaultAudioEndpointKind", defaultAudioEndpointKind);
        trace::RecordScalar(call_id, "endpointIdUtf16Count", endpointIdUtf16Count);
        trace::RecordPointer(call_id, "endpointIdUtf16", reinterpret_cast<const void *>(endpointIdUtf16), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "endpointIdUtf16Used", reinterpret_cast<const void *>(endpointIdUtf16Used), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, defaultAudioEndpointKind, endpointIdUtf16Count, endpointIdUtf16, endpointIdUtf16Used);
    try {
        trace::RecordOutputBuffer(call_id, "endpointIdUtf16", reinterpret_cast<const void *>(endpointIdUtf16), (static_cast<std::size_t>(endpointIdUtf16Count)) * sizeof(*endpointIdUtf16), reinterpret_cast<const void *>(endpointIdUtf16Used), sizeof(*endpointIdUtf16Used), sizeof(*endpointIdUtf16), "WCHAR *", trace::OutputEncoding::Utf16, false);
        trace::RecordOutputObject(call_id, "endpointIdUtf16Used", endpointIdUtf16Used, "SIZE_T *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserDeviceImpl_slot7_XUserRegisterForDefaultAudioEndpointUtf16Changed(void *self, XTaskQueueHandle queue, void * context, XUserDefaultAudioEndpointUtf16ChangedCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XUserDefaultAudioEndpointUtf16ChangedCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("7d824997-10dc-45ab-86b7-2737767c0bf1", 7, "XUserRegisterForDefaultAudioEndpointUtf16Changed", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XUserDefaultAudioEndpointUtf16ChangedCallback>(call_id, "XUserDefaultAudioEndpointUtf16ChangedCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XUserDefaultAudioEndpointUtf16ChangedCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXUserDeviceImpl_slot8_XUserUnregisterForDefaultAudioEndpointUtf16Changed(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 8));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("7d824997-10dc-45ab-86b7-2737767c0bf1", 8, "XUserUnregisterForDefaultAudioEndpointUtf16Changed", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserDeviceImpl_slot9_XUserFindControllerForUserWithUiAsync(void *self, XUserHandle user, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, XAsyncBlock * async)>(trace::OriginalSlot(self, 9));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("7d824997-10dc-45ab-86b7-2737767c0bf1", 9, "XUserFindControllerForUserWithUiAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserDeviceImpl_slot10_XUserFindControllerForUserWithUiResult(void *self, XAsyncBlock * async, APP_LOCAL_DEVICE_ID * deviceId)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, APP_LOCAL_DEVICE_ID * deviceId)>(trace::OriginalSlot(self, 10));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("7d824997-10dc-45ab-86b7-2737767c0bf1", 10, "XUserFindControllerForUserWithUiResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "deviceId", reinterpret_cast<const void *>(deviceId), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, deviceId);
    try {
        trace::RecordOutputObject(call_id, "deviceId", deviceId, "APP_LOCAL_DEVICE_ID *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserGamertagImpl_slot3_XUserGetGamertag(void *self, XUserHandle user, XUserGamertagComponent gamertagComponent, SIZE_T gamertagSize, char * gamertag, SIZE_T * gamertagUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, XUserGamertagComponent gamertagComponent, SIZE_T gamertagSize, char * gamertag, SIZE_T * gamertagUsed)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("cef4fac0-7676-4a94-a119-4c43f9eb5b74", 3, "XUserGetGamertag", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordScalar(call_id, "gamertagComponent", gamertagComponent);
        trace::RecordScalar(call_id, "gamertagSize", gamertagSize);
        trace::RecordPointer(call_id, "gamertag", reinterpret_cast<const void *>(gamertag), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "gamertagUsed", reinterpret_cast<const void *>(gamertagUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, gamertagComponent, gamertagSize, gamertag, gamertagUsed);
    try {
        trace::RecordOutputBuffer(call_id, "gamertag", reinterpret_cast<const void *>(gamertag), (static_cast<std::size_t>(gamertagSize)) * sizeof(*gamertag), reinterpret_cast<const void *>(gamertagUsed), sizeof(*gamertagUsed), sizeof(*gamertag), "char *", trace::OutputEncoding::Ansi, false);
        trace::RecordOutputObject(call_id, "gamertagUsed", gamertagUsed, "SIZE_T *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot3_XUserDuplicateHandle(void *self, XUserHandle handle, XUserHandle * duplicatedHandle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle handle, XUserHandle * duplicatedHandle)>(trace::OriginalSlot(self, 3));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 3, "XUserDuplicateHandle", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "handle", handle, "XUserHandle");
        trace::RecordPointer(call_id, "duplicatedHandle", reinterpret_cast<const void *>(duplicatedHandle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, handle, duplicatedHandle);
    try {
        trace::RecordOutputHandleObject(call_id, "duplicatedHandle", duplicatedHandle, "XUserHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXUserImpl_slot4_XUserCloseHandle(void *self, XUserHandle user)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XUserHandle user)>(trace::OriginalSlot(self, 4));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 4, "XUserCloseHandle", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, user);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

INT32 WINAPI xgrtrace_wrap_IXUserImpl_slot5_XUserCompare(void *self, XUserHandle user1, XUserHandle user2)
{
    auto original = reinterpret_cast<INT32 (WINAPI *)(void *self, XUserHandle user1, XUserHandle user2)>(trace::OriginalSlot(self, 5));
    if (!original) {
        return {};
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 5, "XUserCompare", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user1", user1, "XUserHandle");
        trace::RecordHandleArgumentValue(call_id, "user2", user2, "XUserHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user1, user2);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot6_XUserGetMaxUsers(void *self, UINT32 * maxUsers)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, UINT32 * maxUsers)>(trace::OriginalSlot(self, 6));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 6, "XUserGetMaxUsers", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "maxUsers", reinterpret_cast<const void *>(maxUsers), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, maxUsers);
    try {
        trace::RecordOutputObject(call_id, "maxUsers", maxUsers, "UINT32 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot7_XUserAddAsync(void *self, XUserAddOptions options, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserAddOptions options, XAsyncBlock * async)>(trace::OriginalSlot(self, 7));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 7, "XUserAddAsync", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "options", options);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, options, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot8_XUserAddResult(void *self, XAsyncBlock * async, XUserHandle * newUser)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XUserHandle * newUser)>(trace::OriginalSlot(self, 8));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 8, "XUserAddResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "newUser", reinterpret_cast<const void *>(newUser), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, newUser);
    try {
        trace::RecordOutputHandleObject(call_id, "newUser", newUser, "XUserHandle *");
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot9_XUserGetLocalId(void *self, XUserHandle user, XUserLocalId * userLocalId)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, XUserLocalId * userLocalId)>(trace::OriginalSlot(self, 9));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 9, "XUserGetLocalId", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordPointer(call_id, "userLocalId", reinterpret_cast<const void *>(userLocalId), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, userLocalId);
    try {
        trace::RecordOutputObject(call_id, "userLocalId", userLocalId, "XUserLocalId *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot10_XUserFindUserByLocalId(void *self, XUserLocalId userLocalId, XUserHandle * handle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserLocalId userLocalId, XUserHandle * handle)>(trace::OriginalSlot(self, 10));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 10, "XUserFindUserByLocalId", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "userLocalId", userLocalId);
        trace::RecordPointer(call_id, "handle", reinterpret_cast<const void *>(handle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, userLocalId, handle);
    try {
        trace::RecordOutputHandleObject(call_id, "handle", handle, "XUserHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot11_XUserGetId(void *self, XUserHandle user, UINT64 * userId)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, UINT64 * userId)>(trace::OriginalSlot(self, 11));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 11, "XUserGetId", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordPointer(call_id, "userId", reinterpret_cast<const void *>(userId), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, userId);
    try {
        trace::RecordOutputObject(call_id, "userId", userId, "UINT64 *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot12_XUserFindUserById(void *self, UINT64 userId, XUserHandle * handle)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, UINT64 userId, XUserHandle * handle)>(trace::OriginalSlot(self, 12));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 12, "XUserFindUserById", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "userId", userId);
        trace::RecordPointer(call_id, "handle", reinterpret_cast<const void *>(handle), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, userId, handle);
    try {
        trace::RecordOutputHandleObject(call_id, "handle", handle, "XUserHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot13_XUserGetIsGuest(void *self, XUserHandle user, BOOLEAN * isGuest)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, BOOLEAN * isGuest)>(trace::OriginalSlot(self, 13));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 13, "XUserGetIsGuest", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordPointer(call_id, "isGuest", reinterpret_cast<const void *>(isGuest), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, isGuest);
    try {
        trace::RecordOutputObject(call_id, "isGuest", isGuest, "BOOLEAN *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot14_XUserGetState(void *self, XUserHandle user, XUserState * state)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, XUserState * state)>(trace::OriginalSlot(self, 14));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 14, "XUserGetState", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordPointer(call_id, "state", reinterpret_cast<const void *>(state), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, state);
    try {
        trace::RecordOutputObject(call_id, "state", state, "XUserState *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot16_XUserGetGamerPictureAsync(void *self, XUserHandle user, XUserGamerPictureSize pictureSize, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, XUserGamerPictureSize pictureSize, XAsyncBlock * async)>(trace::OriginalSlot(self, 16));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 16, "XUserGetGamerPictureAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordScalar(call_id, "pictureSize", pictureSize);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, pictureSize, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot17_XUserGetGamerPictureResultSize(void *self, XAsyncBlock * async, SIZE_T * bufferSize)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T * bufferSize)>(trace::OriginalSlot(self, 17));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 17, "XUserGetGamerPictureResultSize", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "bufferSize", reinterpret_cast<const void *>(bufferSize), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, bufferSize);
    try {
        trace::RecordOutputObject(call_id, "bufferSize", bufferSize, "SIZE_T *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot18_XUserGetGamerPictureResult(void *self, XAsyncBlock * async, SIZE_T bufferSize, void * buffer, SIZE_T * bufferUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T bufferSize, void * buffer, SIZE_T * bufferUsed)>(trace::OriginalSlot(self, 18));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 18, "XUserGetGamerPictureResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "bufferSize", bufferSize);
        trace::RecordPointer(call_id, "buffer", reinterpret_cast<const void *>(buffer), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "bufferUsed", reinterpret_cast<const void *>(bufferUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, bufferSize, buffer, bufferUsed);
    try {
        trace::RecordOutputBuffer(call_id, "buffer", reinterpret_cast<const void *>(buffer), (static_cast<std::size_t>(bufferSize)) * 1, reinterpret_cast<const void *>(bufferUsed), sizeof(*bufferUsed), 1, "void *", trace::OutputEncoding::Binary, false);
        trace::RecordOutputObject(call_id, "bufferUsed", bufferUsed, "SIZE_T *", false);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot19_XUserGetAgeGroup(void *self, XUserHandle user, XUserAgeGroup * ageGroup)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, XUserAgeGroup * ageGroup)>(trace::OriginalSlot(self, 19));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 19, "XUserGetAgeGroup", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordPointer(call_id, "ageGroup", reinterpret_cast<const void *>(ageGroup), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, ageGroup);
    try {
        trace::RecordOutputObject(call_id, "ageGroup", ageGroup, "XUserAgeGroup *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot20_XUserCheckPrivilege(void *self, XUserHandle user, XUserPrivilegeOptions options, XUserPrivilege privilege, BOOLEAN * hasPrivilege, XUserPrivilegeDenyReason * reason)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, XUserPrivilegeOptions options, XUserPrivilege privilege, BOOLEAN * hasPrivilege, XUserPrivilegeDenyReason * reason)>(trace::OriginalSlot(self, 20));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 20, "XUserCheckPrivilege", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordScalar(call_id, "options", options);
        trace::RecordScalar(call_id, "privilege", privilege);
        trace::RecordPointer(call_id, "hasPrivilege", reinterpret_cast<const void *>(hasPrivilege), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "reason", reinterpret_cast<const void *>(reason), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, options, privilege, hasPrivilege, reason);
    try {
        trace::RecordOutputObject(call_id, "hasPrivilege", hasPrivilege, "BOOLEAN *", false);
        trace::RecordOutputObject(call_id, "reason", reason, "XUserPrivilegeDenyReason *", false);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot21_XUserResolvePrivilegeWithUiAsync(void *self, XUserHandle user, XUserPrivilegeOptions options, XUserPrivilege privilege, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, XUserPrivilegeOptions options, XUserPrivilege privilege, XAsyncBlock * async)>(trace::OriginalSlot(self, 21));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 21, "XUserResolvePrivilegeWithUiAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordScalar(call_id, "options", options);
        trace::RecordScalar(call_id, "privilege", privilege);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, options, privilege, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot22_XUserResolvePrivilegeWithUiResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 22));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 22, "XUserResolvePrivilegeWithUiResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot23_XUserGetTokenAndSignatureAsync(void *self, XUserHandle user, XUserGetTokenAndSignatureOptions options, const char * method, const char * url, SIZE_T headerCount, const XUserGetTokenAndSignatureHttpHeader * headers, SIZE_T bodySize, const void * bodyBuffer, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, XUserGetTokenAndSignatureOptions options, const char * method, const char * url, SIZE_T headerCount, const XUserGetTokenAndSignatureHttpHeader * headers, SIZE_T bodySize, const void * bodyBuffer, XAsyncBlock * async)>(trace::OriginalSlot(self, 23));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 23, "XUserGetTokenAndSignatureAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordScalar(call_id, "options", options);
        trace::RecordInputString(call_id, "method", method, trace::ArgumentKind::StringSensitive);
        trace::RecordInputString(call_id, "url", url, trace::ArgumentKind::StringSensitive);
        trace::RecordScalar(call_id, "headerCount", headerCount);
        trace::RecordInputBuffer(call_id, "headers", reinterpret_cast<const void *>(headers), (static_cast<std::size_t>(headerCount)) * sizeof(*headers), "const XUserGetTokenAndSignatureHttpHeader *", true);
        trace::RecordScalar(call_id, "bodySize", bodySize);
        trace::RecordInputBuffer(call_id, "bodyBuffer", reinterpret_cast<const void *>(bodyBuffer), static_cast<std::size_t>(bodySize), "const void *", true);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, options, method, url, headerCount, headers, bodySize, bodyBuffer, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot24_XUserGetTokenAndSignatureResultSize(void *self, XAsyncBlock * async, SIZE_T * bufferSize)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T * bufferSize)>(trace::OriginalSlot(self, 24));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 24, "XUserGetTokenAndSignatureResultSize", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "bufferSize", reinterpret_cast<const void *>(bufferSize), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, bufferSize);
    try {
        trace::RecordOutputObject(call_id, "bufferSize", bufferSize, "SIZE_T *", true);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot25_XUserGetTokenAndSignatureResult(void *self, XAsyncBlock * async, SIZE_T bufferSize, void * buffer, XUserGetTokenAndSignatureData ** ptrToBuffer, SIZE_T * bufferUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T bufferSize, void * buffer, XUserGetTokenAndSignatureData ** ptrToBuffer, SIZE_T * bufferUsed)>(trace::OriginalSlot(self, 25));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 25, "XUserGetTokenAndSignatureResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "bufferSize", bufferSize);
        trace::RecordPointer(call_id, "buffer", reinterpret_cast<const void *>(buffer), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "ptrToBuffer", reinterpret_cast<const void *>(ptrToBuffer), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "bufferUsed", reinterpret_cast<const void *>(bufferUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, bufferSize, buffer, ptrToBuffer, bufferUsed);
    try {
        trace::RecordOutputBuffer(call_id, "buffer", reinterpret_cast<const void *>(buffer), (static_cast<std::size_t>(bufferSize)) * 1, reinterpret_cast<const void *>(bufferUsed), sizeof(*bufferUsed), 1, "void *", trace::OutputEncoding::Binary, true);
        trace::RecordOutputPointeeValue(call_id, "ptrToBuffer", reinterpret_cast<const void *>(ptrToBuffer), sizeof(*ptrToBuffer), sizeof(**ptrToBuffer), "XUserGetTokenAndSignatureData **", true);
        trace::RecordOutputObject(call_id, "bufferUsed", bufferUsed, "SIZE_T *", true);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot26_XUserGetTokenAndSignatureUtf16Async(void *self, XUserHandle user, XUserGetTokenAndSignatureOptions options, const WCHAR * method, const WCHAR * url, SIZE_T headerCount, const XUserGetTokenAndSignatureUtf16HttpHeader * headers, SIZE_T bodySize, const void * bodyBuffer, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, XUserGetTokenAndSignatureOptions options, const WCHAR * method, const WCHAR * url, SIZE_T headerCount, const XUserGetTokenAndSignatureUtf16HttpHeader * headers, SIZE_T bodySize, const void * bodyBuffer, XAsyncBlock * async)>(trace::OriginalSlot(self, 26));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 26, "XUserGetTokenAndSignatureUtf16Async", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordScalar(call_id, "options", options);
        trace::RecordInputString(call_id, "method", method, trace::ArgumentKind::StringSensitive);
        trace::RecordInputString(call_id, "url", url, trace::ArgumentKind::StringSensitive);
        trace::RecordScalar(call_id, "headerCount", headerCount);
        trace::RecordInputBuffer(call_id, "headers", reinterpret_cast<const void *>(headers), (static_cast<std::size_t>(headerCount)) * sizeof(*headers), "const XUserGetTokenAndSignatureUtf16HttpHeader *", true);
        trace::RecordScalar(call_id, "bodySize", bodySize);
        trace::RecordInputBuffer(call_id, "bodyBuffer", reinterpret_cast<const void *>(bodyBuffer), static_cast<std::size_t>(bodySize), "const void *", true);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, options, method, url, headerCount, headers, bodySize, bodyBuffer, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot27_XUserGetTokenAndSignatureUtf16ResultSize(void *self, XAsyncBlock * async, SIZE_T * bufferSize)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T * bufferSize)>(trace::OriginalSlot(self, 27));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 27, "XUserGetTokenAndSignatureUtf16ResultSize", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "bufferSize", reinterpret_cast<const void *>(bufferSize), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, bufferSize);
    try {
        trace::RecordOutputObject(call_id, "bufferSize", bufferSize, "SIZE_T *", true);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot28_XUserGetTokenAndSignatureUtf16Result(void *self, XAsyncBlock * async, SIZE_T bufferSize, void * buffer, XUserGetTokenAndSignatureUtf16Data ** ptrToBuffer, SIZE_T * bufferUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T bufferSize, void * buffer, XUserGetTokenAndSignatureUtf16Data ** ptrToBuffer, SIZE_T * bufferUsed)>(trace::OriginalSlot(self, 28));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 28, "XUserGetTokenAndSignatureUtf16Result", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "bufferSize", bufferSize);
        trace::RecordPointer(call_id, "buffer", reinterpret_cast<const void *>(buffer), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "ptrToBuffer", reinterpret_cast<const void *>(ptrToBuffer), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "bufferUsed", reinterpret_cast<const void *>(bufferUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, bufferSize, buffer, ptrToBuffer, bufferUsed);
    try {
        trace::RecordOutputBuffer(call_id, "buffer", reinterpret_cast<const void *>(buffer), (static_cast<std::size_t>(bufferSize)) * 1, reinterpret_cast<const void *>(bufferUsed), sizeof(*bufferUsed), 1, "void *", trace::OutputEncoding::Binary, true);
        trace::RecordOutputPointeeValue(call_id, "ptrToBuffer", reinterpret_cast<const void *>(ptrToBuffer), sizeof(*ptrToBuffer), sizeof(**ptrToBuffer), "XUserGetTokenAndSignatureUtf16Data **", true);
        trace::RecordOutputObject(call_id, "bufferUsed", bufferUsed, "SIZE_T *", true);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot29_XUserResolveIssueWithUiAsync(void *self, XUserHandle user, const char * url, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, const char * url, XAsyncBlock * async)>(trace::OriginalSlot(self, 29));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 29, "XUserResolveIssueWithUiAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordInputString(call_id, "url", url, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, url, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot30_XUserResolveIssueWithUiResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 30));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 30, "XUserResolveIssueWithUiResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot31_XUserResolveIssueWithUiUtf16Async(void *self, XUserHandle user, const WCHAR * url, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, const WCHAR * url, XAsyncBlock * async)>(trace::OriginalSlot(self, 31));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 31, "XUserResolveIssueWithUiUtf16Async", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordInputString(call_id, "url", url, trace::ArgumentKind::String);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, url, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot32_XUserResolveIssueWithUiUtf16Result(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 32));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 32, "XUserResolveIssueWithUiUtf16Result", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot33_XUserRegisterForChangeEvent(void *self, XTaskQueueHandle queue, void * context, XUserChangeEventCallback * callback, XTaskQueueRegistrationToken * token)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, void * context, XUserChangeEventCallback * callback, XTaskQueueRegistrationToken * token)>(trace::OriginalSlot(self, 33));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 33, "XUserRegisterForChangeEvent", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "callback", reinterpret_cast<const void *>(callback), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "token", reinterpret_cast<const void *>(token), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, context, trace::WrapCallback<XUserChangeEventCallback>(call_id, "XUserChangeEventCallback", callback, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XUserChangeEventCallback), token);
    try {
        trace::RecordOutputHandleObject(call_id, "token", token, "XTaskQueueRegistrationToken *");
        trace::RecordCallbackToken(call_id, reinterpret_cast<const void *>(token), sizeof(*token));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXUserImpl_slot34_XUserUnregisterForChangeEvent(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XTaskQueueRegistrationToken token, BOOLEAN wait)>(trace::OriginalSlot(self, 34));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 34, "XUserUnregisterForChangeEvent", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "token", token, "XTaskQueueRegistrationToken");
        trace::RecordScalar(call_id, "wait", wait);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, token, wait);
    try {
        trace::UnregisterCallback(call_id, reinterpret_cast<const void *>(&token), sizeof(token), static_cast<bool>(call_result));
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl_slot35_XUserGetSignOutDeferral(void *self, XUserSignOutDeferralHandle * deferral)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserSignOutDeferralHandle * deferral)>(trace::OriginalSlot(self, 35));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 35, "XUserGetSignOutDeferral", reinterpret_cast<const void *>(self));
        trace::RecordPointer(call_id, "deferral", reinterpret_cast<const void *>(deferral), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, deferral);
    try {
        trace::RecordOutputHandleObject(call_id, "deferral", deferral, "XUserSignOutDeferralHandle *");
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

void WINAPI xgrtrace_wrap_IXUserImpl_slot36_XUserCloseSignOutDeferralHandle(void *self, XUserSignOutDeferralHandle deferral)
{
    auto original = reinterpret_cast<void (WINAPI *)(void *self, XUserSignOutDeferralHandle deferral)>(trace::OriginalSlot(self, 36));
    if (!original) {
        return;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("01acd177-91f9-4763-a38e-ccbb55ce32e0", 36, "XUserCloseSignOutDeferralHandle", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "deferral", deferral, "XUserSignOutDeferralHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    original(self, deferral);
    try {
        trace::EndCallVoid(call_id);
    } catch (...) {
    }
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl2_slot37_XUserAddByIdWithUiAsync(void *self, UINT64 userId, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, UINT64 userId, XAsyncBlock * async)>(trace::OriginalSlot(self, 37));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("eb9bf948-18dc-4d82-bbcc-40e0a809c4c0", 37, "XUserAddByIdWithUiAsync", reinterpret_cast<const void *>(self));
        trace::RecordScalar(call_id, "userId", userId);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, userId, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl2_slot38_XUserAddByIdWithUiResult(void *self, XAsyncBlock * async, XUserHandle * newUser)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, XUserHandle * newUser)>(trace::OriginalSlot(self, 38));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("eb9bf948-18dc-4d82-bbcc-40e0a809c4c0", 38, "XUserAddByIdWithUiResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "newUser", reinterpret_cast<const void *>(newUser), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, newUser);
    try {
        trace::RecordOutputHandleObject(call_id, "newUser", newUser, "XUserHandle *");
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl3_slot39_XUserGetMsaTokenSilentlyAsync(void *self, XUserHandle user, XUserGetMsaTokenSilentlyOptions options, const char * scope, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, XUserGetMsaTokenSilentlyOptions options, const char * scope, XAsyncBlock * async)>(trace::OriginalSlot(self, 39));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("1bf2f8c5-d507-4e52-bb05-f726d0e71161", 39, "XUserGetMsaTokenSilentlyAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordScalar(call_id, "options", options);
        trace::RecordInputString(call_id, "scope", scope, trace::ArgumentKind::StringSensitive);
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, options, scope, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl3_slot40_XUserGetMsaTokenSilentlyResult(void *self, XAsyncBlock * async, SIZE_T resultTokenSize, char * resultToken, SIZE_T * resultTokenUsed)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T resultTokenSize, char * resultToken, SIZE_T * resultTokenUsed)>(trace::OriginalSlot(self, 40));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("1bf2f8c5-d507-4e52-bb05-f726d0e71161", 40, "XUserGetMsaTokenSilentlyResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordScalar(call_id, "resultTokenSize", resultTokenSize);
        trace::RecordPointer(call_id, "resultToken", reinterpret_cast<const void *>(resultToken), trace::ArgumentKind::Out);
        trace::RecordPointer(call_id, "resultTokenUsed", reinterpret_cast<const void *>(resultTokenUsed), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, resultTokenSize, resultToken, resultTokenUsed);
    try {
        trace::RecordOutputBuffer(call_id, "resultToken", reinterpret_cast<const void *>(resultToken), (static_cast<std::size_t>(resultTokenSize)) * sizeof(*resultToken), reinterpret_cast<const void *>(resultTokenUsed), sizeof(*resultTokenUsed), sizeof(*resultToken), "char *", trace::OutputEncoding::Ansi, true);
        trace::RecordOutputObject(call_id, "resultTokenUsed", resultTokenUsed, "SIZE_T *", true);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl3_slot41_XUserGetMsaTokenSilentlyResultSize(void *self, XAsyncBlock * async, SIZE_T * tokenSize)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async, SIZE_T * tokenSize)>(trace::OriginalSlot(self, 41));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("1bf2f8c5-d507-4e52-bb05-f726d0e71161", 41, "XUserGetMsaTokenSilentlyResultSize", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
        trace::RecordPointer(call_id, "tokenSize", reinterpret_cast<const void *>(tokenSize), trace::ArgumentKind::Out);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async, tokenSize);
    try {
        trace::RecordOutputObject(call_id, "tokenSize", tokenSize, "SIZE_T *", true);
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXUserImpl4_slot42_XUserIsStoreUser(void *self, XUserHandle user)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self, XUserHandle user)>(trace::OriginalSlot(self, 42));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("079415e3-6727-437f-8e9d-8f8f9b2439f7", 42, "XUserIsStoreUser", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl5_slot43_XUserPlatformRemoteConnectSetEventHandlers(void *self, XTaskQueueHandle queue, XUserPlatformRemoteConnectEventHandlers * handlers)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, XUserPlatformRemoteConnectEventHandlers * handlers)>(trace::OriginalSlot(self, 43));
    if (!original) {
        return E_FAIL;
    }
    XUserPlatformRemoteConnectEventHandlers handlers_callback_copy{};
    bool handlers_callback_copy_valid = false;
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("26f3c674-a2fe-44fa-b6c4-a323bc94ff53", 43, "XUserPlatformRemoteConnectSetEventHandlers", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "handlers", reinterpret_cast<const void *>(handlers), trace::ArgumentKind::Pointer);
        handlers_callback_copy_valid = trace::CopyFromTarget(handlers, &handlers_callback_copy);
        if (handlers_callback_copy_valid) {
            handlers_callback_copy.show = trace::WrapCallback<XUserPlatformRemoteConnectShowPromptEventHandler>(call_id, "XUserPlatformRemoteConnectShowPromptEventHandler", handlers_callback_copy.show, reinterpret_cast<const void *>(handlers_callback_copy.context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XUserPlatformRemoteConnectShowPromptEventHandler);
            handlers_callback_copy.close = trace::WrapCallback<XUserPlatformRemoteConnectClosePromptEventHandler>(call_id, "XUserPlatformRemoteConnectClosePromptEventHandler", handlers_callback_copy.close, reinterpret_cast<const void *>(handlers_callback_copy.context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XUserPlatformRemoteConnectClosePromptEventHandler);
        }
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, (handlers_callback_copy_valid ? &handlers_callback_copy : handlers));
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl5_slot44_XUserPlatformRemoteConnectCancelPrompt(void *self, XUserPlatformOperation operation)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserPlatformOperation operation)>(trace::OriginalSlot(self, 44));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("26f3c674-a2fe-44fa-b6c4-a323bc94ff53", 44, "XUserPlatformRemoteConnectCancelPrompt", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "operation", operation, "XUserPlatformOperation");
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, operation);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl5_slot45_XUserPlatformSpopPromptSetEventHandlers(void *self, XTaskQueueHandle queue, XUserPlatformSpopPromptEventHandler * handler, void * context)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XTaskQueueHandle queue, XUserPlatformSpopPromptEventHandler * handler, void * context)>(trace::OriginalSlot(self, 45));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("26f3c674-a2fe-44fa-b6c4-a323bc94ff53", 45, "XUserPlatformSpopPromptSetEventHandlers", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "queue", queue, "XTaskQueueHandle");
        trace::RecordPointer(call_id, "handler", reinterpret_cast<const void *>(handler), trace::ArgumentKind::Pointer);
        trace::RecordPointer(call_id, "context", reinterpret_cast<const void *>(context), trace::ArgumentKind::Pointer);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, queue, trace::WrapCallback<XUserPlatformSpopPromptEventHandler>(call_id, "XUserPlatformSpopPromptEventHandler", handler, reinterpret_cast<const void *>(context), reinterpret_cast<const void *>(queue), &xgrtrace_callback_XUserPlatformSpopPromptEventHandler), context);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl5_slot46_XUserPlatformSpopPromptComplete(void *self, XUserPlatformOperation operation, XUserPlatformOperationResult result)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserPlatformOperation operation, XUserPlatformOperationResult result)>(trace::OriginalSlot(self, 46));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("26f3c674-a2fe-44fa-b6c4-a323bc94ff53", 46, "XUserPlatformSpopPromptComplete", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "operation", operation, "XUserPlatformOperation");
        trace::RecordScalar(call_id, "result", result);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, operation, result);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

BOOLEAN WINAPI xgrtrace_wrap_IXUserImpl6_slot47_XUserIsSignOutPresent(void *self)
{
    auto original = reinterpret_cast<BOOLEAN (WINAPI *)(void *self)>(trace::OriginalSlot(self, 47));
    if (!original) {
        return FALSE;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("5131d685-4394-4ee6-8c18-bfb5d4aef1ff", 47, "XUserIsSignOutPresent", reinterpret_cast<const void *>(self));
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self);
    try {
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl6_slot48_XUserSignOutAsync(void *self, XUserHandle user, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XUserHandle user, XAsyncBlock * async)>(trace::OriginalSlot(self, 48));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("5131d685-4394-4ee6-8c18-bfb5d4aef1ff", 48, "XUserSignOutAsync", reinterpret_cast<const void *>(self));
        trace::RecordHandleArgumentValue(call_id, "user", user, "XUserHandle");
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, user, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

HRESULT WINAPI xgrtrace_wrap_IXUserImpl6_slot49_XUserSignOutResult(void *self, XAsyncBlock * async)
{
    auto original = reinterpret_cast<HRESULT (WINAPI *)(void *self, XAsyncBlock * async)>(trace::OriginalSlot(self, 49));
    if (!original) {
        return E_FAIL;
    }
    std::uint64_t call_id = 0;
    try {
        call_id = trace::BeginCall("5131d685-4394-4ee6-8c18-bfb5d4aef1ff", 49, "XUserSignOutResult", reinterpret_cast<const void *>(self));
        trace::RecordAsyncBlock(call_id, "async", async);
    } catch (...) {
        // Tracing must never prevent the real ABI call.
    }
    auto call_result = original(self, async);
    try {
        trace::RecordAsyncCallEnd(call_id, async, call_result, true);
        trace::EndCall(call_id, call_result);
    } catch (...) {
    }
    return call_result;
}

struct WrapperEntry { std::uint32_t slot; WrapperAddress address; };

static const WrapperEntry wrappers_IXAccessibilityImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot3_XClosedCaptionGetProperties)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot4_XClosedCaptionSetEnabled)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot5_XHighContrastGetMode)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot6_XSpeechToTextSetPositionHint)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot7_XSpeechToTextSendString)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot8_XSpeechSynthesizerEnumerateInstalledVoices)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot9_XSpeechSynthesizerCreate)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot10_XSpeechSynthesizerCloseHandle)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot11_XSpeechSynthesizerSetDefaultVoice)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot12_XSpeechSynthesizerSetCustomVoice)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot13_XSpeechSynthesizerCreateStreamFromText)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot14_XSpeechSynthesizerCloseStreamHandle)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot15_XSpeechSynthesizerGetStreamDataSize)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot16_XSpeechSynthesizerGetStreamData)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot17_XSpeechToTextBeginHypothesisString)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot18_XSpeechToTextUpdateHypothesisString)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot19_XSpeechToTextFinalizeHypothesisString)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot20_XSpeechToTextCancelHypothesisString)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot21_XSpeechSynthesizerCreateStreamFromSsml)},
};
static const WrapperEntry wrappers_IXAccessibilityImpl2[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot3_XClosedCaptionGetProperties)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot4_XClosedCaptionSetEnabled)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot5_XHighContrastGetMode)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot6_XSpeechToTextSetPositionHint)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot7_XSpeechToTextSendString)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot8_XSpeechSynthesizerEnumerateInstalledVoices)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot9_XSpeechSynthesizerCreate)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot10_XSpeechSynthesizerCloseHandle)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot11_XSpeechSynthesizerSetDefaultVoice)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot12_XSpeechSynthesizerSetCustomVoice)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot13_XSpeechSynthesizerCreateStreamFromText)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot14_XSpeechSynthesizerCloseStreamHandle)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot15_XSpeechSynthesizerGetStreamDataSize)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot16_XSpeechSynthesizerGetStreamData)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot17_XSpeechToTextBeginHypothesisString)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot18_XSpeechToTextUpdateHypothesisString)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot19_XSpeechToTextFinalizeHypothesisString)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot20_XSpeechToTextCancelHypothesisString)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAccessibilityImpl_slot21_XSpeechSynthesizerCreateStreamFromSsml)},
};
static const WrapperEntry wrappers_IXAppCaptureImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot3_XAppCaptureTakeDiagnosticScreenshot)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot4_XAppCaptureRecordDiagnosticClip)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot5_XAppCaptureTakeScreenshot)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot6_XAppCaptureOpenScreenshotStream)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot7_XAppCaptureReadScreenshotStream)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot8_XAppCaptureCloseScreenshotStream)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot9_XAppCaptureEnableRecord)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot10_XAppCaptureDisableRecord)},
};
static const WrapperEntry wrappers_IXAppCaptureImpl2[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot3_XAppCaptureTakeDiagnosticScreenshot)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot4_XAppCaptureRecordDiagnosticClip)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot5_XAppCaptureTakeScreenshot)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot6_XAppCaptureOpenScreenshotStream)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot7_XAppCaptureReadScreenshotStream)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot8_XAppCaptureCloseScreenshotStream)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot9_XAppCaptureEnableRecord)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot10_XAppCaptureDisableRecord)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl2_slot11_XAppCaptureGetVideoCaptureSettings)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl2_slot12_XAppCaptureRecordTimespan)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl2_slot13_XAppCaptureReadLocalStream)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl2_slot14_XAppCaptureCloseLocalStream)},
};
static const WrapperEntry wrappers_IXAppCaptureImpl3[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot3_XAppCaptureTakeDiagnosticScreenshot)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot4_XAppCaptureRecordDiagnosticClip)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot5_XAppCaptureTakeScreenshot)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot6_XAppCaptureOpenScreenshotStream)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot7_XAppCaptureReadScreenshotStream)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot8_XAppCaptureCloseScreenshotStream)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot9_XAppCaptureEnableRecord)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot10_XAppCaptureDisableRecord)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl2_slot11_XAppCaptureGetVideoCaptureSettings)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl2_slot12_XAppCaptureRecordTimespan)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl2_slot13_XAppCaptureReadLocalStream)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl2_slot14_XAppCaptureCloseLocalStream)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl3_slot15_XAppCaptureStartUserRecord)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl3_slot16_XAppCaptureStopUserRecord)},
};
static const WrapperEntry wrappers_IXAppCaptureImpl4[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot3_XAppCaptureTakeDiagnosticScreenshot)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot4_XAppCaptureRecordDiagnosticClip)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot5_XAppCaptureTakeScreenshot)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot6_XAppCaptureOpenScreenshotStream)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot7_XAppCaptureReadScreenshotStream)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot8_XAppCaptureCloseScreenshotStream)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot9_XAppCaptureEnableRecord)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl_slot10_XAppCaptureDisableRecord)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl2_slot11_XAppCaptureGetVideoCaptureSettings)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl2_slot12_XAppCaptureRecordTimespan)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl2_slot13_XAppCaptureReadLocalStream)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl2_slot14_XAppCaptureCloseLocalStream)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl3_slot15_XAppCaptureStartUserRecord)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl3_slot16_XAppCaptureStopUserRecord)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureImpl4_slot17_XAppCaptureCancelUserRecord)},
};
static const WrapperEntry wrappers_IXAppCaptureMetadataImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot3_XAppBroadcastIsAppBroadcasting)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot4_XAppBroadcastShowUI)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot5_XAppBroadcastGetStatus)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot6_XAppBroadcastRegisterIsAppBroadcastingChanged)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot7_XAppBroadcastUnregisterIsAppBroadcastingChanged)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot8_XAppCaptureMetadataAddStringEvent)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot9_XAppCaptureMetadataAddInt32Event)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot10_XAppCaptureMetadataAddDoubleEvent)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot11_XAppCaptureMetadataStartStringState)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot12_XAppCaptureMetadataStartInt32State)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot13_XAppCaptureMetadataStartDoubleState)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot14_XAppCaptureMetadataStopState)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot15_XAppCaptureMetadataStopAllStates)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot16_XAppCaptureMetadataRemainingStorageBytesAvailable)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot17_XAppCaptureRegisterMetadataPurged)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXAppCaptureMetadataImpl_slot18_XAppCaptureUnRegisterMetadataPurged)},
};
static const WrapperEntry wrappers_IXDisplayImpl[] = {
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXDisplayImpl_slot4_XDisplayTryEnableHdrMode)},
};
static const WrapperEntry wrappers_IXErrorImpl[] = {
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXErrorImpl_slot4_XErrorSetCallback)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXErrorImpl_slot5_XErrorSetOptions)},
};
static const WrapperEntry wrappers_IXGameActivationImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameActivationImpl_slot3_XGameActivationRegisterForEvent)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameActivationImpl_slot4_XGameActivationUnregisterForEvent)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameActivationImpl_slot5_XGameActivationAcceptPendingInvite)},
};
static const WrapperEntry wrappers_IXGameEventImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameEventImpl_slot3_XGameEventWrite)},
};
static const WrapperEntry wrappers_IXGameImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameImpl_slot3_XGameGetXboxTitleId)},
};
static const WrapperEntry wrappers_IXGameImpl2[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameImpl_slot3_XGameGetXboxTitleId)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameImpl2_slot4_XLaunchNewGame)},
};
static const WrapperEntry wrappers_IXGameImpl3[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameImpl_slot3_XGameGetXboxTitleId)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameImpl2_slot4_XLaunchNewGame)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameImpl3_slot5_XLaunchRestartOnCrash)},
};
static const WrapperEntry wrappers_IXGameInviteImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameInviteImpl_slot3_XGameInviteRegisterForEvent)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameInviteImpl_slot4_XGameInviteUnregisterForEvent)},
};
static const WrapperEntry wrappers_IXGameInviteImpl2[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameInviteImpl_slot3_XGameInviteRegisterForEvent)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameInviteImpl_slot4_XGameInviteUnregisterForEvent)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameInviteImpl2_slot5_XGameInviteRegisterForPendingEvent)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameInviteImpl2_slot6_XGameInviteUnregisterForPendingEvent)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameInviteImpl2_slot7_XGameInviteAcceptPendingInvite)},
};
static const WrapperEntry wrappers_IXGameProtocolImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameProtocolImpl_slot3_XGameProtocolRegisterForActivation)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameProtocolImpl_slot4_XGameProtocolUnregisterForActivation)},
};
static const WrapperEntry wrappers_IXGameRuntimeFeatureImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameRuntimeFeatureImpl_slot3_XGameRuntimeIsFeatureAvailable)},
};
static const WrapperEntry wrappers_IXGameSaveImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot3_XGameSaveInitializeProvider)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot4_XGameSaveInitializeProviderAsync)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot5_XGameSaveInitializeProviderResult)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot6_XGameSaveCloseProvider)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot7_XGameSaveGetRemainingQuota)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot8_XGameSaveGetRemainingQuotaAsync)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot9_XGameSaveGetRemainingQuotaResult)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot10_XGameSaveDeleteContainer)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot11_XGameSaveDeleteContainerAsync)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot12_XGameSaveDeleteContainerResult)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot13_XGameSaveGetContainerInfo)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot14_XGameSaveEnumerateContainerInfo)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot15_XGameSaveEnumerateContainerInfoByName)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot16_XGameSaveCreateContainer)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot17_XGameSaveCloseContainer)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot18_XGameSaveEnumerateBlobInfo)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot19_XGameSaveEnumerateBlobInfoByName)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot20_XGameSaveReadBlobData)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot21_XGameSaveReadBlobDataAsync)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot22_XGameSaveReadBlobDataResult)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot23_XGameSaveCreateUpdate)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot24_XGameSaveCloseUpdate)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot25_XGameSaveSubmitBlobWrite)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot26_XGameSaveSubmitBlobDelete)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot27_XGameSaveSubmitUpdate)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot28_XGameSaveSubmitUpdateAsync)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot29_XGameSaveSubmitUpdateResult)},
};
static const WrapperEntry wrappers_IXGameSaveImpl2[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot3_XGameSaveInitializeProvider)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot4_XGameSaveInitializeProviderAsync)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot5_XGameSaveInitializeProviderResult)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot6_XGameSaveCloseProvider)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot7_XGameSaveGetRemainingQuota)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot8_XGameSaveGetRemainingQuotaAsync)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot9_XGameSaveGetRemainingQuotaResult)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot10_XGameSaveDeleteContainer)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot11_XGameSaveDeleteContainerAsync)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot12_XGameSaveDeleteContainerResult)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot13_XGameSaveGetContainerInfo)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot14_XGameSaveEnumerateContainerInfo)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot15_XGameSaveEnumerateContainerInfoByName)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot16_XGameSaveCreateContainer)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot17_XGameSaveCloseContainer)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot18_XGameSaveEnumerateBlobInfo)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot19_XGameSaveEnumerateBlobInfoByName)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot20_XGameSaveReadBlobData)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot21_XGameSaveReadBlobDataAsync)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot22_XGameSaveReadBlobDataResult)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot23_XGameSaveCreateUpdate)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot24_XGameSaveCloseUpdate)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot25_XGameSaveSubmitBlobWrite)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot26_XGameSaveSubmitBlobDelete)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot27_XGameSaveSubmitUpdate)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot28_XGameSaveSubmitUpdateAsync)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot29_XGameSaveSubmitUpdateResult)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl2_slot30_XGameSaveFilesGetFolderWithUiAsync)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl2_slot31_XGameSaveFilesGetFolderWithUiResult)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl2_slot32_XGameSaveFilesGetRemainingQuota)},
};
static const WrapperEntry wrappers_IXGameSaveImpl3[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot3_XGameSaveInitializeProvider)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot4_XGameSaveInitializeProviderAsync)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot5_XGameSaveInitializeProviderResult)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot6_XGameSaveCloseProvider)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot7_XGameSaveGetRemainingQuota)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot8_XGameSaveGetRemainingQuotaAsync)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot9_XGameSaveGetRemainingQuotaResult)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot10_XGameSaveDeleteContainer)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot11_XGameSaveDeleteContainerAsync)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot12_XGameSaveDeleteContainerResult)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot13_XGameSaveGetContainerInfo)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot14_XGameSaveEnumerateContainerInfo)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot15_XGameSaveEnumerateContainerInfoByName)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot16_XGameSaveCreateContainer)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot17_XGameSaveCloseContainer)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot18_XGameSaveEnumerateBlobInfo)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot19_XGameSaveEnumerateBlobInfoByName)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot20_XGameSaveReadBlobData)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot21_XGameSaveReadBlobDataAsync)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot22_XGameSaveReadBlobDataResult)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot23_XGameSaveCreateUpdate)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot24_XGameSaveCloseUpdate)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot25_XGameSaveSubmitBlobWrite)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot26_XGameSaveSubmitBlobDelete)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot27_XGameSaveSubmitUpdate)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot28_XGameSaveSubmitUpdateAsync)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl_slot29_XGameSaveSubmitUpdateResult)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl2_slot30_XGameSaveFilesGetFolderWithUiAsync)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl2_slot31_XGameSaveFilesGetFolderWithUiResult)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameSaveImpl2_slot32_XGameSaveFilesGetRemainingQuota)},
};
static const WrapperEntry wrappers_IXGameStreamingImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot3_XGameStreamingInitialize)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot4_XGameStreamingUninitialize)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot5_XGameStreamingIsStreaming)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot6_XGameStreamingRegisterClientPropertiesChanged)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot7_XGameStreamingUnregisterClientPropertiesChanged)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot8_XGameStreamingGetStreamPhysicalDimensions)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot9_XGameStreamingGetClientCount)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot10_XGameStreamingGetClients)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot11_XGameStreamingGetConnectionState)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot12_XGameStreamingRegisterConnectionStateChanged)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot13_XGameStreamingUnregisterConnectionStateChanged)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot14_XGameStreamingGetStreamAddedLatency)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot15_XGameStreamingGetServerLocationNameSize)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot16_XGameStreamingGetServerLocationName)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot17_XGameStreamingHideTouchControls)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot18_XGameStreamingShowTouchControlLayout)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot19_XGameStreamingHideTouchControlsOnClient)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot20_XGameStreamingShowTouchControlLayoutOnClient)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot21_XGameStreamingIsTouchInputEnabled)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot22_XGameStreamingGetLastFrameDisplayed)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot23_XGameStreamingGetAssociatedFrame)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot24_XGameStreamingGetGamepadPhysicality)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot25_XGameStreamingUpdateTouchControlsState)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot26_XGameStreamingUpdateTouchControlsStateOnClient)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot27_XGameStreamingShowTouchControlsWithStateUpdate)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot28_XGameStreamingShowTouchControlsWithStateUpdateOnClient)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot29_XGameStreamingGetTouchBundleVersionNameSize)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot30_XGameStreamingGetTouchBundleVersion)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot31_XGameStreamingGetClientIPAddress)},
};
static const WrapperEntry wrappers_IXGameStreamingImpl2[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot3_XGameStreamingInitialize)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot4_XGameStreamingUninitialize)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot5_XGameStreamingIsStreaming)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot6_XGameStreamingRegisterClientPropertiesChanged)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot7_XGameStreamingUnregisterClientPropertiesChanged)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot8_XGameStreamingGetStreamPhysicalDimensions)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot9_XGameStreamingGetClientCount)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot10_XGameStreamingGetClients)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot11_XGameStreamingGetConnectionState)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot12_XGameStreamingRegisterConnectionStateChanged)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot13_XGameStreamingUnregisterConnectionStateChanged)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot14_XGameStreamingGetStreamAddedLatency)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot15_XGameStreamingGetServerLocationNameSize)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot16_XGameStreamingGetServerLocationName)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot17_XGameStreamingHideTouchControls)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot18_XGameStreamingShowTouchControlLayout)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot19_XGameStreamingHideTouchControlsOnClient)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot20_XGameStreamingShowTouchControlLayoutOnClient)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot21_XGameStreamingIsTouchInputEnabled)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot22_XGameStreamingGetLastFrameDisplayed)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot23_XGameStreamingGetAssociatedFrame)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot24_XGameStreamingGetGamepadPhysicality)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot25_XGameStreamingUpdateTouchControlsState)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot26_XGameStreamingUpdateTouchControlsStateOnClient)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot27_XGameStreamingShowTouchControlsWithStateUpdate)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot28_XGameStreamingShowTouchControlsWithStateUpdateOnClient)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot29_XGameStreamingGetTouchBundleVersionNameSize)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot30_XGameStreamingGetTouchBundleVersion)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot31_XGameStreamingGetClientIPAddress)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl2_slot32_XGameStreamingGetSessionId)},
};
static const WrapperEntry wrappers_IXGameStreamingImpl3[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot3_XGameStreamingInitialize)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot4_XGameStreamingUninitialize)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot5_XGameStreamingIsStreaming)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot6_XGameStreamingRegisterClientPropertiesChanged)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot7_XGameStreamingUnregisterClientPropertiesChanged)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot8_XGameStreamingGetStreamPhysicalDimensions)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot9_XGameStreamingGetClientCount)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot10_XGameStreamingGetClients)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot11_XGameStreamingGetConnectionState)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot12_XGameStreamingRegisterConnectionStateChanged)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot13_XGameStreamingUnregisterConnectionStateChanged)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot14_XGameStreamingGetStreamAddedLatency)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot15_XGameStreamingGetServerLocationNameSize)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot16_XGameStreamingGetServerLocationName)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot17_XGameStreamingHideTouchControls)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot18_XGameStreamingShowTouchControlLayout)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot19_XGameStreamingHideTouchControlsOnClient)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot20_XGameStreamingShowTouchControlLayoutOnClient)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot21_XGameStreamingIsTouchInputEnabled)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot22_XGameStreamingGetLastFrameDisplayed)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot23_XGameStreamingGetAssociatedFrame)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot24_XGameStreamingGetGamepadPhysicality)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot25_XGameStreamingUpdateTouchControlsState)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot26_XGameStreamingUpdateTouchControlsStateOnClient)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot27_XGameStreamingShowTouchControlsWithStateUpdate)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot28_XGameStreamingShowTouchControlsWithStateUpdateOnClient)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot29_XGameStreamingGetTouchBundleVersionNameSize)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot30_XGameStreamingGetTouchBundleVersion)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl_slot31_XGameStreamingGetClientIPAddress)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl2_slot32_XGameStreamingGetSessionId)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl3_slot33_XGameStreamingGetDisplayDetails)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameStreamingImpl3_slot34_XGameStreamingSetResolution)},
};
static const WrapperEntry wrappers_IXGameUiImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot3_XGameUiShowMessageDialogAsync)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot4_XGameUiShowMessageDialogResult)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot5_XGameUiShowSendGameInviteAsync)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot6_XGameUiShowSendGameInviteResult)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot7_XGameUiShowPlayerProfileCardAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot8_XGameUiShowPlayerProfileCardResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot9_XGameUiShowAchievementsAsync)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot10_XGameUiShowAchievementsResult)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot11_XGameUiShowPlayerPickerAsync)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot12_XGameUiShowPlayerPickerResultCount)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot13_XGameUiShowPlayerPickerResult)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot14_XGameUiShowErrorDialogAsync)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot15_XGameUiShowErrorDialogResult)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot16_XGameUiSetNotificationPositionHint)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot17_XGameUiShowTextEntryAsync)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot18_XGameUiShowTextEntryResultSize)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot19_XGameUiShowTextEntryResult)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot24_XGameUiShowWebAuthenticationAsync)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot25_XGameUiShowWebAuthenticationResultSize)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot26_XGameUiShowWebAuthenticationResult)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot27_XGameUiShowWebAuthenticationWithOptionsAsync)},
};
static const WrapperEntry wrappers_IXGameUiImpl2[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot3_XGameUiShowMessageDialogAsync)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot4_XGameUiShowMessageDialogResult)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot5_XGameUiShowSendGameInviteAsync)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot6_XGameUiShowSendGameInviteResult)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot7_XGameUiShowPlayerProfileCardAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot8_XGameUiShowPlayerProfileCardResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot9_XGameUiShowAchievementsAsync)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot10_XGameUiShowAchievementsResult)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot11_XGameUiShowPlayerPickerAsync)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot12_XGameUiShowPlayerPickerResultCount)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot13_XGameUiShowPlayerPickerResult)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot14_XGameUiShowErrorDialogAsync)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot15_XGameUiShowErrorDialogResult)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot16_XGameUiSetNotificationPositionHint)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot17_XGameUiShowTextEntryAsync)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot18_XGameUiShowTextEntryResultSize)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot19_XGameUiShowTextEntryResult)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot24_XGameUiShowWebAuthenticationAsync)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot25_XGameUiShowWebAuthenticationResultSize)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot26_XGameUiShowWebAuthenticationResult)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot27_XGameUiShowWebAuthenticationWithOptionsAsync)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot30_XGameUiShowMultiplayerActivityGameInviteAsync)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot31_XGameUiShowMultiplayerActivityGameInviteResult)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot34_XGameUiTextEntryOpen)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot35_XGameUiTextEntryClose)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot36_XGameUiTextEntryGetState)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot37_XGameUiTextEntryGetExtents)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot38_XGameUiTextEntryUpdatePositionHint)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot39_XGameUiTextEntryUpdateVisibility)},
};
static const WrapperEntry wrappers_IXGameUiImpl3[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot3_XGameUiShowMessageDialogAsync)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot4_XGameUiShowMessageDialogResult)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot5_XGameUiShowSendGameInviteAsync)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot6_XGameUiShowSendGameInviteResult)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot7_XGameUiShowPlayerProfileCardAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot8_XGameUiShowPlayerProfileCardResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot9_XGameUiShowAchievementsAsync)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot10_XGameUiShowAchievementsResult)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot11_XGameUiShowPlayerPickerAsync)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot12_XGameUiShowPlayerPickerResultCount)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot13_XGameUiShowPlayerPickerResult)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot14_XGameUiShowErrorDialogAsync)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot15_XGameUiShowErrorDialogResult)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot16_XGameUiSetNotificationPositionHint)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot17_XGameUiShowTextEntryAsync)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot18_XGameUiShowTextEntryResultSize)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot19_XGameUiShowTextEntryResult)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot24_XGameUiShowWebAuthenticationAsync)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot25_XGameUiShowWebAuthenticationResultSize)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot26_XGameUiShowWebAuthenticationResult)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot27_XGameUiShowWebAuthenticationWithOptionsAsync)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot30_XGameUiShowMultiplayerActivityGameInviteAsync)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot31_XGameUiShowMultiplayerActivityGameInviteResult)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot34_XGameUiTextEntryOpen)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot35_XGameUiTextEntryClose)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot36_XGameUiTextEntryGetState)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot37_XGameUiTextEntryGetExtents)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot38_XGameUiTextEntryUpdatePositionHint)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot39_XGameUiTextEntryUpdateVisibility)},
    {40, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl3_slot40_XGameUiShowStateShareAsync)},
    {41, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl3_slot41_XGameUiShowStateShareResult)},
};
static const WrapperEntry wrappers_IXGameUiImpl4[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot3_XGameUiShowMessageDialogAsync)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot4_XGameUiShowMessageDialogResult)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot5_XGameUiShowSendGameInviteAsync)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot6_XGameUiShowSendGameInviteResult)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot7_XGameUiShowPlayerProfileCardAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot8_XGameUiShowPlayerProfileCardResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot9_XGameUiShowAchievementsAsync)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot10_XGameUiShowAchievementsResult)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot11_XGameUiShowPlayerPickerAsync)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot12_XGameUiShowPlayerPickerResultCount)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot13_XGameUiShowPlayerPickerResult)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot14_XGameUiShowErrorDialogAsync)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot15_XGameUiShowErrorDialogResult)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot16_XGameUiSetNotificationPositionHint)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot17_XGameUiShowTextEntryAsync)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot18_XGameUiShowTextEntryResultSize)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot19_XGameUiShowTextEntryResult)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot24_XGameUiShowWebAuthenticationAsync)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot25_XGameUiShowWebAuthenticationResultSize)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot26_XGameUiShowWebAuthenticationResult)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl_slot27_XGameUiShowWebAuthenticationWithOptionsAsync)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot30_XGameUiShowMultiplayerActivityGameInviteAsync)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot31_XGameUiShowMultiplayerActivityGameInviteResult)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot34_XGameUiTextEntryOpen)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot35_XGameUiTextEntryClose)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot36_XGameUiTextEntryGetState)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot37_XGameUiTextEntryGetExtents)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot38_XGameUiTextEntryUpdatePositionHint)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl2_slot39_XGameUiTextEntryUpdateVisibility)},
    {40, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl3_slot40_XGameUiShowStateShareAsync)},
    {41, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl3_slot41_XGameUiShowStateShareResult)},
    {42, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl4_slot42_XGameUiSetUiCallbacks)},
    {43, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl4_slot43_XGameUiSetMessageDialogUiResponse)},
    {44, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl4_slot44_XGameUiSetPlayerPickerUiResponse)},
    {45, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl4_slot45_XGameUiSetTextEntryUiResponse)},
    {46, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl4_slot46_XGameUiSetPlayerProfileCardUiResponse)},
    {47, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl4_slot47_XGameUiSetSendGameInviteUiResponse)},
    {48, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl4_slot48_XGameUiSetAchievementsUiResponse)},
    {49, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl4_slot49_XGameUiSetMultiplayerActivityGameInviteUiResponse)},
    {50, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXGameUiImpl4_slot50_XGameUiSetErrorDialogUiResponse)},
};
static const WrapperEntry wrappers_IXLauncherImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXLauncherImpl_slot3_XLaunchUri)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXLauncherImpl_slot4_XDisplayAcquireTimeoutDeferral)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXLauncherImpl_slot5_XDisplayCloseTimeoutDeferralHandle)},
};
static const WrapperEntry wrappers_IXNetworkingImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot3_XNetworkingQueryPreferredLocalUdpMultiplayerPort)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot4_XNetworkingQueryPreferredLocalUdpMultiplayerPortAsync)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot5_XNetworkingQueryPreferredLocalUdpMultiplayerPortAsyncResult)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot6_XNetworkingRegisterPreferredLocalUdpMultiplayerPortChanged)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot7_XNetworkingUnregisterPreferredLocalUdpMultiplayerPortChanged)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot8_XNetworkingQuerySecurityInformationForUrlAsync)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot9_XNetworkingQuerySecurityInformationForUrlAsyncResultSize)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot10_XNetworkingQuerySecurityInformationForUrlAsyncResult)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot11_XNetworkingQuerySecurityInformationForUrlUtf16Async)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot12_XNetworkingQuerySecurityInformationForUrlUtf16AsyncResultSize)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot13_XNetworkingQuerySecurityInformationForUrlUtf16AsyncResult)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot14_XNetworkingVerifyServerCertificate)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot15_XNetworkingGetConnectivityHint)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot16_XNetworkingRegisterConnectivityHintChanged)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot17_XNetworkingUnregisterConnectivityHintChanged)},
};
static const WrapperEntry wrappers_IXNetworkingImpl2[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot3_XNetworkingQueryPreferredLocalUdpMultiplayerPort)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot4_XNetworkingQueryPreferredLocalUdpMultiplayerPortAsync)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot5_XNetworkingQueryPreferredLocalUdpMultiplayerPortAsyncResult)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot6_XNetworkingRegisterPreferredLocalUdpMultiplayerPortChanged)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot7_XNetworkingUnregisterPreferredLocalUdpMultiplayerPortChanged)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot8_XNetworkingQuerySecurityInformationForUrlAsync)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot9_XNetworkingQuerySecurityInformationForUrlAsyncResultSize)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot10_XNetworkingQuerySecurityInformationForUrlAsyncResult)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot11_XNetworkingQuerySecurityInformationForUrlUtf16Async)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot12_XNetworkingQuerySecurityInformationForUrlUtf16AsyncResultSize)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot13_XNetworkingQuerySecurityInformationForUrlUtf16AsyncResult)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot14_XNetworkingVerifyServerCertificate)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot15_XNetworkingGetConnectivityHint)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot16_XNetworkingRegisterConnectivityHintChanged)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl_slot17_XNetworkingUnregisterConnectivityHintChanged)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl2_slot18_XNetworkingQueryConfigurationSetting)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl2_slot19_XNetworkingSetConfigurationSetting)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXNetworkingImpl2_slot20_XNetworkingQueryStatistics)},
};
static const WrapperEntry wrappers_IXPackageImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot3_XPackageGetCurrentProcessPackageIdentifier)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot4_XPackageIsPackagedProcess)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot5_XPackageCreateInstallationMonitor)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot6_XPackageCloseInstallationMonitorHandle)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot7_XPackageGetInstallationProgress)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot8_XPackageUpdateInstallationMonitor)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot9_XPackageRegisterInstallationProgressChanged)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot10_XPackageUnregisterInstallationProgressChanged)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot11_XPackageGetUserLocale)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot12_XPackageFindChunkAvailability)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot13_XPackageEnumerateChunkAvailability)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot14_XPackageChangeChunkInstallOrder)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot15_XPackageInstallChunks)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot16_XPackageInstallChunksAsync)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot17_XPackageInstallChunksResult)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot18_XPackageEstimateDownloadSize)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot19_XPackageUninstallChunks)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot22_XPackageUnregisterPackageInstalled)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot23_XPackageMount)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot24_XPackageGetMountPathSize)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot25_XPackageGetMountPath)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot26_XPackageCloseMountHandle)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot28_XPackageEnumeratePackages)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot29_XPackageRegisterPackageInstalled)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot30_XPackageGetWriteStats)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot32_XPackageUninstallUWPInstance)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot33_XPackageEnumerateFeatures)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot34_XPackageUninstallPackage)},
};
static const WrapperEntry wrappers_IXPackageImpl2[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot3_XPackageGetCurrentProcessPackageIdentifier)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot4_XPackageIsPackagedProcess)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot5_XPackageCreateInstallationMonitor)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot6_XPackageCloseInstallationMonitorHandle)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot7_XPackageGetInstallationProgress)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot8_XPackageUpdateInstallationMonitor)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot9_XPackageRegisterInstallationProgressChanged)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot10_XPackageUnregisterInstallationProgressChanged)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot11_XPackageGetUserLocale)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot12_XPackageFindChunkAvailability)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot13_XPackageEnumerateChunkAvailability)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot14_XPackageChangeChunkInstallOrder)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot15_XPackageInstallChunks)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot16_XPackageInstallChunksAsync)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot17_XPackageInstallChunksResult)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot18_XPackageEstimateDownloadSize)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot19_XPackageUninstallChunks)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot22_XPackageUnregisterPackageInstalled)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot23_XPackageMount)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot24_XPackageGetMountPathSize)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot25_XPackageGetMountPath)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot26_XPackageCloseMountHandle)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot28_XPackageEnumeratePackages)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot29_XPackageRegisterPackageInstalled)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot30_XPackageGetWriteStats)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot32_XPackageUninstallUWPInstance)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot33_XPackageEnumerateFeatures)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot34_XPackageUninstallPackage)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl2_slot35_XPackageEnumeratePackages)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl2_slot36_XPackageRegisterPackageInstalled)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl2_slot37_XPackageMountWithUiAsync)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl2_slot38_XPackageMountWithUiResult)},
};
static const WrapperEntry wrappers_IXPackageImpl3[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot3_XPackageGetCurrentProcessPackageIdentifier)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot4_XPackageIsPackagedProcess)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot5_XPackageCreateInstallationMonitor)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot6_XPackageCloseInstallationMonitorHandle)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot7_XPackageGetInstallationProgress)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot8_XPackageUpdateInstallationMonitor)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot9_XPackageRegisterInstallationProgressChanged)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot10_XPackageUnregisterInstallationProgressChanged)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot11_XPackageGetUserLocale)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot12_XPackageFindChunkAvailability)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot13_XPackageEnumerateChunkAvailability)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot14_XPackageChangeChunkInstallOrder)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot15_XPackageInstallChunks)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot16_XPackageInstallChunksAsync)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot17_XPackageInstallChunksResult)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot18_XPackageEstimateDownloadSize)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot19_XPackageUninstallChunks)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot22_XPackageUnregisterPackageInstalled)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot23_XPackageMount)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot24_XPackageGetMountPathSize)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot25_XPackageGetMountPath)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot26_XPackageCloseMountHandle)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot28_XPackageEnumeratePackages)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot29_XPackageRegisterPackageInstalled)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot30_XPackageGetWriteStats)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot32_XPackageUninstallUWPInstance)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot33_XPackageEnumerateFeatures)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot34_XPackageUninstallPackage)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl2_slot35_XPackageEnumeratePackages)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl2_slot36_XPackageRegisterPackageInstalled)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl2_slot37_XPackageMountWithUiAsync)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl2_slot38_XPackageMountWithUiResult)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl3_slot39_XPackageEnumeratePackages)},
    {40, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl3_slot40_XPackageRegisterPackageInstalled)},
};
static const WrapperEntry wrappers_IXPackageImpl4[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot3_XPackageGetCurrentProcessPackageIdentifier)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot4_XPackageIsPackagedProcess)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot5_XPackageCreateInstallationMonitor)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot6_XPackageCloseInstallationMonitorHandle)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot7_XPackageGetInstallationProgress)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot8_XPackageUpdateInstallationMonitor)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot9_XPackageRegisterInstallationProgressChanged)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot10_XPackageUnregisterInstallationProgressChanged)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot11_XPackageGetUserLocale)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot12_XPackageFindChunkAvailability)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot13_XPackageEnumerateChunkAvailability)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot14_XPackageChangeChunkInstallOrder)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot15_XPackageInstallChunks)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot16_XPackageInstallChunksAsync)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot17_XPackageInstallChunksResult)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot18_XPackageEstimateDownloadSize)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot19_XPackageUninstallChunks)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot22_XPackageUnregisterPackageInstalled)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot23_XPackageMount)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot24_XPackageGetMountPathSize)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot25_XPackageGetMountPath)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot26_XPackageCloseMountHandle)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot28_XPackageEnumeratePackages)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot29_XPackageRegisterPackageInstalled)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot30_XPackageGetWriteStats)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot32_XPackageUninstallUWPInstance)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot33_XPackageEnumerateFeatures)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl_slot34_XPackageUninstallPackage)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl2_slot35_XPackageEnumeratePackages)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl2_slot36_XPackageRegisterPackageInstalled)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl2_slot37_XPackageMountWithUiAsync)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl2_slot38_XPackageMountWithUiResult)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl3_slot39_XPackageEnumeratePackages)},
    {40, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl3_slot40_XPackageRegisterPackageInstalled)},
    {41, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPackageImpl4_slot41_XPackageGetKind)},
};
static const WrapperEntry wrappers_IXPersistentLocalStorageImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot3_XPersistentLocalStorageGetPathSize)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot4_XPersistentLocalStorageGetPath)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot5_XPersistentLocalStorageGetSpaceInfo)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot6_XPersistentLocalStoragePromptUserForSpaceAsync)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot7_XPersistentLocalStoragePromptUserForSpaceResult)},
};
static const WrapperEntry wrappers_IXPersistentLocalStorageImpl2[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot3_XPersistentLocalStorageGetPathSize)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot4_XPersistentLocalStorageGetPath)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot5_XPersistentLocalStorageGetSpaceInfo)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot6_XPersistentLocalStoragePromptUserForSpaceAsync)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot7_XPersistentLocalStoragePromptUserForSpaceResult)},
};
static const WrapperEntry wrappers_IXPersistentLocalStorageImpl3[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot3_XPersistentLocalStorageGetPathSize)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot4_XPersistentLocalStorageGetPath)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot5_XPersistentLocalStorageGetSpaceInfo)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot6_XPersistentLocalStoragePromptUserForSpaceAsync)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl_slot7_XPersistentLocalStoragePromptUserForSpaceResult)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXPersistentLocalStorageImpl3_slot8_XPersistentLocalStorageMountForPackage)},
};
static const WrapperEntry wrappers_IXStoreImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot3_XStoreCreateContext)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot4_XStoreCloseContextHandle)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot5_XStoreQueryAssociatedProductsAsync)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot6_XStoreQueryAssociatedProductsResult)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot7_XStoreQueryProductsAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot8_XStoreQueryProductsResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot9_XStoreQueryEntitledProductsAsync)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot10_XStoreQueryEntitledProductsResult)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot11_XStoreQueryProductForCurrentGameAsync)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot12_XStoreQueryProductForCurrentGameResult)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot13_XStoreQueryProductForPackageAsync)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot14_XStoreQueryProductForPackageResult)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot15_XStoreEnumerateProductsQuery)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot16_XStoreProductsQueryHasMorePages)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot17_XStoreProductsQueryNextPageAsync)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot18_XStoreProductsQueryNextPageResult)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot19_XStoreCloseProductsQueryHandle)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot20_XStoreAcquireLicenseForPackageAsync)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot21_XStoreAcquireLicenseForPackageResult)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot22_XStoreIsLicenseValid)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot23_XStoreCloseLicenseHandle)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot24_XStoreCanAcquireLicenseForStoreIdAsync)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot25_XStoreCanAcquireLicenseForStoreIdResult)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot26_XStoreCanAcquireLicenseForPackageAsync)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot27_XStoreCanAcquireLicenseForPackageResult)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot28_XStoreQueryGameLicenseAsync)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot29_XStoreQueryGameLicenseResult)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot30_XStoreQueryAddOnLicensesAsync)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot31_XStoreQueryAddOnLicensesResultCount)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot32_XStoreQueryAddOnLicensesResult)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot33_XStoreQueryConsumableBalanceRemainingAsync)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot34_XStoreQueryConsumableBalanceRemainingResult)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot35_XStoreReportConsumableFulfillmentAsync)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot36_XStoreReportConsumableFulfillmentResult)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot37_XStoreGetUserCollectionsIdAsync)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot38_XStoreGetUserCollectionsIdResultSize)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot39_XStoreGetUserCollectionsIdResult)},
    {40, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot40_XStoreGetUserPurchaseIdAsync)},
    {41, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot41_XStoreGetUserPurchaseIdResultSize)},
    {42, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot42_XStoreGetUserPurchaseIdResult)},
    {43, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot43_XStoreQueryLicenseTokenAsync)},
    {44, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot44_XStoreQueryLicenseTokenResultSize)},
    {45, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot45_XStoreQueryLicenseTokenResult)},
    {49, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot49_XStoreShowPurchaseUIAsync)},
    {50, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot50_XStoreShowPurchaseUIResult)},
    {51, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot51_XStoreShowRateAndReviewUIAsync)},
    {52, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot52_XStoreShowRateAndReviewUIResult)},
    {53, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot53_XStoreShowRedeemTokenUIAsync)},
    {54, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot54_XStoreShowRedeemTokenUIResult)},
    {55, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot55_XStoreQueryGameAndDlcPackageUpdatesAsync)},
    {56, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot56_XStoreQueryGameAndDlcPackageUpdatesResultCount)},
    {57, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot57_XStoreQueryGameAndDlcPackageUpdatesResult)},
    {58, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot58_XStoreDownloadPackageUpdatesAsync)},
    {59, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot59_XStoreDownloadPackageUpdatesResult)},
    {60, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot60_XStoreDownloadAndInstallPackageUpdatesAsync)},
    {61, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot61_XStoreDownloadAndInstallPackageUpdatesResult)},
    {62, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot62_XStoreDownloadAndInstallPackagesAsync)},
    {63, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot63_XStoreDownloadAndInstallPackagesResultCount)},
    {64, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot64_XStoreDownloadAndInstallPackagesResult)},
    {65, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot65_XStoreQueryPackageIdentifier)},
    {66, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot66_XStoreRegisterGameLicenseChanged)},
    {67, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot67_XStoreUnregisterGameLicenseChanged)},
    {68, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot68_XStoreRegisterPackageLicenseLost)},
    {69, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot69_XStoreUnregisterPackageLicenseLost)},
};
static const WrapperEntry wrappers_IXStoreImpl2[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot3_XStoreCreateContext)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot4_XStoreCloseContextHandle)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot5_XStoreQueryAssociatedProductsAsync)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot6_XStoreQueryAssociatedProductsResult)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot7_XStoreQueryProductsAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot8_XStoreQueryProductsResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot9_XStoreQueryEntitledProductsAsync)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot10_XStoreQueryEntitledProductsResult)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot11_XStoreQueryProductForCurrentGameAsync)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot12_XStoreQueryProductForCurrentGameResult)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot13_XStoreQueryProductForPackageAsync)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot14_XStoreQueryProductForPackageResult)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot15_XStoreEnumerateProductsQuery)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot16_XStoreProductsQueryHasMorePages)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot17_XStoreProductsQueryNextPageAsync)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot18_XStoreProductsQueryNextPageResult)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot19_XStoreCloseProductsQueryHandle)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot20_XStoreAcquireLicenseForPackageAsync)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot21_XStoreAcquireLicenseForPackageResult)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot22_XStoreIsLicenseValid)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot23_XStoreCloseLicenseHandle)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot24_XStoreCanAcquireLicenseForStoreIdAsync)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot25_XStoreCanAcquireLicenseForStoreIdResult)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot26_XStoreCanAcquireLicenseForPackageAsync)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot27_XStoreCanAcquireLicenseForPackageResult)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot28_XStoreQueryGameLicenseAsync)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot29_XStoreQueryGameLicenseResult)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot30_XStoreQueryAddOnLicensesAsync)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot31_XStoreQueryAddOnLicensesResultCount)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot32_XStoreQueryAddOnLicensesResult)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot33_XStoreQueryConsumableBalanceRemainingAsync)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot34_XStoreQueryConsumableBalanceRemainingResult)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot35_XStoreReportConsumableFulfillmentAsync)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot36_XStoreReportConsumableFulfillmentResult)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot37_XStoreGetUserCollectionsIdAsync)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot38_XStoreGetUserCollectionsIdResultSize)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot39_XStoreGetUserCollectionsIdResult)},
    {40, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot40_XStoreGetUserPurchaseIdAsync)},
    {41, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot41_XStoreGetUserPurchaseIdResultSize)},
    {42, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot42_XStoreGetUserPurchaseIdResult)},
    {43, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot43_XStoreQueryLicenseTokenAsync)},
    {44, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot44_XStoreQueryLicenseTokenResultSize)},
    {45, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot45_XStoreQueryLicenseTokenResult)},
    {49, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot49_XStoreShowPurchaseUIAsync)},
    {50, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot50_XStoreShowPurchaseUIResult)},
    {51, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot51_XStoreShowRateAndReviewUIAsync)},
    {52, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot52_XStoreShowRateAndReviewUIResult)},
    {53, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot53_XStoreShowRedeemTokenUIAsync)},
    {54, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot54_XStoreShowRedeemTokenUIResult)},
    {55, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot55_XStoreQueryGameAndDlcPackageUpdatesAsync)},
    {56, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot56_XStoreQueryGameAndDlcPackageUpdatesResultCount)},
    {57, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot57_XStoreQueryGameAndDlcPackageUpdatesResult)},
    {58, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot58_XStoreDownloadPackageUpdatesAsync)},
    {59, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot59_XStoreDownloadPackageUpdatesResult)},
    {60, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot60_XStoreDownloadAndInstallPackageUpdatesAsync)},
    {61, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot61_XStoreDownloadAndInstallPackageUpdatesResult)},
    {62, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot62_XStoreDownloadAndInstallPackagesAsync)},
    {63, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot63_XStoreDownloadAndInstallPackagesResultCount)},
    {64, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot64_XStoreDownloadAndInstallPackagesResult)},
    {65, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot65_XStoreQueryPackageIdentifier)},
    {66, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot66_XStoreRegisterGameLicenseChanged)},
    {67, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot67_XStoreUnregisterGameLicenseChanged)},
    {68, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot68_XStoreRegisterPackageLicenseLost)},
    {69, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot69_XStoreUnregisterPackageLicenseLost)},
    {70, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl2_slot70_XStoreIsAvailabilityPurchasable)},
};
static const WrapperEntry wrappers_IXStoreImpl3[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot3_XStoreCreateContext)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot4_XStoreCloseContextHandle)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot5_XStoreQueryAssociatedProductsAsync)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot6_XStoreQueryAssociatedProductsResult)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot7_XStoreQueryProductsAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot8_XStoreQueryProductsResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot9_XStoreQueryEntitledProductsAsync)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot10_XStoreQueryEntitledProductsResult)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot11_XStoreQueryProductForCurrentGameAsync)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot12_XStoreQueryProductForCurrentGameResult)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot13_XStoreQueryProductForPackageAsync)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot14_XStoreQueryProductForPackageResult)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot15_XStoreEnumerateProductsQuery)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot16_XStoreProductsQueryHasMorePages)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot17_XStoreProductsQueryNextPageAsync)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot18_XStoreProductsQueryNextPageResult)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot19_XStoreCloseProductsQueryHandle)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot20_XStoreAcquireLicenseForPackageAsync)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot21_XStoreAcquireLicenseForPackageResult)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot22_XStoreIsLicenseValid)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot23_XStoreCloseLicenseHandle)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot24_XStoreCanAcquireLicenseForStoreIdAsync)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot25_XStoreCanAcquireLicenseForStoreIdResult)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot26_XStoreCanAcquireLicenseForPackageAsync)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot27_XStoreCanAcquireLicenseForPackageResult)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot28_XStoreQueryGameLicenseAsync)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot29_XStoreQueryGameLicenseResult)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot30_XStoreQueryAddOnLicensesAsync)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot31_XStoreQueryAddOnLicensesResultCount)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot32_XStoreQueryAddOnLicensesResult)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot33_XStoreQueryConsumableBalanceRemainingAsync)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot34_XStoreQueryConsumableBalanceRemainingResult)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot35_XStoreReportConsumableFulfillmentAsync)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot36_XStoreReportConsumableFulfillmentResult)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot37_XStoreGetUserCollectionsIdAsync)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot38_XStoreGetUserCollectionsIdResultSize)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot39_XStoreGetUserCollectionsIdResult)},
    {40, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot40_XStoreGetUserPurchaseIdAsync)},
    {41, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot41_XStoreGetUserPurchaseIdResultSize)},
    {42, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot42_XStoreGetUserPurchaseIdResult)},
    {43, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot43_XStoreQueryLicenseTokenAsync)},
    {44, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot44_XStoreQueryLicenseTokenResultSize)},
    {45, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot45_XStoreQueryLicenseTokenResult)},
    {49, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot49_XStoreShowPurchaseUIAsync)},
    {50, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot50_XStoreShowPurchaseUIResult)},
    {51, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot51_XStoreShowRateAndReviewUIAsync)},
    {52, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot52_XStoreShowRateAndReviewUIResult)},
    {53, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot53_XStoreShowRedeemTokenUIAsync)},
    {54, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot54_XStoreShowRedeemTokenUIResult)},
    {55, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot55_XStoreQueryGameAndDlcPackageUpdatesAsync)},
    {56, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot56_XStoreQueryGameAndDlcPackageUpdatesResultCount)},
    {57, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot57_XStoreQueryGameAndDlcPackageUpdatesResult)},
    {58, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot58_XStoreDownloadPackageUpdatesAsync)},
    {59, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot59_XStoreDownloadPackageUpdatesResult)},
    {60, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot60_XStoreDownloadAndInstallPackageUpdatesAsync)},
    {61, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot61_XStoreDownloadAndInstallPackageUpdatesResult)},
    {62, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot62_XStoreDownloadAndInstallPackagesAsync)},
    {63, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot63_XStoreDownloadAndInstallPackagesResultCount)},
    {64, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot64_XStoreDownloadAndInstallPackagesResult)},
    {65, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot65_XStoreQueryPackageIdentifier)},
    {66, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot66_XStoreRegisterGameLicenseChanged)},
    {67, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot67_XStoreUnregisterGameLicenseChanged)},
    {68, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot68_XStoreRegisterPackageLicenseLost)},
    {69, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot69_XStoreUnregisterPackageLicenseLost)},
    {70, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl2_slot70_XStoreIsAvailabilityPurchasable)},
    {71, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl3_slot71_XStoreAcquireLicenseForDurablesAsync)},
    {72, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl3_slot72_XStoreAcquireLicenseForDurablesResult)},
};
static const WrapperEntry wrappers_IXStoreImpl4[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot3_XStoreCreateContext)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot4_XStoreCloseContextHandle)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot5_XStoreQueryAssociatedProductsAsync)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot6_XStoreQueryAssociatedProductsResult)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot7_XStoreQueryProductsAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot8_XStoreQueryProductsResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot9_XStoreQueryEntitledProductsAsync)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot10_XStoreQueryEntitledProductsResult)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot11_XStoreQueryProductForCurrentGameAsync)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot12_XStoreQueryProductForCurrentGameResult)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot13_XStoreQueryProductForPackageAsync)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot14_XStoreQueryProductForPackageResult)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot15_XStoreEnumerateProductsQuery)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot16_XStoreProductsQueryHasMorePages)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot17_XStoreProductsQueryNextPageAsync)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot18_XStoreProductsQueryNextPageResult)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot19_XStoreCloseProductsQueryHandle)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot20_XStoreAcquireLicenseForPackageAsync)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot21_XStoreAcquireLicenseForPackageResult)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot22_XStoreIsLicenseValid)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot23_XStoreCloseLicenseHandle)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot24_XStoreCanAcquireLicenseForStoreIdAsync)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot25_XStoreCanAcquireLicenseForStoreIdResult)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot26_XStoreCanAcquireLicenseForPackageAsync)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot27_XStoreCanAcquireLicenseForPackageResult)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot28_XStoreQueryGameLicenseAsync)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot29_XStoreQueryGameLicenseResult)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot30_XStoreQueryAddOnLicensesAsync)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot31_XStoreQueryAddOnLicensesResultCount)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot32_XStoreQueryAddOnLicensesResult)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot33_XStoreQueryConsumableBalanceRemainingAsync)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot34_XStoreQueryConsumableBalanceRemainingResult)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot35_XStoreReportConsumableFulfillmentAsync)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot36_XStoreReportConsumableFulfillmentResult)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot37_XStoreGetUserCollectionsIdAsync)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot38_XStoreGetUserCollectionsIdResultSize)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot39_XStoreGetUserCollectionsIdResult)},
    {40, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot40_XStoreGetUserPurchaseIdAsync)},
    {41, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot41_XStoreGetUserPurchaseIdResultSize)},
    {42, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot42_XStoreGetUserPurchaseIdResult)},
    {43, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot43_XStoreQueryLicenseTokenAsync)},
    {44, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot44_XStoreQueryLicenseTokenResultSize)},
    {45, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot45_XStoreQueryLicenseTokenResult)},
    {49, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot49_XStoreShowPurchaseUIAsync)},
    {50, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot50_XStoreShowPurchaseUIResult)},
    {51, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot51_XStoreShowRateAndReviewUIAsync)},
    {52, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot52_XStoreShowRateAndReviewUIResult)},
    {53, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot53_XStoreShowRedeemTokenUIAsync)},
    {54, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot54_XStoreShowRedeemTokenUIResult)},
    {55, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot55_XStoreQueryGameAndDlcPackageUpdatesAsync)},
    {56, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot56_XStoreQueryGameAndDlcPackageUpdatesResultCount)},
    {57, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot57_XStoreQueryGameAndDlcPackageUpdatesResult)},
    {58, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot58_XStoreDownloadPackageUpdatesAsync)},
    {59, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot59_XStoreDownloadPackageUpdatesResult)},
    {60, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot60_XStoreDownloadAndInstallPackageUpdatesAsync)},
    {61, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot61_XStoreDownloadAndInstallPackageUpdatesResult)},
    {62, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot62_XStoreDownloadAndInstallPackagesAsync)},
    {63, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot63_XStoreDownloadAndInstallPackagesResultCount)},
    {64, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot64_XStoreDownloadAndInstallPackagesResult)},
    {65, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot65_XStoreQueryPackageIdentifier)},
    {66, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot66_XStoreRegisterGameLicenseChanged)},
    {67, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot67_XStoreUnregisterGameLicenseChanged)},
    {68, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot68_XStoreRegisterPackageLicenseLost)},
    {69, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot69_XStoreUnregisterPackageLicenseLost)},
    {70, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl2_slot70_XStoreIsAvailabilityPurchasable)},
    {71, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl3_slot71_XStoreAcquireLicenseForDurablesAsync)},
    {72, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl3_slot72_XStoreAcquireLicenseForDurablesResult)},
    {73, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl4_slot73_XStoreShowAssociatedProductsUIAsync)},
    {74, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl4_slot74_XStoreShowAssociatedProductsUIResult)},
    {75, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl4_slot75_XStoreShowProductPageUIAsync)},
    {76, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl4_slot76_XStoreShowProductPageUIResult)},
};
static const WrapperEntry wrappers_IXStoreImpl5[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot3_XStoreCreateContext)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot4_XStoreCloseContextHandle)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot5_XStoreQueryAssociatedProductsAsync)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot6_XStoreQueryAssociatedProductsResult)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot7_XStoreQueryProductsAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot8_XStoreQueryProductsResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot9_XStoreQueryEntitledProductsAsync)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot10_XStoreQueryEntitledProductsResult)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot11_XStoreQueryProductForCurrentGameAsync)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot12_XStoreQueryProductForCurrentGameResult)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot13_XStoreQueryProductForPackageAsync)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot14_XStoreQueryProductForPackageResult)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot15_XStoreEnumerateProductsQuery)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot16_XStoreProductsQueryHasMorePages)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot17_XStoreProductsQueryNextPageAsync)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot18_XStoreProductsQueryNextPageResult)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot19_XStoreCloseProductsQueryHandle)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot20_XStoreAcquireLicenseForPackageAsync)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot21_XStoreAcquireLicenseForPackageResult)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot22_XStoreIsLicenseValid)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot23_XStoreCloseLicenseHandle)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot24_XStoreCanAcquireLicenseForStoreIdAsync)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot25_XStoreCanAcquireLicenseForStoreIdResult)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot26_XStoreCanAcquireLicenseForPackageAsync)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot27_XStoreCanAcquireLicenseForPackageResult)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot28_XStoreQueryGameLicenseAsync)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot29_XStoreQueryGameLicenseResult)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot30_XStoreQueryAddOnLicensesAsync)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot31_XStoreQueryAddOnLicensesResultCount)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot32_XStoreQueryAddOnLicensesResult)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot33_XStoreQueryConsumableBalanceRemainingAsync)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot34_XStoreQueryConsumableBalanceRemainingResult)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot35_XStoreReportConsumableFulfillmentAsync)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot36_XStoreReportConsumableFulfillmentResult)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot37_XStoreGetUserCollectionsIdAsync)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot38_XStoreGetUserCollectionsIdResultSize)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot39_XStoreGetUserCollectionsIdResult)},
    {40, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot40_XStoreGetUserPurchaseIdAsync)},
    {41, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot41_XStoreGetUserPurchaseIdResultSize)},
    {42, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot42_XStoreGetUserPurchaseIdResult)},
    {43, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot43_XStoreQueryLicenseTokenAsync)},
    {44, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot44_XStoreQueryLicenseTokenResultSize)},
    {45, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot45_XStoreQueryLicenseTokenResult)},
    {49, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot49_XStoreShowPurchaseUIAsync)},
    {50, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot50_XStoreShowPurchaseUIResult)},
    {51, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot51_XStoreShowRateAndReviewUIAsync)},
    {52, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot52_XStoreShowRateAndReviewUIResult)},
    {53, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot53_XStoreShowRedeemTokenUIAsync)},
    {54, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot54_XStoreShowRedeemTokenUIResult)},
    {55, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot55_XStoreQueryGameAndDlcPackageUpdatesAsync)},
    {56, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot56_XStoreQueryGameAndDlcPackageUpdatesResultCount)},
    {57, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot57_XStoreQueryGameAndDlcPackageUpdatesResult)},
    {58, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot58_XStoreDownloadPackageUpdatesAsync)},
    {59, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot59_XStoreDownloadPackageUpdatesResult)},
    {60, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot60_XStoreDownloadAndInstallPackageUpdatesAsync)},
    {61, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot61_XStoreDownloadAndInstallPackageUpdatesResult)},
    {62, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot62_XStoreDownloadAndInstallPackagesAsync)},
    {63, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot63_XStoreDownloadAndInstallPackagesResultCount)},
    {64, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot64_XStoreDownloadAndInstallPackagesResult)},
    {65, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot65_XStoreQueryPackageIdentifier)},
    {66, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot66_XStoreRegisterGameLicenseChanged)},
    {67, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot67_XStoreUnregisterGameLicenseChanged)},
    {68, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot68_XStoreRegisterPackageLicenseLost)},
    {69, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot69_XStoreUnregisterPackageLicenseLost)},
    {70, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl2_slot70_XStoreIsAvailabilityPurchasable)},
    {71, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl3_slot71_XStoreAcquireLicenseForDurablesAsync)},
    {72, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl3_slot72_XStoreAcquireLicenseForDurablesResult)},
    {73, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl4_slot73_XStoreShowAssociatedProductsUIAsync)},
    {74, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl4_slot74_XStoreShowAssociatedProductsUIResult)},
    {75, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl4_slot75_XStoreShowProductPageUIAsync)},
    {76, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl4_slot76_XStoreShowProductPageUIResult)},
    {77, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl5_slot77_XStoreQueryAssociatedProductsForStoreIdAsync)},
    {78, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl5_slot78_XStoreQueryAssociatedProductsForStoreIdResult)},
    {79, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl5_slot79_XStoreQueryPackageUpdatesAsync)},
    {80, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl5_slot80_XStoreQueryPackageUpdatesResultCount)},
    {81, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl5_slot81_XStoreQueryPackageUpdatesResult)},
};
static const WrapperEntry wrappers_IXStoreImpl6[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot3_XStoreCreateContext)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot4_XStoreCloseContextHandle)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot5_XStoreQueryAssociatedProductsAsync)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot6_XStoreQueryAssociatedProductsResult)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot7_XStoreQueryProductsAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot8_XStoreQueryProductsResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot9_XStoreQueryEntitledProductsAsync)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot10_XStoreQueryEntitledProductsResult)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot11_XStoreQueryProductForCurrentGameAsync)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot12_XStoreQueryProductForCurrentGameResult)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot13_XStoreQueryProductForPackageAsync)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot14_XStoreQueryProductForPackageResult)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot15_XStoreEnumerateProductsQuery)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot16_XStoreProductsQueryHasMorePages)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot17_XStoreProductsQueryNextPageAsync)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot18_XStoreProductsQueryNextPageResult)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot19_XStoreCloseProductsQueryHandle)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot20_XStoreAcquireLicenseForPackageAsync)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot21_XStoreAcquireLicenseForPackageResult)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot22_XStoreIsLicenseValid)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot23_XStoreCloseLicenseHandle)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot24_XStoreCanAcquireLicenseForStoreIdAsync)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot25_XStoreCanAcquireLicenseForStoreIdResult)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot26_XStoreCanAcquireLicenseForPackageAsync)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot27_XStoreCanAcquireLicenseForPackageResult)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot28_XStoreQueryGameLicenseAsync)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot29_XStoreQueryGameLicenseResult)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot30_XStoreQueryAddOnLicensesAsync)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot31_XStoreQueryAddOnLicensesResultCount)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot32_XStoreQueryAddOnLicensesResult)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot33_XStoreQueryConsumableBalanceRemainingAsync)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot34_XStoreQueryConsumableBalanceRemainingResult)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot35_XStoreReportConsumableFulfillmentAsync)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot36_XStoreReportConsumableFulfillmentResult)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot37_XStoreGetUserCollectionsIdAsync)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot38_XStoreGetUserCollectionsIdResultSize)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot39_XStoreGetUserCollectionsIdResult)},
    {40, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot40_XStoreGetUserPurchaseIdAsync)},
    {41, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot41_XStoreGetUserPurchaseIdResultSize)},
    {42, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot42_XStoreGetUserPurchaseIdResult)},
    {43, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot43_XStoreQueryLicenseTokenAsync)},
    {44, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot44_XStoreQueryLicenseTokenResultSize)},
    {45, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot45_XStoreQueryLicenseTokenResult)},
    {49, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot49_XStoreShowPurchaseUIAsync)},
    {50, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot50_XStoreShowPurchaseUIResult)},
    {51, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot51_XStoreShowRateAndReviewUIAsync)},
    {52, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot52_XStoreShowRateAndReviewUIResult)},
    {53, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot53_XStoreShowRedeemTokenUIAsync)},
    {54, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot54_XStoreShowRedeemTokenUIResult)},
    {55, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot55_XStoreQueryGameAndDlcPackageUpdatesAsync)},
    {56, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot56_XStoreQueryGameAndDlcPackageUpdatesResultCount)},
    {57, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot57_XStoreQueryGameAndDlcPackageUpdatesResult)},
    {58, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot58_XStoreDownloadPackageUpdatesAsync)},
    {59, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot59_XStoreDownloadPackageUpdatesResult)},
    {60, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot60_XStoreDownloadAndInstallPackageUpdatesAsync)},
    {61, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot61_XStoreDownloadAndInstallPackageUpdatesResult)},
    {62, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot62_XStoreDownloadAndInstallPackagesAsync)},
    {63, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot63_XStoreDownloadAndInstallPackagesResultCount)},
    {64, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot64_XStoreDownloadAndInstallPackagesResult)},
    {65, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot65_XStoreQueryPackageIdentifier)},
    {66, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot66_XStoreRegisterGameLicenseChanged)},
    {67, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot67_XStoreUnregisterGameLicenseChanged)},
    {68, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot68_XStoreRegisterPackageLicenseLost)},
    {69, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl_slot69_XStoreUnregisterPackageLicenseLost)},
    {70, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl2_slot70_XStoreIsAvailabilityPurchasable)},
    {71, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl3_slot71_XStoreAcquireLicenseForDurablesAsync)},
    {72, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl3_slot72_XStoreAcquireLicenseForDurablesResult)},
    {73, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl4_slot73_XStoreShowAssociatedProductsUIAsync)},
    {74, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl4_slot74_XStoreShowAssociatedProductsUIResult)},
    {75, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl4_slot75_XStoreShowProductPageUIAsync)},
    {76, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl4_slot76_XStoreShowProductPageUIResult)},
    {77, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl5_slot77_XStoreQueryAssociatedProductsForStoreIdAsync)},
    {78, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl5_slot78_XStoreQueryAssociatedProductsForStoreIdResult)},
    {79, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl5_slot79_XStoreQueryPackageUpdatesAsync)},
    {80, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl5_slot80_XStoreQueryPackageUpdatesResultCount)},
    {81, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl5_slot81_XStoreQueryPackageUpdatesResult)},
    {82, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl6_slot82_XStoreShowGiftingUIAsync)},
    {83, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXStoreImpl6_slot83_XStoreShowGiftingUIResult)},
};
static const WrapperEntry wrappers_IXSystemAnalyticsImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemAnalyticsImpl_slot3_XSystemGetAnalyticsInfo)},
};
static const WrapperEntry wrappers_IXSystemImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot3_XSystemGetConsoleId)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot4_XSystemGetXboxLiveSandboxId)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot5_XSystemGetAppSpecificDeviceId)},
};
static const WrapperEntry wrappers_IXSystemImpl2[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot3_XSystemGetConsoleId)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot4_XSystemGetXboxLiveSandboxId)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot5_XSystemGetAppSpecificDeviceId)},
};
static const WrapperEntry wrappers_IXSystemImpl3[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot3_XSystemGetConsoleId)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot4_XSystemGetXboxLiveSandboxId)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot5_XSystemGetAppSpecificDeviceId)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl3_slot6_XSystemHandleTrack)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl3_slot7_XSystemIsHandleValid)},
};
static const WrapperEntry wrappers_IXSystemImpl4[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot3_XSystemGetConsoleId)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot4_XSystemGetXboxLiveSandboxId)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot5_XSystemGetAppSpecificDeviceId)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl3_slot6_XSystemHandleTrack)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl3_slot7_XSystemIsHandleValid)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl4_slot8_XSystemAllowFullDownloadBandwidth)},
};
static const WrapperEntry wrappers_IXSystemImpl5[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot3_XSystemGetConsoleId)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot4_XSystemGetXboxLiveSandboxId)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl_slot5_XSystemGetAppSpecificDeviceId)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl3_slot6_XSystemHandleTrack)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl3_slot7_XSystemIsHandleValid)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXSystemImpl4_slot8_XSystemAllowFullDownloadBandwidth)},
};
static const WrapperEntry wrappers_IXThreadingImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot3_XAsyncGetStatus)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot4_XAsyncGetResultSize)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot5_XAsyncCancel)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot6_XAsyncRun)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot7_XAsyncBegin)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot9_XAsyncSchedule)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot10_XAsyncComplete)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot11_XAsyncGetResult)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot12_XTaskQueueCreate)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot13_XTaskQueueCreateComposite)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot14_XTaskQueueGetPort)},
    {15, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot15_XTaskQueueDuplicateHandle)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot16_XTaskQueueDispatch)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot17_XTaskQueueCloseHandle)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot18_XTaskQueueSubmitCallback)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot19_XTaskQueueSubmitDelayedCallback)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot20_XTaskQueueRegisterWaiter)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot21_XTaskQueueUnregisterWaiter)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot22_XTaskQueueTerminate)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot23_XTaskQueueRegisterMonitor)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot24_XTaskQueueUnregisterMonitor)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot25_XTaskQueueGetCurrentProcessTaskQueue)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot26_XTaskQueueSetCurrentProcessTaskQueue)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot27_XThreadSetTimeSensitive)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot29_XThreadAssertNotTimeSensitive)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXThreadingImpl_slot30_XThreadIsTimeSensitive)},
};
static const WrapperEntry wrappers_IXUserDeviceImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot3_XUserFindForDevice)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot4_XUserRegisterForDeviceAssociationChanged)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot5_XUserUnregisterForDeviceAssociationChanged)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot6_XUserGetDefaultAudioEndpointUtf16)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot7_XUserRegisterForDefaultAudioEndpointUtf16Changed)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot8_XUserUnregisterForDefaultAudioEndpointUtf16Changed)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot9_XUserFindControllerForUserWithUiAsync)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot10_XUserFindControllerForUserWithUiResult)},
};
static const WrapperEntry wrappers_IXUserDeviceImpl2[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot3_XUserFindForDevice)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot4_XUserRegisterForDeviceAssociationChanged)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot5_XUserUnregisterForDeviceAssociationChanged)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot6_XUserGetDefaultAudioEndpointUtf16)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot7_XUserRegisterForDefaultAudioEndpointUtf16Changed)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot8_XUserUnregisterForDefaultAudioEndpointUtf16Changed)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot9_XUserFindControllerForUserWithUiAsync)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserDeviceImpl_slot10_XUserFindControllerForUserWithUiResult)},
};
static const WrapperEntry wrappers_IXUserGamertagImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserGamertagImpl_slot3_XUserGetGamertag)},
};
static const WrapperEntry wrappers_IXUserImpl[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot3_XUserDuplicateHandle)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot4_XUserCloseHandle)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot5_XUserCompare)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot6_XUserGetMaxUsers)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot7_XUserAddAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot8_XUserAddResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot9_XUserGetLocalId)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot10_XUserFindUserByLocalId)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot11_XUserGetId)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot12_XUserFindUserById)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot13_XUserGetIsGuest)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot14_XUserGetState)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot16_XUserGetGamerPictureAsync)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot17_XUserGetGamerPictureResultSize)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot18_XUserGetGamerPictureResult)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot19_XUserGetAgeGroup)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot20_XUserCheckPrivilege)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot21_XUserResolvePrivilegeWithUiAsync)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot22_XUserResolvePrivilegeWithUiResult)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot23_XUserGetTokenAndSignatureAsync)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot24_XUserGetTokenAndSignatureResultSize)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot25_XUserGetTokenAndSignatureResult)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot26_XUserGetTokenAndSignatureUtf16Async)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot27_XUserGetTokenAndSignatureUtf16ResultSize)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot28_XUserGetTokenAndSignatureUtf16Result)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot29_XUserResolveIssueWithUiAsync)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot30_XUserResolveIssueWithUiResult)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot31_XUserResolveIssueWithUiUtf16Async)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot32_XUserResolveIssueWithUiUtf16Result)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot33_XUserRegisterForChangeEvent)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot34_XUserUnregisterForChangeEvent)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot35_XUserGetSignOutDeferral)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot36_XUserCloseSignOutDeferralHandle)},
};
static const WrapperEntry wrappers_IXUserImpl2[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot3_XUserDuplicateHandle)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot4_XUserCloseHandle)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot5_XUserCompare)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot6_XUserGetMaxUsers)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot7_XUserAddAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot8_XUserAddResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot9_XUserGetLocalId)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot10_XUserFindUserByLocalId)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot11_XUserGetId)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot12_XUserFindUserById)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot13_XUserGetIsGuest)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot14_XUserGetState)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot16_XUserGetGamerPictureAsync)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot17_XUserGetGamerPictureResultSize)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot18_XUserGetGamerPictureResult)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot19_XUserGetAgeGroup)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot20_XUserCheckPrivilege)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot21_XUserResolvePrivilegeWithUiAsync)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot22_XUserResolvePrivilegeWithUiResult)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot23_XUserGetTokenAndSignatureAsync)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot24_XUserGetTokenAndSignatureResultSize)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot25_XUserGetTokenAndSignatureResult)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot26_XUserGetTokenAndSignatureUtf16Async)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot27_XUserGetTokenAndSignatureUtf16ResultSize)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot28_XUserGetTokenAndSignatureUtf16Result)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot29_XUserResolveIssueWithUiAsync)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot30_XUserResolveIssueWithUiResult)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot31_XUserResolveIssueWithUiUtf16Async)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot32_XUserResolveIssueWithUiUtf16Result)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot33_XUserRegisterForChangeEvent)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot34_XUserUnregisterForChangeEvent)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot35_XUserGetSignOutDeferral)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot36_XUserCloseSignOutDeferralHandle)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl2_slot37_XUserAddByIdWithUiAsync)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl2_slot38_XUserAddByIdWithUiResult)},
};
static const WrapperEntry wrappers_IXUserImpl3[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot3_XUserDuplicateHandle)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot4_XUserCloseHandle)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot5_XUserCompare)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot6_XUserGetMaxUsers)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot7_XUserAddAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot8_XUserAddResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot9_XUserGetLocalId)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot10_XUserFindUserByLocalId)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot11_XUserGetId)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot12_XUserFindUserById)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot13_XUserGetIsGuest)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot14_XUserGetState)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot16_XUserGetGamerPictureAsync)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot17_XUserGetGamerPictureResultSize)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot18_XUserGetGamerPictureResult)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot19_XUserGetAgeGroup)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot20_XUserCheckPrivilege)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot21_XUserResolvePrivilegeWithUiAsync)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot22_XUserResolvePrivilegeWithUiResult)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot23_XUserGetTokenAndSignatureAsync)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot24_XUserGetTokenAndSignatureResultSize)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot25_XUserGetTokenAndSignatureResult)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot26_XUserGetTokenAndSignatureUtf16Async)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot27_XUserGetTokenAndSignatureUtf16ResultSize)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot28_XUserGetTokenAndSignatureUtf16Result)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot29_XUserResolveIssueWithUiAsync)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot30_XUserResolveIssueWithUiResult)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot31_XUserResolveIssueWithUiUtf16Async)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot32_XUserResolveIssueWithUiUtf16Result)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot33_XUserRegisterForChangeEvent)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot34_XUserUnregisterForChangeEvent)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot35_XUserGetSignOutDeferral)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot36_XUserCloseSignOutDeferralHandle)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl2_slot37_XUserAddByIdWithUiAsync)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl2_slot38_XUserAddByIdWithUiResult)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl3_slot39_XUserGetMsaTokenSilentlyAsync)},
    {40, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl3_slot40_XUserGetMsaTokenSilentlyResult)},
    {41, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl3_slot41_XUserGetMsaTokenSilentlyResultSize)},
};
static const WrapperEntry wrappers_IXUserImpl4[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot3_XUserDuplicateHandle)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot4_XUserCloseHandle)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot5_XUserCompare)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot6_XUserGetMaxUsers)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot7_XUserAddAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot8_XUserAddResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot9_XUserGetLocalId)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot10_XUserFindUserByLocalId)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot11_XUserGetId)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot12_XUserFindUserById)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot13_XUserGetIsGuest)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot14_XUserGetState)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot16_XUserGetGamerPictureAsync)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot17_XUserGetGamerPictureResultSize)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot18_XUserGetGamerPictureResult)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot19_XUserGetAgeGroup)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot20_XUserCheckPrivilege)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot21_XUserResolvePrivilegeWithUiAsync)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot22_XUserResolvePrivilegeWithUiResult)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot23_XUserGetTokenAndSignatureAsync)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot24_XUserGetTokenAndSignatureResultSize)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot25_XUserGetTokenAndSignatureResult)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot26_XUserGetTokenAndSignatureUtf16Async)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot27_XUserGetTokenAndSignatureUtf16ResultSize)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot28_XUserGetTokenAndSignatureUtf16Result)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot29_XUserResolveIssueWithUiAsync)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot30_XUserResolveIssueWithUiResult)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot31_XUserResolveIssueWithUiUtf16Async)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot32_XUserResolveIssueWithUiUtf16Result)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot33_XUserRegisterForChangeEvent)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot34_XUserUnregisterForChangeEvent)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot35_XUserGetSignOutDeferral)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot36_XUserCloseSignOutDeferralHandle)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl2_slot37_XUserAddByIdWithUiAsync)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl2_slot38_XUserAddByIdWithUiResult)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl3_slot39_XUserGetMsaTokenSilentlyAsync)},
    {40, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl3_slot40_XUserGetMsaTokenSilentlyResult)},
    {41, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl3_slot41_XUserGetMsaTokenSilentlyResultSize)},
    {42, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl4_slot42_XUserIsStoreUser)},
};
static const WrapperEntry wrappers_IXUserImpl5[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot3_XUserDuplicateHandle)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot4_XUserCloseHandle)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot5_XUserCompare)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot6_XUserGetMaxUsers)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot7_XUserAddAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot8_XUserAddResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot9_XUserGetLocalId)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot10_XUserFindUserByLocalId)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot11_XUserGetId)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot12_XUserFindUserById)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot13_XUserGetIsGuest)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot14_XUserGetState)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot16_XUserGetGamerPictureAsync)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot17_XUserGetGamerPictureResultSize)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot18_XUserGetGamerPictureResult)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot19_XUserGetAgeGroup)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot20_XUserCheckPrivilege)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot21_XUserResolvePrivilegeWithUiAsync)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot22_XUserResolvePrivilegeWithUiResult)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot23_XUserGetTokenAndSignatureAsync)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot24_XUserGetTokenAndSignatureResultSize)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot25_XUserGetTokenAndSignatureResult)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot26_XUserGetTokenAndSignatureUtf16Async)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot27_XUserGetTokenAndSignatureUtf16ResultSize)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot28_XUserGetTokenAndSignatureUtf16Result)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot29_XUserResolveIssueWithUiAsync)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot30_XUserResolveIssueWithUiResult)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot31_XUserResolveIssueWithUiUtf16Async)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot32_XUserResolveIssueWithUiUtf16Result)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot33_XUserRegisterForChangeEvent)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot34_XUserUnregisterForChangeEvent)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot35_XUserGetSignOutDeferral)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot36_XUserCloseSignOutDeferralHandle)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl2_slot37_XUserAddByIdWithUiAsync)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl2_slot38_XUserAddByIdWithUiResult)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl3_slot39_XUserGetMsaTokenSilentlyAsync)},
    {40, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl3_slot40_XUserGetMsaTokenSilentlyResult)},
    {41, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl3_slot41_XUserGetMsaTokenSilentlyResultSize)},
    {42, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl4_slot42_XUserIsStoreUser)},
    {43, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl5_slot43_XUserPlatformRemoteConnectSetEventHandlers)},
    {44, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl5_slot44_XUserPlatformRemoteConnectCancelPrompt)},
    {45, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl5_slot45_XUserPlatformSpopPromptSetEventHandlers)},
    {46, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl5_slot46_XUserPlatformSpopPromptComplete)},
};
static const WrapperEntry wrappers_IXUserImpl6[] = {
    {3, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot3_XUserDuplicateHandle)},
    {4, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot4_XUserCloseHandle)},
    {5, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot5_XUserCompare)},
    {6, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot6_XUserGetMaxUsers)},
    {7, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot7_XUserAddAsync)},
    {8, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot8_XUserAddResult)},
    {9, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot9_XUserGetLocalId)},
    {10, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot10_XUserFindUserByLocalId)},
    {11, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot11_XUserGetId)},
    {12, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot12_XUserFindUserById)},
    {13, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot13_XUserGetIsGuest)},
    {14, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot14_XUserGetState)},
    {16, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot16_XUserGetGamerPictureAsync)},
    {17, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot17_XUserGetGamerPictureResultSize)},
    {18, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot18_XUserGetGamerPictureResult)},
    {19, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot19_XUserGetAgeGroup)},
    {20, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot20_XUserCheckPrivilege)},
    {21, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot21_XUserResolvePrivilegeWithUiAsync)},
    {22, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot22_XUserResolvePrivilegeWithUiResult)},
    {23, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot23_XUserGetTokenAndSignatureAsync)},
    {24, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot24_XUserGetTokenAndSignatureResultSize)},
    {25, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot25_XUserGetTokenAndSignatureResult)},
    {26, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot26_XUserGetTokenAndSignatureUtf16Async)},
    {27, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot27_XUserGetTokenAndSignatureUtf16ResultSize)},
    {28, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot28_XUserGetTokenAndSignatureUtf16Result)},
    {29, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot29_XUserResolveIssueWithUiAsync)},
    {30, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot30_XUserResolveIssueWithUiResult)},
    {31, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot31_XUserResolveIssueWithUiUtf16Async)},
    {32, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot32_XUserResolveIssueWithUiUtf16Result)},
    {33, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot33_XUserRegisterForChangeEvent)},
    {34, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot34_XUserUnregisterForChangeEvent)},
    {35, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot35_XUserGetSignOutDeferral)},
    {36, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl_slot36_XUserCloseSignOutDeferralHandle)},
    {37, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl2_slot37_XUserAddByIdWithUiAsync)},
    {38, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl2_slot38_XUserAddByIdWithUiResult)},
    {39, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl3_slot39_XUserGetMsaTokenSilentlyAsync)},
    {40, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl3_slot40_XUserGetMsaTokenSilentlyResult)},
    {41, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl3_slot41_XUserGetMsaTokenSilentlyResultSize)},
    {42, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl4_slot42_XUserIsStoreUser)},
    {43, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl5_slot43_XUserPlatformRemoteConnectSetEventHandlers)},
    {44, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl5_slot44_XUserPlatformRemoteConnectCancelPrompt)},
    {45, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl5_slot45_XUserPlatformSpopPromptSetEventHandlers)},
    {46, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl5_slot46_XUserPlatformSpopPromptComplete)},
    {47, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl6_slot47_XUserIsSignOutPresent)},
    {48, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl6_slot48_XUserSignOutAsync)},
    {49, reinterpret_cast<WrapperAddress>(&xgrtrace_wrap_IXUserImpl6_slot49_XUserSignOutResult)},
};

WrapperAddress WrapperFor(const InterfaceMetadata &interface_metadata, std::uint32_t slot)
{
    switch (interface_metadata.interface_index)
    {
    case 0: for (const auto &entry : wrappers_IXAccessibilityImpl) if (entry.slot == slot) return entry.address; break;
    case 1: for (const auto &entry : wrappers_IXAccessibilityImpl2) if (entry.slot == slot) return entry.address; break;
    case 2: for (const auto &entry : wrappers_IXAppCaptureImpl) if (entry.slot == slot) return entry.address; break;
    case 3: for (const auto &entry : wrappers_IXAppCaptureImpl2) if (entry.slot == slot) return entry.address; break;
    case 4: for (const auto &entry : wrappers_IXAppCaptureImpl3) if (entry.slot == slot) return entry.address; break;
    case 5: for (const auto &entry : wrappers_IXAppCaptureImpl4) if (entry.slot == slot) return entry.address; break;
    case 6: for (const auto &entry : wrappers_IXAppCaptureMetadataImpl) if (entry.slot == slot) return entry.address; break;
    case 7: for (const auto &entry : wrappers_IXDisplayImpl) if (entry.slot == slot) return entry.address; break;
    case 8: for (const auto &entry : wrappers_IXErrorImpl) if (entry.slot == slot) return entry.address; break;
    case 9: for (const auto &entry : wrappers_IXGameActivationImpl) if (entry.slot == slot) return entry.address; break;
    case 10: for (const auto &entry : wrappers_IXGameEventImpl) if (entry.slot == slot) return entry.address; break;
    case 11: for (const auto &entry : wrappers_IXGameImpl) if (entry.slot == slot) return entry.address; break;
    case 12: for (const auto &entry : wrappers_IXGameImpl2) if (entry.slot == slot) return entry.address; break;
    case 13: for (const auto &entry : wrappers_IXGameImpl3) if (entry.slot == slot) return entry.address; break;
    case 14: for (const auto &entry : wrappers_IXGameInviteImpl) if (entry.slot == slot) return entry.address; break;
    case 15: for (const auto &entry : wrappers_IXGameInviteImpl2) if (entry.slot == slot) return entry.address; break;
    case 16: for (const auto &entry : wrappers_IXGameProtocolImpl) if (entry.slot == slot) return entry.address; break;
    case 17: for (const auto &entry : wrappers_IXGameRuntimeFeatureImpl) if (entry.slot == slot) return entry.address; break;
    case 18: for (const auto &entry : wrappers_IXGameSaveImpl) if (entry.slot == slot) return entry.address; break;
    case 19: for (const auto &entry : wrappers_IXGameSaveImpl2) if (entry.slot == slot) return entry.address; break;
    case 20: for (const auto &entry : wrappers_IXGameSaveImpl3) if (entry.slot == slot) return entry.address; break;
    case 21: for (const auto &entry : wrappers_IXGameStreamingImpl) if (entry.slot == slot) return entry.address; break;
    case 22: for (const auto &entry : wrappers_IXGameStreamingImpl2) if (entry.slot == slot) return entry.address; break;
    case 23: for (const auto &entry : wrappers_IXGameStreamingImpl3) if (entry.slot == slot) return entry.address; break;
    case 24: for (const auto &entry : wrappers_IXGameUiImpl) if (entry.slot == slot) return entry.address; break;
    case 25: for (const auto &entry : wrappers_IXGameUiImpl2) if (entry.slot == slot) return entry.address; break;
    case 26: for (const auto &entry : wrappers_IXGameUiImpl3) if (entry.slot == slot) return entry.address; break;
    case 27: for (const auto &entry : wrappers_IXGameUiImpl4) if (entry.slot == slot) return entry.address; break;
    case 28: for (const auto &entry : wrappers_IXLauncherImpl) if (entry.slot == slot) return entry.address; break;
    case 29: for (const auto &entry : wrappers_IXNetworkingImpl) if (entry.slot == slot) return entry.address; break;
    case 30: for (const auto &entry : wrappers_IXNetworkingImpl2) if (entry.slot == slot) return entry.address; break;
    case 31: for (const auto &entry : wrappers_IXPackageImpl) if (entry.slot == slot) return entry.address; break;
    case 32: for (const auto &entry : wrappers_IXPackageImpl2) if (entry.slot == slot) return entry.address; break;
    case 33: for (const auto &entry : wrappers_IXPackageImpl3) if (entry.slot == slot) return entry.address; break;
    case 34: for (const auto &entry : wrappers_IXPackageImpl4) if (entry.slot == slot) return entry.address; break;
    case 35: for (const auto &entry : wrappers_IXPersistentLocalStorageImpl) if (entry.slot == slot) return entry.address; break;
    case 36: for (const auto &entry : wrappers_IXPersistentLocalStorageImpl2) if (entry.slot == slot) return entry.address; break;
    case 37: for (const auto &entry : wrappers_IXPersistentLocalStorageImpl3) if (entry.slot == slot) return entry.address; break;
    case 38: for (const auto &entry : wrappers_IXStoreImpl) if (entry.slot == slot) return entry.address; break;
    case 39: for (const auto &entry : wrappers_IXStoreImpl2) if (entry.slot == slot) return entry.address; break;
    case 40: for (const auto &entry : wrappers_IXStoreImpl3) if (entry.slot == slot) return entry.address; break;
    case 41: for (const auto &entry : wrappers_IXStoreImpl4) if (entry.slot == slot) return entry.address; break;
    case 42: for (const auto &entry : wrappers_IXStoreImpl5) if (entry.slot == slot) return entry.address; break;
    case 43: for (const auto &entry : wrappers_IXStoreImpl6) if (entry.slot == slot) return entry.address; break;
    case 44: for (const auto &entry : wrappers_IXSystemAnalyticsImpl) if (entry.slot == slot) return entry.address; break;
    case 45: for (const auto &entry : wrappers_IXSystemImpl) if (entry.slot == slot) return entry.address; break;
    case 46: for (const auto &entry : wrappers_IXSystemImpl2) if (entry.slot == slot) return entry.address; break;
    case 47: for (const auto &entry : wrappers_IXSystemImpl3) if (entry.slot == slot) return entry.address; break;
    case 48: for (const auto &entry : wrappers_IXSystemImpl4) if (entry.slot == slot) return entry.address; break;
    case 49: for (const auto &entry : wrappers_IXSystemImpl5) if (entry.slot == slot) return entry.address; break;
    case 50: for (const auto &entry : wrappers_IXThreadingImpl) if (entry.slot == slot) return entry.address; break;
    case 51: for (const auto &entry : wrappers_IXUserDeviceImpl) if (entry.slot == slot) return entry.address; break;
    case 52: for (const auto &entry : wrappers_IXUserDeviceImpl2) if (entry.slot == slot) return entry.address; break;
    case 53: for (const auto &entry : wrappers_IXUserGamertagImpl) if (entry.slot == slot) return entry.address; break;
    case 54: for (const auto &entry : wrappers_IXUserImpl) if (entry.slot == slot) return entry.address; break;
    case 55: for (const auto &entry : wrappers_IXUserImpl2) if (entry.slot == slot) return entry.address; break;
    case 56: for (const auto &entry : wrappers_IXUserImpl3) if (entry.slot == slot) return entry.address; break;
    case 57: for (const auto &entry : wrappers_IXUserImpl4) if (entry.slot == slot) return entry.address; break;
    case 58: for (const auto &entry : wrappers_IXUserImpl5) if (entry.slot == slot) return entry.address; break;
    case 59: for (const auto &entry : wrappers_IXUserImpl6) if (entry.slot == slot) return entry.address; break;
    default: break;
    }
    return 0;
}

}
