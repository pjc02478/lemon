#pragma once

#include <iostream>
#include <atomic>

#include "../flowcontrol/signal.h"

namespace lemon{
	template <typename T>
	class shared_state{
	public:
		shared_state() :
			has_value(false){
		}

		void set_value(T &&val){
			value = std::forward<T>(val);

			has_value = true;
			sig.notify_all();
		}
		void set_value(const T &val){
			value = val;

			has_value = true;
			sig.notify_all();
		}

		T &get_value(){
			if(has_value == false)
				sig.wait();

			return value;
		}

		void wait(){
			sig.wait();
		}


	private:
		flowcontrol::signal sig;
		std::atomic<bool> has_value;

		T value;
	};

	template <typename T>
	class future_base{
	public:
		future_base(){
		}
		future_base(std::shared_ptr<shared_state<T>> state) :
			state(state){
		}

		void wait() const{
			shared_state->wait();
		}

	protected:
		T &get_value() const{
			return state->get_value();
		}

	private:
		std::shared_ptr<shared_state<T>> state;
	};
	
	template <typename T>
	class future : public future_base<T>{
	public:
		future(){
		}
		future(std::shared_ptr<shared_state<T>> state) :
			future_base<T>(state){

		}

		T get(){
			return std::move(get_value());
		}
	};

	template <typename T>
	class future<T&> : public future_base<T*>{
	public:
		future(){
		}
		future(std::shared_ptr<shared_state<T>> state) :
			future_base<T*>(state){

		}

		T& get(){
			return *get_value();
		}
	};

	template <typename T>
	class promise_base{
	public:
		promise_base() :
			state(new shared_state<T>()){
		}

		void set_value(T &&val){
			state->set_value(std::forward<T>(val));
		}
		void set_value(const T &val){
			state->set_value(val);
		}

		future<T> get_future(){
			return future<T>(state);
		}

	private:
		std::shared_ptr<shared_state<T>> state;
	};

	template <typename T>
	class promise : public promise_base<T>{
	};

	template <typename T>
	class promise<T&> : public promise_base<T*>{
	public:
	};
};