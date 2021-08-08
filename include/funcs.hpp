#pragma once

#include <type_traits>
#include <iostream>

#include <include/types.h>

void func_withAsio() {
    std::puts(__FUNCSIG__);
}

void func_withLibuv() {
    std::puts(__FUNCSIG__);
}

template <typename T, typename ...Args>
void func(Args... args)
{
    if constexpr (std::is_same_v<decltype(T::thread_selector), AsioBased>)
    {
        func_withAsio(std::forward<Args>(args)...);
    }
    else if constexpr (std::is_same_v<decltype(T::thread_selector), LibuvBased>)
    {
        func_withLibuv(std::forward<Args>(args)...);
    }
}