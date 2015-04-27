#include "time.h"

#include <Windows.h>

namespace lemon{
	namespace time{
		
		/* TODO : std::chrono·Î ±³Ã¼ */
		float now(){
			return GetTickCount() / 1000.0f;
		}
	};
};