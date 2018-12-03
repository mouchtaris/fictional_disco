#include "scafold_tokens.h"
#include <iostream>

int main(int, char**)
{
    for (auto&& token: scafold::make_token_stream())
        std::cout
            << "Token[" << (uint16_t) type(token) << ": " << value(token) << "]\n";
    return 0;
}
