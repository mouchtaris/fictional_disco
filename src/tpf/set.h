#pragma once
#include "tpf.h"
#include <type_traits>
namespace tpf::set
{
    struct sacl_mod;

    /**
     * Set ADT
     *
     * Cmp: compartator
     * Els: elements
     */
    template <
        typename Cmp,
        typename... Els
    >
    struct Set;
    struct _default_cmp;
    struct _push;
    struct _pop;

    /** def init cmp = set(cmp) */
    struct init;

    /** def add set cmp el */
    struct add;

    /** def contains set cmp el */
    struct contains;
}

/**
 * _push
 */
template <
    typename Cmp,
    typename El,
    typename... Els
>
struct tpf::def<
    tpf::set::_push,
    tpf::set::Set<Cmp, Els...>,
    El
>
{
    using result = tpf::set::Set<Cmp, El, Els...>;
};

/**
 * _pop
 */
template <
    typename Cmp,
    typename El,
    typename... Els
>
struct tpf::def<
    tpf::set::_pop,
    tpf::set::Set<Cmp, El, Els...>
>
{
    using result = tpf::set::Set<Cmp, Els...>;
};

/**
 * contains
 */
template <
    typename Cmp,
    typename El,
    typename... Els,
    typename V
>
struct tpf::def<
    tpf::set::contains,
    tpf::set::Set<Cmp, El, Els...>,
    V
>
{
    using _set = tpf::set::Set<Cmp, El, Els...>;

    using result =
        std::disjunction<
            std::conjunction<
                tpf::is_defined<tpf::def<Cmp, El, V>>,
                std::conjunction<tpf::eval<Cmp, El, V>>
            >,
            std::conjunction<
                tpf::is_defined<tpf::def<tpf::set::_pop, _set>>,
                tpf::eval<
                    tpf::set::contains,
                    tpf::eval<tpf::set::_pop, _set>,
                    V
                >
            >
        >
    ;
};
//
template <
    typename Cmp,
    typename V
>
struct tpf::def<
    tpf::set::contains,
    tpf::set::Set<Cmp>,
    V
>
{
    using result = std::false_type;
};


/**
 * _default_cmp
 */
template <
    typename A,
    typename B
>
struct tpf::def<tpf::set::_default_cmp, A, B>
{
    using result = std::is_same<A, B>;
};

/**
 * init
 */
template <
    typename Cmp
>
struct tpf::def<tpf::set::init, Cmp>
{
    using result = tpf::set::Set<Cmp>;
};
//
template <
>
struct tpf::def<tpf::set::init>
{
    using result = tpf::eval<tpf::set::init, tpf::set::_default_cmp>;
};

/**
 * add
 */
template <
    typename Self,
    typename El
>
struct tpf::def<tpf::set::add, Self, El>
{
    using result = std::conditional_t<
        std::conjunction_v<
            tpf::eval<tpf::set::contains, Self, El>
        >,
        Self,
        tpf::eval<tpf::set::_push, Self, El>
    >;
};
