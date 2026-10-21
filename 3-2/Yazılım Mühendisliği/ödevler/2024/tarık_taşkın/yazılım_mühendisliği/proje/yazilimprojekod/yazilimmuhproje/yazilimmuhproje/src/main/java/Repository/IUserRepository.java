package Repository;

import Entities.User;

public interface IUserRepository {
    User findByEmail(String email);
}
