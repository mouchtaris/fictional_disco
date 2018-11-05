#pragma once
#include <tuple>

namespace tpf {

    template <
        typename PF,
        typename... Args
    >
    struct apply;

    template <
        typename PF,
        typename Argpack,
        template <typename, typename...> typename applicator = apply
    >
    struct apply_tuple;
    template <
        typename PF,
        typename... Args,
        template <typename, typename...> typename applicator
    >
    struct apply_tuple<PF, std::tuple<Args...>, applicator> {
        using result = typename applicator<PF, Args...>::result;
    };

    template <
        typename PF,
        typename... Args
    >
    using f = typename apply<PF, Args...>::result;

}
