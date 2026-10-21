package org.db.dao;

import org.db.model.SpendingRequestState;

import java.util.List;

/**
 * Created by mgunes on 25.12.2016.
 */
public interface SpendingRequestStateDAO {
    List<SpendingRequestState> getAllStates();
}
