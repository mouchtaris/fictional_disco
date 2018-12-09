#pragma once
#include "def.h"
namespace Tpf
{

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
        using type = def<Bound..., Args...>;
    };


    extern void _u__mod__Prepend();
}
