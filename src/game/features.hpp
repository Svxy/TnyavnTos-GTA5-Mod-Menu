#pragma once

namespace Cheat
{
	namespace Features
	{
		extern int SpeedometerVectorPosition;
		extern int AimbotBoneVectorPosition;
		extern int ImpactAmmoVectorPosition;
		extern int CustomAmmoVectorPosition;
		extern int ParticleAmmoVectorPosition;
		extern int FontTypeVectorPosition;
		extern int AnimationsVectorPosition;
		extern int ScenariosVectorPosition;
		extern int PedMovementVectorPosition;
		extern int OpenVehicleDoorPosition;
		extern int CloseVehicleDoorPosition;
		extern int FastSuperRunPosition;
		extern int SelectedPlayer;
		extern int PlayerOpacityInt;
		extern bool BlockAllScriptEvents;
		extern bool ProtectionScriptEvents_Kicks;
		extern bool ProtectionScriptEvents_CEOMoney;
		extern bool ProtectionScriptEvents_PropertyTeleport;
		extern bool ProtectionScriptEvents_CayoPericoTeleport;
		extern bool ProtectionScriptEvents_ForceIntoMission;
		extern bool ProtectionScriptEvents_Bounty;
		extern bool ProtectionScriptEvents_ClearWantedlevel;
		extern bool ProtectionScriptEvents_GameBanner;
		extern bool ProtectionScriptEvents_NetworkBail;
		extern bool ProtectionScriptEvents_Crash;
		extern bool ProtectionScriptEvents_PersonalVehicleDestroyed;
		extern bool ProtectionScriptEvents_RemoteOffradar;
		extern bool ProtectionScriptEvents_SendToCutscene;
		extern bool ProtectionScriptEvents_SendToLocation;
		extern bool ProtectionScriptEvents_SoundSpam;
		extern bool ProtectionScriptEvents_Spectate;
		extern bool HideOwnIPAddress;
		extern bool DisableTransactionErrorWarning;
		extern bool DisableCutscenes;
		extern bool HideVehiclePreview;
		extern bool ShowJoiningPlayersNotification;
		extern bool VehicleSpawnerSpawnInsideVehicle;
		extern bool VehicleSpawnerDeleteOldVehicle;
		extern bool VehicleSpawnerSpawnWithGodmode;
		extern bool VehicleSpawnerSpawnMaxUpgraded;
		extern bool VehicleSpawnerSpawnAirVehicleAir;
		extern int VehicleSpawnerLicensePlateVectorPosition;
		extern std::string VehicleSpawnerCustomLicensePlateTextString;
		extern bool HidePlayerInformationBox;
		extern bool HideSelectableInformationBox;
		extern bool ControllableAnimations;
		extern bool AllPlayersExclusionsSelf;
		extern bool AllPlayersExclusionsFriends;
		extern bool AllPlayersExclusionsHost;
		extern bool TeleportTransition;
		extern bool NoTextureFileOverwrite;
		extern bool SafeMode;

