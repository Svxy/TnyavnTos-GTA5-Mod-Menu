#include "../Header/Cheat Functions/FiberMain.h"

using namespace Cheat;
int HairColor;
int ComponentIDInt, DrawableIDInt, DrawableTextureIDInt, PaletteIDInt;
int PropComponentIDInt, PropDrawableIDInt, PropDrawableTextureIDInt;
void GUI::Submenus::Wardrobe()
{
	GUI::Title("Wardrobe");
	if (GUI::Option("Random Components", ""))
	{
		PED::SET_PED_RANDOM_COMPONENT_VARIATION(GameFunctions::PlayerPedID, false);
	}
	if (GUI::Option("Random Props", ""))
	{
		PED::SET_PED_RANDOM_PROPS(GameFunctions::PlayerPedID);
	}
	GUI::Break("Components", SELECTABLE_CENTER_TEXT);
	if (DrawableIDInt >= PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(GameFunctions::PlayerPedID, ComponentIDInt))
	{
		DrawableIDInt = 0;
		PED::SET_PED_COMPONENT_VARIATION(GameFunctions::PlayerPedID, ComponentIDInt, DrawableIDInt, DrawableTextureIDInt, PaletteIDInt);
	}
	if (DrawableTextureIDInt >= PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(GameFunctions::PlayerPedID, ComponentIDInt, DrawableIDInt))
	{
		DrawableTextureIDInt = 0;
		PED::SET_PED_COMPONENT_VARIATION(GameFunctions::PlayerPedID, ComponentIDInt, DrawableIDInt, DrawableTextureIDInt, PaletteIDInt);
	}
	GUI::StringVector("Component", { "Head", "Beards/Mask", "Hair", "Upper Body", "Lower Body", "Hands/Arms", "Shoes/Feet", "Accessories", "Miscellaneous Clothing", "Gear and equipment", "Overlays", "Miscellaneous" }, ComponentIDInt, "");	
	if (GUI::Int("Drawable", DrawableIDInt, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(GameFunctions::PlayerPedID, ComponentIDInt) - 1, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		PED::SET_PED_COMPONENT_VARIATION(GameFunctions::PlayerPedID, ComponentIDInt, DrawableIDInt, DrawableTextureIDInt, PaletteIDInt);
	}
	if (GUI::Int("Drawable Variation", DrawableTextureIDInt, 0, PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(GameFunctions::PlayerPedID, ComponentIDInt, DrawableIDInt) - 1, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		PED::SET_PED_COMPONENT_VARIATION(GameFunctions::PlayerPedID, ComponentIDInt, DrawableIDInt, DrawableTextureIDInt, PaletteIDInt);
	}
	if (GUI::Int("Palette", PaletteIDInt, 0, 3, 1, "Optional", SELECTABLE_RETURN_VALUE_CHANGE))
	{
		PED::SET_PED_COMPONENT_VARIATION(GameFunctions::PlayerPedID, ComponentIDInt, DrawableIDInt, DrawableTextureIDInt, PaletteIDInt);
	}
	if (GUI::Option("Clear", ""))
	{
		PED::SET_PED_DEFAULT_COMPONENT_VARIATION(GameFunctions::PlayerPedID);
	}
	GUI::Break("Props", SELECTABLE_CENTER_TEXT);
	if (PropDrawableIDInt >= PED::GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(GameFunctions::PlayerPedID, PropComponentIDInt))
	{
		PropDrawableIDInt = 0;
		PED::SET_PED_PROP_INDEX(GameFunctions::PlayerPedID, PropComponentIDInt, PropDrawableIDInt, PropDrawableTextureIDInt, true);
	}
	if (PropDrawableTextureIDInt >= PED::GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(GameFunctions::PlayerPedID, PropComponentIDInt, PropDrawableIDInt))
	{
		PropDrawableTextureIDInt = 0;
		PED::SET_PED_PROP_INDEX(GameFunctions::PlayerPedID, PropComponentIDInt, PropDrawableIDInt, PropDrawableTextureIDInt, true);
	}
	GUI::StringVector("Prop", { "Hat", "Glasses", "Ear", "Watch", "Bracelet" }, PropComponentIDInt, "");
	if (GUI::Int("Drawable", PropDrawableIDInt, 0, PED::GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(GameFunctions::PlayerPedID, PropComponentIDInt) - 1, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
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
		PED::SET_PED_PROP_INDEX(GameFunctions::PlayerPedID, ComponentIDTemp, PropDrawableIDInt, PropDrawableTextureIDInt, true);
	}
	if (GUI::Int("Drawable Variation", PropDrawableTextureIDInt, 0, PED::GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(GameFunctions::PlayerPedID, PropComponentIDInt, PropDrawableIDInt) - 1, 1, "", SELECTABLE_RETURN_VALUE_CHANGE))
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
		PED::SET_PED_PROP_INDEX(GameFunctions::PlayerPedID, ComponentIDTemp, PropDrawableIDInt, PropDrawableTextureIDInt, true);
	}
	if (GUI::Option("Clear", ""))
	{
		PED::CLEAR_ALL_PED_PROPS(GameFunctions::PlayerPedID);
	}
	GUI::Break("Hair", SELECTABLE_CENTER_TEXT);
	if (GUI::Int("Color", HairColor, 0, PED::_GET_NUM_HAIR_COLORS(), 1, "", SELECTABLE_DISABLE_SAVE | SELECTABLE_RETURN_VALUE_CHANGE))
	{
		PED::_SET_PED_HAIR_COLOR(GameFunctions::PlayerPedID, HairColor, 0);
	}
}