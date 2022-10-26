#pragma once

typedef DWORD Void;
typedef DWORD Any;
typedef DWORD uint;
typedef DWORD Hash;
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
	DWORD _paddingx;
	float y;
	DWORD _paddingy;
} Vector2;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	float x;
	DWORD _paddingx;
	float y;
	DWORD _paddingy;
	float z;
	DWORD _paddingz;
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
	DWORD _paddingx;
	float y;
	DWORD _paddingy;
	float z;
	DWORD _paddingz;
	float w;
	DWORD _paddingw;
} Vector4;
#pragma pack(pop)

struct Blip_t {
public:
	__int32 iID;
	__int8 iID2;
	char _0x0005[3];
	BYTE N000010FB;
	char _0x0009[7];
	Vector3 coords;
	char _0x001C[6];
	BYTE bFocused;
	char _0x0023[5];
	char* szMessage;
	char _0x0030[16];
	int iIcon;
	char _0x0044[4];
	DWORD dwColor;
	char _0x004C[4];
	float fScale;
	__int16 iRotation;
	BYTE bInfoIDType;
	BYTE bZIndex;
	BYTE bDisplay;
	BYTE bAlpha;
};