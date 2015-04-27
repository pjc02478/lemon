#pragma once

#include <stack>

#include "../microthread/task.h"

namespace lemon{
	namespace flowcontrol{

		class signal{
		public:
			void add_waiting_context(const microthread::task &ctx);

			bool notify_one();
			unsigned int notify_all();

		private:
			std::stack<std::reference_wrapper<const microthread::task>> ctxs;
		};
	};
};