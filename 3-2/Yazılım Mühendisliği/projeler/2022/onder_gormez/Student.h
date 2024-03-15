#pragma once

#include <string>
#include <vector>

#include "Person.h"
#include "Course.h"

namespace LanguageSchool
{
    // student.updateName("Batuhan")
    // REQUIRE(student.getName() == "Batuhan")
    class Student : public Person
    {

    public:
        bool addToCourse(Course &course);
        bool deletFromCourse(Course &course);

    private:
        std::vector<std::string> m_courses;
        std::vector<std::string> m_courseLevel;
        std::string m_paymentInfos;
    }

} // LanguageSchool
