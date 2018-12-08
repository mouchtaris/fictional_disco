#include "scafold_tokens.h"
#include <iostream>
#include "smaragd/ast/token/Token.h"

int main(int, char**)
{
    using namespace scafold;

    make_grammar();

    for (auto&& token: make_token_stream())
        std::cout
            << "Token[" << type(token) << ": " << value(token) << "]\n";
    return 0;
}
