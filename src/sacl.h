#pragma once

template <typename> extern void sacl();

template <
    typename... Sacls
>
void sacls()
{
    (
        sacl<Sacls>(), ...
    );
}
