package com.example.must.mobilehomework.model;

/**
 * Created by must on 01.05.2016.
 */
public class RentDate {
    private String pickupMonth;
    private int pickupDay;
    private String dropoffMonth;
    private int dropoffDay;

    public RentDate(){

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

}
