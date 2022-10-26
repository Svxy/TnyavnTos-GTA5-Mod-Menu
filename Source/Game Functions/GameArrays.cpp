#include "../Header/Cheat Functions/FiberMain.h"

// https://wiki.rage.mp/index.php?title=Weapons
const std::vector<WeaponHashesStruct> Cheat::GameArrays::WeaponsHashList = {
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
	{ "Service Carbine", 0xD1D5F52B			}  //WeaponTacticalRifle
};

const std::vector<std::string> Cheat::GameArrays::PedModels = {
	"A_C_Boar",
	"A_C_Cat_01",
	"A_C_Chickenhawk",
	"A_C_Chimp",
	"A_C_Chop",
	"A_C_Chop_02",
	"A_C_Cormorant",
	"A_C_Cow",
	"A_C_Coyote",
	"A_C_Crow",
	"A_C_Deer",
	"A_C_Dolphin",
	"A_C_Fish",
	"A_C_Hen",
	"A_C_HumpBack",
	"A_C_Husky",
	"A_C_KillerWhale",
	"A_C_MtLion",
	"A_C_Panther",
	"A_C_Pig",
	"A_C_Pigeon",
	"A_C_Poodle",
	"A_C_Pug",
	"A_C_Rabbit_01",
	"A_C_Rat",
	"A_C_Retriever",
	"A_C_Rhesus",
	"A_C_Rottweiler",
	"A_C_Seagull",
	"A_C_SharkHammer",
	"A_C_SharkTiger",
	"A_C_shepherd",
	"A_C_Stingray",
	"A_C_Westy",
	"A_F_M_Beach_01",
	"A_F_M_BevHills_01",
	"A_F_M_BevHills_02",
	"A_F_M_BodyBuild_01",
	"A_F_M_Business_02",
	"A_F_M_Downtown_01",
	"A_F_M_EastSA_01",
	"A_F_M_EastSA_02",
	"A_F_M_FatBla_01",
	"A_F_M_FatCult_01",
	"A_F_M_FatWhite_01",
	"A_F_M_KTown_01",
	"A_F_M_KTown_02",
	"A_F_M_ProlHost_01",
	"A_F_M_Salton_01",
	"A_F_M_SkidRow_01",
	"A_F_M_SouCent_01",
	"A_F_M_SouCent_02",
	"A_F_M_SouCentMC_01",
	"A_F_M_Tourist_01",
	"A_F_M_Tramp_01",
	"A_F_M_TrampBeac_01",
	"A_F_O_GenStreet_01",
	"A_F_O_Indian_01",
	"A_F_O_KTown_01",
	"A_F_O_Salton_01",
	"A_F_O_SouCent_01",
	"A_F_O_SouCent_02",
	"A_F_Y_Beach_01",
	"A_F_Y_Beach_02",
	"A_F_Y_BevHills_01",
	"A_F_Y_BevHills_02",
	"A_F_Y_BevHills_03",
	"A_F_Y_BevHills_04",
	"A_F_Y_Bevhills_05",
	"A_F_Y_Business_01",
	"A_F_Y_Business_02",
	"A_F_Y_Business_03",
	"A_F_Y_Business_04",
	"A_F_Y_CarClub_01",
	"A_F_Y_ClubCust_01",
	"A_F_Y_ClubCust_02",
	"A_F_Y_ClubCust_03",
	"A_F_Y_ClubCust_04",
	"A_F_Y_EastSA_01",
	"A_F_Y_EastSA_02",
	"A_F_Y_EastSA_03",
	"A_F_Y_Epsilon_01",
	"A_F_Y_FemaleAgent",
	"A_F_Y_Fitness_01",
	"A_F_Y_Fitness_02",
	"A_F_Y_GenCasPat_01",
	"A_F_Y_GenHot_01",
	"A_F_Y_Golfer_01",
	"A_F_Y_Hiker_01",
	"A_F_Y_Hippie_01",
	"A_F_Y_Hipster_01",
	"A_F_Y_Hipster_02",
	"A_F_Y_Hipster_03",
	"A_F_Y_Hipster_04",
	"A_F_Y_Indian_01",
	"A_F_Y_Juggalo_01",
	"A_F_Y_Runner_01",
	"A_F_Y_RurMeth_01",
	"A_F_Y_SCDressy_01",
	"A_F_Y_Skater_01",
	"A_F_Y_SmartCasPat_01",
	"A_F_Y_SouCent_01",
	"A_F_Y_SouCent_02",
	"A_F_Y_SouCent_03",
	"A_F_Y_StudioParty_01",
	"A_F_Y_StudioParty_02",
	"A_F_Y_Tennis_01",
	"A_F_Y_Topless_01",
	"A_F_Y_Tourist_01",
	"A_F_Y_Tourist_02",
	"A_F_Y_Vinewood_01",
	"A_F_Y_Vinewood_02",
	"A_F_Y_Vinewood_03",
	"A_F_Y_Vinewood_04",
	"A_F_Y_Yoga_01",
	"A_M_M_ACult_01",
	"A_M_M_AfriAmer_01",
	"A_M_M_Beach_01",
	"A_M_M_Beach_02",
	"A_M_M_BevHills_01",
	"A_M_M_BevHills_02",
	"A_M_M_Business_01",
	"A_M_M_EastSA_01",
	"A_M_M_EastSA_02",
	"A_M_M_Farmer_01",
	"A_M_M_FatLatin_01",
	"A_M_M_GenFat_01",
	"A_M_M_GenFat_02",
	"A_M_M_Golfer_01",
	"A_M_M_HasJew_01",
	"A_M_M_Hillbilly_01",
	"A_M_M_Hillbilly_02",
	"A_M_M_Indian_01",
	"A_M_M_KTown_01",
	"A_M_M_Malibu_01",
	"A_M_M_MexCntry_01",
	"A_M_M_MexLabor_01",
	"A_M_M_MLCrisis_01",
	"A_M_M_OG_Boss_01",
	"A_M_M_Paparazzi_01",
	"A_M_M_Polynesian_01",
	"A_M_M_ProlHost_01",
	"A_M_M_RurMeth_01",
	"A_M_M_Salton_01",
	"A_M_M_Salton_02",
	"A_M_M_Salton_03",
	"A_M_M_Salton_04",
	"A_M_M_Skater_01",
	"A_M_M_Skidrow_01",
	"A_M_M_SoCenLat_01",
	"A_M_M_SouCent_01",
	"A_M_M_SouCent_02",
	"A_M_M_SouCent_03",
	"A_M_M_SouCent_04",
	"A_M_M_StLat_02",
	"A_M_M_StudioParty_01",
	"A_M_M_Tennis_01",
	"A_M_M_Tourist_01",
	"A_M_M_Tramp_01",
	"A_M_M_TrampBeac_01",
	"A_M_M_TranVest_01",
	"A_M_M_TranVest_02",
	"A_M_O_ACult_01",
	"A_M_O_ACult_02",
	"A_M_O_Beach_01",
	"A_M_O_Beach_02",
	"A_M_O_GenStreet_01",
	"A_M_O_KTown_01",
	"A_M_O_Salton_01",
	"A_M_O_SouCent_01",
	"A_M_O_SouCent_02",
	"A_M_O_SouCent_03",
	"A_M_O_Tramp_01",
	"A_M_Y_ACult_01",
	"A_M_Y_ACult_02",
	"A_M_Y_Beach_01",
	"A_M_Y_Beach_02",
	"A_M_Y_Beach_03",
	"A_M_Y_Beach_04",
	"A_M_Y_BeachVesp_01",
	"A_M_Y_BeachVesp_02",
	"A_M_Y_BevHills_01",
	"A_M_Y_BevHills_02",
	"A_M_Y_BreakDance_01",
	"A_M_Y_BusiCas_01",
	"A_M_Y_Business_01",
	"A_M_Y_Business_02",
	"A_M_Y_Business_03",
	"A_M_Y_CarClub_01",
	"A_M_Y_ClubCust_01",
	"A_M_Y_ClubCust_02",
	"A_M_Y_ClubCust_03",
	"A_M_Y_ClubCust_04",
	"A_M_Y_Cyclist_01",
	"A_M_Y_DHill_01",
	"A_M_Y_Downtown_01",
	"A_M_Y_EastSA_01",
	"A_M_Y_EastSA_02",
	"A_M_Y_Epsilon_01",
	"A_M_Y_Epsilon_02",
	"A_M_Y_Gay_01",
	"A_M_Y_Gay_02",
	"A_M_Y_GenCasPat_01",
	"A_M_Y_GenStreet_01",
	"A_M_Y_GenStreet_02",
	"A_M_Y_Golfer_01",
	"A_M_Y_HasJew_01",
	"A_M_Y_Hiker_01",
	"A_M_Y_Hippy_01",
	"A_M_Y_Hipster_01",
	"A_M_Y_Hipster_02",
	"A_M_Y_Hipster_03",
	"A_M_Y_Indian_01",
	"A_M_Y_Jetski_01",
	"A_M_Y_Juggalo_01",
	"A_M_Y_KTown_01",
	"A_M_Y_KTown_02",
	"A_M_Y_Latino_01",
	"A_M_Y_MethHead_01",
	"A_M_Y_MexThug_01",
	"A_M_Y_MotoX_01",
	"A_M_Y_MotoX_02",
	"A_M_Y_MusclBeac_01",
	"A_M_Y_MusclBeac_02",
	"A_M_Y_Polynesian_01",
	"A_M_Y_RoadCyc_01",
	"A_M_Y_Runner_01",
	"A_M_Y_Runner_02",
	"A_M_Y_Salton_01",
	"A_M_Y_Skater_01",
	"A_M_Y_Skater_02",
	"A_M_Y_SmartCasPat_01",
	"A_M_Y_SouCent_01",
	"A_M_Y_SouCent_02",
	"A_M_Y_SouCent_03",
	"A_M_Y_SouCent_04",
	"A_M_Y_StBla_01",
	"A_M_Y_StBla_02",
	"A_M_Y_StLat_01",
	"A_M_Y_StudioParty_01",
	"A_M_Y_StWhi_01",
	"A_M_Y_StWhi_02",
	"A_M_Y_Sunbathe_01",
	"A_M_Y_Surfer_01",
	"A_M_Y_TattooCust_01",
	"A_M_Y_VinDouche_01",
	"A_M_Y_Vinewood_01",
	"A_M_Y_Vinewood_02",
	"A_M_Y_Vinewood_03",
	"A_M_Y_Vinewood_04",
	"A_M_Y_Yoga_01",
	"CS_AmandaTownley",
	"CS_Andreas",
	"cs_ashley",
	"CS_Bankman",
	"CS_Barry",
	"CS_Beverly",
	"CS_Brad",
	"CS_BradCadaver",
	"CS_Carbuyer",
	"CS_Casey",
	"CS_ChengSr",
	"CS_ChrisFormage",
	"CS_Clay",
	"CS_Dale",
	"CS_DaveNorton",
	"cs_debra",
	"cs_denise",
	"CS_Devin",
	"CS_Dom",
	"CS_Dreyfuss",
	"CS_DrFriedlander",
	"CS_Fabien",
	"CS_FBISuit_01",
	"CS_Floyd",
	"CS_Guadalope",
	"cs_gurk",
	"CS_Hunter",
	"CS_Janet",
	"CS_JewelAss",
	"CS_JimmyBoston",
	"CS_JimmyDiSanto",
	"CS_JimmyDiSanto2",
	"CS_JoeMinuteMan",
	"CS_JohnnyKlebitz",
	"CS_Josef",
	"CS_Josh",
	"CS_Karen_Daniels",
	"CS_LamarDavis",
	"CS_LamarDavis_02",
	"CS_Lazlow",
	"CS_Lazlow_2",
	"CS_LesterCrest",
	"CS_LesterCrest_2",
	"CS_LesterCrest_3",
	"CS_LifeInvad_01",
	"CS_Magenta",
	"CS_Manuel",
	"CS_Marnie",
	"CS_MartinMadrazo",
	"CS_MaryAnn",
	"CS_Michelle",
	"CS_Milton",
	"CS_Molly",
	"CS_MovPremF_01",
	"CS_MovPremMale",
	"CS_MRK",
	"CS_MRS_Thornhill",
	"CS_MrsPhillips",
	"CS_Natalia",
	"CS_NervousRon",
	"CS_Nigel",
	"CS_Old_Man1A",
	"CS_Old_Man2",
	"CS_Omega",
	"CS_Orleans",
	"CS_Paper",
	"CS_Patricia",
	"CS_Patricia_02",
	"CS_Priest",
	"CS_ProlSec_02",
	"CS_RussianDrunk",
	"CS_SiemonYetarian",
	"CS_Solomon",
	"CS_SteveHains",
	"CS_Stretch",
	"CS_Tanisha",
	"CS_TaoCheng",
	"CS_TaoCheng2",
	"CS_TaosTranslator",
	"CS_TaosTranslator2",
	"CS_TennisCoach",
	"CS_Terry",
	"CS_Tom",
	"CS_TomEpsilon",
	"CS_TracyDiSanto",
	"CS_Wade",
	"CS_Zimbor",
	"CSB_Abigail",
	"CSB_Agatha",
	"CSB_Agent",
	"CSB_Alan",
	"CSB_Anita",
	"CSB_Anton",
	"CSB_ARY",
	"CSB_ARY_02",
	"CSB_Avery",
	"CSB_AviSchwartzman_02",
	"CSB_Avon",
	"CSB_Ballas_Leader",
	"CSB_BallasOG",
	"CSB_Billionaire",
	"CSB_Bogdan",
	"CSB_Bride",
	"CSB_Brucie2",
	"CSB_Bryony",
	"CSB_BurgerDrug",
	"CSB_Car3guy1",
	"CSB_Car3guy2",
	"CSB_Celeb_01",
	"CSB_Chef",
	"CSB_Chef2",
	"CSB_Chin_goon",
	"CSB_Cletus",
	"CSB_Cop",
	"CSB_Customer",
	"CSB_Denise_friend",
	"CSB_Dix",
	"CSB_DJBlaMadon",
	"CSB_DrugDealer",
	"CSB_EnglishDave",
	"CSB_EnglishDave_02",
	"CSB_FOS_rep",
	"CSB_G",
	"CSB_GeorginaCheng",
	"CSB_Golfer_A",
	"CSB_Golfer_B",
	"CSB_Groom",
	"CSB_Grove_str_dlr",
	"CSB_Gustavo",
	"CSB_Hao",
	"CSB_Hao_02",
	"CSB_HelmsmanPavel",
	"CSB_Huang",
	"CSB_Hugh",
	"CSB_Imani",
	"CSB_Imran",
	"CSB_IslDJ_00",
	"CSB_IslDJ_01",
	"CSB_ISLDJ_02",
	"CSB_IslDJ_03",
	"CSB_IslDJ_04",
	"CSB_JackHowitzer",
	"CSB_Janitor",
	"CSB_JIO",
	"CSB_JIO_02",
	"CSB_Johnny_Guns",
	"CSB_JuanStrickler",
	"CSB_Maude",
	"CSB_MiguelMadrazo",
	"CSB_Mimi",
	"CSB_MJO",
	"CSB_MJO_02",
	"CSB_Money",
	"CSB_Moodyman_02",
	"CSB_MP_Agent14",
	"CSB_Mrs_R",
	"CSB_Musician_00",
	"CSB_MWeather",
	"CSB_Ortega",
	"CSB_Oscar",
	"CSB_Paige",
	"CSB_Party_Promo",
	"CSB_Popov",
	"CSB_PornDudes",
	"CSB_PrologueDriver",
	"CSB_ProlSec",
	"CSB_Ramp_gang",
	"CSB_Ramp_hic",
	"CSB_Ramp_hipster",
	"CSB_Ramp_marine",
	"CSB_Ramp_mex",
	"CSB_Rashcosvki",
	"CSB_Reporter",
	"CSB_Req_Officer",
	"CSB_RoccoPelosi",
	"CSB_Screen_Writer",
	"CSB_Security_A",
	"CSB_Sessanta",
	"CSB_Sol",
	"CSB_SoundEng_00",
	"CSB_SSS",
	"CSB_Stripper_01",
	"CSB_Stripper_02",
	"CSB_TalCC",
	"CSB_TalMM",
	"CSB_Thornton",
	"CSB_TomCasino",
	"CSB_Tonya",
	"CSB_TonyPrince",
	"CSB_TrafficWarden",
	"CSB_Undercover",
	"CSB_Vagos_Leader",
	"CSB_VagSpeak",
	"CSB_Vernon",
	"CSB_Vincent",
	"CSB_Vincent_2",
	"CSB_Wendy",
	"G_F_ImportExport_01",
	"G_F_Y_ballas_01",
	"G_F_Y_Families_01",
	"G_F_Y_Lost_01",
	"G_F_Y_Vagos_01",
	"G_M_ImportExport_01",
	"G_M_M_ArmBoss_01",
	"G_M_M_ArmGoon_01",
	"G_M_M_ArmLieut_01",
	"G_M_M_CartelGuards_01",
	"G_M_M_CartelGuards_02",
	"G_M_M_CasRN_01",
	"G_M_M_ChemWork_01",
	"G_M_M_ChiBoss_01",
	"G_M_M_ChiCold_01",
	"G_M_M_ChiGoon_01",
	"G_M_M_ChiGoon_02",
	"G_M_M_Goons_01",
	"G_M_M_KorBoss_01",
	"G_M_M_MexBoss_01",
	"G_M_M_MexBoss_02",
	"G_M_M_Prisoners_01",
	"G_M_M_Slasher_01",
	"G_M_Y_ArmGoon_02",
	"G_M_Y_Azteca_01",
	"G_M_Y_BallaEast_01",
	"G_M_Y_BallaOrig_01",
	"G_M_Y_BallaSout_01",
	"G_M_Y_FamCA_01",
	"G_M_Y_FamDNF_01",
	"G_M_Y_FamFor_01",
	"G_M_Y_Korean_01",
	"G_M_Y_Korean_02",
	"G_M_Y_KorLieut_01",
	"G_M_Y_Lost_01",
	"G_M_Y_Lost_02",
	"G_M_Y_Lost_03",
	"G_M_Y_MexGang_01",
	"G_M_Y_MexGoon_01",
	"G_M_Y_MexGoon_02",
	"G_M_Y_MexGoon_03",
	"G_M_Y_PoloGoon_01",
	"G_M_Y_PoloGoon_02",
	"G_M_Y_SalvaBoss_01",
	"G_M_Y_SalvaGoon_01",
	"G_M_Y_SalvaGoon_02",
	"G_M_Y_SalvaGoon_03",
	"G_M_Y_StrPunk_01",
	"G_M_Y_StrPunk_02",
	"HC_Driver",
	"HC_Gunman",
	"HC_Hacker",
	"IG_Abigail",
	"IG_Agatha",
	"IG_Agent",
	"IG_AmandaTownley",
	"IG_Andreas",
	"IG_ARY",
	"IG_ARY_02",
	"IG_Ashley",
	"IG_Avery",
	"IG_AviSchwartzman_02",
	"IG_Avon",
	"IG_Ballas_Leader",
	"IG_BallasOG",
	"IG_Bankman",
	"IG_Barry",
	"IG_Benny",
	"IG_Benny_02",
	"IG_BestMen",
	"IG_Beverly",
	"IG_Billionaire",
	"IG_Brad",
	"IG_Bride",
	"IG_Brucie2",
	"IG_Car3guy1",
	"IG_Car3guy2",
	"IG_Casey",
	"IG_Celeb_01",
	"IG_Chef",
	"IG_Chef2",
	"IG_ChengSr",
	"IG_ChrisFormage",
	"IG_Clay",
	"IG_ClayPain",
	"IG_Cletus",
	"IG_Dale",
	"IG_DaveNorton",
	"IG_Denise",
	"IG_Devin",
	"IG_Dix",
	"IG_DJBlaMadon",
	"IG_DJBlamRupert",
	"IG_DJBlamRyanH",
	"IG_DJBlamRyanS",
	"IG_DJDixManager",
	"IG_DJGeneric_01",
	"IG_DJSolFotios",
	"IG_DJSolJakob",
	"IG_DJSolManager",
	"IG_DJSolMike",
	"IG_DJSolRobT",
	"IG_DJTalAurelia",
	"IG_DJTalIgnazio",
	"IG_Dom",
	"IG_Dreyfuss",
	"IG_DrFriedlander",
	"IG_DrugDealer",
	"IG_EnglishDave",
	"IG_EnglishDave_02",
	"IG_Entourage_A",
	"IG_Entourage_B",
	"IG_Fabien",
	"IG_FBISuit_01",
	"IG_Floyd",
	"IG_G",
	"IG_GeorginaCheng",
	"IG_Golfer_A",
	"IG_Golfer_B",
	"IG_Groom",
	"IG_Gustavo",
	"IG_Hao",
	"IG_Hao_02",
	"IG_HelmsmanPavel",
	"IG_Huang",
	"IG_Hunter",
	"IG_Imani",
	"IG_IslDJ_00",
	"IG_IslDJ_01",
	"IG_IslDJ_02",
	"IG_IslDJ_03",
	"IG_IslDJ_04",
	"IG_ISLDJ_04_D_01",
	"IG_ISLDJ_04_D_02",
	"IG_ISLDJ_04_E_01",
	"IG_Jackie",
	"IG_Janet",
	"ig_JAY_Norris",
	"IG_JewelAss",
	"IG_JimmyBoston",
	"IG_JimmyBoston_02",
	"IG_JimmyDiSanto",
	"IG_JimmyDiSanto2",
	"IG_JIO",
	"IG_JIO_02",
	"IG_JoeMinuteMan",
	"IG_Johnny_Guns",
	"ig_JohnnyKlebitz",
	"IG_Josef",
	"IG_Josh",
	"IG_JuanStrickler",
	"IG_Karen_Daniels",
	"IG_Kaylee",
	"IG_KerryMcIntosh",
	"IG_KerryMcIntosh_02",
	"IG_Lacey_Jones_02",
	"IG_LamarDavis",
	"IG_LamarDavis_02",
	"IG_Lazlow",
	"IG_Lazlow_2",
	"IG_LesterCrest",
	"IG_LesterCrest_2",
	"IG_LesterCrest_3",
	"IG_LifeInvad_01",
	"IG_LifeInvad_02",
	"IG_LilDee",
	"IG_Magenta",
	"IG_Malc",
	"IG_Manuel",
	"IG_Marnie",
	"IG_MaryAnn",
	"IG_Maude",
	"IG_Michelle",
	"IG_MiguelMadrazo",
	"IG_Milton",
	"IG_Mimi",
	"IG_MJO",
	"IG_MJO_02",
	"IG_Molly",
	"IG_Money",
	"IG_Moodyman_02",
	"IG_MP_Agent14",
	"IG_MRK",
	"IG_MRS_Thornhill",
	"IG_MrsPhillips",
	"IG_Musician_00",
	"IG_Natalia",
	"IG_NervousRon",
	"IG_Nigel",
	"IG_Old_Man1A",
	"IG_Old_Man2",
	"IG_OldRichGuy",
	"IG_Omega",
	"IG_ONeil",
	"IG_Orleans",
	"IG_Ortega",
	"IG_Paige",
	"IG_Paper",
	"IG_Party_Promo",
	"IG_Patricia",
	"IG_Patricia_02",
	"IG_Pilot",
	"IG_Popov",
	"IG_Priest",
	"IG_ProlSec_02",
	"IG_Ramp_Gang",
	"IG_Ramp_Hic",
	"IG_Ramp_Hipster",
	"IG_Ramp_Mex",
	"IG_Rashcosvki",
	"IG_Req_Officer",
	"IG_RoccoPelosi",
	"IG_RussianDrunk",
	"IG_Sacha",
	"IG_Screen_Writer",
	"IG_Security_A",
	"IG_Sessanta",
	"IG_SiemonYetarian",
	"IG_Sol",
	"IG_Solomon",
	"IG_SoundEng_00",
	"IG_SSS",
	"IG_SteveHains",
	"IG_Stretch",
	"IG_TalCC",
	"IG_Talina",
	"IG_TalMM",
	"IG_Tanisha",
	"IG_TaoCheng",
	"IG_TaoCheng2",
	"IG_TaosTranslator",
	"IG_TaosTranslator2",
	"ig_TennisCoach",
	"IG_Terry",
	"IG_Thornton",
	"IG_TomCasino",
	"IG_TomEpsilon",
	"IG_Tonya",
	"IG_TonyPrince",
	"IG_TracyDiSanto",
	"IG_TrafficWarden",
	"IG_TylerDix",
	"IG_TylerDix_02",
	"IG_Vagos_Leader",
	"IG_VagSpeak",
	"IG_Vernon",
	"IG_Vincent",
	"IG_Vincent_2",
	"IG_Vincent_3",
	"IG_Wade",
	"IG_Wendy",
	"IG_Zimbor",
	"MP_F_BennyMech_01",
	"MP_F_BoatStaff_01",
	"MP_F_CarDesign_01",
	"MP_F_CHBar_01",
	"MP_F_Cocaine_01",
	"MP_F_Counterfeit_01",
	"MP_F_DeadHooker",
	"MP_F_ExecPA_01",
	"MP_F_ExecPA_02",
	"MP_F_Forgery_01",
	"MP_F_Freemode_01",
	"MP_F_HeliStaff_01",
	"MP_F_Meth_01",
	"MP_F_Misty_01",
	"MP_F_StripperLite",
	"MP_F_Weed_01",
	"MP_G_M_Pros_01",
	"MP_HeadTargets",
	"MP_M_AvonGoon",
	"MP_M_BoatStaff_01",
	"MP_M_BogdanGoon",
	"MP_M_Claude_01",
	"MP_M_Cocaine_01",
	"MP_M_Counterfeit_01",
	"MP_M_ExArmy_01",
	"MP_M_ExecPA_01",
	"MP_M_FamDD_01",
	"MP_M_FIBSec_01",
	"MP_M_Forgery_01",
	"MP_M_Freemode_01",
	"MP_M_G_VagFun_01",
	"MP_M_Marston_01",
	"MP_M_Meth_01",
	"MP_M_Niko_01",
	"MP_M_SecuroGuard_01",
	"MP_M_ShopKeep_01",
	"MP_M_WareMech_01",
	"MP_M_WeapExp_01",
	"MP_M_WeapWork_01",
	"MP_M_Weed_01",
	"MP_S_M_Armoured_01",
	"P_Franklin_02",
	"Player_One",
	"Player_Two",
	"Player_Zero",
	"S_F_M_Autoshop_01",
	"S_F_M_Fembarber",
	"S_F_M_Maid_01",
	"S_F_M_RetailStaff_01",
	"S_F_M_Shop_HIGH",
	"S_F_M_StudioAssist_01",
	"S_F_M_SweatShop_01",
	"S_F_Y_AirHostess_01",
	"S_F_Y_Bartender_01",
	"S_F_Y_Baywatch_01",
	"S_F_Y_BeachBarStaff_01",
	"S_F_Y_Casino_01",
	"S_F_Y_ClubBar_01",
	"S_F_Y_ClubBar_02",
	"S_F_Y_Cop_01",
	"S_F_Y_Factory_01",
	"S_F_Y_Hooker_01",
	"S_F_Y_Hooker_02",
	"S_F_Y_Hooker_03",
	"S_F_Y_Migrant_01",
	"S_F_Y_MovPrem_01",
	"S_F_Y_Ranger_01",
	"S_F_Y_Scrubs_01",
	"S_F_Y_Sheriff_01",
	"S_F_Y_Shop_LOW",
	"S_F_Y_Shop_MID",
	"S_F_Y_Stripper_01",
	"S_F_Y_Stripper_02",
	"S_F_Y_StripperLite",
	"S_F_Y_SweatShop_01",
	"S_M_M_AmmuCountry",
	"S_M_M_Armoured_01",
	"S_M_M_Armoured_02",
	"S_M_M_AutoShop_01",
	"S_M_M_AutoShop_02",
	"S_M_M_Autoshop_03",
	"S_M_M_Bouncer_01",
	"S_M_M_Bouncer_02",
	"S_M_M_CCrew_01",
	"S_M_M_ChemSec_01",
	"S_M_M_CIASec_01",
	"S_M_M_CntryBar_01",
	"S_M_M_DockWork_01",
	"S_M_M_Doctor_01",
	"S_M_M_DrugProcess_01",
	"S_M_M_FIBOffice_01",
	"S_M_M_FIBOffice_02",
	"S_M_M_FIBSec_01",
	"S_M_M_FieldWorker_01",
	"S_M_M_Gaffer_01",
	"S_M_M_Gardener_01",
	"S_M_M_GenTransport",
	"S_M_M_HairDress_01",
	"S_M_M_HighSec_01",
	"S_M_M_HighSec_02",
	"S_M_M_HighSec_03",
	"S_M_M_HighSec_04",
	"S_M_M_HighSec_05",
	"S_M_M_Janitor",
	"S_M_M_LatHandy_01",
	"S_M_M_LifeInvad_01",
	"S_M_M_Linecook",
	"S_M_M_LSMetro_01",
	"S_M_M_Mariachi_01",
	"S_M_M_Marine_01",
	"S_M_M_Marine_02",
	"S_M_M_Migrant_01",
	"S_M_M_MovAlien_01",
	"S_M_M_MovPrem_01",
	"S_M_M_MovSpace_01",
	"S_M_M_Paramedic_01",
	"S_M_M_Pilot_01",
	"S_M_M_Pilot_02",
	"S_M_M_Postal_01",
	"S_M_M_Postal_02",
	"S_M_M_PrisGuard_01",
	"S_M_M_RaceOrg_01",
	"S_M_M_Scientist_01",
	"S_M_M_Security_01",
	"S_M_M_SnowCop_01",
	"S_M_M_StrPerf_01",
	"S_M_M_StrPreach_01",
	"S_M_M_StrVend_01",
	"S_M_M_StudioAssist_02",
	"S_M_M_StudioProd_01",
	"S_M_M_StudioSouEng_02",
	"S_M_M_Tattoo_01",
	"S_M_M_Trucker_01",
	"S_M_M_UPS_01",
	"S_M_M_UPS_02",
	"S_M_O_Busker_01",
	"S_M_Y_AirWorker",
	"S_M_Y_AmmuCity_01",
	"S_M_Y_ArmyMech_01",
	"S_M_Y_Autopsy_01",
	"S_M_Y_Barman_01",
	"S_M_Y_BayWatch_01",
	"S_M_Y_BlackOps_01",
	"S_M_Y_BlackOps_02",
	"S_M_Y_BlackOps_03",
	"S_M_Y_BusBoy_01",
	"S_M_Y_Casino_01",
	"S_M_Y_Chef_01",
	"S_M_Y_Clown_01",
	"S_M_Y_ClubBar_01",
	"S_M_Y_Construct_01",
	"S_M_Y_Construct_02",
	"S_M_Y_Cop_01",
	"S_M_Y_Dealer_01",
	"S_M_Y_DevinSec_01",
	"S_M_Y_DockWork_01",
	"S_M_Y_Doorman_01",
	"S_M_Y_DWService_01",
	"S_M_Y_DWService_02",
	"S_M_Y_Factory_01",
	"S_M_Y_Fireman_01",
	"S_M_Y_Garbage",
	"S_M_Y_Grip_01",
	"S_M_Y_HwayCop_01",
	"S_M_Y_Marine_01",
	"S_M_Y_Marine_02",
	"S_M_Y_Marine_03",
	"S_M_Y_Mime",
	"S_M_Y_PestCont_01",
	"S_M_Y_Pilot_01",
	"S_M_Y_PrisMuscl_01",
	"S_M_Y_Prisoner_01",
	"S_M_Y_Ranger_01",
	"S_M_Y_Robber_01",
	"S_M_Y_Sheriff_01",
	"S_M_Y_Shop_MASK",
	"S_M_Y_StrVend_01",
	"S_M_Y_Swat_01",
	"S_M_Y_USCG_01",
	"S_M_Y_Valet_01",
	"S_M_Y_Waiter_01",
	"S_M_Y_WareTech_01",
	"S_M_Y_WestSec_01",
	"S_M_Y_WestSec_02",
	"S_M_Y_WinClean_01",
	"S_M_Y_XMech_01",
	"S_M_Y_XMech_02",
	"S_M_Y_XMech_02_MP",
	"U_F_M_CasinoCash_01",
	"U_F_M_CasinoShop_01",
	"U_F_M_Corpse_01",
	"U_F_M_Debbie_01",
	"U_F_M_Drowned_01",
	"U_F_M_Miranda",
	"U_F_M_Miranda_02",
	"U_F_M_ProMourn_01",
	"U_F_O_Carol",
	"U_F_O_Eileen",
	"U_F_O_MovieStar",
	"U_F_O_ProlHost_01",
	"U_F_Y_Beth",
	"U_F_Y_BikerChic",
	"U_F_Y_COMJane",
	"U_F_Y_corpse_01",
	"U_F_Y_corpse_02",
	"U_F_Y_DanceBurl_01",
	"U_F_Y_DanceLthr_01",
	"U_F_Y_DanceRave_01",
	"U_F_Y_HotPosh_01",
	"U_F_Y_JewelAss_01",
	"U_F_Y_Lauren",
	"U_F_Y_Mistress",
	"U_F_Y_PoppyMich",
	"U_F_Y_PoppyMich_02",
	"U_F_Y_Princess",
	"U_F_Y_SpyActress",
	"U_F_Y_Taylor",
	"U_M_M_Aldinapoli",
	"U_M_M_BankMan",
	"U_M_M_BikeHire_01",
	"U_M_M_Blane",
	"U_M_M_Curtis",
	"U_M_M_DOA_01",
	"U_M_M_EdToh",
	"U_M_M_FIBArchitect",
	"U_M_M_FilmDirector",
	"U_M_M_GlenStank_01",
	"U_M_M_Griff_01",
	"U_M_M_Jesus_01",
	"U_M_M_JewelSec_01",
	"U_M_M_JewelThief",
	"U_M_M_MarkFost",
	"U_M_M_PartyTarget",
	"U_M_M_ProlSec_01",
	"U_M_M_ProMourn_01",
	"U_M_M_RivalPap",
	"U_M_M_SpyActor",
	"U_M_M_StreetArt_01",
	"U_M_M_Vince",
	"U_M_M_WillyFist",
	"U_M_O_Dean",
	"U_M_O_FilmNoir",
	"U_M_O_FinGuru_01",
	"U_M_O_TapHillBilly",
	"U_M_O_Tramp_01",
	"U_M_Y_Abner",
	"U_M_Y_AntonB",
	"U_M_Y_BabyD",
	"U_M_Y_Baygor",
	"U_M_Y_BurgerDrug_01",
	"U_M_Y_Caleb",
	"U_M_Y_Chip",
	"U_M_Y_Corpse_01",
	"U_M_Y_CroupThief_01",
	"U_M_Y_Cyclist_01",
	"U_M_Y_DanceBurl_01",
	"U_M_Y_DanceLthr_01",
	"U_M_Y_DanceRave_01",
	"U_M_Y_FIBMugger_01",
	"U_M_Y_Gabriel",
	"U_M_Y_Guido_01",
	"U_M_Y_GunVend_01",
	"U_M_Y_Hippie_01",
	"U_M_Y_ImpoRage",
	"U_M_Y_Juggernaut_01",
	"U_M_Y_Justin",
	"U_M_Y_Mani",
	"U_M_Y_MilitaryBum",
	"U_M_Y_Paparazzi",
	"U_M_Y_Party_01",
	"U_M_Y_Pogo_01",
	"U_M_Y_Prisoner_01",
	"U_M_Y_ProlDriver_01",
	"U_M_Y_RSRanger_01",
	"U_M_Y_SBike",
	"U_M_Y_SmugMech_01",
	"U_M_Y_StagGrm_01",
	"U_M_Y_Tattoo_01",
	"U_M_Y_Ushi",
	"U_M_Y_Zombie_01",
	"A_F_M_GenBiker_01",
	"A_M_M_GenBiker_01",
	"G_M_M_GenThug_01",
	"IG_Agent_02",
	"IG_Mason_Duggan",
	"IG_WarehouseBoss",
	"S_F_M_Warehouse_01",
	"S_M_M_Warehouse_01",
	"U_M_Y_Juggernaut_02"
};

