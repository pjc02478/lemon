#include "pool.h"

#include "../lemon.h"
#ifdef P_WIN32
	#include "../common/win32/concurrent_queue_win32.h"
	#include "../common/win32/event_win32.h"
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

			static sync::concurrent_queue<function<void()>> job_q;
			static mutex job_q_mutex;
			static sync::event sig;
			
			static vector<thread> workers;
			static atomic<unsigned int> busy(0);
			static unsigned int max_workers;

			bool initialize(){
				max_workers =
					thread::hardware_concurrency() * 2;

				return true;
			}
			void quit(){
			
			}

			unsigned int get_workers(){
				return workers.size();
			}

			void invoke(const function<void()> job){
				/* try-catch ?? */
				job();
			}
			void worker_func(const function<void()> &initial_job){
				invoke(initial_job);

				while(true){
					sig.wait();

					function<void()> job;

					while(job_q.try_pop(job)){
						invoke(job);
					}
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