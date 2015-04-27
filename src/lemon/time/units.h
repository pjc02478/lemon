#pragma once

namespace lemon{
	namespace time{
		struct unit{
			unit(float value) : value(value) {};
			virtual float to_s() const = 0;

			float value;
		};
		template <int TARGET>
		struct frame : unit{
			/* seconds per frame */
			static const float spf;

			frame(float value) : unit(value) {}

			virtual float to_s() const{
				return spf * value;
			}
		};
		template <int TARGET>
		const float frame<TARGET>::spf = 1.0f / TARGET;

		struct second : unit{
			second(float value) : unit(value) {}

			virtual float to_s() const{
				return value;
			}
		};
		struct millisecond : unit{
			millisecond(float value) : unit(value) {}

			virtual float to_s() const{
				return value / 1000.0f;
			}
		};
	};
};