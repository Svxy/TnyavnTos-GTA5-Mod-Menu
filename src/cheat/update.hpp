#pragma once

namespace Cheat
{
	class update_check
	{
	public:
		static int GetLatest();
		static bool IsAvailable;
	private:
		static bool GithubReachable();
	};
}