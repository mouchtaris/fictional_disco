#pragma once
#include "tpf/bind.h"
namespace smaragd::tpf
{
    void _u__compiled();



    template <
        typename... Result
    >
    struct apply
    {
        template <
            template <typename...> typename K
        >
        using type = K<Result...>;
    };
}
