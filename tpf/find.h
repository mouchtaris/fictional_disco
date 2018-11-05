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
        using _select = select<PF>;

        using result = std::tuple_element_t<
            0, 
            f<_select, Ts...>
        >;

        static auto rt(std::tuple<Ts...> t)
        {
            return std::get<0>(rtf<_select>(t));
        }
    };

}
