#include "../Header/Cheat Functions/FiberMain.h"
Player Cheat::GameFunctions::PlayerID;
Ped Cheat::GameFunctions::PlayerPedID;

void Cheat::GameFunctions::GiveAllWeaponsToPlayer(Ped Player)
{
	for (auto const& i : GameArrays::WeaponsHashList)
	{
		WEAPON::GIVE_WEAPON_TO_PED(Player, i.WeaponHash, 9999, false, false);
	}
}

void Cheat::GameFunctions::RepairAndCleanVehicle(Vehicle vehicle)
{
	ENTITY::SET_ENTITY_HEALTH(vehicle, ENTITY::GET_ENTITY_MAX_HEALTH(vehicle), 0);
	VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.f);
	VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
	VEHICLE::SET_VEHICLE_FIXED(vehicle);
	VEHICLE::SET_VEHICLE_ENGINE_ON(vehicle, true, true, false);
	Cheat::GameFunctions::AdvancedMinimapNotification("Vehicle Repaired & Cleaned", "Textures", "AdvancedNotificationImage", false, 4, "Los Santos Customs", "", 1.0, "");
}

void Cheat::GameFunctions::TeleportToBlipCoord(Blip TargetBlip)
{
	if (TargetBlip == SpriteWaypoint && !UI::IS_WAYPOINT_ACTIVE())
	{
		Cheat::GameFunctions::MinimapNotification("~r~No Waypoint has been set"); 
		return;
	}

	Blip BlipHandle = UI::GET_FIRST_BLIP_INFO_ID(TargetBlip);
	if (UI::DOES_BLIP_EXIST(BlipHandle))
	{
		GameFunctions::TeleportToCoords(Cheat::GameFunctions::PlayerPedID, UI::GET_BLIP_INFO_ID_COORD(BlipHandle), true, false);
		return;
	}
	GameFunctions::MinimapNotification("~r~Target Blip does not exist");
}

void Cheat::GameFunctions::TeleportToObjective()
{
	Vector3 wayp{};
	Ped e = Cheat::GameFunctions::PlayerPedID;
	bool blipFound = false;
	for (int i = 0; i <= 1000; i++)
	{
		int blipIterator = UI::IS_WAYPOINT_ACTIVE() ? UI::GET_WAYPOINT_BLIP_ENUM_ID() : SpriteStandard;
		for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator);
			UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator)) {
			if (UI::GET_BLIP_INFO_ID_TYPE(i) == ColorPlayer && UI::GET_BLIP_COLOUR(i) == ColorYellow && UI::GET_BLIP_COLOUR(i) != ColorBlue && UI::IS_BLIP_ON_MINIMAP(i) == ColorRed)
			{
				wayp = UI::GET_BLIP_INFO_ID_COORD(i);
				blipFound = true;
				Cheat::GameFunctions::TeleportToCoords(e, wayp, false, false);
			}
			GameFunctions::TeleportToCoords(e, wayp, true, false);
		}
		break;
	}
	if (!blipFound) 
	{
		Blip i = UI::GET_FIRST_BLIP_INFO_ID(SpriteRaceFinish);
		if (UI::DOES_BLIP_EXIST(i)) 
		{
			wayp = UI::GET_BLIP_INFO_ID_COORD(i);
			blipFound = true;
		}
	}
	blipFound ? Cheat::GameFunctions::TeleportToCoords(e, wayp, false, false) : Cheat::GameFunctions::MinimapNotification("~r~Objective not found");
}

void Cheat::GameFunctions::SetOffAlarmPlayerVehicle(Ped selectedPed)
{
	Entity selectedVehicle = PED::GET_VEHICLE_PED_IS_USING(selectedPed);
	RequestNetworkControlOfEntity(selectedVehicle);
	VEHICLE::SET_VEHICLE_ALARM(selectedVehicle, true);
	VEHICLE::START_VEHICLE_ALARM(selectedVehicle);
}

bool Cheat::GameFunctions::IsPlayerFriend(Player player)
{
	int handle[76];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &handle[0], 13);
	if (NETWORK::NETWORK_IS_HANDLE_VALID(&handle[0], 13))
	{
		if (NETWORK::NETWORK_IS_FRIEND(&handle[0]))
		{
			return true;
		}
	}
	return false;
}

Vector3 Cheat::GameFunctions::MultiplyVector(Vector3 vector, float inc) 
{
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector._paddingx *= inc;
	vector._paddingy *= inc;
	vector._paddingz *= inc;
	return vector;
}

Vector3 Cheat::GameFunctions::AddVector(Vector3 vector, Vector3 vector2) 
{
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector._paddingx += vector2._paddingx;
	vector._paddingy += vector2._paddingy;
	vector._paddingz += vector2._paddingz;
	return vector;
}

void Cheat::GameFunctions::SetRankRockstarGift(int Rank)
{
	if (Rank > 0 && Rank <= 8000)
	{ 
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(ReturnCurrentGTAOCharacter() + "_CHAR_SET_RP_GIFT_ADMIN")), ReturnReputationPointsAmount(Rank), true);
		MinimapNotification("Join a new GTAO session for the new Rank to be applied");
	}
	else
	{
		MinimapNotification("Invalid Rank Inputted");
	}
}

