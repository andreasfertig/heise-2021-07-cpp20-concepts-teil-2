// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <type_traits>

template<typename T>
class Wrapper
{
public:
    template<typename std::enable_if<std::is_default_constructible_v<T>,
                                     T>::type = 0>
    Wrapper()
    {
    }

    Wrapper(T) {}

    // more access functions
};

static_assert(std::is_default_constructible_v<Wrapper<int>>);

int main() {}