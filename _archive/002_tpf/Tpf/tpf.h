#pragma once
#include <type_traits>
namespace Tpf
{
    namespace _tpf { struct sacl; }

    /**
     * A Type(-level) Partial Function.
     *
     * TPFs operate on types in a functional programming approach.
     *
     * Tpf definitions include 2 things:
     *
     *  * A Symbol (equivalent to function name)
     *  * An argument
     *
     * Essentially TPF<F, A>::type is type-level syntax for
     *
     *   let F A = type
     *
     */
    template <
        typename...
    >
    struct tpf;


    /**
     * Partial functions can be defined or not at specific inputs.
     *
     * It's the same for TPFs, which are generally undefined
     * (just like PFs) unless explicitly defined.
     */
    template <
        typename,
        typename = std::void_t<>
    >
    struct is_defined__tc: public std::false_type
    {
    };

    /**
     * A TPF is defined if TPF<...>::type is a well-defined
     * expression.
     */
    template <
        typename F
    >
    struct is_defined__tc<F, std::void_t<typename F::type>>: public std::true_type
    {
    };

    /** Alias for is_defined__tc */
    template <
        typename... Args
    >
    using is_defined_t = typename is_defined__tc<tpf<Args...>>::type;

    /** Alias for is_defined__tc's value */
    template <
        typename... Args
    >
    constexpr auto is_defined = is_defined_t<Args...>::value;


    /**
     * Apply is the quick-way of applying a TPF to arguments.
     */
    template <
        typename... Args
    >
    using apply = std::enable_if_t<
        is_defined<Args...>,
        typename tpf<Args...>::type
    >;

}
