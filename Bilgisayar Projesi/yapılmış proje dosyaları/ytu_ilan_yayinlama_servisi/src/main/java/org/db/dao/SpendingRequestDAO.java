package org.db.dao;

import java.util.List;

import org.db.model.SpendingRequest;

public interface SpendingRequestDAO {
	boolean sendRequest(SpendingRequest sr);
	boolean updateRequest(SpendingRequest sr);
	int calculateTotalRequestAmount(String unitName);
	List<SpendingRequest> listSpendingRequest(String unitName, int state);
	SpendingRequest getSpendingRequest(int id);
	List<SpendingRequest> getAllSpendingRequest();
	List<SpendingRequest> getSpendingRequestByQuery(String query);
}
