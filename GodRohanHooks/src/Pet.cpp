#include "stdafx.h"
#include "Pet.h"
#include "MapEnums.h"
#include "TradeItemList.h"
#include "TradeItemScriptManager.h"
#include <iterator>


#pragma pack(push, 1)
struct tagResponseMAPPETLEVELUP {
	EpochID2 itemID;                                      // _tagEpochID2 itemID;
	char inventory;                                          // char nInventory;
	char slot;                                               // char nSlot;
	char level;                                              // char nLevel;
};
#pragma pack(pop)
auto Pet_PetLevelUp = (void(__thiscall*)(void * tThis))(0x005EE9C0);
void __fastcall dPet_PetLevelUp(void* This, void* notUsed)
{
	Pet * pet = (Pet*)This;
	if (pet->_level < 2)
	{
		EpochItemScriptManager  * g_pEpochItemScriptManager = EpochItemScriptManager::GetInstance();

		EpochItemScript *pItemScript;
		pItemScript = (EpochItemScript *)g_pEpochItemScriptManager->GetScriptById(pet->_petItem->GetEpochId()->type);
		if (pItemScript)
		{
			if (pItemScript->GetAttr(27) <= 1 && pet->_feedCount >= 1000 * pet->_petItem->GetAttribute(pet->_level + Itemattributetype::IAT_PET_FEED1))
			{
				pet->_feedCount = 0;
				pet->_petItem->SetOption(41, ++pet->_level);
				tagResponseMAPPETLEVELUP rcres;
				rcres.itemID.id = pet->_petItem->GetEpochId()->id;
				rcres.itemID.type = pet->_petItem->GetEpochId()->type;
				rcres.inventory = pet->_petItem->GetAttribute(Itemattributetype::IAT_INVENTORY);
				rcres.slot = pet->_petItem->GetAttribute(Itemattributetype::IAT_SLOT);
				if (pet->_owner->GetConnection())
				{
					(RohanConnection*)pet->_owner->GetConnection()->SendPacketEx(272, &rcres, 11);
				}
				int32_t currentPetLvl = pet->_level - 1;
				int32_t nextPetLvl = pet->_level;
				const int32_t NEXT_LEVEL = 1;


				int32_t currentWeightRate = pet->_petItem->GetAttribute(currentPetLvl + Itemattributetype::IAT_PET_WEIGHT1_RATE);
				int32_t nextMaxWeightRate = pet->_petItem->GetAttribute(nextPetLvl + Itemattributetype::IAT_PET_WEIGHT2_RATE);

				//Turn off current weight rate, and add new level weight rate;
				pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_MAX_WEIGHT_RATE, currentWeightRate, 0);
				pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_MAX_WEIGHT_RATE, nextMaxWeightRate, 1);


				//Fetch current params and next level params;
				int32_t currentParam1 = pet->_petItem->GetAttribute(currentPetLvl + Itemattributetype::IAT_PET_LEVEL1_RATE);
				int32_t currentParam2 = pet->_petItem->GetAttribute(currentPetLvl + Itemattributetype::IAT_PET_LEVEL1_EXPVALUE_1);
				int32_t currentParam3 = pet->_petItem->GetAttribute(currentPetLvl + Itemattributetype::IAT_PET_LEVEL1_EXPVALUE_2);
				int32_t currentParam4 = pet->_petItem->GetAttribute(currentPetLvl + Itemattributetype::IAT_PET_LEVEL1_EXPVALUE_3);
				int32_t currentParam5 = pet->_petItem->GetAttribute(currentPetLvl + Itemattributetype::IAT_PET_LEVEL1_EXPVALUE_4);

				int32_t nextParam1 = pet->_petItem->GetAttribute(nextPetLvl + Itemattributetype::IAT_PET_LEVEL1_RATE);
				int32_t nextParam2 = pet->_petItem->GetAttribute(nextPetLvl + Itemattributetype::IAT_PET_LEVEL1_EXPVALUE_1);
				int32_t nextParam3 = pet->_petItem->GetAttribute(nextPetLvl + Itemattributetype::IAT_PET_LEVEL1_EXPVALUE_2);
				int32_t nextParam4 = pet->_petItem->GetAttribute(nextPetLvl + Itemattributetype::IAT_PET_LEVEL1_EXPVALUE_3);
				int32_t nextParam5 = pet->_petItem->GetAttribute(nextPetLvl + Itemattributetype::IAT_PET_LEVEL1_EXPVALUE_4);

				int32_t itemType = pet->_petItem->GetAttribute(Itemattributetype::IAT_ITEM_TYPE);
				switch (itemType)
				{
					//Honey Bear.
				case Itemtype::IT_PET_STRENGTH:
					pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_MAX_LIFE_RATE, currentParam1, 0);
					pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_MAX_LIFE_RATE, nextParam1, 1);
					break;
				case Itemtype::IT_PET_SPEED:
					pet->_owner->GetPlayerItemSlotManager()->_optionAttr.SetOption(Itemabilityoptiontype::IAOT_MOVE_SPEED_RATE_BY_PET, nextParam1);
					break;
				case Itemtype::IT_PET_CRITICAL:

					pet->_owner->GetPlayerItemSlotManager()->_optionAttr.SetOption(Itemabilityoptiontype::IAOT_CRITICAL_RATE_RATE_BY_PET, nextParam2);
					pet->_owner->GetSkillManager()->_option.SetOption(Skillabilityoptiontype::SAOT_DEC_CRITICAL_DAMAGE_BY_PET, nextParam3);
					break;
				case Itemtype::IT_PET_ATTACK_SPEED:
					pet->_owner->GetPlayerItemSlotManager()->_optionAttr.SetOption(Itemabilityoptiontype::IAOT_ATTACK_SPEED_RATE_BY_PET, nextParam2);
					break;
				case Itemtype::IT_PET_DAMAGE:
					pet->SetDamagePet(1);
					break;
				case Itemtype::IT_PET_HEALING:
					pet->_owner->GetSkillManager()->_option.SetOption(Skillabilityoptiontype::SAOT_PERFECT_DEFENCE_RATE_BY_PET, nextParam1);
					break;
				case Itemtype::IT_PET_STAT:
				case Itemtype::IT_PET_STAT_EVENT:
					pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_ALL_STATUS, currentParam1, 0);
					pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_ALL_STATUS, nextParam1, 1);
					break;
				case Itemtype::IT_PET_DRAGON:
					pet->_owner->GetPlayerItemSlotManager()->_optionAttr.SetOption(Itemabilityoptiontype::IAOT_MOVE_SPEED_RATE_BY_PET, nextParam2);
					break;
				case Itemtype::IT_PET_UNICORN:
					pet->_owner->GetSkillManager()->_option.SetOption(Skillabilityoptiontype::SAOT_PERFECT_DEFENCE_RATE_BY_PET, nextParam1);
					break;
				case Itemtype::IT_PET_LION:
					pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_MAX_LIFE_RATE, currentParam1, 0);
					pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_MAX_LIFE_RATE, nextParam1, 1);
					pet->_owner->GetPlayerItemSlotManager()->_optionAttr.SetOption(Itemabilityoptiontype::IAOT_ATTACK_SPEED_RATE_BY_PET, nextParam2);
					pet->_owner->GetSkillManager()->_option.SetOption(Skillabilityoptiontype::SAOT_DEC_CRITICAL_DAMAGE_BY_PET, nextParam3);
					break;
				case Itemtype::IT_PET_FAIRY:
					pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_ALL_STATUS, currentParam2, 0);
					pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_ALL_STATUS, nextParam2, 1);
					break;
				case Itemtype::IT_PET_TEMP1:
					pet->_owner->GetPlayerItemSlotManager()->_optionAttr.SetOption(300, nextParam1);
					pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_ALL_STATUS, currentParam3, 0);
					pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_ALL_STATUS, nextParam3, 1);
					pet->_owner->GetPlayerItemSlotManager()->_optionAttr.SetOption(Itemabilityoptiontype::IAOT_ATTACK_SPEED_RATE_BY_PET, nextParam2);
					break;
				default:
					break;
				}
			}
		}
		pet->_owner->CalAllAbility();
		pet->_owner->SendStatus();
		pet->_owner->BroadcastPetLevelUp(pet->_level);
	}
}

