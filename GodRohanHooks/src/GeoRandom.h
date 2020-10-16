// struct CGeoRandom
#pragma once
#pragma pack(push,4)
class GeoRandom {

public:
	unsigned int _rseed;                                         // unsigned int rseed;
	unsigned int _rseedSp;                                       // unsigned int rseed_sp;
	unsigned int _mt[624];                                       // unsigned int mt[624];
	int _mti;                                                    // int mti;

};
#pragma pack(pop)