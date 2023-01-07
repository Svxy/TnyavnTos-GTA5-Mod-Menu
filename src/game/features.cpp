#include "../cheat/fibermain.hpp"
#include "../cheat/cheat.hpp"
#include "../game/game.hpp"
#include "../gui/gui_controls.hpp"
#include "../cheat/update.hpp"
#include "../hooking/globalhandle.hpp"
#include "../hooking/offsets.hpp"
#include "../hooking/natives.hpp"
#include "notification.hpp"
#include "data/game_data.hpp"
#include "../cheat/config.hpp"

int Cheat::Features::SelectedPlayer;
int Cheat::Features::SpeedometerVectorPosition = 0;
int Cheat::Features::AimbotBoneVectorPosition = 0;
int Cheat::Features::ImpactAmmoVectorPosition = 0;
int Cheat::Features::CustomAmmoVectorPosition = 0;
int Cheat::Features::ParticleAmmoVectorPosition = 0;
int Cheat::Features::FontTypeVectorPosition = 0;
int Cheat::Features::AnimationsVectorPosition = 0;
int Cheat::Features::ScenariosVectorPosition = 0;
int Cheat::Features::PedMovementVectorPosition = 0;
int Cheat::Features::OpenVehicleDoorPosition = 0;
int Cheat::Features::CloseVehicleDoorPosition = 0;
int Cheat::Features::FastSuperRunPosition = 0;
int Cheat::Features::PlayerOpacityInt = 250;
bool Cheat::Features::BlockAllScriptEvents = false;
bool Cheat::Features::ProtectionScriptEvents_Kicks = false;
bool Cheat::Features::ProtectionScriptEvents_CEOMoney = false;
bool Cheat::Features::ProtectionScriptEvents_PropertyTeleport = false;
bool Cheat::Features::ProtectionScriptEvents_CayoPericoTeleport = false;
bool Cheat::Features::ProtectionScriptEvents_ForceIntoMission = false;
bool Cheat::Features::ProtectionScriptEvents_Bounty = false;
bool Cheat::Features::ProtectionScriptEvents_ClearWantedlevel = false;
bool Cheat::Features::ProtectionScriptEvents_GameBanner = false;
bool Cheat::Features::ProtectionScriptEvents_NetworkBail = false;
bool Cheat::Features::ProtectionScriptEvents_Crash = false;
bool Cheat::Features::ProtectionScriptEvents_PersonalVehicleDestroyed = false;
bool Cheat::Features::ProtectionScriptEvents_RemoteOffradar = false;
bool Cheat::Features::ProtectionScriptEvents_SendToCutscene = false;
bool Cheat::Features::ProtectionScriptEvents_SendToLocation = false;
bool Cheat::Features::ProtectionScriptEvents_SoundSpam = false;
bool Cheat::Features::ProtectionScriptEvents_Spectate = false;
bool Cheat::Features::HideOwnIPAddress = true;
bool Cheat::Features::DisableTransactionErrorWarning = true;
bool Cheat::Features::DisableCutscenes = false;
bool Cheat::Features::HideVehiclePreview = false;
bool Cheat::Features::ShowJoiningPlayersNotification = false;
bool Cheat::Features::VehicleSpawnerSpawnInsideVehicle = false;
bool Cheat::Features::VehicleSpawnerDeleteOldVehicle = false;
bool Cheat::Features::VehicleSpawnerSpawnWithGodmode = false;
bool Cheat::Features::VehicleSpawnerSpawnMaxUpgraded = false;
bool Cheat::Features::VehicleSpawnerSpawnAirVehicleAir = false;
int Cheat::Features::VehicleSpawnerLicensePlateVectorPosition = 0;
std::string Cheat::Features::VehicleSpawnerCustomLicensePlateTextString = "GTAV";
bool Cheat::Features::HidePlayerInformationBox = false;
bool Cheat::Features::HideSelectableInformationBox = false;
bool Cheat::Features::ControllableAnimations = false;
bool Cheat::Features::AllPlayersExclusionsSelf = true;
bool Cheat::Features::AllPlayersExclusionsFriends = false;
bool Cheat::Features::AllPlayersExclusionsHost = false;
bool Cheat::Features::TeleportTransition = false;
bool Cheat::Features::NoTextureFileOverwrite = false;
bool Cheat::Features::SafeMode = true;

