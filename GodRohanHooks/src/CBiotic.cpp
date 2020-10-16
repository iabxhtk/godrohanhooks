#include "stdafx.h"
#include "CBiotic.h"
#include "MapEnums.h"
#include "EntityManager.h"
int(__thiscall* CBiotic__GetSkillAttackForce)(void * tThis, CSkill *pSkill, int *nAttackType) = (int(__thiscall*)(void * tThis, CSkill *pSkill, int *nAttackType))(0x004D9C80);//(0x004C46A0);
int __fastcall dCBiotic__GetSkillAttackForce(void * This, void* notUsed, CSkill *pSkill, int *nAttackType)
{

	CBiotic * biotic = (CBiotic*)This;
	char nDynamicLevel = biotic->GetSkillManager()->GetTotalDynamicLevel(pSkill->_skillState.kind);
	_tagSkillInfo * skillInfo = SkillScript::GetSkillInfo(pSkill->_skillState.kind);
	tagSkillLevelInfo * levelInfo;
	if (skillInfo)
	{
		if (nDynamicLevel >= static_cast<char>(7))
			return 0;
		else
			levelInfo = &skillInfo->levelInfo[(unsigned __int8)nDynamicLevel];
	}
	else
	{
		return 0;
	}

	int nValue = 0;
	
	switch (pSkill->_skillState.kind)
	{
		

		/*
	case Skillidx::SAVAGE_HERO_SKILL_TEMP_1:
	case Skillidx::DEFENDER_HERO_SKILL_TEMP_1:
	case Skillidx::DRAGONKNIGHT_HERO_SKILL_TEMP_1:
	case Skillidx::DRAGONSAGE_HERO_SKILL_TEMP_1:
	case Skillidx::TEMPLER_HERO_SKILL_TEMP_1:
	{
		*nAttackType = 1;
		nValue = ((BioticBase*)biotic)->GetAbility(Characterability::CA_CAL_MELEE_ATTACK_FORCE);
		return nValue;
	}
	case Skillidx::PRIEST_HERO_SKILL_TEMP_1:
	case Skillidx::WARLOCK_HERO_SKILL_TEMP_1:
	{
		*nAttackType = 3;
		nValue = ((BioticBase*)biotic)->GetAbility(Characterability::CA_CAL_MAGIC_ATTACK_FORCE);
		return nValue;
	}
	case Skillidx::RANGER_HERO_SKILL_TEMP_1:
	{
		*nAttackType = 2;
		nValue = ((BioticBase*)biotic)->GetAbility(Characterability::CA_CAL_MISSILE_ATTACK_FORCE);
		return nValue;
	}*/
	default:
		return CBiotic__GetSkillAttackForce(This, pSkill, nAttackType);
	}

	
}




bool CBioticHooks(HMODULE hModule) {
	DisableThreadLibraryCalls(hModule);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)CBiotic__GetSkillAttackForce, dCBiotic__GetSkillAttackForce);
	DetourTransactionCommit();
	return true;
}

