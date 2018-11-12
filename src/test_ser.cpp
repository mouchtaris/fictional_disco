#include "ser.h"
#include <tuple>
#include <cstdint>
#include <cassert>

using namespace std;

void test_ser()
{

    ser_compiled();

    auto test = [](auto n)
    {
        assert(deser<decltype(n)>(ser(n)) == n);
    };

    for (uint64_t i = 0; i < 126; ++i) {
        test(static_cast<uint8_t>(i));
        test(static_cast<uint16_t>(i));
        test(static_cast<uint32_t>(i));
        test(static_cast<uint64_t>(i));
    }
}
