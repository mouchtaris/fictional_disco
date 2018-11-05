#include "common.h"

template <
    typename...
>
struct pig {
    static constexpr char const* _value() { return __PRETTY_FUNCTION__; }
    static constexpr char const* val = pig::_value();
};
