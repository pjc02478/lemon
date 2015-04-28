#include "pool.h"

#include "../lemon.h"
#ifdef P_WIN32
	#include "win32/concurrent_queue_win32.h"
#endif

#include <thread>

using namespace std;

namespace lemon{
	namespace multithread{
		namespace pool{

			static concurrent_queue<std::function<void()>> q;

			bool initialize(){

				return true;
			}
			void quit(){

			}

			unsigned int get_workers(){
				return 0;
			}

			void enqueue(const std::function<void()> &t){
				q.push(t);
			}
		};
	};
};