void Cheat::Features::Loop()
{
	// POST initialization notification
	if (core::init_complete && config::Loaded && !GUI::MenuGUIHasBeenOpened)
	{
		Game::InGameHelpTextMessage = "Press " + GUI::gui_controls::VirtualKeyCodeToString(GUI::gui_controls::OpenMenuGUIKey) + " to open Menu GUI";
		std::string WelcomeText = "Welcome " + (std::string)SOCIALCLUB::_SC_GET_NICKNAME() + ", have fun!";
		Game::notification::MinimapAdvanced(helper::StringToChar(WelcomeText), (char*)"Textures", (char*)"AdvancedNotificationImage", false, 4, (char*)"TnyavnTos GTA 5 Mod Menu", (char*)"", 0.1f, (char*)"");
		UI::DISPLAY_HELP_TEXT_THIS_FRAME("LETTERS_HELP2", false);
	}
	Game::InGameHelpTextMessage.clear();

	// New cheat update notification
	if (update_check::IsAvailable && core::init_complete && config::Loaded)
	{
		GUI::DrawTextInGame("~bold~A newer cheat version is available on GitHub", { 255, 255, 255, 255, FontChaletLondon }, { 0.003f, 0.001f }, { 0.25f, 0.25f }, false);
	}

	// New session member notification feature
	Game::CheckNewSessionMembersLoop();

	// Speedometer
	if (SpeedometerVectorPosition > 0 && PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
	{
		std::ostringstream Speed;
		if (MISC::SHOULD_USE_METRIC_MEASUREMENTS())
		{
			Speed << Game::math::MSToKMH(ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0))) << " KM";
		}
		else
		{
			Speed << Game::math::MSToMPH(ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0))) << " MP";
		}
		if (SpeedometerVectorPosition == 1 || SpeedometerVectorPosition == 3) { GUI::DrawTextInGame(Speed.str(), { 0, 0, 255, 255 }, { 0.85f, 0.5000f }, { 0.70f, 0.70f }, false); }
		if (SpeedometerVectorPosition == 2 || SpeedometerVectorPosition == 3) { VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), helper::StringToChar(Speed.str())); }
	}

	// Impact ammo
	if (ImpactAmmoVectorPosition > 0)
	{
		if (ImpactAmmoVectorPosition == 1)
		{
			Memory::set_value<int>({ OFFSET_LOCAL_PED, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_FRAMEFLAGS }, FrameFlagFireAmmo);
		}
		else if (ImpactAmmoVectorPosition == 2)
		{
			if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
			{
				Vector3 coords;
				if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &coords))
				{
					// VEHICLE_WEAPON_SPACE_ROCKET
					MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 30, coords.x, coords.y, coords.z, 250, 0, 0xF8A3939F, 0, 1, 1, 500);
				}
			}
		}
		else if (ImpactAmmoVectorPosition == 3)
		{
			if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
			{
				Vector3 iCoord;
				if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &iCoord))
				{
					ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), iCoord.x, iCoord.y, iCoord.z + 1, false, false, true, true);
				}
			}
		}
		else if (ImpactAmmoVectorPosition == 4)
		{
			Memory::set_value<int>({ OFFSET_LOCAL_PED, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_FRAMEFLAGS }, FrameFlagExplosiveAmmo);
		}
		else if (ImpactAmmoVectorPosition == 5)
		{
			Vector3 iCoord;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &iCoord))
			{
				
				Game::notification::Minimap(helper::StringToChar(std::to_string(iCoord.x) + ", " + std::to_string(iCoord.y) + ", " + std::to_string(iCoord.z)));
			}
		}
	}

	// Sprint Speed
	if (FastSuperRunPosition > 0 && (TASK::IS_PED_SPRINTING(PLAYER::PLAYER_PED_ID()) || TASK::IS_PED_RUNNING(PLAYER::PLAYER_PED_ID())))
	{
		if (FastSuperRunPosition == 1)
		{
			PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(PLAYER::PLAYER_ID(), 1.49f);
		}
		else if (FastSuperRunPosition == 2)
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), 1, 0.0f, 1.3f, 0.f, 0.0f, 0.0f, 0.0f, 0, true, true, true, false, true);
		}
	}

	// Custom ammo
	if (CustomAmmoVectorPosition > 0)
	{
		Vector3 Direction				= Game::vector::get_cam_direction();
		Vector3 CameraPosition			= CAM::GET_GAMEPLAY_CAM_COORD();
		Vector3 PlayerPosition			= ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		
		float ProjectileSpawnDistance	= Game::vector::get_distance_between_two(CameraPosition, PlayerPosition);
		ProjectileSpawnDistance			+= 0.25;
		
		Vector3 MultiplySpawnDistance	= Game::vector::multiply(Direction, ProjectileSpawnDistance);
		Vector3 ProjectileSpawnPosition	= Game::vector::add_two(CameraPosition, MultiplySpawnDistance);
		
		float EndDistance				= Game::vector::get_distance_between_two(CameraPosition,PlayerPosition);
		EndDistance += 1000;

		Vector3 EndPositionVectorB		= Game::vector::multiply(Direction, EndDistance);
		Vector3 EndPosition				= Game::vector::add_two(CameraPosition, EndPositionVectorB);

		Hash WeaponAsset = NULL;
		if (CustomAmmoVectorPosition == 1)
		{
			WeaponAsset = 0x4170E491; // VEHICLE_WEAPON_NOSE_TURRET_VALKYRIE
		}
		else if (CustomAmmoVectorPosition == 2)
		{
			WeaponAsset = 0x73F7C04B; // VEHICLE_WEAPON_TANK
		}
		else if (CustomAmmoVectorPosition == 3)
		{
			WeaponAsset = 0xBEFDC581; // WEAPON_VEHICLE_ROCKET
		}
		else if (CustomAmmoVectorPosition == 4)
		{
			WeaponAsset = 0x7F7497E5; // WEAPON_FIREWORK
		}

		if (PED::IS_PED_ON_FOOT(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()) && WeaponAsset != NULL)
		{
			if (!WEAPON::HAS_WEAPON_ASSET_LOADED(WeaponAsset))
			{
				WEAPON::REQUEST_WEAPON_ASSET(WeaponAsset, 31, 0);
				while (!WEAPON::HAS_WEAPON_ASSET_LOADED(WeaponAsset)) { GameHooking::PauseMainFiber(0); }
			}
			MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(ProjectileSpawnPosition.x, ProjectileSpawnPosition.y, ProjectileSpawnPosition.z, EndPosition.x, EndPosition.y, EndPosition.z, 250, true, WeaponAsset, PLAYER::PLAYER_PED_ID(), true, false, -1.0);
		}
	}

	// Particle ammo
	if (ParticleAmmoVectorPosition > 0)
	{
		const char* PTFX;
		const char* EffectName;

		if (ParticleAmmoVectorPosition == 1)
		{
			PTFX = "scr_rcbarry2";
			EffectName = "muz_clown";
		}

		Vector3 BulletCoord;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &BulletCoord))
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
		globalHandle(GLOBAL_TRANS_ERROR_SHOWN_1).As<bool>() = false;
		globalHandle(GLOBAL_TRANS_ERROR_SHOWN_2).As<bool>() = false;
		globalHandle(GLOBAL_TRANS_ERROR_SHOWN_3).As<bool>() = false;
	}

	// Disable Cutscenes
	if (DisableCutscenes)
	{
		if (CUTSCENE::IS_CUTSCENE_ACTIVE())
		{
			CUTSCENE::STOP_CUTSCENE_IMMEDIATELY();
		}
	}

	if (GodmodeBool) { Godmode(true); } else if (GodmodeWasEnabled) { Godmode(false);  GodmodeWasEnabled = false; }
	NeverWantedBool ? NeverWanted() : void();
	NoWeaponReloadBool ? NoWeaponReload() : void();
	if (InfiniteAmmoBool) { InfiniteAmmo(true); } else if (InfiniteAmmoWasEnabled) { InfiniteAmmo(false);  InfiniteAmmoWasEnabled = false; }
	if (SlowMotionBool) { SlowMotion(true); } else if (SlowMotionWasEnabled) { SlowMotion(false);  SlowMotionWasEnabled = false; }
	if (WorldBlackoutBool) { WorldBlackout(true); } else if (WorldBlackoutWasEnabled) { WorldBlackout(false); WorldBlackoutWasEnabled = false; }
	GravityGunBool ? GravityGun() : void();
	DisableHUDBool ? DisableHUD() : void();
	if (NoGravityBool) { NoGravity(true); } else if (NoGravityWasEnabled) { NoGravity(false);  NoGravityWasEnabled = false; }
	if (WorldSnowLocalBool) { WorldSnowLocal(true); } else if (WorldSnowLocalWasEnabled) { WorldSnowLocal(false);  WorldSnowLocalWasEnabled = false; }
	AutoTeleportToWaypointBool ? AutoTeleportToWaypoint() : void();
	if (OneHitKillBool) { OneHitKill(); } else if (OneHitKillWasEnabled) { PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), 1.f); PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), 1.f, false); OneHitKillWasEnabled = false; }
	PauseTimeBool ? PauseTime(true) : PauseTime(false);
	ExplosiveMeleeBool ? ExplosiveMelee() : void();
	OrbitalCannonCooldownBypassBool ? OrbitalCannonCooldownBypass() : void();
	ProtectionVoteKickBool ? ProtectionVoteKick(true) : ProtectionVoteKick(false);
	ProtectionFreezeBool ? ProtectionFreeze(true) : ProtectionFreeze(false);
	ProtectionWorldEventsBool ? ProtectionWorldEvents(true) : ProtectionWorldEvents(false);
	ProtectionVehicleBool ? ProtectionVehicle(true) : ProtectionVehicle(false);
	ProtectionAlterWantedLevelBool ? ProtectionAlterWantedLevel(true) : ProtectionAlterWantedLevel(false);
	ProtectionGiveRemoveWeaponsBool ? ProtectionGiveRemoveWeapons(true) : ProtectionGiveRemoveWeapons(false);
	SuperJumpBool ? SuperJump() : void();
	ShowFPSBool ? ShowFPS() : void();
	JumpAroundModeBool ? JumpAroundMode() : void();
	VehicleHornBoostBool ? VehicleHornBoost() : void();
	VehicleGodmodeBool ? VehicleGodmode(true) : VehicleGodmode(false);
	VehicleInvisibleBool ? VehicleInvisible(true) : VehicleInvisible(false);
	PlayerInvisibleLocalBool ? PlayerInvisibleLocal(true) : PlayerInvisibleLocal(false);
	PlayerInvisibleNetworkBool ? PlayerInvisibleNetwork(true) : PlayerInvisibleNetwork(false);
	MobileRadioBool ? MobileRadio(true) : MobileRadio(false);
	WeaponRapidFireBool ? WeaponRapidFire() : void();
	if (NoClipBool) { NoClip(); } else if (NoClipWasEnabled) { ENTITY::SET_ENTITY_COLLISION(PLAYER::PLAYER_PED_ID(), true, true); NoClipWasEnabled = false; }
	RainbowVehicleBool ? RainbowVehicle() : void();
	DeleteGunBool ? DeleteGun() : void();
	if (NerfBulletsBool) { NerfBullets(); } else if (NerfBulletsWasEnabled) { PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), 1.f); NerfBulletsWasEnabled = false; }
	if (SpectatePlayerBool) { SpectatePlayer(true); } else if (SpectatePlayerWasEnabled) { SpectatePlayer(false);  SpectatePlayerWasEnabled = false; }
	NoRagdollAndSeatbeltBool ? NoRagdollAndSeatbelt(true) : NoRagdollAndSeatbelt(false);
	FreezeSelectedPlayerBool ? FreezeSelectedPlayer() : void();
	FreezeAllPlayersBool ? FreezeAllPlayers() : void();
	TriggerBotBool ? TriggerBot() : void();
	SuperBrakesBool ? SuperBrakes() : void();
	TinyPlayerBool ? TinyPlayer(true) : TinyPlayer(false);
	UnlimitedRocketBoostBool ? UnlimitedRocketBoost() : void();
	ShootEntitiesBool ? ShootEntities() : void();
	PlayerESPBool ? PlayerESP() : void();
	OffRadarBool ? OffRadar() : void();
	ExplodeLoopSelectedPlayerBool ? ExplodeLoopSelectedPlayer() : void();
	DriveOnWaterBool ? DriveOnWater() : void();
	SuperManBool ? SuperMan() : void();
	ShakeCamSelectedPlayerBool ? ShakeCamSelectedPlayer() : void();
	RainbowGunBool ? RainbowGun() : void();
	DisableMobilePhoneBool ? DisableMobilePhone() : void();
	NoIdleKickBool ? NoIdleKick() : void();
	CopsTurnBlindEyeBool ? CopsTurnBlindEye() : void();
	VehicleWeaponsBool ? VehicleWeapons() : void();
	AutoGiveAllWeaponsBool ? AutoGiveAllWeapons() : void();
	AutoGiveAllWeaponUpgradesBool ? AutoGiveAllWeaponUpgrades() : void();
	FreeCamBool ? FreeCam(true) : FreeCam(false);
	EntityInformationGunBool ? EntityInformationGun() : void();
	CrossHairBool ? CrossHair() : void();
	if (RGBDiscoBool) { RGBDisco(); } else if (!RGBDiscoFirstCall) { RGBDiscoFirstCall = true;  }
	if (FreezeStationBool) { FreezeStation(); } else if (FreezeStationWasEnabled) { AUDIO::UNFREEZE_RADIO_STATION(AUDIO::GET_PLAYER_RADIO_STATION_NAME()); FreezeStationWasEnabled = false; }
	if (HideMinimapBool) { HideMinimap(); } else if (HideMinimapWasEnabled) { UI::DISPLAY_RADAR(true);   HideMinimapWasEnabled = false; }
	if (WeaponInvisibilityBool) { WeaponInvisibility(true); } else if (WeaponInvisibilityWasEnabled) { WeaponInvisibility(false); WeaponInvisibilityWasEnabled = false; }
	SessionLockFriendsOnlyBool ? SessionLockFriendsOnly() : void();
	if (ShowTVBool) { ShowTV(true); } else if (ShowTVWasEnabled) { ShowTV(false); ShowTVWasEnabled = false; }
}