const std::vector<DWORD> Cheat::GameArrays::VehicleModels = {
	0xB779A091, // adder
	0x4C80EB0E, // airbus
	0x5D0AAC8F, // airtug
	0x46699F47, // akula
	0x63ABADE7, // akuma
	0xEA313705, // alkonost
	0x2DB8D1AA, // alpha
	0xA52F6866, // alphaz1
	0x45D56ADA, // ambulance
	0x31F0B376, // annihilator
	0x11962E49, // annihilator2
	0x2189D250, // apc
	0x97E5533, // ardent
	0xB8081009, // armytanker
	0xA7FF33F5, // armytrailer
	0x9E6B14D6, // armytrailer2
	0x42ACA95F, // asbo
	0x94204D89, // asea
	0x9441D8D5, // asea2
	0x8E9254FB, // asterope
	0x258C9364, // astron
	0xED552C74, // autarch
	0x81E38F7F, // avarus
	0x81BD2ED0, // avenger
	0x18606535, // avenger2
	0x9A474B5E, // avisa
	0x806B9CC3, // bagger
	0xE82AE656, // baletrailer
	0xCFCA3668, // baller
	0x8852855, // baller2
	0x6FF0F727, // baller3
	0x25CBE2E2, // baller4
	0x1C09CF5E, // baller5
	0x27B4E6B0, // baller6
	0x1573422D, // baller7
	0xC1E908D2, // banshee
	0x25C5AF13, // banshee2
	0xCEEA3F4B, // barracks
	0x4008EABB, // barracks2
	0x2592B5CF, // barracks3
	0xF34DFB25, // barrage
	0xF9300CC5, // bati
	0xCADD5D2D, // bati2
	0x7A61B330, // benson
	0x6CBD1D6D, // besra
	0x4BFCF28B, // bestiagts
	0x5283265, // bf400
	0x432AA566, // bfinjection
	0x32B91AE8, // biff
	0xEB298297, // bifta
	0xFEFD644F, // bison
	0x7B8297C5, // bison2
	0x67B3F020, // bison3
	0x32B29A4B, // bjxl
	0xB820ED5E, // blade
	0x8125BCF9, // blazer
	0xFD231729, // blazer2
	0xB44F0582, // blazer3
	0xE5BA6858, // blazer4
	0xA1355F67, // blazer5
	0xF7004C86, // blimp
	0xDB6B4924, // blimp2
	0xEDA4ED97, // blimp3
	0xEB70965F, // blista
	0x3DEE5EDA, // blista2
	0xDCBC1C3B, // blista3
	0x43779C54, // bmx
	0x1F3D44B5, // boattrailer
	0x3FC5D440, // bobcatxl
	0xAA699BB6, // bodhi2
	0xFE0A508C, // bombushka
	0x898ECCEA, // boxville
	0xF21B33BE, // boxville2
	0x7405E08, // boxville3
	0x1A79847A, // boxville4
	0x28AD20E1, // boxville5
	0xA7CE1BC5, // brawler
	0xEDC6F847, // brickade
	0x5C55CB39, // brioso
	0x55365079, // brioso2
	0xE827DE, // brioso3
	0x27D79225, // bruiser
	0x9B065C9E, // bruiser2
	0x8644331A, // bruiser3
	0x7F81A829, // brutus
	0x8F49AE28, // brutus2
	0x798682A2, // brutus3
	0x6FF6914, // btype
	0xCE6B35A4, // btype2
	0xDC19D101, // btype3
	0xD756460C, // buccaneer
	0xC397F748, // buccaneer2
	0xEDD516C6, // buffalo
	0x2BEC3CBE, // buffalo2
	0xE2C013E, // buffalo3
	0xDB0C9B04, // buffalo4
	0x7074F39D, // bulldozer
	0x9AE6DDA1, // bullet
	0xAFBB2CA4, // burrito
	0xC9E8FF76, // burrito2
	0x98171BD3, // burrito3
	0x353B561D, // burrito4
	0x437CF2A0, // burrito5
	0xD577C962, // bus
	0x2F03547B, // buzzard
	0x2C75F0DD, // buzzard2
	0xC6C3242D, // cablecar
	0x44623884, // caddy
	0xDFF0594C, // caddy2
	0xD227BDBB, // caddy3
	0xB8D657AD, // calico
	0x6FD95F68, // camper
	0x4ABEBF23, // caracara
	0xAF966F3C, // caracara2
	0x7B8AB45F, // carbonizzare
	0xABB0C0, // carbonrs
	0xFCFCB68B, // cargobob
	0x60A7EA10, // cargobob2
	0x53174EEF, // cargobob3
	0x78BC1A3C, // cargobob4
	0x15F27762, // cargoplane
	0x3822BDFE, // casco
	0x779F23AA, // cavalcade
	0xD0EB2BE5, // cavalcade2
	0xD039510B, // cerberus
	0x287FA449, // cerberus2
	0x71D3B6F0, // cerberus3
	0xC972A155, // champion
	0xC514AAE0, // cheburek
	0xB1D95DA0, // cheetah
	0xD4E5F4D, // cheetah2
	0xD6BC7523, // chernobog
	0x675ED7, // chimera
	0x14D69010, // chino
	0xAED64A63, // chino2
	0xA4F52C13, // cinquemila
	0x17420102, // cliffhanger
	0xA29F78B0, // clique
	0x82E47E85, // club
	0x84718D34, // coach
	0x360A438E, // cog55
	0x29FCD3E4, // cog552
	0x13B57D8A, // cogcabrio
	0x86FE0B60, // cognoscenti
	0xDBF2D57A, // cognoscenti2
	0xC1AE4D16, // comet2
	0x877358AD, // comet3
	0x5D1903F9, // comet4
	0x276D98A3, // comet5
	0x991EFC04, // comet6
	0x440851D8, // comet7
	0xE384DD25, // conada
	0x28B67ACA, // contender
	0x67BC037, // coquette
	0x3C4E2113, // coquette2
	0x2EC385FE, // coquette3
	0x98F65A5E, // coquette4
	0xD3046147, // corsita
	0x1ABA13B5, // cruiser
	0x132D5A1A, // crusader
	0xD9927FE3, // cuban800
	0xC3FBA120, // cutter
	0x52FF9437, // cyclone
	0x68A5D1EF, // cypher
	0x77934CEE, // daemon
	0xAC4E93C9, // daemon2
	0xFE5F0722, // deathbike
	0x93F09558, // deathbike2
	0xAE12C99C, // deathbike3
	0x30FF0190, // defiler
	0x5B531351, // deity
	0x586765FB, // deluxo
	0x5EE005DA, // deveste
	0x4C3FFF49, // deviant
	0xF1B44F44, // diablous
	0x6ABDF65E, // diablous2
	0xBC993509, // dilettante
	0x64430650, // dilettante2
	0x3D961290, // dinghy
	0x107F392C, // dinghy2
	0x1E5E54EA, // dinghy3
	0x33B47F96, // dinghy4
	0xC58DA34A, // dinghy5
	0x698521E3, // dloader
	0x806EFBEE, // docktrailer
	0xCB44B1CA, // docktug
	0xCA495705, // dodo
	0x4CE68AC, // dominator
	0xC96B73D9, // dominator2
	0xC52C6B93, // dominator3
	0xD6FB0F30, // dominator4
	0xAE0A3D4F, // dominator5
	0xB2E046FB, // dominator6
	0x196F9418, // dominator7
	0x2BE8B90A, // dominator8
	0x9C669788, // double
	0x28EAB80F, // drafter
	0xD235A4A6, // draugur
	0x462FE277, // dubsta
	0xE882E5F6, // dubsta2
	0xB6410173, // dubsta3
	0x2B26F456, // dukes
	0xEC8F7094, // dukes2
	0x7F3415E3, // dukes3
	0x810369E2, // dump
	0x9CF21E0F, // dune
	0x1FD824AF, // dune2
	0x711D4738, // dune3
	0xCEB28249, // dune4
	0xED62BFA9, // dune5
	0x39D6779E, // duster
	0x127E90D5, // dynasty
	0xBBA2261, // elegy
	0xDE3D9D22, // elegy2
	0xB472D2B5, // ellie
	0x4EE74355, // emerus
	0xD7278283, // emperor
	0x8FC3AADC, // emperor2
	0xB5FCF74E, // emperor3
	0x6882FA73, // enduro
	0x8198AEDC, // entity2
	0xB2FE5CF9, // entityxf
	0x794CB30C, // esskey
	0x7980BDD5, // euros
	0x97553C28, // everon
	0xFFB15B5E, // exemplar
	0xDCBCBE48, // f620
	0x81A9CDDF, // faction
	0x95466BDB, // faction2
	0x866BCE26, // faction3
	0x6068AD86, // fagaloa
	0x9229E4EB, // faggio
	0x350D1AB, // faggio2
	0xB328B188, // faggio3
	0x432EA949, // fbi
	0x9DC66994, // fbi2
	0x25676EAF, // fcr
	0xD2D5E00E, // fcr2
	0xE8A8BDA8, // felon
	0xFAAD85EE, // felon2
	0x8911B9F5, // feltzer2
	0xA29D6D10, // feltzer3
	0x73920F8E, // firetruk
	0xCE23D3BF, // fixter
	0xB4F32118, // flashgt
	0x50B0215A, // flatbed
	0x5502626C, // fmj
	0x58E49664, // forklift
	0x1446590A, // formula
	0x8B213907, // formula2
	0xBC32A33B, // fq2
	0xFCC2F483, // freecrawler
	0x3D6AAA9B, // freight
	0xAFD22A6, // freightcar
	0xBDEC3D99, // freightcar2
	0x36DCFF98, // freightcont1
	0xE512E79, // freightcont2
	0x264D9262, // freightgrain
	0xD1ABB666, // freighttrailer
	0x2C634FBD, // frogger
	0x742E9AC0, // frogger2
	0x71CB2FFB, // fugitive
	0x3944D5A0, // furia
	0xBF1691E0, // furoregt
	0x1DC0BA53, // fusilade
	0x7836CE2F, // futo
	0xA6297CC8, // futo2
	0x2C2C2324, // gargoyle
	0x94B395C5, // gauntlet
	0x14D22159, // gauntlet2
	0x2B0C4DCD, // gauntlet3
	0x734C5E50, // gauntlet4
	0x817AFAAD, // gauntlet5
	0x71CBEA98, // gb200
	0x97FA4F36, // gburrito
	0x11AA0E14, // gburrito2
	0x47A6BC1, // glendale
	0xC98BBAD6, // glendale2
	0x4992196C, // gp1
	0x3CC7F596, // graintrailer
	0x9628879C, // granger
	0xF06C29C7, // granger2
	0x26ED430, // greenwood
	0xA3FC0F4D, // gresley
	0x4DC079D7, // growler
	0x8408F33A, // gt500
	0x825A9F4C, // guardian
	0x34B7390F, // habanero
	0x4B6C568A, // hakuchou
	0xF0C2A91F, // hakuchou2
	0xFE141DA6, // halftrack
	0x1A7FCEFA, // handler
	0x5A82F9AE, // hauler
	0x171C92C4, // hauler2
	0x89BA59F5, // havok
	0xEA6A047F, // hellion
	0xE83C17, // hermes
	0x11F76C14, // hexer
	0x239E390, // hotknife
	0x42836BE5, // hotring
	0xC3F25753, // howard
	0xFD707EDE, // hunter
	0x1D06D681, // huntley
	0x23CA25F2, // hustler
	0x39D6E83F, // hydra
	0xA9EC907B, // ignus
	0xBC7C0A00, // imorgon
	0x83070B62, // impaler
	0x3C26BD0C, // impaler2
	0x8D45DF49, // impaler3
	0x9804F4C7, // impaler4
	0x1A861243, // imperator
	0x619C1B82, // imperator2
	0xD2F77E37, // imperator3
	0x18F25AC7, // infernus
	0xAC33179C, // infernus2
	0xB3206692, // ingot
	0xF683EACA, // innovation
	0x9114EADA, // insurgent
	0x7B7E56F0, // insurgent2
	0x8D4B7A8A, // insurgent3
	0x34DD8AA1, // intruder
	0xB9CB3B69, // issi2
	0x378236E1, // issi3
	0x256E92BA, // issi4
	0x5BA0FF1E, // issi5
	0x49E25BA1, // issi6
	0x6E8DA4F7, // issi7
	0x85E8E76B, // italigtb
	0xE33A477B, // italigtb2
	0xEC3E3404, // italigto
	0xBB78956A, // italirsx
	0x27816B7E, // iwagen
	0xDAC67112, // jackal
	0x3EAB5555, // jb700
	0x177DA45C, // jb7002
	0xB2A716A3, // jester
	0xBE0E6126, // jester2
	0xF330CB6A, // jester3
	0xA1B3A871, // jester4
	0x3F119114, // jet
	0x33581161, // jetmax
	0xF8D48E7A, // journey
	0x1B8165D3, // jubilee
	0xF38C4245, // jugular
	0x5852838, // kalahari
	0xF8C2E0E7, // kamacho
	0x18619B7E, // kanjo
	0xFC2E479A, // kanjosj
	0x206D1B68, // khamelion
	0xAA6F980A, // khanjali
	0xCE44C4B9, // komoda
	0x4FAF0D70, // kosatka
	0xD86A0247, // krieger
	0xAE2BFE94, // kuruma
	0x187D938D, // kuruma2
	0x4BA4E8DC, // landstalker
	0xCE0B9F22, // landstalker2
	0xB39B0AE6, // lazer
	0xB6846A55, // le7b
	0x26321E67, // lectro
	0x1BF8D381, // lguard
	0xF92AEC4D, // limo2
	0xFF5968CD, // lm87
	0xC7E55211, // locust
	0x6EF89CCC, // longfin
	0x7B47A6A7, // lurcher
	0x250B0C5E, // luxor
	0xB79F589E, // luxor2
	0x1CBDC10B, // lynx
	0x9CFFFC56, // mamba
	0x97E55D11, // mammatus
	0x81634188, // manana
	0x665F785D, // manana2
	0xA5325278, // manchez
	0x40C332A3, // manchez2
	0xC1CE1183, // marquis
	0x49863E9C, // marshall
	0xF77ADE32, // massacro
	0xDA5819A3, // massacro2
	0x9D0450CA, // maverick
	0x79DD18AE, // menacer
	0x36848602, // mesa
	0xD36A4B44, // mesa2
	0x84F42E51, // mesa3
	0x33C9E158, // metrotrain
	0x3E5BD8D9, // michelli
	0x96E24857, // microlight
	0x9D80F93, // miljet
	0xB53C6C52, // minitank
	0xED7EADA4, // minivan
	0xBCDE91F0, // minivan2
	0xD138A6BB, // mixer
	0x1C534995, // mixer2
	0xD35698EF, // mogul
	0x5D56F01B, // molotok
	0xE62B361B, // monroe
	0xCD93A7DB, // monster
	0x669EB40A, // monster3
	0x32174AFC, // monster4
	0xD556917C, // monster5
	0x1F52A43F, // moonbeam
	0x710A2B9B, // moonbeam2
	0x6A4BD8F6, // mower
	0x35ED670B, // mule
	0xC1632BEB, // mule2
	0x85A5B471, // mule3
	0x73F4110E, // mule4
	0x501AC93C, // mule5
	0xCB642637, // nebula
	0xDA288376, // nemesis
	0x9F6ED5A2, // neo
	0x91CA96EE, // neon
	0x3DA47243, // nero
	0x4131F378, // nero2
	0xA0438767, // nightblade
	0x8C2BD0DC, // nightshade
	0x19DD9ED1, // nightshark
	0xB2CF7250, // nimbus
	0x3D8FA25C, // ninef
	0xA8E38B01, // ninef2
	0x3DC92356, // nokota
	0x92F5024E, // novak
	0xD1AD4937, // omnis
	0xE1E2E6D7, // omnisegt
	0x58F77553, // openwheel1
	0x4669D038, // openwheel2
	0x34B82784, // oppressor
	0x7B54A9D3, // oppressor2
	0x506434F6, // oracle
	0xE18195B2, // oracle2
	0x767164D6, // osiris
	0x185E2FF3, // outlaw
	0x21EEE87D, // packer
	0xE644E480, // panto
	0x58B3979C, // paradise
	0xE550775B, // paragon
	0x546D8EEE, // paragon2
	0x33B98FE2, // pariah
	0xCFCFEB3B, // patriot
	0xE6E967F8, // patriot2
	0xD80F4A44, // patriot3
	0xEF813606, // patrolboat
	0x885F3671, // pbus
	0x149BD32A, // pbus2
	0xC9CEAF06, // pcj
	0x9734F3EA, // penetrator
	0xE9805550, // penumbra
	0xDA5EC7DA, // penumbra2
	0x6D19CCBC, // peyote
	0x9472CD24, // peyote2
	0x4201A843, // peyote3
	0x92EF6E04, // pfister811
	0x809AA4CB, // phantom
	0x9DAE1398, // phantom2
	0xA90ED5C, // phantom3
	0x831A21D5, // phoenix
	0x59E0FBF3, // picador
	0x404B6381, // pigalle
	0x79FBB0C5, // police
	0x9F05F101, // police2
	0x71FA16EA, // police3
	0x8A63C7B9, // police4
	0xFDEFAEC3, // policeb
	0xA46462F7, // policeold1
	0x95F4C618, // policeold2
	0x1B38E955, // policet
	0x1517D4D9, // polmav
	0xF8DE29A8, // pony
	0x38408341, // pony2
	0xEE6F8F79, // postlude
	0x7DE35E7D, // pounder
	0x6290F15B, // pounder2
	0xA988D3A2, // prairie
	0x2C33B46E, // pranger
	0xE2E7D4AB, // predator
	0x8FB66F9B, // premier
	0x546DA331, // previon
	0xBB6B404F, // primo
	0x86618EDA, // primo2
	0x153E1B0A, // proptrailer
	0x7E8F677F, // prototipo
	0xAD6065C0, // pyro
	0x9D96B45B, // radi
	0xA4D99B7D, // raiden
	0x174CB172, // raketrailer
	0x829A3C44, // rallytruck
	0x6210CBB0, // rancherxl
	0x7341576B, // rancherxl2
	0x8CB29A14, // rapidgt
	0x679450AF, // rapidgt2
	0x7A2EF5E4, // rapidgt3
	0xD7C56D39, // raptor
	0x6FACDF31, // ratbike
	0xD83C13CE, // ratloader
	0xDCE1D9F7, // ratloader2
	0xEEF345EC, // rcbandito
	0xDF381E5, // reaper
	0xB802DD46, // rebel
	0x8612B64B, // rebel2
	0x4F48FC4, // rebla
	0x76D7C404, // reever
	0xFF22D208, // regina
	0x5216AD5E, // remus
	0xBE819C63, // rentalbus
	0x6DBD6C0A, // retinue
	0x79178F0A, // retinue2
	0xE78CC3D9, // revolter
	0x322CF98F, // rhapsody
	0x91673D0E, // rhinehart
	0x2EA68690, // rhino
	0xA4A4E453, // riata
	0xB822A1AA, // riot
	0x9B16A3B4, // riot2
	0xCD935EF9, // ripley
	0x7F5C91F1, // rocoto
	0xC5DD6967, // rogue
	0x2560B2FC, // romero
	0x36A167E0, // rrocket
	0xE505CF99, // rt3000
	0x9A5B1DCC, // rubble
	0xCABD11E8, // ruffian
	0xF26CEFF9, // ruiner
	0x381E10BD, // ruiner2
	0x2E5AFD37, // ruiner3
	0x65BDEBFC, // ruiner4
	0x4543B74D, // rumpo
	0x961AFEF7, // rumpo2
	0x57F682AF, // rumpo3
	0x2AE524A8, // ruston
	0xECA6B6A3, // s80
	0x9B909C94, // sabregt
	0xD4EA603, // sabregt2
	0xDC434E51, // sadler
	0x2BC345D1, // sadler2
	0x2EF89E46, // sanchez
	0xA960B13E, // sanchez2
	0x58E316C7, // sanctus
	0xB9210FD0, // sandking
	0x3AF8C345, // sandking2
	0xFB133A17, // savage
	0x35DED0DD, // savestra
	0x5097F589, // sc1
	0xBBA2A2F7, // scarab
	0x5BEB3CE0, // scarab2
	0xDD71BFEB, // scarab3
	0xB52B5113, // schafter2
	0xA774B5A6, // schafter3
	0x58CF185C, // schafter4
	0xCB0E7CD9, // schafter5
	0x72934BE4, // schafter6
	0xE1C03AB0, // schlagen
	0xD37B7976, // schwarzer
	0xF4E1AA15, // scorcher
	0xD9F0503D, // scramjet
	0x9A9FD3DF, // scrap
	0xE8983F9F, // seabreeze
	0xC2974024, // seashark
	0xDB4388E4, // seashark2
	0xED762D49, // seashark3
	0xD4AE63D9, // seasparrow
	0x494752F7, // seasparrow2
	0x5F017E6B, // seasparrow3
	0x48CECED3, // seminole
	0x94114926, // seminole2
	0x50732C82, // sentinel
	0x3412AE2D, // sentinel2
	0x41D149AA, // sentinel3
	0xAF1FA439, // sentinel4
	0x4FB1A214, // serrano
	0x97398A4B, // seven70
	0xB79C1BF5, // shamal
	0x30D3F6D8, // sheava
	0x9BAA707C, // sheriff
	0x72935408, // sheriff2
	0x50A6FB9C, // shinobi
	0xE7D2A16E, // shotaro
	0x3E48BF23, // skylift
	0xC1A8A914, // slamtruck
	0x2B7F9DE3, // slamvan
	0x31ADBBFC, // slamvan2
	0x42BC5E19, // slamvan3
	0x8526E2F5, // slamvan4
	0x163F8520, // slamvan5
	0x67D52852, // slamvan6
	0x2E3967B0, // sm722
	0x2C509634, // sovereign
	0x706E2B40, // specter
	0x400F5147, // specter2
	0xDC60D2B, // speeder
	0x1A144F2A, // speeder2
	0xCFB3870C, // speedo
	0x2B6DC64A, // speedo2
	0xD17099D, // speedo4
	0xF9E67C05, // squaddie
	0x17DF5EC2, // squalo
	0x1324E960, // stafford
	0x72A4C31E, // stalion
	0xE80F67EE, // stalion2
	0xA7EDE74D, // stanier
	0x9A9EB7DE, // starling
	0x5C23AF9B, // stinger
	0x82E499FA, // stingergt
	0x6827CF72, // stockade
	0xF337AB36, // stockade3
	0x66B4FC45, // stratum
	0x67D2B389, // streiter
	0x8B13F083, // stretch
	0x64DE07A1, // strikeforce
	0x34DBA661, // stromberg
	0x11F58A5A, // stryder
	0x81794C70, // stunt
	0x2DFF622F, // submersible
	0xC07107EE, // submersible2
	0x3ADB9758, // sugoi
	0x39DA2754, // sultan
	0x3404691C, // sultan2
	0xEEA75E63, // sultan3
	0xEE6024BC, // sultanrs
	0xEF2295C9, // suntrap
	0x42F2ED16, // superd
	0x2A54C47D, // supervolito
	0x9C5E5644, // supervolito2
	0x16E478C1, // surano
	0x29B0DA97, // surfer
	0xB1D80E06, // surfer2
	0x8F0E3594, // surge
	0xEBC24DF2, // swift
	0x4019CB4C, // swift2
	0x1DD4C0FF, // swinger
	0x6322B39A, // t20
	0x744CA80D, // taco
	0xC3DDFDCE, // tailgater
	0xB5D306A4, // tailgater2
	0xBC5DC07E, // taipan
	0x39F9C898, // tampa
	0xC0240885, // tampa2
	0xB7D9F7F1, // tampa3
	0xD46F4737, // tanker
	0x74998082, // tanker2
	0x22EDDC30, // tankercar
	0xC703DB5F, // taxi
	0x83051506, // technical
	0x4662BCBB, // technical2
	0x50D4D19F, // technical3
	0x1044926F, // tempesta
	0xCAB6E261, // tenf
	0x10635A0E, // tenf2
	0x897AFC65, // terbyte
	0x3D7C6410, // tezeract
	0x3E3D1F59, // thrax
	0x6D6F8F43, // thrust
	0x58CDAF30, // thruster
	0xAF0B8D48, // tigon
	0x2E19879, // tiptruck
	0xC7824E5E, // tiptruck2
	0x761E2AD3, // titan
	0x56C8A5EF, // toreador
	0x59A9E570, // torero
	0xF62446BA, // torero2
	0x1BB290BC, // tornado
	0x5B42A5C4, // tornado2
	0x690A4153, // tornado3
	0x86CF7CDD, // tornado4
	0x94DA98EF, // tornado5
	0xA31CB573, // tornado6
	0x3FD5AA2F, // toro
	0x362CAC6D, // toro2
	0xBA5334AC, // toros
	0x73B1C3CB, // tourbus
	0xB12314E0, // towtruck
	0xE5A2D6C6, // towtruck2
	0x7BE032C6, // tr2
	0x6A59902D, // tr3
	0x7CAB34D0, // tr4
	0x61D6BA8C, // tractor
	0x843B73DE, // tractor2
	0x562A97BD, // tractor3
	0x5993F939, // trailerlarge
	0x782A236D, // trailerlogs
	0xCBB2BE0E, // trailers
	0xA1DA3C91, // trailers2
	0x8548036D, // trailers3
	0xBE66F5AA, // trailers4
	0x2A72BEAB, // trailersmall
	0x8FD54EBB, // trailersmall2
	0x72435A19, // trash
	0xB527915C, // trash2
	0xAF62F6B2, // trflat
	0x4339CD69, // tribike
	0xB67597EC, // tribike2
	0xE823FB48, // tribike3
	0x612F4B6, // trophytruck
	0xD876DBE2, // trophytruck2
	0x1149422F, // tropic
	0x56590FE9, // tropic2
	0x707E63A4, // tropos
	0x82CAC433, // tug
	0x3E2E4F8A, // tula
	0x56D42971, // tulip
	0xC575DF11, // turismo2
	0x185484E1, // turismor
	0x967620BE, // tvtrailer
	0xE99011C2, // tyrant
	0x7B406EFB, // tyrus
	0x1ED0A534, // utillitruck
	0x34E6BF6B, // utillitruck2
	0x7F2153DF, // utillitruck3
	0x142E0DC3, // vacca
	0xF79A00F7, // vader
	0x7397224C, // vagner
	0x2C1FEA99, // vagrant
	0xA09E15FD, // valkyrie
	0x5BFA5C4B, // valkyrie2
	0xFD128DFD, // vamos
	0xA42FC3A5, // vectre
	0x9C429B6A, // velum
	0x403820E8, // velum2
	0x41B77FA4, // verlierer2
	0x11CBC051, // verus
	0x4FF77E37, // vestra
	0x780FFBD2, // vetir
	0xCCE5C8FA, // veto
	0xA703E4A9, // veto2
	0xCEC6B9B7, // vigero
	0x973141FC, // vigero2
	0xB5EF4C33, // vigilante
	0xAF599F01, // vindicator
	0xE2504942, // virgo
	0xCA62927A, // virgo2
	0xFDFFB0, // virgo3
	0xE8A8BA94, // viseris
	0xC4810400, // visione
	0x1AAD0DED, // volatol
	0x920016F1, // volatus
	0x9F4B77BE, // voltic
	0x3AF76F4A, // voltic2
	0x779B4F2D, // voodoo
	0x1F3766E3, // voodoo2
	0xDBA9DBFC, // vortex
	0x56CDEE7D, // vstr
	0x51D83328, // warrener
	0x2290C50A, // warrener2
	0x69F06B57, // washington
	0x8E08EC82, // wastelander
	0x61FE4D6A, // weevil
	0xC4BB1908, // weevil2
	0x5E4327C8, // windsor
	0x8CF5CAE1, // windsor2
	0xF376F1E6, // winky
	0xDB20A373, // wolfsbane
	0x36B4A8A9, // xa21
	0x47BBCF2E, // xls
	0xE6401328, // xls2
	0x6F946279, // yosemite
	0x64F49967, // yosemite2
	0x409D787, // yosemite3
	0x3E5F6B8, // youga
	0x3D29CD2B, // youga2
	0x6B73A9BE, // youga3
	0x589A840C, // youga4
	0x3201DD49, // z190
	0x2714AA93, // zeno
	0xAC5DF515, // zentorno
	0x4C8DBA51, // zhaba
	0xBD1B39C3, // zion
	0xB8E2AE18, // zion2
	0x6F039A67, // zion3
	0xC3D7C72B, // zombiea
	0xDE05FB87, // zombieb
	0xD757D97D, // zorrusso
	0x91373058, // zr350
	0x20314B42, // zr380
	0xBE11EFC6, // zr3802
	0xA7DCC35C, // zr3803
	0x2D3BD401  // ztype
};

