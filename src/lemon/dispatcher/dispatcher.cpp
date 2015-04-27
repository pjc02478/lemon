#include "dispatcher.h"
#include "dispatcher_intern.h"

#include "../time/time.h"

#include <vector>

using namespace std;

namespace lemon{
	namespace dispatcher{

		vector<timer> pending;
		vector<timer> running;

		timer::timer() :
			last(time::now()){
		}

		timer &add_timer(const timer &t){
			pending.push_back(t);

			return *pending.begin();
		}

		void step(){
			for (auto it = running.begin(); it != running.end();){
				auto t = it;

				t->remain -= time::now() - t->last;
				t->last = time::now();

				if (t->remain <= 0){
					t->sig.notify_one();

					it = running.erase(it);

					if (it == running.end())
						break;
				}

				++it;
			}

			if (!pending.empty()){
				running.insert(
					running.end(),
					pending.begin(), pending.end());
				pending.clear();
			}
		}
	};
};