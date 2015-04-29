#include "profiler.h"
#include "profiler_intern.h"

using namespace std;

namespace lemon{
	namespace profiler{

		static string current_name;

		void set_name(const string &name){
			current_name = name;
		}
		const string &get_name(){
			return current_name;
		}
	};
};