#include "task.h"

#include "../lemon.h"
#ifdef P_WIN32
	#include "win32/coroutine_win32.h"
#endif

#include <atomic>

using namespace std;

namespace lemon{
	namespace microthread{

		static atomic<unsigned int> _id = 0;

		task::task(
			const function<void()> &f){

			id = _id.fetch_add(1);
			coro = new(nothrow) coroutine(this, f);
		}
		task::~task(){
			if (coro != nullptr){
				delete coro;
				coro = nullptr;
			}
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