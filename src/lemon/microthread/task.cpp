#include "task.h"

#include "../lemon.h"
#ifdef P_WIN32
	#include "win32/coroutine_win32.h"
#endif

#include "../profiler/profiler.h"
#include "../profiler/profiler_intern.h"

#include <atomic>

using namespace std;

namespace lemon{
	namespace microthread{

		static atomic<unsigned int> _id = 0;

		task::task(
			const function<void()> &f) :
			coro(new(nothrow) coroutine(this, f)){

			id = _id.fetch_add(1);
		}
		task::~task(){
		}

		void task::schedule() const{
			coro->schedule();
		}
		void task::yield() const{
			coro->yield();
		}

		unsigned int task::get_id() const{
			return id;
		}
		bool task::is_yieldable() const{
			return true;
		}
		void task::set_yieldable(bool v){

		}
	};
};