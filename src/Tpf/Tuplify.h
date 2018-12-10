#pragma once
#include "tpf.h"
namespace Tpf
{
    namespace sacl { struct Tuplify; }

    struct Tuplify;


    template <
        typename... Ts
    >
    struct tpf<Tuplify, Ts...>
    {
        using type = std::tuple<Ts...>;
    };


    void _u__mod__Tuplify();
}
