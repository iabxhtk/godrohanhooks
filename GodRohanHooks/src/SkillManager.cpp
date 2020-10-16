#pragma once
#include "stdafx.h"
#include "MapEnums.h"
#include "Monster.h"
#include "TimeAPI.h"
#include "Player.h"
auto ___RTDynamicCast = (char *(__cdecl*)(void *inptr, int VfDelta, void *SrcType, void *TargetType, int isReference))0x00753FAB;//(0x006F3BEB) 0x00753FAB


/*//Attempt to fix dhan hide not unhiding on Hero3.
auto CSkillManager__CureSleep_OnAttacked = (void(__thiscall*)(void * tThis))(0x00492FC0);
void __fastcall dCSkillManager__CureSleep_OnAttacked(void * This, void* notUsed) {
	CSkillManager * skillMgr = (CSkillManager*)This;
	if (skillMgr->IsHidingSkillActive())
		skillMgr->OffHiding(0);
	CSkillManager__CureSleep_OnAttacked(This);
}

//Fox healing hook.*/
int(__thiscall* CSkillManager__ProcessdDamageDecrement)(void * tThis, int nDamage, int bCriticalHit) = (int(__thiscall*)(void * tThis, int nDamage, int bCriticalHit))(0x004AD8B0);//(0x0049BB20);
int __fastcall dCSkillManager__ProcessdDamageDecrement(void * This, void* notUsed, int nDamage, int bCriticalHit)
{

	CSkillManager * skillMgr = (CSkillManager *)This;
	CPlayer * player = (CPlayer *)___RTDynamicCast(skillMgr->_biotic, 0, (void *)0x7E9608, (void *)0x7E9638, 0);
	Monster * monsta = (Monster *)___RTDynamicCast(skillMgr->_biotic, 0, (void *)0x7E9608, (void *)0x007E9F50, 0);


	if (player) 
	{
		int pendd = player->GetAbility(Characterability::CA_PENETRATE_DEC_DMG_RATE);
		std::cout << pendd << " " << player->GetEpochId()->id << " " << player->GetEpochId()->type << " "   << " "  << std::endl;


	}

	if (monsta)
	{
		int pendd = monsta->GetAbility(Characterability::CA_PENETRATE_DEC_DMG_RATE);
		std::cout << pendd << " " << monsta->GetEpochId()->id << " " << monsta->GetEpochId()->type << " " <<   " " << std::endl;


	}




		 return CSkillManager__ProcessdDamageDecrement(This, nDamage, bCriticalHit);

	

}

