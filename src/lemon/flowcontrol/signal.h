#pragma once

#include <stack>

#include "../microthread/task.h"

namespace lemon{
	namespace flowcontrol{

		class signal{
		public:
			void add_waiting_context(const microthread::task &ctx);

			/* 대기하고 있는 context중 하나를 꺠웁니다 */
			bool notify_one();
			/* 대기하고 있는 모든 context를 깨웁니다 */
			unsigned int notify_all();

		private:
			std::stack<std::reference_wrapper<const microthread::task>> ctxs;
		};
	};
};