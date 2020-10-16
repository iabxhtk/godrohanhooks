#pragma once
#include "stdafx.h"

class CRLTimer
{
	int m_tTime;
	

public:
	//CPlayer *m_pPlayer;
	int GetSecond()
	{
		auto GetSecond = (int(__thiscall*)(void*))0x00646020; //(0x00608170) 0x00646020
		return GetSecond(this);
	}
};
class CCrime
{
public:
	int *vfptr;
	CPlayer *m_pPlayer;
	int m_nPoint;
	char m_nGrade;
	int m_nTimeState;
	int m_bParole;
	CRLTimer m_rlTimerPrison;
	IOCriticalSection m_crit;

	
	void _GotoPrison(int nPrisonSecond)
	{
		auto _GotoPrison = (void(__thiscall*)(void*, int nPrisonSecond))0x004EE410; //(0x004D7500) 0x004EE410
		return _GotoPrison(this, nPrisonSecond);
	}
	void GotoPrison(int nPrisonSecond, char reason)
	{
		struct  __declspec(align(1)) _tagResponseMAP_CHANGE_BLACKPOINT
		{
			char nReason;
			int nDiff;
			int nPoint;
			char bParole;
			int nRemainedPrisonSecond;
		};

		if (nPrisonSecond > 0)
		{
			_tagResponseMAP_CHANGE_BLACKPOINT rcres;
			EnterCriticalSection(&m_crit._criticalSection);
			_GotoPrison(nPrisonSecond);
			rcres.nReason = reason;
			rcres.nDiff = 0;
			rcres.nPoint = m_nPoint;
			rcres.bParole = m_bParole;
			rcres.nRemainedPrisonSecond = m_rlTimerPrison.GetSecond();
			if (m_pPlayer->GetConnection())
				m_pPlayer->GetConnection()->SendPacketEx(0x1A11u, &rcres, 0xEu);
			LeaveCriticalSection(&m_crit._criticalSection);
		}
		else
		{
		}
	}
};