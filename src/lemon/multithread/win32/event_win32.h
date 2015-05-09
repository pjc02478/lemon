#pragma once

#include <windows.h>

namespace lemon{
	namespace multithread{
		
		class event{
		public:
			event();
			virtual ~event();

			void wait();

			void notify_one();

		private:
			HANDLE h_event;
		};
	};
};