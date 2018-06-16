#pragma once

#include "stdafx.h"
#include "APIHook.h"
#include "HookManager.h"

namespace Steam
{
	class ISteamHTTP_Hooks : CHookManager<ISteamHTTP>
	{

	public:
		ISteamHTTP_Hooks() = delete;
		ISteamHTTP_Hooks(ISteamHTTP* obj) : CHookManager<ISteamHTTP>(obj) {};

        		
		HOOK_DECL(CreateHTTPRequest, 0, HTTPRequestHandle, EHTTPMethod eHTTPRequestMethod, const char *pchAbsoluteURL)
		{
			Util::Debug::PrintLine("CreateHTTPRequest!");

			return CreateHTTPRequestOriginal(This, eHTTPRequestMethod, pchAbsoluteURL);
		}
				
		HOOK_DECL(SetHTTPRequestContextValue, 1, bool, HTTPRequestHandle hRequest, uint64 ulContextValue)
		{
			Util::Debug::PrintLine("SetHTTPRequestContextValue!");

			return SetHTTPRequestContextValueOriginal(This, hRequest, ulContextValue);
		}
				
		HOOK_DECL(SetHTTPRequestNetworkActivityTimeout, 2, bool, HTTPRequestHandle hRequest, uint32 unTimeoutSeconds)
		{
			Util::Debug::PrintLine("SetHTTPRequestNetworkActivityTimeout!");

			return SetHTTPRequestNetworkActivityTimeoutOriginal(This, hRequest, unTimeoutSeconds);
		}
				
		HOOK_DECL(SetHTTPRequestHeaderValue, 3, bool, HTTPRequestHandle hRequest, const char *pchHeaderName, const char *pchHeaderValue)
		{
			Util::Debug::PrintLine("SetHTTPRequestHeaderValue!");

			return SetHTTPRequestHeaderValueOriginal(This, hRequest, pchHeaderName, pchHeaderValue);
		}
				
		HOOK_DECL(SetHTTPRequestGetOrPostParameter, 4, bool, HTTPRequestHandle hRequest, const char *pchParamName, const char *pchParamValue)
		{
			Util::Debug::PrintLine("SetHTTPRequestGetOrPostParameter!");

			return SetHTTPRequestGetOrPostParameterOriginal(This, hRequest, pchParamName, pchParamValue);
		}
				
		HOOK_DECL(SendHTTPRequest, 5, bool, HTTPRequestHandle hRequest, SteamAPICall_t *pCallHandle)
		{
			Util::Debug::PrintLine("SendHTTPRequest!");

			return SendHTTPRequestOriginal(This, hRequest, pCallHandle);
		}
				
		HOOK_DECL(SendHTTPRequestAndStreamResponse, 6, bool, HTTPRequestHandle hRequest, SteamAPICall_t *pCallHandle)
		{
			Util::Debug::PrintLine("SendHTTPRequestAndStreamResponse!");

			return SendHTTPRequestAndStreamResponseOriginal(This, hRequest, pCallHandle);
		}
				
		HOOK_DECL(DeferHTTPRequest, 7, bool, HTTPRequestHandle hRequest)
		{
			Util::Debug::PrintLine("DeferHTTPRequest!");

			return DeferHTTPRequestOriginal(This, hRequest);
		}
				
		HOOK_DECL(PrioritizeHTTPRequest, 8, bool, HTTPRequestHandle hRequest)
		{
			Util::Debug::PrintLine("PrioritizeHTTPRequest!");

			return PrioritizeHTTPRequestOriginal(This, hRequest);
		}
				
		HOOK_DECL(GetHTTPResponseHeaderSize, 9, bool, HTTPRequestHandle hRequest, const char *pchHeaderName, uint32 *unResponseHeaderSize)
		{
			Util::Debug::PrintLine("GetHTTPResponseHeaderSize!");

			return GetHTTPResponseHeaderSizeOriginal(This, hRequest, pchHeaderName, unResponseHeaderSize);
		}
				
		HOOK_DECL(GetHTTPResponseHeaderValue, 10, bool, HTTPRequestHandle hRequest, const char *pchHeaderName, uint8 *pHeaderValueBuffer, uint32 unBufferSize)
		{
			Util::Debug::PrintLine("GetHTTPResponseHeaderValue!");

			return GetHTTPResponseHeaderValueOriginal(This, hRequest, pchHeaderName, pHeaderValueBuffer, unBufferSize);
		}
				
		HOOK_DECL(GetHTTPResponseBodySize, 11, bool, HTTPRequestHandle hRequest, uint32 *unBodySize)
		{
			Util::Debug::PrintLine("GetHTTPResponseBodySize!");

			return GetHTTPResponseBodySizeOriginal(This, hRequest, unBodySize);
		}
				
