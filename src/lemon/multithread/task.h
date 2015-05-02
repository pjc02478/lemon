#pragma once

#include <functional>

namespace lemon{
	namespace multithread{
		class task{
		public:
			task(
				const std::function<void()> &f);
			virtual ~task();
		};
	};
};