bool Cheat::Features::GodmodeBool = false;
bool Cheat::Features::GodmodeWasEnabled = false;
void Cheat::Features::Godmode(bool toggle)
{
	GodmodeWasEnabled = true;
	ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), toggle);
}

bool Cheat::Features::NeverWantedBool = false;
void Cheat::Features::NeverWanted()
{
	if (PLAYER::GET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID()) > 0)
	{
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
	}
}

bool Cheat::Features::NoWeaponReloadBool = false;
void Cheat::Features::NoWeaponReload()
{
	Hash EquippedWeapon;
	if (WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &EquippedWeapon, false))
	{
		if (EquippedWeapon != 0xB62D1F67 && EquippedWeapon != 0x42BF8A85) //Skip if Widowmaker or Minigun; it won't shoot when this is looped
		{
			WEAPON::REFILL_AMMO_INSTANTLY(PLAYER::PLAYER_PED_ID());
		}
	}
}

bool Cheat::Features::InfiniteAmmoBool = false;
bool Cheat::Features::InfiniteAmmoWasEnabled = false;
void Cheat::Features::InfiniteAmmo(bool toggle)
{
	InfiniteAmmoWasEnabled = true;
	for (auto const& i : game_data::WeaponsHashList)
	{
		WEAPON::SET_PED_INFINITE_AMMO(PLAYER::PLAYER_PED_ID(), toggle, i.WeaponHash);
	}
}

