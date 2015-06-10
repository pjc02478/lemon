#pragma once

#include <iostream>

namespace lemon{

	template <typename T>
	class future_base{
	public:
		future_base() :
			has_value(false){
		}

		void wait() const{

		}

	protected:
		T &get_value() const{
			return value;
		}

	private:
		bool has_value;
		T value;
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