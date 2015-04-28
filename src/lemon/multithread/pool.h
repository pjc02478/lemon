#pragma once

#include <functional>

namespace lemon{
	namespace multithread{
		namespace pool{

			bool initialize();
			void quit();

			unsigned int get_workers();

			void enqueue(const std::function<void()> &t);
		};
	};
};