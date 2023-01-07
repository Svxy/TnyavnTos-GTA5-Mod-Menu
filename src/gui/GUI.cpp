#include "../cheat/fibermain.hpp"
#include "../cheat/cheat.hpp"
#include "../cheat/entry_point.hpp"
#include "../cheat/file_system.hpp"
#include "../cheat/version.hpp"
#include "../cheat/Logger.hpp"
#include "../hooking/globalhandle.hpp"
#include "../hooking/offsets.hpp"
#include "../hooking/natives.hpp"
#include "../game/notification.hpp"
#include "../game/data/game_data.hpp"

using namespace Cheat;

const float GUI::guiX_Default				= 0.15f;
const float GUI::guiY_Default				= 0.30f;
const float GUI::guiWidth_Default			= 0.25f;
const float GUI::SelectableInfoBoxX_Default	= 0.50f;
const float GUI::SelectableInfoBoxY_Default	= 0.850f;
float GUI::guiX								= 0.15f;
float GUI::guiY								= 0.30f;
float GUI::guiWidth							= 0.25f;
float GUI::SelectableInfoBoxX				= 0.50f;
float GUI::SelectableInfoBoxY				= 0.850f;
float GUI::SelectableHeight					= 0.040f;
bool GUI::ShowHeaderBackground				= true;
bool GUI::ShowHeaderTexture					= true;
bool GUI::DisableMenuGUIOpenCloseFade		= false;
bool GUI::HideGUIElements					= false;		// Prevents all GUI elements from being visible
bool GUI::MenuGUIHasBeenOpened				= false;		// Set when the Menu GUI has been opened at least once
bool GUI::CurrentSelectableIsSavable		= false;
bool GUI::RestorePreviousSubmenu			= true;
std::string GUI::CurrentSubmenu;
int GUI::maxVisOptions						= 11;
int GUI::currentOption						= 0;
int GUI::currentOptionVisible				= 0; // This has GUI::Break excluded
int GUI::previousOption						= 0;
int GUI::optionCount						= 0;
int GUI::optionCountVisible					= 0; // This has GUI::Break excluded
int GUI::TotalOptionsCount					= 0;
int GUI::menuLevel							= 0;
void* GUI::PreviousMenu						= nullptr;
void* GUI::currentMenu						= nullptr;
int GUI::PreviousMenuLevel					= 0;
int GUI::optionsArray						[1000];
void* GUI::menusArray						[1000];
                 
RGBA GUI::PrimaryColor						{ 0, 0, 255, 255 };
RGBAF GUI::TextColorAndFont					{ 255, 255, 255, 255, FontChaletLondon };
int GUI::SelectableTransparency				= 150;
int GUI::HeaderBackgroundTransparency		= 200;
int GUI::TitleAndEndTransparency			= 210;
int GUI::ToggleSelectableTransparency		= 255;
int GUI::HeaderTextureTransparency			= 255;
int GUI::EndSmallLogoTransparency			= 255;
int GUI::OnlinePlayerPictureTransparency	= 255;

int GUI::MenuArrowAnimationDelay			= 1000;

