#pragma once

#include <stack>

#include "../microthread/task.h"
#include "../time/units.h"
#include "signal.h"

namespace lemon{
	namespace flowcontrol{

		/* 시간에 관계 없이 1 step 대기합니다. */
		void delay();
		/* 지정된 시간만큼 대기합니다 */
		void delay(const time::unit &t);
		/* 지정된 signal 오브젝트에 알림이 올 때 까지 대기합니다 */
		void delay_until(signal &s);
	};
};