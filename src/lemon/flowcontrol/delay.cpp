#include "delay.h"

#include "../microthread/microthread.h"
#include "../dispatcher/dispatcher.h"
#include "../dispatcher/dispatcher_intern.h"

namespace lemon{
	namespace flowcontrol{

		void delay(){
			delay(time::second(0));
		}
		void delay(const time::unit &t){
			dispatcher::timer tmr;
			tmr.remain = t.to_s();

			delay_until(
				dispatcher::main_thread.add_timer(tmr).sig);
		}
		void delay_until(signal &sig){
			sig.wait();
		}
	};
};