#pragma once

#include <functional>

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
			task *parent;
			const std::function<void()> func;
			void *yield_fiber, *fiber;
		};
	};
};