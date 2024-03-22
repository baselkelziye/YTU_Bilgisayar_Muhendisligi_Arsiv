#include "Person.h"

namespace LanguageSchool
{
    class Person::Person(std::string name, std::string surname, std::string mobilephone, std::string phone, std::string email, int age, std::string gender, std::string address) : m_name(name),
                                                                                                                                                                                   m_surname(surname),
                                                                                                                                                                                   m_mobilephone(mobilephone),
                                                                                                                                                                                   m_phone(phone),
                                                                                                                                                                                   m_email(email),
                                                                                                                                                                                   m_age(age),
                                                                                                                                                                                   m_gender(gender),
                                                                                                                                                                                   m_address(address)

    {
    }

    void Person::setName(std::string newName)
    {
        m_name = newName;
    }

    std::string Person::getName()
    {
        return m_name;
    }
} // LanguageSchool
