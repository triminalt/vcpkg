#include "pch.h"
#include "PostBuildLint_ConfigurationType.h"
#include "vcpkg_Enums.h"
#include "package_spec.h"

namespace vcpkg::PostBuildLint::ConfigurationType
{
    static constexpr auto NULLVALUE_STRING = Enums::nullvalue_toString(ENUM_NAME);
    static constexpr auto NAME_DEBUG = "Debug";
    static constexpr auto NAME_RELEASE = "Release";

    cstring_view type::toString() const
    {
        switch (this->backing_enum)
        {
        case ConfigurationType::DEBUG:
            return NAME_DEBUG;
        case ConfigurationType::RELEASE:
            return NAME_RELEASE;
        case ConfigurationType::NULLVALUE:
            return NULLVALUE_STRING.data();
        default:
            Checks::unreachable(VCPKG_LINE_INFO);
        }
    }
}
