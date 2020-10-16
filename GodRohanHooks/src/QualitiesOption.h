
#include "stdafx.h"

#pragma pack(push,4)
class QualitiesOption : public CQualities {

private:

public:
	void CalOption(int nOptionType, int nCalValue, int bAdd)
	{
	

		void(__thiscall *CalOption)(void*, int nOptionType, int nCalValue, int bAdd) = (void(__thiscall*)(void*, int nOptionType, int nCalValue, int bAdd))0x004EACF0;
		//std::cout << "1->" << nOptionType << " " << nCalValue << " " << bAdd << std::endl;
		return CalOption(this, nOptionType, nCalValue, bAdd);
	}
	void SetOption(int nOptionType, int nValue)
	{
		
		
		void(__thiscall *SetOption)(void*, int nOptionType, int nValue) = (void(__thiscall*)(void*, int nOptionType, int nValue))0x004EACD0;
	//	std::cout << "2->" << nOptionType << " " << nValue << std::endl;
		return SetOption(this, nOptionType, nValue);

		
	}
	int GetOption(int nOptionType)
	{
	
		int temp = 0;
		int(__thiscall *GetInt)(void*, int nKey, int *nValue) = (int(__thiscall*)(void*, int nKey, int *nValue))0x0066E010;
		GetInt(this, nOptionType, &temp);
	//	std::cout << "3->" << nOptionType << std::endl;
		return temp;

	}
};
#pragma pack(pop)