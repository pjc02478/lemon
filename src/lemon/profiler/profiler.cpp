#include "profiler.h"
#include "profiler_intern.h"

#include "../time/time.h"

#include <cassert>

using namespace std;

namespace lemon{
	namespace profiler{

		static string current_name;
		static float profile_since = -1;

		void set_name(const string &name){
			current_name = name;
		}
		string get_name(bool reset){
			if (reset)
				return std::move(current_name);
			else
				return current_name;
		}

		void reset_all(){
			reset_count(TAG_SWITCH);
			reset_count(TAG_NEW_COROUTINE);
			reset_count(TAG_END_COROUTINE);

			reset_exe_times();
		}

		void start(){
			assert(profile_since == -1);

			reset_all();
			profile_since = time::now();
		}
		profile_data end(){
			assert(profile_since != -1);

			profile_data pd = {
				time::now() - profile_since,

				get_count(TAG_SWITCH),
				get_count(TAG_NEW_COROUTINE),
				get_count(TAG_END_COROUTINE),

				get_exe_time()
			};

			profile_since = -1;

			return pd;
		}
		bool is_profiling(){
			return profile_since != -1 ? true : false;
		}

		void profile_data::print(){
			printf(
				"\n==profiling data==\n"
				"  - duration : %20f\n"
				"  - context switching : %16d\n"
				"  - new coroutine : %20d\n"
				"  - end coroutine : %20d\n"
				"  - tasks \n",
				duration,
				context_switching,
				new_coroutine, end_coroutine);

			for (auto &p : exe_time){
				printf("    - %s : %f\n",
					p.first.c_str(), p.second);
			}
		}
	};
};