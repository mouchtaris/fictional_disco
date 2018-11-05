#include "apply.h"

namespace tpf {
    void bind_compiled();

    template <
        typename PF,
        typename... BoundArgs
    >
    struct bind;
    template <
        typename PF,
        typename... BoundArgs,
        typename... Args
    >
    struct apply<bind<PF, BoundArgs...>, Args...> {
        using result = f<PF, BoundArgs..., Args...>;
    };

}
