#include "test_tpf_lib.h"
#include "tpf/set.h"

#define RESULT(R, CALL)                         \
    static_assert(is_defined<CALL>::value, ""); \
    using R = CALL::result                      \


void test_tpf_lib()
{
    using namespace tpf;

    using call0 = def<set::init>;
    static_assert(is_defined<call0>::value, "");
    using s0 = call0::result;

    struct el0;
    struct el1;

    using call1 = def<set::_push, s0, el0>;
    RESULT(s1, call1);

    using call2 = def<set::_contains, s1, el0>;
    RESULT(s2, call2);
}
