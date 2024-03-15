#pragma once

#include <string>

namespace LanguageSchool
{
    class Person
    {
    protected:
        std::string m_name;
        std::string m_surname;
        std::string m_mobilephone;
        std::string m_phone;
        std::string m_email;
        int m_age;
        std::string m_gender;
        std::string m_address;

    public:
        Person(std::string name, std::string surname, std::string mobilephone, std::string phone, std::string email, int age, std::string gender, std::string address);
        void setName(std::string newName);
        std::string getName();
    };
} // LanguageSchool
