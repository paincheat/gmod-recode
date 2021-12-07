#pragma once
#include "../css-math/matrix.h"
#include "../css-math/color.h"
#include "../css-math/vec.h"

class math
{
public:
	bool world_to_screen(const vec3_t& origin, vec3_t& screen);
};

extern math g_math;