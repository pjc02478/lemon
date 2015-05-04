#pragma once

#include <functional>
#include <memory>

namespace lemon{
	namespace microthread{
		class coroutine;

		class task{
		public:
			task(
				const std::function<void()> &f);
			virtual ~task();

			void yield()  const;
			void schedule() const;

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

			std::shared_ptr<coroutine> coro;
		};
	};
};