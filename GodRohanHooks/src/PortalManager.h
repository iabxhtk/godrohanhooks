#pragma once
#include "OldStlContainers.h"
struct _tagNeuPortal {
	int m_nIndex;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_strPortalName;
};
struct _tagStartPortal {
	int m_nIndex;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_strPortalName;
};
struct _tagShowTotalPortal {
	int m_nIndex;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_strPortalName;
};
struct _tabStartPortalForClient {
	int m_nIndex;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_strPortalName;
	int m_RaceGottenPortal;
};
struct _tabSaveBind {
	int m_nIndex;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_strPortalName;
};
struct _tagRespawnPortalByRace {
	int m_nIndex;
	int m_nRaceType;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_strPortalName;
};
struct _tagSaveBindByMapIndexForServer {
	int m_nIndex;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_strPortalName;
	EpochVector3 m_vPos;
};


bool applyPortals(HMODULE hModule);
#pragma pack(push,4)
class PortalManager {
public:
	std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, EpochVector3, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, EpochVector3> > > _mapPortals;
	std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::vector<EpochVector3, std::allocator<EpochVector3> >, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, std::vector<EpochVector3, std::allocator<EpochVector3> > > > >  _mapRandomPortals;
	std::vector<_tagNeuPortal, std::allocator<_tagNeuPortal> > m_vecNeuPortal;
	std::vector<_tagStartPortal, std::allocator<_tagStartPortal> > m_vecStartPortal;
	std::vector<_tagShowTotalPortal, std::allocator<_tagShowTotalPortal> > m_vecShowTotalPortal;
	std::vector<_tabStartPortalForClient, std::allocator<_tabStartPortalForClient> > m_vecStartPortalClient;
	std::vector<_tabSaveBind, std::allocator<_tabSaveBind> > m_vecSaveBind;
	std::vector<_tagRespawnPortalByRace, std::allocator<_tagRespawnPortalByRace> > m_vecBindRace;
	std::vector<_tagSaveBindByMapIndexForServer, std::allocator<_tagSaveBindByMapIndexForServer> > m_vecSaveBindByMapIndex;
	bool m_bLoaded;
	intptr_t *m_pScriptMgr;
	static PortalManager * GetInstance()
	{
		return (PortalManager*)*(int*)0x04BEEB54;
	}
	void _RegistUniqueValue(oldstd::basic_string *reserved_txt, const unsigned int unique_value)
	{
		auto _RegistUniqueValue = (void(__thiscall*)(void*, oldstd::basic_string *reserved_txt, const unsigned int unique_value))0x006A7580;
		return _RegistUniqueValue(this, reserved_txt, unique_value);
	}
	void GetNearestPortalReservedText(oldstd::basic_string *reserved_txt, EpochVector3 *pos, bool bCheckTutorial)
	{
		auto GetNearestPortalReservedText = (void(__thiscall*)(void*, oldstd::basic_string *reserved_txt, EpochVector3 *pos, bool bCheckTutorial))0x006A83E0;
		return GetNearestPortalReservedText(this, reserved_txt, pos, bCheckTutorial);
	}
	static unsigned int ConvertReservedText_ToUniqueValue(oldstd::basic_string *reserved_txt)
	{
		auto ConvertReservedText_ToUniqueValue = (unsigned int(__cdecl*)(oldstd::basic_string *reserved_txt))0x006A7750;
		return ConvertReservedText_ToUniqueValue(reserved_txt);
	}
	unsigned int GetNearestPortal(EpochVector3 *pos)
	{
		auto GetNearestPortal = (unsigned int(__thiscall*)(void*, EpochVector3 *pos))0x006A8880;
		return GetNearestPortal(this, pos);
	}
	static bool ApplyHooks();
};
#pragma pack(pop)