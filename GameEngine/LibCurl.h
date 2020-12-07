#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_LIBCURL __declspec(dllexport)
#else
#define GAMEENGINE_LIBCURL __declspec(dllimport)
#endif

#pragma once
#include <curl/curl.h>
#include <iostream>

class GAMEENGINE_LIBCURL LibCurl
{
public:
	std::string PerformRequest(const std::string& url);
	struct CurlDeleter {
		void operator()(CURL* curl) {
			if (curl) curl_easy_cleanup(curl);
		}
	};
};

