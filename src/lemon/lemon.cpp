// test.cpp : 肄섏넄 �쓳�슜 �봽濡쒓렇�옩�뿉 �?�븳 吏꾩엯�젏�쓣 �젙�쓽�빀�땲�떎.
//

#include "stdafx.h"

#include <Windows.h>
#include "lemon.h"

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
