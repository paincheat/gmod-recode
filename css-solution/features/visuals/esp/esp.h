#pragma once
#include "../../../css-math/color.h"
#include "../../../css-math/matrix.h"
#include "../../../css-math/vec.h"
#include "../../../utilities/console.h"
#include "../../../utilities/global_vars.h"
#include "../../../utilities/math.h"
#include "../../../utilities/renderer/render.h"

class esp
{
private:

	std::array<int, 4> getbndbx(c_baseentity* entity)
	{
		vec3_t origin = entity->abs_origin();
		vec3_t mins = vec3_t(20, 20, 20) + origin;
		vec3_t maxs = vec3_t(20, 20, 20) + origin;

		vec3_t points[] = {
			vec3_t(mins.x, mins.y, mins.z),
			   vec3_t(mins.x, maxs.y, mins.z),
			   vec3_t(maxs.x, maxs.y, mins.z),
			   vec3_t(maxs.x, mins.y, mins.z),
			   vec3_t(maxs.x, maxs.y, maxs.z),
			   vec3_t(mins.x, maxs.y, maxs.z),
			   vec3_t(mins.x, mins.y, maxs.z),
			   vec3_t(maxs.x, mins.y, maxs.z)
		};

		vec3_t screen_points[] = {
			vec3_t(0, 0, 0),
			vec3_t(0, 0, 0),
			vec3_t(0, 0, 0),
			vec3_t(0, 0, 0),
			vec3_t(0, 0, 0),
			vec3_t(0, 0, 0),
			vec3_t(0, 0, 0),
			vec3_t(0, 0, 0)
		};

		int box[] = { 0, 0, 0, 0 };

		for (int i = 0; i < 8; i++)
		{
			if (!g_math.world_to_screen(points[i], screen_points[i]))
				return { 0, 0, 0, 0 };

			if (!i)
			{
				box[0] = screen_points[i].x;
				box[1] = screen_points[i].y;
				box[2] = screen_points[i].x;
				box[3] = screen_points[i].y;
			}

			if (box[0] > screen_points[i].x)
				box[0] = screen_points[i].x;
			if (box[1] > screen_points[i].y)
				box[1] = screen_points[i].y;
			if (box[2] < screen_points[i].x)
				box[2] = screen_points[i].x;
			if (box[3] < screen_points[i].y)
				box[3] = screen_points[i].y;
		}

		std::array<int, 4> arr = { box[0], box[1], box[2] - box[0], box[3] - box[1] };
		return arr;
	}

public:
	void start();
};
extern esp g_esp;