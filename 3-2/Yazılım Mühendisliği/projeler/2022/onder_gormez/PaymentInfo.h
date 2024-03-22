#pragma once

#include <vector>
#include <string>

namespace LanguageSchool
{
    struct PaymentInfo
    {
    public:
        // Ödenen taksiti siler
        void deleteInstallment();

    private:
        // peşin ödendi mi?
        bool isPaidInAdvance;
        // Nisan, Mayıs, Haziran
        std::vector<std::string> installments;
        // 1000 er lira olarak aylık ödeyecek
        int installmentAmount = 1000;
    };
} // LanguageSchool
