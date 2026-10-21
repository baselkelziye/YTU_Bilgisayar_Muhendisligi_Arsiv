package org.db.hibernate;

import org.db.dao.SpendingRequestStateDAO;
import org.db.model.SpendingRequestState;

import java.util.List;

/**
 * Created by mgunes on 25.12.2016.
 */
public class SRStateHibernateImpl extends AbstractDAO implements SpendingRequestStateDAO {
    public List<SpendingRequestState> getAllStates() {
        return getAllRows(SpendingRequestState.class);
    }
}
