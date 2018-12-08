#include <deque>
#include <string>
#include "smaragd/ast/token/Token.h"
namespace scafold
{
    using smaragd::ast::token::Token;

    auto make_grammar()         -> void                 ;
    auto make_token_stream()    -> std::deque<Token>    ;
}
