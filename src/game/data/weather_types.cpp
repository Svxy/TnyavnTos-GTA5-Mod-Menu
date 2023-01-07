#include "game_data.hpp"

namespace Cheat
{
	const std::vector<game_data::WeatherTypesS> game_data::WeatherTypes = {
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
}