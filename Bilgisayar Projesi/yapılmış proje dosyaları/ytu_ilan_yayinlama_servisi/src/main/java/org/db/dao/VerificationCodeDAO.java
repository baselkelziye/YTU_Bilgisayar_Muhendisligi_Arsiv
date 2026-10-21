package org.db.dao;

import org.db.model.Student;
import org.db.model.VerificationCode;

/**
 * Created by mgunes on 25.01.2017.
 */
public interface VerificationCodeDAO {
    VerificationCode findActivateDate(String username);
    boolean reCode(Student student, String code);
}
