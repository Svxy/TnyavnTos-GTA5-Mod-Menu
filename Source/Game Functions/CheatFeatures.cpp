#include "../Header/Cheat Functions/FiberMain.h"

int Cheat::CheatFeatures::SelectedPlayer;
int Cheat::CheatFeatures::SpeedometerVectorPosition = 0;
int Cheat::CheatFeatures::AimbotBoneVectorPosition = 0;
int Cheat::CheatFeatures::ImpactAmmoVectorPosition = 0;
int Cheat::CheatFeatures::CustomAmmoVectorPosition = 0;
int Cheat::CheatFeatures::ParticleAmmoVectorPosition = 0;
int Cheat::CheatFeatures::FontTypeVectorPosition = 0;
int Cheat::CheatFeatures::AnimationsVectorPosition = 0;
int Cheat::CheatFeatures::ScenariosVectorPosition = 0;
int Cheat::CheatFeatures::PedMovementVectorPosition = 0;
int Cheat::CheatFeatures::OpenVehicleDoorPosition = 0;
int Cheat::CheatFeatures::CloseVehicleDoorPosition = 0;
int Cheat::CheatFeatures::FastSuperRunPosition = 0;
int Cheat::CheatFeatures::PlayerOpacityInt = 250;
bool Cheat::CheatFeatures::BlockAllScriptEvents = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_Kicks = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_CEOKick = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_CEOBan = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_CEOMoney = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_PropertyTeleport = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_CayoPericoTeleport = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_ForceIntoMission = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_Bounty = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_ClearWantedlevel = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_GameBanner = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_NetworkBail = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_Crash = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_PersonalVehicleDestroyed = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_RemoteOffradar = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_SendToCutscene = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_SendToLocation = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_SoundSpam = false;
bool Cheat::CheatFeatures::ProtectionScriptEvents_Spectate = false;
bool Cheat::CheatFeatures::HideOwnIPAddress = true;
bool Cheat::CheatFeatures::DisableTransactionErrorWarning = true;
bool Cheat::CheatFeatures::DisableCutscenes = false;
bool Cheat::CheatFeatures::HideVehiclePreview = false;
bool Cheat::CheatFeatures::ShowJoiningPlayersNotification = false;
bool Cheat::CheatFeatures::LogChatMessages = true;
bool Cheat::CheatFeatures::VehicleSpawnerSpawnInsideVehicle = false;
bool Cheat::CheatFeatures::VehicleSpawnerDeleteOldVehicle = false;
bool Cheat::CheatFeatures::VehicleSpawnerSpawnWithBlip = false;
bool Cheat::CheatFeatures::VehicleSpawnerSpawnWithGodmode = false;
bool Cheat::CheatFeatures::VehicleSpawnerSpawnMaxUpgraded = false;
bool Cheat::CheatFeatures::VehicleSpawnerSpawnAirVehicleAir = false;
int Cheat::CheatFeatures::VehicleSpawnerLicensePlateVectorPosition = 0;
std::string Cheat::CheatFeatures::VehicleSpawnerCustomLicensePlateTextString = "GTAV";
bool Cheat::CheatFeatures::HidePlayerInformationBox = false;
bool Cheat::CheatFeatures::HideSelectableInformationBox = false;
bool Cheat::CheatFeatures::ControllableAnimations = false;
bool Cheat::CheatFeatures::AllPlayersExclusionsSelf = true;
bool Cheat::CheatFeatures::AllPlayersExclusionsFriends = false;
bool Cheat::CheatFeatures::AllPlayersExclusionsHost = false;
bool Cheat::CheatFeatures::TeleportTransition = false;
bool Cheat::CheatFeatures::NoTextureFileOverwrite = false;

