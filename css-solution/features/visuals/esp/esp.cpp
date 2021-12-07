#include "esp.h"
esp g_esp;

void esp::start()
{
	if (!interfaces::engine->IsInGame())
		return;
	if (!g::local)
		return;


	for (int i = 1; i <= interfaces::entitylist->getmaxclients(); ++i)
	{
		c_baseentity* entity = interfaces::entitylist->getcliententity(i);
		if (!entity)
			continue;
		if (!entity->is_alive())
			continue;
		//std::array<int, 4> box = getbndbx(entity);
		//int x = box[0], y = box[1], w = box[2], h = box[3];

		vec3_t Origin3D = entity->abs_origin();
		vec3_t Origin;

		if (Origin3D == vec3_t(0, 0, 0))
			return;
		if (!g_math.world_to_screen(Origin3D, Origin))
			return;
		vec3_t Head3D = entity->bone_pos(14);

		if (Head3D == vec3_t(0, 0, 0))
			return;
		Head3D.z += 12.0f;

		vec3_t Head;

		if (!g_math.world_to_screen(Head3D, Head))
			return;

		float h = fabs(Head.y - Origin.y);
		float w = h / 1.60f;

		RECT rect =
		{
			static_cast<long>(Origin.x - w * 0.5f),
			static_cast<long>(Head.y),
			static_cast<long>(w),
			static_cast<long>(Origin.y)
		};

		rect.right += static_cast<long>(rect.left);

		int middle = ((rect.right - rect.left) * 0.5) + rect.left;
		rect.right += static_cast<long>(rect.left);
		g_render.outlined_rect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, color(255, 255, 255));
		g_render.outlined_rect(rect.left - 1, rect.top - 1, rect.right - rect.left + 2, rect.bottom - rect.top + 2, color(0, 0, 0));
		g_render.outlined_rect(rect.left + 1, rect.top + 1, rect.right - rect.left - 2, rect.bottom - rect.top - 2, color(0, 0, 0));
	}
}