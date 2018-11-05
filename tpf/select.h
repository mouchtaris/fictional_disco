#include "to_bool.h"
#include "cons.h"

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
    };

}