void Cheat::CheatFeatures::Loop()
{
	// Commonly used game functions
	GameFunctions::PlayerID = PLAYER::PLAYER_ID();
	GameFunctions::PlayerPedID = PLAYER::PLAYER_PED_ID();

	// POST initialization notification
	if (CheatFunctions::CheatInitEntirelyCompleted && !GUI::MenuGUIHasBeenOpened)
	{
		GameFunctions::InGameHelpTextMessage = "Press " + CheatFunctions::VirtualKeyCodeToString(Controls::OpenMenuGUIKey) + " to open Menu GUI";
		std::string WelcomeText = "Welcome " + (std::string)SOCIALCLUB::_SC_GET_NICKNAME() + ", have fun!";
		GameFunctions::AdvancedMinimapNotification(CheatFunctions::StringToChar(WelcomeText), "Textures", "AdvancedNotificationImage", false, 4, "TnyavnTo's GTAV Cheat", "", 0.3f, "");
		UI::DISPLAY_HELP_TEXT_THIS_FRAME("LETTERS_HELP2", false);
	}
	GameFunctions::InGameKeyboardWindowTitle.clear();

	// New cheat update notification
	if (!CheatFunctions::NewCheatVersionString.empty() && CheatFunctions::CheatInitEntirelyCompleted)
	{
		GUI::DrawTextInGame("~bold~A newer cheat version (" + CheatFunctions::NewCheatVersionString + ") is available on GitHub.", { 255, 255, 255, 255, FontChaletLondon }, { 0.003f, 0.001f }, { 0.25f, 0.25f }, false);
	}

	// New session member notification feature
	GameFunctions::CheckNewSessionMembersLoop();

	// Speedometer
	if (PED::IS_PED_IN_ANY_VEHICLE(GameFunctions::PlayerPedID, false)) 
	{
		std::ostringstream Speed;
		if (MISC::SHOULD_USE_METRIC_MEASUREMENTS())
		{
			Speed << GameFunctions::MSToKMH(ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(GameFunctions::PlayerPedID, 0))) << " KM/H";
		}
		else
		{
			Speed << GameFunctions::MSToMPH(ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(GameFunctions::PlayerPedID, 0))) << " MP/H";
		}
		if (SpeedometerVectorPosition == 1 || SpeedometerVectorPosition == 3) { GUI::DrawTextInGame(Speed.str(), { 0, 0, 255, 255 }, { 0.85f, 0.5000f }, { 0.70f, 0.70f }, false); }
		if (SpeedometerVectorPosition == 2 || SpeedometerVectorPosition == 3) { VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(GameFunctions::PlayerPedID, 0), CheatFunctions::StringToChar(Speed.str())); }
	}

	// Impact ammo
	if (ImpactAmmoVectorPosition != 0)
	{
		if (ImpactAmmoVectorPosition == 1)
		{
			Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_FRAMEFLAGS }, FrameFlagFireAmmo);
		}
		else if (ImpactAmmoVectorPosition == 2)
		{
			if (PED::IS_PED_SHOOTING(Cheat::GameFunctions::PlayerPedID))
			{
				Vector3 coords;
				if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(Cheat::GameFunctions::PlayerPedID, &coords))
				{
					MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 30, coords.x, coords.y, coords.z, 250, 0, MISC::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET"), 0, 1, 1, 500);
				}
			}
		}
		else if (ImpactAmmoVectorPosition == 3)
		{
			if (PED::IS_PED_SHOOTING(GameFunctions::PlayerPedID))
			{
				Vector3 iCoord;
				if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(GameFunctions::PlayerPedID, &iCoord))
				{
					ENTITY::SET_ENTITY_COORDS(GameFunctions::PlayerPedID, iCoord.x, iCoord.y, iCoord.z + 1, false, false, true, true);
				}
			}
		}
		else if (ImpactAmmoVectorPosition == 4)
		{
			Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_FRAMEFLAGS }, FrameFlagExplosiveAmmo);
		}
		else if (ImpactAmmoVectorPosition == 5)
		{
			Vector3 iCoord;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(GameFunctions::PlayerPedID, &iCoord))
			{
				
				GameFunctions::MinimapNotification(CheatFunctions::StringToChar(std::to_string(iCoord.x) + ", " + std::to_string(iCoord.y) + ", " + std::to_string(iCoord.z)));
			}
		}
	}

	// Sprint Speed
	if (FastSuperRunPosition != 0 && (TASK::IS_PED_SPRINTING(GameFunctions::PlayerPedID) || TASK::IS_PED_RUNNING(GameFunctions::PlayerPedID)))
	{
		if (FastSuperRunPosition == 1)
		{
			PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(GameFunctions::PlayerID, 1.49f);
		}
		else if (FastSuperRunPosition == 2)
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(GameFunctions::PlayerPedID, 1, 0.0f, 1.3f, 0.f, 0.0f, 0.0f, 0.0f, 0, true, true, true, false, true);
		}
	}

	// Custom ammo
	if (CustomAmmoVectorPosition != 0)
	{
		Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 dir = GameFunctions::RotationToDirection(&rot);
		Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
		Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(GameFunctions::PlayerPedID, false);
		float spawnDistance = GameFunctions::GetDistanceBetweenTwoVectors(&camPosition, &playerPosition);
		spawnDistance += 0.25;
		Vector3 spawnPosition = GameFunctions::AddTwoVectors(&camPosition, &GameFunctions::MultiplyVector(&dir, spawnDistance));
		float endDistance = GameFunctions::GetDistanceBetweenTwoVectors(&camPosition, &playerPosition);
		endDistance += 1000;
		Vector3 endPosition = GameFunctions::AddTwoVectors(&camPosition, &GameFunctions::MultiplyVector(&dir, endDistance));

		Hash WeaponAsset;
		if (CustomAmmoVectorPosition == 1)
		{
			WeaponAsset = MISC::GET_HASH_KEY("VEHICLE_WEAPON_NOSE_TURRET_VALKYRIE");
		}
		else if (CustomAmmoVectorPosition == 2)
		{
			WeaponAsset = MISC::GET_HASH_KEY("VEHICLE_WEAPON_TANK");
		}
		else if (CustomAmmoVectorPosition == 3)
		{
			WeaponAsset = MISC::GET_HASH_KEY("WEAPON_VEHICLE_ROCKET");
		}
		else if (CustomAmmoVectorPosition == 4)
		{
			WeaponAsset = MISC::GET_HASH_KEY("WEAPON_FIREWORK");
		}

		if (PED::IS_PED_ON_FOOT(Cheat::GameFunctions::PlayerPedID) && PED::IS_PED_SHOOTING(Cheat::GameFunctions::PlayerPedID))
		{
			if (!WEAPON::HAS_WEAPON_ASSET_LOADED(WeaponAsset))
			{
				WEAPON::REQUEST_WEAPON_ASSET(WeaponAsset, 31, 0);
				while (!WEAPON::HAS_WEAPON_ASSET_LOADED(WeaponAsset)) { GameHooking::PauseMainFiber(0); }
			}
			MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(spawnPosition.x, spawnPosition.y, spawnPosition.z, endPosition.x, endPosition.y, endPosition.z, 250, 1, WeaponAsset, GameFunctions::PlayerPedID, 1, 0, -1.0);
		}
	}

	// Particle ammo
	if (ParticleAmmoVectorPosition != 0)
	{
		const char* PTFX;
		const char* EffectName;

		if (ParticleAmmoVectorPosition == 1)
		{
			PTFX = "scr_rcbarry2";
			EffectName = "muz_clown";
		}

		Vector3 BulletCoord;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(GameFunctions::PlayerPedID, &BulletCoord))
		{
			while (!STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(PTFX))
			{
				STREAMING::REQUEST_NAMED_PTFX_ASSET(PTFX);
				GameHooking::PauseMainFiber(0, false); 
			}
			GRAPHICS::USE_PARTICLE_FX_ASSET(PTFX);
			GRAPHICS::START_NETWORKED_PARTICLE_FX_NON_LOOPED_AT_COORD(EffectName, BulletCoord.x, BulletCoord.y, BulletCoord.z + 0.3f, 0.f, 0.f, 0.f, 1.f, true, true, true, true);
		}
		STREAMING::REMOVE_NAMED_PTFX_ASSET(PTFX);
	}

	// Disable Transaction Error Warnings
	if (DisableTransactionErrorWarning)
	{
		globalHandle(GLOBAL_TRANS_ERROR_SHOWN_1).As<BOOL>() = false;
		globalHandle(GLOBAL_TRANS_ERROR_SHOWN_2).As<BOOL>() = false;
		globalHandle(GLOBAL_TRANS_ERROR_SHOWN_3).As<BOOL>() = false;
	}

	// Disable Cutscenes
	if (DisableCutscenes)
	{
		if (CUTSCENE::IS_CUTSCENE_ACTIVE())
		{
			CUTSCENE::STOP_CUTSCENE_IMMEDIATELY();
		}
	}

	GodmodeBool ? Godmode(true) : GodmodeWasEnabled ? Godmode(false), GodmodeWasEnabled = false : NULL;
	NeverWantedBool ? NeverWanted() : NULL;
	NoWeaponReloadBool ? NoWeaponReload() : NULL;
	InfiniteAmmoBool ? InfiniteAmmo(true) : InfiniteAmmoWasEnabled ? InfiniteAmmo(false), InfiniteAmmoWasEnabled = false : NULL;
	SlowMotionBool ? SlowMotion(true) : SlowMotionWasEnabled ? SlowMotion(false), SlowMotionWasEnabled = false : NULL;
	WorldBlackoutBool ? WorldBlackout(true) : WorldBlackoutWasEnabled ? WorldBlackout(false), WorldBlackoutWasEnabled = false : NULL;
	GravityGunBool ? GravityGun() : NULL;
	DisableHUDBool ? DisableHUD() : NULL;
	NoGravityBool ? NoGravity(true) : NoGravityWasEnabled ? NoGravity(false), NoGravityWasEnabled = false : NULL;
	WorldSnowLocalBool ? WorldSnowLocal(true) : WorldSnowLocalWasEnabled ? WorldSnowLocal(false), WorldSnowLocalWasEnabled = false : NULL;
	AutoTeleportToWaypointBool ? AutoTeleportToWaypoint() : NULL;
	OneHitKillBool ? OneHitKill() : OneHitKillWasEnabled ? PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(GameFunctions::PlayerID, 1.f), PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(GameFunctions::PlayerID, 1.f, false), OneHitKillWasEnabled  = false: NULL;
	PauseTimeBool ? PauseTime(true) : PauseTime(false);
	ExplosiveMeleeBool ? ExplosiveMelee() : NULL;
	OrbitalCannonCooldownBypassBool ? OrbitalCannonCooldownBypass() : NULL;
	ProtectionVoteKickBool ? ProtectionVoteKick(true) : ProtectionVoteKick(false);
	ProtectionFreezeBool ? ProtectionFreeze(true) : ProtectionFreeze(false);
	ProtectionWorldEventsBool ? ProtectionWorldEvents(true) : ProtectionWorldEvents(false);
	ProtectionVehicleBool ? ProtectionVehicle(true) : ProtectionVehicle(false);
	ProtectionAlterWantedLevelBool ? ProtectionAlterWantedLevel(true) : ProtectionAlterWantedLevel(false);
	ProtectionGiveRemoveWeaponsBool ? ProtectionGiveRemoveWeapons(true) : ProtectionGiveRemoveWeapons(false);
	SuperJumpBool ? SuperJump() : NULL;
	ShowFPSBool ? ShowFPS() : NULL;
	JumpAroundModeBool ? JumpAroundMode() : NULL;
	VehicleHornBoostBool ? VehicleHornBoost() : NULL;
	VehicleGodmodeBool ? VehicleGodmode(true) : VehicleGodmode(false);
	VehicleInvisibleBool ? VehicleInvisible(true) : VehicleInvisible(false);
	PlayerInvisibleLocalBool ? PlayerInvisibleLocal(true) : PlayerInvisibleLocal(false);
	PlayerInvisibleNetworkBool ? PlayerInvisibleNetwork(true) : PlayerInvisibleNetwork(false);
	MobileRadioBool ? MobileRadio(true) : MobileRadio(false);
	WeaponRapidFireBool ? WeaponRapidFire() : NULL;
	PlayerIgnoredBool ? PlayerIgnored(true) : PlayerIgnored(false);
	NoClipBool ? NoClip() : NoClipWasEnabled ? ENTITY::SET_ENTITY_COLLISION(Cheat::GameFunctions::PlayerPedID, true, true), NoClipWasEnabled = false : NULL;
	RainbowVehicleBool ? RainbowVehicle() : NULL;
	DeleteGunBool ? DeleteGun() : NULL;
	NerfBulletsBool ? NerfBullets() : NerfBulletsWasEnabled ? PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(GameFunctions::PlayerID, 1.f), NerfBulletsWasEnabled = false : NULL;
	SpectatePlayerBool ? SpectatePlayer(true) : SpectatePlayerWasEnabled ? SpectatePlayer(false), SpectatePlayerWasEnabled = false : NULL;
	NoRagdollAndSeatbeltBool ? NoRagdollAndSeatbelt(true) : NoRagdollAndSeatbelt(false);
	FreezeSelectedPlayerBool ? FreezeSelectedPlayer() : NULL;
	FreezeAllPlayersBool ? FreezeAllPlayers() : NULL;
	TriggerBotBool ? TriggerBot() : NULL;
	SuperBrakesBool ? SuperBrakes() : NULL;
	TinyPlayerBool ? TinyPlayer(true) : TinyPlayer(false);
	UnlimitedRocketBoostBool ? UnlimitedRocketBoost() : NULL;
	ShootEntitiesBool ? ShootEntities() : NULL;
	PlayerESPBool ? PlayerESP() : NULL;
	OffRadarBool ? OffRadar() : NULL;
	ExplodeLoopSelectedPlayerBool ? ExplodeLoopSelectedPlayer() : NULL;
	DriveOnWaterBool ? DriveOnWater() : NULL;
	SuperManBool ? SuperMan() : NULL;
	ShakeCamSelectedPlayerBool ? ShakeCamSelectedPlayer() : NULL;
	RainbowGunBool ? RainbowGun() : NULL;
	DisableMobilePhoneBool ? DisableMobilePhone() : NULL;
	NoIdleKickBool ? NoIdleKick() : NULL;
	CopsTurnBlindEyeBool ? CopsTurnBlindEye() : NULL;
	VehicleWeaponsBool ? VehicleWeapons() : NULL;
	AutoGiveAllWeaponsBool ? AutoGiveAllWeapons() : NULL;
	AutoGiveAllWeaponUpgradesBool ? AutoGiveAllWeaponUpgrades() : NULL;
	FreeCamBool ? FreeCam(true) : FreeCam(false);
	EntityInformationGunBool ? EntityInformationGun() : NULL;
	CrossHairBool ? CrossHair() : NULL;
	RGBDiscoBool ? RGBDisco() : !RGBDiscoFirstCall ? RGBDiscoFirstCall = true : NULL;
	FreezeStationBool ? FreezeStation() : FreezeStationWasEnabled ? AUDIO::UNFREEZE_RADIO_STATION(AUDIO::GET_PLAYER_RADIO_STATION_NAME()), FreezeStationWasEnabled = false : NULL;
	HideMinimapBool ? HideMinimap() : HideMinimapWasEnabled ? UI::DISPLAY_RADAR(true), HideMinimapWasEnabled = false : NULL;
	WeaponInvisibilityBool ? WeaponInvisibility(true) : WeaponInvisibilityWasEnabled ? WeaponInvisibility(false), WeaponInvisibilityWasEnabled = false : NULL;
	SessionLockFriendsOnlyBool ? SessionLockFriendsOnly() : NULL;
	ShowTVBool ? ShowTV(true) : ShowTVWasEnabled ? ShowTV(false), ShowTVWasEnabled = false : NULL;
}

