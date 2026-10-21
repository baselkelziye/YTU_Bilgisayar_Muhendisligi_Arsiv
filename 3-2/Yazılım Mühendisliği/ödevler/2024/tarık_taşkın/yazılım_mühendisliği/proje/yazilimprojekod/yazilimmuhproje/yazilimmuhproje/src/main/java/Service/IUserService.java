package Service;

import DTO.UserDto;
import DTO.UserLoginDto;

public interface IUserService {
    UserDto login(UserLoginDto loginDto);
}
