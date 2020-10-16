#pragma once
#include "Structs.h"
class CRegionAndRoomManager
{
public:
	static CRegionAndRoomManager * GetInstance()
	{
		auto GetInstance = (CRegionAndRoomManager *(__cdecl*)())0x00671390;
		return GetInstance();
	}
	int IsInWorldCupZone(EpochVector3 *vPos)
	{
		auto IsInWorldCupZone = (int(__thiscall*)(void*, EpochVector3 *vPos))0x006725E0;
		return IsInWorldCupZone(this, vPos);
	}
	static char IsInDungeon(unsigned int WorldSectionIndex_X, unsigned int WorldSectionIndex_Z)
	{
		auto IsInDungeon = (char(__stdcall*)(unsigned int WorldSectionIndex_X, unsigned int WorldSectionIndex_Z))0x00672460;
		return IsInDungeon(WorldSectionIndex_X, WorldSectionIndex_Z);
	}
	static char IsInInstRegion(EpochVector3 *vPos)
	{
		auto IsInInstRegion = (char(__stdcall*)(EpochVector3 *vPos))0x00672C70;
		return IsInInstRegion(vPos);
	}
	unsigned int GetRoomIndex(float x, float z)
	{
		auto GetRoomIndex = (unsigned int(__thiscall*)(void*, float x, float z))0x00672230;
		return GetRoomIndex(this, x, z);
	}
	void GetRegionAndRoomIndex(float x, float z, int *RegionIndex, int *RoomIndex)
	{
		auto GetRegionAndRoomIndex = (void(__thiscall*)(void*, float x, float z, int *RegionIndex, int *RoomIndex))0x00670A40;
		return GetRegionAndRoomIndex(this, x, z, RegionIndex, RoomIndex);
	}
	void GetRegionAndRoomIndex2(float x, float z, unsigned int *RegionIndex, unsigned int *RoomIndex)
	{
		auto GetRegionAndRoomIndex = (void(__thiscall*)(void*, float x, float z, unsigned int *RegionIndex, unsigned int *RoomIndex))0x006722E0;
		return GetRegionAndRoomIndex(this, x, z, RegionIndex, RoomIndex);
	}
};