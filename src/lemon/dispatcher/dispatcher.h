#pragma once

#include <functional>
#include <vector>
#include <queue>

#include "../flowcontrol/signal.h"

namespace lemon{
	struct timer;

	class dispatcher{
	public:
		struct timer{
			float remain;
			float last;

			flowcontrol::signal sig;

			timer();
		};

	public:
		static dispatcher main_thread;

	public:
		timer &add_timer(timer &t);

		void enqueue(const std::function<void()> &func);
		void step();

	private:
		/* therad_safe ÆÐÄ¡ */
		std::vector<timer> pending;
		std::vector<timer> running;
		std::queue<std::function<void()>> jobs;
	};
};