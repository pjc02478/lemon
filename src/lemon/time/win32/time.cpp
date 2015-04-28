#include "time.h"
#include <chrono>

using namespace std;

namespace lemon{
	namespace time{
		static auto uptime_since = chrono::system_clock::now();

		float now(){
			auto _now = chrono::system_clock::now();

			return (chrono::duration<float>(_now - uptime_since)).count();
		}
	};
};
