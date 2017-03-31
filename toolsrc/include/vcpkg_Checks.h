#pragma once

#include "vcpkg_Strings.h"


namespace vcpkg::Checks
{
    struct line_info
    {
        int line_number;
        const char* file_name;

        constexpr line_info() : line_number(0), file_name(nullptr) {}
        constexpr line_info(const int line_number, const char* file_name) : line_number(line_number), file_name(file_name) {}
    };

#define VCPKG_LINE_INFO vcpkg::Checks::line_info(__LINE__, __FILE__)

    [[noreturn]]
    void unreachable(const line_info& linfo);

    [[noreturn]]
    void exit_with_code(const line_info& linfo, const int exit_code);

    [[noreturn]]
    inline void exit_fail(const line_info& linfo)
    {
        exit_with_code(linfo, EXIT_FAILURE);
    }

    [[noreturn]]
    inline void exit_success(const line_info& linfo)
    {
        exit_with_code(linfo, EXIT_SUCCESS);
    }

    [[noreturn]]
    void exit_with_message(const line_info& linfo, const cstring_view errorMessage = "");

    template <class Arg1, class...Args>
    [[noreturn]]
    void exit_with_message(const line_info& linfo, const char* errorMessageTemplate, const Arg1& errorMessageArg1, const Args&... errorMessageArgs)
    {
        exit_with_message(linfo, Strings::format(errorMessageTemplate, errorMessageArg1, errorMessageArgs...));
    }

    template <class...Args>
    void check_exit(const line_info& linfo, bool expression, const Args&... errorMessageArgs)
    {
        if (!expression)
        {
            exit_with_message(linfo, errorMessageArgs...);
        }
    }
}
