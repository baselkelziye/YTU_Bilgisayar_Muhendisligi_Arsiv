package tr.edu.yildiz.payci.soner.model;

import java.util.ArrayList;
import java.util.Date;

import tr.edu.yildiz.payci.soner.R;

public class Person {
    private long id;
    private String firstName;
    private String lastName;
    private String username;
    private String password;
    private byte[] avatar;
    private String email;
    private String phone;
    private Date birthDate;

    public Person(String username, String password, byte[] avatar) {
        this.username = username;
        this.password = password;
        this.avatar = avatar;
    }

    public Person(long id, String firstName, String lastName, String email, String password, byte[] avatar, String phone, Date birthDate) {
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.username = email;
        this.email = email;
        this.password = password;
        this.avatar = avatar;
        this.phone = phone;
        this.birthDate = birthDate;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password)
    {
        this.password = password;
    }

    public byte[] getAvatar()
    {
        return avatar;
    }

    public void setAvatar(byte[] avatar)
    {
        this.avatar = avatar;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public Date getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(Date birthDate) {
        this.birthDate = birthDate;
    }

}
