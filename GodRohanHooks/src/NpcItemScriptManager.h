#pragma once
class NpcItemScriptManager
{
public:
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecWeaponOneHand;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecWeaponOneHand;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecWeaponTwoHand;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecWeaponTwoHand;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecWeaponBow;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecWeaponBow;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecWeaponCrossBow;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecWeaponCrossBow;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecEtcArrowAndBolt;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecEtcArrowAndBolt;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecWeaponWand;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecWeaponWand;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecWeaponStaff;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecWeaponStaff;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecArmor;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecArmor;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecShield;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecShield;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecPotion;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecPotion;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecEtc; // std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecEtc;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecScroll;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecScroll;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecSiege;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecSiege;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecEmpty;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecEmpty;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > *_vecPrev;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > *m_pVecPrev;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecRiding;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecRiding;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecPet; // std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecPet;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecPetFood;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecPetFood;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecGuildWar;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecGuildWar;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecFishing;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecFishing;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecCostume;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecCostume;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecBuffScroll;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecBuffScroll;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecProduct;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecProduct;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecResource;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecResource;
	std::vector<STRADEITEM, std::allocator<STRADEITEM> > _vecRecipe;// std::vector<STRADEITEM,std::allocator<STRADEITEM> > m_vecRecipe;

};