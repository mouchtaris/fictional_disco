#include "test_def.h"
#include <iostream>
#include <type_traits>

using namespace __MODULE__;
#define FAIL "Test failure."

namespace
{
    constexpr auto nl = "\n";

    static_assert(std::is_same<def, int>::value, FAIL);
}

void test_def()
{
    std::cerr << "[def] Process initiation." << nl;
    std::cerr << "[def] Process complete. No results." << nl;
}
