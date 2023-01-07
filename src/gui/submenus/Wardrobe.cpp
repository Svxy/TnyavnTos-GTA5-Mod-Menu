#include "submenus.hpp"
#include "../../cheat/cheat.hpp"
#include "../../game/game.hpp"
#include "../../game/features.hpp"
#include "../../game/notification.hpp"
#include "../../gui/GUI.hpp"
#include "../../gui/gui_controls.hpp"
#include "../../hooking/natives.hpp"
#include "../../game/features/wardrobe_loader.hpp"

using namespace Cheat;
using namespace Features;
int HairColor;
int ComponentIDInt, DrawableIDInt, DrawableTextureIDInt, PaletteIDInt;
int PropComponentIDInt, PropDrawableIDInt, PropDrawableTextureIDInt;
int UnloadStringVector = 0;
void GUI::Submenus::Wardrobe()
{
	GUI::Title("Wardrobe");
	GUI::MenuOption("Saved", Submenus::WardrobeFiles);
	if (!wardrobe_loader::currently_loaded.empty())
		GUI::Break("Current: ~c~" + wardrobe_loader::currently_loaded);
	else
		GUI::Break("Current: ~c~none");
	if (GUI::Option("Create", "Automatically loads the Wardrobe upon creation"))
	{
		std::string Input;
		if (Game::keyboard::get_input("Enter wardrobe name", Input, 1, 25) == Game::keyboard::input_status::SUCCESS)
		{
			if (wardrobe_loader::Create(Input) == wardrobe_loader::status::SUCCESS && wardrobe_loader::Load(Input) == wardrobe_loader::status::SUCCESS)
				Game::notification::MinimapAdvanced((char*)"Created & loaded successfully", (char*)"Textures", (char*)"AdvancedNotificationImage", false, 4, (char*)"Wardrobe", (char*)"", 0.5f, (char*)"");
		}
	}
	if (!wardrobe_loader::currently_loaded.empty())
	{
		if (GUI::Option("Resave", "Resave to current"))
		{
			if (wardrobe_loader::Create(wardrobe_loader::currently_loaded) == wardrobe_loader::status::SUCCESS)
				Game::notification::MinimapAdvanced((char*)"Resaved wardrobe", (char*)"Textures", (char*)"AdvancedNotificationImage", false, 4, (char*)"Wardrobe", (char*)"", 0.5f, (char*)"");
		}
		if (GUI::StringVector("Unload/Remove", { "Unload & Remove", "Unload only" }, UnloadStringVector, ""))
		{
			if (UnloadStringVector == 0)
			{
				if (wardrobe_loader::Remove(wardrobe_loader::currently_loaded) == wardrobe_loader::status::SUCCESS)
					Game::notification::MinimapAdvanced((char*)"Unloaded & removed", (char*)"Textures", (char*)"AdvancedNotificationImage", false, 4, (char*)"Wardrobe", (char*)"", 0.5f, (char*)"");
			}	
			else
			{
					wardrobe_loader::currently_loaded.clear();
					Game::notification::MinimapAdvanced((char*)"Unloaded", (char*)"Textures", (char*)"AdvancedNotificationImage", false, 4, (char*)"Wardrobe", (char*)"", 0.5f, (char*)"");
			}
		}
	}
	GUI::Break("Components", SELECTABLE_CENTER_TEXT);
	if (DrawableIDInt >= PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), ComponentIDInt))
	{
		DrawableIDInt = 0;
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), ComponentIDInt, DrawableIDInt, DrawableTextureIDInt, PaletteIDInt);
	}
	if (DrawableTextureIDInt >= PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(PLAYER::PLAYER_PED_ID(), ComponentIDInt, DrawableIDInt))
	{
		DrawableTextureIDInt = 0;
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), ComponentIDInt, DrawableIDInt, DrawableTextureIDInt, PaletteIDInt);
	}
	GUI::StringVector("Component", { "Head", "Beards/Mask", "Hair", "Upper Body", "Lower Body", "Hands/Arms", "Shoes/Feet", "Accessories", "Miscellaneous Clothing", "Gear and equipment", "Overlays", "Miscellaneous" }, ComponentIDInt, "", SELECTABLE_DISABLE_SAVE);
	if (GUI::Int("Drawable", DrawableIDInt, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), ComponentIDInt) - 1, 1, "", SELECTABLE_RETURN_VALUE_CHANGE | SELECTABLE_DISABLE_SAVE))
	{
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), ComponentIDInt, DrawableIDInt, DrawableTextureIDInt, PaletteIDInt);
	}
	if (GUI::Int("Drawable Variation", DrawableTextureIDInt, 0, PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(PLAYER::PLAYER_PED_ID(), ComponentIDInt, DrawableIDInt) - 1, 1, "", SELECTABLE_RETURN_VALUE_CHANGE | SELECTABLE_DISABLE_SAVE))
	{
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), ComponentIDInt, DrawableIDInt, DrawableTextureIDInt, PaletteIDInt);
	}
	if (GUI::Int("Palette", PaletteIDInt, 0, 3, 1, "Optional", SELECTABLE_RETURN_VALUE_CHANGE | SELECTABLE_DISABLE_SAVE))
	{
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), ComponentIDInt, DrawableIDInt, DrawableTextureIDInt, PaletteIDInt);
	}
	if (GUI::Option("Clear", ""))
	{
		PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
	}
	GUI::Break("Props", SELECTABLE_CENTER_TEXT);
	if (PropDrawableIDInt >= PED::GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), PropComponentIDInt))
	{
		PropDrawableIDInt = 0;
		PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), PropComponentIDInt, PropDrawableIDInt, PropDrawableTextureIDInt, true);
	}
	if (PropDrawableTextureIDInt >= PED::GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(PLAYER::PLAYER_PED_ID(), PropComponentIDInt, PropDrawableIDInt))
	{
		PropDrawableTextureIDInt = 0;
		PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), PropComponentIDInt, PropDrawableIDInt, PropDrawableTextureIDInt, true);
	}
	GUI::StringVector("Prop", { "Hat", "Glasses", "Ear", "Watch", "Bracelet" }, PropComponentIDInt, "", SELECTABLE_DISABLE_SAVE);
	if (GUI::Int("Drawable", PropDrawableIDInt, 0, PED::GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), PropComponentIDInt) - 1, 1, "", SELECTABLE_RETURN_VALUE_CHANGE | SELECTABLE_DISABLE_SAVE))
	{
		int ComponentIDTemp;
		if (PropComponentIDInt == 3)
		{
			ComponentIDTemp = 6;
		}
		else if (PropComponentIDInt == 4)
		{
			ComponentIDTemp = 7;
		}
		else
		{
			ComponentIDTemp = PropComponentIDInt;
		}
		PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), ComponentIDTemp, PropDrawableIDInt, PropDrawableTextureIDInt, true);
	}
	if (GUI::Int("Drawable Variation", PropDrawableTextureIDInt, 0, PED::GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(PLAYER::PLAYER_PED_ID(), PropComponentIDInt, PropDrawableIDInt) - 1, 1, "", SELECTABLE_RETURN_VALUE_CHANGE | SELECTABLE_DISABLE_SAVE))
	{
		int ComponentIDTemp;
		if (PropComponentIDInt == 3)
		{
			ComponentIDTemp = 6;
		}
		else if (PropComponentIDInt == 4)
		{
			ComponentIDTemp = 7;
		}
		else
		{
			ComponentIDTemp = PropComponentIDInt;
		}
		PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), ComponentIDTemp, PropDrawableIDInt, PropDrawableTextureIDInt, true);
	}
	if (GUI::Option("Clear", ""))
	{
		PED::CLEAR_ALL_PED_PROPS(PLAYER::PLAYER_PED_ID());
	}
	GUI::Break("Hair", SELECTABLE_CENTER_TEXT);
	if (GUI::Int("Color", HairColor, 0, PED::_GET_NUM_HAIR_COLORS(), 1, "Only works in GTA:O", SELECTABLE_DISABLE_SAVE | SELECTABLE_RETURN_VALUE_CHANGE))
	{
		PED::_SET_PED_HAIR_COLOR(PLAYER::PLAYER_PED_ID(), HairColor, 0);
	}
	GUI::Break("Miscellaneous", SELECTABLE_CENTER_TEXT);
	if (GUI::Option("Random Components", ""))
	{
		PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), false);
	}
	if (GUI::Option("Random Props", ""))
	{
		PED::SET_PED_RANDOM_PROPS(PLAYER::PLAYER_PED_ID());
	}
}