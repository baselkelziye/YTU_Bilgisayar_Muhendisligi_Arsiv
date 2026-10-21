package savtproje.database.entities;

import java.util.Date;


public class Rent {
    public final int ID, studentID, bicycleID, totalTimeInMinutes;
    public final Date date; // renting'in başladığı zamanı gösterir

    public Rent(int ID, int studentID, int bicycleID, int totalTimeInMinutes) {
        this.totalTimeInMinutes = totalTimeInMinutes;
        this.studentID = studentID;
        this.bicycleID = bicycleID;
        this.date = new Date();
        this.ID = ID;
    }
}