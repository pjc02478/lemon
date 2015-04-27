#pragma once

#include <functional>

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

		private:
			unsigned int id;

			coroutine *coro;
		};
	};
};