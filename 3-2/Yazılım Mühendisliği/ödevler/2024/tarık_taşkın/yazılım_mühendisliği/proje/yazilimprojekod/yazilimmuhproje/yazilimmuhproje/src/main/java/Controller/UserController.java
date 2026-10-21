package Controller;


import DTO.UserDto;
import DTO.UserLoginDto;
import Service.IUserService;


public class UserController{
    private final IUserService userService;

    public UserController(IUserService userService) {
        this.userService = userService;
    }

    public UserDto login(String email, String password) {
        UserLoginDto loginDto = new UserLoginDto(email, password);
        return userService.login(loginDto);
    }
}

