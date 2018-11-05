#include "find.h"

void tpf::find_compiled() {}

struct isint;
template <typename T> struct tpf::apply<isint, T> { using result = std::is_same<int, T>; };

namespace {
    using tpf::find;
    using tpf::f;

    static_assert(
        std::is_same_v<
            f<find<isint>, bool, float, double, int>,
            int
        >,
        ""
    );

}
