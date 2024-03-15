#pragma once

namespace LanguageSchool
{
    class ClassRoom
    {
        // TODO: Maybe move this
    };

    class SchoolBranch
    {
    private:
        std::string m_name;
        std::string m_address;
        // M2 metro, T34, 500T bus
        std::string m_publicTransport;
        // Use 15 Temmuz Bridge
        std::string m_privateTransport;
        // table tennis, langırt, ...
        std::vector<std::string> m_socialBenefits;
        std::vector<ClassRoom> m_allClasses;
        bool m_isActiveBranch;

    public:
        void activateBranch();
        void deactivateBranch();
    };
} // LanguageSchool
