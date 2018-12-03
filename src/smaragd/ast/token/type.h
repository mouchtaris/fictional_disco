#pragma once
#include <cstdint>

namespace smaragd::ast::token
{
    enum class type: uint16_t
    {
        COLON,
        COMMA,
        CONSTANT,
        DOT,
        EQ,
        ID,
        INSTANCE_ID,
        INT,
        KW_CLASS,
        KW_DEF,
        KW_END,
        KW_OF,
        LBRACK,
        LPAR,
        NL,
        RBRACK,
        RPAR,
        SEMICOLON,
        STR,
    };
}
