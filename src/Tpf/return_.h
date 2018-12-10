#pragma once
#include "tpf.h"
#include "Id.h"
namespace Tpf
{
    namespace sacl { struct return_; }

    template <
        typename... Def
    >
    using return_ = apply<apply<Def...>, Id>;



    extern void _u__mod__return_();
}
