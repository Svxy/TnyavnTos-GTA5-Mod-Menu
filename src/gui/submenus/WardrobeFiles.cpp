#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../game/features/wardrobe_loader.hpp"
#include "../../cheat/file_system.hpp"
#include <filesystem>

using namespace Cheat;
void GUI::Submenus::WardrobeFiles()
{
	int index = 0;
	GUI::Title("Saved Wardrobes");
	for (const auto& file : std::filesystem::directory_iterator(file_system::paths::WardrobesDir))
	{
		if (GUI::Option(file.path().stem().string(), ""))
		{
			auto status = Features::wardrobe_loader::Load(file.path().stem().string());
			if (status == Features::wardrobe_loader::status::SUCCESS)
				Game::notification::MinimapAdvanced((char*)"Loaded & applied successfully", (char*)"Textures", (char*)"AdvancedNotificationImage", false, 4, (char*)"Wardrobe", (char*)"", 0.5f, (char*)"");
			else if (status == Features::wardrobe_loader::status::OUTDATED)
				Game::notification::MinimapAdvanced((char*)"File is outdated, it must be resaved", (char*)"Textures", (char*)"AdvancedNotificationImage", false, 4, (char*)"Wardrobe", (char*)"", 0.5f, (char*)"");
			else if (status == Features::wardrobe_loader::status::PED_MISMATCH)
				Game::notification::MinimapAdvanced((char*)"Loaded but not applied as this Wardrobe is made for another Ped", (char*)"Textures", (char*)"AdvancedNotificationImage", false, 4, (char*)"Wardrobe", (char*)"", 0.5f, (char*)"");
		}
		index++;
	}
	if (!index)
		GUI::Break("No wardrobes have been saved");
}