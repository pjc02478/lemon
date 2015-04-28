#pragma once

#include <concurrent_queue.h>

namespace lemon{
	namespace multithread{
		
		template <typename T>
		class concurrent_queue{
		public:

			void push(const T &v){
				q.push(v);
			}
			void push(T &&v){
				q.push(v);
			}
			bool try_pop(T &dst){
				return q.try_pop(dst);
			}
			bool empty() const{
				return q.empty();
			}
			void clear(){
				q.clear();
			}

		private:
			concurrency::concurrent_queue<T> q;
		};
	};
};