#pragma once
#include "typelite/Tagged.h"
#include <string>
#include <functional>
#include <type_traits>
#include <tuple>
#include <deque>
#include <string>
namespace sms::args
{

    /**
     * Configuration root path
     */
    struct ConfigurationRootTag;
    using ConfigurationRoot = typelite::Tagged<ConfigurationRootTag, std::string>;

    /**
     * Parsed params
     */
    struct ParamsTag;
    using Params = typelite::Tagged<ParamsTag, std::tuple<
        ConfigurationRoot
    >>;
    namespace Params_
    {
        using Value = typelite::TaggedTraits_Value<Params>;
    }

    //
    // Accessor alias helper
    //
    template <
        size_t I
    >
    constexpr auto _Accessor = [](Params params)
    -> typelite::TaggedTraits_Value<
        std::tuple_element_t<I, Params_::Value>
    >
    {
        return value(
            std::get<I>(
                value(
                    std::move(params)
                )
            )
        );
    };

    /**
     * Access configuration root from Params
     */
    constexpr auto configuration_root = _Accessor<0>;

    /**
     * Parse an iterable of string into Params
     */
    Params parse(std::deque<std::string> args);
    Params parse(int argc, char* argv[]);

}
