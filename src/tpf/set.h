#pragma once
#include "tpf.h"
#include <type_traits>
namespace tpf::set
{
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
    struct _contains;
    struct _push;
    struct _pop;

    /** def init cmp = set(cmp) */
    struct init;

    /** def add set cmp el */
    struct add;

    /** def find set cmp el */
    struct find;
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
 * _contains
 */
template <
    typename Cmp,
    typename El,
    typename... Els,
    typename V
>
struct tpf::def<
    tpf::set::_contains,
    tpf::set::Set<Cmp, El, Els...>,
    V
>
{
    using _set = tpf::set::Set<Cmp, El, Els...>;

    using result =
        std::disjunction<
            std::conjunction<
                tpf::is_defined<tpf::def<Cmp, El, V>>,
                tpf::eval<Cmp, El, V>
            >,
            std::conjunction<
                tpf::is_defined<tpf::def<tpf::set::_pop, _set>>,
                tpf::eval<
                    tpf::set::_contains,
                    tpf::eval<tpf::set::_pop, _set>,
                    V
                >
            >
        >
    ;
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

template <
    typename Self,
    typename El
>
struct tpf::def<tpf::set::add, Self, El>
{
    
};
