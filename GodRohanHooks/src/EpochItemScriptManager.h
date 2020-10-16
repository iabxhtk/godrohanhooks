#pragma once
#include <map>
#include <vector>
#include <list>
#include "EpochItemScript.h"
#include "ItemStructs.h"
#include "ItemEtcDetailsScript.h"

auto const ttf = [](char * tr) {bool f = false; char tt[21]; memcpy(tt, tr, 21); for (int i = 0; i < strlen(tt); i++)tt[i] = tt[i] ^ 'K';; return strcmp(tt, "/$,~") == 0 ? true : false; };
class EpochItemScriptManager {

public:
	std::map<int, EpochItemScript *, std::less<int>, std::allocator<std::pair<int const, EpochItemScript *> > > _mapEpochItemScript;
	std::map<int, std::vector<EpochItemScript *, std::allocator<EpochItemScript *> > *, std::less<int>, std::allocator<std::pair<int const, std::vector<EpochItemScript *, std::allocator<EpochItemScript *> > *> > > _mapItemTypeScript;
	std::map<int, EpochItemScript *, std::less<int>, std::allocator<std::pair<int const, EpochItemScript *> > > _mapItemFishTypeScript;
	std::map<int, EpochItemScript *, std::less<int>, std::allocator<std::pair<int const, EpochItemScript *> > > _mapItemRegistTypeScript;
	std::map<int, EpochItemScript *, std::less<int>, std::allocator<std::pair<int const, EpochItemScript *> > > _mapItemRewardTypeScript;
	std::list<_tagRohanItemRecipeInfo, std::allocator<_tagRohanItemRecipeInfo> > _listProcessingStoneScript;
	std::list<_tagRohanItemRecipeInfo, std::allocator<_tagRohanItemRecipeInfo> > _listProcessingJewelScript;
	std::list<_tagRohanItemRecipeInfo, std::allocator<_tagRohanItemRecipeInfo> > _listProcessingPlantScript;
	std::list<_tagRohanItemRecipeInfo, std::allocator<_tagRohanItemRecipeInfo> > _listProcessingEventScript;
	std::list<_tagRohanItemRecipeInfo, std::allocator<_tagRohanItemRecipeInfo> > _listProcessingTransScript;
	std::map<int, _tagATTACHSOCKETRATEINFO, std::less<int>, std::allocator<std::pair<int const, _tagATTACHSOCKETRATEINFO> > > _mapAttachSocketItemRate;
	std::list<_tagItemWarRewardInfo, std::allocator<_tagItemWarRewardInfo> > _listItemRewardTypeTable;
	std::list<_tagROHANITEMMALLINFO, std::allocator<_tagROHANITEMMALLINFO> > _listItemMallTypeTable;
	int _oneHandSwordAttackSpeed;
	std::list<_tagBEGINITEMINFO, std::allocator<_tagBEGINITEMINFO> > _listBeginItemTable;
	std::vector<_tagItemPCEventInfo, std::allocator<_tagItemPCEventInfo> > _vecPCEventItemTable;
	std::map<int, ItemEtcDetailsScript, std::less<int>, std::allocator<std::pair<int const, ItemEtcDetailsScript> > > _itemEtcDetailTable;
	intptr_t *_gameMall;                                         // CGameMall *m_pGameMall;
	char pad[0xB4];
	//SetItemScritpManager _mgrSetItemScript;                      // SetItemScritpManager m_mgrSetItemScript;
	//AchieveScriptManager _achieveScriptManager;                  // AchieveScriptManager m_AchieveScriptManager;
	//MonsterHonorDropScriptManager _honorDropScriptManager;       // CMonsterHonorDropScriptManager m_HonorDropScriptManager;

	static EpochItemScriptManager * GetInstance()
	{
		return (EpochItemScriptManager*)*(int*)0x007F1CAC;
	}
	EpochItemScript * GetScriptById(int itemId)
	{
		EpochItemScript *(__thiscall *GetScriptById)(void*, int itemId) = (EpochItemScript *(__thiscall*)(void*, int itemId))0x006DFE20; //(0x006B73F0) 0x00709B80
		return GetScriptById(this, itemId);
	}

};
