#include "./select.h"

struct isint;
template <
    typename T
>
struct tpf::apply<isint, T> {
    using result = std::is_same<int, T>;
};

void tpf::select_compiled() {}

namespace {

    using tpf::f;
    using tpf::select;
    using tpf::apply;

    static_assert(
        std::is_same_v<
            f<select<isint>, bool, float, double, int>,
            std::tuple<int>
        >,
        ""
    );

}
