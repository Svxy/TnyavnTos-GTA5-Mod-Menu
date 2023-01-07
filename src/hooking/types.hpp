#pragma once

typedef unsigned long Void;
typedef unsigned long Any;
typedef unsigned long uint;
typedef unsigned long Hash;
typedef int Entity;
typedef int Player;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int Cam;
typedef int CarGenerator;
typedef int Group;
typedef int Train;
typedef int Pickup;
typedef int Object;
typedef int Weapon;
typedef int Interior;
typedef int Blip;
typedef int Texture;
typedef int TextureDict;
typedef int CoverPoint;
typedef int Camera;
typedef int TaskSequence;
typedef int ColourIndex;
typedef int Sphere;
typedef int ScrHandle;

#pragma pack(push, 1)
typedef struct
{
	float x;
	float y;
} Vector2;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	float w;
	float h;
} Vector2_2;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	float x;
	unsigned long _paddingx;
	float y;
	unsigned long _paddingy;
	float z;
	unsigned long _paddingz;
} Vector3;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	float x;
	float y;
	float z;
} Vector3_t;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	float x;
	unsigned long _paddingx;
	float y;
	unsigned long _paddingy;
	float z;
	unsigned long _paddingz;
	float w;
	unsigned long _paddingw;
} Vector4;
#pragma pack(pop)