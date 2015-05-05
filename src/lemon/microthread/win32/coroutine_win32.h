#pragma once

#include <functional>
#include <memory>
#include <string>

namespace lemon{
	namespace microthread{
		struct task;
		class handle;

		class coroutine{
		public:
			coroutine(
				task &parent,
				const std::function<void()> &f);
			virtual ~coroutine();

			void schedule();
			void yield();

			task &get_task();

		private:
			void dispose();
			static void _stdcall fiber_func(void *arg);

		private:
			std::string name;

			task &parent;
			const std::function<void()> func;
			void *yield_fiber;
			std::shared_ptr<void> fiber;
		};
	};
};