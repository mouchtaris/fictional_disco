#pragma once
#include "def.h"
namespace Tpf
{
    struct Append;


    template <
        typename... Bound
    >
    struct tpf<Append, Bound...>
    {
        using type = std::tuple<Append, Bound...>;
    };


    template <
        typename... Bound,
        typename... Args
    >
    struct tpf<std::tuple<Append, Bound...>, Args...>
    {
        using type = def<Args..., Bound...>;
    };


    extern void _u__mod__Append();
}
