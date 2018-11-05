#include "apply.h"

namespace tpf {
    void templ_compiled();

    template <
        template <typename...> typename T
    >
    struct templ;
    template <
        template <typename...> typename T,
        typename... Args
    >
    struct apply<templ<T>, Args...> {
        using result = T<Args...>;
    };


}