const std::vector<VehicleModelPicturesStruct> Cheat::GameArrays::VehicleModelPictures = {
	{"candc_heist4","alkonost"},
	{"candc_heist4","annihilator2"},
	{"candc_heist4","avisa"},
	{"sssa_dlc_heist4","brioso2"},
	{"candc_heist4","dinghy5"},
	{"lgm_dlc_heist4","italirsx"},
	{"sssa_dlc_heist4","kosatka"},
	{"dock_dlc_heist4","longfin"},
	{"candc_heist4","manchez2"},
	{"candc_heist4","patrolboat"},
	{"sssa_dlc_heist4","seasparrow2"},
	{"candc_heist4","seasparrow3"},
	{"sssa_dlc_heist4","slamtruck"},
	{"candc_heist4","squaddie"},
	{"candc_heist4","toreador"},
	{"candc_heist4","verus"},
	{"candc_heist4","vetir"},
	{"candc_heist4","veto"},
	{"candc_heist4","veto2"},
	{"candc_heist4","weevil"},
	{"candc_heist4","winky"},
	{"lgm_dlc_executive1","pfister811"},
	{"lgm_default","adder"},
	{"lgm_dlc_xmas2017","autarch_b"},
	{"lsc_jan2016","banshee2"},
	{"lgm_default","bullet"},
	{"lgm_default","cheetah"},
	{"lgm_dlc_smuggler","cyclone"},
	{"lgm_dlc_smuggler","cyclone"},
	{"lgm_dlc_arena","deveste"},
	{"lgm_dlc_stunt","sheava"},
	{"lgm_dlc_vinewood","emerus"},
	{"lgm_dlc_assault","entity2"},
	{"lgm_default","entityxf"},
	{"lgm_dlc_executive1","fmj"},
	{"lgm_dlc_casinoheist","furia"},
	{"lgm_dlc_specialraces","gp1"},
	{"sssa_default","infernus"},
	{"lsc_dlc_import_export","italigtb2"},
	{"lsc_dlc_import_export","italigtb"},
	{"lgm_dlc_vinewood","krieger"},
	{"lsc_dlc_import_export","nero2_b"},
	{"lsc_dlc_import_export","nero2_a"},
	{"lgm_dlc_luxe","Osiris"},
	{"lgm_dlc_importexport","penetrator"},
	{"lgm_dlc_stunt","le7b"},
	{"lgm_dlc_executive1","reaper"},
	{"candc_importexport","voltic2"},
	{"lgm_dlc_vinewood","s80"},
	{"lgm_dlc_xmas2017","sc1_b"},
	{"candc_battle","scramjet"},
	{"lsc_jan2016","sultan2_a"},
	{"lgm_dlc_luxe","t20"},
	{"lgm_dlc_assault","taipan"},
	{"lgm_dlc_importexport","tempesta"},
	{"lgm_dlc_assault","tezeract"},
	{"lgm_dlc_vinewood","thrax"},
	{"lgm_dlc_business","turismor"},
	{"lgm_dlc_assault","tyrant"},
	{"lgm_dlc_stunt","tyrus"},
	{"lgm_default","vacca"},
	{"lgm_dlc_gunrunning","vagner"},
	{"candc_smuggler","vigilante"},
	{"lgm_dlc_smuggler","visione"},
	{"lgm_default","voltic_tless"},
	{"lgm_dlc_executive1","prototipo"},
	{"lgm_dlc_gunrunning","xa21"},
	{"lgm_dlc_business2","zentorno"},
	{"lgm_dlc_vinewood","zorrusso"},
	{"lgm_dlc_business","alpha"},
	{"lgm_dlc_business2","banshee_tless"},
	{"sssa_dlc_mp_to_sp","blista2"},
	{"lgm_dlc_executive1","bestiagts"},
	{"sssa_dlc_hipster","buffalo"},
	{"sssa_dlc_mp_to_sp","buffalo3"},
	{"sssa_dlc_hipster","buffalo"},
	{"lgm_default","carboniz"},
	{"lsc_dlc_import_export","comet3"},
	{"sssa_default","comet2"},
	{"lgm_dlc_xmas2017","comet4_b"},
	{"lgm_dlc_xmas2017","comet5_b"},
	{"lgm_default","coquette"},
	{"lgm_dlc_vinewood","drafter"},
	{"sssa_dlc_stunt","tampa2"},
	{"lgm_default","elegy2"},
	{"lsc_dlc_import_export","elegy"},
	{"lgm_dlc_casinoheist", "formula"},
	{"lgm_dlc_casinoheist", "formula2"},
	{"lgm_dlc_assault","flashgt"},
	{"lgm_dlc_lts_creator","furore"},
	{"sssa_dlc_business2","fusilade"},
	{"sssa_dlc_battle","futo"},
	{"lgm_dlc_assault","gb200"},
	{"sssa_dlc_assault","hotring"},
	{"lgm_dlc_casinoheist","imorgon"},
	{"sssa_dlc_vinewood","issi7"},
	{"lgm_dlc_arena","italigto"},
	{"sssa_dlc_christmas_2","jester2"},
	{"lgm_dlc_assault","jester3"},
	{"lgm_dlc_business","jester"},
	{"lgm_dlc_vinewood","jugular"},
	{"lgm_dlc_casinoheist","komoda"},
	{"sssa_dlc_heist","kuruma2"},
	{"sssa_dlc_heist","kuruma"},
	{"lgm_dlc_vinewood","locust"},
	{"lgm_dlc_stunt","lynx"},
	{"sssa_dlc_christmas_2","massacro2"},
	{"lgm_dlc_business2","massacro"},
	{"lgm_dlc_vinewood","neo"},
	{"lgm_dlc_xmas2017","neon_b"},
	{"lgm_default","ninef2"},
	{"sssa_default","ninef"},
	{"sssa_dlc_stunt","omnis"},
	{"lgm_dlc_vinewood","paragon"},
	{"lgm_dlc_vinewood","paragon"},
	{"lgm_dlc_xmas2017","pariah_b"},
	{"sssa_dlc_business2","penumbra"},
	{"lgm_dlc_xmas2017","raiden_b"},
	{"lgm_default","rapidgt2"},
	{"lgm_default","rapidgt"},
	{"lgm_dlc_biker","raptor"},
	{"lgm_dlc_xmas2017","revolter_b"},
	{"lgm_dlc_specialraces","ruston"},
	{"lgm_dlc_apartments","schafter4"},
	{"lgm_dlc_apartments","schafter3"},
	{"lgm_dlc_arena","schlagen"},
	{"sssa_default","schwarze"},
	{"sssa_dlc_xmas2017","sentinel3_b"},
	{"lgm_dlc_executive1","seven70"},
	{"lsc_dlc_import_export","specter2_a"},
	{"lsc_dlc_import_export","specter2_b"},
	{"lgm_dlc_xmas2017","streiter_b"},
	{"sssa_dlc_casinoheist","sugoi"},
	{"lsc_jan2016","sultan2_a"},
	{"sssa_dlc_casinoheist","sultan2"},
	{"lgm_default","surano_convertable"},
	{"sssa_dlc_stunt","tropos"},
	{"lgm_dlc_casinoheist","vstr"},
	{"lgm_dlc_apartments","verlier"},
	{"mba_vehicles","zr3802"},
	{"mba_vehicles","zr3803"},
	{"mba_vehicles","zr3801"},
	{"candc_gunrunning","ardent"},
	{"lgm_dlc_heist","casco"},
	{"sssa_dlc_assault","cheburek"},
	{"lgm_dlc_gunrunning","cheetah2"},
	{"lgm_dlc_pilot","coquette2"},
	{"candc_xmas2017","deluxo_b"},
	{"sssa_dlc_vinewood","dynasty"},
	{"sssa_dlc_assault","fagaloa"},
	{"lgm_dlc_xmas2017","gt500_b"},
	{"lgm_dlc_specialraces","infernus2"},
	{"lgm_default","jb700"},
	{"lgm_dlc_apartments","mamba"},
	{"sssa_dlc_assault","michelli"},
	{"lgm_default","monroe"},
	{"sssa_dlc_vinewood","nebula"},
	{"sssa_dlc_hipster","pigalle"},
	{"lgm_dlc_smuggler","rapidgt3"},
	{"sssa_dlc_casinoheist","retinue2"},
	{"sssa_dlc_smuggler","retinue_b"},
	{"sssa_dlc_halloween","btype2"},
	{"lgm_dlc_valentines2","roosevelt2"},
	{"lgm_dlc_valentines","roosevelt"},
	{"lgm_dlc_xmas2017","savestra_b"},
	{"lgm_default","stingerg"},
	{"lgm_default","stinger"},
	{"lgm_dlc_luxe","feltzer3"},
	{"candc_xmas2017","stromberg_b"},
	{"lgm_dlc_battle","swinger"},
	{"lgm_dlc_gunrunning","torero"},
	{"lsc_lowrider2","tornado5_a"},
	{"sssa_dlc_biker","tornado6"},
	{"lgm_dlc_specialraces","turismo2"},
	{"lgm_dlc_xmas2017","viseris_b"},
	{"lgm_default","ztype"},
	{"lgm_dlc_xmas2017","z190_b"},
	{"sssa_dlc_vinewood","zion3"},
	{"lgm_default","cogcabri"},
	{"sssa_default","exemplar"},
	{"sssa_dlc_business2","f620"},
	{"sssa_default","felon"},
	{"sssa_default","felon2"},
	{"sssa_dlc_heist","jackal"},
	{"sssa_default","oracle"},
	{"sssa_dlc_heist","oracle1"},
	{"sssa_dlc_business2","sentinel"},
	{"sssa_dlc_business2","sentinel"},
	{"lgm_dlc_luxe","windsor"},
	{"sssa_default","zion"},
	{"sssa_default","zion2"},
	{"sssa_dlc_hipster","blade"},
	{"lsc_default","buccaneer2_b"},
	{"lsc_default","buccaneer2_a"},
	{"lsc_default","chino2_a"},
	{"lgm_dlc_luxe","chino"},
	{"lgm_dlc_arena","clique"},
	{"lgm_dlc_luxe","coquette3"},
	{"lgm_dlc_arena","deviant"},
	{"sssa_dlc_assault","dominator3"},
	{"mba_vehicles","dominato_c_1"},
	{"mba_vehicles","dominato_c_2"},
	{"mba_vehicles","dominato_c_3"},
	{"sssa_dlc_business2","dominato"},
	{"candc_default","dukes"},
	{"sssa_dlc_mp_to_sp","dukes"},
	{"sssa_dlc_assault","ellie"},
	{"lsc_lowrider2","faction3_b"},
	{"lsc_lowrider2","faction3_a"},
	{"lsc_default","faction2_a"},
	{"sssa_dlc_mp_to_sp","gauntlet2"},
	{"sssa_dlc_vinewood","gauntlet3"},
	{"sssa_dlc_vinewood","gauntlet4"},
	{"sssa_default","gauntlet"},
	{"sssa_dlc_xmas2017","hermes_b"},
	{"lgm_default","hotknife"},
	{"lgm_dlc_xmas2017","hustler_b"},
	{"mba_vehicles","impaler"},
	{"sssa_dlc_vinewood","impaler"},
	{"mba_vehicles","impaler_c_1"},
	{"mba_vehicles","impaler_c_2"},
	{"mba_vehicles","impaler_c_3"},
	{"mba_vehicles","imperator2"},
	{"mba_vehicles","imperator3"},
	{"mba_vehicles","imperator1"},
	{"sssa_dlc_halloween","lurcher"},
	{"lsc_default","moonbeam2"},
	{"lgm_dlc_apartments","niteshad"},
	{"sssa_dlc_vinewood","peyote2"},
	{"sssa_dlc_hipster","picador"},
	{"sssa_dlc_mp_to_sp","dominator2"},
	{"sssa_dlc_valentines","rloader"},
	{"sssa_dlc_christmas_2","rloader2"},
	{"candc_importexport","ruiner2"},
	{"sssa_dlc_battle","ruiner"},
	{"lsc_lowrider2","sabregt2_a"},
	{"lsc_lowrider2","slamvan3_b"},
	{"mba_vehicles","slamvan_c_1"},
	{"mba_vehicles","slamvan_c_2"},
	{"mba_vehicles","slamvan_c_3"},
	{"sssa_dlc_christmas_2","slamvan"},
	{"sssa_dlc_mp_to_sp","stalion2"},
	{"sssa_dlc_mp_to_sp","stallion"},
	{"candc_gunrunning","tampa3"},
	{"sssa_dlc_christmas_3","tampa"},
	{"sssa_dlc_arena","tulip"},
	{"sssa_dlc_arena","vamos"},
	{"sssa_default","vigero"},
	{"lsc_lowrider2","virgo2_a"},
	{"lsc_lowrider2","virgo2_b"},
	{"lgm_dlc_luxe","virgo"},
	{"lsc_default","voodoo_b"},
	{"lsc_default","voodoo_a"},
	{"sssa_dlc_xmas2017","yosemite_b"},
	{"sssa_dlc_casinoheist","yosemite2"},
	{"sssa_default","bfinject"},
	{"sssa_default","bifta"},
	{"sssa_dlc_hipster","blazer3"},
	{"candc_importexport","blazer5"},
	{"sssa_default","blazer"},
	{"sssa_dlc_biker","blazer4"},
	{"sssa_default","bodhi2"},
	{"lgm_dlc_luxe","brawler"},
	{"mba_vehicles","bruiser_c_2"},
	{"mba_vehicles","bruiser_c_3"},
	{"mba_vehicles","bruiser_c_1"},
	{"mba_vehicles","brutus2"},
	{"mba_vehicles","brutus3"},
	{"mba_vehicles","brutus1"},
	{"sssa_dlc_vinewood","caracara2"},
	{"candc_assault","caracara"},
	{"candc_default","dubsta3"},
	{"candc_gunrunning","dune3"},
	{"sssa_default","dune"},
	{"sssa_dlc_casinoheist","everon"},
	{"lgm_dlc_battle","freecrawler"},
	{"sssa_dlc_vinewood","hellion"},
	{"ua_generic","ua_unlock_11"},
	{"candc_default","insurgent"},
	{"candc_default","insurgent"},
	{"sssa_default","kalahari"},
	{"sssa_dlc_xmas2017","kamacho_b"},
	{"candc_default","marshall"},
	{"candc_battle","menacer"},
	{"candc_default","mesa3"},
	{"mba_vehicles","monster_c_1"},
	{"mba_vehicles","monster_c_2"},
	{"mba_vehicles","monster_c_3"},
	{"candc_gunrunning","nightshark"},
	{"sssa_dlc_casinoheist","outlaw"},
	{"candc_importexport","dune5"},
	{"sssa_dlc_business","rancherx"},
	{"sssa_dlc_arena","rcbandito"},
	{"sssa_dlc_hipster","rebel2"},
	{"sssa_default","rebel"},
	{"sssa_dlc_xmas2017","riata_b"},
	{"sssa_default","sandking_b"},
	{"sssa_default","sandkin_2b"},
	{"candc_importexport","technical2"},
	{"ua_generic","ua_unlock_15"},
	{"candc_default","technical"},
	{"candc_default","monster"},
	{"sssa_dlc_stunt","trophy2"},
	{"sssa_dlc_stunt","trophy"},
	{"sssa_dlc_casinoheist","vagrant"},
	{"sssa_default","akuma"},
	{"sssa_dlc_biker","avarus"},
	{"sssa_dlc_stunt","bf400"},
	{"sssa_dlc_biker","bagger"},
	{"sssa_default","bati2"},
	{"sssa_default","bati"},
	{"lgm_default","carbon"},
	{"sssa_dlc_biker","chimera"},
	{"sssa_dlc_stunt","cliffhanger"},
	{"sssa_dlc_biker","daemon2"},
	{"mba_vehicles","deathbike_c_2"},
	{"mba_vehicles","deathbike_c_3"},
	{"mba_vehicles","deathbike_c_1"},
	{"sssa_dlc_biker","defiler"},
	{"lsc_dlc_import_export","diablous2"},
	{"sssa_default","double"},
	{"sssa_dlc_heist","enduro"},
	{"sssa_dlc_biker","esskey"},
	{"lsc_dlc_import_export","fcr2_b"},
	{"lsc_dlc_import_export","fcr2_a"},
	{"sssa_dlc_biker","faggio3"},
	{"sssa_default","faggio"},
	{"sssa_dlc_biker","faggion"},
	{"sssa_dlc_stunt","gargoyle"},
	{"lgm_dlc_biker","hakuchou2"},
	{"sssa_dlc_lts_creator","hakuchou"},
	{"sssa_default","hexer"},
	{"sssa_dlc_lts_creator","innovation"},
	{"lgm_dlc_heist","lectro"},
	{"sssa_dlc_biker","manchez"},
	{"sssa_dlc_heist","nemesis"},
	{"sssa_dlc_biker","nightblade"},
	{"candc_battle","oppressor2"},
	{"candc_gunrunning","oppressor"},
	{"sssa_default","pcj"},
	{"sssa_dlc_biker","ratbike"},
	{"lgm_dlc_vinewood","rrocket"},
	{"sssa_default","ruffian"},
	{"sssa_default","sanchez2"},
	{"sssa_default","sanchez"},
	{"sssa_dlc_biker","sanctus"},
	{"lgm_dlc_biker","shotaro"},
	{"lgm_dlc_casinoheist","stryder"},
	{"lgm_dlc_business2","thrust"},
	{"sssa_default","vader"},
	{"lgm_dlc_luxe","vindicator"},
	{"sssa_dlc_biker","vortex"},
	{"sssa_dlc_biker","wolfsbane"},
	{"sssa_dlc_biker","zombieb"},
	{"sssa_dlc_biker","zombiea"},
	{"candc_gunrunning","apc"},
	{"candc_gunrunning","trsmall2"},
	{"candc_default","barracks"},
	{"candc_xmas2017","barrage_b"},
	{"candc_xmas2017","chernobog_b"},
	{"candc_default","crusader"},
	{"candc_gunrunning","halftrack"},
	{"candc_xmas2017","khanjali_b"},
	{"candc_default","rhino"},
	{"mba_vehicles","scarab2"},
	{"mba_vehicles","scarab3"},
	{"mba_vehicles","scarab1"},
	{"candc_xmas2017","thruster_b"},
	{"candc_default","pbus"},
	{"candc_xmas2017","riot2_b"},
	{"candc_default","airbus"},
	{"candc_executive1","brickade"},
	{"candc_default","bus"},
	{"candc_default","coach"},
	{"sssa_dlc_stunt","rallytruck"},
	{"sssa_dlc_battle","pbus2"},
	{"candc_default","rentbus"},
	{"candc_importexport","wastlndr"},
	{"sssa_dlc_business","asea"},
	{"sssa_dlc_business","astrope"},
	{"lgm_dlc_apartments","cognosc"},
	{"sssa_dlc_business","premier"},
	{"sssa_default","superd"},
	{"sssa_default","fugitive"},
	{"sssa_dlc_hipster","glendale"},
	{"sssa_dlc_business","intruder"},
	{"sssa_default","stretch"},
	{"sssa_dlc_hipster","primo"},
	{"sssa_dlc_hipster","regina"},
	{"sssa_dlc_battle","Romero"},
	{"lgm_dlc_apartments","schafter3"},
	{"lgm_dlc_apartments","schafter4"},
	{"sssa_dlc_heist","schafter2"},
	{"lgm_dlc_battle","stafford"},
	{"sssa_dlc_business","stanier"},
	{"sssa_dlc_business","stratum"},
	{"sssa_dlc_heist","surge"},
	{"sssa_dlc_hipster","tailgater"},
	{"sssa_dlc_business","ingot"},
	{"sssa_dlc_hipster","warrener"},
	{"sssa_dlc_business","washingt"},
	{"candc_default","dump"},
	{"sssa_dlc_heist","guardian"},
	{"sssa_dlc_casinoheist","asbo"},
	{"sssa_default","dilettan"},
	{"sssa_dlc_stunt","brioso"},
	{"sssa_dlc_assault","issi3"},
	{"mba_vehicles","issi3_c_1"},
	{"mba_vehicles","issi3_c_2"},
	{"mba_vehicles","issi3_c_3"},
	{"sssa_dlc_casinoheist","kanjo"},
	{"sssa_dlc_hipster","panto"},
	{"sssa_dlc_battle","prairie"},
	{"sssa_dlc_hipster","rhapsody"},
	{"sssa_default","issi2"},
	{"mba_vehicles","cerberus2"},
	{"mba_vehicles","cerberus3"},
	{"mba_vehicles","cerberus1"},
	{"candc_truck","cab_1"},
	{"candc_default","mule3"},
	{"candc_battle","mule4"},
	{"candc_default","mule"},
	{"candc_truck","cab_0"},
	{"candc_importexport","phantom2"},
	{"candc_battle","pounder2"},
	{"elt_dlc_smuggler","alphaz1"},
	{"candc_chopper","banner_5"},
	{"candc_chopper","banner_4"},
	{"elt_dlc_pilot","besra"},
	{"elt_dlc_battle","blimp3"},
	{"candc_smuggler","bombushka"},
	{"elt_default","cuban800"},
	{"elt_default","dodo"},
	{"elt_default","duster"},
	{"elt_dlc_smuggler","howard"},
	{"candc_default","hydra"},
	{"elt_dlc_executive1","luxor2"},
	{"elt_default","luxor"},
	{"elt_default","mammatus"},
	{"elt_dlc_smuggler","microlight"},
	{"elt_dlc_pilot","miljet"},
	{"candc_smuggler","mogu"},
	{"candc_smuggler","molotok_b"},
	{"elt_dlc_executive1","nimbus"},
	{"candc_smuggler","nokota"},
	{"candc_smuggler","lazer"},
	{"candc_smuggler","pyro"},
	{"candc_smuggler","rogue"},
	{"elt_dlc_smuggler","seabreeze"},
	{"elt_default","shama"},
	{"candc_smuggler","starling"},
	{"candc_battle","strikeforce"},
	{"elt_default","stunt"},
	{"elt_default","titan"},
	{"candc_smuggler","tula"},
	{"elt_default","velum2"},
	{"elt_default","velum"},
	{"candc_xmas2017","volatol_b"},
	{"foreclosures_bunker","transportation_2"},
	{"foreclosures_bunker","transportation_1"},
	{"candc_truck","banner_2"},
	{"sssa_default","sadler"},
	{"candc_xmas2017","akula_b"},
	{"elt_default","annih"},
	{"candc_default","buzzard"},
	{"candc_default","cargobob"},
	{"elt_default","frogger"},
	{"elt_dlc_smuggler","havok"},
	{"candc_smuggler","hunter"},
	{"elt_default","maverick"},
	{"candc_default","savage"},
	{"elt_dlc_assault","sparrow"},
	{"elt_dlc_executive1","swift2"},
	{"elt_dlc_pilot","swift"},
	{"candc_default","valkyrie"},
	{"elt_dlc_executive1","volatus"},
	{"sssa_dlc_hipster","surfer"},
	{"sssa_default","bison"},
	{"sssa_dlc_business","bobcatx"},
	{"candc_importexport","boxville5"},
	{"candc_default","boxville4"},
	{"sssa_dlc_heist","gburrito2"},
	{"candc_default","journey"},
	{"lsc_lowrider2","minivan2_b"},
	{"sssa_dlc_business","minivan"},
	{"sssa_default","paradise"},
	{"sssa_dlc_executive_1","rumpo3_b"},
	{"sssa_dlc_heist","rumpo"},
	{"sssa_dlc_biker","youga2"},
	{"sssa_dlc_hipster","youga"},
	{"dock_default","dinghy3"},
	{"dock_default","jetmax"},
	{"dock_default","marquis"},
	{"dock_default","seashark"},
	{"dock_default","squalo"},
	{"dock_default","sub2"},
	{"dock_default","suntrap"},
	{"dock_default","toro"},
	{"dock_default","tropic"},
	{"pandm_default","bmx"},
	{"pandm_default","cruiser"},
	{"pandm_default","tribike2"},
	{"pandm_default","scorcher"},
	{"pandm_default","tribike3"},
	{"pandm_default","tribike"},
	{"sssa_default","baller2"},
	{"lgm_dlc_apartments","baller4"},
	{"lgm_dlc_apartments","baller3"},
	{"sssa_dlc_battle","bjx"},
	{"sssa_dlc_heist","seminole"},
	{"sssa_dlc_business","cavcade2"},
	{"sssa_default","cavcade"},
	{"sssa_dlc_stunt","contender"},
	{"sssa_dlc_battle","habanero"},
	{"lgm_dlc_business2","huntley"},
	{"sssa_dlc_battle","fq2"},
	{"sssa_dlc_business","granger"},
	{"sssa_dlc_heist","gresley"},
	{"sssa_dlc_heist","landstalker"},
	{"sssa_dlc_battle","patriot"},
	{"candc_default","mesa"},
	{"lgm_dlc_vinewood","novak"},
	{"sssa_dlc_battle","patriot2"},
	{"sssa_dlc_business","radi"},
	{"lgm_dlc_casinoheist","rebla"},
	{"sssa_default","rocoto"},
	{"sssa_dlc_battle","serrano"},
	{"lgm_dlc_arena","toros"},
	{"lgm_dlc_executive1","xls"},
	{"lgm_dlc_tuner","zr350" },
	{"lgm_dlc_tuner","growler" },
	{"lgm_dlc_tuner","cypher" },
	{"lgm_dlc_tuner","comet6" },
	{"lgm_dlc_tuner","jester4" },
	{"lgm_dlc_tuner","tailgater2" },
	{"lgm_dlc_tuner","vectre" },
	{"lgm_dlc_tuner","euros" },
	{"sssa_dlc_tuner","calico" },
	{"sssa_dlc_tuner","dominator7" },
	{"sssa_dlc_tuner","dominator8" },
	{"sssa_dlc_tuner","futo2" },
	{"sssa_dlc_tuner","previon" },
	{"sssa_dlc_tuner","remus" },
	{"sssa_dlc_tuner","rt3000" },
	{"sssa_dlc_tuner","sultan3" },
	{"sssa_dlc_tuner","warrener2" }
};

