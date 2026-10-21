package savtproje.database.entities;

import java.util.Date;


public class Review {
    public final int ID, studentID, bicycleID, bicycleRating, drivingRating, overallRating;
    public final Date date;

    public Review(int ID, int studentID, int bicycleID, int bicycleRating, int drivingRating, int overallRating) {
        this.bicycleRating = bicycleRating;
        this.drivingRating = drivingRating;
        this.overallRating = overallRating;
        this.studentID = studentID;
        this.bicycleID = bicycleID;
        this.date = new Date();
        this.ID = ID;
    }
}