bool Cheat::CheatFeatures::GodmodeBool = false;
bool Cheat::CheatFeatures::GodmodeWasEnabled = false;
void Cheat::CheatFeatures::Godmode(bool toggle)
{
	GodmodeWasEnabled = true;
	ENTITY::SET_ENTITY_INVINCIBLE(GameFunctions::PlayerPedID, toggle);
}

bool Cheat::CheatFeatures::NeverWantedBool = false;
void Cheat::CheatFeatures::NeverWanted()
{
	if (PLAYER::GET_PLAYER_WANTED_LEVEL(GameFunctions::PlayerID) > 0)
	{
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(GameFunctions::PlayerID);
	}
}

bool Cheat::CheatFeatures::NoWeaponReloadBool = false;
void Cheat::CheatFeatures::NoWeaponReload()
{
	Hash EquippedWeapon;
	if (WEAPON::GET_CURRENT_PED_WEAPON(GameFunctions::PlayerPedID, &EquippedWeapon, false))
	{
		if (EquippedWeapon != 0xB62D1F67 && EquippedWeapon != 0x42BF8A85) //Skip if Widowmaker or Minigun; it won't shoot when this is looped
		{
			WEAPON::REFILL_AMMO_INSTANTLY(GameFunctions::PlayerPedID);
		}
	}
}

bool Cheat::CheatFeatures::InfiniteAmmoBool = false;
bool Cheat::CheatFeatures::InfiniteAmmoWasEnabled = false;
void Cheat::CheatFeatures::InfiniteAmmo(bool toggle)
{
	InfiniteAmmoWasEnabled = true;
	for (auto const& i : GameArrays::WeaponsHashList)
	{
		WEAPON::SET_PED_INFINITE_AMMO(GameFunctions::PlayerPedID, toggle, i.WeaponHash);
	}
}

bool Cheat::CheatFeatures::SlowMotionBool = false;
bool Cheat::CheatFeatures::SlowMotionWasEnabled = false;
void Cheat::CheatFeatures::SlowMotion(bool toggle)
{
	if (toggle)
	{
		SlowMotionWasEnabled = true;
		MISC::SET_TIME_SCALE(0.2f);
	}
	else
	{
		MISC::SET_TIME_SCALE(1.f);
	}
}

bool Cheat::CheatFeatures::WorldBlackoutBool = false;
bool Cheat::CheatFeatures::WorldBlackoutWasEnabled = false;
void Cheat::CheatFeatures::WorldBlackout(bool toggle)
{
	if (toggle)
	{
		WorldBlackoutWasEnabled = true;
		GRAPHICS::SET_ARTIFICIAL_LIGHTS_STATE(toggle);
	}
	else
	{
		GRAPHICS::SET_ARTIFICIAL_LIGHTS_STATE(toggle);
	}
}

float Cheat::CheatFeatures::GravityGunEntityDistance = 5.f;
bool Cheat::CheatFeatures::GravityGunBool = false;
void Cheat::CheatFeatures::GravityGun()
{
	if (CAM::GET_FOLLOW_PED_CAM_VIEW_MODE() == PedCamViewModes::FirstPerson)
	{
		CAM::SET_FOLLOW_PED_CAM_VIEW_MODE(PedCamViewModes::ThirdPersonMedium);
	}
	PAD::DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);

	if (!CursorNavigationState)
	{
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_CURSOR_SCROLL_UP) && GravityGunEntityDistance < 25.f)
		{
			GravityGunEntityDistance += 1.f;
		}
		else if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_CURSOR_SCROLL_DOWN) && GravityGunEntityDistance > 5.f)
		{
			GravityGunEntityDistance -= 1.f;
		}
	}

	Entity EntityTarget;
	DWORD equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(GameFunctions::PlayerPedID, &equippedWeapon, true);

	Vector3 dir = Cheat::GameFunctions::RotationToDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0));
	Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
	float spawnDistance = GameFunctions::GetDistanceBetweenTwoVectors(&camPosition, &ENTITY::GET_ENTITY_COORDS(GameFunctions::PlayerPedID, false));
	spawnDistance += GravityGunEntityDistance;
	Vector3 spawnPosition = GameFunctions::AddTwoVectors(&camPosition, &GameFunctions::MultiplyVector(&dir, spawnDistance));

	Player tempPed = GameFunctions::PlayerID;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(GameFunctions::PlayerID, &EntityTarget) && PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_AIM))
	{
		Vector3 EntityTargetPos = ENTITY::GET_ENTITY_COORDS(EntityTarget, false);
		PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
		if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, false))
		{
			EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
		}

		GameFunctions::RequestNetworkControlOfEntity(EntityTarget);

		if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget))
		{
			ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
		}

		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityTarget, spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 0);

		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_AIM))
		{
			ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
			ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
			PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
		}
	}
	if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(Cheat::GameFunctions::PlayerID, &EntityTarget))
	{
		PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
	}
}

bool Cheat::CheatFeatures::DisableHUDBool = false;
void Cheat::CheatFeatures::DisableHUD()
{
	UI::HIDE_HUD_AND_RADAR_THIS_FRAME();
}

bool Cheat::CheatFeatures::HideMinimapBool = false;
bool Cheat::CheatFeatures::HideMinimapWasEnabled = false;
void Cheat::CheatFeatures::HideMinimap()
{
	UI::DISPLAY_RADAR(false);
	HideMinimapWasEnabled = true;
}

bool Cheat::CheatFeatures::NoGravityBool = false;
bool Cheat::CheatFeatures::NoGravityWasEnabled = false;
void Cheat::CheatFeatures::NoGravity(bool toggle)
{
	if (toggle)
	{
		NoGravityWasEnabled = true;
		MISC::SET_GRAVITY_LEVEL(3);
	}
	else
	{
		MISC::SET_GRAVITY_LEVEL(0);
	}
}

bool Cheat::CheatFeatures::WorldSnowLocalBool = false;
bool Cheat::CheatFeatures::WorldSnowLocalWasEnabled = false;
void Cheat::CheatFeatures::WorldSnowLocal(bool toggle)
{
	WorldSnowLocalWasEnabled = true;
	globalHandle(GLOBAL_SNOW[0]).At(GLOBAL_SNOW[1]).As<bool>() = toggle;
}

bool Cheat::CheatFeatures::AutoTeleportToWaypointBool = false;
void Cheat::CheatFeatures::AutoTeleportToWaypoint()
{
	if (!UI::IS_PAUSE_MENU_ACTIVE()) 
	{
		if (UI::IS_WAYPOINT_ACTIVE()) 
		{
			GameFunctions::TeleportToBlipCoord(SpriteWaypoint); 
			UI::SET_WAYPOINT_OFF();
		}
	}
}

bool Cheat::CheatFeatures::OneHitKillBool = false;
bool Cheat::CheatFeatures::OneHitKillWasEnabled = false;
void Cheat::CheatFeatures::OneHitKill()
{
	OneHitKillWasEnabled = true;
	PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(GameFunctions::PlayerID, 999999.f);
	PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(GameFunctions::PlayerID, 999999.f, false);
}

bool PauseTime_IsCurrentTimeSet = false;
int CurrentHourPauseTime;
int CurrentMinutePauseTime;
int CurrentSecondPauseTime;
bool Cheat::CheatFeatures::PauseTimeBool = false;
void Cheat::CheatFeatures::PauseTime(bool toggle)
{
	if (toggle)
	{
		if (!PauseTime_IsCurrentTimeSet)
		{
			PauseTime_IsCurrentTimeSet = true;
			CurrentHourPauseTime = CLOCK::GET_CLOCK_HOURS();
			CurrentMinutePauseTime = CLOCK::GET_CLOCK_MINUTES();
			CurrentSecondPauseTime = CLOCK::GET_CLOCK_SECONDS();
		}
		NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(CurrentHourPauseTime, CurrentMinutePauseTime, CurrentSecondPauseTime);
	}
	else
	{
		PauseTime_IsCurrentTimeSet = false;
	}
}

