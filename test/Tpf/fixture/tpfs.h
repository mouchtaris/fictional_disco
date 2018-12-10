#pragma once
#include "Tpf/def.h"
namespace test::Tpf::fixture
{
    struct tuplize;

    template <typename = void> struct Zero;
    template <typename = void> struct Next;
    struct Add;
}
namespace Tpf
{
    using namespace test::Tpf::fixture;


    template <
        typename... Ts
    >
    struct tpf<tuplize, Ts...>
    {
        using type = std::tuple<Ts...>;
    };


    template <
        typename a,
        typename b
    >
    struct tpf<Add, a, Next<b>>
    {
        using type = apply<Add, Next<a>, b>;
    };

    template <
        typename a,
        typename z
    >
    struct tpf<Add, a, Zero<z>>
    {
        using type = apply<def, a>;
    };
}
