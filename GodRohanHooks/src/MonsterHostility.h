#pragma once

class Monster;
class HostilityBase {
	char paddngg[0x90];
};
class MonsterHostility : public HostilityBase {
public:
	int m_fpMonsterDrop[8];
	Monster * GetMonster() {
		Monster *(__thiscall* GetMonster)(void * tThis) = (Monster *(__thiscall*)(void * tThis))(0x0053636F);
		return GetMonster(this);
	}
};
