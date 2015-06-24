#pragma once

#include <functional>

#include "../core/future.h"

namespace lemon{
	namespace multithread{
		class task{
		public:
			task(
				const std::function<void()> &f);
			virtual ~task();
		};

		template <typename T>
		future<T> create(
			const std::function<T()> &func){

			future<T> f;

			pool::enqueue([&f](){
				
			});

			return f;
		}
	};
};