#pragma once
namespace smaragd
{
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

    enum class TokenType { digit, sum, sub, mul, div, semi };

    //
    // LE GRAMMAR
    //
    struct NumberId;
    using Number = Rule<NumberId, rhs<Token<TokenType::digit>>>;

    struct LiteralId;
    using Literal = Rule<LiteralId, rhs<NumberId>>;

    struct OpId;
    using Op = Rule<OpId,
        Or< rhs<    Token<  TokenType::sum  >   >,
        Or< rhs<    Token<  TokenType::sub  >   >,
        Or< rhs<    Token<  TokenType::mul  >   >,
            rhs<    Token<  TokenType::div  >   >
        >>>
    >;

    struct ExprId;
    using Expr = Rule<ExprId,
        Or< rhs<    ExprId, OpId, ExprId    >,
            rhs<    NumberId                >
        >
    >;
}