bool Cheat::CheatFeatures::ExplosiveMeleeBool = false;
void Cheat::CheatFeatures::ExplosiveMelee()
{
	Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_FRAMEFLAGS }, FrameFlagExplosiveMelee);
}

bool Cheat::CheatFeatures::OrbitalCannonCooldownBypassBool = false;
void Cheat::CheatFeatures::OrbitalCannonCooldownBypass()
{
	if (NETWORK::NETWORK_IS_SESSION_STARTED()) { STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ORBITAL_CANNON_COOLDOWN"), 0, true); STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_ORBITAL_CANNON_COOLDOWN"), 0, true); }
}

bool Cheat::CheatFeatures::ProtectionVoteKickBool = false;
void Cheat::CheatFeatures::ProtectionVoteKick(bool toggle)
{
	GameHooking::defuseEvent(KICK_VOTES_EVENT, toggle);
}

bool Cheat::CheatFeatures::ProtectionFreezeBool = false;
void Cheat::CheatFeatures::ProtectionFreeze(bool toggle)
{
	GameHooking::defuseEvent(RAGDOLL_REQUEST_EVENT, toggle);
	GameHooking::defuseEvent(INCIDENT_ENTITY_EVENT, toggle);
	GameHooking::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, toggle);
}

bool Cheat::CheatFeatures::ProtectionWorldEventsBool = false;
void Cheat::CheatFeatures::ProtectionWorldEvents(bool toggle)
{
	GameHooking::defuseEvent(NETWORK_PTFX_EVENT, toggle);
	GameHooking::defuseEvent(FIRE_EVENT, toggle);
	GameHooking::defuseEvent(EXPLOSION_EVENT, toggle);
	GameHooking::defuseEvent(START_PROJECTILE_EVENT, toggle);
	GameHooking::defuseEvent(RAGDOLL_REQUEST_EVENT, toggle);
	GameHooking::defuseEvent(CLEAR_AREA_EVENT, toggle);
	GameHooking::defuseEvent(CLEAR_RECTANGLE_AREA_EVENT, toggle);
	GameHooking::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, toggle);
	GameHooking::defuseEvent(MODIFY_VEHICLE_LOCK_WORD_STATE_DATA, toggle);
	GameHooking::defuseEvent(BLOW_UP_VEHICLE_EVENT, toggle);
	GameHooking::defuseEvent(INFORM_SILENCED_GUNSHOT_EVENT, toggle);
	GameHooking::defuseEvent(PED_PLAY_PAIN_EVENT, toggle);
	GameHooking::defuseEvent(REQUEST_DETACHMENT_EVENT, toggle);
	GameHooking::defuseEvent(VEHICLE_COMPONENT_CONTROL_EVENT, toggle);
	GameHooking::defuseEvent(SCRIPTED_GAME_EVENT, toggle);
}

bool Cheat::CheatFeatures::ProtectionVehicleBool = false;
void Cheat::CheatFeatures::ProtectionVehicle(bool toggle)
{
	GameHooking::defuseEvent(VEHICLE_COMPONENT_CONTROL_EVENT, toggle);
	GameHooking::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, toggle);
	GameHooking::defuseEvent(MODIFY_VEHICLE_LOCK_WORD_STATE_DATA, toggle);
	GameHooking::defuseEvent(BLOW_UP_VEHICLE_EVENT, toggle);
}

bool Cheat::CheatFeatures::ProtectionAlterWantedLevelBool = false;
void Cheat::CheatFeatures::ProtectionAlterWantedLevel(bool toggle)
{
	GameHooking::defuseEvent(ALTER_WANTED_LEVEL_EVENT, toggle);
}

bool Cheat::CheatFeatures::ProtectionGiveRemoveWeaponsBool = false;
void Cheat::CheatFeatures::ProtectionGiveRemoveWeapons(bool toggle)
{
	GameHooking::defuseEvent(GIVE_WEAPON_EVENT, toggle);
	GameHooking::defuseEvent(REMOVE_WEAPON_EVENT, toggle);
	GameHooking::defuseEvent(REMOVE_ALL_WEAPONS_EVENT, toggle);
}

bool Cheat::CheatFeatures::SuperJumpBool = false;
void Cheat::CheatFeatures::SuperJump()
{
	MISC::SET_SUPER_JUMP_THIS_FRAME(Cheat::GameFunctions::PlayerID);
}

bool Cheat::CheatFeatures::ShowFPSBool = false;
void Cheat::CheatFeatures::ShowFPS()
{
	static int		iFrames = 0;
	static clock_t	clockFrames = clock();
	static float	iFps;
	iFrames++;
	clock_t dif = clock() - clockFrames;
	if (dif > 500)
	{
		iFps = iFrames / (dif / 1000.f);
		iFrames = 0;
		clockFrames = clock();
	}

	std::string str = std::to_string(iFps);
	while (str.size() > str.find(".")) { str.pop_back(); }
	std::string MessageString = "FPS: " + str;
	GUI::DrawTextInGame(MessageString, { 255, 255, 255, 255 }, { 0.50f, 0.002f }, { 0.30f, 0.30f }, false);
}

bool Cheat::CheatFeatures::JumpAroundModeBool = false;
void Cheat::CheatFeatures::JumpAroundMode()
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Vehicle* vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(Cheat::GameFunctions::PlayerPedID, vehs);

	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(Cheat::GameFunctions::PlayerPedID, false))
		{
			if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(vehs[OffsetID]))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(vehs[OffsetID], 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0);
			}
		}
	}
}

bool FreeCamFeaturedUsed = false;
bool Cheat::CheatFeatures::FreeCamBool = false;
Cam FreeCamHandle;
void Cheat::CheatFeatures::FreeCam(bool toggle)
{
	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	Vector3 coord = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 p_coord = { 0, 0, 0 };

	if (toggle)
	{
		if (CAM::GET_FOLLOW_PED_CAM_VIEW_MODE() == PedCamViewModes::FirstPerson)
		{
			CAM::SET_FOLLOW_PED_CAM_VIEW_MODE(PedCamViewModes::ThirdPersonMedium);
		}
		FreeCamFeaturedUsed = true;
		if (!CAM::DOES_CAM_EXIST(FreeCamHandle))
		{
			FreeCamHandle = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", true);
			CAM::SET_CAM_ROT(FreeCamHandle, rot.x, rot.y, rot.z, 0);
			CAM::SET_CAM_COORD(FreeCamHandle, coord.x, coord.y, coord.z);
		}

		CAM::RENDER_SCRIPT_CAMS(true, true, 700, true, true, false);
		CAM::SET_CAM_ACTIVE(FreeCamHandle, 1);
		CAM::SET_CAM_ROT(FreeCamHandle, rot.x, rot.y, rot.z, 0);

		p_coord = ENTITY::GET_ENTITY_COORDS(Cheat::GameFunctions::PlayerPedID, false);

		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(GameFunctions::PlayerPedID, p_coord.x, p_coord.y, p_coord.z, 0, 0, 0);
		PLAYER::DISABLE_PLAYER_FIRING(GameFunctions::PlayerPedID, true);
		UI::HIDE_HUD_AND_RADAR_THIS_FRAME();

		float speed = .5f;
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_SPRINT))
		{
			speed += .3f;
		}

		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_MOVE_UD)) // S key
		{
			speed /= -1;
			Vector3 c = Cheat::GameFunctions::AddTwoVectors(&CAM::GET_CAM_COORD(FreeCamHandle), &Cheat::GameFunctions::MultiplyVector(&GameFunctions::RotationToDirection(&rot), speed));
			CAM::SET_CAM_COORD(FreeCamHandle, c.x, c.y, c.z);
		}

		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_MOVE_UP_ONLY)) // W key
		{
			Vector3 c = Cheat::GameFunctions::AddTwoVectors(&CAM::GET_CAM_COORD(FreeCamHandle), &Cheat::GameFunctions::MultiplyVector(&GameFunctions::RotationToDirection(&rot), speed));
			CAM::SET_CAM_COORD(FreeCamHandle, c.x, c.y, c.z);
		}
	}
	else
	{
		if (FreeCamFeaturedUsed)
		{
			FreeCamFeaturedUsed = false;
			CAM::RENDER_SCRIPT_CAMS(false, true, 10, false, false, false);
			CAM::SET_CAM_ACTIVE(FreeCamHandle, false);
			CAM::DESTROY_CAM(FreeCamHandle, true);
		}
	}
}


bool Cheat::CheatFeatures::VehicleHornBoostBool = false;
void Cheat::CheatFeatures::VehicleHornBoost()
{
	if (PLAYER::IS_PLAYER_PRESSING_HORN(GameFunctions::PlayerID))
	{
		Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(GameFunctions::PlayerID), false);
		GameFunctions::RequestNetworkControlOfEntity(Veh);
		VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 70);
	}
}

