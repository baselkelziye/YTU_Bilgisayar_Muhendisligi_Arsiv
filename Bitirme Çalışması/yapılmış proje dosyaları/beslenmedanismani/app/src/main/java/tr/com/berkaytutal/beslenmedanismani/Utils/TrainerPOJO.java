package tr.com.berkaytutal.beslenmedanismani.Utils;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.R;

/**
 * Created by berka on 21.05.2017.
 */

public class TrainerPOJO {
    private String name;
    private String surname;
    private String sex;
    private Bitmap photo;
    private int userID;
    private String birthday;
    private String bio;
    private String intro;
    private ArrayList<CertificatePOJO> certificates;
    private boolean isBanned;


    public TrainerPOJO(String name, String surname, String sex, Bitmap photo, int userID, String birthday, String bio, String intro, ArrayList<CertificatePOJO> certificates,boolean isBanned)
    {
        this.name = name;
        this.surname = surname;
        this.sex = sex;
        this.photo = photo;
        this.userID = userID;
        this.birthday = birthday;
        this.certificates = certificates;
        this.bio = bio;
        this.intro = intro;
        this.isBanned = isBanned;
    }


    public boolean isBanned() {
        return isBanned;
    }

    public void setBanned(boolean banned) {
        isBanned = banned;
    }

    public int getCertificateCount(){
        return certificates.size();
    }

    public String getBio() {
        return bio;
    }

    public void setBio(String bio) {
        this.bio = bio;
    }

    public String getIntro() {
        return intro;
    }

    public void setIntro(String intro) {
        this.intro = intro;
    }

    public ArrayList<CertificatePOJO> getCertificates() {
        return certificates;
    }

    public void setCertificates(ArrayList<CertificatePOJO> certificates) {
        this.certificates = certificates;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public Bitmap getPhoto() {


        return photo;
    }

    public void setPhoto(Bitmap photo) {
        this.photo = photo;
    }

    public int getUserID() {
        return userID;
    }

    public void setUserID(int userID) {
        this.userID = userID;
    }

    public String getBirthday() {
        return birthday;
    }

    public void setBirthday(String birthday) {
        this.birthday = birthday;
    }
}