int Cheat::GameFunctions::ReturnReputationPointsAmount(int Level)
{
	return globalHandle(GLOBAL_LEVEL_TO_RP).At(1, Level).As<int>();
}

Vector3 Cheat::GameFunctions::RotationToDirection(Vector3* rot)
{
	float radiansZ = rot->z * 0.0174532924f;
	float radiansX = rot->x * 0.0174532924f;
	float num = abs((float)cos((double)radiansX));
	Vector3 dir;
	dir.x = (float)((double)((float)(-(float)sin((double)radiansZ))) * (double)num);
	dir.y = (float)((double)((float)cos((double)radiansZ)) * (double)num);
	dir.z = (float)sin((double)radiansX);
	return dir;
}

Vector3 Cheat::GameFunctions::AddTwoVectors(Vector3* vectorA, Vector3* vectorB) 
{
	Vector3 result;
	result.x = vectorA->x;
	result.y = vectorA->y;
	result.z = vectorA->z;
	result.x += vectorB->x;
	result.y += vectorB->y;
	result.z += vectorB->z;
	return result;
}

Vector3 Cheat::GameFunctions::MultiplyVector(Vector3* vector, float x) 
{
	Vector3 result;
	result.x = vector->x;
	result.y = vector->y;
	result.z = vector->z;
	result.x *= x;
	result.y *= x;
	result.z *= x;
	return result;
}

float Cheat::GameFunctions::GetDistanceBetweenTwoVectors(Vector3* pointA, Vector3* pointB) 
{
	float a_x = pointA->x;
	float a_y = pointA->y;
	float a_z = pointA->z;
	float b_x = pointB->x;
	float b_y = pointB->y;
	float b_z = pointB->z;
	double x_ba = (double)(b_x - a_x);
	double y_ba = (double)(b_y - a_y);
	double z_ba = (double)(b_z - a_z);
	double y_2 = y_ba * y_ba;
	double x_2 = x_ba * x_ba;
	double sum_2 = y_2 + x_2;
	return (float)sqrt(sum_2 + z_ba);
}

void Cheat::GameFunctions::SubtitleNotification(char* Message, int ShowDuration)
{
	UI::BEGIN_TEXT_COMMAND_PRINT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Message);
	UI::END_TEXT_COMMAND_PRINT(ShowDuration, true);
}

float Cheat::GameFunctions::DegreesToRadians(float degs)
{
	return degs * 3.141592653589793f / 180.f;
}

float Cheat::GameFunctions::GetDistanceBetweenTwoPoints(Vector3 A, Vector3 B) 
{
	return MISC::GET_DISTANCE_BETWEEN_COORDS(A.x, A.y, A.z, B.x, B.y, B.z, 1);
}

void Cheat::GameFunctions::TeleportToCoords(Entity e, Vector3 coords, bool AutoCorrectGroundHeight, bool IgnoreCurrentPedVehicle)
{
	Entity TargetEntity = e;
	bool TeleportTransition = CheatFeatures::TeleportTransition && TargetEntity == GameFunctions::PlayerPedID;
	if (TeleportTransition)
	{
		STREAMING::_SWITCH_OUT_PLAYER(TargetEntity, 0, 2);
	}

	if (ENTITY::IS_AN_ENTITY(TargetEntity))
	{
		GameFunctions::RequestNetworkControlOfEntity(TargetEntity);

		if (PED::IS_PED_IN_ANY_VEHICLE(TargetEntity, false) && !IgnoreCurrentPedVehicle)
		{
			TargetEntity = PED::GET_VEHICLE_PED_IS_USING(TargetEntity);
		}

		if (!AutoCorrectGroundHeight)
		{
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(TargetEntity, coords.x, coords.y, coords.z, false, false, true);
		}
		else
		{
			bool GroundFound = false;
			static std::array<float, 21> GroundCheckHeight = { 0.0f, 50.0f, 100.0f, 150.0f, 200.0f, 250.0f, 300.0f, 350.0f, 400.0f, 450.0f, 500.0f, 550.0f, 600.0f, 650.0f, 700.0f, 750.0f, 800.0f, 850.0f, 900.0f, 950.0f, 1000.00f };

			for (const float& CurrentHeight : GroundCheckHeight)
			{
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(TargetEntity, coords.x, coords.y, CurrentHeight, false, false, true);
				GameHooking::PauseMainFiber(50, false);
				if (MISC::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, CurrentHeight, &coords.z, false, false))
				{
					GroundFound = true;
					coords.z += 3.0f;
					break;
				}
			}

			if (!GroundFound)
			{
				Vector3 ClosestRoadCoord;
				if (PATHFIND::GET_CLOSEST_ROAD(coords.x, coords.y, coords.z, 1.0f, 1,
					&ClosestRoadCoord, &ClosestRoadCoord, NULL, NULL, NULL, NULL))
				{
					coords = ClosestRoadCoord;
				}
				GameFunctions::SubtitleNotification("~r~Ground not found, teleported to nearby road", 4000);
			}
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(TargetEntity, coords.x, coords.y, coords.z, false, false, true);
		}
		if (TeleportTransition)
		{
			STREAMING::_SWITCH_IN_PLAYER(TargetEntity);
		}
	}
}

