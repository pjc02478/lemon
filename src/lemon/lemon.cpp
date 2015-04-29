#include "stdafx.h"

#include <Windows.h>
#include "lemon.h"

#include <string>
#include <iostream>

using namespace std;
using namespace lemon;

void main(){
	ConvertThreadToFiber(0);

	lemon::microthread::task a([](){
		printf("123\n");

		flowcontrol::delay(time::second(1.4f));
		
		printf("456\n");
	});
	a.schedule();

	while (true){		
		lemon::dispatcher::step();

		printf("-");
		Sleep(11);
	}
}
