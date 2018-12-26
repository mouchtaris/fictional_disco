#include "typelite.h"
#include "lr1.h"
#include "smaragd.h"
#include "sacl.h"

int main(int, char**)
{
    sacls<
        typelite::sacl_mod,
        lr1::sacl_mod,
        smaragd::sacl_mod
    >();
    return 0;
}
