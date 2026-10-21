package org.db.hibernate;

import org.db.dao.InterestsDAO;
import org.db.model.Interests;

import java.util.List;

/**
 * Created by mgunes on 07.01.2017.
 */
public class InterestsHibernateImpl extends AbstractDAO implements InterestsDAO {

    public List<Interests> getMyInterests(String username) {
        String query = "SELECT * FROM interests WHERE student = '" + username + "';";
        return getRowsBySQLQuery(Interests.class, query);
    }

    public List<Interests> getInterestsByQuery(String query) {
        return getRowsBySQLQuery(Interests.class, query);
    }

    public boolean saveInterests(Interests interests) {
        return save(interests);
    }

    public boolean deleteInterestsByName(String name) {
        return deleteByQuery(Interests.class, "Interests", "name", name);
    }

    public boolean updateInterests(String oldName, Interests interests) {
        String query = " UPDATE interests SET name = '" + interests.getName() + "' , student = '" + interests.getStudent().getUserName() + "' , " +
                " category = " + interests.getCategory().getId() + " , ann_type = " + interests.getType().getId() + ", " +
                " language = '" + interests.getLanguage() + "' , keywords = '" + interests.getKeywords() + "' " +
                " WHERE name = '" + oldName + "';";

        return updateBySQLQuery(Interests.class, query);
    }
}
