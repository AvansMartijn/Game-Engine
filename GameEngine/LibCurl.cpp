#include "pch.h"
#include "LibCurl.h"
#include "AssetRegistry.h"
#include <iostream>
#include <string>
#include <cstring>

size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream)
{
	size_t written;
	written = fwrite(ptr, size, nmemb, stream);
	return written;
}

std::string LibCurl::PerformRequest(const std::string& url)
{
	std::string _s;
	FILE* fp;
	std::string prefPath = AssetRegistry::getInstance().getPrefPath("Mike", "Laptrop 2") + "ad.jpg";
	char outfilename[FILENAME_MAX];
	strcpy_s(outfilename, prefPath.c_str());

	std::unique_ptr<CURL, CurlDeleter> curl(curl_easy_init(), CurlDeleter());
	fopen_s(&fp, outfilename, "wb");	
	curl_easy_setopt(curl.get(), CURLOPT_HTTPGET, 1L);
	curl_easy_setopt(curl.get(), CURLOPT_SSL_VERIFYPEER, 0L);
	curl_easy_setopt(curl.get(), CURLOPT_SSL_VERIFYHOST, 0L);
	curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, fp);
	curl_easy_setopt(curl.get(), CURLOPT_URL, url.c_str());

	CURLcode res;
	res = curl_easy_perform(curl.get());
	if (res != CURLE_OK)
	{
		//throw std::runtime_error("Failed to fetch: " + url);
	}

	fclose(fp);

	return prefPath;
}

