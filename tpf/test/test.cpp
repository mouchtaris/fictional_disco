#include "test.h"
#include <iostream>

namespace
{
    constexpr auto nl = "\n";
}

void _u__test__load()
{
    std::cerr << "[test] Module loaded." << nl;
    ::test_def();
}

void _u__test__unload()
{
    std::cerr << "[test] Module unloaded." << nl;
}
