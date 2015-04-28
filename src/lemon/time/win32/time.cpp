#include "time.h"
#include <chrono>

using namespace std;

namespace lemon{
	namespace time{
		
		float now(){
			chrono::duration<double> dTime =
			chrono::high_resolution_clock::now().time_since_epoch();

			return static_cast<float>(dTime.count());
		}
	};
};
