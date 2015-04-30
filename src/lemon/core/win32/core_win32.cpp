#include "../../lemon.h"

#include <Windows.h>

namespace lemon{
	
	bool initialize(){
		return 
			ConvertThreadToFiber(0) != nullptr ? true : false;
	}
	void quit(){
		ConvertFiberToThread();
	}
};