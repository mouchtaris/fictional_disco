#include "cons.h"

void tpf::cons_compiled() {}

namespace {

    static_assert(
        std::is_same_v<
            tpf::f<tpf::cons, int, std::tuple<float>>,
            std::tuple<int, float>
        >,
        ""
    );


}
