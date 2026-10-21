package savtproje.database.entities;


public class Admin {
    public final int ID;
    public final String fullname, password;

    public Admin(int ID, String fullname, String password) {
        this.fullname = fullname;
        this.password = password;
        this.ID = ID;
    }
}

