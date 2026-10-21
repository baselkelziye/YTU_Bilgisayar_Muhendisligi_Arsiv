package org.db.dao;

import org.db.model.GlobalParameter;

import java.util.List;
import java.util.Map;

/**
 * Created by mgunes on 27.01.2017.
 */
public interface GlobalParameterDAO {
    Map<String, String> getParameters(String type);
    List<GlobalParameter> getParameterList(String type);
    boolean updateParameters(Map<String, String> parameter);

}
