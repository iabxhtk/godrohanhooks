#include "stdafx.h"
#include "BattleManager.h"
#include "MapEnums.h"
#include "SkillManager.h"


auto ___RTDynamicCast1 = (char *(__cdecl*)(void *inptr, int VfDelta, void *SrcType, void *TargetType, int isReference))0x00753FAB;//(0x006F3BEB) 0x00753FAB


auto OnAttckDmg = (int(__thiscall*)(void * tThis, SBATTLECONTEXT *sao))(0x00528ED0);
int __fastcall dOnAttckDmg(void * This, void* notUsed, SBATTLECONTEXT *sao)
{
	BattleManager * battleMgr = (BattleManager*)This;
	std::cout << This << "\n";
	std::cout << sao->nRectTypeDamageCount << "\n";
	return OnAttckDmg(This, sao);
}
//on Attack Check
auto OnAttck = (int(__thiscall*)(void * tThis, SATTACKORDER *sao ))(0x0052BE10);//(0x00528ED0);
int __fastcall dOnAttck(void * This, void* notUsed, SATTACKORDER *sao)
{
	BattleManager * battleMgr = (BattleManager*)This;
	return OnAttck(This, sao);
}
//Skill dmg modifier calculation.
auto CBattleManager__CalSkillDamage = (int(__thiscall*)(void * tThis, SBATTLECONTEXT *BC, SATTACKORDER *sao, int nDamage))(0x00529A10);//(0x0050F4F0) 0x00529A10
int __fastcall dCBattleManager__CalSkillDamage(void * This, void* notUsed, SBATTLECONTEXT *BC, SATTACKORDER *sao, int nDamage)
{
	BattleManager * battleMgr = (BattleManager*)This;
	CBiotic * pAttackee = BC->pAttackee;
	CPlayer * player = (CPlayer *)Toolset::DynamicCast(battleMgr->_attacker->GetSkillManager()->_biotic, 0, (void *)0x7E9608, (void *)0x7E9638, 0);
	char nDynamicLevel = battleMgr->_attacker->GetSkillManager()->GetTotalDynamicLevel(sao->wSkillKind);
	_tagSkillInfo * skillInfo = SkillScript::GetSkillInfo(sao->wSkillKind);
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



	switch (sao->wSkillKind)
	{
	case Skillidx::ZHEN_MASTERY_K:
	{
		int boostByvit = ((BioticBase *)battleMgr->_attacker)->GetAbility(Characterability::CA_MAX_LIFE) * levelInfo->param[1] / 100;
		std::cout << nDamage << " " << boostByvit << "\n";
		nDamage += boostByvit;

		return nDamage;



	}

	case Skillidx::ZHEN_MASTERY:

	{
		int boostByint = ((BioticBase *)battleMgr->_attacker)->GetAbility(Characterability::CA_INTELLIGENCE) * levelInfo->param[1] / 100;
		return nDamage;
	}

	default:
	

		
		//return CBattleManager__CalSkillDamage(This, BC, sao, nDamage);
		return CBattleManager__CalSkillDamage(This, BC, sao, nDamage);
	}
}



auto CBattleManager__IsSkillAffect = (int(__thiscall*)(void * tThis, CBiotic *pAttackee, unsigned __int16 wSkillKind, char nSkillLevel, int nDamage, int *nResult))(0x00530BF0);// (0x00515AF0) 0x00530BF0
int __fastcall dCBattleManager__IsSkillAffect(void * This, void* notUsed, CBiotic *pAttackee, unsigned __int16 wSkillKind, char nSkillLevel, int nDamage, int *nResult)
{

	BattleManager * battleMgr = (BattleManager*)This;
	int stateType = ((BioticBase*)pAttackee)->GetState()->nType;
	
	if (stateType> 524291 && (stateType >= 0x80009 || stateType <= 0x8000A) || (stateType >= 0x80001 || stateType == 65539))
	{
		return 0;
	}

	
	if (wSkillKind && *nResult == 263 || *nResult == 259)
		return 0;
		


	int bSkillAffect = 0;
	switch (wSkillKind)
	{
		case Skillidx::ZHEN_MASTERY:
		case Skillidx::ZHEN_MASTERY_K:
		{
			bSkillAffect = 1;
			break;
		}
	


	





	default:
		return CBattleManager__IsSkillAffect(This, pAttackee, wSkillKind, nSkillLevel, nDamage, nResult);
	}
	
	if (wSkillKind)
	{
		if (bSkillAffect == 1)
		{
			int bStunTypeSkill = 0;
			int bNoDamage = 0;
			int bResistStun = pAttackee->GetSkillManager()->IsResistStunOnCombat(wSkillKind, &bStunTypeSkill, &bNoDamage);
			if (bStunTypeSkill)
			{
				if (bResistStun)
				{
					*nResult = 266;
					bSkillAffect = 0;
				}
				if (bNoDamage && *nResult != 257 && *nResult != 266)
					*nResult = 257;
			}
		}
	}
	return bSkillAffect;
}

