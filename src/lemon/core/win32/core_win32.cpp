﻿#include "../../lemon.h"

#include <Windows.h>
#include <thread>

using namespace std;

namespace lemon{
	
	extern thread::id mainthread_id;

	bool initialize_sys(){
		mainthread_id = this_thread::get_id();

		return 
			ConvertThreadToFiber(0) != nullptr ? true : false;
	}
	void quit_sys(){
		ConvertFiberToThread();
	}
};