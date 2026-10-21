package a;

import java.io.Serializable;

public abstract class Person implements Serializable {

	private static final long serialVersionUID = 1L;
	
	private String username;
	private String password;
	public Person(String username, String password) {
		this.username = username;
		this.password = password;
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
	
	
}
