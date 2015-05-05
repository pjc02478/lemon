#include "task.h"

#include "../lemon.h"
#ifdef P_WIN32
	#include "win32/coroutine_win32.h"
#endif

#include "../profiler/profiler.h"
#include "../profiler/profiler_intern.h"
#include "../flowcontrol/delay.h"
#include "../flowcontrol/signal.h"

#include <atomic>
#include <unordered_map>

using namespace std;

namespace lemon{
	namespace microthread{
		static atomic<unsigned int> _id = 0;
		static unordered_map<unsigned int,unique_ptr<task>> tasks;

		task::task(
			unsigned int _id,
			const function<void()> &f) :
			id(_id),
			sig(new(nothrow)flowcontrol::signal()),
			coro(new(nothrow)coroutine(*this, f)){
		}
		handle task::create_handle() const{
			return microthread::handle(
				id, coro, sig);
		}

		handle create(
			const function<void()> &f){

			auto id = _id.fetch_add(1);
			auto t = make_unique<task>(id, f);
			auto &slot = tasks[id];

			slot = std::move(t);

			return slot->create_handle();
		}
	};
};