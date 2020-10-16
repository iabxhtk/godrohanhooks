#pragma once
#include "stdafx.h"
#include "Qualities.h"
#include "TrapEntity.h"


void SkillManagerHooks(HMODULE hModule);
class CBiotic;
class CSkillManager : public CSkillSlot {

public:
	CBiotic *_biotic;                                             // CBiotic *m_pBiotic;
	unsigned int _lastBeginTime;                                 // unsigned int m_dwLastBeginTime;
	QualitiesOption _option;                                     // CQualitiesOption m_option;
	int _changeMana;                                             // int m_bChangeMana;
	int _changeLife;                                             // int m_bChangeLife;
	CQualities _dotDamage;                                        // CQualities m_dotDamage;
	int _dotDamageDelayTime;                                     // int m_nDotDamageDelayTime;
	CQualities _dotHeal;                                          // CQualities m_dotHeal;
	char padlistSkillMgr[0x24];
	//std::list<SEndSkill, std::allocator<SEndSkill> > _removeSkillList;// std::list<SEndSkill,std::allocator<SEndSkill> > m_RemoveSkillList;
	//std::list<CSkill *, std::allocator<CSkill *> > _eventSkillList;// std::list<CSkill *,std::allocator<CSkill *> > m_EventSkillList;
	//std::list<SENDAFFECTSKILL, std::allocator<SENDAFFECTSKILL> > _listEndAffectSkill;// std::list<SENDAFFECTSKILL,std::allocator<SENDAFFECTSKILL> > m_listEndAffectSkill;
	int _iMagicBarrierDefence;                                   // int m_iMagicBarrierDefence;
	int _iManaGuardDefence;                                      // int m_iManaGuardDefence;
	int _soulMeditation;                                         // int m_bSoulMeditation;
	int _castOver;                                               // int m_bCastOver;
	int _groupEuphoria;                                          // int m_bGroupEuphoria;
	int _killTime;                                               // int m_bKillTime;
	unsigned __int16 _killTimeSkillKind;                         // unsigned __int16 m_wKillTimeSkillKind;
	int _killTimeCount;                                          // int m_nKillTime_Count;
	int _sKillTimeCount;                                         // int m_nSKillTime_Count;
	int _killingTimeCount;                                       // int m_nKillingTime_Count;
	int _ghostArrowCount;                                        // int m_GhostArrowCount;
	int _ignoreAggroPercent;                                     // int m_IgnoreAggroPercent;
	int _orderSwingCount;                                        // int m_OrderSwingCount;
	int _manaShield;                                             // int m_bManaShield;
	int _manaShieldDE;                                           // int m_bManaShieldDE;
	int _manaShieldUnitDamage;                                   // int m_ManaShield_UnitDamage;
	int _manaShieldUnitManaConsume;                              // int m_ManaShield_UnitManaConsume;
	int _manaShieldManaSaving;                                   // int m_ManaShield_ManaSaving;
	int _obligation;                                             // int m_bObligation;
	int _obligationUnitDamage;                                   // int m_Obligation_UnitDamage;
	int _obligationUnitManaConsume;                              // int m_Obligation_UnitManaConsume;
	int _secretHideOn;                                           // int m_bSecretHideOn;
	int _blackMantleOn;                                          // int m_bBlackMantleOn;
	int _manaReturn;                                             // int m_bManaReturn;
	int _manaReturnPercent;                                      // int m_ManaReturnPercent;
	int _percentDragonsSkin;                                     // int m_percentDragonsSkin;
	int _mistOn;                                                 // int m_bMistOn;
	int _initDekanTransform;                                     // int m_bInitDekanTransform;
	int _criticalReflectCount;                                   // int m_nCriticalReflectCount;
	int _guildMantleOn;                                          // int m_bGuildMantleOn;
	int _kingShadowOn;                                           // int m_bKingShadowOn;
	int _iGuildMagicBarrierDefence;                              // int m_iGuildMagicBarrierDefence;
	int _iScrollMagicBarrierDefence;                             // int m_iScrollMagicBarrierDefence;
	int _sCriticalImmuneOn;                                      // int m_bSCriticalImmuneOn;
	int _sHidingOn;                                              // int m_bSHidingOn;
	CQualities _mapItemSkillCoolingTime;                          // CQualities m_mapItemSkillCoolingTime;
	CQualities _mapSkillTeleport;                                 // CQualities m_mapSkillTeleport;
	CQualities _mapSkillRespawn;                                  // CQualities m_mapSkillRespawn;
	int _intelligentShield;                                      // int m_nIntelligentShield;
	int _mentalityShield;                                        // int m_nMentalityShield;
	int _groupMortalImmuneOn;                                    // int m_bGroupMortalImmuneOn;
	int _magicMirrorCount;                                       // int m_nMagicMirrorCount;
	int _tripleFatal;                                            // int m_nTripleFatal;
	char skillMgMapPads[0x18];
	//std::map<unsigned short, TrapEntity *, std::less<unsigned short>, std::allocator<std::pair<unsigned short const, TrapEntity *> > > _mapTrapEntities;// std::map<unsigned short,CTrapEntity *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CTrapEntity *> > > m_mapTrapEntities;
	//std::multimap<unsigned short, TrapEntity *, std::less<unsigned short>, std::allocator<std::pair<unsigned short const, TrapEntity *> > > _mapGuildTrapEntities;// std::multimap<unsigned short,CTrapEntity *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CTrapEntity *> > > m_mapGuildTrapEntities;
	int _isLoadingSkill;                                         // int m_bIsLoadingSkill;
	int _isAffectSkillByLevel;                                   // int m_nIsAffectSkillByLevel;




	
	
