#pragma once
#include "tpf.h"
#include <cstdint>
#include <type_traits>
namespace tpf::example
{
    struct sacl;

    //
    // ADT
    //
    struct Zero;
    template <
        typename N
    >
    struct Succ;

    //
    // API (functions)
    //
    struct succ;
    struct sum;
}

//
// TPF definitions
//
template <
    typename N
>
struct tpf::def<tpf::example::succ, N>
{
    using result = tpf::example::Succ<N>;
};

template <
    typename N
>
struct tpf::def<tpf::example::sum, N>
{
    using result = N;
};
template <
    typename... N
>
struct tpf::def<tpf::example::sum, tpf::example::Zero, N...>
{
    using result = tpf::eval<tpf::example::sum, N...>;
};
template <
    typename A,
    typename B,
    typename... N
>
struct tpf::def<tpf::example::sum, tpf::example::Succ<A>, B, N...>
{
    using result = tpf::eval<tpf::example::sum, A, tpf::example::Succ<B>, N...>;
};

namespace tpf::example {
    using _0 = Zero;
    using _1 = tpf::eval<succ, _0>;
    using _2 = tpf::eval<succ, _1>;
    using _3a = tpf::eval<succ, _2>;
    using _3b = tpf::eval<sum, _1, _2>;
    using _3c = tpf::eval<sum, _2, _1>;
    using _3d = tpf::eval<sum, _0, _1, _2>;
    using _3e = tpf::eval<sum, _0, _0, _0, _1, _1, _1, _0, _0, _0, _0>;

    template <
        typename
    >
    struct rt__tc;
    template <
    >
    struct rt__tc<Zero>
    {
        static constexpr std::uint64_t value = 0;
    };
    template <
        typename N
    >
    struct rt__tc<Succ<N>>
    {
        static constexpr std::uint64_t value = rt__tc<N>::value + 1;
    };
    template <
        typename N
    >
    constexpr decltype(auto) rt = rt__tc<N>::value;

    //
    // Proof of concept
    //
    template <
        typename A,
        typename B
    >
    constexpr bool totally_equal =
        std::is_same_v<A, B> &&
        rt<A> == rt<B>
    ;
    static_assert(totally_equal<_3a, _3b>, "");
    static_assert(totally_equal<_3a, _3c>, "");
    static_assert(totally_equal<_3a, _3d>, "");
    static_assert(totally_equal<_3a, _3e>, "");
    static_assert(totally_equal<_3b, _3c>, "");
    static_assert(totally_equal<_3b, _3d>, "");
    static_assert(totally_equal<_3b, _3e>, "");
    static_assert(totally_equal<_3c, _3d>, "");
    static_assert(totally_equal<_3c, _3e>, "");
    static_assert(totally_equal<_3d, _3e>, "");

    template <
        typename OutStream
    >
    inline void print_threes(OutStream&& outs)
    {
        static constexpr auto nl = '\n';
        outs
            << rt<_3a> << nl
            << rt<_3b> << nl
            << rt<_3c> << nl
            << rt<_3d> << nl
            << rt<_3e> << nl
            ;
    }
}
