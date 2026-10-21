package org.db.hibernate;

import org.db.dao.VerificationCodeDAO;
import org.db.model.Student;
import org.db.model.VerificationCode;
import org.hibernate.SQLQuery;
import org.hibernate.Session;

import java.util.Date;
import java.util.List;

/**
 * Created by mgunes on 25.01.2017.
 */
public class VerificationCodeHibernateImpl extends AbstractDAO implements VerificationCodeDAO {
    private Session session;

    public VerificationCode findActivateDate(String username) {
        String sql = "SELECT * FROM verification_code WHERE user_name = '" + username + "' and state = 'Aktif'";
        List<VerificationCode> verificationCodeList = getRowsBySQLQuery(VerificationCode.class, sql);

        if(verificationCodeList.size() == 0)
            return null;
        else
            return verificationCodeList.get(0);
    }

    public boolean reCode(Student student, String code) {
        String sql = "UPDATE verification_code SET state = 'Yeni Kod Gönderildi', operation_time = now() " +
                " WHERE user_name = '" + student.getUserName() + "' and state = 'Onay Bekleniyor';";

        VerificationCode verificationCode = new VerificationCode();
        verificationCode.setCode(code);
        verificationCode.setSendingTime(new Date());
        verificationCode.setUsername(student);
        verificationCode.setState("Onay Bekleniyor");

        try {
            session = HibernateSessionFactory.getSessionFactory().openSession();
            session.getTransaction().begin();
            SQLQuery query = session.createSQLQuery(sql);
            session.save(verificationCode);
            query.executeUpdate();
            session.getTransaction().commit();
            return true;
        } catch (Exception ex) {
            session.getTransaction().rollback();
            System.out.println("Recode hatası: " + ex.getMessage());
            ex.printStackTrace();
            return false;
        } finally {
            session.close();
        }
    }
}
