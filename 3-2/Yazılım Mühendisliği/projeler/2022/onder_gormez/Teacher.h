#pragma once

#include <vector>
#include <string>

#include "Worker.h"
#include "SchoolBranch.h"

namespace LanguageSchool
{
    class Teacher : public Worker
    {
    public:
    private:
        std::vector<std::string> m_languages;
        std::vector<SchoolBranch> m_classLocations;
        std::string m_availableDays;
        std::string m_availableHours;
    };
} // LanguageSchool
