#include "main.h"
#include "core.h"

#include "../microthread/task.h"
#include "../dispatcher/dispatcher.h"
#include "../time/units.h"

int main(int argc, char **argv){
	lemon::initialize();

	auto &h = lemon::microthread::create(
		[argc, argv](){
			lemon_main(argc, argv);
		});
	h.schedule();

	while(true){
		lemon::dispatcher::get_current().sleep(
			lemon::time::second(0.01));

		printf("A");
	}
}