bool Cheat::Features::SlowMotionBool = false;
bool Cheat::Features::SlowMotionWasEnabled = false;
void Cheat::Features::SlowMotion(bool toggle)
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

bool Cheat::Features::WorldBlackoutBool = false;
bool Cheat::Features::WorldBlackoutWasEnabled = false;
void Cheat::Features::WorldBlackout(bool toggle)
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

float Cheat::Features::GravityGunEntityDistance = 5.f;
bool Cheat::Features::GravityGunBool = false;
void Cheat::Features::GravityGun()
{
	if (CAM::GET_FOLLOW_PED_CAM_VIEW_MODE() == PedCamViewModes::FirstPerson)
	{
		CAM::SET_FOLLOW_PED_CAM_VIEW_MODE(PedCamViewModes::ThirdPersonMedium);
	}
	PAD::DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);

	if (!GUI::gui_controls::cursor_nav_state)
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
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, true);

	Vector3 dir = Cheat::Game::vector::get_cam_direction();
	Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 PlayerPedCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
	float spawnDistance = Game::vector::get_distance_between_two(camPosition, PlayerPedCoords);
	spawnDistance += GravityGunEntityDistance;
	Vector3 SpawnPositionVec2 = Game::vector::multiply(dir, spawnDistance);
	Vector3 spawnPosition = Game::vector::add_two(camPosition, SpawnPositionVec2);

	Player tempPed = PLAYER::PLAYER_ID();
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_AIM))
	{
		Vector3 EntityTargetPos = ENTITY::GET_ENTITY_COORDS(EntityTarget, false);
		PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
		if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, false))
		{
			EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
		}

		Game::entity::request_network_control(EntityTarget);

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
	if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
	{
		PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
	}
}

bool Cheat::Features::DisableHUDBool = false;
void Cheat::Features::DisableHUD()
{
	UI::HIDE_HUD_AND_RADAR_THIS_FRAME();
}

bool Cheat::Features::HideMinimapBool = false;
bool Cheat::Features::HideMinimapWasEnabled = false;
void Cheat::Features::HideMinimap()
{
	UI::DISPLAY_RADAR(false);
	HideMinimapWasEnabled = true;
}

bool Cheat::Features::NoGravityBool = false;
bool Cheat::Features::NoGravityWasEnabled = false;
void Cheat::Features::NoGravity(bool toggle)
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

bool Cheat::Features::WorldSnowLocalBool = false;
bool Cheat::Features::WorldSnowLocalWasEnabled = false;
void Cheat::Features::WorldSnowLocal(bool toggle)
{
	WorldSnowLocalWasEnabled = true;
	globalHandle(GLOBAL_SNOW[0]).At(GLOBAL_SNOW[1]).As<bool>() = toggle;
}

bool Cheat::Features::AutoTeleportToWaypointBool = false;
void Cheat::Features::AutoTeleportToWaypoint()
{
	if (!UI::IS_PAUSE_MENU_ACTIVE()) 
	{
		if (UI::IS_WAYPOINT_ACTIVE()) 
		{
			Game::teleport::to_blip(SpriteWaypoint); 
			UI::SET_WAYPOINT_OFF();
		}
	}
}

bool Cheat::Features::OneHitKillBool = false;
bool Cheat::Features::OneHitKillWasEnabled = false;
void Cheat::Features::OneHitKill()
{
	OneHitKillWasEnabled = true;
	PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), 999999.f);
	PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), 999999.f, false);
}

bool PauseTime_IsCurrentTimeSet = false;
int CurrentHourPauseTime;
int CurrentMinutePauseTime;
int CurrentSecondPauseTime;
bool Cheat::Features::PauseTimeBool = false;
void Cheat::Features::PauseTime(bool toggle)
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

bool Cheat::Features::ExplosiveMeleeBool = false;
void Cheat::Features::ExplosiveMelee()
{
	Memory::set_value<int>({ OFFSET_LOCAL_PED, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_FRAMEFLAGS }, FrameFlagExplosiveMelee);
}

bool Cheat::Features::OrbitalCannonCooldownBypassBool = false;
void Cheat::Features::OrbitalCannonCooldownBypass()
{
	if (NETWORK::NETWORK_IS_SESSION_STARTED()) { STATS::STAT_SET_INT(0xD25C0D25, 0, true); STATS::STAT_SET_INT(0xB2544929, 0, true); }
}

bool Cheat::Features::ProtectionVoteKickBool = false;
void Cheat::Features::ProtectionVoteKick(bool toggle)
{
	GameHooking::defuseEvent(KICK_VOTES_EVENT, toggle);
}

bool Cheat::Features::ProtectionFreezeBool = false;
void Cheat::Features::ProtectionFreeze(bool toggle)
{
	GameHooking::defuseEvent(RAGDOLL_REQUEST_EVENT, toggle);
	GameHooking::defuseEvent(INCIDENT_ENTITY_EVENT, toggle);
	GameHooking::defuseEvent(NETWORK_CLEAR_PED_TASKS_EVENT, toggle);
}

bool Cheat::Features::ProtectionWorldEventsBool = false;
void Cheat::Features::ProtectionWorldEvents(bool toggle)
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

bool Cheat::Features::ProtectionVehicleBool = false;
void Cheat::Features::ProtectionVehicle(bool toggle)
{
	GameHooking::defuseEvent(VEHICLE_COMPONENT_CONTROL_EVENT, toggle);
	GameHooking::defuseEvent(NETWORK_SOUND_CAR_HORN_EVENT, toggle);
	GameHooking::defuseEvent(MODIFY_VEHICLE_LOCK_WORD_STATE_DATA, toggle);
	GameHooking::defuseEvent(BLOW_UP_VEHICLE_EVENT, toggle);
}

bool Cheat::Features::ProtectionAlterWantedLevelBool = false;
void Cheat::Features::ProtectionAlterWantedLevel(bool toggle)
{
	GameHooking::defuseEvent(ALTER_WANTED_LEVEL_EVENT, toggle);
}

bool Cheat::Features::ProtectionGiveRemoveWeaponsBool = false;
void Cheat::Features::ProtectionGiveRemoveWeapons(bool toggle)
{
	GameHooking::defuseEvent(GIVE_WEAPON_EVENT, toggle);
	GameHooking::defuseEvent(REMOVE_WEAPON_EVENT, toggle);
	GameHooking::defuseEvent(REMOVE_ALL_WEAPONS_EVENT, toggle);
}

bool Cheat::Features::SuperJumpBool = false;
void Cheat::Features::SuperJump()
{
	Memory::set_value<int>({ OFFSET_LOCAL_PED, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_FRAMEFLAGS }, FrameFlagSuperJump);
}

