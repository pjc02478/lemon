#pragma once

#include <vector>

#include "../microthread/task.h"

namespace lemon{
	namespace flowcontrol{

		class signal{
		public:
			void wait();

			/* 대기하고 있는 context중 하나를 꺠웁니다 */
			bool notify_one();
			/* 대기하고 있는 모든 context를 깨웁니다 */
			unsigned int notify_all();

		//protected:
			void add_waiting_context(const microthread::task &ctx);

		private:
			std::vector<std::reference_wrapper<const microthread::task>> ctxs;
		};
	};
};