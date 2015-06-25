#include "event_win32.h"

#include <cassert>

using namespace std;

namespace lemon{
	namespace multithread{
		
		event::event() :
			h_event(nullptr){

			h_event = CreateEvent(
				nullptr, false, false, nullptr);
		}
		event::~event(){
			if (h_event){
				CloseHandle(h_event);
				h_event = nullptr;
			}
		}

		void event::wait(){
			assert(h_event != nullptr);

			WaitForSingleObject(
				h_event, INFINITE);
		}
		void event::notify_one(){
			assert(h_event != nullptr);

			SetEvent(h_event);
		}
	};
};