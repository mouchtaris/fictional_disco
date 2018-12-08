#include "test_def.h"
#include "fixture/tpfs.h"
#include <iostream>
#include <type_traits>

#define FAIL "Test failure."
using namespace test::Tpf;

namespace
{
    constexpr auto nl = "\n";

    namespace t_def_1_tuplize
    {
        struct a;

        using expected = std::tuple<a>;

        using def = Tpf::apply<Tpf::def, a>;
        using subject = Tpf::apply<def, fixture::tuplize>;

        static_assert(std::is_same_v<subject, expected>, FAIL);
    }

    namespace t_def_2_tuplize
    {
        struct a;
        struct b;

        using expected = std::tuple<a, b>;

        using def = Tpf::apply<Tpf::def, a, b>;
        using subject = Tpf::apply<def, fixture::tuplize>;

        static_assert(std::is_same_v<subject, expected>, FAIL);
    }
}

void test_def()
{
    std::cerr << "[def] Process initiation." << nl;
    std::cerr << "[def] Process complete. No results." << nl;
}
