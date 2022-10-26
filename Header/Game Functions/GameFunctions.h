#pragma once

namespace Cheat
{
	namespace GameFunctions
	{
		extern Player PlayerID;
		extern Ped PlayerPedID;
		extern std::string InGameKeyboardWindowTitle;
		extern std::string InGameHelpTextMessage;
		void GiveAllWeaponsToPlayer(Ped Player);
		void RepairAndCleanVehicle(Vehicle vehicle);
		void SubtitleNotification(char* Message, int ShowDuration = 4000);
		void TeleportToBlipCoord(Blip TargetBlip);
		void TeleportToObjective();
		void SetOffAlarmPlayerVehicle(Ped selectedPed);
		bool IsPlayerFriend(Player player);
		Vector3 MultiplyVector(Vector3 vector, float inc);
		Vector3 AddVector(Vector3 vector, Vector3 vector2);
		void SetRankRockstarGift(int Rank);
		int ReturnReputationPointsAmount(int Level);
		Vector3 RotationToDirection(Vector3* rot);
		Vector3 AddTwoVectors(Vector3* vectorA, Vector3* vectorB);
		Vector3 MultiplyVector(Vector3* vector, float x);
		float GetDistanceBetweenTwoVectors(Vector3* pointA, Vector3* pointB);
		void TeleportToCoords(Entity e, Vector3 coords, bool AutoCorrectGroundHeight, bool IgnoreCurrentPedVehicle);
		float GetDistanceBetweenTwoPoints(Vector3 A, Vector3 B);
		float DegreesToRadians(float degs);
		void GetCameraDirection(float* dirX, float* dirY, float* dirZ);
		void RequestNetworkControlOfEntity(Entity entity);
		void ClonePed(Ped ped);
		bool DisplayKeyboardAndReturnInput(int MaxInput, std::string Title, const char* &Input);
		bool DisplayKeyboardAndReturnInputInteger(int MaxInput, std::string Title, int &Input);
		void StopAllPedAnimations(Ped TargetPed);
		float Get3DDistance(Vector3 a, Vector3 b);
		void ApplyForceToEntity(Entity e, float x, float y, float z);
		void SpawnVehicle(const char* ModelName);
		void MaxDowngradeVehicle(int VehicleHandle);
		void MaxUpgradeVehicle(int VehicleHandle);
		void EnableDisableAntiCrashCamera();
		void CheckNewSessionMembersLoop();
		bool IsEntityInInterior(Entity Entity);
		void ClearNearbyPedAnimations();
		void DoNearbyPedsAnimation(char* AnimationName, char* AnimationID);
		void PlayPedAnimation(Ped TargetPed, char* AnimationName, char* AnimationID, bool Controllable);
		void AttachObjectToPed(Ped Ped, char* ObjectName);
		void RemoveObjectFromPed(Ped Ped, char* ObjectName);
		void MinimapNotification(char* Message);
		void AdvancedMinimapNotification(char* Message, char* PicName1, char* PicName2, bool Flash, int IconType, char* Sender, char* Subject, float Duration, char* ClanTag);
		void AddBlipToVehicle(Vehicle Vehicle);
		bool DeleteVehicle(Vehicle Vehicle);
		float MSToKMH(float MS);
		float MSToMPH(float MS);
		float KMHToMS(float MS);
		float MPHToMS(float MS);
		void ChangeEntityInvincibilityState(Entity EntityHandle, bool Enable);
		const char* ReturnOnlinePlayerPictureString(Player PlayerHandle);
		VECTOR2 ReturnCursorYXCoords();
		void EnableDisableCursorNavigation();
		bool IsCursorAtXYPosition(VECTOR2 const& boxCentre, VECTOR2 const& boxSize);
		void ChangePedModelLocalPlayer(Hash PedModel);
		bool PlayerIsFreemodeScriptHost(Player Player);
		void CopySelectedPlayerOutfit(Player SelectedPlayer);
		int ReturnPlayerRockstarID(Player PlayerHandle);
		std::string ReturnPlayerIPAddressAsString(Player PlayerHandle);
		std::string ReturnCurrentGTAOCharacter(bool NumberOnly = false);
		void PlayFrontendSoundDefault(char* SoundName);
		void PlayScenarioNearbyPeds(char* Scenario);
		void MaxUpgradeAllWeapons();
		void ShowTeleportLocationsMenu(std::vector<TeleportLocationStruct> category);
		void FadeRGB(int& r, int& g, int& b);
		bool ShowFullScreenMessage(std::string Message);
		void SetCharacterSkillStat(std::string Skill, int Level);
		int GetCharacterSkillStat(std::string Skill);
		void ChangeGTAOSessionType(eSessionTypes SessionType);
		void TriggerScriptEvent(eScriptEventTypes EventType, Player TargetPlayer, int property_teleport_index = -1);
	}
}

// Macros
#define PlayersSessionForLoop for(int i = 0; i < 32; i++)