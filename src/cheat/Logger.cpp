#include <filesystem>
#include "Logger.hpp"
#include "cheat.hpp"
#include "version.hpp"
#include "file_system.hpp"
#include <color.hpp>

using namespace Cheat;

bool Logger::LoggerInitialized = false;
std::string Logger::CheatLogFilePath = file_system::paths::LogDir + helper::ReturnDateTimeFormatAsString("\\Main_%d_%m_%Y-%H_%M_%S.log");

void Logger::Init()
{
    if (!AllocConsole() || !freopen("CONIN$", "r", stdin) || !freopen("CONOUT$", "w", stdout) ||
        !freopen("CONOUT$", "w", stderr) || !SetConsoleTitleA("TnyavnTos GTA 5 Mod Menu") || SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS))
    {
        Logger::LogMsg(LOGGER_FATAL_MSG, "Failed to allocate console - %i", GetLastError());
    }

    std::string MessageString = "Version: " + static_cast<std::string>(build_info::VersionString) + " | Compile Date & Time: " + build_info::BuildDate + " " + build_info::BuildTime +
        helper::ReturnDateTimeFormatAsString(" | Load Date & Time: %b %e %Y %H:%M:%S")
        + "\nGitHub Repository: HatchesPls/GrandTheftAutoV-Cheat\n";
    std::cout << "Version: " << build_info::VersionString << std::endl;

    // Write text
    file_system::write_file(CheatLogFilePath, MessageString);

    LoggerInitialized = true;

    // Cleanup main log files
    for (const auto& file : std::filesystem::directory_iterator(file_system::paths::LogDir))
    {
        struct stat result;
        if (stat(file.path().string().c_str(), &result) == 0)
        {
            auto CurrentEpoch = duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            auto FileEpoch = result.st_mtime; // Using st_mtime (last modified) instead of st_ctime (creation date) as the later changes when the file is recreated during a copy action

            // Delete files older than 24 hours
            if (CurrentEpoch - FileEpoch > 86400)
            {
                std::remove(file.path().string().c_str());
                Logger::LogMsg(LOGGER_DBG_MSG, "[LOGGER] Deleted outdated file: %s", file.path().filename().string().c_str());
            }
        }
    }
}

// Note: this function is NOT thread-safe at the moment - TODO
const std::vector<std::string> LogMsgTypeStrings = { " [INFO] ", " [WARN] ", " [ERR] ", " [FATAL] ", " [DBG] " };
void Logger::LogMsg(LoggerMsgTypes Type, const char* Message, ...)
{
    if (LoggerInitialized)
    {
        // Get message with additional arguments
        va_list args;
        va_start(args, Message);
        char buf[1024];
        vsnprintf_s(buf, sizeof(buf), Message, args);
        va_end(args);

        // Get current time formatted
        std::string CurrentTime = helper::ReturnDateTimeFormatAsString("[%H:%M:%S]").c_str();

        // Display & log message based on type
        std::string FormattedMsg;

        if (Type == LoggerMsgTypes::LOGGER_INFO_MSG)
        {
            FormattedMsg = CurrentTime + LogMsgTypeStrings[0] + buf + "\n";
            std::cout << CurrentTime << dye::green(LogMsgTypeStrings[0]) << buf << std::endl;
        }
        else if (Type == LoggerMsgTypes::LOGGER_WARNING_MSG)
        {
            FormattedMsg = CurrentTime + LogMsgTypeStrings[1] + buf + "\n";
            std::cout << CurrentTime << dye::yellow(LogMsgTypeStrings[1]) << buf << std::endl;
        }
        else if (Type == LoggerMsgTypes::LOGGER_ERROR_MSG)
        {
            FormattedMsg = CurrentTime + LogMsgTypeStrings[2] + buf + "\n";
            std::cout << CurrentTime << dye::red(LogMsgTypeStrings[2]) << buf << std::endl;
        }
        else if (Type == LoggerMsgTypes::LOGGER_FATAL_MSG)
        {
            FormattedMsg = CurrentTime + LogMsgTypeStrings[3] + buf + "\n";
            std::cout << CurrentTime << dye::red(LogMsgTypeStrings[3]) << buf << std::endl;
            if (MessageBoxA(NULL, buf, "TnyavnTos GTA 5 Mod Menu", MB_ICONSTOP | MB_OK | MB_SETFOREGROUND | MB_APPLMODAL) == IDOK)
            {
                std::exit(EXIT_FAILURE);
            }
        }
        else if (Type == LoggerMsgTypes::LOGGER_DBG_MSG)
        {
            FormattedMsg = CurrentTime + LogMsgTypeStrings[4] + buf + "\n";
            std::cout << CurrentTime << dye::grey(LogMsgTypeStrings[4]) << dye::grey(buf) << std::endl;
        }
        file_system::write_file(CheatLogFilePath, FormattedMsg);
    }
}