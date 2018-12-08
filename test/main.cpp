#include "../Tpf/test/test.h"
#include <iostream>

namespace
{
    constexpr auto nl = "\n";
}

int main(int, char**)
{
    test::Tpf::_u__mod__load();
    test::Tpf::_u__mod__initiate();
    test::Tpf::_u__mod__unload();
    return 0;
}