void Cheat::GameFunctions::GetCameraDirection(float* dirX, float* dirY, float* dirZ)
{
	float tX, tZ, num;
	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);

	tZ = rot.z * 0.0174532924f;
	tX = rot.x * 0.0174532924f;
	num = abs(cos(tX));

	*dirX = (-sin(tZ)) * num;
	*dirY = (cos(tZ)) * num;
	*dirZ = sin(tX);
}

void Cheat::GameFunctions::RequestNetworkControlOfEntity(Entity entity)
{
	int EntityTick = 0;
	int IdTick = 0;
	while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity) && EntityTick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
		EntityTick++;
	}
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(entity);
		while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netID) && IdTick <= 25)
		{
			NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netID);
			IdTick++;
		}
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, true);
	}
}

void Cheat::GameFunctions::ClonePed(Ped ped)
{
	if (ENTITY::DOES_ENTITY_EXIST(ped) && !ENTITY::IS_ENTITY_DEAD(ped, false))
	{
		PED::CLONE_PED(ped, ENTITY::GET_ENTITY_HEADING(ped), true, true);
	}
}

void Cheat::GameFunctions::MinimapNotification(char* Message)
{
	UI::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Message);
	UI::END_TEXT_COMMAND_THEFEED_POST_TICKER(false, false);
}

void Cheat::GameFunctions::AdvancedMinimapNotification(char* Message, char* PicName1, char* PicName2, bool Flash, int IconType, char* Sender, char* Subject, float Duration, char* ClanTag)
{
	UI::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Message);
	UI::END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT_WITH_CREW_TAG(PicName1, PicName2, Flash, IconType, Sender, Subject, Duration, ClanTag);
	UI::END_TEXT_COMMAND_THEFEED_POST_TICKER(false, false);
}

std::string Cheat::GameFunctions::InGameKeyboardWindowTitle;
bool Cheat::GameFunctions::DisplayKeyboardAndReturnInput(int MaxInput, std::string Title, const char*& Input)
{
	InGameKeyboardWindowTitle = Title;
	MISC::DISPLAY_ONSCREEN_KEYBOARD(0, "FMMC_KEY_TIP8", "", "", "", "", "", MaxInput);
	while (MISC::UPDATE_ONSCREEN_KEYBOARD() == 0) { GameHooking::PauseMainFiber(0, false); }
	InGameKeyboardWindowTitle.clear();
	if (!MISC::GET_ONSCREEN_KEYBOARD_RESULT())
	{
		return false;
	}
	Input = MISC::GET_ONSCREEN_KEYBOARD_RESULT();
	return true;
}

bool Cheat::GameFunctions::DisplayKeyboardAndReturnInputInteger(int MaxInput, std::string Title, int &Input)
{	
	const char* InputString;
	if (!DisplayKeyboardAndReturnInput(MaxInput, Title, InputString)) { return false; }
	Input = CheatFunctions::StringToInt(InputString);
	return true;
}

void Cheat::GameFunctions::StopAllPedAnimations(Ped TargetPed)
{
	TASK::CLEAR_PED_TASKS_IMMEDIATELY(TargetPed);
}

void Cheat::GameFunctions::ClearNearbyPedAnimations()
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Ped* peds = new Ped[ArrSize];
	peds[0] = ElementAmount;

	int PedFound = PED::GET_PED_NEARBY_PEDS(PlayerPedID, peds, -1);

	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		Cheat::GameFunctions::RequestNetworkControlOfEntity(peds[OffsetID]);
		if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PlayerPedID != peds[OffsetID])
		{
			StopAllPedAnimations(peds[OffsetID]);
		}
	}
}

void Cheat::GameFunctions::PlayPedAnimation(Ped TargetPed, char* AnimationName, char* AnimationID, bool Controllable)
{
	Cheat::GameFunctions::RequestNetworkControlOfEntity(TargetPed);
	while (!STREAMING::HAS_ANIM_DICT_LOADED((AnimationName))) { STREAMING::REQUEST_ANIM_DICT(AnimationName); GameHooking::PauseMainFiber(0, false); }
	int Flags = 0;
	if (Controllable) { Flags = ANIM_FLAG_UPPERBODY | ANIM_FLAG_ENABLE_PLAYER_CONTROL | ANIM_FLAG_STOP_LAST_FRAME;  }
	TASK::TASK_PLAY_ANIM(TargetPed, AnimationName, AnimationID, 8.0f, 0.0f, -1, Flags, 0, false, false, false);
}

void Cheat::GameFunctions::DoNearbyPedsAnimation(char* AnimationName, char* AnimationID)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Ped* peds = new Ped[ArrSize];
	peds[0] = ElementAmount;

	int PedFound = PED::GET_PED_NEARBY_PEDS(Cheat::GameFunctions::PlayerPedID, peds, -1);

	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		Cheat::GameFunctions::RequestNetworkControlOfEntity(peds[OffsetID]);
		if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && Cheat::GameFunctions::PlayerPedID != peds[OffsetID])
		{
			Cheat::GameFunctions::RequestNetworkControlOfEntity(peds[OffsetID]);
			STREAMING::REQUEST_ANIM_DICT(AnimationName);
			if (STREAMING::HAS_ANIM_DICT_LOADED((AnimationName)))
			{
				TASK::TASK_PLAY_ANIM(peds[OffsetID], AnimationName, AnimationID, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
			}
		}
	}
}

