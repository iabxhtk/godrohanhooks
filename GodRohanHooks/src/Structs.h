#pragma once



#pragma pack(push, 1)
struct EpochID2//8
{
	int type;
	int id;
};



struct tagRequestCOMMGMNOTICE {
	short type = 7945;
	short size;
	char gmMsgType;                                               // char nType;
	__int16 len;                                             // __int16 nLen;
	char msg[256];                                             // char szMsg[1];
};
struct _tagRequestMAP_BUYITEMFROMNPC_2Broken {
	EpochID2 npcID;                                       // _tagEpochID2 npcID;
	EpochID2 itemID;                                      // _tagEpochID2 itemID;
	char inventory;                                          // char nInventory;
	char slot;                                               // char nSlot;
	char something;
	char count;                                              // char nCount;
	char magic;                                              // char bMagic;
	char buyTaxRate;                                         // char nBuyTaxRate;
};
struct _tagRequestMAP_BUYITEMFROMNPC_2 {
	EpochID2 npcID;                                       // _tagEpochID2 npcID;
	EpochID2 itemID;                                      // _tagEpochID2 itemID;
	char inventory;                                          // char nInventory;
	char slot;                                               // char nSlot;
	char count;                                              // char nCount;
	char magic;                                              // char bMagic;
	char buyTaxRate;                                         // char nBuyTaxRate;
};
struct _tagGR_MAP_MEMO {
	unsigned __int16 xPos;                                   // unsigned __int16 xPos;
	unsigned __int16 yPos;                                   // unsigned __int16 yPos;
	int sectionID;                                           // int nSectionID;
	char memo[31];                                           // char szMemo[31];
};
struct packet_53523 {
	char pad;
	int pad1;
};
struct packet_53524 {
	char pad;
	int pad1;
	int timestamp;
};


struct _tagGR_ATTACKER {
	EpochID2 iD;                                          // _tagEpochID2 ID;
	char attackType;                                         // char nAttackType;
	unsigned __int16 skillKind;                              // unsigned __int16 nSkillKind;
	char skillLevel;                                         // char nSkillLevel;
	unsigned int useItemID;                                  // unsigned int dwUseItemID;
	char itemCount;                                          // char nItemCount;
};

struct _tagGR_ATTACKEE {
	unsigned int lifeManaIndex;                              // unsigned int nLifeManaIndex;
	EpochID2 iD;                                          // _tagEpochID2 ID;
	int result;                                              // int nResult;
	int damage;                                              // int nDamage;
	int elementDamage;                                       // int nElementDamage;
	int curLife;                                             // int nCurLife;
	int curMana;                                             // int nCurMana;
	__int16 level;                                           // __int16 nLevel;
	char skillAffect;                                        // char bSkillAffect;
};
#pragma pack(pop)

class CBiotic;
#pragma pack(push, 4)
struct STRADEITEM
{
	int nGrade;
	int pScript;
};
struct SBATTLECONTEXT
{
	unsigned int bWeaponHit;
	unsigned int bCriticalHit;
	unsigned int bIgnoreDefence;
	unsigned int bUseRevisionDamage;
	unsigned int nRectTypeDamageCount;
	unsigned int nAllinshotUsecount;
	unsigned int nAllinshotArrowDamage;
	unsigned int nElementDamage;
	unsigned int nAttackeeIndex;
	unsigned int nUseGhostArrow;
	CBiotic * pAttackee;
};
struct SATTACKORDER
{
	unsigned int nBattleIndex;
	unsigned int dwAttackerID;
	unsigned int dwAttackeeID[10];
	char nAttackType;
	unsigned int nDurationTime;
	unsigned int dwStartTime;
	char nMissRate;
	char nCriticalRate;
	unsigned short nCriticalFactor;
	unsigned short nHitParam;
	unsigned short nHitRate;
	unsigned int nAttackRange;
	unsigned int nAttackForce;
	unsigned short wSkillKind;
	char nSkillLevel;
	unsigned int nElementForce;
	unsigned int dwUseItemID;
	char nUseItemCount;
	int bIsSkillAttack;
};
struct SATTACKRESULT
{
	unsigned int nBattleIndex;
	_tagGR_ATTACKER attacker;
	char nAttackeeCount;
	_tagGR_ATTACKEE attackee[10];
	unsigned int nTotalDamage[10];
	unsigned int nReflectDamage[10];
	char nUseItemCount;
	unsigned int bIsSkillAttack;
};
#pragma pack(pop)
#pragma pack(push,1)
struct _tagRequestINCABILITY
{
	int nChar;
	__int16 nAbilityPoint;
	__int16 nStrength;
	__int16 nDexterity;
	__int16 nIntelligence;
	__int16 nMentality;
	__int16 nHealth;
	__int16 nQuickness;
};
struct _rcmRequestMapIncreaseMultipleAbility
{