		void Loop();
		extern bool GodmodeBool;
		extern bool GodmodeWasEnabled;
		void Godmode(bool toggle);
		extern bool NeverWantedBool;
		void NeverWanted();
		extern bool NoWeaponReloadBool;
		void NoWeaponReload();
		extern bool InfiniteAmmoBool;
		extern bool InfiniteAmmoWasEnabled;
		void InfiniteAmmo(bool toggle);
		extern bool SlowMotionBool;
		extern bool SlowMotionWasEnabled;
		void SlowMotion(bool toggle);
		extern bool WorldBlackoutBool;
		extern bool WorldBlackoutWasEnabled;
		void WorldBlackout(bool toggle);
		extern float GravityGunEntityDistance;
		extern bool GravityGunBool;
		void GravityGun();
		extern bool DisableHUDBool;
		void DisableHUD();
		extern bool HideMinimapBool;
		extern bool HideMinimapWasEnabled;
		void HideMinimap();
		extern bool NoGravityBool;
		extern bool NoGravityWasEnabled;
		void NoGravity(bool toggle);
		extern bool WorldSnowLocalBool;
		extern bool WorldSnowLocalWasEnabled;
		void WorldSnowLocal(bool toggle);
		extern bool AutoTeleportToWaypointBool;
		void AutoTeleportToWaypoint();
		extern bool OneHitKillBool;
		extern bool OneHitKillWasEnabled;
		void OneHitKill();
		extern bool PauseTimeBool;
		void PauseTime(bool toggle);
		extern bool ExplosiveMeleeBool;
		void ExplosiveMelee();
		extern bool OrbitalCannonCooldownBypassBool;
		void OrbitalCannonCooldownBypass();
		extern bool ProtectionVoteKickBool;
		void ProtectionVoteKick(bool toggle);
		extern bool ProtectionFreezeBool;
		void ProtectionFreeze(bool toggle);
		extern bool ProtectionWorldEventsBool;
		void ProtectionWorldEvents(bool toggle);
		extern bool ProtectionVehicleBool;
		void ProtectionVehicle(bool toggle);
		extern bool ProtectionAlterWantedLevelBool;
		void ProtectionAlterWantedLevel(bool toggle);
		extern bool ProtectionGiveRemoveWeaponsBool;
		void ProtectionGiveRemoveWeapons(bool toggle);
		extern bool SuperJumpBool;
		void SuperJump();
		extern bool ShowFPSBool;
		void ShowFPS();
		extern bool JumpAroundModeBool;
		void JumpAroundMode();
		extern bool VehicleHornBoostBool;
		void VehicleHornBoost();
		extern bool VehicleGodmodeBool;
		void VehicleGodmode(bool toggle);
		extern bool VehicleInvisibleBool;
		void VehicleInvisible(bool toggle);
		extern bool PlayerInvisibleLocalBool;
		void PlayerInvisibleLocal(bool toggle);
		extern bool PlayerInvisibleNetworkBool;
		void PlayerInvisibleNetwork(bool toggle);
		extern bool MobileRadioBool;
		void MobileRadio(bool toggle);
		extern bool FreezeStationBool;
		extern bool FreezeStationWasEnabled;
		void FreezeStation();
		extern bool WeaponRapidFireBool;
		void WeaponRapidFire();
		extern bool NoClipBool;
		extern bool NoClipWasEnabled;
		void NoClip();
		extern bool RainbowVehicleBool;
		void RainbowVehicle();
		extern bool DeleteGunBool;
		void DeleteGun();
		extern bool NerfBulletsBool;
		extern bool NerfBulletsWasEnabled;
		void NerfBullets();
		extern bool EntityInformationGunBool;
		void EntityInformationGun();
		extern bool SpectatePlayerBool;
		extern bool SpectatePlayerWasEnabled;
		void SpectatePlayer(bool toggle);
		extern bool NoRagdollAndSeatbeltBool;
		void NoRagdollAndSeatbelt(bool toggle);
		extern bool FreezeSelectedPlayerBool;
		void FreezeSelectedPlayer();
		extern bool FreezeAllPlayersBool;
		void FreezeAllPlayers();
		extern bool TriggerBot_ShootNPCBool;
		extern bool TriggerBot_ShootPlayersBool;
		extern bool TriggerBotBool;
		void TriggerBot();
		extern bool SuperBrakesBool;
		void SuperBrakes();
		extern bool TinyPlayerBool;
		void TinyPlayer(bool toggle);
		extern bool UnlimitedRocketBoostBool;
		void UnlimitedRocketBoost();
		extern bool ShootEntitiesBool;
		extern std::string ShootEntitiesCurrent;
		void ShootEntities();
		extern bool PlayerESPBool;
		void PlayerESP();
		extern bool OffRadarBool;
		void OffRadar();
		extern bool ExplodeLoopSelectedPlayerBool;
		void ExplodeLoopSelectedPlayer();
		extern bool DriveOnWaterBool;
		void DriveOnWater();
		extern bool SuperManBool;
		void SuperMan();
		extern bool ShakeCamSelectedPlayerBool;
		void ShakeCamSelectedPlayer();
		extern bool RainbowGunBool;
		void RainbowGun();
		extern bool DisableMobilePhoneBool;
		void DisableMobilePhone();
		extern bool NoIdleKickBool;
		void NoIdleKick();
		extern bool CopsTurnBlindEyeBool;
		void CopsTurnBlindEye();
		extern bool VehicleWeaponsBool;
		extern bool VehicleWeapons_TankRounds;
		extern bool VehicleWeapons_VehicleRockets;
		extern bool VehicleWeapons_Fireworks;
		extern bool VehicleWeapons_DrawLaser;
		void VehicleWeapons();
		extern bool AutoGiveAllWeaponsBool;
		void AutoGiveAllWeapons();
		extern bool AutoGiveAllWeaponUpgradesBool;
		void AutoGiveAllWeaponUpgrades();
		extern bool CrossHairBool;
		extern bool CrossHairADSOnlyBool;
		void CrossHair();
		extern bool FreeCamBool;
		void FreeCam(bool toggle);
		extern bool RGBDiscoBool;
		extern bool RGBDiscoFirstCall;
		void RGBDisco();
		extern bool WeaponInvisibilityBool;
		extern bool WeaponInvisibilityWasEnabled;
		void WeaponInvisibility(bool toggle);
		extern bool SessionLockFriendsOnlyBool;
		void SessionLockFriendsOnly();
		extern bool ShowTVBool;
		extern bool ShowTVWasEnabled;
		void ShowTV(bool toggle);
	}
}