#include "task.h"
#include "pool.h"

#include <thread>

using namespace std;

namespace lemon{
	namespace multithread{
		task::task(
			const std::function<void()> &f){
		}
		task::~task(){
		}
	};
};