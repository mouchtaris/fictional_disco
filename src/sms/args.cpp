#include "args.h"
#include <algorithm>
#include <iterator>
#include <cstring>
namespace
{
    using namespace sms::args;

    namespace handler
    {
        constexpr auto configuration_root = std::make_tuple(
            "configuration_root",
            [](Params, std::string arg)
            {
                return typelite::make<Params>(
                    typelite::make<ConfigurationRoot>(
                        std::move(arg)
                    )
                );
            }
        );
    }
    constexpr auto handlers = std::initializer_list<decltype(handler::configuration_root)> {
        handler::configuration_root
    };
}

namespace sms::args
{
    void sms__args__compiled();


    Params parse(std::deque<std::string> args)
    {
        Params params;
        for (auto&& arg: args)
            for (auto&& handler: handlers)
                if (arg.substr(2, std::strlen(std::get<0>(handler))) == std::get<0>(handler))
                    params = std::get<1>(handler)(
                        std::move(params),
                        arg.substr(std::strlen(std::get<0>(handler)) + 3)
                    );
        return params;
    }

    Params parse(int argc, char* argv[])
    {
        auto result = std::deque<std::string> { };
        auto inserter = std::back_inserter(result);

        std::copy(argv, argv + argc, inserter);
        return parse(std::move(result));
    }

}
