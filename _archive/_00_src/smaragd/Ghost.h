#pragma once
#include <tuple>
namespace smaragd
{
    template <
        typename T
    >
    struct Ghost
    {
    };

    namespace ghost
    {
        template <
            typename
        >
        struct make__tc;
        template <
            typename... Rest
        >
        struct make__tc<std::tuple<Rest...>>
        {
            template <typename... Args>
            static auto call(Args&&... args) -> std::tuple<Rest...>
            {
                return { std::forward<Args>(args)... };
            }
        };
        template <
            typename T,
            typename... Rest
        >
        struct make__tc<std::tuple<Ghost<T>, Rest...>>
        {
            template <typename... Args>
            static auto call(Args&&... args) -> std::tuple<Ghost<T>, Rest...>
            {
                auto mine = std::tuple<Ghost<T>> {};
                auto rest = make__tc<std::tuple<Rest...>>::call(std::forward<Args>(args)...);
                return std::tuple_cat(std::move(mine), std::move(rest));
            }
        };
    }


    template <
        typename Tag,
        typename Val
    >
    using Type = std::tuple<Ghost<Tag>, Val>;



    template <
        typename
    >
    struct type__tc;

    template <
        typename Tag,
        typename Val
    >
    struct type__tc<Type<Tag, Val>>
    {
        using tag_type = Tag;
        using val_type = Val;
    };

    template <
        typename T
    >
    using type_tag_t = typename type__tc<T>::tag_type;

    template <
        typename T
    >
    using type_val_t = typename type__tc<T>::val_type;



    template <
        typename T
    >
    struct maker
    {
        template <
            typename... Args
        >
        T operator () (Args&&... args) const&
        {
            return ghost::make__tc<T>::call(std::forward<Args>(args)...);
        }
    };



    template <
        typename T,
        typename... Args
    >
    T make(Args&&... args)
    {
        return ghost::make__tc<T>::call(std::forward<Args>(args)...);
    }



    template <
        typename Val
    >
    struct TypeOf
    {
        struct Tag;
        using type = Type<Tag, Val>;
        static constexpr auto make = maker<type>{};
    };
}
