#pragma once
#include "../css-math/matrix.h"
#include "../css-math/vec.h"
#include "../css-math/color.h"
class c_baseentity;
class entity_list
{
public:
	c_baseentity* getcliententity(int entnum)
	{
		using original_fn = c_baseentity *(__thiscall*)(entity_list*, int);
		return (*(original_fn**)this)[3](this, entnum);
	}

	int getmaxclients()
	{
		using original_fn = int(__thiscall*)(entity_list*);
		return (*(original_fn**)this)[8](this); // or 9
	}
};