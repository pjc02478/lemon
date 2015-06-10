#include "signal.h"

#include "../microthread/microthread.h"

namespace lemon{
	namespace flowcontrol{
		void signal::wait(){
			auto &current = microthread::get_current();

			add_waiting_context(current);

			current.handle.yield();
		}
		void signal::add_waiting_context(const microthread::task &ctx){
			ctxs.push_back(ctx);
		}
		bool signal::notify_one(){
			if (ctxs.empty())
				return false;
			
			auto &ctx = ctxs.rbegin()->get();
			ctxs.pop_back();
			ctx.handle.schedule();
			
			return true;
		}
		unsigned int signal::notify_all(){
			std::vector<std::reference_wrapper<const microthread::task>> copy(
				ctxs.begin(), ctxs.end());

			unsigned int c = 0;

			// TODO: 코드 정리 notify_one 쓰도록
			for(auto &ctx : copy){
				auto &ctx = ctxs.rbegin()->get();
				ctxs.pop_back();
				ctx.handle.schedule();

				c++;
			}

			return c;
		}
	};
};