void Cheat::GameFunctions::PlayScenarioNearbyPeds(char* Scenario)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Ped* peds = new Ped[ArrSize];
	peds[0] = ElementAmount;

	int PedFound = PED::GET_PED_NEARBY_PEDS(Cheat::GameFunctions::PlayerPedID, peds, -1);

	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		Cheat::GameFunctions::RequestNetworkControlOfEntity(peds[OffsetID]);
		if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && Cheat::GameFunctions::PlayerPedID != peds[OffsetID])
		{
			StopAllPedAnimations(peds[OffsetID]);
			TASK::TASK_START_SCENARIO_IN_PLACE(peds[OffsetID], Scenario, 0, true);
		}
	}
}

void Cheat::GameFunctions::MaxUpgradeVehicle(int VehicleHandle)
{
	Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PlayerPedID, false);
	VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
	for (int i = 0; i < 50; i++)
	{
		VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
	}
	VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 18, true); //Set turbo on vehicle
	VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 22, true); //Enable xeon headlights
}

void Cheat::GameFunctions::MaxDowngradeVehicle(int VehicleHandle)
{
	Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PlayerPedID, false);
	VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
	for (int i = 0; i < 50; i++)
	{
		VEHICLE::REMOVE_VEHICLE_MOD(vehicle, i);
	}
	VEHICLE::REMOVE_VEHICLE_MOD(vehicle, 18); //Remove turbo on vehicle
	VEHICLE::REMOVE_VEHICLE_MOD(vehicle, 22); //Remove xeon headlights
}

float Cheat::GameFunctions::Get3DDistance(Vector3 a, Vector3 b)
{
	float x = pow((a.x - b.x), 2);
	float y = pow((a.y - b.y), 2);
	float z = pow((a.z - b.z), 2);
	return sqrt(x + y + z);
}

void Cheat::GameFunctions::ApplyForceToEntity(Entity e, float x, float y, float z)
{
	if (e != Cheat::GameFunctions::PlayerPedID && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(e) == false) { RequestNetworkControlOfEntity(e); }
	ENTITY::APPLY_FORCE_TO_ENTITY(e, 1, x, y, z, 0, 0, 0, 0, 1, 1, 1, 0, 1);
}

void Cheat::GameFunctions::RemoveObjectFromPed(Ped Ped, char* ObjectName)
{
	Vector3 PedCoords = ENTITY::GET_ENTITY_COORDS(Ped, false);
	Object Object = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(PedCoords.x, PedCoords.y, PedCoords.z, 4.0, MISC::GET_HASH_KEY(ObjectName), false, false, true);
	if (ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(Object, Ped))
	{
		Cheat::GameFunctions::RequestNetworkControlOfEntity(Object);
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Object, true, true);
		ENTITY::DELETE_ENTITY(&Object);
		ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&Object);
	}
}

void Cheat::GameFunctions::AttachObjectToPed(Ped Ped, char* ObjectName)
{
	int attachobj[100];
	int nuattach = 1;
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Ped), false);
	int hash = MISC::GET_HASH_KEY(ObjectName);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(hash))
	{
		if (STREAMING::IS_MODEL_VALID(hash))
		{
			STREAMING::REQUEST_MODEL(hash);
			while (!STREAMING::HAS_MODEL_LOADED(hash)) GameHooking::PauseMainFiber(0);

			if (STREAMING::HAS_MODEL_LOADED(hash))
			{
				attachobj[nuattach] = OBJECT::CREATE_OBJECT(hash, pos.x, pos.y, pos.z, 1, 1, 1);
				if (ENTITY::DOES_ENTITY_EXIST(attachobj[nuattach]))
				{
					ENTITY::ATTACH_ENTITY_TO_ENTITY(attachobj[nuattach], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Ped), 31086, 0, 0, 0, 0, 0, 0, true, false, false, false, 2, true);
					nuattach++;
					if (nuattach >= 101) { nuattach = 1; }
				}
			}
		}
	}
}