bool Cheat::CheatFeatures::VehicleGodmodeBool = false;
void Cheat::CheatFeatures::VehicleGodmode(bool toggle)
{
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(Cheat::GameFunctions::PlayerPedID);
	if (toggle)
	{
		GameFunctions::ChangeEntityInvincibilityState(veh, true);
	}
	else
	{
		GameFunctions::ChangeEntityInvincibilityState(veh, false);
	}
}

bool Cheat::CheatFeatures::VehicleInvisibleBool = false;
void Cheat::CheatFeatures::VehicleInvisible(bool toggle)
{
	ENTITY::SET_ENTITY_VISIBLE(PED::GET_VEHICLE_PED_IS_USING(Cheat::GameFunctions::PlayerPedID), !toggle, false);
}

bool Cheat::CheatFeatures::PlayerInvisibleLocalBool = false;
void Cheat::CheatFeatures::PlayerInvisibleLocal(bool toggle)
{
	ENTITY::SET_ENTITY_VISIBLE(GameFunctions::PlayerPedID, !toggle, false);
}

bool Cheat::CheatFeatures::PlayerInvisibleNetworkBool = false;
void Cheat::CheatFeatures::PlayerInvisibleNetwork(bool toggle)
{
	NETWORK::_NETWORK_SET_ENTITY_INVISIBLE_TO_NETWORK(GameFunctions::PlayerPedID, toggle);
}

bool Cheat::CheatFeatures::MobileRadioBool = false;
void Cheat::CheatFeatures::MobileRadio(bool toggle)
{
	AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(toggle);
}

bool Cheat::CheatFeatures::FreezeStationBool = false;
bool Cheat::CheatFeatures::FreezeStationWasEnabled = false;
void Cheat::CheatFeatures::FreezeStation()
{
	AUDIO::FREEZE_RADIO_STATION(AUDIO::GET_PLAYER_RADIO_STATION_NAME());
	FreezeStationWasEnabled = true;
}

bool Cheat::CheatFeatures::WeaponRapidFireBool = false;
void Cheat::CheatFeatures::WeaponRapidFire()
{
	if (!PED::IS_PED_IN_ANY_VEHICLE(GameFunctions::PlayerPedID, false)) 
	{
		PLAYER::DISABLE_PLAYER_FIRING(GameFunctions::PlayerPedID, true);
		Vector3 GameplayCamDirection = GameFunctions::RotationToDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0));
		Vector3 StartCoords = GameFunctions::AddVector(CAM::GET_FINAL_RENDERED_CAM_COORD(), GameFunctions::MultiplyVector(GameplayCamDirection, 1.0f));
		Vector3 EndCoords = GameFunctions::AddVector(StartCoords, GameFunctions::MultiplyVector(GameplayCamDirection, 500.0f));
		Hash weaponhash;
		WEAPON::GET_CURRENT_PED_WEAPON(GameFunctions::PlayerPedID, &weaponhash, false);
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_ATTACK) && !UI::IS_PAUSE_MENU_ACTIVE())
		{
			MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(StartCoords.x, StartCoords.y, StartCoords.z, EndCoords.x, EndCoords.y, EndCoords.z, 50, true, weaponhash, Cheat::GameFunctions::PlayerPedID, true, false, 0xbf800000);
		}
	}
}

bool Cheat::CheatFeatures::PlayerIgnoredBool = false;
void Cheat::CheatFeatures::PlayerIgnored(bool toggle)
{
	PLAYER::SET_EVERYONE_IGNORE_PLAYER(GameFunctions::PlayerPedID, toggle);
}

bool Cheat::CheatFeatures::NoClipBool = false;
bool Cheat::CheatFeatures::NoClipWasEnabled = false;
void Cheat::CheatFeatures::NoClip()
{
	NoClipWasEnabled = true;
	float x, y, z;
	float d = 0.999999f;

	Cheat::GameFunctions::GetCameraDirection(&x, &y, &z);

	if (!PED::IS_PED_ON_FOOT(GameFunctions::PlayerPedID) && PED::IS_PED_IN_ANY_VEHICLE(GameFunctions::PlayerPedID, false))
	{
		Vehicle CurrentVehicle = PED::GET_VEHICLE_PED_IS_IN(Cheat::GameFunctions::PlayerPedID, false);
		GameFunctions::RequestNetworkControlOfEntity(CurrentVehicle);
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(CurrentVehicle, false);
		Vector3 rotation = CAM::GET_GAMEPLAY_CAM_ROT(0);

		ENTITY::SET_ENTITY_COLLISION(CurrentVehicle, true, true);
		ENTITY::SET_ENTITY_ROTATION(CurrentVehicle, rotation.x, rotation.y, rotation.z, 2, 1);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(CurrentVehicle, Pos.x, Pos.y, Pos.z, 0, 0, 0);
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_MOVE_UP_ONLY)) // W key
		{
			ENTITY::SET_ENTITY_COLLISION(CurrentVehicle, false, false);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(CurrentVehicle, Pos.x + (x * d), Pos.y + (y * d), Pos.z + (z * d), 0, 0, 0);
		}
	}
	else
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(GameFunctions::PlayerPedID, false);

		Vector3 rotation = CAM::GET_GAMEPLAY_CAM_ROT(0);
		ENTITY::SET_ENTITY_COLLISION(GameFunctions::PlayerPedID, true, true);
		ENTITY::SET_ENTITY_ROTATION(GameFunctions::PlayerPedID, rotation.x, rotation.y, rotation.z, 2, 1);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(GameFunctions::PlayerPedID, Pos.x, Pos.y, Pos.z, 0, 0, 0);
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_MOVE_UP_ONLY)) // W key
		{
			ENTITY::SET_ENTITY_COLLISION(GameFunctions::PlayerPedID, false, false);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(GameFunctions::PlayerPedID, Pos.x + (x * d), Pos.y + (y * d), Pos.z + (z * d), 0, 0, 0);
		}
	}
}

int RainbowVehicle_Red = 255, RainbowVehicle_Green, RainbowVehicle_Blue;
bool Cheat::CheatFeatures::RainbowVehicleBool = false;
void Cheat::CheatFeatures::RainbowVehicle()
{
	GameFunctions::FadeRGB(RainbowVehicle_Red, RainbowVehicle_Green, RainbowVehicle_Blue);
	VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(PED::GET_VEHICLE_PED_IS_USING(GameFunctions::PlayerPedID), RainbowVehicle_Red, RainbowVehicle_Green, RainbowVehicle_Blue);
	VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(PED::GET_VEHICLE_PED_IS_USING(GameFunctions::PlayerPedID), RainbowVehicle_Red, RainbowVehicle_Green, RainbowVehicle_Blue);
}

bool Cheat::CheatFeatures::EntityInformationGunBool = false;
void Cheat::CheatFeatures::EntityInformationGun()
{
	Entity AimedEntityHandle;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(Cheat::GameFunctions::PlayerID, &AimedEntityHandle))
	{
		Vector3 AimedEntityCoords = ENTITY::GET_ENTITY_COORDS(AimedEntityHandle, false);;
		std::string AimedEntityHealth = "Entity Health: " + std::to_string(ENTITY::GET_ENTITY_HEALTH(AimedEntityHandle));
		std::string AimedEntityHash = "Entity Hash: " + std::to_string(ENTITY::GET_ENTITY_MODEL(AimedEntityHandle));
		GUI::DrawTextInGame("~bold~Aimed Entity Information", { 255, 255, 255, 255, 0 }, { 0.500f, 0.380f }, { 0.35f, 0.35f }, false);
		GUI::DrawTextInGame(AimedEntityHash, { 255, 255, 255, 255, 0 }, { 0.500f, 0.400f }, { 0.35f, 0.35f }, false);
		GUI::DrawTextInGame(AimedEntityHealth, { 255, 255, 255, 255, 0 }, { 0.500f, 0.420f }, { 0.35f, 0.35f }, false);

		std::string EntityTypeMessageString;
		if (ENTITY::IS_ENTITY_A_PED(AimedEntityHandle)) { EntityTypeMessageString = "Entity Type: Ped"; }
		else if (ENTITY::IS_ENTITY_A_VEHICLE(AimedEntityHandle)) { EntityTypeMessageString = "Entity Type: Vehicle"; }
		else if (ENTITY::IS_ENTITY_AN_OBJECT(AimedEntityHandle)) { EntityTypeMessageString = "Entity Type: Object"; }
		else { EntityTypeMessageString = "Entity Type: Generic"; }
		GUI::DrawTextInGame(EntityTypeMessageString, { 255, 255, 255, 255, 0 }, { 0.500f, 0.440f }, { 0.35f, 0.35f }, false);
	}
}

