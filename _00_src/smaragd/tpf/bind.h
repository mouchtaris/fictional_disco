#pragma once
namespace smaragd::tpf
{
    template <
        template <typename...> typename K
    >
    struct bind
    {
        template <
            typename... Bound
        >
        struct apply
        {
            template <
                typename... Args
            >
            using bound = K<Bound..., Args...>;

            template <
                typename... Args
            >
            using type = bound<Args...>;
        };
    };

    void _u__bind__compiled();
}
