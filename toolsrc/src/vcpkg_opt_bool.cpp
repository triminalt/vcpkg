#include "pch.h"
#include "vcpkg_opt_bool.h"
#include "vcpkg_Checks.h"

namespace vcpkg::opt_bool
{
    static constexpr auto UNSPECIFIED_NAME = "unspecified";
    static constexpr auto ENABLED_NAME = "enabled";
    static constexpr auto DISABLED_NAME = "disabled";
    type parse(const std::string& s)
    {
        if (s == UNSPECIFIED_NAME)
        {
            return opt_bool_t::UNSPECIFIED;
        }

        if (s == ENABLED_NAME)
        {
            return opt_bool_t::ENABLED;
        }

        if (s == DISABLED_NAME)
        {
            return opt_bool_t::DISABLED;
        }

        Checks::exit_with_message(VCPKG_LINE_INFO, "Could not convert string [%s] to opt_bool", s);
    }
}
