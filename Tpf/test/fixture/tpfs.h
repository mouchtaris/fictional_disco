#include "Tpf/def.h"
namespace test::Tpf::fixture
{
    struct tuplize;
}
namespace Tpf
{
    using namespace test::Tpf;

    template <
        typename... Ts
    >
    struct tpf<fixture::tuplize, Ts...>
    {
        using type = std::tuple<Ts...>;
    };
}
