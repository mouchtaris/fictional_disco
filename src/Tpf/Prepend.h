#pragma once
#include "def.h"
namespace Tpf
{
    namespace sacl { struct Prepend; }

    struct Prepend;


    template <
        typename... Bound
    >
    struct tpf<Prepend, Bound...>
    {
        using type = std::tuple<Prepend, Bound...>;
    };


    template <
        typename... Bound,
        typename... Args
    >
    struct tpf<std::tuple<Prepend, Bound...>, Args...>
    {
        using type = apply<def, Bound..., Args...>;
    };


    extern void _u__mod__Prepend();
}