const std::vector<TeleportLocationStruct> Cheat::GameArrays::TeleportLocationsSafehouses = {
	{ "Michael's Safehouse", -827.138f, 176.368f, 70.4999f },
	{ "Franklin's Safehouse", -18.0355f, -1456.94f, 30.4548f },
	{ "Franklin's Safehouse 2", 10.8766f, 545.654f, 175.419f },
	{ "Trevor's Safehouse", 1982.13f, 3829.44f, 32.3662f },
	{ "Trevor's Safehouse 2", -1157.05f, -1512.73f, 4.2127f },
	{ "Trevor's Safehouse 3", 91.1407f, -1280.65f, 29.1353f },
	{ "Michael's Safehouse Inside", -813.603f, 179.474f, 72.1548f },
	{ "Franklin's Safehouse Inside", -14.3803f, -1438.51f, 31.1073f },
	{ "Franklin's Safehouse 2 Inside", 7.11903f, 536.615f, 176.028f },
	{ "Trevor's Safehouse Inside", 1972.61f, 3817.04f, 33.4278f },
	{ "Trevor's Safehouse 2 Inside", -1151.77f, -1518.14f, 10.6327f },
	{ "Trevor's Safehouse 3 Inside", 96.1536f, -1290.73f, 29.2664f }
};

