package tr.com.berkaytutal.beslenmedanismani.Utils;

import android.graphics.Bitmap;
import android.provider.MediaStore;

import java.io.Serializable;

public class CardioPOJO extends ExercisePOJO implements Serializable {
    private int exerciseTime;

    public CardioPOJO(String description, String exerciseType, int exercises_ID, String name, int orderExercise, byte[] photo1, byte[] photo2, int restTime, String title, String video, int exerciseTime, Integer circleID, Integer circleCount) {
        super(description, exerciseType, exercises_ID, name, orderExercise, photo1, photo2, restTime, title, video, circleID, circleCount);
        this.exerciseTime = exerciseTime;
    }

    public int getExerciseTime() {
        return exerciseTime;
    }

    public void setExerciseTime(int exerciseTime) {
        this.exerciseTime = exerciseTime;
    }
}
