#include "profiler.h"
#include "profiler_intern.h"

#include "../time/time.h"

#include <unordered_map>
#include <cassert>

using namespace std;

namespace lemon{
	namespace profiler{
		static unordered_map<string, unsigned int> counter;
		static unordered_map<string, float> exe_time;
		static string current_task;
		static float exe_since = -1;

		void add_count(const string &name){
			counter[name] += 1;
		}
		unsigned int get_count(const string &name){
			return counter[name];
		}
		void reset_count(const string &name){
			counter[name] = 0;
		}

		void begin_task(const std::string &name){
			assert(exe_since == -1);

			current_task = name;
			exe_since = time::now();
		}
		void leave_task(const std::string &name){
			assert(exe_since != -1);

			exe_time[name] += time::now() - exe_since;

			exe_since = -1;
		}
		unordered_map<string, float> get_exe_time(){
			/* 즉시 반영 */
			//exe_time[current_task] += time::now() - exe_since;

			return exe_time;
		}
		void reset_exe_times(){
			exe_time.clear();
		}
	};
};