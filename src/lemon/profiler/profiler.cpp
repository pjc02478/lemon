#include "profiler.h"
#include "profiler_intern.h"

using namespace std;

namespace lemon{
	namespace profiler{

		static string current_name;

		void set_name(const string &name){
			current_name = name;
		}
		string get_name(bool reset){
			return std::move(current_name);;
		}
	};
};