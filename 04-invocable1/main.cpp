// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#if !defined(_LIBCPP_VERSION) && not defined(_MSC_VER) &&                 \
    not defined(__clang__)
#include <functional>

#include <concepts>
#include <cstdio>
#include <mutex>
#include <type_traits>

std::mutex globalOsMutex;

void DoLocked(std::invocable auto&& f)
{
    std::lock_guard lock{globalOsMutex};

    f();
}

int main()
{
    DoLocked([] { printf("hello\n"); });
}

#else
int main()
{
#pragma message("not supported")
}
#endif