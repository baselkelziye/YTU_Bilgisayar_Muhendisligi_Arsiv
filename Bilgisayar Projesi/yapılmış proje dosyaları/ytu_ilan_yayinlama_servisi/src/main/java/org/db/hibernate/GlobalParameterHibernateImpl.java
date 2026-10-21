package org.db.hibernate;

import org.db.dao.GlobalParameterDAO;
import org.db.model.GlobalParameter;
import org.hibernate.SQLQuery;
import org.hibernate.Session;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by mgunes on 27.01.2017.
 */
public class GlobalParameterHibernateImpl extends AbstractDAO implements GlobalParameterDAO {
    private Session session;

    public Map<String, String> getParameters(String type) {
        String query = "SELECT * FROM global_parameter WHERE type = '" + type + "' ";
        List<GlobalParameter> parameterList = getRowsBySQLQuery(GlobalParameter.class, query);
        Map<String, String> parameterMap = new HashMap<String, String>();

        for(GlobalParameter parameter: parameterList)
            parameterMap.put(parameter.getName(), parameter.getValue());

        return parameterMap;
    }

    public List<GlobalParameter> getParameterList(String type) {
        String query = "SELECT * FROM global_parameter WHERE type = '" + type + "';";
        return getRowsBySQLQuery(GlobalParameter.class, query);
    }

    public boolean updateParameters(Map<String, String> parameter) {
        try {
            session = HibernateSessionFactory.getSessionFactory().openSession();
            session.getTransaction().begin();

            List<SQLQuery> queryList = new ArrayList<SQLQuery>();

            for(String name: parameter.keySet()) {
                String query = "UPDATE global_parameter SET value = '" + parameter.get(name) + "' WHERE name = '" + name + "';";
                queryList.add(session.createSQLQuery(query));
            }

            for(SQLQuery query: queryList) {
                query.executeUpdate();
            }

            session.getTransaction().commit();
            return true;
        } catch (Exception ex) {
            session.getTransaction().rollback();
            System.out.println("Global parametreler güncellenemedi: " + ex.getMessage());
            ex.printStackTrace();
            return false;
        } finally {
            session.close();
        }
    }
}
