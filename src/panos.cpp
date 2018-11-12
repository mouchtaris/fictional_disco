#include"ser.h"

#include <utility>
#include <cassert>
#include <iostream>
#include <array>
#include <tuple>
#include <cstdint>
#include <string>
#include <set>
#include <deque>
#include <functional>
#include <algorithm>
#include <regex>
#include <type_traits>


void test();

int main(int, char**)
{
    std::cout << "Hello, panos." << std::endl;
    test();
    return 0;
}

void test()
{
    extern void test_ser();
    test_ser();
}
