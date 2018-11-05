#include "tpf/apply.h"
#include <type_traits>

namespace tpf {

    struct to_bool;
    template <
        typename... Args
    >
    struct apply<to_bool, Args...> {
        using result = std::conjunction<Args...>;
    };

}