bool Cheat::CheatFeatures::DeleteGunBool = false;
void Cheat::CheatFeatures::DeleteGun()
{
	Entity AimedAtEntity;
	DWORD equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(Cheat::GameFunctions::PlayerPedID, &equippedWeapon, 1);
	if (equippedWeapon == 0xBFD21232 || equippedWeapon == 0x88374054) // SNS Pistol & mk2 SNS Pistol
	{
		if (PED::IS_PED_SHOOTING(Cheat::GameFunctions::PlayerPedID))
		{
			if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(Cheat::GameFunctions::PlayerID, &AimedAtEntity))
			{
				Cheat::GameFunctions::RequestNetworkControlOfEntity(AimedAtEntity);
				ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&AimedAtEntity);
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(AimedAtEntity, true, true);
				ENTITY::DELETE_ENTITY(&AimedAtEntity);
			}
		}
	}
}

bool Cheat::CheatFeatures::NerfBulletsBool = false;
bool Cheat::CheatFeatures::NerfBulletsWasEnabled = false;
void Cheat::CheatFeatures::NerfBullets()
{
	NerfBulletsWasEnabled = true;
	PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(GameFunctions::PlayerID, 0.1f);
}

bool Cheat::CheatFeatures::SpectatePlayerBool = false;
bool Cheat::CheatFeatures::SpectatePlayerWasEnabled = false;
void Cheat::CheatFeatures::SpectatePlayer(bool toggle)
{
	if (toggle)
	{
		SpectatePlayerWasEnabled = true;
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(GameFunctions::PlayerPedID, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(SelectedPlayer));
		std::string String = "Spectating '" + (std::string)PLAYER::GET_PLAYER_NAME(SelectedPlayer) + "'";
		GameFunctions::SubtitleNotification(CheatFunctions::StringToChar(String), 1);
	}
	else
	{
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(false, GameFunctions::PlayerPedID);
	}
}

bool Cheat::CheatFeatures::NoRagdollAndSeatbeltBool = false;
void Cheat::CheatFeatures::NoRagdollAndSeatbelt(bool toggle)
{
	if (toggle)
	{
		PED::SET_PED_CAN_RAGDOLL(GameFunctions::PlayerPedID, false);
		PED::SET_PED_CONFIG_FLAG(GameFunctions::PlayerPedID, 32, false);
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(GameFunctions::PlayerPedID, 1);
	}
	else
	{
		PED::SET_PED_CAN_RAGDOLL(GameFunctions::PlayerPedID, true);
		PED::SET_PED_CONFIG_FLAG(GameFunctions::PlayerPedID, 32, true);
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(GameFunctions::PlayerPedID, 0);
	}
}

bool Cheat::CheatFeatures::FreezeSelectedPlayerBool = false;
void Cheat::CheatFeatures::FreezeSelectedPlayer()
{
	Ped PlayerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(SelectedPlayer);
	TASK::CLEAR_PED_TASKS_IMMEDIATELY(PlayerPed);
	TASK::CLEAR_PED_TASKS(PlayerPed);
	TASK::CLEAR_PED_SECONDARY_TASK(PlayerPed);
}

bool Cheat::CheatFeatures::FreezeAllPlayersBool = false;
void Cheat::CheatFeatures::FreezeAllPlayers()
{
	PlayersSessionForLoop
	{
		bool ExcludeSelf = GameFunctions::PlayerID == i && AllPlayersExclusionsSelf;
		bool ExcludeFriend = GameFunctions::IsPlayerFriend(i) && AllPlayersExclusionsFriends;
		bool ExcludeHost = GameFunctions::PlayerIsFreemodeScriptHost(i) && AllPlayersExclusionsHost;

		if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
		{
			Ped PlayerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			TASK::CLEAR_PED_TASKS_IMMEDIATELY(PlayerPed);
			TASK::CLEAR_PED_TASKS(PlayerPed);
			TASK::CLEAR_PED_SECONDARY_TASK(PlayerPed);
		}
	}
}

bool Cheat::CheatFeatures::TriggerBot_ShootNPCBool = false;
bool Cheat::CheatFeatures::TriggerBot_ShootPlayersBool = false;
bool Cheat::CheatFeatures::TriggerBotBool = false;
void Cheat::CheatFeatures::TriggerBot()
{
	int TargetBone;
	if (AimbotBoneVectorPosition == 0)
	{
		TargetBone = SKEL_Head;
	}
	else if (AimbotBoneVectorPosition == 1)
	{
		TargetBone = SKEL_Neck_1;
	}
	else if (AimbotBoneVectorPosition == 2)
	{
		TargetBone = SKEL_R_Hand;
	}
	else if (AimbotBoneVectorPosition == 3)
	{
		TargetBone = SKEL_L_Hand;
	}
		
	Entity AimedAtEntity;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(GameFunctions::PlayerID, &AimedAtEntity))
	{
		Vector3 BoneCoords = PED::GET_PED_BONE_COORDS(AimedAtEntity, TargetBone, 0.1f, 0.0f, 0.0f);
		if ((PED::IS_PED_A_PLAYER(AimedAtEntity) && TriggerBot_ShootPlayersBool) || (ENTITY::IS_ENTITY_A_PED(AimedAtEntity) && TriggerBot_ShootNPCBool) && !ENTITY::IS_ENTITY_DEAD(AimedAtEntity, false) && ENTITY::GET_ENTITY_ALPHA(AimedAtEntity) == 255)
		{
			PED::SET_PED_SHOOTS_AT_COORD(GameFunctions::PlayerPedID, BoneCoords.x, BoneCoords.y, BoneCoords.z, true);
		}
	}
}

bool Cheat::CheatFeatures::SuperBrakesBool = false;
void Cheat::CheatFeatures::SuperBrakes()
{
	Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(GameFunctions::PlayerPedID, false);
	if ((PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_VEH_BRAKE) && ENTITY::GET_ENTITY_SPEED_VECTOR(vehicle, true).y > 1.f) ||
		(PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_VEH_ACCELERATE) && ENTITY::GET_ENTITY_SPEED_VECTOR(vehicle, true).y < -1.f))
	{
		VEHICLE::SET_VEHICLE_FORWARD_SPEED(vehicle, 0.f);
	}
}

bool Cheat::CheatFeatures::TinyPlayerBool = false;
void Cheat::CheatFeatures::TinyPlayer(bool toggle)
{
	PED::SET_PED_CONFIG_FLAG(GameFunctions::PlayerPedID, 223, toggle);
}

bool Cheat::CheatFeatures::UnlimitedRocketBoostBool = false;
void Cheat::CheatFeatures::UnlimitedRocketBoost()
{
	if (PED::IS_PED_IN_ANY_VEHICLE(GameFunctions::PlayerPedID, false)) 
	{
		Ped veh = PED::GET_VEHICLE_PED_IS_USING(GameFunctions::PlayerPedID);
		VEHICLE::_SET_VEHICLE_ROCKET_BOOST_REFILL_TIME(veh, 0.f);
		VEHICLE::_SET_VEHICLE_ROCKET_BOOST_PERCENTAGE(veh, 100.f);

		if (VEHICLE::_IS_VEHICLE_ROCKET_BOOST_ACTIVE(veh)) 
		{
			VEHICLE::_SET_VEHICLE_ROCKET_BOOST_ACTIVE(veh, true);
			GameFunctions::SubtitleNotification("PRESS SPACEBAR TO STOP BOOST", 100);
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_DIVE)) // Spacebar
			{
				VEHICLE::_SET_VEHICLE_ROCKET_BOOST_ACTIVE(veh, false);
			}
		}
	}
}

std::string Cheat::CheatFeatures::ShootEntitiesCurrent = "Rhino";
bool Cheat::CheatFeatures::ShootEntitiesBool = false;
void Cheat::CheatFeatures::ShootEntities()
{
	if (PED::IS_PED_SHOOTING(GameFunctions::PlayerPedID))
	{
		Hash EntityHash = MISC::GET_HASH_KEY(CheatFunctions::StringToChar(ShootEntitiesCurrent));

		if (STREAMING::IS_MODEL_VALID(EntityHash))
		{
			while (!STREAMING::HAS_MODEL_LOADED(EntityHash)) { STREAMING::REQUEST_MODEL(EntityHash); GameHooking::PauseMainFiber(0, false); }
			Vector3 Dimension1, Dimension2;
			MISC::GET_MODEL_DIMENSIONS(EntityHash, &Dimension1, &Dimension2);

			float Offset = Dimension2.y * 1.5; //1.6

			Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(GameFunctions::PlayerPedID);
			Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(GameFunctions::PlayerPedID, false);
			float Rotation = ENTITY::GET_ENTITY_ROTATION(GameFunctions::PlayerPedID, 0).z;
			Vector3 gameplayCam = CAM::GET_FINAL_RENDERED_CAM_COORD();
			Vector3 gameplayCamDirection = GameFunctions::RotationToDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0));
			Vector3 startCoords = GameFunctions::AddVector(gameplayCam, (GameFunctions::MultiplyVector(gameplayCamDirection, 10)));
			Vector3 endCoords = GameFunctions::AddVector(gameplayCam, (GameFunctions::MultiplyVector(gameplayCamDirection, 500.0f)));


			Entity EntityHandle = NULL;
			if (STREAMING::IS_MODEL_A_VEHICLE(EntityHash))
			{
				EntityHandle = VEHICLE::CREATE_VEHICLE(EntityHash, pCoords.x + (dir.x * Offset), pCoords.y + (dir.y * Offset), startCoords.z, Rotation, true, true, false);
			}
			else if (ENTITY::IS_ENTITY_A_PED(EntityHash))
			{
				EntityHandle = PED::CREATE_PED(0, EntityHash, pCoords.x + (dir.x * Offset), pCoords.y + (dir.y * Offset), startCoords.z, Rotation, true, true);
			}
			else
			{
				EntityHandle = OBJECT::CREATE_OBJECT(EntityHandle, pCoords.x + (dir.x * Offset), pCoords.y + (dir.y * Offset), startCoords.z, true, true, false);
			}

			ENTITY::APPLY_FORCE_TO_ENTITY(EntityHandle, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, true, true, true, false, true);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&EntityHandle);
		}
	}
}


