#include "stdafx.h"
#include "EntityManager.h"
#include "AdvancedHK.h"
std::unordered_map<int, int> AdvancedHK::armorStats{
	{ Itemoptiontype::IOT_PHYSICS_DEFENCE, 30 },
};
std::unordered_map<int, int> AdvancedHK::wandStaffStats{
	{ Itemoptiontype::IOT_INTELLIGENCE, 30 },
	{ Itemoptiontype::IOT_MENTALITY, 30 },
	{ Itemoptiontype::IOT_MAX_LIFE_RATE, 10 },
	{ Itemoptiontype::IOT_MAGIC_ATTACK_FORCE_RATE, 10 }
};
std::unordered_map<int, int> AdvancedHK::zhensStats{
	{ Itemoptiontype::IOT_MAX_LIFE_RATE, 10 },
	{ Itemoptiontype::IOT_MELEE_ATTACK_FORCE_RATE, 10 },
	{ Itemoptiontype::IOT_MAGIC_ATTACK_FORCE_RATE, 10 }
};
std::unordered_map<int, int> AdvancedHK::daggerStats{
	{ Itemoptiontype::IOT_INTELLIGENCE, 30 },
	{ Itemoptiontype::IOT_DEXTERITY, 30 },
	{ Itemoptiontype::IOT_QUICKNESS, 30 },
	{ Itemoptiontype::IOT_MENTALITY, 30 },
	{ Itemoptiontype::IOT_MAX_LIFE_RATE, 10 },
	{ Itemoptiontype::IOT_MELEE_ATTACK_FORCE_RATE, 10 }
};
std::unordered_map<int, int> AdvancedHK::katarStats{
	{ Itemoptiontype::IOT_QUICKNESS, 30 },
	{ Itemoptiontype::IOT_MAX_LIFE_RATE, 10 },
	{ Itemoptiontype::IOT_MELEE_ATTACK_FORCE_RATE, 10 }
};
std::unordered_map<int, int> AdvancedHK::swordAxePolearmDualSwordStats{
	{ Itemoptiontype::IOT_INTELLIGENCE, 30 },
	{ Itemoptiontype::IOT_MAX_LIFE_RATE, 10 },
	{ Itemoptiontype::IOT_MELEE_ATTACK_FORCE_RATE, 10 }
};
std::unordered_map<int, int> AdvancedHK::bowXbowStats{
	{ Itemoptiontype::IOT_MISSILE_ATTACK_FORCE_RATE, 10 },
	{ Itemoptiontype::IOT_MAX_LIFE_RATE, 10 },
};
std::unordered_map<int, int> AdvancedHK::accessoryStats{
	{ Itemoptiontype::IOT_STRENGTH, 25 },
	{ Itemoptiontype::IOT_HEALTH, 25 },
	{ Itemoptiontype::IOT_DEXTERITY, 25 },
	{ Itemoptiontype::IOT_QUICKNESS, 25 },
	{ Itemoptiontype::IOT_INTELLIGENCE, 25 },
	{ Itemoptiontype::IOT_MENTALITY, 25 }
};

