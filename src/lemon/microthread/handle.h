#pragma once

#include <functional>
#include <memory>

#include "../common/interface/handle.h"

namespace lemon{
	namespace flowcontrol{
		class signal;
	};
	namespace microthread{
		class coroutine;

		class handle : public interface::handle{
		public:
			void yield()  const;
			void schedule() const;

			virtual void join() const;
			virtual unsigned int get_id() const;

			bool is_yieldable() const;
			void set_yieldable(bool v);

			handle(handle &&other);
			handle &operator=(handle &&other);

		private:
			handle(const handle &other);
			handle &operator=(const handle &other);

		private:
			unsigned int id;

			std::shared_ptr<flowcontrol::signal> sig;
			std::shared_ptr<coroutine> coro;
		};
	};
};