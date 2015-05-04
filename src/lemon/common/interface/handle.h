#pragma once

namespace lemon{
	namespace interface{

		class handle{
		public:

			virtual unsigned int get_id() =0;
			virtual void join() =0;
		};
	};
};