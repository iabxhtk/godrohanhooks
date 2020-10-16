#pragma once
#ifndef CKILL_SLOT_H
#define CKILL_SLOT_H
#include "stdafx.h"

#include "IOCriticalSection.h"

class CSkillSlot : SkillEvent {

public:
	//std::map<unsigned long, CSkill *, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, CSkill *> > > _mapSkill;// std::map<unsigned long,CSkill *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CSkill *> > > m_mapSkill;
	///std::list<CSkill *, std::allocator<CSkill *> > _listActiveSkill;// std::list<CSkill *,std::allocator<CSkill *> > m_listActiveSkill;
	//std::map<unsigned long, _tagAffectSkill *, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, _tagAffectSkill *> > > _mapAffectedSkill;// std::map<unsigned long,_tagAffectSkill *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,_tagAffectSkill *> > > m_mapAffectedSkill;
	char skillslotmapspad[0x24];
	CSkill *_activeNativeSkill;                                   // CSkill *m_pActiveNativeSkill;
	CSkill *_activeOwnSkill;                                      // CSkill *m_pActiveOwnSkill;
	int _manaRecover;                                            // int m_bManaRecover;
	char skillslotmappad2[0xC];
	//std::map<unsigned short, EpochVector3, std::less<unsigned short>, std::allocator<std::pair<unsigned short const, EpochVector3> > > _mapTargetPos;// std::map<unsigned short,EpochVector3,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,EpochVector3> > > m_mapTargetPos;
	IOCriticalSection _lock;                                     // CIOCriticalSection m_lock;


	int IsAffectSkill(unsigned int dwKInd)
	{

		int(__thiscall *IsAffectSkill)(void*, unsigned int dwKInd) = (int(__thiscall*)(void*, unsigned int dwKInd))0x00694800; //(0x00642040) 0x00694800
		return IsAffectSkill(this, dwKInd);

	}
	CSkill *  GetSkill(unsigned int dwKInd)
	{

		CSkill *(__thiscall *GetSkill)(void*, unsigned int dwKInd) = (CSkill *(__thiscall*)(void*, unsigned int dwKInd))0x00692FE0; //(0x00640BE0) 0x00692FE0
		return GetSkill(this, dwKInd);

	}
};
#endif