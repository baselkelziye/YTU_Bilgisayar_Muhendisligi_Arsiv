package a;

import java.io.Serializable;

public class Admin extends Person implements Serializable{

	private static final long serialVersionUID = 1L;
	private static int ID = 2023670001;
	public Admin(String username, String password) {
        super(username,password);
        ID++;
    }
	public static int getID() {
		return ID;
	}
	
}