	unsigned __int32 abiType;
	unsigned __int16  count;
};
struct timePacket
{
	int sec;
	int min;
	int hour;
	int day;
	int month;
	int year;
	int s1;
	int s2;
	int s3;
	int s4;
};
struct tagSkillLevelInfo {
	char learnLevel;                                         // char nLearnLevel;
	unsigned __int16 castingMana;                            // unsigned __int16 nCastingMana;
	unsigned __int16 castingTime;                            // unsigned __int16 nCastingTime;
	unsigned __int16 skillAniTime;                           // unsigned __int16 nSkillAniTime;
	unsigned __int16 manaPerSec;                             // unsigned __int16 nManaPerSec;
	unsigned int durationTime;                               // unsigned int nDurationTime;
	unsigned int coolingTime;                                // unsigned int nCoolingTime;
	unsigned int param[5];                                   // unsigned int nParam[5];
	char affectDescription[128];                             // char szAffectDescription[128];
	char description[128];                                   // char szDescription[128];
	char explainFileName[128];                               // char szExplainFileName[128];
};
struct _tagSkillInfo {
	unsigned __int16 kind;                                   // unsigned __int16 nKind;
	char korName[40];                                        // char szKorName[40];
	char engName[40];                                        // char szEngName[40];
	char type;                                               // char nType;
	char subType;                                            // char nSubType;
	int target;                                              // int nTarget;
	tagSkillLevelInfo levelInfo[7];                          // _tagSkillLevelInfo nLevelInfo[7];
	char description[128];                                   // char szDescription[128];
	char iconFileName[30];                                   // char szIconFileName[30];
	char iconPushFileName[30];                               // char szIconPushFileName[30];
	char iconSmallFileName[30];                              // char szIconSmallFileName[30];
	char iconLargeFileName[30];                              // char szIconLargeFileName[30];
	int range;                                               // int nRange;
	int countinuousAttack;                                   // int bCountinuous_Attack;
	int assistance;                                          // int bAssistance;
	char iconAffectFileName[30];                             // char szIconAffectFileName[30];
	char affectDescription[128];                             // char szAffectDescription[128];
	char iconAffectSmallFileName[30];                        // char szIconAffectSmallFileName[30];
	char addPoint;                                           // char nAddPoint;
	int addPointProbability;                                 // int nAddPointProbability;
	int addPointProbability2;                                // int nAddPointProbability2;
	unsigned int timeFlag;                                   // unsigned int nTimeFlag;
};
struct EpochVector3
{
	float x;
	float y;
	float z;
};



struct _tagAffectSkill {
	unsigned __int16 kind;                                   // unsigned __int16 nKind;
	char level;                                              // char nLevel;
	unsigned int affectTime;                                 // unsigned int nAffectTime;
	unsigned int eventTime;                                  // unsigned int nEventTime;
	char eventType;                                          // char nEventType;
	unsigned int durationTime;                               // unsigned int dwDurationTime;
	unsigned int entityID;                                   // unsigned int dwEntityID;
	EpochVector3 pos;                                     // _tagEpochVector3 Pos;
};

struct tagITEMINFO {
	EpochID2 id;                                          // _tagEpochID2 id;
	char inventory;                                          // char nInventory;
	char slot;                                               // char nSlot;
};
struct tagSkill {
	unsigned __int16 kind;                                   // unsigned __int16 nKind;
	char level;                                              // char nLevel;
	char point;                                              // char nPoint;
	char state;                                              // char nState;
	unsigned int eventTime;                                  // unsigned int nEventTime;
	char addPoint;                                           // char nAddPoint;
	unsigned int expireTime;                                 // unsigned int nExpireTime;
};
struct SENDAFFECTSKILL
{
	short wKind;
	char nReason;
	char padddd;
	int dwParam;
	int dwSkiller;
};
struct SEndSkill
{
	short sk_kind;
	char pad[2];
	int end_reason;
};
struct SITEMOPTIONATTR {
	int nType;
	int nMin;
	int nMax;
};
struct _tagGOPacket
{
	unsigned __int16 type;                                   // unsigned __int16 type;
	unsigned __int16 size;                                   // unsigned __int16 size;
	char data[1];                                            // char data[1];
};
struct tagGRITEMOPTION {
	char type;                                               // char nType;
	__int16 value;                                           // __int16 nValue;
};
struct tagItem {
	EpochID2 id;                                          // _tagEpochID2 id;
															  //union $A984B0A807735FDE680E0B93BDA7EBB0
	union {
		char pItemAttr[42];                                   // char pItemAttr[42];
		tagGRITEMOPTION option[14];                          // _tagGR_ITEMOPTION option[14];
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

