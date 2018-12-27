#pragma once
#include <type_traits>
namespace tpf
{
    struct sacl_mod;



    template <
        typename...
    >
    struct def;



    template <
        typename,
        typename = std::void_t<>
    >
    struct is_defined__tc: public std::false_type{};
    //
    template <
        typename Tpf
    >
    struct is_defined__tc<
        Tpf,
        std::void_t<typename Tpf::result>
    >
    : public std::true_type{};
    //
    template <
        typename Tpf
    >
    using is_defined = is_defined__tc<Tpf>;



    template <
        typename... Bound
    >
    struct BoundFront;
    //
    template <
        typename... Bound,
        typename F,
        typename... Args
    >
    struct def<BoundFront<Bound...>, F, Args...>
    {
        using result = typename def<F, Bound..., Args...>::result;
    };



    template <
        typename... Seq
    >
    struct eval__tc
    {
        using result = std::enable_if_t<
            std::conjunction_v<
                is_defined<def<Seq...>>
            >,
            typename def<Seq...>::result
        >;
    };
    //
    template <
        typename... Seq
    >
    using eval = typename eval__tc<Seq...>::result;
}
