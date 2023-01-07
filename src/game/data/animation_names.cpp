#include "game_data.hpp"

namespace Cheat
{
	const std::vector<game_data::AnimationsS> game_data::Animations = {
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
	const std::vector<std::string> game_data::AnimationsDisplayNames = {
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
}