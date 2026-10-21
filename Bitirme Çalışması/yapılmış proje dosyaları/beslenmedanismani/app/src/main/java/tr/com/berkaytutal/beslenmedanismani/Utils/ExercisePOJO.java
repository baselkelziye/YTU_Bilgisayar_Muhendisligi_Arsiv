package tr.com.berkaytutal.beslenmedanismani.Utils;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.provider.MediaStore;

import java.io.Serializable;

public class ExercisePOJO extends CircleTekrarAbsPOJO implements Serializable {


    private String description;
    private String exerciseType;
    private int exercises_ID;
    private String name;
    private int orderExercise;
    private byte[] photo1;
    private byte[] photo2;
    private int restTime;
    private String title;
    private String video;

    private Integer circleID;
    private Integer circleCount;


    public ExercisePOJO(String description, String exerciseType, int exercises_ID, String name, int orderExercise, byte[] photo1, byte[] photo2, int restTime, String title, String video, Integer circleID, Integer circleCount) {
        this.description = description;
        this.exerciseType = exerciseType;
        this.exercises_ID = exercises_ID;
        this.name = name;
        this.orderExercise = orderExercise;
        this.photo1 = photo1;
        this.photo2 = photo2;
        this.restTime = restTime;
        this.title = title;
        this.video = video;
        this.circleID = circleID;
        this.circleCount = circleCount;
    }

    public Integer getCircleID() {
        return circleID;
    }

    public void setCircleID(Integer circleID) {
        this.circleID = circleID;
    }

    public Integer getCircleCount() {
        return circleCount;
    }

    public void setCircleCount(Integer circleCount) {
        this.circleCount = circleCount;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getExerciseType() {
        return exerciseType;
    }

    public void setExerciseType(String exerciseType) {
        this.exerciseType = exerciseType;
    }

    public int getExercises_ID() {
        return exercises_ID;
    }

    public void setExercises_ID(int exercises_ID) {
        this.exercises_ID = exercises_ID;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getOrderExercise() {
        return orderExercise;
    }

    public void setOrderExercise(int orderExercise) {
        this.orderExercise = orderExercise;
    }

    public Bitmap getPhoto1() {
        return BitmapFactory.decodeByteArray(photo1, 0, photo1.length);
    }

    public void setPhoto1(byte[] photo1) {
        this.photo1 = photo1;
    }

    public Bitmap getPhoto2() {
        return BitmapFactory.decodeByteArray(photo2, 0, photo2.length);
    }

    public void setPhoto2(byte[] photo2) {
        this.photo2 = photo2;
    }

    public int getRestTime() {
        return restTime;
    }

    public void setRestTime(int restTime) {
        this.restTime = restTime;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getVideo() {
        return video;
    }

    public void setVideo(String video) {
        this.video = video;
    }

    @Override
    public boolean isCircle() {
        return false;
    }

    @Override
    public boolean isTekrar() {
        return false;
    }

    @Override
    public int getOrder() {
        return getOrderExercise();
    }

    @Override
    public void setOrder(int order) {
        super.setOrder(order);
        setOrderExercise(order);
    }

    @Override
    public int getID(){
        return exercises_ID;
    }
}