int(__thiscall* CBattleManager__CalAffectedSkillDamage)(void * tThis, SBATTLECONTEXT *BC, SATTACKORDER *sao, int nDamage, CBiotic *pAttackee) = (int(__thiscall*)(void * tThis, SBATTLECONTEXT *BC, SATTACKORDER *sao, int nDamage, CBiotic *pAttackee))(0x00533BF0);
int __fastcall dCBattleManager__CalAffectedSkillDamage(void * This, void* notUsed, SBATTLECONTEXT *BC, SATTACKORDER *sao, int nDamage, CBiotic *pAttackee)
{
	if (nDamage == 1) return 0;
		BattleManager * battleMgr = (BattleManager*)This;
		if (battleMgr->_attacker->GetEpochId()->id < 1000000 && pAttackee->GetEpochId()->id < 1000000 &&
			battleMgr->_attacker->GetEpochId()->id > 0 && pAttackee->GetEpochId()->id > 0){

		CPlayer * player = (CPlayer *)Toolset::DynamicCast(battleMgr->_attacker->GetSkillManager()->_biotic, 0, (void *)0x7E9608, (void *)0x7E9638, 0);
		EpochItem * weapon = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(0, 5);
		EpochItem * shield = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(0, 6);

		if (!player)return 0;
		if (!weapon) return 0;
		//if (!BC->pAttackee) return 0;


		

		if (player && shield && shield->IsWeapon() && weapon && weapon->IsWeapon())
		{
			
			if (!shield->IsArmor() && !shield->IsShield() && !shield->IsWeapon())
			return 0;

			auto weapon_description = weapon->GetScript()->GetAttr(Itemattributetype::IAT_DESCRIPTION);
			auto shield_description = shield->GetScript()->GetAttr(Itemattributetype::IAT_DESCRIPTION);
			//if (weapon_description == Itemdescription::ID_PRODUCT && shield_description == Itemdescription::ID_PRODUCT) return nDamage;
			if (weapon_description == Itemdescription::ID_PRODUCT && shield_description != Itemdescription::ID_PRODUCT) {
			int penddshield = shield->GetOption(Itemoptiontype::IOT_PENETRATE_DEC_DMG_RATE) * 50 / 100;
			int checpen = player->GetAbility(Characterability::CA_PENETRATE_DEC_DMG_RATE);
			int penn = penddshield + checpen;
			player->SetAbility(Characterability::CA_PENETRATE_DEC_DMG_RATE, penn);}
			else if (weapon_description != Itemdescription::ID_PRODUCT && shield_description == Itemdescription::ID_PRODUCT){
			int penddweapon = weapon->GetOption(Itemoptiontype::IOT_PENETRATE_DEC_DMG_RATE);
			int checpen = player->GetAbility(Characterability::CA_PENETRATE_DEC_DMG_RATE);
			int penn = penddweapon + checpen;
			player->SetAbility(Characterability::CA_PENETRATE_DEC_DMG_RATE, penn);
			}else if (weapon_description != Itemdescription::ID_PRODUCT && shield_description != Itemdescription::ID_PRODUCT){
			int penddweapon = weapon->GetOption(Itemoptiontype::IOT_PENETRATE_DEC_DMG_RATE);
			int penddshield = shield->GetOption(Itemoptiontype::IOT_PENETRATE_DEC_DMG_RATE) * 50 / 100;
			int penn = penddshield + penddweapon;
			player->SetAbility(Characterability::CA_PENETRATE_DEC_DMG_RATE, penn);}
		} else if (player && weapon && weapon->IsWeapon()){

			auto weapon_description = weapon->GetScript()->GetAttr(Itemattributetype::IAT_DESCRIPTION);
			if (weapon_description != Itemdescription::ID_PRODUCT) {
			int penddweapon = weapon->GetOption(Itemoptiontype::IOT_PENETRATE_DEC_DMG_RATE);
			int penn = penddweapon;
			//int checpen = player->GetAbility(Characterability::CA_PENETRATE_DEC_DMG_RATE);
			player->SetAbility(Characterability::CA_PENETRATE_DEC_DMG_RATE, penn);}
		
		}
		}

		//std::cout << "(4) Dmg: " << nDamage << " " << sao->dwAttackerID<< " " << attacked << "\n";
		return CBattleManager__CalAffectedSkillDamage(This, BC, sao, nDamage, pAttackee);
	}






void BattleManagerHooks(HMODULE hModule)
{
	DisableThreadLibraryCalls(hModule);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)CBattleManager__CalAffectedSkillDamage, dCBattleManager__CalAffectedSkillDamage);
	//DetourAttach(&(PVOID&)OnAttckDmg, dOnAttckDmg);
	//DetourAttach(&(PVOID&)OnAttck, dOnAttck);
	DetourAttach(&(PVOID&)CBattleManager__IsSkillAffect, dCBattleManager__IsSkillAffect);
	DetourAttach(&(PVOID&)CBattleManager__CalSkillDamage, dCBattleManager__CalSkillDamage);
	DetourTransactionCommit(); 
}