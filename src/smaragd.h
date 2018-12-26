#pragma once
#include "lr1.h"
namespace smaragd
{
    using namespace lr1;
    struct sacl_mod;

    //
    // program :=
    //  expr <semi>
    //
    // expr :=
    //  expr op expr
    //  | literal
    //
    // op := + | - | * | /
    //
    // literal :=
    //  number
    //
    // number :=
    //  <\d+>
    //

    enum class TokenType: unsigned long int { digit, sum, sub, mul, div, semi };

    //
    // LE GRAMMAR
    //
    struct NumberId;
    using Number = Rule<NumberId, Rhs<Token<(unsigned long)TokenType::digit>>>;

    struct LiteralId;
    using Literal = Rule<LiteralId, Rhs<NumberId>>;

    struct OpId;
    using Op = Rule<OpId,
        Or< Rhs<    Token<  (unsigned long)TokenType::sum  >   >,
        Or< Rhs<    Token<  (unsigned long)TokenType::sub  >   >,
        Or< Rhs<    Token<  (unsigned long)TokenType::mul  >   >,
            Rhs<    Token<  (unsigned long)TokenType::div  >   >
        >>>
    >;

    struct ExprId;
    using Expr = Rule<ExprId,
        Or< Rhs<    ExprId, OpId, ExprId    >,
            Rhs<    NumberId                >
        >
    >;
}
