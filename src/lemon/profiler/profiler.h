#pragma once

#include <string>

#define __NAME(n) lemon::profiler::set_name(n);

namespace lemon{
	namespace profiler{

		void set_name(const std::string &name);
	};
};