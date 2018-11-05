#pragma once
#include <tuple>
#include <functional>

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
        using application = applicator<PF, Args...>;
        using result = typename application::result;
    };

    template <
        typename PF,
        typename... Args
    >
    using f = typename apply<PF, Args...>::result;

    template <
        typename PF,
        typename Argpack
    >
    using tf = typename apply_tuple<PF, Argpack>::result;

    template <
        typename PF,
        typename... Args
    >
    auto rtf(Args&&... args)
    {
        return apply<PF, Args...>::rt(std::forward<Args>(args)...);
    }

    template <
        typename PF,
        typename Argpack
    >
    auto rttf(Argpack&& argpack)
    {
        return std::apply(
            apply_tuple<PF, Argpack>::application::rt,
            std::forward<Argpack>(argpack)
        );
    }

}
