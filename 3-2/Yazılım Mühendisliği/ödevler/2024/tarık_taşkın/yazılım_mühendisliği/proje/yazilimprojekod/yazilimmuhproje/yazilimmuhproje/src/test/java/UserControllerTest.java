import Controller.ExpenseController;
import Controller.UserController;
import DTO.UserDto;
import DTO.UserLoginDto;
import Service.IUserService;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.util.*;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;


public class UserControllerTest {
    private IUserService userService;
    private UserController userController;

    @BeforeEach
    public void setUp() {
        userService = mock(IUserService.class);
        userController = new UserController(userService);
    }

    // UserControllerTest.java
    @Test
    public void testLogin_ReturnsUserDto() {
        String email = "test@example.com";
        String password = "pass123";
        UserDto userDto = new UserDto();  // dummy object

        when(userService.login(any(UserLoginDto.class))).thenReturn(userDto);

        UserDto result = userController.login(email, password);

        assertNotNull(result);
        verify(userService).login(any(UserLoginDto.class));
    }

}