const std::vector<TeleportLocationStruct> Cheat::GameArrays::TeleportLocationsHighAltitude = {
	{ "Airplane Graveyard Airplane Tail ", 2395.096f, 3049.616f, 60.053f },
	{ "FIB Building Roof", 150.126f, -754.591f, 262.865f },
	{ "Galileo Observatory Roof", -438.804f, 1076.097f, 352.411f },
	{ "IAA Building Roof", 134.085f, -637.859f, 262.851f },
	{ "Maze Bank Arena Roof", -324.300f, -1968.545f, 67.002f },
	{ "Maze Bank Roof", -75.015f, -818.215f, 326.176f },
	{ "Palmer-Taylor Power Station Chimney", 2732.931f, 1577.540f, 83.671f },
	{ "Rebel Radio", 736.153f, 2583.143f, 79.634f },
	{ "Sandy Shores Building Site Crane", 1051.209f, 2280.452f, 89.727f },
	{ "Satellite Dish Antenna", 2034.988f, 2953.105f, 74.602f },
	{ "Stab City", 126.975f, 3714.419f, 46.827f },
	{ "Very High Up", -129.964f, 8130.873f, 6705.307f },
	{ "Windmill Top", 2026.677f, 1842.684f, 133.313f }
};

const std::vector<TeleportLocationStruct> Cheat::GameArrays::TeleportLocationsUnderwater = {
	{ "Dead Sea Monster", -3373.726f, 504.714f, -24.656f },
	{ "Humane Labs Tunnel", 3619.749f, 2742.740f, 28.690f },
	{ "Sunken Body", -3161.078f, 3001.998f, -37.974f },
	{ "Sunken Cargo Ship", 3199.748f, -379.018f, -22.500f },
	{ "Sunken Plane", -942.350f, 6608.752f, -20.912f },
	{ "Underwater Hatch", 4273.950f, 2975.714f, -170.746f },
	{ "Underwater UFO", 762.426f, 7380.371f, -111.377f },
	{ "Underwater WW2 Tank", 4201.633f, 3643.821f, -39.016f }
};

