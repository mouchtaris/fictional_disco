#include "test_tpf.h"
#include "tpf.h"
#include "sacl.h"
namespace
{
    using namespace tpf;
    struct nothing;

    struct int2float;
}
template <> struct def<int2float, int> { using result = float; };

void test_tpf()
{
    static_assert(!is_defined<def<nothing>>::value, "");
    static_assert(!is_defined<def<nothing, int>>::value, "");

    static_assert(is_defined<def<int2float, int>>::value, "");
    static_assert(!is_defined<def<int2float>>::value, "");
    static_assert(!is_defined<def<int2float, float>>::value, "");

    static_assert(std::is_same_v<eval<int2float, int>, float>, "");
}
