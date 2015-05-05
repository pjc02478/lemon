#pragma once

#include <functional>
#include <memory>

#include "handle.h"

namespace lemon{
	namespace flowcontrol{
		class signal;
	};
	namespace microthread{
		class coroutine;

		struct task{
			unsigned int id;
			std::shared_ptr<flowcontrol::signal> sig;
			std::shared_ptr<coroutine> coro;

			task(
				unsigned int _id,
				const std::function<void()> &f);

			handle create_handle() const;
		};

		handle create(
			const std::function<void()> &f);
	};
};