		HOOK_DECL(GetHTTPResponseBodyData, 12, bool, HTTPRequestHandle hRequest, uint8 *pBodyDataBuffer, uint32 unBufferSize)
		{
			Util::Debug::PrintLine("GetHTTPResponseBodyData!");

			return GetHTTPResponseBodyDataOriginal(This, hRequest, pBodyDataBuffer, unBufferSize);
		}
				
		HOOK_DECL(GetHTTPStreamingResponseBodyData, 13, bool, HTTPRequestHandle hRequest, uint32 cOffset, uint8 *pBodyDataBuffer, uint32 unBufferSize)
		{
			Util::Debug::PrintLine("GetHTTPStreamingResponseBodyData!");

			return GetHTTPStreamingResponseBodyDataOriginal(This, hRequest, cOffset, pBodyDataBuffer, unBufferSize);
		}
				
		HOOK_DECL(ReleaseHTTPRequest, 14, bool, HTTPRequestHandle hRequest)
		{
			Util::Debug::PrintLine("ReleaseHTTPRequest!");

			return ReleaseHTTPRequestOriginal(This, hRequest);
		}
				
		HOOK_DECL(GetHTTPDownloadProgressPct, 15, bool, HTTPRequestHandle hRequest, float *pflPercentOut)
		{
			Util::Debug::PrintLine("GetHTTPDownloadProgressPct!");

			return GetHTTPDownloadProgressPctOriginal(This, hRequest, pflPercentOut);
		}
				
		HOOK_DECL(SetHTTPRequestRawPostBody, 16, bool, HTTPRequestHandle hRequest, const char *pchContentType, uint8 *pubBody, uint32 unBodyLen)
		{
			Util::Debug::PrintLine("SetHTTPRequestRawPostBody!");

			return SetHTTPRequestRawPostBodyOriginal(This, hRequest, pchContentType, pubBody, unBodyLen);
		}
				
		HOOK_DECL(CreateCookieContainer, 17, HTTPCookieContainerHandle, bool bAllowResponsesToModify)
		{
			Util::Debug::PrintLine("CreateCookieContainer!");

			return CreateCookieContainerOriginal(This, bAllowResponsesToModify);
		}
				
		HOOK_DECL(ReleaseCookieContainer, 18, bool, HTTPCookieContainerHandle hCookieContainer)
		{
			Util::Debug::PrintLine("ReleaseCookieContainer!");

			return ReleaseCookieContainerOriginal(This, hCookieContainer);
		}
				
		HOOK_DECL(SetCookie, 19, bool, HTTPCookieContainerHandle hCookieContainer, const char *pchHost, const char *pchUrl, const char *pchCookie)
		{
			Util::Debug::PrintLine("SetCookie!");

			return SetCookieOriginal(This, hCookieContainer, pchHost, pchUrl, pchCookie);
		}
				
		HOOK_DECL(SetHTTPRequestCookieContainer, 20, bool, HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer)
		{
			Util::Debug::PrintLine("SetHTTPRequestCookieContainer!");

			return SetHTTPRequestCookieContainerOriginal(This, hRequest, hCookieContainer);
		}
				
		HOOK_DECL(SetHTTPRequestUserAgentInfo, 21, bool, HTTPRequestHandle hRequest, const char *pchUserAgentInfo)
		{
			Util::Debug::PrintLine("SetHTTPRequestUserAgentInfo!");

			return SetHTTPRequestUserAgentInfoOriginal(This, hRequest, pchUserAgentInfo);
		}
				
		HOOK_DECL(SetHTTPRequestRequiresVerifiedCertificate, 22, bool, HTTPRequestHandle hRequest, bool bRequireVerifiedCertificate)
		{
			Util::Debug::PrintLine("SetHTTPRequestRequiresVerifiedCertificate!");

			return SetHTTPRequestRequiresVerifiedCertificateOriginal(This, hRequest, bRequireVerifiedCertificate);
		}
				
		HOOK_DECL(SetHTTPRequestAbsoluteTimeoutMS, 23, bool, HTTPRequestHandle hRequest, uint32 unMilliseconds)
		{
			Util::Debug::PrintLine("SetHTTPRequestAbsoluteTimeoutMS!");

			return SetHTTPRequestAbsoluteTimeoutMSOriginal(This, hRequest, unMilliseconds);
		}
				
		HOOK_DECL(GetHTTPRequestWasTimedOut, 24, bool, HTTPRequestHandle hRequest, bool *pbWasTimedOut)
		{
			Util::Debug::PrintLine("GetHTTPRequestWasTimedOut!");

			return GetHTTPRequestWasTimedOutOriginal(This, hRequest, pbWasTimedOut);
		}
		
	};
}