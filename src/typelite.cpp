#include "typelite.h"
#include "typelite/tag.h"
#include "sacl.h"

template <>
void sacl<typelite::sacl_mod>()
{
    sacls<typelite__sacls>();
}
