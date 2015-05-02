#pragma once

#include <string>
#include <unordered_map>

#define __NAME(n) lemon::profiler::set_name(n);

namespace lemon{
	namespace profiler{

		struct profile_data{
			float duration;
			unsigned int context_switching;
			unsigned int new_coroutine;
			unsigned int end_coroutine;

			std::unordered_map<std::string, float> exe_time;

			void print();
		};

		void set_name(const std::string &name);

		void start();
		profile_data end();
		bool is_profiling();
	};
};