﻿#include "core.h"

#include "../lemon.h"
#ifdef P_WIN32
	#include "win32/core_win32.h"
#endif

#include "../multithread/pool.h"
#include "../dispatcher/dispatcher.h"

#include <thread>

using namespace std;

namespace lemon{
	
	thread::id mainthread_id;

	bool initialize(){
		multithread::pool::initialize();

		dispatcher::set_main(&dispatcher::get_current());

		return initialize_sys();
	}
	void quit(){
		quit_sys();
	}

	thread::id get_mainthread_id(){
		return mainthread_id;
	}
};