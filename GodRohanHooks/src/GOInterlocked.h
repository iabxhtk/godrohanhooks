// struct CGOInterlocked
#pragma once
#pragma pack(push,4)
class GOInterlocked {

public:
	int VTABLEPTRR;
	int _lValue;                                                 // int m_lValue;


	// -----------------------------------------------------------------
	// struct CGOInterlockedVtbl
	// -----------------------------------------------------------------
	// void *(__thiscall *__vecDelDtor)(CGOInterlocked *this, unsigned int);
};
#pragma pack(pop)