		void(__thiscall *Init)(void*) = (void(__thiscall*)(void*))0x004146A0; //(0x004146A0) 
		return Init(this);
	}
};

struct responseBuyByBadges
{
	int zeros;
	tagItem mallItem;
	tagITEMINFO badge_guess;
	char badgeStack_guess;
};


struct tagItemInBasket {
	int type;                                                // int nType;
	char stack;                                              // char nStack;
};
struct tagBASKET {
	int questID;                                             // int nQuestID;
	char count;                                              // char nCount;
	unsigned int usedTime;                                   // unsigned int tUsedTime;
	tagItemInBasket items[16];                               // _tagItemInBasket Items[16];
};

struct tagGRHONORPVPPOINT {
	__int16 killCount;                                       // __int16 killCount;
	__int16 deathCount;                                      // __int16 deathCount;
	__int16 connectPoint;                                    // __int16 connectPoint;
	__int64 cronPoint;                                       // __int64 cronPoint;
};

struct tagP2PCHATREQUEST {
	unsigned int requestTime;                                // unsigned int dwRequestTime;
	char targetName[21];                                     // char szTargetName[21];
};
struct _tagRcReqBeginSkill
{

	char bBegin;
	unsigned __int16 wKind;
	unsigned int dwTargetId;
	bool bCtrlKey;
	EpochVector3 pos;

};
#pragma pack(pop)
#pragma pack(push,2)
struct tagGRPRIVATESHOPINFO {
	char sellerName[21];                                     // char szSellerName[21];
	tagItem item;                                            // __tagItem Item;
	__int64 price;                                           // __int64 nPrice;
	int locationIndex;                                       // int nLocationIndex;
};

struct tagResponseMAPPRIVATESHOPSEARCH {
	char result;                                             // char nResult;
	char count;                                              // char nCount;
	tagGRPRIVATESHOPINFO shopInfo[20];                       // _tagGR_PRIVATE_SHOP_INFO ShopInfo[20];
};
#pragma pack (pop)
struct   tagNewEntityItem
{
	EpochID2 id;
	char nInventory;
	char nSlot;
};
struct _tagGR_ENTITY_PLAYER
{
	char szName[21];
	char nHair;
	char nFace;
	char nRank;
	char nGuildGrade;
	int nActionState;
	char nPKState;
	int nPKSecond;
	int nPKPoint;
	char nWeightState;
	char nMode;
	tagNewEntityItem item[10];
	char nRidingState;
	unsigned int dwRidingType;
	int nRankMaster;
	char nStyleType;
	char nStyleIndex;
	char nSafePKTime;
	unsigned int dwOption;
	int nTitleID;
};

struct stItemOption
{
	int type;
	int value;
};

struct stItemData
{
	unsigned int item_id;
	unsigned __int16 item_num;
	bool no_limit_status;
	int random_opt_level;
	int fix_opt_num;
	stItemOption fix_opt[10];
};



struct stLadderReward
{
	unsigned int money;
	unsigned int exp;
	stItemData item;
};

struct Quest_Special_condition
{
	//Quest_Special_type condition_type;
	//$BDE2166B039AF696F5E0B1FDAB22AF5A ___u1;
	//$8F7BD7F63227ADDD2A7E4BE0D209B86A ___u2;
	//$76CA9BA396754DB3DD4EA33A6489A1DC ___u3;
	unsigned int param_4;
	unsigned int param_5;
};

union $BDE2166B039AF696F5E0B1FDAB22AF5A
{
	unsigned int param_1;
	unsigned int upper_quest_id;
	bool attitude_normal;
	int complete_quest_num;
	int acceptable_rank;
	unsigned int own_pet_type;
	int own_pet_level;
	bool own_pet_activate;
	bool guild_joined;
	bool guild_master;
	bool murderer;
	int pk_record_num;
	unsigned int learning_skill_id;
	unsigned int binded_index;
	char collect_skill_type;
	char product_skill_type;
	unsigned int normal_item_type_id;
	int reach_rank;
	bool become_murderer;
	int pk_new_record_num;
	unsigned int enchant_item_type_id;
	unsigned int new_binding_index;
	int guild_member_num;
	bool guild_warehouse_use;
	unsigned int prob_item_type_id;
	unsigned int buff_type_id;
	unsigned int initialize_type;
	unsigned int collect_exp_reward;
	int m_SpecialTitleID;
};

union $8F7BD7F63227ADDD2A7E4BE0D209B86A
{
	unsigned int param_2;
	int player_num;
	unsigned int collect_exp_min;
	unsigned int product_level_min;
	int normal_item_num;
	int enchant_type;
	int assign_probability;
	int buff_value;
};


union $76CA9BA396754DB3DD4EA33A6489A1DC
{
	unsigned int param_3;
	unsigned int collect_exp_max;
	unsigned int product_level_max;
	int enchant_value;
};