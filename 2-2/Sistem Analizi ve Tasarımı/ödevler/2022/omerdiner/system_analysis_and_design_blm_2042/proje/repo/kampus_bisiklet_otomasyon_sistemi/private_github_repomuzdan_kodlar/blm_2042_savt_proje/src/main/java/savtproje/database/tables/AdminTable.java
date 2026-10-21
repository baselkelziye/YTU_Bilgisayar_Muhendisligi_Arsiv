package savtproje.database.tables;


import savtproje.database.AbstractTable;
import savtproje.database.entities.Admin;

public class AdminTable extends AbstractTable<Admin> {

    public static final String JSON_PATH = "database/admins.json";

    public AdminTable() {
        super(JSON_PATH);
    }


    public boolean isValidIDAndPassword(int adminID, String password) {
        Admin admin = find(x -> x.ID == adminID);
        if(admin == null) return false; // adminID doesnt exist
        return admin.password.equals(password);
    }

    public String getFullnameOf(int adminID) {
        return find(x -> x.ID == adminID).fullname;
    }
}

