#pragma once
#include "tpf/set.h"
#include <cstdint>
#include <array>
namespace smaragd
{
    struct sacl_mod;

    namespace N {
        struct x;
        struct z;

        struct _make_set {
            using r0 = tpf::eval<tpf::set::init>;
            using r1 = tpf::eval<tpf::set::add, r0, x>;
            using r2 = tpf::eval<tpf::set::add, r1, z>;
            using result = r2;
        };

        using set = _make_set::result;
    }

    namespace Σ {
        struct S;
        struct E;
    }
}