bool Cheat::CheatFeatures::PlayerESPBool = false;
void Cheat::CheatFeatures::PlayerESP()
{
	if (NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1)
	{
		PlayersSessionForLoop
		{
			if (GameFunctions::PlayerID != i) 
			{
				Vector3 entitylocation = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
				Vector3 top1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
				Vector3 top2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
				Vector3 top3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
				Vector3 top4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
				Vector3 bottom1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
				Vector3 bottom2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
				Vector3 bottom3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
				Vector3 bottom4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };

				GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top2world.x, top2world.y, top2world.z, 0, 0, 255, 255);
				GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, top4world.x, top4world.y, top4world.z, 0, 0, 255, 255);
				GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, top3world.x, top3world.y, top3world.z, 0, 0, 255, 255);
				GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top3world.x, top3world.y, top3world.z, 0, 0, 255, 255);

				GRAPHICS::DRAW_LINE(bottom1world.x, bottom1world.y, bottom1world.z, bottom2world.x, bottom2world.y, bottom2world.z, 0, 0, 255, 255);
				GRAPHICS::DRAW_LINE(bottom2world.x, bottom2world.y, bottom2world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 0, 255, 255);
				GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 0, 255, 255);
				GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom1world.x, bottom1world.y, bottom1world.z, 0, 0, 255, 255);

				GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, bottom1world.x, bottom1world.y, bottom1world.z, 0, 0, 255, 255);
				GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, bottom2world.x, bottom2world.y, bottom2world.z, 0, 0, 255, 255);
				GRAPHICS::DRAW_LINE(top3world.x, top3world.y, top3world.z, bottom3world.x, bottom3world.y, bottom3world.z, 0, 0, 255, 255);
				GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 0, 255, 255);

				Vector3 locationOne = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
				Vector3 locationTwo = ENTITY::GET_ENTITY_COORDS(GameFunctions::PlayerPedID, false);
				GRAPHICS::DRAW_LINE(locationOne.x, locationOne.y, locationOne.z, locationTwo.x, locationTwo.y, locationTwo.z, 0, 0, 255, 255);
			}
		}
	}
}

bool Cheat::CheatFeatures::OffRadarBool = false;
void Cheat::CheatFeatures::OffRadar()
{
	globalHandle(2689235).At(1 + (Cheat::GameFunctions::PlayerID * 453)).At(208).As<bool>() = true;
	globalHandle(2815059).At(4627).As<int>() = NETWORK::GET_NETWORK_TIME();
}

bool Cheat::CheatFeatures::CopsTurnBlindEyeBool = false;
void Cheat::CheatFeatures::CopsTurnBlindEye()
{
	globalHandle(2815059).At(4624).As<int>() = 5;
	globalHandle(2815059).At(4627).As<int>() = NETWORK::GET_NETWORK_TIME();
}

bool Cheat::CheatFeatures::ExplodeLoopSelectedPlayerBool = false;
void Cheat::CheatFeatures::ExplodeLoopSelectedPlayer()
{
	Vector3 SelectedPlayerPedCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer), false);
	FIRE::ADD_EXPLOSION(SelectedPlayerPedCoords.x, SelectedPlayerPedCoords.y, SelectedPlayerPedCoords.z, 0, 1000.f, true, false, 0.f, false);
}

bool Cheat::CheatFeatures::DriveOnWaterBool = false;
void Cheat::CheatFeatures::DriveOnWater()
{
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(GameFunctions::PlayerPedID, false);
	DWORD model = ENTITY::GET_ENTITY_MODEL(veh);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(GameFunctions::PlayerPedID, false);
	float height = 0.f;
	WATER::SET_DEEP_OCEAN_SCALER(height);
	if (!VEHICLE::IS_THIS_MODEL_A_PLANE(ENTITY::GET_ENTITY_MODEL(veh)) && WATER::GET_WATER_HEIGHT_NO_WAVES(pos.x, pos.y, pos.z, &height)) 
	{
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, MISC::GET_HASH_KEY("prop_container_ld2"), false, false, true);
		if (ENTITY::DOES_ENTITY_EXIST(container) && height > -50.0f) 
		{
			Vector3 pRot = ENTITY::GET_ENTITY_ROTATION(GameFunctions::PlayerPedID, 0);
			if (PED::IS_PED_IN_ANY_VEHICLE(GameFunctions::PlayerPedID, 1)) pRot = ENTITY::GET_ENTITY_ROTATION(veh, 0);
			GameFunctions::RequestNetworkControlOfEntity(container);
			ENTITY::SET_ENTITY_COORDS(container, pos.x, pos.y, height - 1.5f, false, false, false, 1);
			ENTITY::SET_ENTITY_ROTATION(container, 0, 0, pRot.z, 0, 1);
			Vector3 containerCoords = ENTITY::GET_ENTITY_COORDS(container, false);
			if (pos.z < containerCoords.z) 
			{
				if (!PED::IS_PED_IN_ANY_VEHICLE(GameFunctions::PlayerPedID, false))
				{
					ENTITY::SET_ENTITY_COORDS(GameFunctions::PlayerPedID, pos.x, pos.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
				}
				else 
				{
					GameFunctions::RequestNetworkControlOfEntity(veh);
					Vector3 vehc = ENTITY::GET_ENTITY_COORDS(veh, false);
					ENTITY::SET_ENTITY_COORDS(veh, vehc.x, vehc.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
				}
			}
		}
		else 
		{
			Hash model = MISC::GET_HASH_KEY("prop_container_ld2");
			STREAMING::REQUEST_MODEL(model);
			while (!STREAMING::HAS_MODEL_LOADED(model)) GameHooking::PauseMainFiber(0);
			container = OBJECT::CREATE_OBJECT(model, pos.x, pos.y, pos.z, true, true, false);
			ENTITY::FREEZE_ENTITY_POSITION(container, 1);
			ENTITY::SET_ENTITY_ALPHA(container, 0, 1);
			ENTITY::SET_ENTITY_VISIBLE(container, false, false);
		}
	}
	else 
	{
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, MISC::GET_HASH_KEY("prop_container_ld2"), false, false, true);
		if (ENTITY::DOES_ENTITY_EXIST(container)) 
		{
			GameFunctions::RequestNetworkControlOfEntity(container);
			ENTITY::SET_ENTITY_COORDS(container, 0, 0, -1000.0f, 0, 0, 0, 1);
			GameHooking::PauseMainFiber(10);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&container);
			ENTITY::DELETE_ENTITY(&container);
			WATER::RESET_DEEP_OCEAN_SCALER();
		}
	}
}

bool Cheat::CheatFeatures::SuperManBool = false;
void Cheat::CheatFeatures::SuperMan()
{
	if(!Cheat::CheatFeatures::NoRagdollAndSeatbeltBool) { CheatFeatures::NoRagdollAndSeatbeltBool = true; GameFunctions::MinimapNotification("No Ragdoll & Seatbelt feature enabled for this feature"); }
	WEAPON::GIVE_WEAPON_TO_PED(GameFunctions::PlayerPedID, MISC::GET_HASH_KEY("GADGET_PARACHUTE"), 1, false, true);
	ENTITY::SET_ENTITY_INVINCIBLE(GameFunctions::PlayerPedID, true);
	PED::SET_PED_TO_RAGDOLL_WITH_FALL(GameFunctions::PlayerPedID, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);

	if (ENTITY::IS_ENTITY_IN_AIR(GameFunctions::PlayerPedID) && !PED::IS_PED_RAGDOLL(GameFunctions::PlayerPedID))
	{
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_MOVE_UP_ONLY)) { GameFunctions::ApplyForceToEntity(GameFunctions::PlayerPedID, 0, 6, 0); } // W
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_MOVE_DOWN_ONLY)) { GameFunctions::ApplyForceToEntity(GameFunctions::PlayerPedID, 0, -6, 0); } // S
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_SPRINT)) { GameFunctions::ApplyForceToEntity(GameFunctions::PlayerPedID, 0, 0, 6); } // Left shift
	}
}

bool Cheat::CheatFeatures::ShakeCamSelectedPlayerBool = false;
void Cheat::CheatFeatures::ShakeCamSelectedPlayer()
{
	Vector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(CheatFeatures::SelectedPlayer), false);
	FIRE::ADD_EXPLOSION(targetCords.x, targetCords.y, targetCords.z, 0, 0.f, false, true, 1000.f, true);
}

