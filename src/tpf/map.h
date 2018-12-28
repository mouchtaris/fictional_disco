#pragma once
#include "set.h"
/**
 * Use Set as a Map, by inserting pairs of Key-Value.
 */
namespace tpf::map
{
    /** def init = Map() */
    struct init;

    /** def eq cmp p0 p1 = cmp p0.key p1.key */
    struct eq;

    /** def add set cmp p = add set (eq cmp) p */
    struct add;

    /** def find set cmp v = find set (eq cmp) v */
    struct find;
}
