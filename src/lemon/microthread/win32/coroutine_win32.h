#pragma once

#include <functional>
#include <string>

namespace lemon{
	namespace microthread{
		class task;

		class coroutine{
		public:
			coroutine(
				task *p,
				const std::function<void()> &f);
			virtual ~coroutine();

			void schedule();
			void yield();

		private:
			static void _stdcall fiber_func(void *arg);

		private:
			std::string name;

			task *parent;
			const std::function<void()> func;
			void *yield_fiber, *fiber;
		};
	};
};