bool Cheat::Features::ShowFPSBool = false;
void Cheat::Features::ShowFPS()
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

bool Cheat::Features::JumpAroundModeBool = false;
void Cheat::Features::JumpAroundMode()
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Vehicle* vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
		{
			if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(vehs[OffsetID]))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(vehs[OffsetID], 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0);
			}
		}
	}
}

bool FreeCamFeaturedUsed = false;
bool Cheat::Features::FreeCamBool = false;
Cam FreeCamHandle;
void Cheat::Features::FreeCam(bool toggle)
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

		p_coord = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);

		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PLAYER::PLAYER_PED_ID(), p_coord.x, p_coord.y, p_coord.z, 0, 0, 0);
		PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), true);
		UI::HIDE_HUD_AND_RADAR_THIS_FRAME();

		float speed = .5f;
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_SPRINT))
		{
			speed += .3f;
		}

		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_MOVE_UD)) // S key
		{
			speed /= -1;
			Vector3 CameraCoord = CAM::GET_CAM_COORD(FreeCamHandle);
			Vector3 VectorB = Game::vector::multiply(Game::vector::get_cam_direction(), speed);
			Vector3 c = Cheat::Game::vector::add_two(CameraCoord, VectorB);
			CAM::SET_CAM_COORD(FreeCamHandle, c.x, c.y, c.z);
		}

		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_MOVE_UP_ONLY)) // W key
		{
			Vector3 VectorB = Game::vector::multiply(Game::vector::get_cam_direction(), speed);
			Vector3 CameraCoord = CAM::GET_CAM_COORD(FreeCamHandle);
			Vector3 c = Cheat::Game::vector::add_two(CameraCoord, VectorB);
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

bool Cheat::Features::VehicleHornBoostBool = false;
void Cheat::Features::VehicleHornBoost()
{
	if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID()))
	{
		Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
		Game::entity::request_network_control(Veh);
		VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 70);
	}
}

bool Cheat::Features::VehicleGodmodeBool = false;
void Cheat::Features::VehicleGodmode(bool toggle)
{
	ENTITY::SET_ENTITY_INVINCIBLE(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), toggle);
}

bool Cheat::Features::VehicleInvisibleBool = false;
void Cheat::Features::VehicleInvisible(bool toggle)
{
	ENTITY::SET_ENTITY_VISIBLE(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), !toggle, false);
}

bool Cheat::Features::PlayerInvisibleLocalBool = false;
void Cheat::Features::PlayerInvisibleLocal(bool toggle)
{
	ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), !toggle, false);
}

bool Cheat::Features::PlayerInvisibleNetworkBool = false;
void Cheat::Features::PlayerInvisibleNetwork(bool toggle)
{
	NETWORK::_NETWORK_SET_ENTITY_INVISIBLE_TO_NETWORK(PLAYER::PLAYER_PED_ID(), toggle);
}

bool Cheat::Features::MobileRadioBool = false;
void Cheat::Features::MobileRadio(bool toggle)
{
	AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(toggle);
}

bool Cheat::Features::FreezeStationBool = false;
bool Cheat::Features::FreezeStationWasEnabled = false;
void Cheat::Features::FreezeStation()
{
	AUDIO::FREEZE_RADIO_STATION(AUDIO::GET_PLAYER_RADIO_STATION_NAME());
	FreezeStationWasEnabled = true;
}

bool Cheat::Features::WeaponRapidFireBool = false;
void Cheat::Features::WeaponRapidFire()
{
	if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false)) 
	{
		PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), true);
		Vector3 GameplayCamDirection = Game::vector::get_cam_direction();
		Vector3 StartCoords = Game::vector::add_two(CAM::GET_FINAL_RENDERED_CAM_COORD(), Game::vector::multiply(GameplayCamDirection, 1.0f));
		Vector3 EndCoords = Game::vector::add_two(StartCoords, Game::vector::multiply(GameplayCamDirection, 500.0f));
		Hash weaponhash;
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &weaponhash, false);
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_ATTACK) && !UI::IS_PAUSE_MENU_ACTIVE())
		{
			MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(StartCoords.x, StartCoords.y, StartCoords.z, EndCoords.x, EndCoords.y, EndCoords.z, 50, true, weaponhash, PLAYER::PLAYER_PED_ID(), true, false, 0xbf800000);
		}
	}
}

bool Cheat::Features::NoClipBool = false;
bool Cheat::Features::NoClipWasEnabled = false;
void Cheat::Features::NoClip()
{
	NoClipWasEnabled = true;
	Vector3 GetCamDir = Cheat::Game::vector::get_cam_direction();
	float d = 0.999999f;

	if (!PED::IS_PED_ON_FOOT(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
	{
		Vehicle CurrentVehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		Game::entity::request_network_control(CurrentVehicle);
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(CurrentVehicle, false);
		Vector3 rotation = CAM::GET_GAMEPLAY_CAM_ROT(0);

		ENTITY::SET_ENTITY_COLLISION(CurrentVehicle, true, true);
		ENTITY::SET_ENTITY_ROTATION(CurrentVehicle, rotation.x, rotation.y, rotation.z, 2, 1);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(CurrentVehicle, Pos.x, Pos.y, Pos.z, 0, 0, 0);
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_MOVE_UP_ONLY)) // W key
		{
			ENTITY::SET_ENTITY_COLLISION(CurrentVehicle, false, false);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(CurrentVehicle, Pos.x + (GetCamDir.x * d), Pos.y + (GetCamDir.y * d), Pos.z + (GetCamDir.z * d), 0, 0, 0);
		}
	}
	else
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);

		Vector3 rotation = CAM::GET_GAMEPLAY_CAM_ROT(0);
		ENTITY::SET_ENTITY_COLLISION(PLAYER::PLAYER_PED_ID(), true, true);
		ENTITY::SET_ENTITY_ROTATION(PLAYER::PLAYER_PED_ID(), rotation.x, rotation.y, rotation.z, 2, 1);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PLAYER::PLAYER_PED_ID(), Pos.x, Pos.y, Pos.z, 0, 0, 0);
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_MOVE_UP_ONLY)) // W key
		{
			ENTITY::SET_ENTITY_COLLISION(PLAYER::PLAYER_PED_ID(), false, false);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PLAYER::PLAYER_PED_ID(), Pos.x + (GetCamDir.x * d), Pos.y + (GetCamDir.y * d), Pos.z + (GetCamDir.z * d), 0, 0, 0);
		}
	}
}

int RainbowVehicle_Red = 255, RainbowVehicle_Green, RainbowVehicle_Blue;
bool Cheat::Features::RainbowVehicleBool = false;
void Cheat::Features::RainbowVehicle()
{
	GUI::FadeRGB(RainbowVehicle_Red, RainbowVehicle_Green, RainbowVehicle_Blue);
	VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), RainbowVehicle_Red, RainbowVehicle_Green, RainbowVehicle_Blue);
	VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), RainbowVehicle_Red, RainbowVehicle_Green, RainbowVehicle_Blue);
}

