#pragma once

#include <string>

#include "Person.h"

namespace LanguageSchool
{
    class Worker : public Person
    {
    private:
        std::string workStartDate;
        std::string workEndDate;
        bool isActiveWorker;
        int salary;

    public:
        void updateSalaryAccordingToInflation(double inflationRate);
    };
} // LanguageSchool
