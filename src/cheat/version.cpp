#include "version.hpp"

namespace Cheat
{
    const char* build_info::VersionString = "1.0.0.5";
    const int build_info::VersionInt = 1005;
    const char* build_info::BuildTime = __TIME__;
    const char* build_info::BuildDate = __DATE__;
}