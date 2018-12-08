#include "test.h"
#include <iostream>

namespace
{
    constexpr auto nl = "\n";
}

int main(int, char**)
{
    std::cerr << "Welcome to experiment #0000: *** TPF *** [Pilot]" << nl;
    ::_u__test__load();
    ::_u__test__unload();
}
