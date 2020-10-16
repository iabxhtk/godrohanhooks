// struct CEntityScript

#pragma pack(push,4)
class EntityScript {

public:
	int vtabletr111;
	unsigned int _type;                                          // unsigned int Type;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _name;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > Name;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _hangulName;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > HangulName;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _modelLoad;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > ModelLoad;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _fileName;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > FileName;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _lodName;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > LodName;
	int _collisionType;                                          // int CollisionType;
	float _radius;                                               // float Radius;
	float _scenegraphRadius;                                     // float ScenegraphRadius;
	int _actorLodType;                                           // int ActorLodType;
	int _moveType;                                               // int MoveType;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _faceFile;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > FaceFile;
	float _viewDistance;                                         // float ViewDistance;
	float _aCTIVATETIME;                                         // float m_ACTIVATE_TIME;
	float _dEACTIVATETIME;                                       // float m_DEACTIVATE_TIME;
	int _collisionSvrLoad;                                       // int CollisionSvrLoad;
	int _reflection;                                             // int Reflection;



	
};
#pragma pack(pop)