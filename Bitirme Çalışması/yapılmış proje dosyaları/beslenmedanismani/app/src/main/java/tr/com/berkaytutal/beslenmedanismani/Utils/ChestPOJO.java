package tr.com.berkaytutal.beslenmedanismani.Utils;

import android.graphics.Bitmap;
import android.provider.MediaStore;

import java.io.Serializable;

public class ChestPOJO extends ExercisePOJO implements Serializable {
    private int agirlik;
    private int setSayisi;
    private int tekrarSayisi;

    public ChestPOJO(String description, String exerciseType, int exercises_ID, String name, int orderExercise, byte[] photo1, byte[] photo2, int restTime, String title, String video, int agirlik, int setSayisi, int tekrarSayisi, Integer circleID, Integer circleCount) {
        super(description, exerciseType, exercises_ID, name, orderExercise, photo1, photo2, restTime, title, video, circleID, circleCount);
        this.agirlik = agirlik;
        this.setSayisi = setSayisi;
        this.tekrarSayisi = tekrarSayisi;
    }

    public int getAgirlik() {
        return agirlik;
    }

    public void setAgirlik(int agirlik) {
        this.agirlik = agirlik;
    }

    public int getSetSayisi() {
        return setSayisi;
    }

    public void setSetSayisi(int setSayisi) {
        this.setSayisi = setSayisi;
    }

    public int getTekrarSayisi() {
        return tekrarSayisi;
    }

    public void setTekrarSayisi(int tekrarSayisi) {
        this.tekrarSayisi = tekrarSayisi;
    }
}
