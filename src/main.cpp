#include "typelite.h"
#include "lr1.h"
#include "smaragd.h"
#include "sacl.h"
#include "tpf.h"
#include "tpf/example.h"
#include "../test/test_tpf.h"

#include <iostream>


static constexpr auto nl = '\n';

int main(int, char**)
{
    using namespace tpf::example;
    sacls<
        typelite::sacl_mod,
        lr1::sacl_mod,
        smaragd::sacl_mod
    >();
    tpf::example::print_threes(std::cout);
    test_tpf();
    return 0;
}
