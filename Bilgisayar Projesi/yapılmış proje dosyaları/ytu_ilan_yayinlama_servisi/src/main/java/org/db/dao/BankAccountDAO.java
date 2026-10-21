package org.db.dao;

import org.db.model.BankAccountInfo;

import java.util.List;

public interface BankAccountDAO {
	BankAccountInfo getAccount(String iban);
    List<BankAccountInfo> getSiblingAccounts(String iban);
	boolean saveBankAccount(BankAccountInfo bai);
	boolean updateBankAccount(BankAccountInfo bai, String oldIban);
	boolean deleteAccount(String iban);
}
