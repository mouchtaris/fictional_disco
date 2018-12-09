#pragma once
#include "tpf.h"
#include "Id.h"
namespace Tpf
{
    template <
        typename... Def
    >
    using return_ = apply<apply<Def...>, Id>;



    extern void _u__mod__return_();
}
