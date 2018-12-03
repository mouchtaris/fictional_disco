#include "smaragd/ast/token/Token.h"
#include <deque>

namespace scafold {
    using namespace smaragd::ast::token;

    static const std::string empty{};

    auto make_token_stream()
    {
        return std::deque<Token> {
            { type::KW_CLASS, empty },
            { type::CONSTANT, "Account" },
            { type::NL, empty },

            { type::KW_DEF, empty },
            { type::ID, "initialize" },
            { type::LPAR, empty },
            { type::NL, empty },

            { type::ID, "email" },
            { type::COLON, empty },
            { type::CONSTANT, "String" },
            { type::COMMA, empty },
            { type::NL, empty },

            { type::ID, "password" },
            { type::COLON, empty },
            { type::CONSTANT, "List" },
            { type::KW_OF, empty },
            { type::CONSTANT, "Byte" },
            { type::NL, empty },

            { type::RPAR, empty },
            { type::NL, empty },

            { type::INSTANCE_ID, "@email" },
            { type::EQ, empty },
            { type::NL, empty },

            { type::INSTANCE_ID, "@password" },
            { type::EQ, empty },
            { type::NL, empty },

            { type::KW_END, empty },
            { type::NL, empty },

            { type::KW_END, empty },
            { type::NL, empty },


            { type::NL, empty },

            { type::ID, "acc" },
            { type::EQ, empty },
            { type::CONSTANT, "Account" },
            { type::DOT, empty },
            { type::LPAR, empty },
            { type::ID, "email" },
            { type::COLON, empty },
            { type::STR, "Hi" },
            { type::COMMA, empty },
            { type::ID, "password" },
            { type::COLON, empty },
            { type::LBRACK, empty },
            { type::INT, "1" },
            { type::COMMA, empty },
            { type::INT, "2" },
            { type::COMMA, empty },
            { type::RBRACK, empty },
            { type::RPAR, empty },
            { type::NL, empty },

            { type::ID, "print" },
            { type::STR, "Hello, " },
            { type::NL, empty },

            { type::ID, "puts" },
            { type::ID, "acc" },
            { type::DOT, empty },
            { type::ID, "email" }
        };
    }
}
