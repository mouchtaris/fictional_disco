#pragma once
#include "def.h"
namespace Tpf
{
    namespace _Append { struct sacl; }

    /**
     * The Append TPF.
     *
     */
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
        using type = apply<def, Args..., Bound...>;
    };

}