std::vector<Vehicle> Cheat::GameArrays::SpawnedVehicles;
void Cheat::GameFunctions::SpawnVehicle(const char* ModelName)
{
	Hash VehicleHash = MISC::GET_HASH_KEY(ModelName);
	if (STREAMING::IS_MODEL_A_VEHICLE(VehicleHash))
	{
		bool IsInVehicle = PED::IS_PED_IN_ANY_VEHICLE(PlayerPedID, false);

		// Load New Vehicle Model
		while (!STREAMING::HAS_MODEL_LOADED(VehicleHash))
		{
			STREAMING::REQUEST_MODEL(VehicleHash);
			GameHooking::PauseMainFiber(0);
		}

		// Get Velocity Current Vehicle
		Vector3 VelocityCurrentVehicle;
		if (CheatFeatures::VehicleSpawnerDeleteOldVehicle && CheatFeatures::VehicleSpawnerSpawnInsideVehicle && IsInVehicle)
		{
			VelocityCurrentVehicle = ENTITY::GET_ENTITY_VELOCITY(PED::GET_VEHICLE_PED_IS_IN(PlayerPedID, false));
		}

		// Delete Current Vehicle
		if (CheatFeatures::VehicleSpawnerDeleteOldVehicle && IsInVehicle)
		{
			DeleteVehicle(PED::GET_VEHICLE_PED_IS_IN(PlayerPedID, false));
		}

		// Spawn Aircraft In The Air
		Vector3 NewVehiclePosition = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PlayerPedID, 0.0f, 5.0f, 0.0f);
		if (CheatFeatures::VehicleSpawnerSpawnAirVehicleAir)
		{
			if (VEHICLE::IS_THIS_MODEL_A_PLANE(VehicleHash) || VEHICLE::IS_THIS_MODEL_A_HELI(VehicleHash))
			{
				NewVehiclePosition.z += 100.f;
			}
		}

		// Create The New Vehicle
		Vehicle NewVehicleHandle = VEHICLE::CREATE_VEHICLE(VehicleHash, NewVehiclePosition.x, NewVehiclePosition.y, NewVehiclePosition.z, ENTITY::GET_ENTITY_HEADING(PlayerPedID), true, true, false);

		if (NewVehicleHandle)
		{
			// When in GTA:O, play fade-in effect
			if (NETWORK::NETWORK_IS_SESSION_STARTED())
			{
				NETWORK::NETWORK_FADE_IN_ENTITY(NewVehicleHandle, true, 0);
			}
			
			if (CheatFeatures::VehicleSpawnerSpawnInsideVehicle)
			{
				PED::SET_PED_INTO_VEHICLE(PlayerPedID, NewVehicleHandle, -1);
			}

			if (CheatFeatures::VehicleSpawnerSpawnWithGodmode)
			{
				GameFunctions::ChangeEntityInvincibilityState(NewVehicleHandle, true);
			}

			if (CheatFeatures::VehicleSpawnerSpawnMaxUpgraded)
			{ 
				MaxUpgradeVehicle(NewVehicleHandle); 
			}

			if (CheatFeatures::VehicleSpawnerSpawnWithBlip)
			{ 
				AddBlipToVehicle(NewVehicleHandle);
			}

			if (CheatFeatures::VehicleSpawnerLicensePlateVectorPosition != 0)
			{
				char* LicensePlateString = "";
				if (CheatFeatures::VehicleSpawnerLicensePlateVectorPosition == 2)
				{
					LicensePlateString = CheatFunctions::StringToChar(CheatFeatures::VehicleSpawnerCustomLicensePlateTextString);
				}
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(NewVehicleHandle, LicensePlateString);
			}		

			// Set Vehicle Parameters
			VEHICLE::SET_VEHICLE_IS_STOLEN(NewVehicleHandle, false);
			VEHICLE::SET_VEHICLE_ENGINE_ON(NewVehicleHandle, true, true, false);
			ENTITY::SET_ENTITY_VELOCITY(NewVehicleHandle, VelocityCurrentVehicle.x, VelocityCurrentVehicle.y, VelocityCurrentVehicle.z);
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(NewVehicleHandle, true, true);
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(NETWORK::VEH_TO_NET(NewVehicleHandle), true);
			DECORATOR::DECOR_SET_INT(NewVehicleHandle, "MPBitset", 0);
			ENTITY::_SET_ENTITY_CLEANUP_BY_ENGINE(NewVehicleHandle, true);
			Cheat::GameFunctions::MinimapNotification("Vehicle Spawned");
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(VehicleHash);
			GameArrays::SpawnedVehicles.push_back(NewVehicleHandle);
		}
	}
	else
	{
		Cheat::GameFunctions::MinimapNotification("~r~That is not a valid Vehicle model");
	}
}

Cam antiCrashCam;
void Cheat::GameFunctions::EnableDisableAntiCrashCamera()
{
	if (CAM::DOES_CAM_EXIST(antiCrashCam))
	{
		CAM::SET_CAM_ACTIVE(antiCrashCam, false);
		CAM::RENDER_SCRIPT_CAMS(false, true, 10, false, false, false);
		CAM::DESTROY_CAM(antiCrashCam, false);
		PLAYER::SET_PLAYER_CONTROL(Cheat::GameFunctions::PlayerID, true, 0);
	}
	else
	{
		antiCrashCam = CAM::CREATE_CAM_WITH_PARAMS("DEFAULT_SCRIPTED_CAMERA", 9999.0f, 9999.0f, 9999.0f, 9999.0f, 9999.0f, 9999.0f, 9999.0f, true, 1);
		CAM::RENDER_SCRIPT_CAMS(true, true, 1, false, false, false);
		CAM::SET_CAM_ACTIVE(antiCrashCam, true);
		PLAYER::SET_PLAYER_CONTROL(Cheat::GameFunctions::PlayerID, false, 0);
	}
}

