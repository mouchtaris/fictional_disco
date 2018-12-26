#pragma once
namespace tpf
{
    struct sacl_mod;

    struct Zero;
    template <typename N> struct SuccOf;

    struct Succ;
    struct Sum;
    struct Sub;
    struct Mul;
    struct Div;

    template <
        typename...
    >
    struct def;

    template <
        typename N
    >
    struct def<Succ, N, SuccOf<N>> {};

}
