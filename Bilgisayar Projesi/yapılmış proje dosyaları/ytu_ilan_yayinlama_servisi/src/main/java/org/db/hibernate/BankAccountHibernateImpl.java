package org.db.hibernate;

import org.db.dao.BankAccountDAO;
import org.db.model.Accounting;
import org.db.model.AnnouncementPacket;
import org.db.model.BankAccountInfo;
import org.hibernate.SQLQuery;
import org.hibernate.Session;

import java.util.List;

public class BankAccountHibernateImpl extends AbstractDAO implements BankAccountDAO {
    private Session session;

	public boolean saveBankAccount(BankAccountInfo bai) {
		return save(bai);
	}

	public boolean updateBankAccount(BankAccountInfo bai, String oldIban) {
	    //kaydı yeni satır olarak ekle
        //paketlerdeki ibanları bu kayda referans ver
        //eski kaydı sil

		/*StringBuilder query = new StringBuilder();
        query.append("UPDATE bank_account_info SET bank_name = ");
        query.append(" '" + bai.getBankName() + "', ");
        query.append(" branch_bank_name = '" + bai.getBranchBankName() + "', ");
        query.append(" bank_account_number = '" + bai.getBankAccountNumber() + "', ");
        query.append(" iban = '" + bai.getIban().trim() + "' ");
        query.append(" WHERE iban = '" + oldIban + "'");*/

		if(bai.getIban().trim().equals(oldIban)) {
		    return save(bai);
        } else {
           /* String query2 = "UPDATE announcement_packet SET bank_account_info = '" + bai.getIban().trim() + "' " +
                    "WHERE bank_account_info = '" + oldIban + "';";
            String query3 = "DELETE FROM bank_account_info WHERE iban = '" + oldIban + "';";
            boolean b1 = save(bai);
            boolean b2 = updateBySQLQuery(AnnouncementPacket.class, query2);
            boolean b3 = updateBySQLQuery(BankAccountInfo.class, query3);

            return (b1 && b2 && b3);*/
           return false;
        }


        /*session = HibernateSessionFactory.getSessionFactory().openSession();

		try {
            SQLQuery q2 = session.createSQLQuery(query2);
            SQLQuery q3 = session.createSQLQuery(query3);

            session.getTransaction().begin();
            session.save(bai);
            q2.executeUpdate();
            q3.executeUpdate();
            session.getTransaction().commit();
            return true;
        } catch (Exception ex) {
            session.getTransaction().rollback();
            ex.printStackTrace();
            return false;
        } finally {
            session.close();
        }*/
    }

	public BankAccountInfo getAccount(String iban) {
		return (BankAccountInfo) getObject(BankAccountInfo.class, iban);
	}

	public List<BankAccountInfo> getSiblingAccounts(String iban) {
		String query = "select * \n" +
                "from bank_account_info b ,bank_account_info b2\n" +
                "where b.owner_unit_name = b2.owner_unit_name and (b.iban = '" + iban + "' or b2.iban ='" + iban + "')";
		return getRowsBySQLQuery(BankAccountInfo.class, query);
	}

	public boolean deleteAccount(String iban) {
		return deleteByQuery(Accounting.class, "BankAccountInfo", "iban", iban);
	}

}