bool Cheat::Features::EntityInformationGunBool = false;
void Cheat::Features::EntityInformationGun()
{
	Entity AimedEntityHandle;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &AimedEntityHandle))
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

bool Cheat::Features::DeleteGunBool = false;
void Cheat::Features::DeleteGun()
{
	Entity AimedAtEntity;
	DWORD equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
	if (equippedWeapon == 0xBFD21232 || equippedWeapon == 0x88374054) // SNS Pistol & mk2 SNS Pistol
	{
		if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
		{
			if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &AimedAtEntity))
			{
				Game::entity::request_network_control(AimedAtEntity);
				ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&AimedAtEntity);
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(AimedAtEntity, true, true);
				ENTITY::DELETE_ENTITY(&AimedAtEntity);
			}
		}
	}
}

bool Cheat::Features::NerfBulletsBool = false;
bool Cheat::Features::NerfBulletsWasEnabled = false;
void Cheat::Features::NerfBullets()
{
	NerfBulletsWasEnabled = true;
	PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), 0.1f);
}

bool Cheat::Features::SpectatePlayerBool = false;
bool Cheat::Features::SpectatePlayerWasEnabled = false;
void Cheat::Features::SpectatePlayer(bool toggle)
{
	if (toggle)
	{
		SpectatePlayerWasEnabled = true;
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(SelectedPlayer));
		std::string String = "Spectating '" + (std::string)PLAYER::GET_PLAYER_NAME(SelectedPlayer) + "'";
		Game::notification::Subtitle(helper::StringToChar(String), 1);
	}
	else
	{
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(false, PLAYER::PLAYER_PED_ID());
	}
}

bool Cheat::Features::NoRagdollAndSeatbeltBool = false;
void Cheat::Features::NoRagdollAndSeatbelt(bool toggle)
{
	if (toggle)
	{
		PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), false);
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 32, false);
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), 1);
	}
	else
	{
		PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), true);
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 32, true);
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), 0);
	}
}

bool Cheat::Features::FreezeSelectedPlayerBool = false;
void Cheat::Features::FreezeSelectedPlayer()
{
	Ped PlayerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(SelectedPlayer);
	TASK::CLEAR_PED_TASKS_IMMEDIATELY(PlayerPed);
	TASK::CLEAR_PED_TASKS(PlayerPed);
	TASK::CLEAR_PED_SECONDARY_TASK(PlayerPed);
}

bool Cheat::Features::FreezeAllPlayersBool = false;
void Cheat::Features::FreezeAllPlayers()
{
	PlayersSessionForLoop
	{
		bool ExcludeSelf = PLAYER::PLAYER_ID() == i && AllPlayersExclusionsSelf;
		bool ExcludeFriend = Game::gtao::is_friend(i) && AllPlayersExclusionsFriends;
		bool ExcludeHost = Game::gtao::is_freemode_script_host(i) && AllPlayersExclusionsHost;

		if (!ExcludeHost && !ExcludeFriend && !ExcludeSelf && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i))
		{
			Ped PlayerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			TASK::CLEAR_PED_TASKS_IMMEDIATELY(PlayerPed);
			TASK::CLEAR_PED_TASKS(PlayerPed);
			TASK::CLEAR_PED_SECONDARY_TASK(PlayerPed);
		}
	}
}

bool Cheat::Features::TriggerBot_ShootNPCBool = false;
bool Cheat::Features::TriggerBot_ShootPlayersBool = false;
bool Cheat::Features::TriggerBotBool = false;
void Cheat::Features::TriggerBot()
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
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &AimedAtEntity))
	{
		Vector3 BoneCoords = PED::GET_PED_BONE_COORDS(AimedAtEntity, TargetBone, 0.1f, 0.0f, 0.0f);
		if ((PED::IS_PED_A_PLAYER(AimedAtEntity) && TriggerBot_ShootPlayersBool) || (ENTITY::IS_ENTITY_A_PED(AimedAtEntity) && TriggerBot_ShootNPCBool) && !ENTITY::IS_ENTITY_DEAD(AimedAtEntity, false) && ENTITY::GET_ENTITY_ALPHA(AimedAtEntity) == 255)
		{
			PED::SET_PED_SHOOTS_AT_COORD(PLAYER::PLAYER_PED_ID(), BoneCoords.x, BoneCoords.y, BoneCoords.z, true);
		}
	}
}

bool Cheat::Features::SuperBrakesBool = false;
void Cheat::Features::SuperBrakes()
{
	Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
	if ((PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_VEH_BRAKE) && ENTITY::GET_ENTITY_SPEED_VECTOR(vehicle, true).y > 1.f) ||
		(PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_VEH_ACCELERATE) && ENTITY::GET_ENTITY_SPEED_VECTOR(vehicle, true).y < -1.f))
	{
		VEHICLE::SET_VEHICLE_FORWARD_SPEED(vehicle, 0.f);
	}
}

bool Cheat::Features::TinyPlayerBool = false;
void Cheat::Features::TinyPlayer(bool toggle)
{
	PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 223, toggle);
}

bool Cheat::Features::UnlimitedRocketBoostBool = false;
void Cheat::Features::UnlimitedRocketBoost()
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false)) 
	{
		Ped veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
		VEHICLE::_SET_VEHICLE_ROCKET_BOOST_REFILL_TIME(veh, 0.f);
		VEHICLE::_SET_VEHICLE_ROCKET_BOOST_PERCENTAGE(veh, 100.f);

		if (VEHICLE::_IS_VEHICLE_ROCKET_BOOST_ACTIVE(veh)) 
		{
			VEHICLE::_SET_VEHICLE_ROCKET_BOOST_ACTIVE(veh, true);
			Game::notification::Subtitle((char*)"PRESS SPACEBAR TO STOP BOOST", 100);
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_DIVE)) // Spacebar
			{
				VEHICLE::_SET_VEHICLE_ROCKET_BOOST_ACTIVE(veh, false);
			}
		}
	}
}

