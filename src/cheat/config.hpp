#pragma once
#include <string>
#include <vector>
#include "file_system.hpp"
#include "Logger.hpp"
#include "../gui/GUI.hpp"
#include <any>

namespace Cheat
{
	class config
	{
	public:
		static void Load();
		static bool SelectableLoaded(std::string Selectable);
		static bool Loaded;
		static std::vector <std::string> LoadedSelectables;
		static void LoadBoolSelectables(std::string Selectable, bool& ReturnedBool);
		static void LoadIntSelectableState(std::string Selectable, int& ReturnedInt);
		static void LoadFloatSelectableState(std::string Selectable, float& ReturnedFloat);
		static void SaveSelectable(std::string Selectable, std::string OptionValue, bool IsSavable);
	private:
		static std::string GetSelectableDataFromConfig(std::string Selectable);
		static void SelectableLoadNotify(std::string Selectable);
	};
}