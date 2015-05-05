#include "../microthread.h"

#include <cassert>
#include <Windows.h>

#include "coroutine_win32.h"
#include "../handle.h"
#include "../task.h"

namespace lemon{
	namespace microthread{

		task &get_current(){
			assert(GetFiberData() != nullptr);

			auto coro = (coroutine*)GetFiberData();

			return coro->get_task();
		}
	};
};
