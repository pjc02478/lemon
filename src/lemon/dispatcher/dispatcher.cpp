#include "dispatcher.h"
#include "dispatcher_intern.h"

#include "../time/time.h"

#include <vector>
#include <queue>

using namespace std;

namespace lemon{
	dispatcher::timer::timer() :
		last(time::now()){
	}

	dispatcher::timer &dispatcher::add_timer(dispatcher::timer &t){
		pending.push_back(t);

		return *pending.rbegin();
	}

	dispatcher dispatcher::main_thread;

	void dispatcher::enqueue(const function<void()> &func){
		jobs.push(func);
	}
	void dispatcher::step(){
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

		while(jobs.empty() == false){
			auto job = jobs.front();
			jobs.pop();

			job();
		}
	}

	void dispatcher::push_binding_policy(dispatcher::binding_policy policy){
		binding_policies.push(policy);
	}
	dispatcher::binding_policy dispatcher::pop_binding_policy(){
		auto policy = binding_policies.top();
		binding_policies.pop();

		return policy;
	}
	dispatcher::binding_policy dispatcher::get_current_binding_policy(){
		return binding_policies.top();
	}
};
