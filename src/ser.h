#pragma once
#include <array>

void ser_compiled();
void test_ser();

///
// Bytes
template <
    typename T
>
using bytes = std::array<uint8_t, sizeof(T)>;


///
// Serialization type class
template <
    typename T
>
struct ser_tc;

///
// Integer serialization implementation
template <
    typename T,
    typename Is // index_sequence...
>
struct ser_int_impl;
//
template <
    typename T,
    size_t... I
>
struct ser_int_impl<T, std::index_sequence<I...>> {
    static constexpr auto ser (T i)
    {
        return bytes<T> {
            static_cast<uint8_t>((i >> (8 * I)) & 0xff) ...
        };
    }

    static constexpr auto deser (bytes<T> bs)
    {
        return static_cast<T>(
            ((static_cast<T>(bs[I]) << (8 * I)) | ...)
        );
    }
};

///
// Integer serialization
#define SER_INT(T) template <> struct ser_tc<T>: public ser_int_impl<T, std::make_index_sequence<sizeof(T)>> {}
SER_INT(uint8_t);
SER_INT(uint16_t);
SER_INT(uint32_t);
SER_INT(uint64_t);
SER_INT(int8_t);
SER_INT(int16_t);
SER_INT(int32_t);
SER_INT(int64_t);

///
// Serialization Facade
template <
    typename T
>
auto deser(bytes<T> bytes)
{
    return ser_tc<T>::deser(bytes);
}

template <
    typename T
>
auto ser(T t)
{
    return ser_tc<T>::ser(t);
}
