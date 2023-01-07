#include "game_data.hpp"

namespace Cheat
{
	const std::vector <game_data::TeleportLocation> game_data::TeleportLocationsSafehouses = {
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

	const std::vector<game_data::TeleportLocation> game_data::TeleportLocationsHighAltitude = {
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

	const std::vector<game_data::TeleportLocation> game_data::TeleportLocationsUnderwater = {
		{ "Dead Sea Monster", -3373.726f, 504.714f, -24.656f },
		{ "Humane Labs Tunnel", 3619.749f, 2742.740f, 28.690f },
		{ "Sunken Body", -3161.078f, 3001.998f, -37.974f },
		{ "Sunken Cargo Ship", 3199.748f, -379.018f, -22.500f },
		{ "Sunken Plane", -942.350f, 6608.752f, -20.912f },
		{ "Underwater Hatch", 4273.950f, 2975.714f, -170.746f },
		{ "Underwater UFO", 762.426f, 7380.371f, -111.377f },
		{ "Underwater WW2 Tank", 4201.633f, 3643.821f, -39.016f }
	};

	const std::vector<game_data::TeleportLocation> game_data::TeleportLocationsLandmarks = {
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
}