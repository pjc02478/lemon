#include "signal.h"

#include "../microthread/microthread.h"

namespace lemon{
	namespace flowcontrol{
		void signal::wait(){
			add_waiting_context(
				microthread::get_current());
		}
		void signal::add_waiting_context(const microthread::task &ctx){
			ctxs.push(ctx);
		}
		bool signal::notify_one(){
			if (ctxs.empty())
				return false;
			
			auto &ctx = ctxs.top().get();
			ctxs.pop();
			ctx.handle.schedule();
			
			return true;
		}
		unsigned int signal::notify_all(){
			unsigned int c = 0;

			while (notify_one())
				c++;

			return c;
		}
	};
};