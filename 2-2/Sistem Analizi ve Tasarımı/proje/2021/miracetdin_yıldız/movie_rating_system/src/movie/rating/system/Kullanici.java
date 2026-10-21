/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package movie.rating.system;

/**
 *
 * @author bilal
 */
public class Kullanici {
    private String username;
    private String password;
    private String name;
    private String surname;
    private String gender;

    public Kullanici(String username, String password, String name, String surname, String gender) {
        this.username = username;
        this.password = password;
        this.name = name;
        this.surname = surname;
        if(gender.equals("M")){
            this.gender = "Erkek";
        }else{
            this.gender = "Kadın";
        }
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

    public void setPassword(String password) {
        this.password = password;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }
    
    
}
