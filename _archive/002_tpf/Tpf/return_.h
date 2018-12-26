#include "./Id.h"
namespace Tpf
{
    namespace sacl { struct return_; }

    template <
        typename... Def
    >
    using return_ = apply<apply<Def...>, Id>;

}
