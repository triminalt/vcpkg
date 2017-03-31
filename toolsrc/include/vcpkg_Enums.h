#pragma once
#include <string>
#include <array>
#include <utility>
#include "vcpkg_Checks.h"

namespace vcpkg::Enums
{
    namespace details
    {
        template<size_t Sz1, size_t Sz2, size_t...Szs1, size_t...Szs2>
        constexpr std::array<char, Sz1-1 + Sz2> concat(const char(&a1)[Sz1], const char(&a2)[Sz2], std::index_sequence<Szs1...>, std::index_sequence<Szs2...>)
        {
            return { a1[Szs1]..., a2[Szs2]... };
        }
    }

    template<size_t Sz1, size_t Sz2>
    constexpr std::array<char, Sz1-1+Sz2> concat(const char(&a1)[Sz1], const char(&a2)[Sz2])
    {
        return details::concat(a1, a2, std::make_index_sequence<Sz1-1>(), std::make_index_sequence<Sz2>());
    }

    template<size_t Sz1>
    constexpr auto nullvalue_toString(const char(&a)[Sz1])
    {
        return concat(a, "::NULLVALUE");
    }
}
