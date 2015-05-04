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
		struct task_data{
			unsigned int id;
			shared_ptr<flowcontrol::signal> sig;
			shared_ptr<coroutine> coro;

			task_data(
				unsigned int _id,
				const function<void()> &f) :
				id(_id),
				sig(new(nothrow)flowcontrol::signal()),
				coro(new(nothrow)coroutine(f)){
			}

			handle create_handle(){
				return microthread::handle(
					id, coro, sig);
			}
		};

		static atomic<unsigned int> _id = 0;
		static unordered_map<unsigned int,unique_ptr<task_data>> tasks;

		handle create(
			const function<void()> &f){

			auto id = _id.fetch_add(1);
			auto task = make_unique<task_data>(id, f);
			auto &slot = tasks[id];

			slot = std::move(task);

			return slot->create_handle();
		}
		

		task::task(
			const function<void()> &f) :
			id(_id.fetch_add(1)),
			sig(new(nothrow) flowcontrol::signal()),
			coro(new(nothrow) coroutine(f)){

		}
		task::~task(){
		}

		task::task(task &&other){
			id = other.id;
			coro = other.coro;
			sig = other.sig;
			
			other.id = -1;
		}
		task &task::operator=(task &&other){
			if(this != &other){
				id = other.id;
				coro = other.coro;
				sig = other.sig;

				other.id = -1;
			}

			return *this;
		}

		void task::schedule() const{
			coro->schedule();
		}
		void task::yield() const{
			if(is_yieldable())
				coro->yield();
		}

		void task::join() const{
			sig->add_waiting_context(
				get_current());

			flowcontrol::delay_until(*sig);
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