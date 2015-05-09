#include "pool.h"

#include "../lemon.h"
#ifdef P_WIN32
	#include "win32/concurrent_queue_win32.h"
	#include "win32/event_win32.h"
#endif

#include "../core/core_intern.h"

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

			static concurrent_queue<function<void()>> job_q;
			static mutex job_q_mutex;
			static event sig;
			
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

			void worker_func(const function<void()> &initial_job){
				initial_job();

				while(true){
					sig.wait();

					function<void()> job;

					if(!job_q.try_pop(job))
						continue;

					job();
				}
			}

			void enqueue(const function<void()> &job){
				/* enqueue는 외부 스레드에서 실행될 수 없다 */
				assert(get_mainthread_id() == this_thread::get_id());

				auto current = get_workers();

				if(	current - busy == 0 &&
					current < max_workers){

					workers.push_back(
						thread(bind(worker_func, job)));
				}
				else{
					job_q.push(job);
				}
			}
		};
	};
};