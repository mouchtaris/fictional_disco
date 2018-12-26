#pragma once
#include "./tpf.h"
namespace Tpf
{
    namespace _Id { struct sacl; }

    /**
     * def Id x = x
     */
    struct Id;

    template <
        typename T
    >
    struct tpf<Id, T>
    {
        using type = T;
    };

}