bool Cheat::CheatFeatures::RainbowGunBool = false;
void Cheat::CheatFeatures::RainbowGun()
{
	for (auto const& i : GameArrays::WeaponsHashList)
	{
		Hash CurrentHash = i.WeaponHash;
		if (WEAPON::HAS_PED_GOT_WEAPON(GameFunctions::PlayerPedID, CurrentHash, 0))
		{
			WEAPON::SET_PED_WEAPON_TINT_INDEX(GameFunctions::PlayerPedID, CurrentHash, rand() % 8);
		}
	}

}

bool Cheat::CheatFeatures::DisableMobilePhoneBool = false;
void Cheat::CheatFeatures::DisableMobilePhone()
{
	globalHandle(GLOBAL_DISABLE_MOBILE_PHONE).As<int>() = 1;
}

bool Cheat::CheatFeatures::NoIdleKickBool = false;
void Cheat::CheatFeatures::NoIdleKick()
{
	globalHandle(GLOBAL_NO_IDLE_KICK1[0]).At(GLOBAL_NO_IDLE_KICK1[1]).As<int>() = -1;
	globalHandle(GLOBAL_NO_IDLE_KICK2[0]).At(GLOBAL_NO_IDLE_KICK2[1]).As<int>() = -1;
}

DWORD VehicleWeapons_LastTick = 0;
bool Cheat::CheatFeatures::VehicleWeapons_TankRounds = true;
bool Cheat::CheatFeatures::VehicleWeapons_VehicleRockets = false;
bool Cheat::CheatFeatures::VehicleWeapons_Fireworks = false;
bool Cheat::CheatFeatures::VehicleWeapons_DrawLaser = false;
bool Cheat::CheatFeatures::VehicleWeaponsBool = false;
void Cheat::CheatFeatures::VehicleWeapons()
{
	if (VehicleWeapons_DrawLaser) 
	{ 
		Vehicle VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(GameFunctions::PlayerPedID, 0);
		Vector3 getcoords1 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehicleHandle, 0.6f, 0.6707f, 0.3711f);
		Vector3 getcoords2 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehicleHandle, -0.6f, 0.6707f, 0.3711f);
		Vector3 getcoords3 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehicleHandle, 0.6f, 25.0707f, 0.3711f);
		Vector3 getcoords4 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehicleHandle, -0.6f, 25.0707f, 0.3711f);
		float StartCoords1[] = { getcoords1.x, getcoords1.y, getcoords1.z };
		float StartCoords2[] = { getcoords2.x, getcoords2.y, getcoords2.z };
		float EndCoords1[] = { getcoords3.x, getcoords3.y, getcoords3.z };
		float EndCoords2[] = { getcoords4.x, getcoords4.y, getcoords4.z };
		GRAPHICS::DRAW_LINE(getcoords1.x, getcoords1.y, getcoords1.z, getcoords3.x, getcoords3.y, getcoords3.z, 255, 0, 0, 255);
		GRAPHICS::DRAW_LINE(getcoords2.x, getcoords2.y, getcoords2.z, getcoords4.x, getcoords4.y, getcoords4.z, 255, 0, 0, 255);
	}

	if (PLAYER::IS_PLAYER_PRESSING_HORN(Cheat::GameFunctions::PlayerID) && VehicleWeapons_LastTick + 150 < GetTickCount64() && PLAYER::IS_PLAYER_CONTROL_ON(GameFunctions::PlayerID) && PED::IS_PED_IN_ANY_VEHICLE(GameFunctions::PlayerPedID, false))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(Cheat::GameFunctions::PlayerPedID);

		Vector3 v0, v1;
		MISC::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket;
		if (VehicleWeapons_TankRounds) { VehicleWeapons_Fireworks = false; VehicleWeapons_VehicleRockets = false; weaponAssetRocket = MISC::GET_HASH_KEY("VEHICLE_WEAPON_TANK"); }
		else if (VehicleWeapons_VehicleRockets) { VehicleWeapons_TankRounds = false; VehicleWeapons_Fireworks = false; weaponAssetRocket = MISC::GET_HASH_KEY("WEAPON_VEHICLE_ROCKET"); }
		else if (VehicleWeapons_Fireworks) { VehicleWeapons_VehicleRockets = false; VehicleWeapons_TankRounds = false;  weaponAssetRocket = MISC::GET_HASH_KEY("WEAPON_FIREWORK"); }

		if (VehicleWeapons_TankRounds || VehicleWeapons_VehicleRockets || VehicleWeapons_Fireworks)
		{
			if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket)) { WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0); while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket)) { GameHooking::PauseMainFiber(0); } }

			Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1f);
			Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1f);
			Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
			Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);
			MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z, coords0to.x, coords0to.y, coords0to.z, 250, 1, weaponAssetRocket, GameFunctions::PlayerPedID, 1, 0, -1.0);
			MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z, coords1to.x, coords1to.y, coords1to.z, 250, 1, weaponAssetRocket, GameFunctions::PlayerPedID, 1, 0, -1.0);
		}
		VehicleWeapons_LastTick = GetTickCount64();
	}
}

bool Cheat::CheatFeatures::AutoGiveAllWeaponsBool = false;
void Cheat::CheatFeatures::AutoGiveAllWeapons()
{
	if (PLAYER::IS_PLAYER_PLAYING(GameFunctions::PlayerID)) 
	{ 
		for (auto const& i : GameArrays::WeaponsHashList)
		{
			Hash CurrentHash = i.WeaponHash;
			if (!WEAPON::HAS_PED_GOT_WEAPON(GameFunctions::PlayerPedID, CurrentHash, false))
			{
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(GameFunctions::PlayerPedID, CurrentHash, 9999, false);
			}
		}
	}
}

bool Cheat::CheatFeatures::AutoGiveAllWeaponUpgradesBool = false;
void Cheat::CheatFeatures::AutoGiveAllWeaponUpgrades()
{
	if (PLAYER::IS_PLAYER_PLAYING(GameFunctions::PlayerID))
	{
		GameFunctions::MaxUpgradeAllWeapons();
	}
}

bool Cheat::CheatFeatures::CrossHairBool = false;
bool Cheat::CheatFeatures::CrossHairADSOnlyBool = false;
void Cheat::CheatFeatures::CrossHair()
{
	if (!CrossHairADSOnlyBool || CrossHairADSOnlyBool && PLAYER::IS_PLAYER_FREE_AIMING(GameFunctions::PlayerID))
	{
		GUI::DrawSpriteInGame("Textures", "Crosshair", 0.50f, 0.50f, 0.060f, 0.100f, 0, GUI::PrimaryColor.r, GUI::PrimaryColor.g, GUI::PrimaryColor.b, 255);
	}
}

bool Cheat::CheatFeatures::RGBDiscoBool = false;
bool Cheat::CheatFeatures::RGBDiscoFirstCall = true;
void Cheat::CheatFeatures::RGBDisco()
{
	if (RGBDiscoFirstCall)
	{
		GUI::PrimaryColor.r = 255;
		GUI::PrimaryColor.g = 0;
		GUI::PrimaryColor.b = 0;
		GUI::TextColorAndFont.r = 0;
		GUI::TextColorAndFont.g = 0;
		GUI::TextColorAndFont.b = 255;
		RGBDiscoFirstCall = false;
	}
	GameFunctions::FadeRGB(GUI::PrimaryColor.r, GUI::PrimaryColor.g, GUI::PrimaryColor.b);
	GameFunctions::FadeRGB(GUI::TextColorAndFont.r, GUI::TextColorAndFont.g, GUI::TextColorAndFont.b);
}

bool Cheat::CheatFeatures::WeaponInvisibilityBool = false;
bool Cheat::CheatFeatures::WeaponInvisibilityWasEnabled = false;
void Cheat::CheatFeatures::WeaponInvisibility(bool toggle)
{
	WeaponInvisibilityWasEnabled = true;
	ENTITY::SET_ENTITY_VISIBLE(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(GameFunctions::PlayerPedID, 0), !toggle, false);
}

bool Cheat::CheatFeatures::SessionLockFriendsOnlyBool = false;
void Cheat::CheatFeatures::SessionLockFriendsOnly()
{
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		PlayersSessionForLoop
		{
			if (GameFunctions::PlayerID != i && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i) && !GameFunctions::IsPlayerFriend(i))
			{
				GameFunctions::TriggerScriptEvent(eScriptEventTypes::KICK_TO_SINGLE_PLAYER, i);
			}
		}
	}
}

bool Cheat::CheatFeatures::ShowTVBool = false;
bool Cheat::CheatFeatures::ShowTVWasEnabled = false;
void Cheat::CheatFeatures::ShowTV(bool toggle)
{
	ShowTVWasEnabled = true;
	GRAPHICS::SET_TV_AUDIO_FRONTEND(toggle);
	GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(4);
	GRAPHICS::SET_SCRIPT_GFX_DRAW_BEHIND_PAUSEMENU(toggle);
	GRAPHICS::DRAW_TV_CHANNEL(0.800f, 0.200f, 0.2f, 0.2f, 0.0f, 255, 255, 255, 250);
}