std::vector<std::string> CurrentPlayerNamesSession;
std::vector<std::string> CurrentPlayerNamesSession2;
bool SecondCall = false;
void Cheat::GameFunctions::CheckNewSessionMembersLoop()
{
	if (NETWORK::NETWORK_IS_SESSION_STARTED() && CheatFeatures::ShowJoiningPlayersNotification)
	{
		if (!SecondCall) { CurrentPlayerNamesSession.clear(); CurrentPlayerNamesSession2.clear(); }

		PlayersSessionForLoop
		{
			const char* PlayernameString = PLAYER::GET_PLAYER_NAME(i);
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)))
			{
				if (!SecondCall) 
				{ 
					CurrentPlayerNamesSession.push_back(PlayernameString); 
				}
				else
				{
					CurrentPlayerNamesSession2.push_back(PlayernameString);
				}
			}
		}

		if (SecondCall)
		{
			for (const auto& var : CurrentPlayerNamesSession2)
			{
				if (!std::count(CurrentPlayerNamesSession.begin(), CurrentPlayerNamesSession.end(), var))
				{
					std::string NewPlayerString = "<C>" + var + "</C> joined the session.";
					Cheat::GameFunctions::MinimapNotification(CheatFunctions::StringToChar(NewPlayerString));
				}
			}
			SecondCall = false;
		}
		else
		{
			SecondCall = true;
		}
	}
}

bool Cheat::GameFunctions::IsEntityInInterior(Entity Entity)
{
	if (INTERIOR::GET_INTERIOR_FROM_ENTITY(Entity) == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Cheat::GameFunctions::AddBlipToVehicle(Vehicle Vehicle)
{
	RequestNetworkControlOfEntity(Vehicle);
	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Vehicle, true, true);
	for (int i = 0; i < 350; i++)NETWORK::SET_NETWORK_ID_CAN_MIGRATE(Vehicle, 0);
	VEHICLE::SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(Vehicle, true);
	int BlipHandle = UI::ADD_BLIP_FOR_ENTITY(Vehicle);
	UI::SET_BLIP_SPRITE(BlipHandle, 60);
	UI::SET_BLIP_NAME_FROM_TEXT_FILE(BlipHandle, "Vehicle");
}

bool Cheat::GameFunctions::DeleteVehicle(Vehicle Vehicle)
{
	RequestNetworkControlOfEntity(Vehicle);
	if (PED::IS_PED_IN_ANY_VEHICLE(Cheat::GameFunctions::PlayerPedID, false) && ENTITY::DOES_ENTITY_EXIST(Vehicle))
	{
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Vehicle, true, true);
		VEHICLE::DELETE_VEHICLE(&Vehicle);
		return true;
	}
	return false;
}

float Cheat::GameFunctions::MSToKMH(float MS)
{
	return roundf(MS * 3.6);
}

float Cheat::GameFunctions::MSToMPH(float MS)
{
	return roundf(MS * 2.2);
}

float Cheat::GameFunctions::KMHToMS(float MS)
{
	return roundf(MS * 0.27);
}

float Cheat::GameFunctions::MPHToMS(float MS)
{
	return roundf(MS * 0.44);
}

void Cheat::GameFunctions::ChangeEntityInvincibilityState(Entity EntityHandle, bool Enable)
{
	if (Enable)
	{
		ENTITY::SET_ENTITY_INVINCIBLE(EntityHandle, true);
		ENTITY::SET_ENTITY_PROOFS(EntityHandle, false, false, false, false, false, false, false, false);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(EntityHandle, false);
		VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(EntityHandle, false);
		VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(EntityHandle, false);
	}
	else
	{
		ENTITY::SET_ENTITY_INVINCIBLE(EntityHandle, false);
		ENTITY::SET_ENTITY_PROOFS(EntityHandle, false, false, false, false, false, false, false, false);
		VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(EntityHandle, true);
	}
}

const char* Cheat::GameFunctions::ReturnOnlinePlayerPictureString(Player PlayerHandle)
{
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		int Index = GLOBAL_PLAYER_PICTURE_INDEX + 2;
		for (int x = 0; x <= 150; x += 5)
		{
			int playerId = globalHandle(Index).At(x).As<int>();
			if (playerId == PlayerHandle)
			{
				int PedHeadshotHandle = globalHandle(Index).At(x).At(1).As<int>();
				if (PED::IS_PEDHEADSHOT_VALID(PedHeadshotHandle))
				{
					return PED::GET_PEDHEADSHOT_TXD_STRING(PedHeadshotHandle);
				}
			}
			if (playerId == -1)
			{
				break;
			}
		}
	}
	return "CHAR_DEFAULT";
}

VECTOR2 Cheat::GameFunctions::ReturnCursorYXCoords()
{
	return { PAD::GET_DISABLED_CONTROL_NORMAL(2, INPUT_CURSOR_X), PAD::GET_DISABLED_CONTROL_NORMAL(2, INPUT_CURSOR_Y) };
}

// https://github.com/MAFINS/MenyooSP/blob/v1.3.0/Solution/source/Menu/Menu.cpp
bool Cheat::GameFunctions::IsCursorAtXYPosition(VECTOR2 const& boxCentre, VECTOR2 const& boxSize)
{
	return (ReturnCursorYXCoords().x >= boxCentre.x - boxSize.x / 2 && ReturnCursorYXCoords().x <= boxCentre.x + boxSize.x / 2)
		&& (ReturnCursorYXCoords().y > boxCentre.y - boxSize.y / 2 && ReturnCursorYXCoords().y < boxCentre.y + boxSize.y / 2);
}

