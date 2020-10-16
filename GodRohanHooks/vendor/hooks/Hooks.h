#pragma once
#include <Windows.h>
class Hooks
{
public:
	static void MakeJMP(BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen)
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
	static bool HookVfTable(void * toHook, void * ourFunct, int len) {
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
	static bool Hooks::Hook(void * toHook, void * ourFunct, int len) {
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
	static bool Hooks::HookCall(void * toHook, void * ourFunct, int len = 5) {
		if (len < 5) {
			//return false;
		}

		DWORD curProtection;
		VirtualProtect(toHook, len, PAGE_EXECUTE_READWRITE, &curProtection);

		memset(toHook, 0x90, len);

		DWORD relativeAddress = ((DWORD)ourFunct - (DWORD)toHook) - 5;

		*(BYTE*)toHook = 0xE8;
		*(DWORD*)((DWORD)toHook + 1) = relativeAddress;

		DWORD temp;
		VirtualProtect(toHook, len, curProtection, &temp);

		return true;
	}
	static void PatchBytes(void* address, BYTE val, size_t count)
	{
		DWORD curProtection;
		DWORD temp;
		VirtualProtect(address, count, PAGE_EXECUTE_READWRITE, &curProtection);
		for (size_t i = 0; i < count; ++i)
		{
			BYTE * addy = (BYTE*)address;
			addy[i] = (BYTE)val;
		}
		VirtualProtect(address, count, curProtection, &temp);
	}
	template<typename T>
	static void PatchBytes(void* address, T obj)
	{
		DWORD curProtection;
		DWORD temp;
		VirtualProtect(address, sizeof(T), PAGE_EXECUTE_READWRITE, &curProtection);
		*(T*)((DWORD)address) = (T)obj;
		VirtualProtect(address, sizeof(T), curProtection, &temp);
	}
};
