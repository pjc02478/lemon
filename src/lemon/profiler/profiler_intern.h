#pragma once

#include <string>
#include <unordered_map>

#define TAG_SWITCH "switch"
#define TAG_NEW_COROUTINE "new_coroutine"
#define TAG_END_COROUTINE "end_coroutine"

#ifdef _DEBUG
	#define __SWITCH lemon::profiler::add_count(TAG_SWITCH);
	#define __NEW_COROUTINE lemon::profiler::add_count(TAG_NEW_COROUTINE);
	#define __END_COROUTINE lemon::profiler::add_count(TAG_END_COROUTINE);
	#define __BEGIN(n) lemon::profiler::begin_task(n);
	#define __LEAVE(n) lemon::profiler::leave_task(n);
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

		void begin_task(const std::string &name);
		void leave_task(const std::string &name);
		std::unordered_map<std::string, float> get_exe_time();
		void reset_exe_times();
	};
};