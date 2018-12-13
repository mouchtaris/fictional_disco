// SMS:autogenerated_begin
#pragma once
#include "def.h"
namespace Tpf
{
    namespace sacl { struct Append; }
// SMS:autogenerated_end

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

// SMS:autogenerated_begin
}
// SMS:autogenerated_end
