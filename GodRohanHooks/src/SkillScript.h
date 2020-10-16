#pragma once
#include "Structs.h"

// struct CSkillScript
class SkillScript {

public:
	char _dummy[1];                                              // char dummy[1];
	static _tagSkillInfo * GetSkillInfo(unsigned int dwSkillIdx)
	{
		_tagSkillInfo *(__cdecl *GetSkillInfo)(unsigned int dwSkillIdx) = (_tagSkillInfo *(__cdecl*)(unsigned int dwSkillIdx))0x00437010; //(0x004334A0) 0x00437010
		return GetSkillInfo(dwSkillIdx);
	}
};
