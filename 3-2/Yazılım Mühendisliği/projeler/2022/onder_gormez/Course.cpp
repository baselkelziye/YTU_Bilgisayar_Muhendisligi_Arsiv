

bool Course::addNewStudent()
{
    if (m_registeredStudentCount == m_capacity)
    {
        std::cout << "Hata: Kapasite dolu!";
        return false;
    }

    ++m_registeredStudentCount;
    return true;
}

bool Course::deleteStudent()
{
    // TODO: Öğrenci derse kayıtlı mı kontrolü yapılmalıdır.
    if (m_registeredStudentCount == 0)
    {
        std::cout << "Hata: Öğrenci ekli değil!";
        return false;
    }

    --m_registeredStudentCount;
    return true;
}
