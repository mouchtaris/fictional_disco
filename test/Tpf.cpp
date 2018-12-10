#include "test.h"
#include <iostream>
namespace test::Tpf
{

namespace
{
    constexpr auto nl = "\n";
}


void _u__mod__load()
{
    std::cerr << "[test] Module loaded." << nl;
}

void _u__mod__unload()
{
    std::cerr << "[test] Module unloaded." << nl;
}

void _u__mod__initiate()
{
    std::cerr << "Welcome to experiment #0000: *** TPF *** [Pilot]" << nl;
    ::test_def();
}

}
