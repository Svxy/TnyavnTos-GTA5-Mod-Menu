#include "game_data.hpp"

namespace Cheat
{
	// https://wiki.rage.mp/index.php?title=Weapons
	const std::vector<game_data::WeaponHashes> game_data::WeaponsHashList = {
		{ "Knife", 0x99B507EA					}, //WeaponKnife
		{ "Nightstick", 0x678B81B1				}, //WeaponNightstick
		{ "Hammer", 0x4E875F73					}, //WeaponHammer
		{ "Bat", 0x958A4A8F						}, //WeaponBat
		{ "Golf Club", 0x440E4788				}, //WeaponGolfClub
		{ "Crowbar", 0x84BD7BFD					}, //WeaponCrowbar
		{ "Pistol", 0x1B06D571					}, //WeaponPistol
		{ "Combat Pistol", 0x5EF9FEC4			}, //WeaponCombatPistol
		{ "AP Pistol", 0x22D8FE39				}, //WeaponAPPistol
		{ "Pistol .50", 0x99AEEB3B				}, //WeaponPistol50
		{ "Micro SMG", 0x13532244				}, //WeaponMicroSMG
		{ "SMG", 0x2BE6766B						}, //WeaponSMG
		{ "Assault SMG", 0xEFE7E2DF				}, //WeaponAssaultSMG
		{ "Combat PDW", 0x0A3D4D34				}, //WeaponCombatPDW
		{ "Assault Rifle", 0xBFEFFF6D			}, //WeaponAssaultRifle
		{ "Carbine Rifle", 0x83BF0278			}, //WeaponCarbineRifle
		{ "Advanced Rifle", 0xAF113F99			}, //WeaponAdvancedRifle
		{ "MG", 0x9D07F764						}, //WeaponMG
		{ "Combat MG", 0x7FD62962				}, //WeaponCombatMG
		{ "Pump Shotgun", 0x1D073A89			}, //WeaponPumpShotgun
		{ "Saw-Off Shotgun", 0x7846A318			}, //WeaponSawnOffShotgun
		{ "Assault Shotgun", 0xE284C527			}, //WeaponAssaultShotgun
		{ "Bullpup Shotgun", 0x9D61E50F			}, //WeaponBullpupShotgun
		{ "Stun Gun", 0x3656C8C1				}, //WeaponStunGun
		{ "Sniper Rifle", 0x5FC3C11				}, //WeaponSniperRifle
		{ "Heavy Sniper", 0xC472FE2				}, //WeaponHeavySniper
		{ "Grenade Launcher", 0xA284510B		}, //WeaponGrenadeLauncher
		{ "Grenade Launcher (Smoke)", 0x4DD2DC56}, //WeaponGrenadeLauncherSmoke
		{ "RPG", 0xB1CA77B1						}, //WeaponRPG
		{ "Minigun", 0x42BF8A85					}, //WeaponMinigun
		{ "Grenade", 0x93E220BD					}, //WeaponGrenade
		{ "Sticky Bomb", 0x2C3731D9				}, //WeaponStickyBomb
		{ "Smoke Grenade", 0xFDBC8A50			}, //WeaponSmokeGrenade
		{ "BZ Gas", 0xA0973D5E					}, //WeaponBZGas
		{ "Molotov", 0x24B17070					}, //WeaponMolotov
		{ "Fire Extinguisher", 0x60EC506		}, //WeaponFireExtinguisher
		{ "Petrol Can", 0x34A67B97				}, //WeaponPetrolCan
		{ "SNS Pistol", 0xBFD21232				}, //WeaponSNSPistol
		{ "Special Carbine", 0xC0A3098D			}, //WeaponSpecialCarbine
		{ "Heavy Pistol", 0xD205520E			}, //WeaponHeavyPistol
		{ "Bullpup Rifle", 0x7F229F94			}, //WeaponBullpupRifle
		{ "Homing Launcher", 0x63AB0442			}, //WeaponHomingLauncher
		{ "Proximity Mine", 0xAB564B93			}, //WeaponProximityMine
		{ "Snowball", 0x787F0BB					}, //WeaponSnowball
		{ "Vintage Pistol", 0x83839C4			}, //WeaponVintagePistol
		{ "Dagger", 0x92A27487					}, //WeaponDagger
		{ "Firework", 0x7F7497E5				}, //WeaponFirework
		{ "Musket", 0xA89CB99E					}, //WeaponMusket
		{ "Marksman Rifle", 0xC734385A			}, //WeaponMarksmanRifle
		{ "Heavy Shotgun", 0x3AABBBAA			}, //WeaponHeavyShotgun
		{ "Gusenberg", 0x61012683				}, //WeaponGusenberg
		{ "Hatchet", 0xF9DCBF2D					}, //WeaponHatchet
		{ "Rail Gun", 0x6D544C99				}, //WeaponRailgun
		{ "Unarmed", 0xA2719263					}, //WeaponUnarmed
		{ "Bottle", 0xF9E6AA4B					}, //WeaponBottle
		{ "Flashlight", 0x8BB05FD7				}, //WeaponFlashlight
		{ "Knuckle", 0xD8DF3C3C					}, //WeaponKnuckle
		{ "Machete", 0xDD5DF8D9					}, //WeaponMachete
		{ "Switch Blade", 0xDFE37640			}, //WeaponSwitchBlade
		{ "Wrench", 0x19044EE0					}, //WeaponWrench
		{ "Battle Axe", 0xCD274149				}, //WeaponBattleAxe
		{ "Pool Cue", 0x94117305				}, //WeaponPoolCue
		{ "Stone Hatchet", 0x3813FC08			}, //WeaponStoneHatchet
		{ "Pistol Mk2", 0xBFE256D4				}, //WeaponPistolMk2
		{ "SNS Pistol Mk2", 0x88374054			}, //WeaponSNSPistolMk2
		{ "Flare Gun", 0x47757124				}, //WeaponFlareGun
		{ "Marksman Pistol", 0xDC4DB296			}, //WeaponMarksmanPistol
		{ "Revolver", 0xC1B3C3D1				}, //WeaponRevolver
		{ "Revolver Mk2", 0xCB96392F			}, //WeaponRevolverMk2
		{ "Double Action", 0x97EA20B8			}, //WeaponDoubleAction
		{ "Ray Pistol", 0xAF3696A1				}, //WeaponRayPistol
		{ "Ceramic Pistol", 0x2B5EF5EC			}, //WeaponCeramicPistol
		{ "Navy Revolver", 0x917F6C8C			}, //WeaponNavyRevolver
		{ "Gadget Pistol", 0x57A4368C			}, //WeaponGadgetPistol
		{ "SMG Mk2", 0x78A97CD0					}, //WeaponSMGMk2
		{ "Machine Pistol", 0xDB1AA450			}, //WeaponMachinePistol
		{ "Mini SMG", 0xBD248B55				}, //WeaponMiniSMG
		{ "Ray Carbine", 0x476BF155				}, //WeaponRayCarbine
		{ "Pump Shotgun Mk2", 0x555AF99A		}, //WeaponPumpshotgunMk2
		{ "Db Shotgun", 0xEF951FBB				}, //WeaponDbShotgun
		{ "Auto Shotgun", 0x12E82D3D			}, //WeaponAutoShotgun
		{ "Combat Shotgun", 0x5A96BA4			}, //WeaponCombatShotgun
		{ "Assault Rifle Mk2", 0x394F415C		}, //WeaponAssaultRifleMk2
		{ "Carbine Rifle Mk2", 0xFAD1F1C9		}, //WeaponCarbineRifleMk2
		{ "Special Carbine Mk2", 0x969C3D67		}, //WeaponSpecialCarbineMk2
		{ "Bullpup Rifle Mk2", 0x84D6FAFD		}, //WeaponBullpupRifleMk2
		{ "Compact Rifle", 0x624FE830			}, //WeaponCompactRifle
		{ "Military Rifle", 0x9D1F17E6			}, //WeaponMilitaryRifle
		{ "Combat MG", 0xDBBD7280				}, //WeaponCombatMG
		{ "Sniper Rifle", 0x05FC3C11			}, //WeaponSniperRifle
		{ "Heavy Sniper", 0x0C472FE2			}, //WeaponHeavySniper
		{ "Heavy Sniper Mk2", 0xA914799			}, //WeaponHeavySniperMk2
		{ "Marksman Rifle", 0xC734385A			}, //WeaponMarksmanRifle
		{ "Marksman Rifle Mk2", 0x6A6C02E0		}, //WeaponMarksmanRifleMk2
		{ "Compact Launcher", 0x0781FE4A		}, //WeaponCompactLauncher
		{ "Widowmaker", 0xB62D1F67				}, //WeaponWidowmaker
		{ "Pipe Bomb", 0xBA45E8B8				}, //WeaponPipeBomb
		{ "Ball", 0x23C9F95C					}, //WeaponBall
		{ "Flare", 0x497FACC3					}, //WeaponFlare
		{ "Parachute", 0xFBAB5776				}, //WeaponParachute
		{ "Fire Extinguisher", 0x060EC506		}, //WeaponFireExtinguisher
		{ "Hazard Can", 0xBA536372				}, //WeaponHazardCan
		{ "Fertilizer Can", 0x184140A1			}, //WeaponFertilizerCan	
		{ "Heavy Rifle", 0xC78D71B4				}, //WeaponHeavyRifle									
		{ "Compact EMP Launcher", 0xDB26713A	}, //WeaponEMPLauncher
		{ "StunGun MP", 0x45CD9CF3				}, //WeaponStunGunMP
		{ "Precision Rifle", 0x6E7DDDEC			}, //WeaponPrecisionRifle
		{ "Service Carbine", 0xD1D5F52B			}, //WeaponTacticalRifle
		{ "WM 29 Pistol", 0x1BC4FDB9			}, //WeaponPistolXM3
		{ "Candy Cane", 0x6589186A				}, //WeaponCandyCane
		{ "Railgun (XM3)", 0xFEA23564			}, //WeaponRailgunXM3
		{ "Acid Package", 0xF7F1E25E			}  //WeaponAcidPackage
	};
}