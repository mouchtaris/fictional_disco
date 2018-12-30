#pragma once
#include "tpf.h"
namespace tpf::lib
{
    struct sacl_mod;

    /**
     * def closure f args...
     */
    struct closure;
    template <
        typename... Seq
    >
    struct Closure;



    /**
     * def compose f g
     */
    struct compose;
    template <
        typename F,
        typename G
    >
    struct Composition;



    /**
     * def bind_front args...
     */
    struct bind_front;
    template <
        typename...
    >
    struct BoundFront;



    /**
     * def bind_back args...
     */
    struct bind_back;
    template <
        typename...
    >
    struct BoundBack;
}



/**
 * closure
 */
template <
    typename... Seq
>
struct tpf::def<
    tpf::lib::closure,
    Seq...
>
{
    using result = tpf::lib::Closure<Seq...>;
};
//
template <
    typename... Clos,
    typename... Args
>
struct tpf::def<
    tpf::lib::Closure<Clos...>,
    Args...
>
{
    using result = tpf::eval<Clos..., Args...>;
};



/**
 * bind_front
 */
template <
    typename... Bound
>
struct tpf::def<
    tpf::lib::bind_front,
    Bound...
>
{
    using result = tpf::lib::BoundFront<Bound...>;
};
//
template <
    typename... Bound,
    typename F,
    typename... Args
>
struct tpf::def<
    tpf::lib::BoundFront<Bound...>,
    F,
    Args...
>
{
    using result = tpf::eval<F, Bound..., Args...>;
};



/**
 * bind_back
 */
template <
    typename... Bound
>
struct tpf::def<
    tpf::lib::bind_back,
    Bound...
>
{
    using result = tpf::lib::BoundBack<Bound...>;
};
//
template <
    typename... Bound,
    typename F,
    typename... Args
>
struct tpf::def<
    tpf::lib::BoundBack<Bound...>,
    F,
    Args...
>
{
    using result = tpf::eval<F, Args..., Bound...>;
};




/**
 * compose
 */
template <
    typename F,
    typename G
>
struct tpf::def<
    tpf::lib::compose,
    F,
    G
>
{
    using result = tpf::lib::Composition<F, G>;
};
//
template <
    typename F,
    typename G,
    typename... Args
>
struct tpf::def<
    tpf::lib::Composition<F, G>,
    Args...
>
{
    using result = tpf::eval<
        G,
        tpf::eval<
            F,
            Args...
        >
    >;
};
