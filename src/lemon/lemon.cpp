﻿#include "stdafx.h"

#include <Windows.h>
#include "lemon.h"

#include <string>
#include <iostream>
#include <conio.h>
#include <thread>


#include "profiler/profiler.h"

using namespace std;
using namespace lemon;

void main(){
	ConvertThreadToFiber(0);

	profiler::start();

	lemon::microthread::task a([](){
		printf("123\n");

		flowcontrol::delay();
		
		printf("456\n");
	});
	a.schedule();

	__NAME("hello_task")
	lemon::microthread::task b([](){
		flowcontrol::delay(time::second(0.5f));

		printf("ASDF\n");

		flowcontrol::delay(time::second(1.4f));

		printf("QWER\n");
	});
	//b.schedule();

	microthread::task abc([](){});
	{
	microthread::task abc1([](){
		while(true){
		//	printf("QQ\n");
			flowcontrol::delay(time::frame<60>(1));
		}
	});

	abc1.schedule();
	//bb = abc2;
	abc = std::move(abc1);
	}

	while (true){		
		lemon::dispatcher::step();

		printf("-");
		Sleep(1000 / 60);

		if (kbhit() && profiler::is_profiling() ){
			auto &&pd = profiler::end();

			pd.print();
		}
	}
}
