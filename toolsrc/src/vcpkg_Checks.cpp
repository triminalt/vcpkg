#include "pch.h"
#include "vcpkg_Checks.h"
#include "vcpkg_System.h"
#include "vcpkglib.h"

namespace vcpkg::Checks
{
    [[noreturn]]
    void unreachable(const line_info& linfo)
    {
        System::println(System::color::error,
            "Error: Unreachable code was reached\n"
            "%s(%d)", linfo.file_name, linfo.line_number); // Always print linfo here
#ifndef NDEBUG
        std::abort();
#else
        ::exit(EXIT_FAILURE);
#endif
    }

    [[noreturn]]
    void exit_with_code(const line_info& linfo, const int exit_code)
    {
        if (g_debugging)
        {
            System::println(System::color::error, "[DEBUG] %s(%d)", linfo.file_name, linfo.line_number);
        }
        ::exit(exit_code);
    }

    [[noreturn]]
    void exit_with_message(const line_info& linfo, const cstring_view errorMessage)
    {
        if (errorMessage)
            System::println(System::color::error, errorMessage);
        exit_fail(linfo);
    }
}
