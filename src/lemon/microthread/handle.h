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

		class handle : public intf::handle{
		public:
			handle(
				unsigned int id,
				std::weak_ptr<coroutine> coro_wp,
				std::weak_ptr<flowcontrol::signal> sig_wp);
			handle(handle &&);

			const handle &yield() const;
			const handle &schedule() const;

			virtual void join() const;
			virtual unsigned int get_id() const;

			bool is_yieldable() const;
			handle &set_yieldable(bool v);

			handle &operator=(handle &&other);

		private:
			handle(const handle &other);
			handle &operator=(const handle &other);

		private:
			unsigned int id;

			std::weak_ptr<flowcontrol::signal> sig_wp;
			std::weak_ptr<coroutine> coro_wp;
		};
	};
};