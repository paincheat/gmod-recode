#pragma once
#include "../includes.h"

namespace console {
	void initialize(const char* title);
	void destroy();

	template <typename ... Args>
	void log(char const* const format, Args const& ... args) {
#ifdef _DEBUG
		printf(format, args ...);
#endif
	}

}