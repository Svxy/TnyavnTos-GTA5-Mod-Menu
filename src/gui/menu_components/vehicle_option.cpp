#include "../../cheat/fibermain.hpp"
#include "../../game/data/game_data.hpp"
#include "../../hooking/natives.hpp"

using namespace Cheat;

bool GUI::VehicleOption(unsigned long VehicleHash)
{
	if (STREAMING::IS_MODEL_A_VEHICLE(VehicleHash))
	{
		std::string ModelName = VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(VehicleHash);
		std::string OptionText = UI::_GET_LABEL_TEXT(ModelName.c_str());
		if (Option(OptionText == "NULL" ? ModelName : OptionText, "Model Name: " + ModelName + "\nSeats: " + std::to_string(VEHICLE::GET_VEHICLE_MODEL_NUMBER_OF_SEATS(VehicleHash))))
		{
			return true;
		}
		if (GUI::currentOption == GUI::optionCount && !Features::HideVehiclePreview)
		{
			std::string VehiclePreviewDictName, VehiclePreviewName;
			std::transform(ModelName.begin(), ModelName.end(), ModelName.begin(), tolower);
			VehiclePreviewDictName = "Textures";
			VehiclePreviewName = "NoVehiclePreviewAvailable";

			for (auto& Vector : game_data::VehicleModelPictures)
			{
				if (Vector.PreviewName == ModelName)
				{
					VehiclePreviewDictName = Vector.DictName;
					VehiclePreviewName = Vector.PreviewName;
				}
			}

			float x = guiX < 0.75f ? guiX + (GUI::guiWidth / 2) + 0.080f : guiX - (GUI::guiWidth / 2) - 0.080f;
			DrawSpriteInGame(VehiclePreviewDictName, VehiclePreviewName, x, guiY - 0.098f, 0.16f, 0.16f, 0.f, 255, 255, 255, GUI::PrimaryColor.a);
		}
	}
	return false;
}