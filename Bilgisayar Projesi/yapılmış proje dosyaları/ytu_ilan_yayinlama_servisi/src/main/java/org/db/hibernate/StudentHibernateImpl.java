package org.db.hibernate;

import org.db.dao.StudentDAO;
import org.db.model.Student;
import org.db.model.VerificationCode;
import org.hibernate.SQLQuery;
import org.hibernate.Session;

import java.util.Date;
import java.util.List;
import java.util.Random;

public class StudentHibernateImpl extends AbstractDAO implements StudentDAO {
    private Session session;

	public String saveStudent(Student student) {
	    Random random = new Random();
        String code;

        do {
            code = String.valueOf(random.nextInt(100000) + 100000);
            code += "lj";
        } while (isCodeExist(code));

        VerificationCode verificationCode = new VerificationCode();
        verificationCode.setCode(code);
        verificationCode.setSendingTime(new Date());
        verificationCode.setUsername(student);
        verificationCode.setState("Onay Bekleniyor");

        try {
            session = HibernateSessionFactory.getSessionFactory().openSession();
            session.getTransaction().begin();
            session.save(student);
            session.save(verificationCode);
            session.getTransaction().commit();
            return code;
        } catch (Exception ex) {
            session.getTransaction().rollback();
            System.out.println("Öğrenci kayıt edilemedi");
            ex.printStackTrace();
            return "hata";
        } finally {
            session.close();
        }
	}

    public int activateStudent(Student student, String code) {
        //önce kodun doğruluğunu kontrol et
        if(!isCodeMatching(code, student.getUserName()))
            return 0;

        String q1 = "UPDATE verification_code SET operation_time = now(), state = 'Aktif' WHERE code = '" + code + "';";
        String q2 = "UPDATE users SET membership_status = 1 WHERE user_name = '" + student.getUserName() + "';";

        try {
            session = HibernateSessionFactory.getSessionFactory().openSession();
            session.getTransaction().begin();
            SQLQuery sqlQuery = session.createSQLQuery(q1);
            SQLQuery sqlQuery2 = session.createSQLQuery(q2);
            sqlQuery.executeUpdate();
            sqlQuery2.executeUpdate();
            session.getTransaction().commit();
            return 1;
        } catch (Exception ex) {
            session.getTransaction().rollback();
            System.out.println("Aktifleştirme hatası: " + ex.getMessage());
            ex.printStackTrace();
            return 2;
        } finally {
            session.close();
        }
    }

    private boolean isCodeMatching(String code, String username) {
        String sql = "SELECT * FROM verification_code WHERE code = '" + code + "' and user_name = '" + username + "' and " +
                " state = 'Onay Bekleniyor'";

        List<VerificationCode> codeList = getRowsBySQLQuery(VerificationCode.class, sql);

        if(codeList.size() == 0)
            return false;
        else
            return true;
    }

    public Student getStudent(String username) {
		return (Student) getObject(Student.class, (Object)username);
	}

	public boolean isCodeExist(String code) {
	    Object o = getObject(VerificationCode.class, code);

        if(o == null)
            return false;
        else
            return true;
    }
}
