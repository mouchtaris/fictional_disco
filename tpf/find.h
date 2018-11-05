#include "select.h"

namespace tpf {
    void find_compiled();

    template <
        typename PF
    >
    struct find;
    template <
        typename PF,
        typename... Ts
    >
    struct apply<find<PF>, Ts...> {
        using result = std::tuple_element_t<
            0, 
            f<select<PF>, Ts...>
        >;
    };

}