void GUI::Loop()
{
	// Draw menu bottom
	if (GUI::menuLevel > 0)
	{
		GUI::TotalOptionsCount = GUI::optionCount;
		float OptionCountPositionX = GUI::guiX - (GUI::guiWidth * 43 / 100);
		float BuildNumberPositionX = GUI::guiX + (GUI::guiWidth * 42 / 100);
		float OptionCountAndBuildNumberY, RectY, LogoSmall;
		if (GUI::optionCount >= GUI::maxVisOptions)
		{
			OptionCountAndBuildNumberY = GUI::guiY + ((GUI::maxVisOptions + 1) * SelectableHeight - 0.172f);
			RectY = GUI::guiY + ((GUI::maxVisOptions + 1) * SelectableHeight - 0.1585f);
			LogoSmall = GUI::guiY + ((GUI::maxVisOptions + 1) * SelectableHeight - 0.159f);
		}
		else if (GUI::optionCount > 0)
		{
			OptionCountAndBuildNumberY = GUI::guiY + (GUI::optionCount + 1) * SelectableHeight - 0.172f;
			RectY = GUI::guiY + (GUI::optionCount + 1) * SelectableHeight - 0.1585f;
			LogoSmall = GUI::guiY + ((GUI::optionCount + 1) * SelectableHeight - 0.159f);
		}

		if (GUI::currentOptionVisible != 0 && GUI::optionCountVisible != 0)
		{
			DrawTextInGame(std::to_string(GUI::currentOptionVisible) + "/" + std::to_string(GUI::optionCountVisible), TextColorAndFont, { OptionCountPositionX, OptionCountAndBuildNumberY }, { 0.30f, 0.30f }, true);
		}
		DrawTextInGame(build_info::VersionString, TextColorAndFont, { BuildNumberPositionX, OptionCountAndBuildNumberY }, { 0.30f, 0.30f }, true);
		DrawRectInGame({ 0, 0, 0, TitleAndEndTransparency }, { GUI::guiX, RectY }, { GUI::guiWidth, SelectableHeight });
		DrawSpriteInGame("Textures", "LogoSmall", GUI::guiX, LogoSmall, 0.030f, 0.045f, 0, GUI::PrimaryColor.r, GUI::PrimaryColor.g, GUI::PrimaryColor.b, EndSmallLogoTransparency);
	}
}

void GUI::MoveMenu(void* Submenu)
{
	GUI::menusArray[GUI::menuLevel] = GUI::currentMenu;
	GUI::optionsArray[GUI::menuLevel] = GUI::currentOption;
	GUI::menuLevel++;
	GUI::currentMenu = Submenu;
	GUI::currentOption = 1;
}

void GUI::CloseMenuGUI()
{
	GUI::PreviousMenu = GUI::currentMenu;
	GUI::PreviousMenuLevel = GUI::menuLevel;
	GUI::previousOption = GUI::currentOption;
	GUI::menuLevel = 0;
	GUI::currentMenu = GUI::menusArray[GUI::menuLevel];
	GUI::currentOption = GUI::optionsArray[GUI::menuLevel];
	if (gui_controls::DisableCursorNavigationWhenMenuGUIIsClosed)
	{
		if (gui_controls::cursor_nav_state)
		{
			gui_controls::toggle_cursor_nav_state();
		}
	}
}

void GUI::BackMenu()
{
	if (GUI::currentMenu == GUI::Submenus::Home)
	{
		CloseMenuGUI();
	}
	else
	{
		GUI::PreviousMenu = GUI::currentMenu;
		GUI::PreviousMenuLevel = GUI::menuLevel;
		GUI::previousOption = GUI::currentOption;
		GUI::menuLevel--;
		GUI::currentMenu = GUI::menusArray[GUI::menuLevel];
		GUI::currentOption = GUI::optionsArray[GUI::menuLevel];
	}
}

