#pragma once

#include <string>

#define TAG_SWITCH "switch"
#define TAG_NEW_COROUTINE "new_coroutine"
#define TAG_END_COROUTINE "end_coroutine"

#ifdef _DEBUG
	#define __SWITCH lemon::profiler::add_count(TAG_SWITCH);
	#define __NEW_COROUTINE lemon::profiler::add_count(TAG_NEW_COROUTINE);
	#define __END_COROUTINE lemon::profiler::add_count(TAG_END_COROUTINE);
#else
	#define __SWITCH
	#define __NEW_COROUTINE
	#define __END_COROUTINE
#endif

namespace lemon{
	namespace profiler{

		std::string get_name(bool reset=true);

		void add_count(const std::string &name);
		unsigned int get_count(const std::string &name);
		void reset_count(const std::string &name);
	};
};