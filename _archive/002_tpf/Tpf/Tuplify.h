// SMS:autogenerated_begin
#pragma once
#include "./tpf.h"
namespace Tpf
{
    namespace sacl { struct Tuplify; }
// SMS:autogenerated_end

    struct Tuplify;


    template <
        typename... Ts
    >
    struct tpf<Tuplify, Ts...>
    {
        using type = std::tuple<Ts...>;
    };

// SMS:autogenerated_begin
}
// SMS:autogenerated_end