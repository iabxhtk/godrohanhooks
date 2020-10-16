#pragma once
namespace oldstd {
	//this basic vector class is read only (cast it to memorry regionand read from it)
	template<class T>
	class vector
	{
	public:
		int someVecInt;
		T *_Myfirst;
		T *_Mylast;
		T *_Myend;

		T& operator [] (int i)
		{
			return _Myfirst[i];
		}
		size_t size()
		{
			return _Mylast - _Myfirst;
		}
		void push_back(T _Val)
		{
			T * result = nullptr;
			unsigned int v3; // [esp+Ch] [ebp-110h]
			unsigned int v4; // [esp+10h] [ebp-10Ch]
			T *v5; // [esp+F8h] [ebp-24h]
			T *v6; // [esp+100h] [ebp-1Ch]
			signed int v7; // [esp+104h] [ebp-18h]
			if (this->_Myfirst)
				v4 = this->_Mylast - this->_Myfirst;
			else
				v4 = 0;
			if (this->_Myfirst)
				v3 = this->_Myend - this->_Myfirst;
			else
				v3 = 0;
			if (v4 >= v3)
			{
				this->insert(result, this->_Mylast, _Val);
			}
			else
			{
				v5 = this->_Mylast;
				v7 = 1;
				v6 = this->_Mylast;
				while (v7)
				{
					memcpy(v6, (void*)_Val, sizeof(T));
					--v7;
					++v6;
				}
				this->_Mylast = v5 + 1;
			}
		}
	private:
		T * insert(T * result, T* where, T val)
		{
			auto insert = (T *(__thiscall*)(void*, T * result, T* where, T val))0x006B6500;
			return insert(this, result, where, val);
		}
	};
	//basic_string class uses mapid code (dont use until server is loaded into memory)
	class basic_string
	{
	private:
		char originalMembersSize[0x1C];
	public:
		basic_string()
		{
			auto basic_string = (void(__thiscall*)(void*))0x006652B0;
			basic_string(this);
		}
		basic_string(const char *_Ptr)
		{
			auto basic_string = (void(__thiscall*)(void*, const char *_Ptr))0x0049AAB0;
			basic_string(this, _Ptr);
		}
		~basic_string()
		{
			auto basic_string = (void(__thiscall*)(void*))0x0049B7E0;
			basic_string(this);
		}
		const char * c_str()
		{
			auto c_str = (const char *(__thiscall*)(void*))0x00637B50;
			return c_str(this);
		}
		basic_string * assign(const char *_Ptr)
		{
			auto assign = (basic_string *(__thiscall*)(void*, const char *_Ptr))0x005E6DE0;
			return assign(this, _Ptr);

		}
		basic_string * operator=(const char *_Ptr)
		{
			auto assign = (basic_string *(__thiscall*)(void*, const char *_Ptr))0x005E6DE0;
			return assign(this, _Ptr);
		}
	};
}