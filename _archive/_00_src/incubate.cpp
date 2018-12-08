#include "incubate.h"
#include <string>
#include <array>
#include <type_traits>
#include "smaragd/Ghost.h"
#include "smaragd/ast/token/type.h"
#include "smaragd/tpf.h"
namespace smaragd::parse::incubate
{
    namespace bnf
    {
        namespace id
        {
            template <typename> struct name;
#           define ID(id) \
                struct id; \
                template <> struct name<id> { static constexpr auto value = #id; }

            ID(program);
            ID(exprlist);
            ID(expr);
            ID(comma);
            ID(classexpr);
            ID(eos);
#           undef ID
        }

        template <
            typename Id,
            typename... Expansion
        >
        struct rule;
        template <typename> struct rule_id__tc;
        //
        template <typename Id, typename... Exp> struct rule_id__tc<rule<Id, Exp...>>
        {
            using type = Id;
        };
        template <typename T> using rule_id = typename rule_id__tc<T>::type;
        //
        template <typename T> struct rule_expansion__tc;
        template <typename Id, typename... Exp> struct rule_expansion__tc<rule<Id, Exp...>>
        {
            using type = tpf::apply<Exp...>;
        };
        template <typename T> using rule_exp = typename rule_expansion__tc<T>::type;


        struct start;
        struct empty;
        struct eos;

        using rules = std::tuple<
            rule<start, id::program>,

            rule<id::program, id::exprlist>,

            rule<id::exprlist, empty>,
            rule<id::exprlist, id::expr>,
            rule<id::exprlist, id::expr, id::comma, id::exprlist>,

            rule<id::expr, id::classexpr>,

            rule<id::classexpr, ast::token::types::kw_class, ast::token::types::id, id::eos>,

            rule<id::eos, ast::token::types::nl>,
            rule<id::eos, ast::token::types::semicolon>
        >;

        constexpr auto lol = Ghost<rules>{};
    }

    namespace dfa
    {
        struct dot;

        template <
            typename... Expansion
        >
        struct ShiftReduceItem;

        template <typename id, typename rules> struct find_rule;
        template <
            typename id,
            typename... exp,
            typename... rest
        > struct find_rule<id, std::tuple<bnf::rule<id, exp...>, rest...>>
        {
            using type = bnf::rule<id, exp...>;
        };
        template <
            typename id,
            typename first,
            typename... rest
        > struct find_rule<id, std::tuple<first, rest...>>
        {
            using type = typename find_rule<id, rest...>::type;
        };

        template <typename rules> struct make_initial_item;
        template <
            typename... rules
        >
        struct make_initial_item<std::tuple<rules...>>
        {
            using _start = typename find_rule<bnf::start, bnf::rules>::type;
            using _rule_id = bnf::rule_id<_start>;

            using _bind_head =
                tpf::bind<ShiftReduceItem>::apply<_rule_id, dot>;
            using _wat =
                bnf::rule_exp<_start>::type<_bind_head::bound>;
        };
        //constexpr Ghost<make_initial_item<bnf::rules>::type> a{};
    }
}
