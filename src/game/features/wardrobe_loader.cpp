#include "wardrobe_loader.hpp"
#include "../game.hpp"
#include "../../cheat/cheat.hpp"
#include "../../cheat/file_system.hpp"
#include "../../cheat/fibermain.hpp"
#include "../../hooking/natives.hpp"

namespace Cheat
{
	namespace Features
	{
		const std::string wardrobe_loader::version = "1.0";	// This value must be incremented when INI structure is modified
		std::string wardrobe_loader::currently_loaded;
		wardrobe_loader::status wardrobe_loader::Create(std::string Name)
		{
			// Check whether PLAYER::PLAYER_PED_ID() is valid - no point continuing if it is not
			if (!PED::IS_PED_A_PLAYER(PLAYER::PLAYER_PED_ID()))
				return status::PED_ID_INVALID;

			Ped PedModel = ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID());

			// Get and write data
			std::string TargetPath = file_system::paths::WardrobesDir + "\\" + Name + ".ini";
			file_system::ini_file::write(version, TargetPath, "wardrobe", "version");
			file_system::ini_file::write(std::to_string(PedModel), TargetPath, "wardrobe", "ped");

			// Drawable variations
			std::vector<int> Drawable, Texture, Palette;
			for (int i = 0; i < 12; i++)
			{
				file_system::ini_file::write(std::to_string(PED::GET_PED_DRAWABLE_VARIATION(PLAYER::PLAYER_PED_ID(), i)), TargetPath, "drawable", std::to_string(i));
				file_system::ini_file::write(std::to_string(PED::GET_PED_TEXTURE_VARIATION(PLAYER::PLAYER_PED_ID(), i)), TargetPath, "drawable_texture", std::to_string(i));
				file_system::ini_file::write(std::to_string(PED::GET_PED_PALETTE_VARIATION(PLAYER::PLAYER_PED_ID(), i)), TargetPath, "drawable_palette", std::to_string(i));
			}

			// Prop
			for (int i = 0; i < 5; i++)
			{
				// Using ternary operators here to skip index 3 and 4 because these do not exist
				int ID = i == 3 ? 6 : i == 4 ? 7 : i;
				file_system::ini_file::write(std::to_string(PED::GET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), ID)), TargetPath, "prop", std::to_string(ID));
				file_system::ini_file::write(std::to_string(PED::GET_PED_PROP_TEXTURE_INDEX(PLAYER::PLAYER_PED_ID(), ID)), TargetPath, "prop_texture", std::to_string(ID));
			}

			// Completed
			return status::SUCCESS;
		}
		wardrobe_loader::status wardrobe_loader::Load(std::string Name)
		{
			// Check whether PLAYER::PLAYER_PED_ID() is valid - no point continuing if it is not
			if (!PED::IS_PED_A_PLAYER(PLAYER::PLAYER_PED_ID()))
				return status::PED_ID_INVALID;

			std::string TargetPath = file_system::paths::WardrobesDir + "\\" + Name + ".ini";

			// Make sure the Wardrobe exists
			if (!std::filesystem::exists(TargetPath))
				return status::UNEXISTENT;

			// Make sure the to be loaded wardrobe is not outdated		
			if (file_system::ini_file::get(TargetPath, "wardrobe", "version") != version)
				return status::OUTDATED;

			// Make sure we are loading a wardrobe on the Ped the wardrobe was created for
			bool PedMismatch = false;
			if (helper::StringToInt(file_system::ini_file::get(TargetPath, "wardrobe", "ped")) != (ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID())))
				PedMismatch = true;

			// Read from INI and load using SET_PED_COMPONENT_VARIATION & SET_PED_PROP_INDEX
			if (!PedMismatch)
			{
				// Drawable
				for (int i = 0; i < 12; i++)
				{
					int drawable = helper::StringToInt(file_system::ini_file::get(TargetPath, "drawable", std::to_string(i)));
					int drawable_texture = helper::StringToInt(file_system::ini_file::get(TargetPath, "drawable_texture", std::to_string(i)));
					int drawable_palette = helper::StringToInt(file_system::ini_file::get(TargetPath, "drawable_palette", std::to_string(i)));
					PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), i, drawable, drawable_texture, drawable_palette);
				}

				// Prop
				for (int i = 0; i < 8; i++)
				{
					// Skip non-existent indexes
					if (i == 3 || i == 4 || i == 5)
						continue;

					// Get data
					int prop = helper::StringToInt(file_system::ini_file::get(TargetPath, "prop", std::to_string(i)));
					int prop_texture = helper::StringToInt(file_system::ini_file::get(TargetPath, "prop_texture", std::to_string(i)));

					// Verify validity and change
					if (PED::SET_PED_PRELOAD_PROP_DATA(PLAYER::PLAYER_PED_ID(), i, prop, prop_texture))
						PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), i, prop, prop_texture, true);			
				}
			}
				
			// Completed
			currently_loaded = Name;
			if (PedMismatch)
				return status::PED_MISMATCH;
			return status::SUCCESS;
		}
		wardrobe_loader::status wardrobe_loader::Remove(std::string Name)
		{
			// Clear currently_loaded if we are deleting the currently active Wardrobe
			if (Name == currently_loaded)
				currently_loaded.clear();

			// Remove the Wardrobe file
			std::filesystem::remove(file_system::paths::WardrobesDir + "\\" + Name + ".ini");
			
			return status::SUCCESS;
		}
	}
}