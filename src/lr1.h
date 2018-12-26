#pragma once
namespace lr1
{
    struct sacl_mod;

    /**
     * The Right-Hand-Side of a Rule expansion.
     *
     * Ex.
     *
     *      RuleId := RHS<Id0, Id1, Id2, ...>
     */
    template <
        typename...
    >
    struct Rhs;

    /**
     * A list of alternative RHS expansions.
     *
     * This is a RHS ID element.
     *
     * Ex.
     *
     *      RuleId := Or< RHS<...>, RHS<...> >
     */
    template <
        typename...
    >
    struct Or;

    /**
     * The basis of token type runtime enum vaklues.
     */
    using TokenTypeValue = unsigned long int;

    /**
     * A terminal token symbol.
     *
     * This is a RHS ID element.
     *
     * Ex.
     *
     *      RuleId := Token<DIGIT> ...
     */
    template <
        TokenTypeValue
    >
    struct Token;

    /**
     * An expansion rule.
     *
     * Ex.
     *
     *      RuleId := 
     *          <T0> R0
     *          | R1 <T1>
     *
     * Is written as:
     *
     *      Rule< RuleId,
     *          Or< Rhs< Token<T0>, R0_id >,
     *              Rhs< R1_id, Token<T1> >
     *          >
     *      >
     */
    template <
        typename Id,
        typename Rhs
    >
    struct Rule;
}
