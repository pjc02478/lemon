#include "coroutine_win32.h"

#include <Windows.h>
#include <cassert>

#include "../task.h"
#include "../../profiler/profiler_intern.h"
#include "../../flowcontrol/signal.h"

using namespace std;

namespace lemon{
	namespace microthread{
		coroutine::coroutine(
			const function<void()> &f) :
			func(f){
				
			fiber.reset(CreateFiber(
				0,
				fiber_func, (void*)this),
				std::bind(&coroutine::dispose, this));

			name = profiler::get_name();
			if (name.empty()){
				char tmp[128];
				sprintf_s(tmp, "unnamed_task_%x_%d", this, 1234);
				name.assign(tmp);
			}
		}
		coroutine::~coroutine(){
		}

		void coroutine::dispose(){
			DeleteFiber(fiber.get());
		}

		void coroutine::schedule(){
			assert(fiber.get() != nullptr);

			yield_fiber = GetCurrentFiber();

			__SWITCH __BEGIN(name)
			SwitchToFiber(fiber.get());
		}
		void coroutine::yield(){
			assert(yield_fiber != nullptr);

			__SWITCH __LEAVE(name)
			SwitchToFiber(yield_fiber);
		}

		void _stdcall coroutine::fiber_func(void *arg){
			assert(arg != nullptr);

			coroutine *m = (coroutine*)arg;
				//(coroutine*)((int)arg - offsetof(coroutine, parent));

			__NEW_COROUTINE
				m->func();
			__END_COROUTINE
			
			m->parent->sig->notify_one();
			m->yield();
		}
	};
};