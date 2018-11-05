#include "templ.h"
#include <type_traits>

void tpf::templ_compiled() {}

namespace {

    static_assert(
        tpf::f<tpf::templ<std::is_same>, int, int>::value,
        ""
    );

}
