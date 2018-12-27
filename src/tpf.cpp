#include "tpf.h"
#include "tpf/example.h"
#include "sacl.h"
template <> void sacl<tpf::sacl_mod>()
{
    using namespace tpf;
    sacls<
        example::sacl
    >();
}
