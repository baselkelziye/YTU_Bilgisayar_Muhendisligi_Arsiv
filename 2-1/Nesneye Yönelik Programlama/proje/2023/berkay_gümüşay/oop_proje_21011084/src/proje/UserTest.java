package Proje;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

public class UserTest {

	private User user;
	//USER GETTER-SETTER TESTLERİ
    //USER GETTER-SETTER TESTLERİ
    //USER GETTER-SETTER TESTLERİ
    //USER GETTER-SETTER TESTLERİ
    @Before
    public void setUp() {
        user = new User("John", "Doe", "password123", "admin");
    }

    @Test
    public void testGetName() {
        assertEquals("John", user.getName());
    }

    @Test
    public void testSetName() {
        user.setName("Jane");
        assertEquals("Jane", user.getName());
    }

    @Test
    public void testGetSurname() {
        assertEquals("Doe", user.getSurname());
    }

    @Test
    public void testSetSurname() {
        user.setSurname("Smith");
        assertEquals("Smith", user.getSurname());
    }

    @Test
    public void testGetPassword() {
        assertEquals("password123", user.getPassword());
    }

    @Test
    public void testSetPassword() {
        user.setPassword("newpassword");
        assertEquals("newpassword", user.getPassword());
    }

    @Test
    public void testGetUserType() {
        assertEquals("admin", user.getUserType());
    }

    @Test
    public void testSetUserType() {
        user.setUserType("guest");
        assertEquals("guest", user.getUserType());
    }
}