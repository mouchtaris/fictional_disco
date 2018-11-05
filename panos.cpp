#include "pig.h"
#include "tpf/find.h"
#include "tpf/bind.h"
#include "tpf/templ.h"
#include "tpf/tupletools.h"
#include "common.h"

namespace tpf {

}

template <
    typename MDT,
    typename Val
>
struct Value {
    template <
        typename... Args
    >
    static auto make(Args&&... args)
    {
        return tuple { MDT{}, Val { forward<Args>(args)... } };
    }
};
#define VALUE(NAME, TYPE) \
    struct NAME: public Value<NAME, TYPE> {}; \
    std::ostream& operator << (std::ostream& os, NAME) { return os << #NAME; }

template <typename... Ts> auto value(tuple<Ts...> t) { return get<1>(t); }
template <typename MDT> struct is_valtype;
template <typename MDT, typename... Args> struct tpf::apply<is_valtype<MDT>, Args...> { using result = false_type; };
template <typename MDT, typename Val> struct tpf::apply<is_valtype<MDT>, tuple<MDT, Val>> { using result = true_type; };

VALUE(Email, string)
VALUE(Password, string)

template <typename... Ts>
struct tuple_printer;
template <typename T, typename... Ts>
struct tuple_printer<T, Ts...> {
    static ostream& print(ostream& os, tuple<T, Ts...> t)
    {
        return tuple_printer<Ts...>::print(
            tuple_printer<T>::print(os, std::tuple { std::get<0>(t) }) << ", ",
            tpf::tupletools<T, Ts...>::template subtuple<1>(t, std::index_sequence_for<Ts...>{})
        );
    }
};
template <typename T>
struct tuple_printer<T> { static ostream& print(ostream& os, tuple<T> t) { return os << get<0>(t); } };
template <
    typename... Args
>
std::ostream& operator << (std::ostream& os, tuple<Args...> t)
{
    return tuple_printer<Args...>::print(os << '{', t) << '}';
}

int main(int, char**)
{
    tpf::select_compiled();
    tpf::find_compiled();
    tpf::bind_compiled();
    tpf::templ_compiled();
    tpf::cons_compiled();
    tpf::tupletools_compiled();

    auto email = Email::make("bob@sponge.com");
    auto pass = Password::make("12121212");
    auto user = tuple { move(email), move(pass) };
    using user_t = decltype(user);

    using get_email = tpf::find<is_valtype<Email>>;
    using select_email = tpf::select<is_valtype<Email>>;
    using found = tpf::tf<get_email, user_t>;
    using selected = tpf::tf<select_email, user_t>;
    using wat = tpf::apply_tuple<select_email, user_t>;
    cout << pig<decltype(user)>::val << endl
        << pig<found>::val << endl
        << pig<selected>::val << endl
        << pig<wat>::val << endl
        << wat::application::rt(user) << endl
        //<< tpf::rttf<tpf::select<is_valtype<Email>>>(user) << endl;
        ;

    return 0;
}
