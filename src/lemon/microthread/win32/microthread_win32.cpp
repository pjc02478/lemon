#include "../microthread.h"

#include <cassert>
#include <Windows.h>

namespace lemon{
	namespace microthread{
		task &get_current(){
			assert(GetFiberData() != nullptr);

			/*  ???  */
			return *(task*)*(task**)GetFiberData();
		}
	};
};
