#pragma once
#include <string>
#include "vcpkg_Checks.h"

namespace vcpkg::Enums
{
    std::string nullvalue_toString(const std::string& enum_name);

    [[noreturn]]
    void nullvalue_used(const Checks::line_info& linfo, const std::string& enum_name);
}
