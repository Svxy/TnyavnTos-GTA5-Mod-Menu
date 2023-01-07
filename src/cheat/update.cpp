#include "update.hpp"
#include "cheat.hpp"
#include "Logger.hpp"
#include <iostream>
#include <Windows.h>
#include <WinINet.h>
#pragma comment(lib, "WinINet.lib")
#pragma comment(lib, "Winmm.lib")
#include <json/json.h>

namespace Cheat
{
	bool update_check::IsAvailable = false;
	int update_check::GetLatest()
	{
		// Let's make sure we can actually reach the Github API before doing anything fancy
		if (!GithubReachable())
		{
			Logger::LogMsg(LOGGER_DBG_MSG, "update_check::GetLatest(): api.github.com unreachable, check your network configuration");
			return NULL;
		}

		std::string VersionString;
		int VersionInt = NULL;
		std::wstring URL = L"https://api.github.com/repos/Svxy/TnyavnTos-GTA5-Mod-Menu/releases/latest";
		HINTERNET hopen = InternetOpen(L"GTAVCheat", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, NULL);
		if (hopen)
		{
			HINTERNET hinternet = InternetOpenUrl(hopen, URL.c_str(), NULL, 0, INTERNET_FLAG_NO_CACHE_WRITE | INTERNET_FLAG_SECURE, NULL);
			if (hinternet)
			{
				char tmp[2048 + 1];
				DWORD received = 0;
				std::string buffer;
				while (InternetReadFile(hinternet, tmp, 2048, &received) && received > 0)
				{
					if (!received) break;
					tmp[received] = '\0';
					buffer += (std::string)tmp;
				}

				Json::CharReaderBuilder CharBuilder;
				Json::Value JsonData;
				JSONCPP_STRING JsonError;
				const std::unique_ptr<Json::CharReader> reader(CharBuilder.newCharReader());

				if (reader->parse(buffer.c_str(), buffer.c_str() + buffer.length(), &JsonData, &JsonError))
				{
					VersionString = JsonData["name"].asString();
					helper::remove_chars(VersionString, "v.");
					VersionInt = helper::StringToInt(VersionString);
				}
				else
				{
					Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "update_check::GetLatest(): failed to parse JSON data. Error: %s", JsonError);
					return NULL;
				}
				InternetCloseHandle(hinternet);
			}
			InternetCloseHandle(hopen);
		}
		return VersionInt;
	}
	bool update_check::GithubReachable()
	{
		// InternetCheckConnection is deprecated but this will suffice
		if (InternetCheckConnectionA("https://api.github.com", FLAG_ICC_FORCE_CONNECTION, NULL))
			return true;
		return false;
	}
}