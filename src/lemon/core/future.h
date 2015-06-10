#pragma once

#include <iostream>

#include "../flowcontrol/signal.h"

namespace lemon{

	template <typename T>
	class future_base{
	public:
		future_base() :
			has_value(false){
		}

		void wait() const{
			sig.wait();
		}

	protected:
		T &get_value() const{
			return value;
		}

	private:
		flowcontrol::signal sig;

		T value;
		bool has_value;
	};
	
	template <typename T>
	class future : public future_base<T>{
	public:
		T get(){
			return std::move(
				get_value());
		}
	};

	template <typename T>
	class future<T&> : public future_base<T*>{
	public:
		T& get(){
			return *get_value();
		}
	};
};