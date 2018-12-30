#include "typelite.h"
#include "lr1.h"
#include "smaragd.h"
#include "sacl.h"
#include "tpf.h"
#include "tpf/example.h"
#include "tpf/lib.h"
#include "../test/test_tpf.h"
#include "../test/test_tpf_lib.h"

#include <iostream>

int main(int, char**)
{
    using namespace tpf::example;
    sacls<
        typelite::sacl_mod,
        lr1::sacl_mod,
        smaragd::sacl_mod,
        tpf::set::sacl_mod,
        tpf::lib::sacl_mod
    >();
    tpf::example::print_threes(std::cout);
    test_tpf();
    test_tpf_lib();
    return 0;
}
