#pragma once
#include <map>
#include "Player.h"
#pragma pack(push,1)
struct tagGRRECIPEINFO {
	unsigned int recipeID;                                   // unsigned int nRecipeID;
	int updateTime;                                          // int tUpdateTime;
	int destructionCounter;                                  // int nDestructionCounter;
};
#pragma pack(pop)
class RecipeManager {

private:
	std::map<unsigned long, long, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, long> > > _mapRecipeInfo;// std::map<unsigned long,long,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,long> > > m_mapRecipeInfo;
	CPlayer *_player;                                             // CPlayer *m_pPlayer;
	bool _isLoaded;                                              // bool m_bIsLoaded;
	std::map<unsigned long, tagGRRECIPEINFO *, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, tagGRRECIPEINFO *> > > _extmapRecipeInfo;// std::map<unsigned long,_tagGR_RECIPEINFO *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,_tagGR_RECIPEINFO *> > > m_ExtmapRecipeInfo;

public:

	
};
