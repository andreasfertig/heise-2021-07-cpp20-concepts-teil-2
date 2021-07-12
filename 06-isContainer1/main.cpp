// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <array>
#include <vector>

template<typename T>
concept container = requires(T t)
{
    typename T::value_type;
    typename T::size_type;
    typename T::allocator_type;
    typename T::iterator;
    typename T::const_iterator;
    t.size();
    t.begin();
    t.end();
    t.cbegin();
    t.cend();
};

struct A
{
};

static_assert(not container<A>);
static_assert(container<std::vector<int>>);

static_assert(not container<std::array<int, 5>>);
int main() {}
