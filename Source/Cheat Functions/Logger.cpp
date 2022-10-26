#include "../Header/Cheat Functions/FiberMain.h"
#include "../../ThirdParty/color-console/color.hpp"

bool Cheat::Logger::LoggerInitialized = false;
std::string Cheat::Logger::CheatLogFilePath = Cheat::CheatFunctions::GetWindowsUserDocumentsFolderPath() + (std::string)"\\GTAV Cheat\\Logs\\" + Cheat::CheatFunctions::ReturnDateTimeFormatAsString("Main_%d_%m_%Y-%H_%M_%S.log");

void Cheat::Logger::Init()
{
    if (!AllocConsole() || !freopen("CONIN$", "r", stdin) || !freopen("CONOUT$", "w", stdout) ||
        !freopen("CONOUT$", "w", stderr) || !SetConsoleTitleA("GTAV Cheat") || SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS))
    {
        Logger::LogMsg(LOGGER_FATAL_MSG, "Failed to allocate console - %i", GetLastError());
    }

    std::string MessageString = "Version: " + (std::string)CHEAT_BUILD_NUMBER + " | Compile Date & Time: " + __DATE__ + " " + __TIME__ +
        Cheat::CheatFunctions::ReturnDateTimeFormatAsString(" | Load Date & Time: %b %e %Y %H:%M:%S")
        + "\nGitHub Repository: HatchesPls/GrandTheftAutoV-Cheat\n";
    std::cout << "Version: " << CHEAT_BUILD_NUMBER << std::endl;

    // Write text
    CheatFunctions::WriteToFile(CheatLogFilePath, MessageString, true);

    LoggerInitialized = true;
}

// Note: this function is NOT thread-safe at the moment - TODO
const std::vector<std::string> LogMsgTypeStrings = { " [INFO] ", " [WARN] ", " [ERR] ", " [FATAL] ", " [DBG] " };
void Cheat::Logger::LogMsg(LoggerMsgTypes Type, const char* Message, ...)
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
        std::string CurrentTime = CheatFunctions::ReturnDateTimeFormatAsString("[%H:%M:%S]").c_str();

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
            if (MessageBoxA(NULL, buf, "GTAV Cheat", MB_ICONSTOP | MB_OK | MB_SETFOREGROUND | MB_APPLMODAL) == IDOK)
            {
                std::exit(EXIT_FAILURE);
            }
        }
        else if (Type == LoggerMsgTypes::LOGGER_DBG_MSG)
        {
            FormattedMsg = CurrentTime + LogMsgTypeStrings[4] + buf + "\n";
            std::cout << CurrentTime << dye::grey(LogMsgTypeStrings[4]) << dye::grey(buf) << std::endl;
        }
        CheatFunctions::WriteToFile(CheatLogFilePath, FormattedMsg, true);
    }
}