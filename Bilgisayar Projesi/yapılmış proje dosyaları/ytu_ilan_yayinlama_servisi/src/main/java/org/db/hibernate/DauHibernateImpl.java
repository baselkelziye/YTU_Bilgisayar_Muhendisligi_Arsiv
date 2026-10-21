package org.db.hibernate;

import java.util.List;

import org.db.dao.DonationAcceptUnitDAO;
import org.db.model.*;
import org.hibernate.SQLQuery;
import org.hibernate.Session;

public class DauHibernateImpl extends AbstractDAO implements DonationAcceptUnitDAO{
	private Session session;

	public boolean saveDonationAcceptUnit(DonationAcceptUnit dau) {
		return save(dau);
	}

	public boolean saveBankAccount(BankAccountInfo bai) {
		return save(bai);
	}

	public List<DonationAcceptUnit> getAllUnits() {
		return getAllRows(DonationAcceptUnit.class);
	}

	public List<CompanyOwnPacket> getWaitingDonation(String unitName) {
		try {
			String query = 
					"select cop.* " +
					"from company_own_packet cop, announcement_packet ap, bank_account_info bip " +
					"where cop.packet=ap.packet_id "
					+ "and ap.bank_account_info=bip.iban "
					+ "and (cop.announcement_packet_state = 1 or cop.announcement_packet_state = 6 ) "
					+ "and bip.owner_unit_name = '" + unitName + "' ";
			session = HibernateSessionFactory.getSessionFactory().openSession();
			session.beginTransaction();
			SQLQuery sqlQuery = session.createSQLQuery(query);
			sqlQuery.addEntity(CompanyOwnPacket.class);
			List<CompanyOwnPacket> packetList = sqlQuery.list();
			session.getTransaction().commit();
			
			return packetList;
			
		} catch(Exception ex) {
			session.getTransaction().rollback();
			System.err.println("Bekleyen bağışlar getirilemedi:" + ex.getMessage());
			return null;
		}
		finally {
			session.close();
		}
		
	}

	public DonationAcceptUnit getUnit(String unitName) {
		return (DonationAcceptUnit) getObject(DonationAcceptUnit.class, unitName);
	}

	public boolean deleteDau(String unitName) {
	    String acc = "SELECT * FROM accounting WHERE unit_name ='" + unitName + "';";
        List<Accounting> accList = getRowsBySQLQuery(Accounting.class, acc);

        if(accList.size() > 0) { //muhasebe kaydı varsa silinemez
            return false;
        }

        String bai = "SELECT d.unit_name, d.balance, d.created_date " +
        " FROM donation_accept_unit d, bank_account_info b, announcement_packet a " +
        " WHERE d.unit_name = b.owner_unit_name AND b.iban = a.bank_account_info AND d.unit_name = '" + unitName + "';";

        List<DonationAcceptUnit> dauList = getRowsBySQLQuery(DonationAcceptUnit.class, bai);

        if(dauList.size() > 0) { // üzerinde paket tanımlıysa silinemez
            return false;
        }

        String dau = "DELETE FROM donation_accept_unit WHERE unit_name = '" + unitName + "'";
        String bai2 = "DELETE FROM bank_account_info WHERE owner_unit_name = '" + unitName + "';";
        String user2 = "DELETE FROM users WHERE user_type_no = 1 and user_name not in (SELECT user_name FROM dau_user)";
        String user = "DELETE FROM dau_user WHERE unit_name = '" + unitName + "';";


        //ikisi de yoksa önce user ve hesapları sonra vakfı sil
        deleteDauCascade(bai2);
        deleteDauCascade(user);
        deleteDauCascade(user2);
        return deleteDauCascade(dau);
	}

	public List<DauUser> getSiblingUsers(String unitName) {
		String sql = "SELECT * FROM dau_user WHERE unit_name = '" + unitName + "';";
		return getRowsBySQLQuery(DauUser.class, sql);
	}

	private boolean deleteDauCascade(String sql) {

	    try {
	        session = HibernateSessionFactory.getSessionFactory().openSession();
	        session.getTransaction().begin();

            SQLQuery query = session.createSQLQuery(sql);
            query.executeUpdate();
            session.getTransaction().commit();

	        return true;
        } catch (Exception e) {
            System.out.println("deleteDauCascade:" + e.getMessage());
            session.getTransaction().rollback();
            return false;
        } finally {
            session.close();
        }
    }

}
