// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <array>
#include <vector>

template<typename T, typename U = void>  // A
struct is_container : std::false_type
{
};

template<typename T>
struct is_container<T,
                    std::void_t<typename T::value_type,  // B
                                typename T::size_type,
                                typename T::allocator_type,
                                typename T::iterator,
                                typename T::const_iterator,
                                decltype(std::declval<T>().size()),
                                decltype(std::declval<T>().begin()),
                                decltype(std::declval<T>().end()),
                                decltype(std::declval<T>().cbegin()),
                                decltype(std::declval<T>().cend())>>
: std::true_type
{
};

struct A
{
};

static_assert(!is_container<A>::value);  // C
static_assert(is_container<std::vector<int>>::value);

static_assert(not is_container<std::array<int, 5>>::value);
int main() {}