int AdvancedHK::StringToOptionType(std::string & strOpt)
{
	if (strOpt == "melee")
		return Itemoptiontype::IOT_MELEE_ATTACK_FORCE_RATE;
	else if (strOpt == "magic")
		return Itemoptiontype::IOT_MAGIC_ATTACK_FORCE_RATE;
	else if (strOpt == "ranged")
		return Itemoptiontype::IOT_MISSILE_ATTACK_FORCE_RATE;
	else if (strOpt == "strength")
		return Itemoptiontype::IOT_STRENGTH;
	else if (strOpt == "intelligence")
		return Itemoptiontype::IOT_INTELLIGENCE;
	else if (strOpt == "psyche")
		return Itemoptiontype::IOT_MENTALITY;
	else if (strOpt == "dexterity")
		return Itemoptiontype::IOT_DEXTERITY;
	else if (strOpt == "agility")
		return Itemoptiontype::IOT_QUICKNESS;
	else if (strOpt == "vitality")
		return Itemoptiontype::IOT_HEALTH;
	else if (strOpt == "health")
		return Itemoptiontype::IOT_MAX_LIFE_RATE;
	else if (strOpt == "mana")
		return Itemoptiontype::IOT_MAX_MANA_RATE;
	else if (strOpt == "pdef")
		return Itemoptiontype::IOT_PHYSICS_DEFENCE;
	else if (strOpt == "mdef")
		return Itemoptiontype::IOT_MAGIC_DEFENCE;
	else
		return -1;
}
void AdvancedHK::SendNoticeMessageGreen(CPlayer * sendTo, std::string messageStringworld, char type)
{
	if (messageStringworld.length() > 0 && messageStringworld.length() < 256)
	{
		tagRequestCOMMGMNOTICE noticePacket;
		memset(noticePacket.msg, 0, 256);
		strncpy(noticePacket.msg, messageStringworld.c_str(), messageStringworld.length());
		noticePacket.gmMsgType = 3;
		noticePacket.size = 3 + messageStringworld.length();
		noticePacket.len = messageStringworld.length();

		_tagGOPacket* packet = (_tagGOPacket*)&noticePacket;
		CEntityManager * entityMgr = (CEntityManager*)0x007F8A60;// 0x00796908;
		entityMgr->BroadcastAllPlayer(7965, (void*)packet->data, packet->size);
		if (sendTo->GetConnection())
		{
			sendTo->GetConnection()->SendPacketEx(7968, (void*)packet->data, packet->size);
			sendTo->GetConnection()->SendPacketEx(7946, (void*)packet->data, packet->size);
		}




	}
}
void AdvancedHK::SendNoticeMessage(CPlayer * sendTo, std::string && messageString)
{
	struct _declspec(align(1)) gmNoticeRequest {
		short type = 7945;
		short size;
		char gmMsgType;                                               // char nType;
		__int16 len;                                             // __int16 nLen;
		char msg[120];                                             // char szMsg[1];
	};
	if (!sendTo)
		return;
	gmNoticeRequest noticePacket;
	memset(noticePacket.msg, 0, 120);
	strncpy(noticePacket.msg, messageString.c_str(), messageString.length());
	noticePacket.gmMsgType = 0;
	noticePacket.size = 3 + messageString.length();
	noticePacket.len = messageString.length();
	_tagGOPacket* packet = (_tagGOPacket*)&noticePacket;
	if (sendTo->GetConnection())
		sendTo->GetConnection()->SendPacketEx(7946, (void*)packet->data, packet->size);
}
int AdvancedHK::IsMaxStatInMap(tagItem & item, std::unordered_map<int, int> & itemStatsMap)
{
	for (int i = 0; i < 14; i++)
	{
		std::unordered_map<int, int>::iterator it = itemStatsMap.find(item.u1.option[i].type);
		if (it != itemStatsMap.end())
		{
			if (item.u1.option[i].value >= it->second)
				return 1;
		}
	}
	return 0;
}
void AdvancedHK::readXMLConfig()
{
	using namespace rapidxml;
	xml_document<> doc;
	xml_node<> * root_node;
	std::ifstream theFile("advancedhk.xml");
	if (!theFile.good())
	{
		std::cout << "Advanced hunter kit setting xml file not found! \n";
		return;
	}
	daggerStats.clear();
	accessoryStats.clear();
	katarStats.clear();
	bowXbowStats.clear();
	wandStaffStats.clear();
	swordAxePolearmDualSwordStats.clear();
	zhensStats.clear();
	std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');
	doc.parse<0>(&buffer[0]);
	root_node = doc.first_node("AdvancedHK");
	for (xml_node<> * item_node = root_node->first_node("Item"); item_node; item_node = item_node->next_sibling())
	{
		std::string itemType = item_node->first_attribute("type")->value();
		for (xml_node<> * stat_node = item_node->first_node("Stat"); stat_node; stat_node = stat_node->next_sibling())
		{
			int statType = StringToOptionType(std::string(stat_node->first_attribute("type")->value()));
			int statValue = std::stoi(stat_node->first_attribute("min_value")->value());
			if (statValue && statType != -1)
			{
				if (itemType == "dagger")
				{
					daggerStats.insert_or_assign(statType, statValue);
				}
				else if (itemType == "katar")
				{
					katarStats.insert_or_assign(statType, statValue);
				}
				else if (itemType == "crossbow" || itemType == "bow")
				{
					bowXbowStats.insert_or_assign(statType, statValue);
				}
				else if (itemType == "staff" || itemType == "wand")
				{
					wandStaffStats.insert_or_assign(statType, statValue);
				}
				else if (itemType == "zhen")
				{
					zhensStats.insert_or_assign(statType, statValue);
				}
				else if (itemType == "sword" || itemType == "dualsword" || itemType == "polearm" || itemType == "axe" || itemType == "mace")
				{
					swordAxePolearmDualSwordStats.insert_or_assign(statType, statValue);
				}
				else if (itemType == "accessory")
				{
					accessoryStats.insert_or_assign(statType, statValue);
				}
				else if (itemType == "armor")
				{
					armorStats.insert_or_assign(statType, statValue);
				}
			}
			else
			{
				std::cout << "AdvancedHK config:: wrong stat !!" << stat_node->first_attribute("type")->value() << "\n";
			}
		}
	}
}
int AdvancedHK::IsMaxItem(EpochItem * pickedItem)
{
	if (pickedItem)
	{
		if (pickedItem->GetAttribute(Itemattributetype::IAT_DESCRIPTION) == 0)
		{
			int itemType = (pickedItem->GetAttribute(Itemattributetype::IAT_ITEM_TYPE));
			tagItem item;
			item.Init();
			pickedItem->GetItemGR(&item);
			switch (itemType)
			{
			case Itemtype::IT_WEAPON_ONEHAND_SWORD:
			case Itemtype::IT_WEAPON_TWOHAND_SWORD:
			case Itemtype::IT_WEAPON_ONEHAND_AXE:
			case Itemtype::IT_WEAPON_TWOHAND_POLLARM:
			case Itemtype::IT_WEAPON_ONEHAND_CLUB:
			{
				return IsMaxStatInMap(item, swordAxePolearmDualSwordStats);
			}
			case Itemtype::IT_WEAPON_TWOHAND_STAFF:
			case Itemtype::IT_WEAPON_ONEHAND_WAND:
			{
				return IsMaxStatInMap(item, wandStaffStats);
			}
			case Itemtype::IT_WEAPON_CROSS_BOW:
			case Itemtype::IT_WEAPON_BOW:
			{
				return IsMaxStatInMap(item, bowXbowStats);
			}
			case Itemtype::IT_WEAPON_DAGGER:
			{
				return IsMaxStatInMap(item, daggerStats);
			}
			case Itemtype::IT_WEAPON_TWOHAND_KATAR:
			{
				return IsMaxStatInMap(item, katarStats);
			}
			case Itemtype::IT_WEAPON_TWOHAND_ZEN:
			{
				return IsMaxStatInMap(item, zhensStats);
			}
			case Itemtype::IT_ACCESSORY_EARRING:
			case Itemtype::IT_ACCESSORY_NECKLACE:
			case Itemtype::IT_ACCESSORY_RING:
			case Itemtype::IT_DECORATION_EYEBAND:
			case Itemtype::IT_DECORATION_EARRING:
			case Itemtype::IT_DECORATION_GLASSES:
			{
				return IsMaxStatInMap(item, accessoryStats);
			}
			case Itemtype::IT_ARMOR_BOOTS:
			case Itemtype::IT_ARMOR_DOWN:
			case Itemtype::IT_ARMOR_UP:
			case Itemtype::IT_ARMOR_GLOVES:
			case Itemtype::IT_ARMOR_HELMET:
			case Itemtype::IT_SHIELD:
			{
				return IsMaxStatInMap(item, armorStats);
			}
			default:
				return -1;
			}
		}
	}
	return -1;
}
auto CItemEntity__PetPickupItem = (int(__thiscall*)(void * tThis, CPlayer *pPlayer, void *pPet))(0x004EA390);//(0x004D36C0);
int __fastcall dCItemEntity__PetPickupItem(void* This, void* notUsed, CPlayer *pPlayer, void *pPet)
{
	CItemEntity * itemEntity = (CItemEntity*)This;
	EnterCriticalSection(itemEntity->GetCriticalSection());
	PlayerExtensions * extsn = pPlayer->GetPlayerExtensions();
	if (GlobalSettings::advancedHkOn &&extsn && extsn->isVip && extsn->isAdvancedHkOn && itemEntity->m_pItem)
	{
		if (AdvancedHK::getInstance().IsMaxItem(itemEntity->m_pItem) == 0)
		{
			LeaveCriticalSection(itemEntity->GetCriticalSection());
			return 23;
		}
	}
	LeaveCriticalSection(itemEntity->GetCriticalSection());
	return CItemEntity__PetPickupItem(This, pPlayer, pPet);
}
void AdvancedHK::ApplyHook(HMODULE hModule)
{

	DisableThreadLibraryCalls(hModule);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)CItemEntity__PetPickupItem, dCItemEntity__PetPickupItem);
	DetourTransactionCommit();
}
AdvancedHK::AdvancedHK()
{

}


AdvancedHK::~AdvancedHK()
{
}
