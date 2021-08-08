#pragma once

#include <type_traits>
#include <iostream>

#include <include/types.h>

void func_withAsio()
{
    std::puts(__FUNCSIG__);
}

void func_withLibuv()
{
    std::puts(__FUNCSIG__);
}
void func_withStdThread(std::string const& input)
{
    std::puts(input.c_str());
    std::puts(__FUNCSIG__);
}

template <typename T, typename... Args>
void func(Args... args)
{
    static_assert(std::is_same_v<decltype(T::thread_selector), AsioBased> ||
                      std::is_same_v<decltype(T::thread_selector), LibuvBased> ||
                      std::is_same_v<decltype(T::thread_selector), CustomThreadBased>,
                  "You have to select either asio, libuv or custom");
    if constexpr (std::is_same_v<decltype(T::thread_selector), AsioBased>)
    {
        func_withAsio(std::forward<Args>(args)...);
    }
    else if constexpr (std::is_same_v<decltype(T::thread_selector), LibuvBased>)
    {
        func_withLibuv(std::forward<Args>(args)...);
    }
    else if constexpr (std::is_same_v<decltype(T::thread_selector), CustomThreadBased>)
    {
        func_withStdThread(std::forward<Args>(args)...);
    }
}