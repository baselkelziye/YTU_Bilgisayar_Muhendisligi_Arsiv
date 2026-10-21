package org.db.dao;

import org.db.model.Announcement;
import org.db.model.Company;

import java.util.List;

public interface CompanyDAO {
    boolean updateCompanyPassword(Company c);
	boolean saveCompany(Company c);
	boolean updateCompanyUser(Company c);
	boolean deleteCompany(Company c);
    boolean deleteCompany(String username);
    List<Announcement> getMyActiveAnnouncements(String username);
    List<Announcement> getMyPassiveAnnouncements(String username);
    List<Announcement> getMySuspendedAnnouncements(String username);
    List<Company> getWaitingApproval();
    Company getCompany(String username);
}
