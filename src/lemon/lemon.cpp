#include "stdafx.h"

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

	/*
	lemon::microthread::task a([](){
		printf("123\n");

		flowcontrol::delay(time::second(1));
		
		printf("456\n");
	});
	a.schedule();

	__NAME("hello_task")
	lemon::microthread::task b([&a](){
		a.join();
		printf("a joined\n");

		flowcontrol::delay(time::second(0.5f));

		printf("ASDF\n");

		flowcontrol::delay(time::second(1.4f));

		printf("QWER\n");

		microthread::task c([](){
			printf("hello c\n");
			flowcontrol::delay(time::second(1.4f));
			printf("bye c\n");
		});
		c.schedule();

		printf("end of c\n");
	});
	b.schedule();
	*/
	
	auto handle = microthread::create([](){
		printf("hello\n");
		flowcontrol::delay();
		printf("world\n");
	});

	handle.schedule();

	auto handle2 = microthread::create([&handle](){
		handle.join();

		printf("joined\n");
		flowcontrol::delay(time::frame<60>(30));
		printf("delayed\n");
	});
	handle2.schedule();


	/*
	microthread::task abc([](){});
	{
	microthread::task abc1([](){
		while(true){
		//	printf("QQ\n");
			printf("tt %x\n", &microthread::get_current());
			flowcontrol::delay(time::frame<60>(1));
		}
	});

	abc1.schedule();
	printf("sched2\n");
	//bb = abc2;
	abc = std::move(abc1);
	}
	*/

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