const std::vector<TeleportLocationStruct> Cheat::GameArrays::TeleportLocationsLandmarks = {
	{ "Airport Entrance", -1034.6f, -2733.6f, 13.8f },
	{ "Airport Field", -1336.0f, -3044.0f, 13.9f },
	{ "Altruist Cult Camp", -1170.841f, 4926.646f, 224.295f },
	{ "Calafia Train Bridge", -517.869f, 4425.284f, 89.795f },
	{ "Cargo Ship", 899.678f, -2882.191f, 19.013f },
	{ "Chumash", -3192.6f, 1100.0f, 20.2f },
	{ "Chumash Historic Family Pier", -3426.683f, 967.738f, 8.347f },
	{ "Del Perro Pier", -1850.127f, -1231.751f, 13.017f },
	{ "Devin Weston's House", -2639.872f, 1866.812f, 160.135f },
	{ "El Burro Heights", 1384.0f, -2057.1f, 52.0f },
	{ "Elysian Island", 338.2f, -2715.9f, 38.5f },
	{ "Far North San Andreas", 24.775f, 7644.102f, 19.055f },
	{ "Ferris Wheel", -1670.7f, -1125.0f, 13.0f },
	{ "Fort Zancudo", -2047.4f, 3132.1f, 32.8f },
	{ "Fort Zancudo ATC Entrance", -2344.373f, 3267.498f, 32.811f },
	{ "Fort Zancudo ATC Top Floor", -2358.132f, 3249.754f, 101.451f },
	{ "God's Thumb", -1006.402f, 6272.383f, 1.503f },
	{ "Hippy Camp", 2476.712f, 3789.645f, 41.226f },
	{ "Jetsam", 760.4f, -2943.2f, 5.8f },
	{ "Jolene Cranley-Evans Ghost", 3059.620f, 5564.246f, 197.091f },
	{ "Kortz Center", -2243.810f, 264.048f, 174.615f },
	{ "Main LS Customs", -365.425f, -131.809f, 37.873f },
	{ "Marlowe Vineyards", -1868.971f, 2095.674f, 139.115f },
	{ "McKenzie Airfield", 2121.7f, 4796.3f, 41.1f },
	{ "Merryweather Dock", 486.417f, -3339.692f, 6.070f },
	{ "Mineshaft", -595.342f, 2086.008f, 131.412f },
	{ "Mt. Chiliad", 425.4f, 5614.3f, 766.5f },
	{ "Mt. Chiliad Summit", 450.718f, 5566.614f, 806.183f },
	{ "NOOSE Headquarters", 2535.243f, -383.799f, 92.993f },
	{ "Pacific Standard Bank", 235.046f, 216.434f, 106.287f },
	{ "Paleto Bay Pier", -275.522f, 6635.835f, 7.425f },
	{ "Playboy Mansion", -1475.234f, 167.088f, 55.841f },
	{ "Police Station", 436.491f, -982.172f, 30.699f },
	{ "Quarry", 2954.196f, 2783.410f, 41.004f },
	{ "Sandy Shores Airfield", 1747.0f, 3273.7f, 41.1f },
	{ "Satellite Dishes", 2062.123f, 2942.055f, 47.431f },
	{ "Sisyphus Theater Stage", 686.245f, 577.950f, 130.461f },
	{ "Trevor's Meth Lab", 1391.773f, 3608.716f, 38.942f },
	{ "Weed Farm", 2208.777f, 5578.235f, 53.735f },
	{ "Wind Farm", 2354.0f, 1830.3f, 101.1f }
};

const std::vector<WeatherTypesStruct> Cheat::GameArrays::WeatherTypes = {
	{ "Extra Sunny",	"EXTRASUNNY" },
	{ "Sunny",			"CLEAR" },
	{ "Cloudy",			"CLOUDS" },
	{ "Smoggy",			"SMOG" },
	{ "Foggy",			"FOGGY" },
	{ "Overcast",		"OVERCAST" },
	{ "Stormy",			"THUNDER" },
	{ "Snow",			"SNOW" },
	{ "Snowlight",		"SNOWLIGHT" },
	{ "Blizzard",		"BLIZZARD" }
};

// This only contains the most expensive/'best' weapon components
const std::vector<MaxUpgradeWeaponComponentsStruct> Cheat::GameArrays::MaxUpgradeWeaponComponents = {
	{ 0xD8DF3C3C, "COMPONENT_KNUCKLE_VARMOD_VAGOS" },
	{ 0xDFE37640, "COMPONENT_SWITCHBLADE_VARMOD_VAR1" },
	{ 0x1B06D571, "COMPONENT_PISTOL_CLIP_02" },
	{ 0x1B06D571, "COMPONENT_AT_PI_FLSH" },
	{ 0x1B06D571, "COMPONENT_AT_PI_SUPP_02" },
	{ 0x1B06D571, "COMPONENT_PISTOL_VARMOD_LUXE" },
	{ 0x5EF9FEC4, "COMPONENT_COMBATPISTOL_CLIP_02" },
	{ 0x5EF9FEC4, "COMPONENT_AT_PI_FLSH" },
	{ 0x5EF9FEC4, "COMPONENT_AT_PI_SUPP" },
	{ 0x5EF9FEC4, "COMPONENT_COMBATPISTOL_VARMOD_LOWRIDER" },
	{ 0x22D8FE39, "COMPONENT_APPISTOL_CLIP_02" },
	{ 0x22D8FE39, "COMPONENT_AT_PI_FLSH" },
	{ 0x22D8FE39, "COMPONENT_APPISTOL_VARMOD_LUXE" },
	{ 0x99AEEB3B, "COMPONENT_PISTOL50_CLIP_02" },
	{ 0x99AEEB3B, "COMPONENT_AT_PI_FLSH" },
	{ 0x99AEEB3B, "COMPONENT_AT_AR_SUPP_02" },
	{ 0x99AEEB3B, "COMPONENT_PISTOL50_VARMOD_LUXE" },
	{ 0xC1B3C3D1, "COMPONENT_REVOLVER_VARMOD_BOSS" },
	{ 0xBFD21232, "COMPONENT_SNSPISTOL_CLIP_02" },
	{ 0xBFD21232, "COMPONENT_SNSPISTOL_VARMOD_LOWRIDER" },
	{ 0xD205520E, "COMPONENT_HEAVYPISTOL_CLIP_02" },
	{ 0xD205520E, "COMPONENT_AT_PI_FLSH" },
	{ 0xD205520E, "COMPONENT_AT_PI_SUPP" },
	{ 0xD205520E, "COMPONENT_HEAVYPISTOL_VARMOD_LUXE" },
	{ 0xCB96392F, "COMPONENT_REVOLVER_MK2_CLIP_FMJ" },
	{ 0xCB96392F, "COMPONENT_AT_SCOPE_MACRO_MK2" },
	{ 0xCB96392F, "COMPONENT_AT_PI_FLSH" },
	{ 0xCB96392F, "COMPONENT_AT_PI_COMP_03" },
	{ 0xCB96392F, "COMPONENT_REVOLVER_MK2_CAMO_IND_01" },
	{ 0x88374054, "COMPONENT_SNSPISTOL_MK2_CLIP_FMJ" },
	{ 0x88374054, "COMPONENT_AT_PI_FLSH_03" },
	{ 0x88374054, "COMPONENT_AT_PI_RAIL_02" },
	{ 0x88374054, "COMPONENT_AT_PI_SUPP_02" },
	{ 0x88374054, "COMPONENT_AT_PI_COMP_02" },
	{ 0x88374054, "COMPONENT_SNSPISTOL_MK2_CAMO_IND_01_SLIDE" },
	{ 0xBFE256D4, "COMPONENT_PISTOL_MK2_CLIP_02" },
	{ 0xBFE256D4, "COMPONENT_PISTOL_MK2_CLIP_FMJ" },
	{ 0xBFE256D4, "COMPONENT_AT_PI_RAIL" },
	{ 0xBFE256D4, "COMPONENT_AT_PI_FLSH_02" },
	{ 0xBFE256D4, "COMPONENT_AT_PI_SUPP_02" },
	{ 0xBFE256D4, "COMPONENT_AT_PI_COMP" },
	{ 0xBFE256D4, "COMPONENT_PISTOL_MK2_CAMO_IND_01_SLIDE" },
	{ 0x83839C4, "COMPONENT_VINTAGEPISTOL_CLIP_02" },
	{ 0x83839C4, "COMPONENT_AT_PI_SUPP" },
	{ 0xAF3696A1, "COMPONENT_RAYPISTOL_VARMOD_XMAS18" },
	{ 0x2B5EF5EC, "COMPONENT_CERAMICPISTOL_CLIP_02" },
	{ 0x2B5EF5EC, "COMPONENT_CERAMICPISTOL_SUPP" },
	{ 0x13532244, "COMPONENT_MICROSMG_CLIP_02" },
	{ 0x13532244, "COMPONENT_AT_PI_FLSH" },
	{ 0x13532244, "COMPONENT_AT_SCOPE_MACRO" },
	{ 0x13532244, "COMPONENT_AT_AR_SUPP_02" },
	{ 0x13532244, "COMPONENT_MICROSMG_VARMOD_LUXE" },
	{ 0x2BE6766B, "COMPONENT_SMG_CLIP_03" },
	{ 0x2BE6766B, "COMPONENT_AT_AR_FLSH" },
	{ 0x2BE6766B, "COMPONENT_AT_SCOPE_MACRO_02" },
	{ 0x2BE6766B, "COMPONENT_AT_PI_SUPP" },
	{ 0x2BE6766B, "COMPONENT_SMG_VARMOD_LUXE" },
	{ 0xEFE7E2DF, "COMPONENT_ASSAULTSMG_CLIP_02" },
	{ 0xEFE7E2DF, "COMPONENT_AT_AR_FLSH" },
	{ 0xEFE7E2DF, "COMPONENT_AT_SCOPE_MACRO" },
	{ 0xEFE7E2DF, "COMPONENT_AT_AR_SUPP_02" },
	{ 0xEFE7E2DF, "COMPONENT_ASSAULTSMG_VARMOD_LOWRIDER" },
	{ 0xBD248B55, "COMPONENT_MINISMG_CLIP_02" },
	{ 0x78A97CD0, "COMPONENT_SMG_MK2_CLIP_02" },
	{ 0x78A97CD0, "COMPONENT_SMG_MK2_CLIP_FMJ" },
	{ 0x78A97CD0, "COMPONENT_AT_AR_FLSH" },
	{ 0x78A97CD0, "COMPONENT_AT_SIGHTS_SMG" },
	{ 0x78A97CD0, "COMPONENT_AT_SCOPE_SMALL_SMG_MK2" },
	{ 0x78A97CD0, "COMPONENT_AT_PI_SUPP" },
	{ 0x78A97CD0, "COMPONENT_AT_MUZZLE_07" },
	{ 0x78A97CD0, "COMPONENT_AT_SB_BARREL_02" },
	{ 0x78A97CD0, "COMPONENT_SMG_MK2_CAMO_IND_01" },
	{ 0xDB1AA450, "COMPONENT_MACHINEPISTOL_CLIP_02" },
	{ 0xDB1AA450, "COMPONENT_MACHINEPISTOL_CLIP_03" },
	{ 0xDB1AA450, "COMPONENT_AT_PI_SUPP" },
	{ 0x0A3D4D34, "COMPONENT_COMBATPDW_CLIP_03" },
	{ 0x0A3D4D34, "COMPONENT_AT_AR_FLSH" },
	{ 0x0A3D4D34, "COMPONENT_AT_AR_AFGRIP" },
	{ 0x0A3D4D34, "COMPONENT_AT_SCOPE_SMALL" },
	{ 0x1D073A89, "COMPONENT_AT_AR_FLSH" },
	{ 0x1D073A89, "COMPONENT_AT_SR_SUPP" },
	{ 0x1D073A89, "COMPONENT_PUMPSHOTGUN_VARMOD_LOWRIDER" },
	{ 0x7846A318, "COMPONENT_SAWNOFFSHOTGUN_VARMOD_LUXE" },
	{ 0xE284C527, "COMPONENT_ASSAULTSHOTGUN_CLIP_02" },
	{ 0xE284C527, "COMPONENT_AT_AR_FLSH" },
	{ 0xE284C527, "COMPONENT_AT_AR_SUPP" },
	{ 0xE284C527, "COMPONENT_AT_AR_AFGRIP" },
	{ 0x9D61E50F, "COMPONENT_AT_AR_FLSH" },
	{ 0x9D61E50F, "COMPONENT_AT_AR_SUPP_02" },
	{ 0x9D61E50F, "COMPONENT_AT_AR_AFGRIP" },
	{ 0x555AF99A, "COMPONENT_PUMPSHOTGUN_MK2_CLIP_EXPLOSIVE" },
	{ 0x555AF99A, "COMPONENT_AT_SIGHTS" },
	{ 0x555AF99A, "COMPONENT_AT_SCOPE_SMALL_MK2" },
	{ 0x555AF99A, "COMPONENT_AT_AR_FLSH" },
	{ 0x555AF99A, "COMPONENT_AT_SR_SUPP_03" },
	{ 0x555AF99A, "COMPONENT_AT_MUZZLE_08" },
	{ 0x555AF99A, "COMPONENT_PUMPSHOTGUN_MK2_CAMO_IND_01" },
	{ 0x3AABBBAA, "COMPONENT_HEAVYSHOTGUN_CLIP_03" },
	{ 0x3AABBBAA, "COMPONENT_AT_AR_FLSH" },
	{ 0x3AABBBAA, "COMPONENT_AT_AR_SUPP_02" },
	{ 0x3AABBBAA, "COMPONENT_AT_AR_AFGRIP" },
	{ 0x5A96BA4, "COMPONENT_AT_AR_FLSH" },
	{ 0x5A96BA4, "COMPONENT_AT_AR_SUPP" },
	{ 0xBFEFFF6D, "COMPONENT_ASSAULTRIFLE_CLIP_03" },
	{ 0xBFEFFF6D, "COMPONENT_AT_AR_FLSH" },
	{ 0xBFEFFF6D, "COMPONENT_AT_SCOPE_MACRO" },
	{ 0xBFEFFF6D, "COMPONENT_AT_AR_SUPP_02" },
	{ 0xBFEFFF6D, "COMPONENT_AT_AR_AFGRIP" },
	{ 0xBFEFFF6D, "COMPONENT_ASSAULTRIFLE_VARMOD_LUXE" },
	{ 0x83BF0278, "COMPONENT_CARBINERIFLE_CLIP_03" },
	{ 0x83BF0278, "COMPONENT_AT_AR_FLSH" },
	{ 0x83BF0278, "COMPONENT_AT_SCOPE_MEDIUM" },
	{ 0x83BF0278, "COMPONENT_AT_AR_SUPP" },
	{ 0x83BF0278, "COMPONENT_AT_AR_AFGRIP" },
	{ 0x83BF0278, "COMPONENT_CARBINERIFLE_VARMOD_LUXE" },
	{ 0xAF113F99, "COMPONENT_ADVANCEDRIFLE_CLIP_02" },
	{ 0xAF113F99, "COMPONENT_AT_AR_FLSH" },
	{ 0xAF113F99, "COMPONENT_AT_SCOPE_SMALL" },
	{ 0xAF113F99, "COMPONENT_AT_AR_SUPP" },
	{ 0xAF113F99, "COMPONENT_ADVANCEDRIFLE_VARMOD_LUXE" },
	{ 0xC0A3098D, "COMPONENT_SPECIALCARBINE_CLIP_03" },
	{ 0xC0A3098D, "COMPONENT_AT_AR_FLSH" },
	{ 0xC0A3098D, "COMPONENT_AT_SCOPE_MEDIUM" },
	{ 0xC0A3098D, "COMPONENT_AT_AR_SUPP_02" },
	{ 0xC0A3098D, "COMPONENT_AT_AR_AFGRIP" },
	{ 0xC0A3098D, "COMPONENT_SPECIALCARBINE_VARMOD_LOWRIDER" },
	{ 0x7F229F94, "COMPONENT_BULLPUPRIFLE_CLIP_02" },
	{ 0x7F229F94, "COMPONENT_AT_AR_FLSH" },
	{ 0x7F229F94, "COMPONENT_AT_SCOPE_SMALL" },
	{ 0x7F229F94, "COMPONENT_AT_AR_SUPP" },
	{ 0x7F229F94, "COMPONENT_AT_AR_AFGRIP" },
	{ 0x7F229F94, "COMPONENT_BULLPUPRIFLE_VARMOD_LOW" },
	{ 0x84D6FAFD, "COMPONENT_BULLPUPRIFLE_MK2_CLIP_02" },
	{ 0x84D6FAFD, "COMPONENT_BULLPUPRIFLE_MK2_CLIP_FMJ" },
	{ 0x84D6FAFD, "COMPONENT_AT_AR_FLSH" },
	{ 0x84D6FAFD, "COMPONENT_AT_SIGHTS" },
	{ 0x84D6FAFD, "COMPONENT_AT_SCOPE_SMALL_MK2" },
	{ 0x84D6FAFD, "COMPONENT_AT_BP_BARREL_02" },
	{ 0x84D6FAFD, "COMPONENT_AT_AR_SUPP" },
	{ 0x84D6FAFD, "COMPONENT_AT_MUZZLE_07" },
	{ 0x84D6FAFD, "COMPONENT_AT_AR_AFGRIP_02" },
	{ 0x84D6FAFD, "COMPONENT_BULLPUPRIFLE_MK2_CAMO_IND_01" },
	{ 0x969C3D67, "COMPONENT_SPECIALCARBINE_MK2_CLIP_02" },
	{ 0x969C3D67, "COMPONENT_SPECIALCARBINE_MK2_CLIP_FMJ" },
	{ 0x969C3D67, "COMPONENT_AT_AR_FLSH" },
	{ 0x969C3D67, "COMPONENT_AT_SIGHTS" },
	{ 0x969C3D67, "COMPONENT_AT_SCOPE_MEDIUM_MK2" },
	{ 0x969C3D67, "COMPONENT_AT_AR_SUPP_02" },
	{ 0x969C3D67, "COMPONENT_AT_MUZZLE_07" },
	{ 0x969C3D67, "COMPONENT_AT_AR_AFGRIP_02" },
	{ 0x969C3D67, "COMPONENT_AT_SC_BARREL_02" },
	{ 0x969C3D67, "COMPONENT_SPECIALCARBINE_MK2_CAMO_IND_01" },
	{ 0x394F415C, "COMPONENT_ASSAULTRIFLE_MK2_CLIP_02" },
	{ 0x394F415C, "COMPONENT_ASSAULTRIFLE_MK2_CLIP_FMJ" },
	{ 0x394F415C, "COMPONENT_AT_AR_AFGRIP_02" },
	{ 0x394F415C, "COMPONENT_AT_AR_FLSH" },
	{ 0x394F415C, "COMPONENT_AT_SIGHTS" },
	{ 0x394F415C, "COMPONENT_AT_SCOPE_MEDIUM_MK2" },
	{ 0x394F415C, "COMPONENT_AT_AR_SUPP_02" },
	{ 0x394F415C, "COMPONENT_AT_MUZZLE_07" },
	{ 0x394F415C, "COMPONENT_AT_AR_BARREL_02" },
	{ 0x394F415C, "COMPONENT_ASSAULTRIFLE_MK2_CAMO_IND_01" },
	{ 0xFAD1F1C9, "COMPONENT_CARBINERIFLE_MK2_CLIP_02" },
	{ 0xFAD1F1C9, "COMPONENT_CARBINERIFLE_MK2_CLIP_FMJ" },
	{ 0xFAD1F1C9, "COMPONENT_AT_AR_AFGRIP_02" },
	{ 0xFAD1F1C9, "COMPONENT_AT_AR_FLSH" },
	{ 0xFAD1F1C9, "COMPONENT_AT_SIGHTS" },
	{ 0xFAD1F1C9, "COMPONENT_AT_SCOPE_MEDIUM_MK2" },
	{ 0xFAD1F1C9, "COMPONENT_AT_AR_SUPP" },
	{ 0xFAD1F1C9, "COMPONENT_AT_MUZZLE_07" },
	{ 0xFAD1F1C9, "COMPONENT_AT_CR_BARREL_02" },
	{ 0xFAD1F1C9, "COMPONENT_CARBINERIFLE_MK2_CAMO_IND_01" },
	{ 0x624FE830, "COMPONENT_COMPACTRIFLE_CLIP_03" },
	{ 0x9D1F17E6, "COMPONENT_MILITARYRIFLE_CLIP_02" },
	{ 0x9D1F17E6, "COMPONENT_AT_SCOPE_SMALL" },
	{ 0x9D1F17E6, "COMPONENT_AT_AR_FLSH" },
	{ 0x9D1F17E6, "COMPONENT_AT_AR_SUPP" },
	{ 0x9D07F764, "COMPONENT_MG_CLIP_02" },
	{ 0x9D07F764, "COMPONENT_AT_SCOPE_SMALL_02" },
	{ 0x9D07F764, "COMPONENT_MG_VARMOD_LOWRIDER" },
	{ 0x7FD62962, "COMPONENT_COMBATMG_CLIP_02" },
	{ 0x7FD62962, "COMPONENT_AT_SCOPE_MEDIUM" },
	{ 0x7FD62962, "COMPONENT_AT_AR_AFGRIP" },
	{ 0x7FD62962, "COMPONENT_COMBATMG_VARMOD_LOWRIDER" },
	{ 0xDBBD7280, "COMPONENT_COMBATMG_MK2_CLIP_02" },
	{ 0xDBBD7280, "COMPONENT_COMBATMG_MK2_CLIP_FMJ" },
	{ 0xDBBD7280, "COMPONENT_AT_AR_AFGRIP_02" },
	{ 0xDBBD7280, "COMPONENT_AT_SCOPE_MEDIUM_MK2" },
	{ 0xDBBD7280, "COMPONENT_AT_MUZZLE_07" },
	{ 0xDBBD7280, "COMPONENT_AT_MG_BARREL_02" },
	{ 0xDBBD7280, "COMPONENT_COMBATMG_MK2_CAMO_IND_01" },
	{ 0x61012683, "COMPONENT_GUSENBERG_CLIP_02" },
	{ 0x05FC3C11, "COMPONENT_SNIPERRIFLE_CLIP_01" },
	{ 0x05FC3C11, "COMPONENT_AT_AR_SUPP_02" },
	{ 0x05FC3C11, "COMPONENT_AT_SCOPE_MAX" },
	{ 0x05FC3C11, "COMPONENT_SNIPERRIFLE_VARMOD_LUXE" },
	{ 0x0C472FE2, "COMPONENT_HEAVYSNIPER_CLIP_01" },
	{ 0x0C472FE2, "COMPONENT_AT_SCOPE_MAX" },
	{ 0x6A6C02E0, "COMPONENT_MARKSMANRIFLE_MK2_CLIP_02" },
	{ 0x6A6C02E0, "COMPONENT_MARKSMANRIFLE_MK2_CLIP_FMJ" },
	{ 0x6A6C02E0, "COMPONENT_AT_SCOPE_MEDIUM_MK2" },
	{ 0x6A6C02E0, "COMPONENT_AT_AR_FLSH" },
	{ 0x6A6C02E0, "COMPONENT_AT_AR_SUPP" },
	{ 0x6A6C02E0, "COMPONENT_AT_MUZZLE_07" },
	{ 0x6A6C02E0, "COMPONENT_AT_MRFL_BARREL_02" },
	{ 0x6A6C02E0, "COMPONENT_AT_AR_AFGRIP_02" },
	{ 0x6A6C02E0, "COMPONENT_MARKSMANRIFLE_MK2_CAMO_IND_01" },
	{ 0xA914799, "COMPONENT_HEAVYSNIPER_MK2_CLIP_02" },
	{ 0xA914799, "COMPONENT_HEAVYSNIPER_MK2_CLIP_EXPLOSIVE" },
	{ 0xA914799, "COMPONENT_AT_SCOPE_THERMAL" },
	{ 0xA914799, "COMPONENT_AT_MUZZLE_09" },
	{ 0xA914799, "COMPONENT_AT_SR_BARREL_02" },
	{ 0xA914799, "COMPONENT_HEAVYSNIPER_MK2_CAMO_IND_01" },
	{ 0xC734385A, "COMPONENT_MARKSMANRIFLE_CLIP_02" },
	{ 0xC734385A, "COMPONENT_AT_SCOPE_LARGE_FIXED_ZOOM" },
	{ 0xC734385A, "COMPONENT_AT_AR_FLSH" },
	{ 0xC734385A, "COMPONENT_AT_AR_SUPP" },
	{ 0xC734385A, "COMPONENT_AT_AR_AFGRIP" },
	{ 0xC734385A, "COMPONENT_MARKSMANRIFLE_VARMOD_LUXE" },
	{ 0xA284510B, "COMPONENT_GRENADELAUNCHER_CLIP_01" },
	{ 0xA284510B, "COMPONENT_AT_AR_FLSH" },
	{ 0xA284510B, "COMPONENT_AT_AR_AFGRIP" },
	{ 0xA284510B, "COMPONENT_AT_SCOPE_SMALL" },
	{ 0xD1D5F52B, "COMPONENT_AT_AR_AFGRIP" },
	{ 0xD1D5F52B, "COMPONENT_TACTICALRIFLE_CLIP_02" },
	{ 0xD1D5F52B, "COMPONENT_AT_AR_FLSH_REH" },
	{ 0xD1D5F52B, "COMPONENT_AT_AR_SUPP_02" },
	{ 0xC78D71B4, "COMPONENT_HEAVYRIFLE_CLIP_02" },
	{ 0xC78D71B4, "COMPONENT_AT_SCOPE_MEDIUM" },
	{ 0xC78D71B4, "COMPONENT_AT_AR_FLSH" },
	{ 0xC78D71B4, "COMPONENT_AT_AR_SUPP" },
	{ 0xC78D71B4, "COMPONENT_AT_AR_AFGRIP" },
	{ 0xC78D71B4, "COMPONENT_HEAVYRIFLE_CAMO1" }
};

