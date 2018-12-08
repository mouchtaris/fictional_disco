#pragma once
#include <cstdint>

namespace smaragd::ast::token
{
    namespace types
    {
        template <typename> struct numvalue;
#       define ID(id)   \
            struct id;  \
            template <> struct numvalue<id> { static constexpr auto value = #id; }

        ID(colon);
        ID(comma);
        ID(constant);
        ID(dot);
        ID(eq);
        ID(id);
        ID(instance_id);
        ID(kw_class);
        ID(kw_def);
        ID(kw_end);
        ID(kw_of);
        ID(lbrack);
        ID(lit_int);
        ID(lit_str);
        ID(lpar);
        ID(nl);
        ID(rbrack);
        ID(rpar);
        ID(semicolon);
#       undef ID
    }
}
