#include "stdafx.h"

#include <Windows.h>
#include "lemon.h"

#include <string>
#include <iostream>
#include <conio.h>
#include <thread>


#include "multithread/task.h"
#include "profiler/profiler.h"
#include "core/future.h"

using namespace std;
using namespace lemon;

int lemon_main(int argc, char **argv){
	flowcontrol::delay(time::second(1.5));

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
	
	/*
	flowcontrol::signal s;

	auto &handle = microthread::create([&s](){
		printf("hello\n");
		s.wait();
		printf("world\n");
		s.wait();
		printf("bye\n");
	});

	handle.schedule();
	*/

	/*
	flowcontrol::signal s;

	auto &handle = microthread::create([&s](){
		printf("hello\n");
		s.wait();
		printf("world\n");
		s.wait();
		printf("bye\n");
	});

	handle.schedule();
	*/
	
	
	auto &handle = microthread::create([](){
		printf("hello\n");
		flowcontrol::delay();
		printf("world\n");
	});

	handle.schedule();

	auto &handle2 = microthread::create([&handle](){
		handle.join();

		printf("joined\n");
		flowcontrol::delay(time::frame<60>(30));
		printf("delayed\n");
	});
	handle2.schedule();

	multithread::pool::enqueue(
		[](){
		printf("hello world\n");
		Sleep(1000);
		printf("bye world\n");

			dispatcher::get_main().enqueue([](){
				printf("on main %d\n", std::this_thread::get_id());
			});
		});
	
	printf("on main %d\n", std::this_thread::get_id());
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

	/*
	promise<int> pr;

	multithread::pool::enqueue([&pr](){
		Sleep(1000);

		dispatcher::main_thread.enqueue([&pr](){
			pr.set_value(4);
		});
	});

	auto &m = microthread::create([&pr](){
		auto ft = pr.get_future();

		printf("%d\n", std::this_thread::get_id());

		printf("%d\n", ft.get());

		printf("%d\n", std::this_thread::get_id());
	});
	m.schedule();
	*/
	
/*
	auto handle = multithread::create<int>([](){
		Sleep(1000);
		printf("ASDF");

		return 4;
	});

	auto &m = microthread::create([&handle](){
		cout<<handle.get();
	});
	m.schedule();
*/
	while (true){		
		printf("-");

		if (kbhit() && profiler::is_profiling() ){
			auto &&pd = profiler::end();

			pd.print();
		}

		flowcontrol::delay();
	}
}
