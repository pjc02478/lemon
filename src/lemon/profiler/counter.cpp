#include "profiler.h"
#include "profiler_intern.h"

#include <unordered_map>

using namespace std;

namespace lemon{
	namespace profiler{
		static unordered_map<string, unsigned int> counter;

		void add_count(const string &name){
			counter[name] += 1;
		}
		unsigned int get_count(const string &name){
			return counter[name];
		}
		void reset_count(const string &name){
			counter[name] = 0;
		}
	};
};