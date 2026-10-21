package org.db.hibernate;

import org.db.dao.EducationInfoDAO;
import org.db.model.EducationInfo;

import java.io.Serializable;
import java.util.List;

/**
 * Created by mgunes on 27.01.2017.
 */
public class EducationInfoHibernateImpl extends AbstractDAO implements EducationInfoDAO {
    public List<EducationInfo> getByStudent(String username) {
        String query = "SELECT * FROM education_info WHERE student = '" + username + "' ORDER BY start_date;";
        return  getRowsBySQLQuery(EducationInfo.class, query);
    }

    public boolean saveEducationInfo(EducationInfo info) {
        return save(info);
    }
}
