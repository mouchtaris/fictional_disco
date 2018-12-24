#pragma once
#include "Ghost.h"
#include <tuple>
#include <type_traits>
namespace typelite::tag
{

    /**
     * A tagged value is a plain value associated with a unique Tag Type.
     *
     * Constructing such a value involves perfect forwarding, because it uses
     * tuples from the stdlib.
     *
     * The Tag Type is treated as a Ghost type, and its runtime instantiation
     * is not significant.
     */
    template <
        typename Tag,
        typename Value
    >
    using Tagged = std::tuple<
        Ghost<Tag>,
        Value
    >;

    /**
     * Traits for inspecting a Tagged type.
     */
    template <
        typename
    >
    struct TaggedTraits;

    // Specialization for Tagged types
    template <
        typename _Tag,
        typename _Value
    >
    struct TaggedTraits<Tagged<_Tag, _Value>>
    {
        using Tag = _Tag;
        using Value = _Value;
    };
    // Quick-access aliases
    template <
        typename Tagged
    >
    using TaggedTraits_Tag = typename TaggedTraits<Tagged>::Tag;
    //
    template <
        typename Tagged
    >
    using TaggedTraits_Value = typename TaggedTraits<Tagged>::Value;

    /**
     * Construct a tagged type by forwarding the given arguments to
     * the Value constructor.
     */
    template <
        typename Tagged,
        typename... Args
    >
    Tagged make(Args&&... args)
    {
        return {
            Ghost<TaggedTraits_Tag<Tagged>> { },
            std::forward<Args>(args)...,
        };
    }

    /**
     * Helper for declaring tagged types.
     *
     * This saves the trouble of declaring stand-alone *Tag types
     * around Tagged<> Values.
     *
     * The downside is that one needs use TaggedType::Type instead
     * of a type name itself, but this can circumvented with
     * template "using" aliases.
     */
    template <
        typename Value
    >
    struct TaggedType
    {
        struct Tag;
        using Type = Tagged<Tag, Value>;
    };

    /**
     * Get the plain value of a tagged type.
     *
     * After here no sweet typechecking.
     */
    template <
        typename Tagged
    >
    auto value(Tagged&& tagged)
        -> TaggedTraits_Value<std::decay_t<Tagged>>
    {
        return std::get<1>(std::forward<Tagged>(tagged));
    }

    template <
        typename Tagged
    >
    using value_t = decltype(
        value(std::declval<Tagged>())
    );

    /**
     * Get tuple item I from a tagged type value.
     *
     * Usually TaggedType values are tuples, even if empty
     * or of size 1.
     *
     * This helper comes in handy right then, accessing the
     * tagged type's value as a tuple.
     */
    template <
        size_t I,
        typename Tagged
    >
    auto value_get(Tagged&& tagged)
        -> std::tuple_element_t<I, value_t<Tagged>>
    {
        return std::get<I>(value(std::forward<Tagged>(tagged)));
    }
    /** And the accompanying result_t */
    template <
        size_t I,
        typename Tagged
    >
    using value_get_result_t = decltype(
        value_get<I>(std::declval<Tagged>())
    );
}
