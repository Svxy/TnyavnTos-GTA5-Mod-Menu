#pragma once

struct VehicleModelPicturesStruct
{
	std::string DictName;
	std::string PreviewName;
};

struct WeaponHashesStruct
{
	std::string WeaponName;
	DWORD WeaponHash;
};

struct TeleportLocationStruct
{
	std::string Name;
	float coordinateX;
	float coordinateY;
	float coordinateZ;
};

struct WeatherTypesStruct
{
	std::string SelectableName;
	std::string WeatherType;
};

struct MaxUpgradeWeaponComponentsStruct
{
	Hash WeaponHash;
	std::string UpgradeHash;
};

struct AnimationsStruct
{
	std::string AnimationDictionary;
	std::string AnimationName;
};

struct TSEPropertyListStruct
{
	std::string PropertyName;
	int Index;
};

struct DefaultHUDColorsStruct
{
	int R;
	int G;
	int B;
	int A;
};

namespace Cheat
{
	namespace GameArrays
	{
		extern const std::vector<DWORD> VehicleModels;
		extern const std::vector<std::string> PedModels;
		extern const std::vector<VehicleModelPicturesStruct> VehicleModelPictures;
		extern const std::vector<WeaponHashesStruct> WeaponsHashList;
		extern const std::vector<TeleportLocationStruct> TeleportLocationsSafehouses;
		extern const std::vector<TeleportLocationStruct> TeleportLocationsHighAltitude;
		extern const std::vector<TeleportLocationStruct> TeleportLocationsUnderwater;
		extern const std::vector<TeleportLocationStruct> TeleportLocationsLandmarks;
		extern std::vector<Vehicle> SpawnedVehicles;
		extern const std::vector<WeatherTypesStruct> WeatherTypes;
		extern const std::vector<MaxUpgradeWeaponComponentsStruct> MaxUpgradeWeaponComponents;
		extern const std::vector<AnimationsStruct> Animations;
		extern const std::vector<std::string> AnimationsDisplayNames;
		extern const std::vector<std::string> Scenarios;
		extern const std::vector<TSEPropertyListStruct> TSEPropertyList;
		extern const std::vector<std::string> HUDColors;
		extern std::vector<DefaultHUDColorsStruct> DefaultHUDColors;
		extern const std::vector<const char*> IPLNorthYankton;
		extern const std::vector<const char*> IPLDignityHeistYacht;
		extern const std::vector<const char*> IPLDestroyedHospital;
		extern const std::vector<const char*> IPLJewelryStore;
		extern const std::vector<const char*> IPLMorgue;
		extern const std::vector<const char*> IPLCargoship;
		extern const std::vector<const char*> IPLAircraftCarrier;
		extern const std::map<std::string, std::string> TelevisionPlaylists;
	}
}