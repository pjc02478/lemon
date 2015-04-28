#include "time.h"
#include <chrono>

using namespace std;

namespace lemon{
	namespace time{
		
		float now(){
			static auto startTime = chrono::high_resolution_clock::now();
			auto nowTime = chrono::high_resolution_clock::now();

			chrono::duration<float> dTime = nowTime - startTime;

			return dTime.count();
		}
	};
};
