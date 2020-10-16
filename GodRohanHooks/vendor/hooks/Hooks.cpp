#include "stdafx.h"
void MakeJMP(BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen)
{
	DWORD dwOldProtect, dwBkup, dwRelAddr;
	VirtualProtect(pAddress, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	dwRelAddr = (DWORD)(dwJumpTo - (DWORD)pAddress) - 5;
	*pAddress = 0xE9;
	*((DWORD *)(pAddress + 0x1)) = dwRelAddr;
	for (DWORD x = 0x5; x < dwLen; x++) *(pAddress + x) = 0x90;
	VirtualProtect(pAddress, dwLen, dwOldProtect, &dwBkup);
	return;

}


bool Hook(void * toHook, void * ourFunct, int len) {
	if (len < 5) {
		return false;
	}

	DWORD curProtection;
	VirtualProtect(toHook, len, PAGE_EXECUTE_READWRITE, &curProtection);

	memset(toHook, 0x90, len);

	DWORD relativeAddress = ((DWORD)ourFunct - (DWORD)toHook) - 5;

	*(BYTE*)toHook = 0xE9;
	*(DWORD*)((DWORD)toHook + 1) = relativeAddress;

	DWORD temp;
	VirtualProtect(toHook, len, curProtection, &temp);

	return true;
}
bool HookVfTable(void * toHook, void * ourFunct, int len) {
	if (len < 5) {
		return false;
	}

	DWORD curProtection;
	VirtualProtect(toHook, len, PAGE_EXECUTE_READWRITE, &curProtection);

	memset(toHook, 0x90, len);

	DWORD relativeAddress = ((DWORD)ourFunct - (DWORD)toHook) - 5;

	*(BYTE*)toHook = 0x68;
	*(DWORD*)((DWORD)toHook + 1) = (DWORD)ourFunct;

	DWORD temp;
	VirtualProtect(toHook, len, curProtection, &temp);

	return true;
}