std::string Cheat::Features::ShootEntitiesCurrent = "Rhino";
bool Cheat::Features::ShootEntitiesBool = false;
void Cheat::Features::ShootEntities()
{
	if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
	{
		Hash EntityHash = MISC::GET_HASH_KEY(helper::StringToChar(ShootEntitiesCurrent));

		if (STREAMING::IS_MODEL_VALID(EntityHash))
		{
			while (!STREAMING::HAS_MODEL_LOADED(EntityHash)) { STREAMING::REQUEST_MODEL(EntityHash); GameHooking::PauseMainFiber(0, false); }
			Vector3 Dimension1, Dimension2;
			MISC::GET_MODEL_DIMENSIONS(EntityHash, &Dimension1, &Dimension2);

			float Offset = Dimension2.y * 1.5; //1.6

			Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(PLAYER::PLAYER_PED_ID());
			Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
			float Rotation = ENTITY::GET_ENTITY_ROTATION(PLAYER::PLAYER_PED_ID(), 0).z;
			Vector3 gameplayCam = CAM::GET_FINAL_RENDERED_CAM_COORD();
			Vector3 gameplayCamDirection = Game::vector::get_cam_direction();
			Vector3 startCoords = Game::vector::add_two(gameplayCam, (Game::vector::multiply(gameplayCamDirection, 10)));
			Vector3 endCoords = Game::vector::add_two(gameplayCam, (Game::vector::multiply(gameplayCamDirection, 500.0f)));


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


bool Cheat::Features::PlayerESPBool = false;
void Cheat::Features::PlayerESP()
{
	if (NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1)
	{
		PlayersSessionForLoop
		{
			if (PLAYER::PLAYER_ID() != i) 
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
				Vector3 locationTwo = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
				GRAPHICS::DRAW_LINE(locationOne.x, locationOne.y, locationOne.z, locationTwo.x, locationTwo.y, locationTwo.z, 0, 0, 255, 255);
			}
		}
	}
}

bool Cheat::Features::OffRadarBool = false;
void Cheat::Features::OffRadar()
{
	globalHandle(GLOBAL_OFFRADAR[0]).At( 1 + PLAYER::PLAYER_ID() * GLOBAL_OFFRADAR[1]).At(GLOBAL_OFFRADAR[2]).As<bool>() = true;
	globalHandle(GLOBAL_NETWORK_STOPWATCH[0]).At(GLOBAL_NETWORK_STOPWATCH[1]).As<int>() = NETWORK::GET_NETWORK_TIME();
}

bool Cheat::Features::CopsTurnBlindEyeBool = false;
void Cheat::Features::CopsTurnBlindEye()
{
	globalHandle(GLOBAL_COPSTURNBLINDEYE[0]).At(GLOBAL_COPSTURNBLINDEYE[1]).As<int>() = GLOBAL_COPSTURNBLINDEYE[2];
	globalHandle(GLOBAL_NETWORK_STOPWATCH[0]).At(GLOBAL_NETWORK_STOPWATCH[1]).As<int>() = NETWORK::GET_NETWORK_TIME();
}

bool Cheat::Features::ExplodeLoopSelectedPlayerBool = false;
void Cheat::Features::ExplodeLoopSelectedPlayer()
{
	Vector3 SelectedPlayerPedCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer), false);
	FIRE::ADD_EXPLOSION(SelectedPlayerPedCoords.x, SelectedPlayerPedCoords.y, SelectedPlayerPedCoords.z, 0, 1000.f, true, false, 0.f, false);
}

bool Cheat::Features::DriveOnWaterBool = false;
void Cheat::Features::DriveOnWater()
{
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
	DWORD model = ENTITY::GET_ENTITY_MODEL(veh);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
	float height = 0.f;
	WATER::SET_DEEP_OCEAN_SCALER(height);
	if (!VEHICLE::IS_THIS_MODEL_A_PLANE(ENTITY::GET_ENTITY_MODEL(veh)) && WATER::GET_WATER_HEIGHT_NO_WAVES(pos.x, pos.y, pos.z, &height)) 
	{
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, 0xAEB63C4B, false, false, true);
		if (ENTITY::DOES_ENTITY_EXIST(container) && height > -50.0f) 
		{
			Vector3 pRot = ENTITY::GET_ENTITY_ROTATION(PLAYER::PLAYER_PED_ID(), 0);
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) pRot = ENTITY::GET_ENTITY_ROTATION(veh, 0);
			Game::entity::request_network_control(container);
			ENTITY::SET_ENTITY_COORDS(container, pos.x, pos.y, height - 1.5f, false, false, false, 1);
			ENTITY::SET_ENTITY_ROTATION(container, 0, 0, pRot.z, 0, 1);
			Vector3 containerCoords = ENTITY::GET_ENTITY_COORDS(container, false);
			if (pos.z < containerCoords.z) 
			{
				if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
				{
					ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), pos.x, pos.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
				}
				else 
				{
					Game::entity::request_network_control(veh);
					Vector3 vehc = ENTITY::GET_ENTITY_COORDS(veh, false);
					ENTITY::SET_ENTITY_COORDS(veh, vehc.x, vehc.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
				}
			}
		}
		else 
		{
			Hash model = 0xAEB63C4B;
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
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, 0xAEB63C4B, false, false, true);
		if (ENTITY::DOES_ENTITY_EXIST(container)) 
		{
			Game::entity::request_network_control(container);
			ENTITY::SET_ENTITY_COORDS(container, 0, 0, -1000.0f, 0, 0, 0, 1);
			GameHooking::PauseMainFiber(10);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&container);
			ENTITY::DELETE_ENTITY(&container);
			WATER::RESET_DEEP_OCEAN_SCALER();
		}
	}
}

bool Cheat::Features::SuperManBool = false;
void Cheat::Features::SuperMan()
{
	if(!Cheat::Features::NoRagdollAndSeatbeltBool) { Features::NoRagdollAndSeatbeltBool = true; Game::notification::Minimap((char*)"No Ragdoll & Seatbelt feature enabled for this feature"); }
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 1, false, true); // gadget_parachute
	ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
	PED::SET_PED_TO_RAGDOLL_WITH_FALL(PLAYER::PLAYER_PED_ID(), 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);

	if (ENTITY::IS_ENTITY_IN_AIR(PLAYER::PLAYER_PED_ID()) && !PED::IS_PED_RAGDOLL(PLAYER::PLAYER_PED_ID()))
	{
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_MOVE_UP_ONLY)) { Game::entity::apply_force(PLAYER::PLAYER_PED_ID(), 0, 6, 0); } // W
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_MOVE_DOWN_ONLY)) { Game::entity::apply_force(PLAYER::PLAYER_PED_ID(), 0, -6, 0); } // S
		if (PAD::IS_DISABLED_CONTROL_PRESSED(0, INPUT_SPRINT)) { Game::entity::apply_force(PLAYER::PLAYER_PED_ID(), 0, 0, 6); } // Left shift
	}
}

bool Cheat::Features::ShakeCamSelectedPlayerBool = false;
void Cheat::Features::ShakeCamSelectedPlayer()
{
	Vector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::SelectedPlayer), false);
	FIRE::ADD_EXPLOSION(targetCords.x, targetCords.y, targetCords.z, 0, 0.f, false, true, 1000.f, true);
}

