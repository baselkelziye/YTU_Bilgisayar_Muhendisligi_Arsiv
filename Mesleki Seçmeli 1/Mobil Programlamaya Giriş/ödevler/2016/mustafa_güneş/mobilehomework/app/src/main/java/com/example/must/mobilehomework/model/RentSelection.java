package com.example.must.mobilehomework.model;

import java.io.Serializable;

/**
 * Created by must on 01.05.2016.
 */
public class RentSelection implements Serializable{
    private String pickupCity;
    private String dropoffCity;
    private String pickupMonth;
    private int pickupDay;
    private String dropoffMonth;
    private String carType;

    public RentSelection(){

    }

    public String getCarType() {
        return carType;
    }

    public void setCarType(String carType) {
        this.carType = carType;
    }

    public int getDropoffDay() {
        return dropoffDay;
    }

    public void setDropoffDay(int dropoffDay) {
        this.dropoffDay = dropoffDay;
    }

    public String getDropoffMonth() {
        return dropoffMonth;
    }

    public void setDropoffMonth(String dropoffMonth) {
        this.dropoffMonth = dropoffMonth;
    }

    public int getPickupDay() {
        return pickupDay;
    }

    public void setPickupDay(int pickupDay) {
        this.pickupDay = pickupDay;
    }

    public String getPickupMonth() {
        return pickupMonth;
    }

    public void setPickupMonth(String pickupMonth) {
        this.pickupMonth = pickupMonth;
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

    private int dropoffDay;

}