auto Pet_SendEffect = (void(__thiscall*)(void * tThis, int bOnOff))(0x005EF290);
void __fastcall dPet_SendEffect(void* This, void* notUsed, int bOnOff)
{
	Pet * pet = (Pet*)This;

	
	if (pet->_petItem)
	{
		int32_t petLevel = pet->_level;
		int32_t nMaxWeightRate = pet->_petItem->GetAttribute(4);
		pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_MAX_WEIGHT_RATE, nMaxWeightRate, bOnOff);
		int32_t nParam1 = pet->_petItem->GetAttribute(petLevel + Itemattributetype::IAT_PET_LEVEL1_RATE);
		int32_t nParam2 = pet->_petItem->GetAttribute(petLevel + Itemattributetype::IAT_PET_LEVEL1_EXPVALUE_1);
		int32_t nParam3 = pet->_petItem->GetAttribute(petLevel + Itemattributetype::IAT_PET_LEVEL1_EXPVALUE_2);
		int32_t nParam4 = pet->_petItem->GetAttribute(petLevel + Itemattributetype::IAT_PET_LEVEL1_EXPVALUE_3);
		int32_t nParam5 = pet->_petItem->GetAttribute(petLevel + Itemattributetype::IAT_PET_LEVEL1_EXPVALUE_4);

		int32_t petType = pet->_petItem->GetAttribute(Itemattributetype::IAT_ITEM_TYPE);

		switch (petType)
		{
		case Itemtype::IT_PET_STRENGTH:
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_MAX_LIFE_RATE, nParam1, bOnOff);
			break;
		case Itemtype::IT_PET_SPEED:
			pet->_owner->GetPlayerItemSlotManager()->_optionAttr.SetOption(Itemabilityoptiontype::IAOT_MOVE_SPEED_RATE_BY_PET, bOnOff != 0 ? nParam1 : 0);
			break;
		case Itemtype::IT_PET_CRITICAL:
			pet->_owner->GetPlayerItemSlotManager()->_optionAttr.SetOption(Itemabilityoptiontype::IAOT_CRITICAL_RATE_RATE_BY_PET, bOnOff != 0 ? nParam2 : 0);
			pet->_owner->GetSkillManager()->_option.SetOption(Skillabilityoptiontype::SAOT_DEC_CRITICAL_DAMAGE_BY_PET, bOnOff != 0 ? nParam3 : 0);
			break;
		case Itemtype::IT_PET_ATTACK_SPEED:
			pet->_owner->GetPlayerItemSlotManager()->_optionAttr.SetOption(Itemabilityoptiontype::IAOT_ATTACK_SPEED_RATE_BY_PET, bOnOff != 0 ? nParam2 : 0);
			break;
		case Itemtype::IT_PET_DAMAGE:
			pet->SetDamagePet(bOnOff);
			break;
		case Itemtype::IT_PET_HEALING:
			pet->_owner->GetSkillManager()->_option.SetOption(Skillabilityoptiontype::SAOT_PERFECT_DEFENCE_RATE_BY_PET, bOnOff != 0 ? nParam1 : 0);
			break;
		case Itemtype::IT_PET_STAT:
		case Itemtype::IT_PET_STAT_EVENT:
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_STRENGTH, nParam1, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_DEXTERITY, nParam1, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_INTELLIGENCE, nParam1, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_MENTALITY, nParam1, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_HEALTH, nParam1, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_QUICKNESS, nParam1, bOnOff);
			break;
		case Itemtype::IT_PET_DRAGON:
			pet->_owner->GetPlayerItemSlotManager()->_optionAttr.SetOption(Itemabilityoptiontype::IAOT_MOVE_SPEED_RATE_BY_PET, bOnOff != 0 ? nParam2 : 0);
			break;
		case Itemtype::IT_PET_UNICORN:
			pet->_owner->GetSkillManager()->_option.SetOption(Skillabilityoptiontype::SAOT_PERFECT_DEFENCE_RATE_BY_PET, bOnOff != 0 ? nParam1 : 0);
			break;
		case Itemtype::IT_PET_LION:
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_MAX_LIFE_RATE, nParam1, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionAttr.SetOption(Itemabilityoptiontype::IAOT_ATTACK_SPEED_RATE_BY_PET, bOnOff != 0 ? nParam2 : 0);
			pet->_owner->GetSkillManager()->_option.SetOption(Skillabilityoptiontype::SAOT_DEC_CRITICAL_DAMAGE_BY_PET, bOnOff != 0 ? nParam3 : 0);
			break;
		case Itemtype::IT_PET_FAIRY:
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_STRENGTH, nParam2, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_DEXTERITY, nParam2, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_INTELLIGENCE, nParam2, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_MENTALITY, nParam2, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_HEALTH, nParam2, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_QUICKNESS, nParam2, bOnOff);
			break;
		case Itemtype::IT_PET_TEMP1:
			pet->_owner->GetPlayerItemSlotManager()->_optionAttr.SetOption(300, bOnOff != 0 ? nParam1 : 0);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_STRENGTH, nParam3, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_DEXTERITY, nParam3, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_INTELLIGENCE, nParam3, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_MENTALITY, nParam3, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_HEALTH, nParam3, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionMagic.CalOption(Itemoptiontype::IOT_QUICKNESS, nParam3, bOnOff);
			pet->_owner->GetPlayerItemSlotManager()->_optionAttr.SetOption(Itemabilityoptiontype::IAOT_ATTACK_SPEED_RATE_BY_PET, bOnOff != 0 ? nParam2 : 0);

		default:
			break;
		}

		pet->_owner->CalAllAbility();
		pet->_owner->SendStatus();

	}
}
void PetHooks(HMODULE hModule)
{
	//DisableThreadLibraryCalls(hModule);
	//DetourTransactionBegin();
	//DetourUpdateThread(GetCurrentThread());
	//DetourAttach(&(PVOID&)Pet_SendEffect, dPet_SendEffect);
	//DetourAttach(&(PVOID&)Pet_PetLevelUp, dPet_PetLevelUp);
	//DetourTransactionCommit();
	
}