#pragma once
#include <type_traits>
namespace Tpf
{
    extern void _u__mod__tpf();


    template <
        typename...
    >
    struct tpf;



    template <
        typename,
        typename = std::void_t<>
    >
    struct is_defined__tc: public std::false_type
    {
    };

    template <
        typename F
    >
    struct is_defined__tc<F, std::void_t<typename F::type>>: public std::true_type
    {
    };

    template <
        typename... Args
    >
    using is_defined_t = typename is_defined__tc<tpf<Args...>>::type;

    template <
        typename... Args
    >
    constexpr auto is_defined = is_defined_t<Args...>::value;



    template <
        typename... Args
    >
    using apply = std::enable_if_t<
        is_defined<Args...>,
        typename tpf<Args...>::type
        >;
}