bool Cheat::CheatFeatures::CursorNavigationState = false;
void Cheat::GameFunctions::EnableDisableCursorNavigation()
{
	if (CheatFeatures::CursorNavigationState)
	{
		CheatFeatures::CursorNavigationState = false;
		if (!Controls::AllowGameplayWithCursorNavigationActive)
		{
			PLAYER::SET_PLAYER_CONTROL(GameFunctions::PlayerID, true, 0);
		}	
	}
	else
	{
		CheatFeatures::CursorNavigationState = true;
		if (!Controls::AllowGameplayWithCursorNavigationActive)
		{
			PLAYER::SET_PLAYER_CONTROL(GameFunctions::PlayerID, false, 0);
		}
	}
}

void Cheat::GameFunctions::ChangePedModelLocalPlayer(Hash PedModel)
{
	if (STREAMING::IS_MODEL_A_PED(PedModel))
	{
		while (!STREAMING::HAS_MODEL_LOADED(PedModel)) { STREAMING::REQUEST_MODEL(PedModel); GameHooking::PauseMainFiber(0); }
		PLAYER::SET_PLAYER_MODEL(PlayerID, PedModel);
		GameHooking::PauseMainFiber(100);
		PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PlayerPedID);
		PED::CLEAR_ALL_PED_PROPS(PlayerPedID);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PedModel);
	}
}

bool Cheat::GameFunctions::PlayerIsFreemodeScriptHost(Player Player)
{
	if (Player == NETWORK::NETWORK_GET_HOST_OF_SCRIPT("Freemode", 4294967295, 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Cheat::GameFunctions::CopySelectedPlayerOutfit(Player SelectedPlayer)
{
	if (SelectedPlayer != PlayerID)
	{
		Ped SelectedPlayerPedHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(SelectedPlayer);
		for (int i = 0; i < 12; i++)
		{
			PED::SET_PED_COMPONENT_VARIATION(Cheat::GameFunctions::PlayerPedID, i, PED::GET_PED_DRAWABLE_VARIATION(SelectedPlayerPedHandle, i), PED::GET_PED_TEXTURE_VARIATION(SelectedPlayerPedHandle, i), PED::GET_PED_PALETTE_VARIATION(SelectedPlayerPedHandle, i));
			GameHooking::PauseMainFiber(0, true);
		}
	}
}

int Cheat::GameFunctions::ReturnPlayerRockstarID(Player PlayerHandle)
{
	const char* RockstarIDBuffer;
	int NETWORK_HANDLE[76];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(PlayerHandle, &NETWORK_HANDLE[0], 13);
	if (NETWORK::NETWORK_IS_HANDLE_VALID(&NETWORK_HANDLE[0], 13))
	{
		RockstarIDBuffer = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&NETWORK_HANDLE[0]);
	}
	else  { RockstarIDBuffer = "0"; }
	return CheatFunctions::StringToInt(RockstarIDBuffer);
}

std::string Cheat::GameFunctions::ReturnPlayerIPAddressAsString(Player PlayerHandle)
{
	char IPBuffer[256];
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		if (PlayerHandle == GameFunctions::PlayerID && CheatFeatures::HideOwnIPAddress) { return "Hidden"; }
		auto InfoLong = *reinterpret_cast<std::uintptr_t*>(GameHooking::get_player_address(PlayerHandle) + OFFSET_PLAYER_INFO);
		auto IPAddress = reinterpret_cast<std::uint8_t*>(InfoLong + OFFSET_PLAYER_INFO_EXTERNAL_IP);
		IPAddress ? sprintf_s(IPBuffer, "%i.%i.%i.%i", IPAddress[3], IPAddress[2], IPAddress[1], IPAddress[0]) : sprintf_s(IPBuffer, "Unknown");
	}
	else
	{
		sprintf_s(IPBuffer, "N/A");
	}
	return IPBuffer;
}

std::string Cheat::GameFunctions::ReturnCurrentGTAOCharacter(bool NumberOnly)
{
	int CharacterID;
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY("MPPLY_LAST_MP_CHAR"), &CharacterID, -1);
	if (NumberOnly) { return std::to_string(CharacterID); }
	return "MP" + std::to_string(CharacterID);
}

void Cheat::GameFunctions::PlayFrontendSoundDefault(char* SoundName)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, SoundName, "HUD_FRONTEND_DEFAULT_SOUNDSET", false);
}

void Cheat::GameFunctions::MaxUpgradeAllWeapons()
{
	for (auto const& i : GameArrays::MaxUpgradeWeaponComponents)
	{
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(GameFunctions::PlayerPedID, i.WeaponHash, MISC::GET_HASH_KEY(CheatFunctions::StringToChar(i.UpgradeHash)));
	}
}

void Cheat::GameFunctions::ShowTeleportLocationsMenu(std::vector<TeleportLocationStruct> category)
{
	for (int i = 0; i < category.size(); i++)
	{
		Vector3 Coords;
		Coords.x = category[i].coordinateX;
		Coords.y = category[i].coordinateY;
		Coords.z = category[i].coordinateZ;
		if (GUI::Option(category[i].Name, ""))
		{
			GameFunctions::TeleportToCoords(GameFunctions::PlayerPedID, Coords, false, false);
		}
	}
}

// https://codepen.io/Codepixl/pen/ogWWaK
void Cheat::GameFunctions::FadeRGB(int& r, int& g, int& b)
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

