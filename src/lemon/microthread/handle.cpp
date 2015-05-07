#include "handle.h"

#include "../lemon.h"
#ifdef P_WIN32
	#include "win32/coroutine_win32.h"
#endif

#include <atomic>
#include <vector>

using namespace std;

namespace lemon{
	namespace microthread{

		handle::handle(
			unsigned int _id,
			weak_ptr<coroutine> _coro_wp,
			weak_ptr<flowcontrol::signal> _sig_wp) :
			id(id),
			coro_wp(_coro_wp), sig_wp(_sig_wp){

		}
		handle::handle(handle &&other){
			id = other.id;
			coro_wp = std::move(other.coro_wp);
			sig_wp = std::move(other.sig_wp);

			other.id = -1;
		}

		const handle &handle::schedule() const{
			auto coro = coro_wp.lock();	

			if(coro)
				coro->schedule();

			return *this;
		}
		const handle &handle::yield() const{
			if(is_yieldable()){
				auto coro = coro_wp.lock();

				if(coro)
					coro->yield();
			}

			return *this;
		}

		void handle::join() const{
			auto sig = sig_wp.lock();

			if(sig){
				sig->add_waiting_context(
					get_current());

				flowcontrol::delay_until(*sig);
			}
		}

		unsigned int handle::get_id() const{
			return id;
		}
		bool handle::is_yieldable() const{
			return true;
		}
		void handle::set_yieldable(bool v){

		}
	};
};