#pragma once
#pragma pack (push,4)
struct _tagRohanItemRecipeInfo {
	int disable;                                             // int m_Disable;
	int iD;                                                  // int m_ID;
	char name[50];                                           // char m_Name[50];
	char koreanName[50];                                     // char m_KoreanName[50];
	int itemType;                                            // int m_ItemType;
	int description;                                         // int m_Description;
	int weight;                                              // int m_Weight;
	int price;                                               // int m_Price;
	int sellPrice;                                           // int m_SellPrice;
	int maxStack;                                            // int m_MaxStack;
	int attributeType[4];                                    // int m_AttributeType[4];
	int attributeValue[4];                                   // int m_AttributeValue[4];
	char imageName[50];                                      // char m_ImageName[50];
	int itemEntity;                                          // int m_ItemEntity;
	char equipSound[50];                                     // char m_szEquipSound[50];
	char dropSound[50];                                      // char m_szDropSound[50];
	char itemExplain[256];                                   // char m_szItemExplain[256];
	char itemLargeImage[50];                                 // char m_szItemLargeImage[50];
	char explainFileName[50];                                // char m_szExplainFileName[50];
	int craftSkill;                                          // int m_CraftSkill;
	int leanLevel;                                           // int m_LeanLevel;
};
struct _tagATTACHSOCKETRATEINFO {
	int disable;                                             // int nDisable;
	int itemType;                                            // int nItemType;
	int attachSocketRate5;                                   // int nAttachSocketRate5;
	int attachSocketRate4;                                   // int nAttachSocketRate4;
	int attachSocketRate3;                                   // int nAttachSocketRate3;
	int attachSocketRate2;                                   // int nAttachSocketRate2;
	int attachSocketRate1;                                   // int nAttachSocketRate1;
	int attachSocketRate0;                                   // int nAttachSocketRate0;
};
struct _tagItemWarRewardInfo
{
	int iD;                                                  // int nID;
	int warAreaIndex;                                        // int nWarAreaIndex;
	int warType;                                             // int nWarType;
	int rewardItem;                                          // int nRewardItem;
};
struct _tagROHANITEMMALLINFO
{
	int mallID;                                              // int m_MallID;
	char name[50];                                           // char m_Name[50];
	char koreanName[50];                                     // char m_KoreanName[50];
	int inventoryCount;                                      // int m_InventoryCount;
};
struct _tagBEGINITEMINFO
{
	int playerRace;                                          // int nPlayerRace;
	int itemType;                                            // int nItemType;
	int itemCount;                                           // int nItemCount;
};
struct _tagItemPCEventInfo
{
	int itemID;                                              // int m_ItemID;
};
#pragma pack(pop)