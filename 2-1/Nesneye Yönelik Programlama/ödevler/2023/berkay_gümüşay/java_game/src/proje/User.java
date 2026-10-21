package Proje;

import java.io.Serializable;

public class User implements Serializable {
	
	// KULLANICI BİLGİLERİNİ İÇEREN CLASS YAPISI
	
	private String name;// İSİM
	private String surname;// SOYİSİM
	private String password;// ŞİFRE
	private String userType;// PARENTCHİLD BİLGİSİ
	
	public User(String name, String surname, String password, String userType) {
		super();
		this.name = name;
		this.surname = surname;
		this.password = password;
		this.userType = userType;
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

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public String getUserType() {
		return userType;
	}

	public void setUserType(String userType) {
		this.userType = userType;
	}
	
	
}
