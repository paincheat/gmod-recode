#pragma once
#include "../../css-math/matrix.h"
#include "../../css-math/vec.h"
#include "../../css-math/color.h"
#include "../../classes/cusercmd.h"
#define OFFSET(type, name, offset)\
type &name##() const{\
return *(type*)(uintptr_t(this) + offset);\
}


// m_lifeState values
#define	LIFE_ALIVE				0 // alive
#define	LIFE_DYING				1 // playing death animation or still falling off of a ledge waiting to hit ground
#define	LIFE_DEAD				2 // dead. lying still.
#define LIFE_RESPAWNABLE		3
#define LIFE_DISCARDBODY		4

//get health 

class c_basecombatweapon;

class collideable_t {
public:
	vec3_t& mins() {
		using original_fn = vec3_t & (__thiscall*)(void*);
		return (*(original_fn * *)this)[1](this);
	}
	vec3_t& maxs() {
		using original_fn = vec3_t & (__thiscall*)(void*);
		return (*(original_fn * *)this)[2](this);
	}
};

class c_baseentity : public collideable_t {
public:
	collideable_t* collideable() {
		using original_fn = collideable_t * (__thiscall*)(void*);
		return (*(original_fn * *)this)[3](this);
	}

	OFFSET(int, health, 0x94); // correct
	OFFSET(int, flags, 0x350); // correct
	OFFSET(int, lifestate, 0xD9C); // idk
	OFFSET(vec3_t, origin, 0x190);

	void* renderable()
	{
		using original_fn = void * (__thiscall*)(void*);
		return (*(original_fn * *)this)[5](this);
	}

	bool setup_bones(matrix_t* out)
	{
		if (!this)
			return false;
		auto ren = renderable();
		using original_fn = bool(__thiscall*)(void*, matrix_t*, int, int, float);
		return (*(original_fn * *)ren)[16](ren, out, 128, 0x100, 0);
	}

	vec3_t bone_pos(int boneIndex)
	{
		matrix_t matrix[128];

		if (!this->setup_bones(matrix))
		{
			return this->origin();
		}

		matrix_t hitbox = matrix[boneIndex];

		return vec3_t(hitbox[0][3], hitbox[1][3], hitbox[2][3]);
	}

	const vec3_t& abs_origin()
	{
		typedef const vec3_t& (__thiscall *abs_origin_t)(PVOID);
		return ((abs_origin_t)(*(PDWORD)(*(PDWORD)(this) + 0x24)))(this);
	}

	bool is_alive()
	{
		return health() > 0 && lifestate() == LIFE_ALIVE;
	}

};

class c_basecombatweapon {
public:

};