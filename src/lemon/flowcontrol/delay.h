#pragma once

#include <stack>

#include "../microthread/task.h"
#include "../time/units.h"
#include "signal.h"

namespace lemon{
	namespace flowcontrol{

		void delay();
		void delay(const time::unit &t);
		void delay_until(signal &s);
	};
};