// struct CTrapScript
#include "EntityScript.h"

class TrapScript : EntityScript {

public:
	__int16 _attackType;                                         // __int16 m_AttackType;
	__int16 _sightRange;                                         // __int16 m_SightRange;
	__int16 _attackSpeed;                                        // __int16 m_AttackSpeed;
	__int16 _attackRange;                                        // __int16 m_AttackRange;
	int _damage;                                                 // int m_nDamage;
	int _physicsDefence;                                         // int m_nPhysicsDefence;
	int _magicDefence;                                           // int m_nMagicDefence;
	int _maxLife;                                                // int m_nMaxLife;
	int _abilityType[2];                                         // int m_AbilityType[2];
	int _abilityValue[2];                                        // int m_AbilityValue[2];
	unsigned __int16 _skillKind[2];                              // unsigned __int16 m_SkillKind[2];
	char _skillLevel[2];                                         // char m_SkillLevel[2];


};
