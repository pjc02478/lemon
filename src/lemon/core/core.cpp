#include "core.h"

#include <thread>

using namespace std;

namespace lemon{
	
	thread::id mainthread_id;

	thread::id get_mainthread_id(){
		return mainthread_id;
	}
};