void GUI::AddPlayerInfoBoxTextEntry(std::string text, int Row1, int Row2, int Row3, int Row4)
{
	if (GUI::guiX < 0.55f)
	{
		if (Row1 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX + (GUI::guiWidth / 2) + 0.010f, GUI::guiY + (Row1 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
		else if (Row2 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX + (GUI::guiWidth / 2) + 0.105f, GUI::guiY + (Row2 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
		else if (Row3 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX + (GUI::guiWidth / 2) + 0.195f, GUI::guiY + (Row3 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
		else if (Row4 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX + (GUI::guiWidth / 2) + 0.265f, GUI::guiY + (Row4 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
	}
	else
	{
		if (Row1 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX - (GUI::guiWidth / 2) - 0.325f, GUI::guiY + (Row1 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
		else if (Row2 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX - (GUI::guiWidth / 2) - 0.255f, GUI::guiY + (Row2 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
		else if (Row3 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX - (GUI::guiWidth / 2) - 0.175f, GUI::guiY + (Row3 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
		else if (Row4 != NULL)
		{
			DrawTextInGame(text, TextColorAndFont, { guiX - (GUI::guiWidth / 2) - 0.070f, GUI::guiY + (Row4 * 0.020f) - 0.158f }, { 0.30f, 0.30f }, false);
		}
	}
}

void GUI::LoadTextureFile()
{
	Logger::LogMsg(LoggerMsgTypes::LOGGER_INFO_MSG, "Loading Custom Textures");
	if (!Features::NoTextureFileOverwrite)
	{
		remove(helper::StringToChar(file_system::paths::TextureFile));

		// Find and load the resource
		HRSRC hResource = FindResourceA(entry_point::module_handle, MAKEINTRESOURCEA(140), "CHEAT_DATA");
		if (!hResource) { goto Error; }
		HGLOBAL hFileResource = LoadResource(entry_point::module_handle, hResource);
		if (!hFileResource) { goto Error; }

		// Open and map this to a disk file
		LPVOID lpFile = LockResource(hFileResource);
		DWORD dwSize = SizeofResource(entry_point::module_handle, hResource);

		// Open the file and filemap
		HANDLE hFile = CreateFileA(helper::StringToChar(file_system::paths::TextureFile), GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		HANDLE hFileMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, dwSize, NULL);
		if (!hFileMap) { goto Error; }

		LPVOID lpAddress = MapViewOfFile(hFileMap, FILE_MAP_WRITE, 0, 0, 0);
		if (!lpAddress) { goto Error; }

		// Write the file
		CopyMemory(lpAddress, lpFile, dwSize);

		// Un-map the file and close the handles
		UnmapViewOfFile(lpAddress);
		CloseHandle(hFileMap);
		CloseHandle(hFile);
	}

	int textureID;
	if (std::filesystem::exists(file_system::paths::TextureFile))
	{
		GameHooking::texture_file_register(&textureID, helper::StringToChar(file_system::paths::TextureFile), true, "Textures.ytd", false);
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("Textures", false); // Ensure the custom textures are loaded by RAGE because we need them soon
		return;
	}
	else
	{
		goto Error;
	}

	//Error
Error:
	Game::notification::Minimap((char*)"~r~Failed to load Texture file");
	Logger::LogMsg(LoggerMsgTypes::LOGGER_DBG_MSG, "Failed to load Texture file; missing");
}

void GUI::DrawTextInGame(std::string text, RGBAF rgbaf, Vector2 position, Vector2_2 size, bool center, bool Outline)
{
	if (!GUI::HideGUIElements)
	{
		UI::SET_TEXT_CENTRE(center);
		UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
		UI::SET_TEXT_FONT(rgbaf.f);
		if (Outline) { UI::SET_TEXT_OUTLINE(); }
		UI::SET_TEXT_SCALE(size.w, size.h);
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(helper::StringToChar(text));
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(position.x, position.y, 0);
	}
}

void GUI::DrawSpriteInGame(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	if (!GUI::HideGUIElements)
	{
		if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture.c_str()))
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture.c_str(), false);
		}
		else
		{
			GRAPHICS::DRAW_SPRITE(Streamedtexture.c_str(), textureName.c_str(), x, y, width, height, rotation, r, g, b, a, false, 0);
		}
	}
}

void GUI::DrawRectInGame(RGBA rgba, Vector2 position, Vector2_2 size)
{
	if (!GUI::HideGUIElements)
	{
		GRAPHICS::DRAW_RECT(position.x, position.y, size.w, size.h, rgba.r, rgba.g, rgba.b, rgba.a, false);
	}
}

void GUI::ShowPlayerInformationBox(Player PlayerID)
{
	if (!Features::HidePlayerInformationBox)
	{
		//Definitions
		Ped SelectedPlayerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PlayerID);
		Game::entity::request_network_control(SelectedPlayerPed);

		//Draw Title and Background
		if (GUI::guiX < 0.54f)
		{
			GUI::DrawRectInGame(GUI::PrimaryColor, { guiX + (GUI::guiWidth / 2) + 0.166f, GUI::guiY + 0.014f }, { 0.32f, 0.31f }); //Main Background Rect
			GUI::DrawTextInGame("Player Information", { GUI::TextColorAndFont }, { guiX + (GUI::guiWidth / 2) + 0.155f, GUI::guiY - 0.170f }, { 0.50f, 0.37f }, true);
			GUI::DrawRectInGame({ 0, 0, 0, GUI::PrimaryColor.a }, { guiX + (GUI::guiWidth / 2) + 0.166f, GUI::guiY - 0.156f }, { 0.32f, 0.030f });
		}
		else
		{
			GUI::DrawRectInGame(GUI::PrimaryColor, { guiX - (GUI::guiWidth / 2) - 0.166f, GUI::guiY + 0.014f }, { 0.32f, 0.31f }); //Main Background Rect
			GUI::DrawTextInGame("Player Information", { GUI::TextColorAndFont }, { guiX - (GUI::guiWidth / 2) - 0.155f, GUI::guiY - 0.170f }, { 0.50f, 0.37f }, true);
			GUI::DrawRectInGame({ 0, 0, 0, GUI::PrimaryColor.a }, { guiX - (GUI::guiWidth / 2) - 0.166f,GUI::guiY - 0.156f }, { 0.32f, 0.030f });
		}


		
		//Text Entry's
		GUI::AddPlayerInfoBoxTextEntry("Name", 1);
		GUI::AddPlayerInfoBoxTextEntry(PLAYER::GET_PLAYER_NAME(PlayerID), NULL, 1);

		// Statistics
		GUI::AddPlayerInfoBoxTextEntry("Rank", 2);
		GUI::AddPlayerInfoBoxTextEntry("Money (cash)", 3);
		if (NETWORK::NETWORK_IS_SESSION_STARTED())
		{
			std::ostringstream PlayerRank;
			PlayerRank << globalHandle(GLOBAL_PLAYERSTAT_RANK[0]).At(PlayerID, GLOBAL_PLAYERSTAT_RANK[1]).At(GLOBAL_PLAYERSTAT_RANK[2]).At(GLOBAL_PLAYERSTAT_RANK[3]).As<int>();
			GUI::AddPlayerInfoBoxTextEntry(PlayerRank.str(), NULL, 2);

			std::ostringstream PlayerCash;
			PlayerCash << "$" << globalHandle(GLOBAL_PLAYERSTAT_CASH[0]).At(PlayerID, GLOBAL_PLAYERSTAT_CASH[1]).At(GLOBAL_PLAYERSTAT_CASH[2]).At(GLOBAL_PLAYERSTAT_CASH[3]).As<__int64>();
			GUI::AddPlayerInfoBoxTextEntry(PlayerCash.str(), NULL, 3);
		}
		else
		{
			GUI::AddPlayerInfoBoxTextEntry("~c~N/A", NULL, 2);
			GUI::AddPlayerInfoBoxTextEntry("~c~N/A", NULL, 3);
		}

		//Health
		std::ostringstream Health;
		float health = ENTITY::GET_ENTITY_HEALTH(SelectedPlayerPed);
		float HealthValue = health * 100 / ENTITY::GET_ENTITY_MAX_HEALTH(SelectedPlayerPed);
		GUI::AddPlayerInfoBoxTextEntry("Health", 4);
		if (HealthValue == 100)
		{
			GUI::AddPlayerInfoBoxTextEntry("Full", NULL, 4);
		}
		else
		{
			Health << HealthValue << "%";
			GUI::AddPlayerInfoBoxTextEntry(Health.str(), NULL, 4);
		}

		//Armor
		std::ostringstream Armor;
		int ArmorValue = PED::GET_PED_ARMOUR(SelectedPlayerPed) * 100 / PLAYER::GET_PLAYER_MAX_ARMOUR(PlayerID);
		GUI::AddPlayerInfoBoxTextEntry("Armor", 5);
		if (ArmorValue == 99 || ArmorValue == 100)
		{
			GUI::AddPlayerInfoBoxTextEntry("Full", NULL, 5);
		}
		else
		{
			Armor << ArmorValue;
			GUI::AddPlayerInfoBoxTextEntry(Armor.str(), NULL, 5);
		}

		//Status
		std::ostringstream Status;
		GUI::AddPlayerInfoBoxTextEntry("Status", 6);
		if (TASK::IS_PED_STILL(SelectedPlayerPed)) { Status << "Still"; }
		else if (TASK::IS_PED_WALKING(SelectedPlayerPed)) { Status << "Walking"; }
		else if (TASK::IS_PED_RUNNING(SelectedPlayerPed)) { Status << "Running"; }
		else if (TASK::IS_PED_SPRINTING(SelectedPlayerPed)) { Status << "Sprinting"; }
		else if (PED::IS_PED_CLIMBING(SelectedPlayerPed)) { Status << "Climbing"; }
		else if (PED::IS_PED_DIVING(SelectedPlayerPed)) { Status << "Diving"; }
		else if (PED::IS_PED_FALLING(SelectedPlayerPed)) { Status << "Falling"; }
		else if (PED::IS_PED_DEAD_OR_DYING(SelectedPlayerPed, true)) { Status << "Dead"; }
		else { Status << "~c~Unknown"; }
		GUI::AddPlayerInfoBoxTextEntry(Status.str(), NULL, 6);

		

		//Vehicle
		bool InAnyVehicle = PED::IS_PED_IN_ANY_VEHICLE(SelectedPlayerPed, 0);
		std::ostringstream Vehicle;
		GUI::AddPlayerInfoBoxTextEntry("Vehicle", 7);
		if (InAnyVehicle)
		{
			Vehicle << UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(SelectedPlayerPed, 0))));
		}
		else
		{
			Vehicle << "~c~Not in any";
		}
		GUI::AddPlayerInfoBoxTextEntry(Vehicle.str(), NULL, 7);

		
		//Speed
		std::ostringstream Speed;
		if (InAnyVehicle)
		{
			GUI::AddPlayerInfoBoxTextEntry("Vehicle Speed", 8);
			float VehicleSpeed = round(ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(SelectedPlayerPed, false)) * 100) / 100;
			if (MISC::SHOULD_USE_METRIC_MEASUREMENTS())
			{
				Speed << Game::math::MSToKMH(VehicleSpeed) << " KM/H";
			}
			else
			{
				Speed << Game::math::MSToMPH(VehicleSpeed) << " MP/H";
			}
			GUI::AddPlayerInfoBoxTextEntry(Speed.str(), NULL, 8);
		}
		else
		{
			GUI::AddPlayerInfoBoxTextEntry("Movement Speed", 8);
			Speed << round(ENTITY::GET_ENTITY_SPEED(SelectedPlayerPed) * 100) / 100 << " M/S";
			GUI::AddPlayerInfoBoxTextEntry(Speed.str(), NULL, 8);
		}


		//Wanted Level
		std::ostringstream WantedLevel;
		int PlayerWantedLevel = PLAYER::GET_PLAYER_WANTED_LEVEL(PlayerID);
		GUI::AddPlayerInfoBoxTextEntry("Wanted Level", 9);
		WantedLevel << PlayerWantedLevel << "/5";
		GUI::AddPlayerInfoBoxTextEntry(WantedLevel.str(), NULL, 9);

		

		Hash WeaponHash;
		GUI::AddPlayerInfoBoxTextEntry("Weapon", 10);
		std::string WeaponName;
		if (WEAPON::GET_CURRENT_PED_WEAPON(SelectedPlayerPed, &WeaponHash, true))
		{
			for (auto const& i : game_data::WeaponsHashList)
			{
				if (WeaponHash == i.WeaponHash)
				{
					WeaponName = i.WeaponName;
				}
			}
		}
		else
		{
			WeaponName = "Unarmed";
		}
		GUI::AddPlayerInfoBoxTextEntry(WeaponName, NULL, 10);

		
		//Coords
		Vector3 SelectedPlayerPedCoords = ENTITY::GET_ENTITY_COORDS(SelectedPlayerPed, false);
		std::ostringstream CoordX;
		std::ostringstream CoordY;
		std::ostringstream CoordZ;

		CoordX << SelectedPlayerPedCoords.x;
		CoordY << SelectedPlayerPedCoords.y;
		CoordZ << SelectedPlayerPedCoords.z;

		GUI::AddPlayerInfoBoxTextEntry("X", 11);
		GUI::AddPlayerInfoBoxTextEntry("Y", 12);
		GUI::AddPlayerInfoBoxTextEntry("Z", 13);
		GUI::AddPlayerInfoBoxTextEntry(CoordX.str(), NULL, 11);
		GUI::AddPlayerInfoBoxTextEntry(CoordY.str(), NULL, 12);
		GUI::AddPlayerInfoBoxTextEntry(CoordZ.str(), NULL, 13);
		

		std::ostringstream Zone;
		GUI::AddPlayerInfoBoxTextEntry("Zone", 14);
		Zone << UI::_GET_LABEL_TEXT(ZONE::GET_NAME_OF_ZONE(SelectedPlayerPedCoords.x, SelectedPlayerPedCoords.y, SelectedPlayerPedCoords.z));
		GUI::AddPlayerInfoBoxTextEntry(Zone.str(), NULL, 14);

		Hash streetName, crossingRoad;
		PATHFIND::GET_STREET_NAME_AT_COORD(SelectedPlayerPedCoords.x, SelectedPlayerPedCoords.y, SelectedPlayerPedCoords.z, &streetName, &crossingRoad);
		GUI::AddPlayerInfoBoxTextEntry("Street", 15);	
		std::ostringstream Street;
		Street << UI::GET_STREET_NAME_FROM_HASH_KEY(streetName);
		GUI::AddPlayerInfoBoxTextEntry(Street.str(), NULL, 15);

		float distance = Game::vector::get_distance_between_two(SelectedPlayerPedCoords, ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false));
		std::ostringstream Distance;

		if (PlayerID != PLAYER::PLAYER_ID())
		{
			if (distance > 1000)
			{
				distance = round((distance / 1000) * 100) / 100;
				Distance << distance << " KM";
			}
			else
			{
				distance = round(distance * 1000) / 100;
				Distance << distance << " M";
			}
		}
		else
		{
			Distance << "~c~N/A";
		}
		GUI::AddPlayerInfoBoxTextEntry("Distance", NULL, NULL, 1);
		GUI::AddPlayerInfoBoxTextEntry(Distance.str(), NULL, NULL, NULL, 1);
		
		//Modded Model
		Hash SelectedPlayerPedModel = ENTITY::GET_ENTITY_MODEL(SelectedPlayerPed);
		GUI::AddPlayerInfoBoxTextEntry("Modded Model", NULL, NULL, 2);
		if (NETWORK::NETWORK_IS_SESSION_STARTED() && SelectedPlayerPedModel != 0x705E61F2 && SelectedPlayerPedModel != 0x9C9EFFD8)
		{
			GUI::AddPlayerInfoBoxTextEntry("Yes", NULL, NULL, NULL, 2);
		}
		else
		{
			GUI::AddPlayerInfoBoxTextEntry("No", NULL, NULL, NULL, 2);
		}

		//Is in interior
		GUI::AddPlayerInfoBoxTextEntry("In Interior", NULL, NULL, 3);
		if (Game::entity::is_in_interior(SelectedPlayerPed))
		{
			GUI::AddPlayerInfoBoxTextEntry("Yes", NULL, NULL, NULL, 3);
		}
		else
		{
			GUI::AddPlayerInfoBoxTextEntry("No", NULL, NULL, NULL, 3);
		}

		//Cutscene
		GUI::AddPlayerInfoBoxTextEntry("Cutscene", NULL, NULL, 4);
		if (NETWORK::IS_PLAYER_IN_CUTSCENE(PlayerID))
		{
			GUI::AddPlayerInfoBoxTextEntry("Yes", NULL, NULL, NULL, 4);
		}
		else
		{
			GUI::AddPlayerInfoBoxTextEntry("No", NULL, NULL, NULL, 4);
		}
		
		//Rockstar ID
		GUI::AddPlayerInfoBoxTextEntry("Rockstar ID", NULL, NULL, 5);
		GUI::AddPlayerInfoBoxTextEntry(std::to_string(Game::gtao::get_rockstar_id(PlayerID)), NULL, NULL, NULL, 5);

		//IP Address
		std::string PlayerIPString = Game::gtao::get_public_ip(PlayerID);
		GUI::AddPlayerInfoBoxTextEntry("IP Address", NULL, NULL, 6);
		GUI::AddPlayerInfoBoxTextEntry(PlayerIPString, NULL, NULL, NULL, 6);
	}
}

void MenuGUIFadeFunction(int Type, bool FadeIn);
void Cheat::GUI::MenuGUIFade(bool FadeIn)
{
	using namespace Cheat;
	if (FadeIn)
	{
		GUI::TextColorAndFont.a = 0;
		GUI::PrimaryColor.a = 0;
		GUI::SelectableTransparency = 0;
		GUI::HeaderBackgroundTransparency = 0;
		GUI::TitleAndEndTransparency = 0;
		GUI::ToggleSelectableTransparency = 0;
		GUI::HeaderTextureTransparency = 0;
		GUI::EndSmallLogoTransparency = 0;
		GUI::OnlinePlayerPictureTransparency = 0;
	}
	for (int i = 0; i <= 3; ++i)
	{
		std::thread MenuGUIFadeThread(MenuGUIFadeFunction, i, FadeIn);
		MenuGUIFadeThread.detach();	
	}
}

void MenuGUIFadeFunction(int Type, bool FadeIn)
{
	int Delay = 1;
	if (Type == 0)
	{
		if (FadeIn)
		{
			for (int i = 0; i <= 255; ++i)
			{
				GUI::TextColorAndFont.a = i;
				GUI::PrimaryColor.a = i;
				GUI::ToggleSelectableTransparency = i;
				GUI::HeaderTextureTransparency = i;
				GUI::EndSmallLogoTransparency = i;
				GUI::OnlinePlayerPictureTransparency = i;
				Sleep(Delay);
			}
		}
		else
		{
			for (int i = 255; i >= 0; --i)
			{
				GUI::TextColorAndFont.a = i;
				GUI::PrimaryColor.a = i;
				GUI::ToggleSelectableTransparency = i;
				GUI::HeaderTextureTransparency = i;
				GUI::EndSmallLogoTransparency = i;
				GUI::OnlinePlayerPictureTransparency = i;
				Sleep(Delay);
			}
		}
	}
	else if (Type == 1)
	{
		if (FadeIn)
		{
			for (int i = 0; i <= 150; ++i)
			{
				GUI::SelectableTransparency = i;
				Sleep(Delay);
			}
		}
		else
		{
			for (int i = 150; i >= 0; --i)
			{
				GUI::SelectableTransparency = i;
				Sleep(Delay);
			}
		}
	}
	else if (Type == 2)
	{
		if (FadeIn)
		{
			for (int i = 0; i <= 200; ++i)
			{
				GUI::HeaderBackgroundTransparency = i;
				Sleep(Delay);
			}
		}
		else
		{
			for (int i = 200; i >= 0; --i)
			{
				GUI::HeaderBackgroundTransparency = i;
				Sleep(Delay);
			}
		}
	}
	else if (Type == 3)
	{
		if (FadeIn)
		{
			for (int i = 0; i <= 210; ++i)
			{
				GUI::TitleAndEndTransparency = i;
				Sleep(Delay);
			}
		}
		else
		{
			for (int i = 210; i >= 0; --i)
			{
				GUI::TitleAndEndTransparency = i;
				Sleep(Delay);
			}
			GUI::CloseMenuGUI();
		}
	}
}

bool Cheat::GUI::IsGameWindowFocussed()
{
	if (FindWindowA("grcWindow", NULL) == GetForegroundWindow())
		return true;
	return false;
}

// https://codepen.io/Codepixl/pen/ogWWaK
void Cheat::GUI::FadeRGB(int& r, int& g, int& b)
{
	if (r > 0 && b == 0)
	{
		r--;
		g++;
	}
	if (g > 0 && r == 0)
	{
		g--;
		b++;
	}
	if (b > 0 && g == 0)
	{
		r++;
		b--;
	}
}