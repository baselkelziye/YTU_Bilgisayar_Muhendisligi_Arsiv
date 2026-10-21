package org.db.dao;

import java.util.List;

import org.db.model.BankAccountInfo;
import org.db.model.CompanyOwnPacket;
import org.db.model.DauUser;
import org.db.model.DonationAcceptUnit;

public interface DonationAcceptUnitDAO {
	boolean saveDonationAcceptUnit(DonationAcceptUnit dau);
	boolean saveBankAccount(BankAccountInfo bai);
	List<DonationAcceptUnit> getAllUnits();
	List<CompanyOwnPacket> getWaitingDonation(String dauUsername);
	DonationAcceptUnit getUnit(String unitName);
	boolean deleteDau(String unitName);
    List<DauUser> getSiblingUsers(String unitName);
}
