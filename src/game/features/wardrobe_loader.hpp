#pragma once
#include <iostream>

namespace Cheat
{
	namespace Features
	{
		class wardrobe_loader
		{
		public:
			enum class status
			{
				SUCCESS,
				PED_ID_INVALID,
				OUTDATED,
				PED_MISMATCH,
				UNEXISTENT
			};
			static status Create(std::string Name);
			static status Load(std::string Name);
			static status Remove(std::string Name);
			static std::string currently_loaded;
		private:
			static const std::string version;
		};
	}
}