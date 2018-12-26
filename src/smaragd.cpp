#include "smaragd.h"
#include "sacl.h"
#include <iostream>
#include <string>

namespace smaragd
{

    //
    // tt_to_s
    //
    // TokenType runtime to_s()
    //
    char const* tt_to_s(TokenType tt)
    {
        switch (tt)
        {
            case TokenType::digit: return "DIGIT";
            case TokenType::div: return "DIV";
            case TokenType::sum: return "SUM";
            case TokenType::sub: return "SUB";
            case TokenType::mul: return "MUL";
            case TokenType::semi: return "SEMI";
            default: return "<INVALID>";
        }
    }



    //
    // tto_s<> {
    //  value       : char const*
    //  call(&os)   : void
    // }
    //
    template <typename> struct tto_s;
    template <> struct tto_s<NumberId> { static constexpr auto value = "Number"; };
    template <> struct tto_s<LiteralId> { static constexpr auto value = "Literal"; };
    template <> struct tto_s<OpId> { static constexpr auto value = "Op"; };
    template <> struct tto_s<ExprId> { static constexpr auto value = "Expr"; };

    template <TokenType tt> struct tto_s<Token<tt>>
    {
        static void call(std::ostream& os) { os << '<' << tt_to_s(tt) << '>'; }
    };

    //
    template <typename T> std::ostream& tos(std::ostream&);
    //
    template <typename Id, typename rhs> struct tto_s<Rule<Id, rhs>>
    {
        static void call(std::ostream& os)
        {
            tos<Id>(os) << " := \n    ";
            tos<rhs>(os);
        }
    };
    //
    template <> struct tto_s<rhs<>> { static constexpr auto value = ""; };
    template <typename Id, typename...Ids> struct tto_s<rhs<Id, Ids...>>
    {
        static void call(std::ostream& os)
        {
            tos<Id>(os) << ' ';
            tos<rhs<Ids...>>(os);
        }
    };
    //
    template <typename R1, typename R2> struct tto_s<Or<R1, R2>>
    {
        static void call(std::ostream& os)
        {
            tos<R1>(os);
            os << "\n  | ";
            tos<R2>(os);
        }
    };



    //
    // tto_s_with_value<T>:
    //  true_type |
    //  false_type
    //
    template <typename T, typename = std::void_t<>> struct tto_s_with_value: public std::false_type{};
    template <typename T> struct tto_s_with_value<
        T,
        std::void_t<decltype(tto_s<T>::value)>
    >: public std::is_same<std::remove_const_t<decltype(tto_s<T>::value)>, char const*> {};



    //
    // tto_s_with_call<T>:
    //  true_type |
    //  false_type
    //
    template <typename T, typename = std::void_t<>> struct tto_s_with_call: public std::false_type{};
    template <typename T> struct tto_s_with_call<
        T,
        std::void_t<decltype(tto_s<T>::call(std::declval<std::ostream&>()))>
    >: public std::is_same<decltype(tto_s<T>::call(std::declval<std::ostream&>())), void>{};



    //
    // to_s<T> {
    //  call(&os)   : void
    // }
    //
    template <typename, typename = std::void_t<>> struct to_s;
    template <typename T> struct to_s<T,
        std::enable_if_t<
            std::conjunction_v<tto_s_with_value<T>>,
            void
        >
    >
    {
        static void call(std::ostream& os) { os << tto_s<T>::value; }
    };
    template <typename T> struct to_s<T,
        std::enable_if_t<
            std::conjunction_v<tto_s_with_call<T>>,
            void
        >
    >
    {
        static void call(std::ostream& os) { tto_s<T>::call(os); }
    };


    //
    // tos
    //
    template <typename T> std::ostream& tos(std::ostream& os) { to_s<T>::call(os); return os; }
}

template <typename> struct pig {
    static constexpr char const* _value() { return __PRETTY_FUNCTION__; }
    static constexpr auto value = _value();
};

template <> void sacl<smaragd::sacl_mod>()
{
    using namespace smaragd;
    auto& os = std::cout;
    os << pig<decltype(tto_s<NumberId>::value)>::value << '\n';
    static_assert(tto_s_with_value<NumberId>::value, "");
    static_assert(!tto_s_with_call<NumberId>::value, "");
    tos<NumberId>(os);
    using tt = Token<TokenType::digit>;
    to_s<tt> t;
    (void)t;
    static_assert(tto_s_with_call<tt>::value, "");
    static_assert(!tto_s_with_value<tt>::value, "");
    tos<tt>(os);

    os << "\n\n\n";
    static constexpr auto nl = '\n';
    tos<NumberId>(os) << nl;
    tos<LiteralId>(os) << nl;
    tos<OpId>(os) << nl;
    tos<ExprId>(os) << nl;

    os << nl << nl << nl;
    tos<Expr>(os) << nl;
    tos<Op>(os) << nl;
    tos<Literal>(os) << nl;
    tos<Number>(os) << nl;
}
