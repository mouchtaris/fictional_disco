#include "bind.h"
#include "templ.h"
#include <type_traits>

void tpf::bind_compiled() {}

namespace {

    using is_same = tpf::templ<std::is_same>;
    using is_int = tpf::bind<is_same, int>;

    static_assert(
        tpf::f<is_int, int>::value,
        ""
    );

}