bool Cheat::GameFunctions::ShowFullScreenMessage(std::string Message)
{
	for (;;)
	{
		GUI::DrawRectInGame({ 0, 0, 0, 210 }, { 0.50f, 0.45f }, { 0.30f, 0.15f });
		Cheat::GUI::DrawTextInGame("~bold~CAUTION", { 225, 0, 0, 255, FontChaletLondon }, { 0.450f, 0.370f }, { 0.55f, 0.55f }, false, true);
		Cheat::GUI::DrawTextInGame(Message, { 255, 255, 255, 255, FontChaletLondon }, { 0.500f, 0.420f}, { 0.40f, 0.40f }, true);
		Cheat::GUI::DrawTextInGame("Press ENTER to continue or BACKSPACE to go back", { 255, 255, 255, 255, FontChaletLondon }, { 0.355f, 0.495f }, { 0.30f, 0.30f }, false, true);
		if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, INPUT_FRONTEND_ACCEPT))
		{
			return true;
		}
		if (PAD::IS_DISABLED_CONTROL_JUST_PRESSED(0, INPUT_FRONTEND_CANCEL))
		{
			return false;
		}
		GameHooking::PauseMainFiber(0, false);
	}
}

void Cheat::GameFunctions::SetCharacterSkillStat(std::string Skill, int Level)
{
	STATS::STAT_SET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(ReturnCurrentGTAOCharacter() + "_SCRIPT_INCREASE_" + Skill)), Level, true);
}

int Cheat::GameFunctions::GetCharacterSkillStat(std::string Skill)
{
	int SkillLevelPercentage = 0;
	STATS::STAT_GET_INT(MISC::GET_HASH_KEY(CheatFunctions::StringToChar(ReturnCurrentGTAOCharacter() + "_SCRIPT_INCREASE_" + Skill)), &SkillLevelPercentage, -1);
	return SkillLevelPercentage;
}

void Cheat::GameFunctions::ChangeGTAOSessionType(eSessionTypes SessionType)
{
	if (SessionType >= 0 && SessionType <= 12)
	{
		globalHandle(1575015).As<int>() = (int)SessionType;
		globalHandle(1574589).As<int>() = 1;
		GameHooking::PauseMainFiber(50, false);
		globalHandle(1574589).As<int>() = 0;
		GUI::CloseMenuGUI();
	}
}

void Cheat::GameFunctions::TriggerScriptEvent(eScriptEventTypes EventType, Player TargetPlayer, int property_teleport_index)
{
	if (NETWORK::NETWORK_IS_SESSION_STARTED() && NETWORK::NETWORK_IS_PLAYER_ACTIVE(TargetPlayer))
	{
		if (EventType == eScriptEventTypes::KICK_TO_SINGLE_PLAYER)
		{
			uint64_t arguments_aray[4] = { (uint64_t)eRemoteEvents::KickToSP, (uint64_t)TargetPlayer, 0, 0 };
			SCRIPT::TRIGGER_SCRIPT_EVENT(1, arguments_aray, sizeof(arguments_aray) / sizeof(arguments_aray[0]), 1 << TargetPlayer);
		}
		else if (EventType == eScriptEventTypes::CEO_KICK)
		{
			uint64_t arguments_aray[4] = { (uint64_t)eRemoteEvents::CeoKick, (uint64_t)TargetPlayer, 1, 5 };
			SCRIPT::TRIGGER_SCRIPT_EVENT(1, arguments_aray, sizeof(arguments_aray) / sizeof(arguments_aray[0]), 1 << TargetPlayer);
		}
		else if (EventType == eScriptEventTypes::CEO_BAN)
		{
			uint64_t arguments_aray[4] = { (uint64_t)eRemoteEvents::CeoBan, (uint64_t)TargetPlayer, 1, 5 };
			SCRIPT::TRIGGER_SCRIPT_EVENT(1, arguments_aray, sizeof(arguments_aray) / sizeof(arguments_aray[0]), 1 << TargetPlayer);
		}
		else if (EventType == eScriptEventTypes::PROPERTY_TELEPORT)
		{
			if (property_teleport_index != -1)
			{
				uint64_t teleport[9] = { (uint64_t)eRemoteEvents::PropertyTeleport, TargetPlayer, 0, -1, 1, property_teleport_index, 0, 0, 0 };
				SCRIPT::TRIGGER_SCRIPT_EVENT(1, teleport, 9, (1 << TargetPlayer));
			}
		}
		else if (EventType == eScriptEventTypes::CAYO_PERICO_TELEPORT)
		{
			uint64_t arguments_aray[2] = { (uint64_t)eRemoteEvents::CayoPericoTeleport, (uint64_t)TargetPlayer };
			SCRIPT::TRIGGER_SCRIPT_EVENT(1, arguments_aray, sizeof(arguments_aray) / sizeof(arguments_aray[0]), 1 << TargetPlayer);
		}
		else if (EventType == eScriptEventTypes::FORCE_INTO_MISSION)
		{
			uint64_t arguments_aray[3] = { (uint64_t)eRemoteEvents::ForceIntoMission, (uint64_t)TargetPlayer, 0 };
			SCRIPT::TRIGGER_SCRIPT_EVENT(1, arguments_aray, sizeof(arguments_aray) / sizeof(arguments_aray[0]), 1 << TargetPlayer);
		}
	}
}