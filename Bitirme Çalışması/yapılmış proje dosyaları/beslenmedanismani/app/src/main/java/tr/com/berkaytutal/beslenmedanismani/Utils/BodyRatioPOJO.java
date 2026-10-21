package tr.com.berkaytutal.beslenmedanismani.Utils;

import java.io.Serializable;

/**
 * Created by berka on 13.06.2017.
 */

public class BodyRatioPOJO implements Serializable {

    private String date;
    private float fatRate;
    private float muscleRate;
    private int tall;
    private int userID;
    private float waterRate;
    private float weight;

    public BodyRatioPOJO(String date, float fatRate, float muscleRate, int tall, int userID, float waterRate, float weight) {
        this.date = date;
        this.fatRate = fatRate;
        this.muscleRate = muscleRate;
        this.tall = tall;
        this.userID = userID;
        this.waterRate = waterRate;
        this.weight = weight;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public float getFatRate() {
        return fatRate;
    }

    public void setFatRate(float fatRate) {
        this.fatRate = fatRate;
    }

    public float getMuscleRate() {
        return muscleRate;
    }

    public void setMuscleRate(float muscleRate) {
        this.muscleRate = muscleRate;
    }

    public int getTall() {
        return tall;
    }

    public void setTall(int tall) {
        this.tall = tall;
    }

    public int getUserID() {
        return userID;
    }

    public void setUserID(int userID) {
        this.userID = userID;
    }

    public float getWaterRate() {
        return waterRate;
    }

    public void setWaterRate(float waterRate) {
        this.waterRate = waterRate;
    }

    public float getWeight() {
        return weight;
    }

    public void setWeight(float weight) {
        this.weight = weight;
    }
}
