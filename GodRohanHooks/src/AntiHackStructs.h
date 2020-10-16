#pragma once
#pragma pack(push,1)
struct _tagEpochID2
{
	int type;
	int id;
	
};

struct _questcheckissub
{
	_tagEpochID2 id;
	char nInventory;
	char nSlot;
};

struct _tagITEM_INFO
{
	_tagEpochID2 id;
	char nInventory;
	char nSlot;


};
struct _tagMATERIAL_INFO
{
	unsigned int dwItemType;
	_tagITEM_INFO Material1;
	_tagITEM_INFO Material2;
	_tagITEM_INFO Option1;
	_tagITEM_INFO Option2;
};
struct _tagGR_ITEMOPTION {
	char nType;                                               // char nType;
	__int16 nValue;                                           // __int16 nValue;
};
struct __tagItem {
	_tagEpochID2 id;  
	                                        // _tagEpochID2 id;
															  //union $A984B0A807735FDE680E0B93BDA7EBB0
	union {
		char pItemAttr[42];                                   // char pItemAttr[42];
		_tagGR_ITEMOPTION option[14];                          // _tagGR_ITEMOPTION option[14];
	} u1;


	char nInventory;
	char nSlot;
	char nStack;
	char nRank;
	char nEquipLevel;
	__int16 nEquipStrength;
	__int16 nEquipDexterity;
	__int16 nEquipIntelligence;
	void Init()
	{

		void(__thiscall *Init)(void*) = (void(__thiscall*)(void*))0x004160E0;//(0x004146A0) 0x004160E0
		return Init(this);
	}
};
struct _tagMATERIAL_INFO_1
{
	unsigned int dwItemType;
	_tagITEM_INFO Material1;
	_tagITEM_INFO Material2;
	_tagITEM_INFO Option1;
	_tagITEM_INFO Option2;
	_tagITEM_INFO ConserStone;
};
struct _rcmRequestMapGuildBankMoveStack
{
	unsigned int dwNpcID;
	unsigned int dwFromItemId;
	char nFromInven;
	char nFromSlot;
	unsigned int dwToItemId;
	char nToInven;
	char nToSlot;
	char nCount;

};

struct _tagRequestMAP_COMPOSITION_POTION_1
{
	unsigned int dwNpcID;
	char nCount;
	_tagMATERIAL_INFO Material[10];
};
struct _tagRequestMAP_COMPOSITION_POTION_2
{
	unsigned int dwNpcID;
	_tagMATERIAL_INFO Material;

};
struct _tagRequestMAP_COMPOSITION_POTION_CONSER {
	unsigned int dwNpcID;
	char nCount;
	_tagMATERIAL_INFO Material[10];
};
struct _tagRequestMAP_PRODUCTION_EXTRACTION
{
	_tagITEM_INFO ItemInfo;
	_tagEpochID2 NpcId;
};
struct _rcmRequestMapMoveStackItem
{
	_tagITEM_INFO fromItem;
	_tagITEM_INFO toItem;
	char nMoveCount;
};
struct _tagRequestMAP_ITEM_UPGRADE_CONSER
{
	unsigned int dwNpcID;
	unsigned int dwMakeItem;
	_tagITEM_INFO Material[3];

};
struct _tagRequestMAP_COMPOSITION_SETITEM_CONSER
{
	_tagEpochID2 npcID;
	_tagMATERIAL_INFO_1 Material[5];
};
struct _tagRequestMAP_COMPOSITION_SHIELD_CONSER
{
	_tagEpochID2 npcID;
	_tagMATERIAL_INFO_1 Material;
};
struct _tagRequestMAP_COMPOSITION_ITEM_CONSER
{
	_tagEpochID2 npcID;
	_tagMATERIAL_INFO_1 Material;
};
struct _tagRequestMAP_PRODUCTION_REGISTER_RECIPE
{
	EpochID2 itemID;
	char nInventory;
	char nSlot;
};

struct _tagCOMPLETIONQUESTINFO
{
	int nID;
	char nCompletion;
};

struct _tagGR_SUBQUESTINFO
{
	unsigned __int16 nCount;
	char bReward;
};


struct _tagGR_SUBQUESTINFO_1
{
	unsigned __int16 nCount;
	char bReward;
	unsigned __int16 nTimer;
};

struct _tagQuestInfo3
{
	int nQuestID;
	char bCompletion;
	_tagGR_SUBQUESTINFO SubQuest[10];
};

struct _tagQuestInfo3_1
{
	int nQuestID;
	char bCompletion;
	unsigned __int16 nMainTimer;
	_tagGR_SUBQUESTINFO_1 SubQuest[10];
	char nCompletion;
};
	
struct QuestTimer
{
	int m_nlimitTime;
	int m_nLastSendPercentTime;
	unsigned int m_BeginTime;
	int m_nSavedMins;
	int m_nSavedMinsInitial;
};

struct stGetItemGiver
{
	unsigned int Types;
	char DropPercent;
};


struct CTimer
{
	unsigned int m_dwTimer;
};







#pragma pack(pop)
