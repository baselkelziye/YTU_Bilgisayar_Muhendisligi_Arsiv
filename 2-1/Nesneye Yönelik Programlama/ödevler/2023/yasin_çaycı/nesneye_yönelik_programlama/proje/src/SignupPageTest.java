package a;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.io.File;
import java.util.ArrayList;

import org.junit.jupiter.api.Test;

public class SignupPageTest {

    @Test
    public void testIsExistingUser() {
        SignupPage signupPage = new SignupPage();
        User user = new User("testuser", "password", null);
        ArrayList<User> userList = new ArrayList<>();
        userList.add(user);
        boolean result = signupPage.isExistingUser(user, userList);
        assertTrue(result);
    }

    @Test
    public void testIsExistingAdmin() {
        SignupPage signupPage = new SignupPage();
        Admin admin = new Admin("testadmin", "password");
        ArrayList<Admin> adminList = new ArrayList<>();
        adminList.add(admin);
        boolean result = signupPage.isExistingAdmin(admin, adminList);
        assertTrue(result);
    }

    @Test
    public void testAdminData() {
    	String fileName = "admins.dat";
    	File file = new File(fileName);
        SignupPage signupPage = new SignupPage();
        ArrayList<Admin> adminList = new ArrayList<>();
        ArrayList<User> userList = new ArrayList<>();
        signupPage.loadData(file, adminList, userList);
        assertFalse(adminList.isEmpty());
    }
    
    @Test
    public void testUserData() {
    	String fileName = "users.dat";
    	File file = new File(fileName);
        SignupPage signupPage = new SignupPage();
        ArrayList<Admin> adminList = new ArrayList<>();
        ArrayList<User> userList = new ArrayList<>();
        signupPage.loadData(file, adminList, userList);
        assertFalse(userList.isEmpty());
    }

    @Test
    public void testSaveData() {
        SignupPage signupPage = new SignupPage();
        File file = new File("test.dat");
        ArrayList<String> dataList = new ArrayList<>();
        dataList.add("data1");
        dataList.add("data2");
        signupPage.saveData(file, dataList, "test.dat");
        assertTrue(file.exists());
    }
    
    @Test
    public void testJumpToLogin() {
        SignupPage signupPage = new SignupPage();      
        LoginPage loginPage = new LoginPage();  
        signupPage.jumpToLogin(loginPage);      
        assertFalse(signupPage.isVisible());
        assertTrue(loginPage.isVisible());
    }

}
