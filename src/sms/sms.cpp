#include "args.h"
#include <iostream>
#include <algorithm>

namespace sms
{
    int sms(int argc, char* argv[])
    {
        args::Params params = args::parse(argc, argv);
        auto croot = args::configuration_root(params);
        std::cout << "configuration root: [" << croot << "]\n";
        return 0;
    }
}

int main(int argc, char** argv) { return sms::sms(argc, argv); }
