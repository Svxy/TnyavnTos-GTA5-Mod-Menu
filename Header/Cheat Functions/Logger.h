#pragma once

enum LoggerMsgTypes
{
    LOGGER_INFO_MSG,
    LOGGER_WARNING_MSG,
    LOGGER_ERROR_MSG,
    LOGGER_FATAL_MSG,
    LOGGER_DBG_MSG
};

namespace Cheat
{
    namespace Logger
    {
        extern bool LoggerInitialized;
        extern std::string CheatLogFilePath;
        void Init();
        void LogMsg(LoggerMsgTypes Type, const char* Message, ...);
    }
}