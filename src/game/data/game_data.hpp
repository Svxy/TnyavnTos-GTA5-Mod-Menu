#pragma once
#include <string>
#include <vector>

namespace Cheat
{
	class game_data
	{
	private:
		struct WeaponHashes					{ std::string WeaponName; unsigned long WeaponHash; };
		struct VehicleModelPicturesS		{ std::string DictName; std::string PreviewName; };
		struct WeatherTypesS				{ std::string SelectableName; std::string WeatherType; };
		struct MaxUpgradeWeaponComponentsS	{ unsigned long WeaponHash; std::string UpgradeHash; };
		struct TelevisionPlaylistsS			{ std::string DisplayName; std::string InternalName; };
		struct AnimationsS					{ std::string AnimationDictionary; std::string AnimationName; };
		struct propertyListS				{ std::string PropertyName; int Index; };
	public:
		static const std::vector<WeaponHashes> WeaponsHashList;
		static const std::vector<std::string> PedModels;
		static const std::vector<unsigned long> VehicleModels;
		static const std::vector<VehicleModelPicturesS> VehicleModelPictures;
		struct TeleportLocation { std::string Name; float coordinateX; float coordinateY; float coordinateZ; };
		static const std::vector<TeleportLocation> TeleportLocationsSafehouses;
		static const std::vector<TeleportLocation> TeleportLocationsHighAltitude;
		static const std::vector<TeleportLocation> TeleportLocationsUnderwater;
		static const std::vector<TeleportLocation> TeleportLocationsLandmarks;
		static const std::vector<WeatherTypesS> WeatherTypes;
		static const std::vector<game_data::MaxUpgradeWeaponComponentsS> MaxUpgradeWeaponComponents;
		static const std::vector<const char*> IPLNorthYankton;
		static const std::vector<const char*> IPLDignityHeistYacht;
		static const std::vector<const char*> IPLDestroyedHospital;
		static const std::vector<const char*> IPLJewelryStore;
		static const std::vector<const char*> IPLMorgue;
		static const std::vector<const char*> IPLCargoship;
		static const std::vector<const char*> IPLAircraftCarrier;
		static const std::vector<TelevisionPlaylistsS> TelevisionPlaylists;
		struct DefaultHUDColorsS { int R; int G; int B; int A; };
		static std::vector<game_data::DefaultHUDColorsS> DefaultHUDColors;
		static const std::vector<AnimationsS> Animations;
		static const std::vector<std::string> AnimationsDisplayNames;
		static const std::vector<propertyListS> PropertyList;
		static const std::vector<std::string> Scenarios;
		static const std::vector<std::string> HUDColors;
	};
}