//Buffs calculations
auto CSkillManager__CalAffect = (int(__thiscall*)(void * tThis, unsigned int dwCasterId, unsigned __int16 wKind, unsigned int *pdwParams, int bAdd))(0x004B9C80);//(0x004A7F20) 0x004B9C80
int __fastcall dCSkillManager__CalAffect(void * This, void* notUsed, unsigned int dwCasterId,  unsigned __int16 wKind, unsigned int *pdwParams, int bAdd)
{
	CSkillManager * skillMgr = (CSkillManager*)This;

	



	

	//std::cout << wKind << " " << bAdd << " " << "" << " " << pdwParams[0] << " " << pdwParams[1] << " " << pdwParams[2] << std::endl;

	switch (wKind)
	{
	

	case Skillidx::ADD_TEMPER:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MENTALITY_RATE, *pdwParams, bAdd);
		break;
	}
	case Skillidx::ADD_INTENTION:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_INTELLIGENCE_RATE, *pdwParams, bAdd);
		break;
	}
	case Skillidx::DEADLY_BLOW:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_ADD_DAMAGE_BY_QUICKNESS, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_STRENGTH_RATE, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_QUICKNESS_RATE, pdwParams[1], bAdd);
		break;
	}
	case Skillidx::AVENGER_HERO_SKILL_TEMP_2:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_BLOCK_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_PHYSICS_ATTACK_RATE, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_DAMAGE_RATE, pdwParams[2], bAdd);
		break;
	}
	case Skillidx::PREDATOR_HERO_SKILL_TEMP_2:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_LIFE_DRAIN_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_QUICKNESS_RATE, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_RATE, pdwParams[2], bAdd);
		break;

	}
	case Skillidx::WARLOCK_HERO_SKILL_TEMP_2:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_ADD_DAMAGE_BY_INT, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MOVE_SPEED_RATE_SPRINT, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MAGIC_ATTACK_FORCE_RATE, pdwParams[2], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_RESIST_DBUFF_RATE_BY_S_OHNS, pdwParams[3], bAdd);
		break;
	}
	case Skillidx::WIZARD_HERO_SKILL_TEMP_2:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MENTALITY_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_RESIST_DBUFF_RATE_BY_S_OHNS, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_RATE, pdwParams[2], bAdd);
		break;
	}
	case Skillidx::BERSERKER_HERO_SKILL_TEMP_2:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_PHYSICS_ATTACK_RATE, pdwParams[0], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_ATTACK_SPEED_RATE, pdwParams[1], bAdd);
		break;
	}
	case Skillidx::SAVAGE_HERO_SKILL_TEMP_2:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_PHYSICS_ATTACK_RATE, pdwParams[0], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_ATTACK_SPEED_RATE, pdwParams[1], bAdd);
		break;
	}

	case Skillidx::DRAGONSAGE_HERO_SKILL_TEMP_2:
	{

		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_ADD_DAMAGE_BY_INT, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_RESIST_DBUFF_RATE_BY_S_OHNS, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_RATE, pdwParams[2], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MAGIC_ATTACK_FORCE_RATE, pdwParams[3], bAdd);

		break;
	}
	case Skillidx::DRAGONKNIGHT_HERO_SKILL_TEMP_2:
	{
		//not yet
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_PHYSICS_ATTACK_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_RESIST_DBUFF_RATE_BY_S_OHNS, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_RATE, pdwParams[2], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MAX_LIFE_RATE, pdwParams[3], bAdd);
		break;

	}
	case Skillidx::DEFENDER_HERO_SKILL_TEMP_2:
	{


		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MAX_LIFE_RATE, *pdwParams, bAdd);
		break;

	}
	case Skillidx::GUARDIAN_HERO_SKILL_TEMP_2:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_PHYSICS_ATTACK_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_ATTACK_SPEED_RATE, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MOVE_SPEED_RATE, pdwParams[2], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_LIFE_DRAIN_RATE, pdwParams[3], bAdd);
		break;
	}
	case Skillidx::TEMPLER_HERO_SKILL_TEMP_2:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_ADD_DAMAGE_BY_INT, pdwParams[1], bAdd);
		break;
	}
	case Skillidx::PRIEST_HERO_SKILL_TEMP_2:
	{

		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_STRENGTH_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_DEXTERITY_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_HEALTH_RATE_NO_LIFE_ADD, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_INTELLIGENCE_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_QUICKNESS_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MENTALITY_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_ATTACK_SPEED_RATE, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_STATUS_ATTACK_FORCE_RATE, pdwParams[2], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_RATE, pdwParams[3], bAdd);
		//skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_QUICKNESS_RATE, pdwParams[4], bAdd);
		break;

	}

	case Skillidx::BLUE_DEFENSE_K:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_HEALTH_RATE_NO_LIFE_ADD, *pdwParams, bAdd);
		break;
	}
	case Skillidx::BLUE_DEFENSE:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_INTELLIGENCE_RATE, *pdwParams, bAdd);
		break;
	}
	case Skillidx::QUICKNESS:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_QUICKNESS_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_DEXTERITY_RATE, *pdwParams, bAdd);
		break;
	}
	case Skillidx::MORALE_EXPANSION:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_PHYSICS_ATTACK_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MISSILE_ATTACK_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MAGIC_ATTACK_FORCE_RATE, *pdwParams, bAdd);
		//skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MELEE_ATTACK_RATE, *pdwParams, bAdd);
		//skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_STATUS_ATTACK_FORCE_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_TOTAL_DEFENCE_RATE, pdwParams[1], bAdd);

		break;

	}
	case Skillidx::DRAGONS_POWER:
	{

		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_PHYSICS_ATTACK_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MISSILE_ATTACK_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MAGIC_ATTACK_FORCE_RATE, *pdwParams, bAdd);

	}
	case Skillidx::CRITICAL_AURA:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_RATE, *pdwParams, bAdd);
		//	skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_PHYSICS_ATTACK_RATE, pdwParams[1], bAdd);
		break;
	}
	case Skillidx::FIXATION:
	{

		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_ONE_HAND_CLUB_ATTACK_FORCE_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_TOTAL_DEFENCE_RATE, pdwParams[1], bAdd);
		break;
	}
	case Skillidx::BATTLE_MODE:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_LEVEL_INC_BY_SKILL, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_STRENGTH_RATE, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_DEXTERITY_RATE, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_HEALTH_RATE_NO_LIFE_ADD, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_INTELLIGENCE_RATE, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_QUICKNESS_RATE, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MENTALITY_RATE, pdwParams[1], bAdd);

		break;
	}
	case Skillidx::DEFENDER_HERO_SKILL_TEMP_3:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_PHYSICS_ATTACK_NULL, 100, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MAGICS_ATTACK_NULL, pdwParams[4], bAdd);
		break;
	}
	case Skillidx::STONE_SKIN:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_PHYSICS_ATTACK_NULL, 100, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MAGICS_ATTACK_NULL, pdwParams[4], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_RESIST_STUN_RATE, 100, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_RESIST_DBUFF_RATE_BY_S_OHNS, 100, bAdd);
		break;
	}
	case Skillidx::ZHEN_MASTERY_K:
	{


		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_TWOHAND_ZEN_WEAPON_ATTACK_FORCE_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_DEC_CRITICAL_DAMAGE_VALUE, pdwParams[1], bAdd);

		break;

	}

	case Skillidx::ZHEN_MASTERY:

	{


		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_TWOHAND_ZEN_WEAPON_ATTACK_FORCE_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MAGIC_ATTACK_FORCE_RATE, pdwParams[1], bAdd);

		break;

	}

	case Skillidx::KATAR_MASTERY_D:
	{

		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_TWOHAND_KATAR_FORCE_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_HEALTH_RATE_NO_LIFE_ADD, pdwParams[1], bAdd);

		break;

	}
	case Skillidx::SCOUT_HERO_SKILL_TEMP_2:
	{


		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_DAMAGE_RATE, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_PHYSICS_ATTACK_NULL, pdwParams[2], bAdd);
		break;

	}
	case Skillidx::RANGER_HERO_SKILL_TEMP_2:
	{
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_PHYSICS_ATTACK_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MISSILE_ATTACK_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MAGIC_ATTACK_FORCE_RATE, *pdwParams, bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_RATE, pdwParams[1], bAdd);
		skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_CRITICAL_DAMAGE_RATE, pdwParams[2], bAdd);
		break;
	}

	 case Skillidx::CONFUSION_POUCH:
	 {
		 skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_PHYSICS_ATTACK_NULL, 100, bAdd);
		 skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_MAGICS_ATTACK_NULL, 100, bAdd);
		 skillMgr->_option.CalOption(Skillabilityoptiontype::SAOT_RESIST_STUN_RATE, 100, bAdd);
		
		 break;
	 }

	default:
	{
		return CSkillManager__CalAffect(This, dwCasterId, wKind, pdwParams, bAdd);
	}
	}


	CPlayer * player = (CPlayer *)___RTDynamicCast(skillMgr->_biotic, 0, (void *)0x7E9608, (void *)0x7E9638, 0);//0x786588, (void *)0x7865B8, 0);
	if (player)
	{
		player->CalAllAbility();
	}
	else
	{
		Monster * monsta = (Monster *)___RTDynamicCast(skillMgr->_biotic, 0, (void *)0x7E9608, (void *)0x007E9F50, 0);
		if (monsta) {
			monsta->CalAllAbility();
		}
	}




	return 1;
}

