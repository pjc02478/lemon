#pragma once

namespace lemon{
	namespace intf{

		template<typename T, typename DEFAULT>
		struct get_id_type{
			template<typename Arg>
			static auto Fn(int)
				->decltype(T::id());
			template<typename Arg>
			static auto Fn(...)
				->DEFAULT;

			using type = decltype(Fn<T>(0));
		};

		//template <typename T>
		class handle{
			//using id_t =
			//	typename get_id_type<T, unsigned int>::type;

		public:
			//virtual id_t get_id() const =0;
			virtual unsigned int get_id() const =0;
			virtual void join() const =0;
		};
	};
};