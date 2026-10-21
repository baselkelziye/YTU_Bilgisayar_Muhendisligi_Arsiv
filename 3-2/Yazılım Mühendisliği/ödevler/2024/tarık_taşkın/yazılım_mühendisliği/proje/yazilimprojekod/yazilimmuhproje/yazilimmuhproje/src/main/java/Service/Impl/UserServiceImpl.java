package Service.Impl;

import DTO.UserDto;
import DTO.UserLoginDto;
import Entities.User;
import Repository.IUserRepository;
import Service.IUserService;

public class UserServiceImpl implements IUserService {
    private final IUserRepository userRepository;

    public UserServiceImpl(IUserRepository userRepository) {
        this.userRepository = userRepository;
    }

    @Override
    public UserDto login(UserLoginDto loginDto) {
        User user = userRepository.findByEmail(loginDto.getEmail());

        if (user != null && user.getPassword().equals(loginDto.getPassword())) {
            return new UserDto(
                    user.getId(),
                    user.getEmail(),
                    user.getName(),
                    user.getRole(),
                    user.getDepartmentId()
            );
        }
        return null; // Başarısız giriş
    }
}

