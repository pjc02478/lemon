#pragma once

#include "../flowcontrol/signal.h"

namespace lemon{
	namespace dispatcher{

		struct timer{
			float remain;
			float last;

			flowcontrol::signal sig;

			timer();
		};

		timer &add_timer(const timer &t);
	};
};