#pragma once

#include <string>
#include <vector>

#include "SchoolBranch.h"

namespace LanguageSchool
{
    class InformationSystem
    {
    public:
        void addNewBranch();
        void deleteBranch();

    private:
        std::vector<SchoolBranch> branches;
    };
} // LanguageSchool