bool Cheat::Features::RainbowGunBool = false;
void Cheat::Features::RainbowGun()
{
	for (auto const& i : game_data::WeaponsHashList)
	{
		Hash CurrentHash = i.WeaponHash;
		if (WEAPON::HAS_PED_GOT_WEAPON(PLAYER::PLAYER_PED_ID(), CurrentHash, 0))
		{
			WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), CurrentHash, rand() % 8);
		}
	}

}

bool Cheat::Features::DisableMobilePhoneBool = false;
void Cheat::Features::DisableMobilePhone()
{
	globalHandle(GLOBAL_DISABLE_MOBILE_PHONE).As<int>() = 1;
}

bool Cheat::Features::NoIdleKickBool = false;
void Cheat::Features::NoIdleKick()
{
	globalHandle(GLOBAL_NO_IDLE_KICK1[0]).At(GLOBAL_NO_IDLE_KICK1[1]).As<int>() = -1;
	globalHandle(GLOBAL_NO_IDLE_KICK2[0]).At(GLOBAL_NO_IDLE_KICK2[1]).As<int>() = -1;
}

DWORD VehicleWeapons_LastTick = 0;
bool Cheat::Features::VehicleWeapons_TankRounds = true;
bool Cheat::Features::VehicleWeapons_VehicleRockets = false;
bool Cheat::Features::VehicleWeapons_Fireworks = false;
bool Cheat::Features::VehicleWeapons_DrawLaser = false;
bool Cheat::Features::VehicleWeaponsBool = false;
void Cheat::Features::VehicleWeapons()
{
	if (VehicleWeapons_DrawLaser) 
	{ 
		Vehicle VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
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

	if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID()) && VehicleWeapons_LastTick + 150 < GetTickCount64() && PLAYER::IS_PLAYER_CONTROL_ON(PLAYER::PLAYER_ID()) && PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

		Vector3 v0, v1;
		MISC::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket;
		if (VehicleWeapons_TankRounds) { VehicleWeapons_Fireworks = false; VehicleWeapons_VehicleRockets = false; weaponAssetRocket = 0x73F7C04B; }
		else if (VehicleWeapons_VehicleRockets) { VehicleWeapons_TankRounds = false; VehicleWeapons_Fireworks = false; weaponAssetRocket = 0xBEFDC581; }
		else if (VehicleWeapons_Fireworks) { VehicleWeapons_VehicleRockets = false; VehicleWeapons_TankRounds = false;  weaponAssetRocket = 0x7F7497E5; }

		if (VehicleWeapons_TankRounds || VehicleWeapons_VehicleRockets || VehicleWeapons_Fireworks)
		{
			if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket)) { WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0); while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket)) { GameHooking::PauseMainFiber(0); } }

			Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1f);
			Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1f);
			Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
			Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);
			MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z, coords0to.x, coords0to.y, coords0to.z, 250, 1, weaponAssetRocket, PLAYER::PLAYER_PED_ID(), 1, 0, -1.0);
			MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z, coords1to.x, coords1to.y, coords1to.z, 250, 1, weaponAssetRocket, PLAYER::PLAYER_PED_ID(), 1, 0, -1.0);
		}
		VehicleWeapons_LastTick = GetTickCount64();
	}
}

bool Cheat::Features::AutoGiveAllWeaponsBool = false;
void Cheat::Features::AutoGiveAllWeapons()
{
	if (PLAYER::IS_PLAYER_PLAYING(PLAYER::PLAYER_ID())) 
	{ 
		for (auto const& i : game_data::WeaponsHashList)
		{
			if (!WEAPON::HAS_PED_GOT_WEAPON(PLAYER::PLAYER_PED_ID(), i.WeaponHash, false))
			{
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), i.WeaponHash, 9999, false);
			}
		}
	}
}

bool Cheat::Features::AutoGiveAllWeaponUpgradesBool = false;
void Cheat::Features::AutoGiveAllWeaponUpgrades()
{
	if (PLAYER::IS_PLAYER_PLAYING(PLAYER::PLAYER_ID()))
	{
		Game::weapon::max_upgrade_all(PLAYER::PLAYER_PED_ID());
	}
}

bool Cheat::Features::CrossHairBool = false;
bool Cheat::Features::CrossHairADSOnlyBool = false;
void Cheat::Features::CrossHair()
{
	if (!CrossHairADSOnlyBool || CrossHairADSOnlyBool && PLAYER::IS_PLAYER_FREE_AIMING(PLAYER::PLAYER_ID()))
	{
		GUI::DrawSpriteInGame("Textures", "Crosshair", 0.50f, 0.50f, 0.060f, 0.100f, 0, GUI::PrimaryColor.r, GUI::PrimaryColor.g, GUI::PrimaryColor.b, 255);
	}
}

bool Cheat::Features::RGBDiscoBool = false;
bool Cheat::Features::RGBDiscoFirstCall = true;
void Cheat::Features::RGBDisco()
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
	GUI::FadeRGB(GUI::PrimaryColor.r, GUI::PrimaryColor.g, GUI::PrimaryColor.b);
	GUI::FadeRGB(GUI::TextColorAndFont.r, GUI::TextColorAndFont.g, GUI::TextColorAndFont.b);
}

bool Cheat::Features::WeaponInvisibilityBool = false;
bool Cheat::Features::WeaponInvisibilityWasEnabled = false;
void Cheat::Features::WeaponInvisibility(bool toggle)
{
	WeaponInvisibilityWasEnabled = true;
	ENTITY::SET_ENTITY_VISIBLE(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID(), 0), !toggle, false);
}

bool Cheat::Features::SessionLockFriendsOnlyBool = false;
void Cheat::Features::SessionLockFriendsOnly()
{
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		PlayersSessionForLoop
		{
			if (PLAYER::PLAYER_ID() != i && NETWORK::NETWORK_IS_PLAYER_ACTIVE(i) && !Game::gtao::is_friend(i))
			{
				Game::gtao::tse::start_event(Game::gtao::tse::types::KICK_TO_SINGLE_PLAYER, i);
			}
		}
	}
}

bool Cheat::Features::ShowTVBool = false;
bool Cheat::Features::ShowTVWasEnabled = false;
void Cheat::Features::ShowTV(bool toggle)
{
	ShowTVWasEnabled = true;
	GRAPHICS::SET_TV_AUDIO_FRONTEND(toggle);
	GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(4);
	GRAPHICS::SET_SCRIPT_GFX_DRAW_BEHIND_PAUSEMENU(toggle);
	GRAPHICS::DRAW_TV_CHANNEL(0.800f, 0.200f, 0.2f, 0.2f, 0.0f, 255, 255, 255, 250);
}