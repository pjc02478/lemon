#pragma once

#include <functional>
#include <vector>
#include <queue>
#include <stack>

#include "../flowcontrol/signal.h"

namespace lemon{
	namespace sync{
		template <typename T>
		class concurrent_queue;
	};

	struct timer;

	class dispatcher{
	public:
		struct timer{
			float remain;
			float last;

			flowcontrol::signal sig;

			timer();
		};
		enum class binding_policy{
			bind_current,
			bind_any_worker,
			bind_main
		};

	public:
		static dispatcher &get_main();
		static dispatcher &get_current();
		static void set_main(dispatcher *main);

	private:
		static dispatcher *main;

	public:
		timer &add_timer(timer &t);

		void enqueue(const std::function<void()> &func);
		void step();
		void sleep(const time::unit &time);

		void push_binding_policy(binding_policy policy);
		binding_policy pop_binding_policy();
		binding_policy get_current_binding_policy();

	private:
		/* therad_safe 패치 필요 */
		std::vector<timer> pending;
		std::vector<timer> running;
		std::queue<std::function<void()>> jobs;
		std::stack<binding_policy> binding_policies;
	};
};