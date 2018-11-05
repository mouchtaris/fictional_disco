#include "to_bool.h"
#include "cons.h"
#include "tupletools.h"

namespace tpf {
    void select_compiled();

    template <
        typename PF
    >
    struct select;
    template <
        typename PF
    >
    struct apply<select<PF>> {
        using result = std::tuple<>;

        static std::tuple<> rt(std::tuple<> t)
        {
            return t;
        }
    };

    template <
        typename PF,
        bool selected,
        typename... Ts
    >
    struct _apply_impl;
    template <
        typename PF,
        typename... Ts
    >
    struct _apply_impl<PF, false, Ts...> {
    };


    template <
        typename PF,
        typename T,
        typename... Ts
    >
    struct apply<select<PF>, T, Ts...> {
        using _condition = 
            f<to_bool, f<PF, T>>
        ;
        using result = std::conditional_t<
            _condition::value,
            f<cons, T, f<select<PF>, Ts...>>,
            f<select<PF>, Ts...>
        >;

        static auto rt(std::tuple<T, Ts...> t)
        {
            auto mine = std::tuple { std::get<0>(t) };
            constexpr size_t rest_size = sizeof...(Ts);

            if constexpr(rest_size == 0) {
                if constexpr(_condition::value)
                    return std::move(mine);
                if constexpr(!_condition::value)
                    return std::tuple {};
            }

            if constexpr(rest_size > 0) {
                constexpr auto idx = std::make_index_sequence<rest_size> {};
                auto subitems = tupletools<T, Ts...>::template subtuple<1>(std::move(t), idx);
                auto rest = apply<select<PF>, Ts...>::rt(std::move(subitems));

                if constexpr(_condition::value)
                    return std::tuple_cat(std::move(mine), std::move(rest));
                if constexpr(!_condition::value)
                    return std::move(rest);
            }
        }
    };
}
