#pragma once
#include "stdafx.h"
#include "EpochItem.h"
#include "Pet.h"
#include "PlayerMapMemo.h"
#include "InventoryState.h"
#include "AliveCall.h"
#include "TimerItemManager.h"
#include "NGuildPlayerQueue.h"
#include "GambleInfo.h"
#include "RecipeManager.h"
#include "PlayerSocketManager.h"
#include "PostItemBox.h"
#include "Toolset.h"
#include "MapEnums.h"
#include "PlayerExtensions.h"
#include "EpochItemScriptManager.h"
class CCrime;
// struct CPlayer
#pragma pack(push,8)
class CPlayer : public CBiotic {

public:
	StateID2 * GetAction()
	{
		return (StateID2*)((char*)this + 0x0000008C);
	}
	int GetIRID()
	{
		return *(int*)((char*)this + 0x00000020);
	}


	


	void BroadcastTeleport(EpochVector3 *pos)
	{
		auto BroadcastTeleport = (void(__thiscall*)(void*, EpochVector3 *pos))0x004DAB40;
		return BroadcastTeleport(this, pos);
	}
	inline EpochItem * GetRidingItem()
	{
		return (EpochItem*)*(int*)((char*)this + 0x19C0u);
	}
	inline int HasDungeonVehicleOn()
	{
		return *(int*)((char*)this + 0x00001DC4);
	}
	inline int UseRidingItem(EpochItem *pItem, int bOnOff)
	{
		auto UseRidingItem = (int(__thiscall*)(void*, EpochItem *pItem, int bOnOff))0x00508380;
		return UseRidingItem(this, pItem, bOnOff);
	}
	inline __int64 GetMoney()
	{
		auto GetMoney = (__int64(__thiscall*)(void*))0x00416370;
		return GetMoney(this);
	}
	inline unsigned char GetGrade()
	{
		return *(unsigned char *)((char*)this + 0x000000FC);
	}
	inline PlayerItemSlotManager * GetPlayerItemSlotManager()
	{
		return (PlayerItemSlotManager*)((char*)this + 0x00000CC8);
	}
	void AddIndunPoint(__int64 nDiff, char nReason, int bClient)
	{
		auto AddIndunPoint = (void(__thiscall*)(void*, __int64 nDiff, char nReason, int bClient))0x004FB6B0; //(0x004E39D0)
		return AddIndunPoint(this, nDiff, nReason, bClient);
	}
	RohanConnection * GetConnection()
	{
		return (RohanConnection*)*(int*)((char*)this + 0x00001098);
	}
	int GetUserId()
	{
		return *(int*)((char*)this + 0x19DC);
	}

	CCrime * GetCCrime()
	{
		return (CCrime*)*(int*)((char*)this + 0x00001A18);
	}
	PlayerExtensions * GetPlayerExtensions()
	{
		return (PlayerExtensions*)*(int*)((char*)this + 0x2058u);
	}



	void DeletePlayerExtension();
	void SetPlayerExtensions(PlayerExtensions * extsn);
	/*
	__int64 * GetMoney()
	{
		auto GetMoney = (__int64 * (__thiscall*)(void*))0x004286B0;
		return GetMoney(this);
	}*/


	PlayerItemSlotManager * CreateItem(int nType, char item, int nStack)
	{
		PlayerItemSlotManager *(__thiscall *GetItem)(void*, int nType, char item, int nStack) = (PlayerItemSlotManager *(__thiscall*)(void*, int nType, char item, int nStack))0x006998B0;//(0x0063F1B0) 0x006998B0
		return GetItem(this, nType, item, nStack);
	}




	int _prisontiming()
	{
		auto _prisontiming = (int(__thiscall*)(void*))0x00646020;
		return _prisontiming(this);
	}






	void AddMoney(__int64 nDiff, char nReason, int bClient)
	{
		auto AddMoney = (void(__thiscall*)(void*, __int64 nDiff, char nReason, int bClient))0x004FB140;//(0x004E3460) 0x004FB140
		return AddMoney(this, nDiff, nReason, bClient);
	}





	void SubMoney(__int64 nDiff, char nReason, int bClient)
	{
		auto SubMoney = (void(__thiscall*)(void*, __int64 nDiff, char nReason, int bClient))0x004FB420;// (0x004E3740) 0x004FB420  
		return SubMoney(this, nDiff, nReason, bClient);
	}
	BOOL IsInDuckDungeon()
	{
		auto IsInDuckDungeon = (BOOL(__thiscall*)(void*t))0x0050E130;// (0x004F5140) 0x0050E130
		return IsInDuckDungeon(this);

	}




	
	char * GetName()
	{
		auto CheckWorkItem = (char * (__thiscall*)(void*))0x004F02A0; //(0x004D9100) 0x004F02A0
		return CheckWorkItem(this);
	}







	void BroadcastPetLevelUp(int nLevel)
	{

		void(__thiscall *BroadcastPetLevelUp)(void*, int nLevel) = (void(__thiscall*)(void*, int nLevel))0x0050CEA0;//  (0x004F3EB0) 0x0050CEA0
		return BroadcastPetLevelUp(this, nLevel);
	}
	void BroadcastIncAbility()
	{

		void(__thiscall *BroadcastIncAbility)(void*) = (void(__thiscall*)(void*))0x004F86B0; //(0x004E0A80) 0x00F86B0
		return BroadcastIncAbility(this);
	}
	void CalAllAbility()
	{

		void(__thiscall *CalAllAbility)(void*) = (void(__thiscall*)(void*))0x004F2C00; // (0x004DBAB0) 0x004F2C00
		return CalAllAbility(this);
	}
	void SendStatus()
	{

		void(__thiscall *SendStatus)(void*) = (void(__thiscall*)(void*))0x004F2860; //(0x004DB710) 0x004F2860
		return SendStatus(this);
	}




	BOOL IsInParty()
	{
		auto CheckUser = (BOOL(__thiscall*)(void*f))0x00543F50;
		return CheckUser(this);

	}




	/*BOOL IsBuddy(unsigned int dwPartyLeaderID, unsigned int GetID)
	{
		auto CheckUser = (BOOL(__thiscall*)(void*, unsigned int dwPartyLeaderID, unsigned int getid))0x0045A620;
		return CheckUser(this, dwPartyLeaderID, GetID);

	}*/


	static void InitPlayerHooks(HMODULE hModule);
	static void ApplyHooks(HMODULE hModule);
};
#pragma pack(pop)