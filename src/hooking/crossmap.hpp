#pragma once
#include <unordered_map>

typedef std::unordered_map<uint64_t, uint64_t> nMap;

class crossmap
{
public:
	static void initNativeMap();
	static uint64_t MapNative(uint64_t inNative);
	static bool searchMap(nMap map, uint64_t inNative, uint64_t *outNative);
};