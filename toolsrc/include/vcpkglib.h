#pragma once

#include "StatusParagraphs.h"
#include "vcpkg_paths.h"
#include "ImmutableSortedVector.h"

namespace vcpkg
{
    extern bool g_debugging;

    StatusParagraphs database_load_check(const vcpkg_paths& paths);

    void write_update(const vcpkg_paths& paths, const StatusParagraph& p);

    struct StatusParagraph_and_associated_files
    {
        StatusParagraph pgh;
        ImmutableSortedVector<std::string> files;
    };

    std::vector<StatusParagraph_and_associated_files> get_installed_files(const vcpkg_paths& paths, const StatusParagraphs& status_db);


    struct CMakeVariable
    {
        CMakeVariable(const cwstring_view varname, const cwstring_view varvalue);
        CMakeVariable(const cwstring_view varname, const cstring_view varvalue);
        static CMakeVariable from_path(const cwstring_view varname, const fs::path& path)
        {
            return CMakeVariable(varname, path.generic_wstring());
        }

        std::wstring s;
    };

    std::wstring make_cmake_cmd(const fs::path& cmake_exe, const fs::path& cmake_script, const std::vector<CMakeVariable>& pass_variables);

} // namespace vcpkg
