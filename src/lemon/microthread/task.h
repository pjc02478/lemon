#pragma once

#include <functional>
#include <memory>

#include "handle.h"

namespace lemon{
	namespace flowcontrol{
		class signal;
	};
	namespace microthread{
		class coroutine;

		handle create(
			const std::function<void()> &f);

		class task{
			friend coroutine;

		public:
			task(
				const std::function<void()> &f);
			virtual ~task();

			void yield()  const;
			void schedule() const;

			void join() const;

			unsigned int get_id() const;
			bool is_yieldable() const;
			void set_yieldable(bool v);

			task(task &&other);
			task &operator=(task &&other);

		private:
			task(const task &other);
			task &operator=(const task &other);

		private:
			unsigned int id;

			std::shared_ptr<flowcontrol::signal> sig;
			std::shared_ptr<coroutine> coro;
		};
	};
};