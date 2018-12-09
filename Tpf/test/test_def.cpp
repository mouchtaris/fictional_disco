#include "test_def.h"
#include "fixture/tpfs.h"
#include <iostream>
#include <type_traits>
#include <tuple>

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

    namespace t_fixture_Add
    {
        using namespace fixture;
        using Tpf::apply;
        using Tpf::id;
        using Tpf::return_;

        using _0 = Zero<>;
        using _1 = Next<_0>;
        using _2 = Next<_1>;
        using _3 = Next<_2>;

        template <
            typename a,
            typename b
        >
        using plus = apply<apply<Add, a, b>, id>;

        template <
            typename a,
            typename b
        >
        constexpr auto eq = std::conjunction_v<std::is_same<a, b>>;

        static_assert(eq< plus<_0, _0>, _0>, FAIL);
        static_assert(eq< plus<_0, _1>, _1>, FAIL);
        static_assert(eq< plus<_1, _0>, _1>, FAIL);
        static_assert(eq< plus<_1, _1>, _2>, FAIL);
        static_assert(eq< plus<_1, _2>, _3>, FAIL);
        static_assert(eq< plus<_2, _1>, _3>, FAIL);
        static_assert(eq< plus<_3, _0>, _3>, FAIL);
        static_assert(eq< plus<_0, _3>, _3>, FAIL);

        static_assert(eq< plus<_1, _2>, plus<_2, _1> >, FAIL);


        static_assert(eq< plus<_1, _2>, return_<Add, _2, _1> >, FAIL);


        static_assert(eq<
                return_<Add,
                    return_<Add, _1, _0>,
                    return_<Add, _0, _2>
                >,
                _3
            >, FAIL);
        static_assert(eq<
                _3,
                return_<Add,
                    return_<Add, _1, _1>,
                    return_<Add, _0, _1>
                >
            >, FAIL);
        static_assert(eq<
                return_<Add,
                    return_<Add, _1, _0>,
                    return_<Add, _0, _2>
                >,
                return_<Add,
                    return_<Add, _1, _1>,
                    return_<Add, _0, _1>
                >
            >, FAIL);
    }
}

void test_def()
{
    std::cerr << "[def] Process initiation." << nl;
    std::cerr << "[def] Process complete. No results." << nl;
}
