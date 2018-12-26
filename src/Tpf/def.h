#pragma once
#include "./tpf.h"
#include <type_traits>
namespace Tpf
{
    namespace sacl { struct def; }

    struct def;
    template <typename...> struct Definition;

    template <
        typename... Def
    >
    struct tpf<def, Def...>
    {
        using type = Definition<Def...>;
    };

    template <
        typename... Def,
        typename F
    >
    struct tpf<Definition<Def...>, F>
    {
        using type = Tpf::apply<F, Def...>;
    };

}
