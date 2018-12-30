#pragma once
#include <type_traits>
/**
 * Welcome to TPF.
 *
 * Type Partial Functions are defined by using
 * `def`.
 *
 *      struct int2str;
 *      struct def<int2str, int>
 *      {
 *          using result = std::string;
 *      }
 *
 * Using TPFs is done through the `eval` mechanism:
 *
 *      using result = eval<int2str, int>'
 *      static_assert(std::is_same_v<result, std::string>, "");
 *
 * There is also a mechanism to check if a TPF is defined at a
 * given input:
 *
 *      static_assert(is_defined_v<int2str, int>, "");
 *      static_assert(!is_defined_v<int2str, float>, "");
 *
 * Using `eval1 for TPFs that are not defind will result in a
 * compilation error, because `eval` is defined only if the TPF
 * is defined.
 */
namespace tpf
{
    struct sacl_mod;



    /**
     * Defined a TPF.
     *
     *      def<F, in0, in1>
     */
    template <
        typename...
    >
    struct def;



    /**
     * Check if a TPF is defined at the given input.
     */
    template <
        typename,
        typename = std::void_t<>
    >
    struct is_defined__tc: public std::false_type{};
    //
    template <
        typename Tpf
    >
    struct is_defined__tc<
        Tpf,
        std::void_t<typename Tpf::result>
    >
    : public std::true_type{};
    //
    template <
        typename Tpf
    >
    using is_defined = is_defined__tc<Tpf>;



    /**
     * Evaluate a TPF sequence.
     *
     *      static_assert(is_defined_v<F, in0, in1, ...>, "");
     *      eval<F, in0, in1, ...>
     */
    template <
        typename... Seq
    >
    struct eval__tc
    {
        using result = std::enable_if_t<
            std::conjunction_v<
                is_defined<def<Seq...>>
            >,
            typename def<Seq...>::result
        >;
    };
    //
    template <
        typename... Seq
    >
    struct eval__tc<def<Seq...>>
    {
        using result = typename eval__tc<Seq...>::result;
    };
    //
    template <
        typename... Seq
    >
    using eval = typename eval__tc<Seq...>::result;
}
