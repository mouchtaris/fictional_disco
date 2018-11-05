#pragma once
#include <tuple>

namespace tpf {
    void tupletools_compiled();


    template <
        typename... Ts
    >
    struct tupletools {

        template <
            size_t off,
            size_t... Is
        >
        static auto subtuple(std::tuple<Ts...> t, std::index_sequence<Is...>)
        {
            return std::tuple { std::get<Is + off>(t) ... };
        }

    };

}
