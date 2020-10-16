#pragma once
#include "Qualities.h"
#include "MapEnums.h"
#include "Structs.h"
#pragma pack(push,4)
// struct CEpochItemScript
class EpochItemScript {

public:
	/*int * vfptr1;
	int _type;                                                   // int m_nType;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _strName;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_strName;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _strKoreanName;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_strKoreanName;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _strImageName;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_strImageName;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _strItemLargeImage;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_strItemLargeImage;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _strImageName2;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_strImageName2;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _strItemLargeImage2;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_strItemLargeImage2;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _strImageName3;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_strImageName3;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _strItemLargeImage3;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_strItemLargeImage3;
	int _attackAni;                                              // int m_nAttackAni;
	std::map<int, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<int>, std::allocator<std::pair<int const, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > > _mapEquipMesh;// std::map<int,std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::less<int>,std::allocator<std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > m_mapEquipMesh;
	std::map<int, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<int>, std::allocator<std::pair<int const, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > > _mapEquipMeshChange;// std::map<int,std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::less<int>,std::allocator<std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > m_mapEquipMesh_Change;
	int _itemEntityType;                                         // int m_nItemEntityType;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _material1;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_Material1;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _material2;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_Material2;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _equipSound;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_szEquipSound;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _dropSound;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_szDropSound;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _pickUpsound;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_szPickUpsound;
	int _decoLevel;                                              // int m_DecoLevel;
	int _levelEnchantPrice[3];                                   // int m_nLevelEnchantPrice[3];
	int _levelEnchantRate[3];                                    // int m_nLevelEnchantRate[3];
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _strRegion;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_strRegion;
	int _maxlevel;                                               // int m_nMaxlevel;
	int _minLevel;                                               // int m_nMinLevel;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _strExplain;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_strExplain;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _strExplainFileName;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_strExplainFileName;
	int * _addonBuildingType;            // eSIEGE_ADDON_BUILDING_TYPE_FOR_ITEM m_AddonBuildingType;
	SITEMOPTIONATTR _itemOptionAttr[2];                          // SITEMOPTIONATTR m_ItemOptionAttr[2];
	CQualities _attribute;                                        // CQualities m_attribute;
	CQualities _option;                                           // CQualities m_option;
	int _initStatus[6];                                          // int m_bInitStatus[6];
	int _guildBankFee;                                           // int m_nGuildBankFee;
	__int16 _attributeType[6];                                   // __int16 m_nAttributeType[6];
	*/
	int GetItemEntity()
	{
		return *(int*)((char*)this + 0x00000104);
	}
	int GetAttr(int nAttributeType)
	{

		int(__thiscall *GetAttr)(void*, int nAttributeType) = (int(__thiscall*)(void*, int nAttributeType))0x006799E0;
		return GetAttr(this, nAttributeType);
	}
	bool IsArmor()
	{
		int nItemType = GetAttr(Itemattributetype::IAT_ITEM_TYPE);
		if (nItemType >= Itemtype::IT_ARMOR_START && nItemType <= Itemtype::IT_ARMOR_END)
			return true;
		return false;
	}
	bool IsShield()
	{
		return GetAttr(Itemattributetype::IAT_ITEM_TYPE) == Itemtype::IT_SHIELD;
	}
	bool IsWeapon()
	{
		int nItemType = GetAttr(Itemattributetype::IAT_ITEM_TYPE);
		if (nItemType >= Itemtype::IT_WEAPON_START && nItemType <= Itemtype::IT_WEAPON_END)
			return true;
		return false;
	}
};
#pragma pack(pop)