package savtproje.database.tables;


import com.google.gson.Gson;
import savtproje.database.AbstractTable;
import savtproje.database.entities.*;

import java.util.LinkedList;


public class ReviewTable extends AbstractTable<Review> {

    public static final String JSON_PATH = "database/reviews.json";

    public ReviewTable() {
        super(JSON_PATH);
    }


    public LinkedList<Review> getAllReviewsOfBicycle(int bicycleID) {
        return findAll(review -> review.bicycleID == bicycleID);
    }

    public LinkedList<Review> getAllReviewsOfStudent(int studentID) {
        return findAll(review -> review.studentID == studentID);
    }

    public int getBicycleRatingOf(int bicycleID) {
        return find(x -> x.bicycleID == bicycleID).bicycleRating;
    }

    public int getDrivingRatingOf(int bicycleID) {
        return find(x -> x.bicycleID == bicycleID).drivingRating;
    }

    public int getOverallRatingOf(int bicycleID) {
        return find(x -> x.bicycleID == bicycleID).overallRating;
    }

    public void deleteReview(int reviewID) {
        Review review = find(r -> r.ID == reviewID);
        remove(review);
        save();
    }

}
