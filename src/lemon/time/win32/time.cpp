#include "time.h"
#include <chrono>

#include <Windows.h>

namespace lemon{
	namespace time{
		
		/* TODO : std::chrono·Î ±³Ã¼ */
		float now(){
			std::chrono::duration<double> dTime =
			std::chrono::high_resolution_clock::now().time_since_epoch();

			return static_cast<float>(dTime.count());
		}
	};
};