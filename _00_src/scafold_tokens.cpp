#include "incubate.h"
#include "scafold_tokens.h"

namespace scafold {
    using namespace smaragd::ast::token;
    using namespace smaragd::parse::incubate;

    static const std::string empty{};

    void make_grammar()
    {
    }

    std::deque<Token> make_token_stream()
    {
        using namespace types;
        return {
            { numvalue<kw_class>::value, empty },
            { numvalue<constant>::value, "Account" },
            { numvalue<nl>::value, empty },

            { numvalue<kw_def>::value, empty },
            { numvalue<id>::value, "initialize" },
            { numvalue<lpar>::value, empty },
            { numvalue<nl>::value, empty },

            { numvalue<id>::value, "email" },
            { numvalue<colon>::value, empty },
            { numvalue<constant>::value, "String" },
            { numvalue<comma>::value, empty },
            { numvalue<nl>::value, empty },

            { numvalue<id>::value, "password" },
            { numvalue<colon>::value, empty },
            { numvalue<constant>::value, "List" },
            { numvalue<kw_of>::value, empty },
            { numvalue<constant>::value, "Byte" },
            { numvalue<nl>::value, empty },

            { numvalue<rpar>::value, empty },
            { numvalue<nl>::value, empty },

            { numvalue<instance_id>::value, "@email" },
            { numvalue<eq>::value, empty },
            { numvalue<id>::value, "email" },
            { numvalue<nl>::value, empty },

            { numvalue<instance_id>::value, "@password" },
            { numvalue<eq>::value, empty },
            { numvalue<id>::value, "password" },
            { numvalue<nl>::value, empty },

            { numvalue<kw_end>::value, empty },
            { numvalue<nl>::value, empty },

            { numvalue<kw_end>::value, empty },
            { numvalue<nl>::value, empty },

            { numvalue<nl>::value, empty },

            { numvalue<id>::value, "acc" },
            { numvalue<eq>::value, empty },
            { numvalue<constant>::value, "Account" },
            { numvalue<dot>::value, empty },
            { numvalue<lpar>::value, empty },
            { numvalue<id>::value, "email" },
            { numvalue<colon>::value, empty },
            { numvalue<lit_str>::value, "Hi" },
            { numvalue<comma>::value, empty },
            { numvalue<id>::value, "password" },
            { numvalue<colon>::value, empty },
            { numvalue<lbrack>::value, empty },
            { numvalue<lit_int>::value, "1" },
            { numvalue<comma>::value, empty },
            { numvalue<lit_int>::value, "2" },
            { numvalue<comma>::value, empty },
            { numvalue<rbrack>::value, empty },
            { numvalue<rpar>::value, empty },
            { numvalue<nl>::value, empty },

            { numvalue<id>::value, "print" },
            { numvalue<lit_str>::value, "Hello, " },
            { numvalue<nl>::value, empty },

            { numvalue<id>::value, "puts" },
            { numvalue<id>::value, "acc" },
            { numvalue<dot>::value, empty },
            { numvalue<id>::value, "email" }
        };
    }
}