// on active buff/debuff  effect.
auto CSkillManager__OnAffect_Activ = (int(__thiscall*)(void * tThis, _tagAffectSkill *pASkill, int bActive))(0x004B0970);//(0x0049F370) 0x004B0970
int __fastcall dCSkillManager__OnAffect_Activ(void * This, void* notUsed, _tagAffectSkill *pASkill, int bActive)
{
	CSkillManager * skillMgr = (CSkillManager*)This;
	skillMgr->AddHostility_OnAffect(pASkill, bActive);
	skillMgr->AddHostility_OnAffectNotHarmful(pASkill, bActive);
	char skillLevel = pASkill->level;
	_tagSkillInfo * skillInfo = SkillScript::GetSkillInfo(pASkill->kind);
	tagSkillLevelInfo *pLevelInfo;
	if (skillInfo)
	{
		if (skillLevel >= 7)
			return 0;
		else
			pLevelInfo = &skillInfo->levelInfo[skillLevel];
	}
	else
	{
		return 0;
	}

	unsigned int * pdwParams = pLevelInfo->param;

	//std::cout << pASkill->kind << " " << pASkill->entityID << " " << bActive << " " << *pdwParams << " " << std::endl;

	switch (pASkill->kind)
	{
	
	
	case 321:

	{

		CSkillSlot* checkifactive = (CSkillSlot*)skillMgr->IsAffectSkill(Skillidx::ROHAS_BLESS);
		if (bActive)
		{

			if (checkifactive) {
				((BioticBase*)skillMgr->_biotic)->ClearSkillCondition(Conditionstate::CS_DONT_ACTION, pASkill->kind);
			}
			else
			{
				skillMgr->_biotic->ChangeConditionBySkill(Conditionstate::CS_DONT_ACTION, pASkill->durationTime, pASkill->kind);
			}
		}
		else
		{

			((BioticBase*)skillMgr->_biotic)->ClearSkillCondition(Conditionstate::CS_DONT_ACTION, pASkill->kind);
		}


	}

	case Skillidx::RANGER_HERO_SKILL_TEMP_1:

	{
		CSkillSlot* checkifactive = (CSkillSlot*)skillMgr->IsAffectSkill(Skillidx::ROHAS_BLESS);
		if (bActive)
		{

			if (checkifactive) {
				((BioticBase*)skillMgr->_biotic)->ClearSkillCondition(Conditionstate::CS_SILENCE, pASkill->kind);
			}
			else
			{
				skillMgr->_biotic->ChangeConditionBySkill(Conditionstate::CS_SILENCE, pASkill->durationTime, pASkill->kind);
			}
		}
		else
		{
			((BioticBase*)skillMgr->_biotic)->ClearSkillCondition(Conditionstate::CS_SILENCE, pASkill->kind);
		}
		return 1;
	}


	case Skillidx::SILENCE:
	{

		CSkillSlot * checkifactive = (CSkillSlot*)skillMgr->IsAffectSkill(Skillidx::ROHAS_BLESS);

		if (bActive)
		{		
			if (checkifactive) {
				((BioticBase*)skillMgr->_biotic)->ClearSkillCondition(Conditionstate::CS_SILENCE, pASkill->kind);
			}
			else 
			{
				skillMgr->_biotic->ChangeConditionBySkill(Conditionstate::CS_SILENCE, pASkill->durationTime, pASkill->kind);
			}
		}
		else
		{
			((BioticBase*)skillMgr->_biotic)->ClearSkillCondition(Conditionstate::CS_SILENCE, pASkill->kind);
		}
		return 1;
	}

	
	case Skillidx::CONFUSION_POUCH:
	{


		CSkill * checkifactive = (CSkill*)skillMgr->GetSkill(Skillidx::ROHAS_BLESS);

		if (checkifactive) 
		{
			pASkill->durationTime = 0;
			pASkill->entityID = 0;
			pASkill->affectTime = 0;
			skillMgr->_biotic->ChangeConditionBySkill(Conditionstate::CS_CONFUSION, pASkill->durationTime, pASkill->kind);
		} else
		if (bActive == 1) 
		{
			skillMgr->_biotic->ChangeConditionBySkill(Conditionstate::CS_CONFUSION, pASkill->durationTime, pASkill->kind);
		}
		else if (bActive == 0)
		{
			((BioticBase*)skillMgr->_biotic)->ClearSkillCondition(Conditionstate::CS_CONFUSION, pASkill->kind);
		}
		skillMgr->CalAffect(pASkill->entityID, pASkill->kind, pLevelInfo->param, bActive);
		CPlayer * player = (CPlayer *)___RTDynamicCast(skillMgr->_biotic, 0, (void *)0x7E9608, (void *)0x7E9638, 0);//0x786588, (void *)0x7865B8, 0);
		if (player)
			player->SendStatus();

		return 1;
	}
		

	




/*
	case Skillidx::DRAGONKNIGHT_HERO_SKILL_TEMP_1:
	case Skillidx::DRAGONSAGE_HERO_SKILL_TEMP_1:
	case Skillidx::DEFENDER_HERO_SKILL_TEMP_1:
	{
		if (bActive)
		{
			skillMgr->_biotic->ChangeConditionBySkill(Conditionstate::CS_STUN, pASkill->durationTime, pASkill->kind);
		}
		else
		{
			((BioticBase*)skillMgr->_biotic)->ClearSkillCondition(Conditionstate::CS_STUN, pASkill->kind);
		}
		return 1;
	}

	*/
	

	case Skillidx::STAFF_MASTERY_D:
	case Skillidx::KATAR_MASTERY_D:
	case Skillidx::ZHEN_MASTERY:
	case Skillidx::ZHEN_MASTERY_K:
	case Skillidx::DRAGONS_POWER:
	case Skillidx::ADD_TEMPER:
	case Skillidx::ADD_INTENTION:
	case Skillidx::DEADLY_BLOW:
	case Skillidx::BATTLE_MODE:
	case Skillidx::MORALE_EXPANSION:
	case Skillidx::QUICKNESS:
	case Skillidx::BLUE_DEFENSE:
	case Skillidx::BLUE_DEFENSE_K:
	case Skillidx::CRITICAL_AURA:
	case Skillidx::FIXATION:
	case Skillidx::DEFENDER_HERO_SKILL_TEMP_3:
	case Skillidx::PRIEST_HERO_SKILL_TEMP_2:
	case Skillidx::TEMPLER_HERO_SKILL_TEMP_2:
	case Skillidx::DRAGONKNIGHT_HERO_SKILL_TEMP_2:
	case Skillidx::DRAGONSAGE_HERO_SKILL_TEMP_2:
	case Skillidx::SCOUT_HERO_SKILL_TEMP_2:
	case Skillidx::RANGER_HERO_SKILL_TEMP_2:
	case Skillidx::DEFENDER_HERO_SKILL_TEMP_2:
	case Skillidx::GUARDIAN_HERO_SKILL_TEMP_2:
	case Skillidx::BERSERKER_HERO_SKILL_TEMP_2:
	case Skillidx::SAVAGE_HERO_SKILL_TEMP_2:
	case Skillidx::AVENGER_HERO_SKILL_TEMP_2:
	case Skillidx::PREDATOR_HERO_SKILL_TEMP_2:
	case Skillidx::WARLOCK_HERO_SKILL_TEMP_2:
	case Skillidx::WIZARD_HERO_SKILL_TEMP_2:
	{
		skillMgr->CalAffect(pASkill->entityID, pASkill->kind, pLevelInfo->param, bActive);
		CPlayer * player = (CPlayer *)___RTDynamicCast(skillMgr->_biotic, 0, (void *)0x7E9608, (void *)0x7E9638, 0);//0x786588, (void *)0x7865B8, 0);
		if (player)
			player->SendStatus();
		return 1;
	}


	default:
	{
		return CSkillManager__OnAffect_Activ(This, pASkill, bActive);
	}
	}
}

void SkillManagerHooks(HMODULE hModule)
{
	DisableThreadLibraryCalls(hModule);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	//DetourAttach(&(PVOID&)CSkillManager__CureSleep_OnAttacked, dCSkillManager__CureSleep_OnAttacked);
	//DetourAttach(&(PVOID&)CSkillManager__ProcessdDamageDecrement, dCSkillManager__ProcessdDamageDecrement);
	DetourAttach(&(PVOID&)CSkillManager__CalAffect, dCSkillManager__CalAffect);
	DetourAttach(&(PVOID&)CSkillManager__OnAffect_Activ, dCSkillManager__OnAffect_Activ);
	DetourTransactionCommit();

}