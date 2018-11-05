#include "apply.h"
#include <tuple>

namespace tpf {
    void cons_compiled();

    struct cons;
    template <
        typename T,
        typename... Ts
    >
    struct apply<cons, T, std::tuple<Ts...>> {
        using result = std::tuple<T, Ts...>;
    };

}
