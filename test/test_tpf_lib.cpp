#include "test_tpf_lib.h"
#include "tpf/set.h"
#include "tpf/lib.h"
#include <iostream>

#define RESULT(R, CALL)                         \
    static_assert(is_defined<CALL>::value, ""); \
    using R = CALL::result                      \

#define TESTING(wat) std::cerr << "Testing " wat << nl

namespace
{
    constexpr auto nl = '\n';
    using namespace tpf;

    void test_tpf_set()
    {
        TESTING("tpf_set");

        using call0 = def<set::init>;
        static_assert(is_defined<call0>::value, "");
        using s0 = call0::result;

        struct el0;
        struct el1;

        using call1 = def<set::_push, s0, el0>;
        RESULT(s1, call1);

        using call2 = def<set::contains, s1, el0>;
        static_assert(is_defined<call2>::value, "");

        using call3 = def<set::contains, s1, el1>;
        RESULT(b3, call3);
        static_assert(!b3::value, "");

        using call4 = def<set::_push, s1, el1>;
        RESULT(s4, call4);

        using call5 = def<set::contains, s4, el1>;
        RESULT(b5, call5);
        static_assert(b5::value, "");

        using call6 = def<set::add, s4, el1>;
        RESULT(s6, call6);
        static_assert(eval<set::contains, s6, el1>::value, "");
        static_assert(eval<set::_default_cmp, s4, s6>::value, "");

        struct el2;
        using call7 = def<set::add, s6, el2>;
        RESULT(s7, call7);
        static_assert(eval<set::contains, s7, el2>::value, "");
        using call8 = def<set::add, s7, el2>;
        RESULT(s8, call8);
        static_assert(eval<set::_default_cmp, s7, s8>::value, "");
    }

    void test_lib_closure()
    {
        TESTING("lib_closure");

        using c = lib::Closure<set::init>;
        static_assert(is_defined<def<c>>::value, "");

        using c0 = eval<
            lib::closure,
            set::add,
            eval<c>
        >;

        struct el0;

        using s1 = eval<c0, el0>;
        static_assert(eval<set::contains, s1, el0>::value, "");
    }

    void test_lib_bind_front()
    {
        TESTING("lib_bind_front");
        struct el0;

        using s0 = eval<set::init>;
        using bound = eval<lib::bind_front, s0>;
        using r0 = eval<bound, set::add, el0>;
        using r1 = eval<set::add, s0, el0>;

        static_assert(eval<set::_default_cmp, r0, r1>::value, "");
    }

    void test_lib_bind_back()
    {
        TESTING("lib_bind_back");
        struct el0;

        using add = eval<lib::bind_back, el0>;
        using s0 = eval<set::init>;
        using r0 = eval<add, set::add, s0>;
        using r1 = eval<set::add, s0, el0>;

        static_assert(eval<set::_default_cmp, r0, r1>::value, "");
    }

    void test_lib_compose()
    {
        TESTING("lib_compose");
        struct el0;

        // (...) => set(...)
        using step0 = set::init;
        // (...) => bind_back( el0 )( bind_front, ... )
        using step1 = eval<
            lib::closure,
            eval<lib::bind_back, el0>,
            lib::bind_front
        >;
        // (...) => step1( step0( ... ) )
        //      -> bind_back( el0 )( bind_front, step0(...) )
        //      -> bind_back( el0 )( bind_front, set(...) )
        //      -> bind_front( set(...), el0 )
        using comp = eval<
            lib::compose,
            step0,
            step1
        >;
        // (...) => step1( step0() )(...)
        //      -> bind_back( el0 )( bind_front, step0() )(...)
        //      -> bind_back( el0 )( bind_front, set() )(...)
        //      -> bind_front( set(), el0 )(...)
        // -> bind_front( set(), el )
        using bound = eval<comp>;

        using r0 = eval<bound, set::add>;
        using r1 = eval<
            set::add,
            eval<set::init>,
            el0
        >;
        static_assert(eval<set::_default_cmp, r0, r1>::value, "");
    }

    void test_lib()
    {
        TESTING("lib");
        test_lib_closure();
        test_lib_bind_front();
        test_lib_bind_back();
        test_lib_compose();
    }
}

void test_tpf_lib()
{
    TESTING("tpf_lib");
    test_tpf_set();
    test_lib();
}