const std::vector<AnimationsStruct> Cheat::GameArrays::Animations = {
	{ "rcmpaparazzo_2", "shag_loop_poppy" },
	{ "rcmpaparazzo_2", "shag_loop_a" },
	{ "mini@strip_club@private_dance@part1", "priv_dance_p1" },
	{ "mini@strip_club@pole_dance@pole_dance1", "pd_dance_01" },
	{ "amb@world_human_push_ups@male@base", "base" },
	{ "amb@world_human_sit_ups@male@base", "base" },
	{ "rcmfanatic1celebrate", "celebrate" },
	{ "ragdoll@human", "electrocute" },
	{ "mp_suicide", "pistol" },
	{ "mp_suicide", "pill" },
	{ "mp_safehouseshower@male@", "male_shower_idle_b" }
};
const std::vector<std::string> Cheat::GameArrays::AnimationsDisplayNames = {
	"Sex Receiver", 
	"Sex Giver", 
	"Stripper Dance",
	"Pole Dance", 
	"Push Ups", 
	"Sit Ups",
	"Celebrate",
	"Electrocution",
	"Suicide (Pistol)",
	"Suicide (Pill)",
	"Showering"
};

const std::vector<std::string> Cheat::GameArrays::Scenarios = {
	"WORLD_HUMAN_AA_COFFEE",
	"WORLD_HUMAN_AA_SMOKE",
	"WORLD_HUMAN_BINOCULARS",
	"WORLD_HUMAN_BUM_FREEWAY",
	"WORLD_HUMAN_BUM_SLUMPED",
	"WORLD_HUMAN_BUM_STANDING",
	"WORLD_HUMAN_BUM_WASH",
	"WORLD_HUMAN_CAR_PARK_ATTENDANT",
	"WORLD_HUMAN_CHEERING",
	"WORLD_HUMAN_CLIPBOARD",
	"WORLD_HUMAN_CONST_DRILL",
	"WORLD_HUMAN_COP_IDLES",
	"WORLD_HUMAN_DRINKING",
	"WORLD_HUMAN_DRUG_DEALER",
	"WORLD_HUMAN_DRUG_DEALER_HARD",
	"WORLD_HUMAN_MOBILE_FILM_SHOCKING",
	"WORLD_HUMAN_GARDENER_LEAF_BLOWER",
	"WORLD_HUMAN_GARDENER_PLANT",
	"WORLD_HUMAN_GOLF_PLAYER",
	"WORLD_HUMAN_GUARD_PATROL",
	"WORLD_HUMAN_GUARD_STAND",
	"WORLD_HUMAN_GUARD_STAND_ARMY",
	"WORLD_HUMAN_HAMMERING",
	"WORLD_HUMAN_HANG_OUT_STREET",
	"WORLD_HUMAN_HIKER",
	"WORLD_HUMAN_HIKER_STANDING",
	"WORLD_HUMAN_HUMAN_STATUE",
	"WORLD_HUMAN_JANITOR",
	"WORLD_HUMAN_JOG",
	"WORLD_HUMAN_JOG_STANDING",
	"WORLD_HUMAN_LEANING",
	"WORLD_HUMAN_MAID_CLEAN",
	"WORLD_HUMAN_MUSCLE_FLEX",
	"WORLD_HUMAN_MUSCLE_FREE_WEIGHTS",
	"WORLD_HUMAN_MUSICIAN",
	"WORLD_HUMAN_PAPARAZZI",
	"WORLD_HUMAN_PARTYING",
	"WORLD_HUMAN_PICNIC",
	"WORLD_HUMAN_POWER_WALKER",
	"WORLD_HUMAN_PROSTITUTE_HIGH_CLASS",
	"WORLD_HUMAN_PROSTITUTE_LOW_CLASS",
	"WORLD_HUMAN_PUSH_UPS",
	"WORLD_HUMAN_SEAT_LEDGE",
	"WORLD_HUMAN_SEAT_LEDGE_EATING",
	"WORLD_HUMAN_SEAT_STEPS",
	"WORLD_HUMAN_SEAT_WALL",
	"WORLD_HUMAN_SEAT_WALL_EATING",
	"WORLD_HUMAN_SEAT_WALL_TABLET",
	"WORLD_HUMAN_SECURITY_SHINE_TORCH",
	"WORLD_HUMAN_SIT_UPS",
	"WORLD_HUMAN_SMOKING",
	"WORLD_HUMAN_SMOKING_POT",
	"WORLD_HUMAN_STAND_FIRE",
	"WORLD_HUMAN_STAND_FISHING",
	"WORLD_HUMAN_STAND_IMPATIENT",
	"WORLD_HUMAN_STAND_IMPATIENT_UPRIGHT",
	"WORLD_HUMAN_STAND_MOBILE",
	"WORLD_HUMAN_STAND_MOBILE_UPRIGHT",
	"WORLD_HUMAN_STRIP_WATCH_STAND",
	"WORLD_HUMAN_STUPOR",
	"WORLD_HUMAN_SUNBATHE",
	"WORLD_HUMAN_SUNBATHE_BACK",
	"WORLD_HUMAN_SUPERHERO",
	"WORLD_HUMAN_SWIMMING",
	"WORLD_HUMAN_TENNIS_PLAYER",
	"WORLD_HUMAN_TOURIST_MAP",
	"WORLD_HUMAN_TOURIST_MOBILE",
	"WORLD_HUMAN_VEHICLE_MECHANIC",
	"WORLD_HUMAN_WELDING",
	"WORLD_HUMAN_WINDOW_SHOP_BROWSE",
	"WORLD_HUMAN_YOGA",
	"Walk",
	"WORLD_BOAR_GRAZING",
	"WORLD_CAT_SLEEPING_GROUND",
	"WORLD_CAT_SLEEPING_LEDGE",
	"WORLD_COW_GRAZING",
	"WORLD_COYOTE_HOWL",
	"WORLD_COYOTE_REST",
	"WORLD_COYOTE_WANDER",
	"WORLD_COYOTE_WALK",
	"WORLD_CHICKENHAWK_FEEDING",
	"WORLD_CHICKENHAWK_STANDING",
	"WORLD_CORMORANT_STANDING",
	"WORLD_CROW_FEEDING",
	"WORLD_CROW_STANDING",
	"WORLD_DEER_GRAZING",
	"WORLD_DOG_BARKING_ROTTWEILER",
	"WORLD_DOG_BARKING_RETRIEVER",
	"WORLD_DOG_BARKING_SHEPHERD",
	"WORLD_DOG_SITTING_ROTTWEILER",
	"WORLD_DOG_SITTING_RETRIEVER",
	"WORLD_DOG_SITTING_SHEPHERD",
	"WORLD_DOG_BARKING_SMALL",
	"WORLD_DOG_SITTING_SMALL",
	"WORLD_DOLPHIN_SWIM",
	"WORLD_FISH_FLEE",
	"WORLD_FISH_IDLE",
	"WORLD_GULL_FEEDING",
	"WORLD_GULL_STANDING",
	"WORLD_HEN_FLEE",
	"WORLD_HEN_PECKING",
	"WORLD_HEN_STANDING",
	"WORLD_MOUNTAIN_LION_REST",
	"WORLD_MOUNTAIN_LION_WANDER",
	"WORLD_ORCA_SWIM",
	"WORLD_PIG_GRAZING",
	"WORLD_PIGEON_FEEDING",
	"WORLD_PIGEON_STANDING",
	"WORLD_RABBIT_EATING",
	"WORLD_RABBIT_FLEE",
	"WORLD_RATS_EATING",
	"WORLD_RATS_FLEEING",
	"WORLD_SHARK_SWIM",
	"WORLD_SHARK_HAMMERHEAD_SWIM",
	"WORLD_STINGRAY_SWIM",
	"WORLD_WHALE_SWIM",
	"DRIVE",
	"WORLD_VEHICLE_ATTRACTOR",
	"PARK_VEHICLE",
	"WORLD_VEHICLE_AMBULANCE",
	"WORLD_VEHICLE_BICYCLE_BMX",
	"WORLD_VEHICLE_BICYCLE_BMX_BALLAS",
	"WORLD_VEHICLE_BICYCLE_BMX_FAMILY",
	"WORLD_VEHICLE_BICYCLE_BMX_HARMONY",
	"WORLD_VEHICLE_BICYCLE_BMX_VAGOS",
	"WORLD_VEHICLE_BICYCLE_MOUNTAIN",
	"WORLD_VEHICLE_BICYCLE_ROAD",
	"WORLD_VEHICLE_BIKE_OFF_ROAD_RACE",
	"WORLD_VEHICLE_BIKER",
	"WORLD_VEHICLE_BOAT_IDLE",
	"WORLD_VEHICLE_BOAT_IDLE_ALAMO",
	"WORLD_VEHICLE_BOAT_IDLE_MARQUIS",
	"WORLD_VEHICLE_BROKEN_DOWN",
	"WORLD_VEHICLE_BUSINESSMEN",
	"WORLD_VEHICLE_HELI_LIFEGUARD",
	"WORLD_VEHICLE_CLUCKIN_BELL_TRAILER",
	"WORLD_VEHICLE_CONSTRUCTION_SOLO",
	"WORLD_VEHICLE_CONSTRUCTION_PASSENGERS",
	"WORLD_VEHICLE_DRIVE_PASSENGERS",
	"WORLD_VEHICLE_DRIVE_PASSENGERS_LIMITED",
	"WORLD_VEHICLE_DRIVE_SOLO",
	"WORLD_VEHICLE_FARM_WORKER",
	"WORLD_VEHICLE_FIRE_TRUCK",
	"WORLD_VEHICLE_EMPTY",
	"WORLD_VEHICLE_MARIACHI",
	"WORLD_VEHICLE_MECHANIC",
	"WORLD_VEHICLE_MILITARY_PLANES_BIG",
	"WORLD_VEHICLE_MILITARY_PLANES_SMALL",
	"WORLD_VEHICLE_PARK_PARALLEL",
	"WORLD_VEHICLE_PARK_PERPENDICULAR_NOSE_IN",
	"WORLD_VEHICLE_PASSENGER_EXIT",
	"WORLD_VEHICLE_POLICE_BIKE",
	"WORLD_VEHICLE_POLICE_CAR",
	"WORLD_VEHICLE_POLICE_NEXT_TO_CAR",
	"WORLD_VEHICLE_QUARRY",
	"WORLD_VEHICLE_SALTON",
	"WORLD_VEHICLE_SALTON_DIRT_BIKE",
	"WORLD_VEHICLE_SECURITY_CAR",
	"WORLD_VEHICLE_STREETRACE",
	"WORLD_VEHICLE_TOURBUS",
	"WORLD_VEHICLE_TOURIST",
	"WORLD_VEHICLE_TANDL",
	"WORLD_VEHICLE_TRACTOR",
	"WORLD_VEHICLE_TRACTOR_BEACH",
	"WORLD_VEHICLE_TRUCK_LOGS",
	"WORLD_VEHICLE_TRUCKS_TRAILERS",
	"PROP_BIRD_IN_TREE",
	"WORLD_VEHICLE_DISTANT_EMPTY_GROUND",
	"PROP_BIRD_TELEGRAPH_POLE",
	"PROP_HUMAN_ATM",
	"PROP_HUMAN_BBQ",
	"PROP_HUMAN_BUM_BIN",
	"PROP_HUMAN_BUM_SHOPPING_CART",
	"PROP_HUMAN_MUSCLE_CHIN_UPS",
	"PROP_HUMAN_MUSCLE_CHIN_UPS_ARMY",
	"PROP_HUMAN_MUSCLE_CHIN_UPS_PRISON",
	"PROP_HUMAN_PARKING_METER",
	"PROP_HUMAN_SEAT_ARMCHAIR",
	"PROP_HUMAN_SEAT_BAR",
	"PROP_HUMAN_SEAT_BENCH",
	"PROP_HUMAN_SEAT_BENCH_DRINK",
	"PROP_HUMAN_SEAT_BENCH_DRINK_BEER",
	"PROP_HUMAN_SEAT_BENCH_FOOD",
	"PROP_HUMAN_SEAT_BUS_STOP_WAIT",
	"PROP_HUMAN_SEAT_CHAIR",
	"PROP_HUMAN_SEAT_CHAIR_DRINK",
	"PROP_HUMAN_SEAT_CHAIR_DRINK_BEER",
	"PROP_HUMAN_SEAT_CHAIR_FOOD",
	"PROP_HUMAN_SEAT_CHAIR_UPRIGHT",
	"PROP_HUMAN_SEAT_CHAIR_MP_PLAYER",
	"PROP_HUMAN_SEAT_COMPUTER",
	"PROP_HUMAN_SEAT_DECKCHAIR",
	"PROP_HUMAN_SEAT_DECKCHAIR_DRINK",
	"PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS",
	"PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS_PRISON",
	"PROP_HUMAN_SEAT_SEWING",
	"PROP_HUMAN_SEAT_STRIP_WATCH",
	"PROP_HUMAN_SEAT_SUNLOUNGER",
	"PROP_HUMAN_STAND_IMPATIENT",
	"CODE_HUMAN_COWER",
	"CODE_HUMAN_CROSS_ROAD_WAIT",
	"CODE_HUMAN_PARK_CAR",
	"PROP_HUMAN_MOVIE_BULB",
	"PROP_HUMAN_MOVIE_STUDIO_LIGHT",
	"CODE_HUMAN_MEDIC_KNEEL",
	"CODE_HUMAN_MEDIC_TEND_TO_DEAD",
	"CODE_HUMAN_MEDIC_TIME_OF_DEATH",
	"CODE_HUMAN_POLICE_CROWD_CONTROL",
	"CODE_HUMAN_POLICE_INVESTIGATE",
	"CHAINING_ENTRY",
	"CHAINING_EXIT",
	"CODE_HUMAN_STAND_COWER",
	"EAR_TO_TEXT",
	"EAR_TO_TEXT_FAT",
	"WORLD_LOOKAT_POINT"
};

