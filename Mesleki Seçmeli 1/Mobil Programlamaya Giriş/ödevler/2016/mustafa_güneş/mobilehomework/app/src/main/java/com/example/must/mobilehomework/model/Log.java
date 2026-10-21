package com.example.must.mobilehomework.model;

import java.io.Serializable;

/**
 * Created by must on 01.05.2016.
 */
public class Log implements Serializable {
    private String pickupCity;
    private String dropoffCity;
    private String userName;
    private int carId;
    private RentDate date;

    public Log() {
        //dosyaya aynen yazdır
    }

    public RentDate getDate() {
        return date;
    }

    public void setDate(RentDate date) {
        this.date = date;
    }

    public String getDropoffCity() {
        return dropoffCity;
    }

    public void setDropoffCity(String dropoffCity) {
        this.dropoffCity = dropoffCity;
    }

    public String getPickupCity() {
        return pickupCity;
    }

    public void setPickupCity(String pickupCity) {
        this.pickupCity = pickupCity;
    }

    public int getCarId() {
        return carId;
    }

    public void setCarId(int carId) {
        this.carId = carId;
    }

    public String getUser() {
        return userName;
    }

    public void setUser(String userName) {
        this.userName = userName;
    }

}
