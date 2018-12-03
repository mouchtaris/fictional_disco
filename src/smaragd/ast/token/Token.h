#pragma once

#include "type.h"
#include <string>

namespace smaragd::ast::token
{
    struct Token {
        token::type type;
        std::string value;
    };


    inline auto value(Token const& token) -> std::string const& 
    {
        return token.value;
    }

    inline auto type(Token const& token) -> type
    {
        return token.type;
    }
}
