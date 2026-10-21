package com.airline.models;

public class Seat {
    public enum SeatClass {
        ECONOMY, BUSINESS
    }

    private String seatNum;
    private SeatClass seatClass;
    private double price;
    private boolean isReserved;

    public Seat(String seatNum, SeatClass seatClass, double price) {
        this.seatNum = seatNum;
        this.seatClass = seatClass;
        this.price = price;
        this.isReserved = false;
    }

    public String getSeatNum() {
        return seatNum;
    }

    public SeatClass getSeatClass() {
        return seatClass;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public boolean isReserved() {
        return isReserved;
    }

    public void setReserved(boolean reserved) {
        isReserved = reserved;
    }

    @Override
    public String toString() {
        return "Seat{" + "seatNum='" + seatNum + '\'' + ", seatClass=" + seatClass + ", price=" + price + ", isReserved=" + isReserved + '}';
    }
}
