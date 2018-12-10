#pragma once
#include "tpf.h"
namespace Tpf
{
    namespace sacl { struct Id; }

    struct Id;


    template <
        typename T
    >
    struct tpf<Id, T>
    {
        using type = T;
    };



    extern void _u__mod__Id();
}
