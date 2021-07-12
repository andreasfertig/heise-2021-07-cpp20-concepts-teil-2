// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <type_traits>

template<typename T>
class Wrapper
{
public:
    Wrapper() requires(std::is_default_constructible_v<T>) = default;

    Wrapper(T) {}
};

struct A
{
    A() = delete;
    ;
};

static_assert(std::is_default_constructible_v<Wrapper<int>>);
static_assert(not std::is_default_constructible_v<Wrapper<A>>);

int main() {}