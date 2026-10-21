package org.db.dao;

import org.db.model.Interests;

import java.util.List;

/**
 * Created by mgunes on 07.01.2017.
 */
public interface InterestsDAO {
    List<Interests> getMyInterests(String username);
    List<Interests> getInterestsByQuery(String query);
    boolean saveInterests(Interests interests);
    boolean deleteInterestsByName(String name);
    boolean updateInterests(String oldName, Interests interests);
}
