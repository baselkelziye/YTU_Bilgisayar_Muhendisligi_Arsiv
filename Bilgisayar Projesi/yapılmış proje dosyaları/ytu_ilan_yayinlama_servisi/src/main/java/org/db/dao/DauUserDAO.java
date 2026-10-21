package org.db.dao;

import org.db.model.DauUser;
import org.db.model.User;

import java.util.List;

public interface DauUserDAO {
	boolean saveDauUser(DauUser user);
	boolean deleteUser(String username);
	List<DauUser> getUsersFromDau(String unitName);
}
