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
		class handle{
		public:
			handle(future<T> &&ft) :
				ft(ft){
			}

			T get(){
				return ft.get();
			}

		private:
			future<T> ft;
		};

		template <typename T>
		handle<T> create(
			const std::function<T()> &func){

			promise<T> pr;

			pool::enqueue([pr, func]() mutable {
				/* tODO : switching bug */
				pr.set_value(func());
			});

			return handle<T>(
				std::move(pr.get_future()));
		}
	};
};