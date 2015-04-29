#include "coroutine_win32.h"

#include <Windows.h>
#include <cassert>

#include "../task.h"
#include "../../profiler/profiler_intern.h"

using namespace std;

namespace lemon{
	namespace microthread{
		coroutine::coroutine(
			task *p,
			const function<void()> &f) :
			parent(p), func(f){

			fiber = CreateFiber(
				0,
				fiber_func, (void*)&parent);
		}
		coroutine::~coroutine(){
			if (fiber != nullptr){
				DeleteFiber(fiber);
				fiber = nullptr;
			}
		}

		void coroutine::schedule(){
			assert(fiber != nullptr);

			yield_fiber = GetCurrentFiber();

			__SWITCH
			SwitchToFiber(fiber);
		}
		void coroutine::yield(){
			assert(yield_fiber != nullptr);

			__SWITCH
			SwitchToFiber(yield_fiber);
		}

		void _stdcall coroutine::fiber_func(void *arg){
			assert(arg != nullptr);

			coroutine *m =
				(coroutine*)((int)arg - offsetof(coroutine, parent));

			__NEW_COROUTINE
				m->func();
			__END_COROUTINE

			m->yield();
		}
	};
};