#pragma once

#include <thread>

namespace lemon{

	std::thread::id get_mainthread_id();
};