const std::vector<TSEPropertyListStruct> Cheat::GameArrays::TSEPropertyList = {
	{ "Eclipse Towers", 1 },
	{ "Alta Street", 5 },
	{ "Del Perro Heights", 7 },
	{ "Power Street", 8 },
	{ "Spanish Avenue", 9 },
	{ "Las Lagunas Blvd", 10 },
	{ "Milton Road", 11 },
	{ "The Royale", 12 },
	{ "Milton Drive", 13 },
	{ "San Vitas Street", 18 },
	{ "Vespucci Blvd", 20 },
	{ "Cougar Avenue", 21 },
	{ "Prosperity Street", 22 }
};

const std::vector<std::string> Cheat::GameArrays::HUDColors = {
	"HUD_COLOUR_PURE_WHITE",
	"HUD_COLOUR_WHITE",
	"HUD_COLOUR_BLACK",
	"HUD_COLOUR_GREY",
	"HUD_COLOUR_GREYLIGHT",
	"HUD_COLOUR_GREYDARK",
	"HUD_COLOUR_RED",
	"HUD_COLOUR_REDLIGHT",
	"HUD_COLOUR_REDDARK",
	"HUD_COLOUR_BLUE",
	"HUD_COLOUR_BLUELIGHT",
	"HUD_COLOUR_BLUEDARK",
	"HUD_COLOUR_YELLOW",
	"HUD_COLOUR_YELLOWLIGHT",
	"HUD_COLOUR_YELLOWDARK",
	"HUD_COLOUR_ORANGE",
	"HUD_COLOUR_ORANGELIGHT",
	"HUD_COLOUR_ORANGEDARK",
	"HUD_COLOUR_GREEN",
	"HUD_COLOUR_GREENLIGHT",
	"HUD_COLOUR_GREENDARK",
	"HUD_COLOUR_PURPLE",
	"HUD_COLOUR_PURPLELIGHT",
	"HUD_COLOUR_PURPLEDARK",
	"HUD_COLOUR_PINK",
	"HUD_COLOUR_RADAR_HEALTH",
	"HUD_COLOUR_RADAR_ARMOUR",
	"HUD_COLOUR_RADAR_DAMAGE",
	"HUD_COLOUR_NET_PLAYER1",
	"HUD_COLOUR_NET_PLAYER2",
	"HUD_COLOUR_NET_PLAYER3",
	"HUD_COLOUR_NET_PLAYER4",
	"HUD_COLOUR_NET_PLAYER5",
	"HUD_COLOUR_NET_PLAYER6",
	"HUD_COLOUR_NET_PLAYER7",
	"HUD_COLOUR_NET_PLAYER8",
	"HUD_COLOUR_NET_PLAYER9",
	"HUD_COLOUR_NET_PLAYER10",
	"HUD_COLOUR_NET_PLAYER11",
	"HUD_COLOUR_NET_PLAYER12",
	"HUD_COLOUR_NET_PLAYER13",
	"HUD_COLOUR_NET_PLAYER14",
	"HUD_COLOUR_NET_PLAYER15",
	"HUD_COLOUR_NET_PLAYER16",
	"HUD_COLOUR_NET_PLAYER17",
	"HUD_COLOUR_NET_PLAYER18",
	"HUD_COLOUR_NET_PLAYER19",
	"HUD_COLOUR_NET_PLAYER20",
	"HUD_COLOUR_NET_PLAYER21",
	"HUD_COLOUR_NET_PLAYER22",
	"HUD_COLOUR_NET_PLAYER23",
	"HUD_COLOUR_NET_PLAYER24",
	"HUD_COLOUR_NET_PLAYER25",
	"HUD_COLOUR_NET_PLAYER26",
	"HUD_COLOUR_NET_PLAYER27",
	"HUD_COLOUR_NET_PLAYER28",
	"HUD_COLOUR_NET_PLAYER29",
	"HUD_COLOUR_NET_PLAYER30",
	"HUD_COLOUR_NET_PLAYER31",
	"HUD_COLOUR_NET_PLAYER32",
	"HUD_COLOUR_SIMPLEBLIP_DEFAULT",
	"HUD_COLOUR_MENU_BLUE",
	"HUD_COLOUR_MENU_GREY_LIGHT",
	"HUD_COLOUR_MENU_BLUE_EXTRA_DARK",
	"HUD_COLOUR_MENU_YELLOW",
	"HUD_COLOUR_MENU_YELLOW_DARK",
	"HUD_COLOUR_MENU_GREEN",
	"HUD_COLOUR_MENU_GREY",
	"HUD_COLOUR_MENU_GREY_DARK",
	"HUD_COLOUR_MENU_HIGHLIGHT",
	"HUD_COLOUR_MENU_STANDARD",
	"HUD_COLOUR_MENU_DIMMED",
	"HUD_COLOUR_MENU_EXTRA_DIMMED",
	"HUD_COLOUR_BRIEF_TITLE",
	"HUD_COLOUR_MID_GREY_MP",
	"HUD_COLOUR_NET_PLAYER1_DARK",
	"HUD_COLOUR_NET_PLAYER2_DARK",
	"HUD_COLOUR_NET_PLAYER3_DARK",
	"HUD_COLOUR_NET_PLAYER4_DARK",
	"HUD_COLOUR_NET_PLAYER5_DARK",
	"HUD_COLOUR_NET_PLAYER6_DARK",
	"HUD_COLOUR_NET_PLAYER7_DARK",
	"HUD_COLOUR_NET_PLAYER8_DARK",
	"HUD_COLOUR_NET_PLAYER9_DARK",
	"HUD_COLOUR_NET_PLAYER10_DARK",
	"HUD_COLOUR_NET_PLAYER11_DARK",
	"HUD_COLOUR_NET_PLAYER12_DARK",
	"HUD_COLOUR_NET_PLAYER13_DARK",
	"HUD_COLOUR_NET_PLAYER14_DARK",
	"HUD_COLOUR_NET_PLAYER15_DARK",
	"HUD_COLOUR_NET_PLAYER16_DARK",
	"HUD_COLOUR_NET_PLAYER17_DARK",
	"HUD_COLOUR_NET_PLAYER18_DARK",
	"HUD_COLOUR_NET_PLAYER19_DARK",
	"HUD_COLOUR_NET_PLAYER20_DARK",
	"HUD_COLOUR_NET_PLAYER21_DARK",
	"HUD_COLOUR_NET_PLAYER22_DARK",
	"HUD_COLOUR_NET_PLAYER23_DARK",
	"HUD_COLOUR_NET_PLAYER24_DARK",
	"HUD_COLOUR_NET_PLAYER25_DARK",
	"HUD_COLOUR_NET_PLAYER26_DARK",
	"HUD_COLOUR_NET_PLAYER27_DARK",
	"HUD_COLOUR_NET_PLAYER28_DARK",
	"HUD_COLOUR_NET_PLAYER29_DARK",
	"HUD_COLOUR_NET_PLAYER30_DARK",
	"HUD_COLOUR_NET_PLAYER31_DARK",
	"HUD_COLOUR_NET_PLAYER32_DARK",
	"HUD_COLOUR_BRONZE",
	"HUD_COLOUR_SILVER",
	"HUD_COLOUR_GOLD",
	"HUD_COLOUR_PLATINUM",
	"HUD_COLOUR_GANG1",
	"HUD_COLOUR_GANG2",
	"HUD_COLOUR_GANG3",
	"HUD_COLOUR_GANG4",
	"HUD_COLOUR_SAME_CREW",
	"HUD_COLOUR_FREEMODE",
	"HUD_COLOUR_PAUSE_BG",
	"HUD_COLOUR_FRIENDLY",
	"HUD_COLOUR_ENEMY",
	"HUD_COLOUR_LOCATION",
	"HUD_COLOUR_PICKUP",
	"HUD_COLOUR_PAUSE_SINGLEPLAYER",
	"HUD_COLOUR_FREEMODE_DARK",
	"HUD_COLOUR_INACTIVE_MISSION",
	"HUD_COLOUR_DAMAGE",
	"HUD_COLOUR_PINKLIGHT",
	"HUD_COLOUR_PM_MITEM_HIGHLIGHT",
	"HUD_COLOUR_SCRIPT_VARIABLE",
	"HUD_COLOUR_YOGA",
	"HUD_COLOUR_TENNIS",
	"HUD_COLOUR_GOLF",
	"HUD_COLOUR_SHOOTING_RANGE",
	"HUD_COLOUR_FLIGHT_SCHOOL",
	"HUD_COLOUR_NORTH_BLUE",
	"HUD_COLOUR_SOCIAL_CLUB",
	"HUD_COLOUR_PLATFORM_BLUE",
	"HUD_COLOUR_PLATFORM_GREEN",
	"HUD_COLOUR_PLATFORM_GREY",
	"HUD_COLOUR_FACEBOOK_BLUE",
	"HUD_COLOUR_INGAME_BG",
	"HUD_COLOUR_DARTS",
	"HUD_COLOUR_WAYPOINT",
	"HUD_COLOUR_MICHAEL",
	"HUD_COLOUR_FRANKLIN",
	"HUD_COLOUR_TREVOR",
	"HUD_COLOUR_GOLF_P1",
	"HUD_COLOUR_GOLF_P2",
	"HUD_COLOUR_GOLF_P3",
	"HUD_COLOUR_GOLF_P4",
	"HUD_COLOUR_WAYPOINTLIGHT",
	"HUD_COLOUR_WAYPOINTDARK",
	"HUD_COLOUR_PANEL_LIGHT",
	"HUD_COLOUR_MICHAEL_DARK",
	"HUD_COLOUR_FRANKLIN_DARK",
	"HUD_COLOUR_TREVOR_DARK",
	"HUD_COLOUR_OBJECTIVE_ROUTE",
	"HUD_COLOUR_PAUSEMAP_TINT",
	"HUD_COLOUR_PAUSE_DESELECT",
	"HUD_COLOUR_PM_WEAPONS_PURCHASABLE",
	"HUD_COLOUR_PM_WEAPONS_LOCKED",
	"HUD_COLOUR_END_SCREEN_BG",
	"HUD_COLOUR_CHOP",
	"HUD_COLOUR_PAUSEMAP_TINT_HALF",
	"HUD_COLOUR_NORTH_BLUE_OFFICIAL",
	"HUD_COLOUR_SCRIPT_VARIABLE_2",
	"HUD_COLOUR_H",
	"HUD_COLOUR_HDARK",
	"HUD_COLOUR_T",
	"HUD_COLOUR_TDARK",
	"HUD_COLOUR_HSHARD",
	"HUD_COLOUR_CONTROLLER_MICHAEL",
	"HUD_COLOUR_CONTROLLER_FRANKLIN",
	"HUD_COLOUR_CONTROLLER_TREVOR",
	"HUD_COLOUR_CONTROLLER_CHOP",
	"HUD_COLOUR_VIDEO_EDITOR_VIDEO",
	"HUD_COLOUR_VIDEO_EDITOR_AUDIO",
	"HUD_COLOUR_VIDEO_EDITOR_TEXT",
	"HUD_COLOUR_HB_BLUE",
	"HUD_COLOUR_HB_YELLOW",
	"HUD_COLOUR_VIDEO_EDITOR_SCORE",
	"HUD_COLOUR_VIDEO_EDITOR_AUDIO_FADEOUT",
	"HUD_COLOUR_VIDEO_EDITOR_TEXT_FADEOUT",
	"HUD_COLOUR_VIDEO_EDITOR_SCORE_FADEOUT",
	"HUD_COLOUR_HEIST_BACKGROUND",
	"HUD_COLOUR_VIDEO_EDITOR_AMBIENT",
	"HUD_COLOUR_VIDEO_EDITOR_AMBIENT_FADEOUT",
	"HUD_COLOUR_VIDEO_EDITOR_AMBIENT_DARK",
	"HUD_COLOUR_VIDEO_EDITOR_AMBIENT_LIGHT",
	"HUD_COLOUR_VIDEO_EDITOR_AMBIENT_MID",
	"HUD_COLOUR_LOW_FLOW",
	"HUD_COLOUR_LOW_FLOW_DARK",
	"HUD_COLOUR_G1",
	"HUD_COLOUR_G2",
	"HUD_COLOUR_G3",
	"HUD_COLOUR_G4",
	"HUD_COLOUR_G5",
	"HUD_COLOUR_G6",
	"HUD_COLOUR_G7",
	"HUD_COLOUR_G8",
	"HUD_COLOUR_G9",
	"HUD_COLOUR_G10",
	"HUD_COLOUR_G11",
	"HUD_COLOUR_G12",
	"HUD_COLOUR_G13",
	"HUD_COLOUR_G14",
	"HUD_COLOUR_G15",
	"HUD_COLOUR_ADVERSARY",
	"HUD_COLOUR_DEGEN_RED",
	"HUD_COLOUR_DEGEN_YELLOW",
	"HUD_COLOUR_DEGEN_GREEN",
	"HUD_COLOUR_DEGEN_CYAN",
	"HUD_COLOUR_DEGEN_BLUE",
	"HUD_COLOUR_DEGEN_MAGENTA",
	"HUD_COLOUR_STUNT_1",
	"HUD_COLOUR_STUNT_2",
	"HUD_COLOUR_SPECIAL_RACE_SERIES",
	"HUD_COLOUR_SPECIAL_RACE_SERIES_DARK",
	"HUD_COLOUR_CS",
	"HUD_COLOUR_CS_DARK",
	"HUD_COLOUR_TECH_GREEN",
	"HUD_COLOUR_TECH_GREEN_DARK",
	"HUD_COLOUR_TECH_RED",
	"HUD_COLOUR_TECH_GREEN_VERY_DARK"
};

// We call GET_HUD_COLOUR at initialization to fill this array with all game default HUD colors
std::vector<DefaultHUDColorsStruct> Cheat::GameArrays::DefaultHUDColors;

const std::vector<const char*> Cheat::GameArrays::IPLNorthYankton = {
	"prologue01",
	"prologue01c",
	"prologue01d",
	"prologue01e",
	"prologue01f",
	"prologue01g",
	"prologue01h",
	"prologue01i",
	"prologue01j",
	"prologue01k",
	"prologue01z",
	"prologue02",
	"prologue03",
	"prologue03b",
	"prologue03_grv_dug",
	"prologue_grv_torch",
	"prologue04",
	"prologue04b",
	"prologue04_cover",
	"des_protree_end",
	"des_protree_start",
	"prologue05",
	"prologue05b",
	"prologue06",
	"prologue06b",
	"prologue06_int",
	"prologue06_pannel",
	"plg_occl_00",
	"prologue_occl",
	"prologuerd",
	"prologuerdb",
};

const std::vector<const char*> Cheat::GameArrays::IPLDignityHeistYacht = {
	"hei_yacht_heist",
	"hei_yacht_heist_enginrm",
	"hei_yacht_heist_Lounge",
	"hei_yacht_heist_Bridge",
	"hei_yacht_heist_Bar",
	"hei_yacht_heist_Bedrm",
	"hei_yacht_heist_DistantLights",
	"hei_yacht_heist_LODLights"
};

const std::vector<const char*> Cheat::GameArrays::IPLDestroyedHospital = {
	"RC12B_Destroyed",
	"RC12B_HospitalInterior"
};

const std::vector<const char*> Cheat::GameArrays::IPLJewelryStore = {
	"post_hiest_unload",
	"jewel2fake",
	"bh1_16_refurb"
};

const std::vector<const char*> Cheat::GameArrays::IPLMorgue = {
	"Coroner_Int_On"
};

const std::vector<const char*> Cheat::GameArrays::IPLCargoship = {
	"cargoship"
};

const std::vector<const char*> Cheat::GameArrays::IPLAircraftCarrier = {
	"hei_carrier",
	"hei_carrier_DistantLights",
	"hei_Carrier_int1",
	"hei_Carrier_int2",
	"hei_Carrier_int3",
	"hei_Carrier_int4",
	"hei_Carrier_int5",
	"hei_Carrier_int6",
	"hei_carrier_LODLights"
};

// https://github.com/MAFINS/MenyooSP/blob/d1490e5c170c3f22360b4c6f20519a05a34d7b8f/Solution/source/Submenus/MiscOptions.cpp#L690
const std::map<std::string, std::string> Cheat::GameArrays::TelevisionPlaylists
{
	{ "CNT", "PL_STD_CNT" },
	{ "Weazel News", "PL_STD_WZL" },
	{ "Weazel News Transition", "PL_MP_WEAZEL" },
	{ "Lotto Adverts", "PL_LO_CNT" },
	{ "Piswasser Adverts", "PL_LO_WZL" },
	{ "Righteous Slaughter", "PL_LO_RS" },
	{ "Righteous Slaughter Cutscene", "PL_LO_RS_CUTSCENE" },
	{ "Workout", "PL_SP_WORKOUT" },
	{ "Life Invader", "PL_SP_INV" },
	{ "Life Invader Explosion", "PL_SP_INV_EXP" },
	{ "Weazel Adverts", "PL_SP_PLSH1_INTRO" },
	{ "Fame or Shame Episode 1", "PL_LES1_FAME_OR_SHAME" },
	{ "Fame or Shame Episode 2", "PL_STD_WZL_FOS_EP2" },
	{ "Capolavoro", "PL_CINEMA_ARTHOUSE" },
	{ "The Loneliest Robot", "PL_CINEMA_CARTOON" },
	{ "Meltdown", "PL_CINEMA_ACTION" },
	{ "Cinema (No Meltdown)", "PL_CINEMA_MULTIPLAYER_NO_MELTDOWN" },
	{ "Jack Howitzer", "PL_WEB_HOWITZER" },
	{ "Kung Fu Rainbow LazerForce", "PL_WEB_KFLF" },
	{ "Republican Space Rangers", "PL_WEB_RANGERS" },
	{ "CCTV", "PL_MP_CCTV" }
};