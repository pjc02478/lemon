#include "pool.h"

#include "../lemon.h"
#ifdef P_WIN32
	#include "win32/concurrent_queue_win32.h"
#endif

#include <queue>
#include <thread>
#include <vector>
#include <atomic>
#include <condition_variable>
#include <mutex>

using namespace std;

namespace lemon{
	namespace multithread{
		namespace pool{

			static concurrent_queue<std::function<void()>> q;
			static mutex q_mutex;
			static condition_variable sig;
			
			static vector<thread> workers;
			static atomic<unsigned int> busy(0);
			static unsigned int max_workers;

			bool initialize(unsigned int _max_workers){
				max_workers = _max_workers;

				return true;
			}
			void quit(){
			
			}

			unsigned int get_workers(){
				return workers.size();
			}

			void worker_func(const std::function<void()> &t){
				t();

				while(true){
					
				}
			}

			void enqueue(const std::function<void()> &t){
				auto current = get_workers();

				if(	current - busy == 0 &&
					current < max_workers){

					workers.push_back(
						thread(bind(worker_func, t)));
				}
				else{
					q.push(t);
				}
			}
		};
	};
};