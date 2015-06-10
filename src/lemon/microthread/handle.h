#pragma once

#include <functional>
#include <memory>

#include "../common/interface/handle.h"

namespace lemon{
	namespace time{
		struct unit;
	};
	namespace flowcontrol{
		class signal;
	};
	namespace microthread{
		class coroutine;

		class handle : public intf::handle<handle>{
		public:
			handle(
				id_t id,
				std::weak_ptr<coroutine> coro_wp,
				std::weak_ptr<flowcontrol::signal> sig_wp);
			handle(handle &&);

			const handle &defer(const time::unit &t) const;

			const handle &yield() const;
			const handle &schedule() const;

			virtual void join() const;
			virtual id_t get_id() const;

			bool is_yieldable() const;
			handle &set_yieldable(bool v);

			handle &operator=(handle &&other);

		private:
			handle(const handle &other);
			handle &operator=(const handle &other);

		private:
			id_t id;

			std::weak_ptr<flowcontrol::signal> sig_wp;
			std::weak_ptr<coroutine> coro_wp;
		};
	};
};