	static int IsHarmfulSkill(unsigned __int16 wSkillKind) {
		auto IsHarmfulSkill = (int(__stdcall*)(unsigned __int16 wSkillKind))0x004A4D70; //(0x00493060) 0x004A4D70
		return IsHarmfulSkill(wSkillKind);
	}

	int IsHidingSkillActive() {
		auto IsHidingSkillActive = (int(__thiscall*)(void*))0x004A98D0; //(0x00497970) 0x004A98D0 
		return IsHidingSkillActive(this);
	}
	int OffHiding(int useItem) {
		auto OffHiding = (int(__thiscall*)(void*, int))0x004A7FF0; // (0x00496190) 0x004A7FF0
		return OffHiding(this, useItem);
	}
	int AddAffectSkill(_tagAffectSkill *pAffectedSkill) {
		auto AddAffectSkill = (int(__thiscall*)(void*, _tagAffectSkill *pAffectedSkill))0x004AA8F0; //(0x00498990) 0x004AA8F0
		return AddAffectSkill(this, pAffectedSkill);
	}
	char GetTotalDynamicLevel(unsigned __int16 wSkillKind)
	{

		char(__thiscall *GetTotalDynamicLevel)(void*, unsigned __int16 wSkillKind) = (char(__thiscall*)(void*, unsigned __int16 wSkillKind))0x004ADDC0; //(0x0049C020) 0x004ADDC0
		return GetTotalDynamicLevel(this, wSkillKind);

	}
	void AddHostility_OnAffect(_tagAffectSkill *pASkill, int bActiv)
	{

		void(__thiscall *AddHostility_OnAffect)(void*, _tagAffectSkill *pASkill, int bActiv) = (void(__thiscall*)(void*, _tagAffectSkill *pASkill, int bActiv))0x004A4E90; //(0x00493180) 0x004A4E90
		return AddHostility_OnAffect(this, pASkill, bActiv);

	}
	void AddHostility_OnAffectNotHarmful(_tagAffectSkill *pASkill, int bActiv)
	{

		void(__thiscall *AddHostility_OnAffectNotHarmful)(void*, _tagAffectSkill *pASkill, int bActiv) = (void(__thiscall*)(void*, _tagAffectSkill *pASkill, int bActiv))0x004A55A0; //(0x00493880) 0x004A55A0
		return AddHostility_OnAffectNotHarmful(this, pASkill, bActiv);

	}
	void CalAffect(unsigned int dwCasterId, unsigned __int16 wKind, unsigned int *pdwParams, int bAdd)
	{

		void(__thiscall *CalAffect)(void*, unsigned int dwCasterId, unsigned __int16 wKind, unsigned int *pdwParams, int bAdd) = (void(__thiscall*)(void*, unsigned int dwCasterId, unsigned __int16 wKind, unsigned int *pdwParams, int bAdd))0x004B9C80; // (0x004A7F20) 0x004B9C80 //not sure
		return CalAffect(this, dwCasterId, wKind, pdwParams, bAdd);

	}
	int IsResistStunOnCombat(unsigned __int16 skillkind, int *bStunTypeSkill, int *bNoDamage)
	{

		int(__thiscall *IsResistStunOnCombat)(void*, unsigned __int16 skillkind, int *bStunTypeSkill, int *bNoDamage) = (int(__thiscall*)(void*, unsigned __int16 skillkind, int *bStunTypeSkill, int *bNoDamage))0x004A4880; //(0x00492B90) 0x004A4880
		return IsResistStunOnCombat(this, skillkind, bStunTypeSkill, bNoDamage);

	}
	void ChangeLife(int nDiff, int bMinLife)
	{
		void(__thiscall *CalAffect)(void*, int nDiff, int bMinLife) = (void(__thiscall*)(void*, int nDiff, int bMinLife))0x004A7CB0;// (0x004A7CB0) 0x00495E50
		return CalAffect(this, nDiff, bMinLife);
	}


};

