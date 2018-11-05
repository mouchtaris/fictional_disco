#include "pig.h"
#include "tpf/find.h"
#include "tpf/bind.h"
#include "tpf/templ.h"
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


template <typename... Ts> auto value(tuple<Ts...> t) { return get<1>(t); }
template <typename MDT> struct is_valtype;
template <typename MDT, typename... Args> struct tpf::apply<is_valtype<MDT>, Args...> { using result = false_type; };
template <typename MDT, typename Val> struct tpf::apply<is_valtype<MDT>, tuple<MDT, Val>> { using result = true_type; };

struct Email: public Value<Email, string> {};
struct Password: public Value<Password, string> {};

int main(int, char**)
{
    tpf::select_compiled();
    tpf::find_compiled();
    tpf::bind_compiled();
    tpf::templ_compiled();
    tpf::cons_compiled();

    auto email = Email::make("hello@bob.com");
    auto pass = Password::make("12121212");
    auto user = tuple { move(email), move(pass) };

    using get_email = tpf::find<is_valtype<Email>>;
    using found = tpf::tf<get_email, decltype(user)>;
    cout << pig<decltype(user)>::val << endl
        << pig<found>::val << endl
        << tpf::rttf<get_email>(user) << endl;

    return 0;
}
