#pragma once

#include <string>

// TODO: SetLecturer?
namespace LanguageSchool
{
    class Course
    {
    protected:
        std::string m_name;
        int m_capacity;
        int m_registeredStudentCount;
        std::string m_level;

    public:
        void setName(std::string newName);
        std::string getName();
        bool addNewStudent();
        bool deleteStudent();
    };
} // LanguageSchool
