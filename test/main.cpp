#include "Tpf.h"
#include <iostream>

namespace
{
    constexpr auto nl = "\n";
}

int main(int, char**)
{
    std::cerr << "Initiating test process:" << nl;
    test::Tpf::_u__mod__load();
    test::Tpf::_u__mod__initiate();
    test::Tpf::_u__mod__unload();
    std::cerr << "Testing process -- complete." << nl;
    return 0;
}
