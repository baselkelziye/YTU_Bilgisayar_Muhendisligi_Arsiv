package com.example.must.mobilehomework.model;

import java.io.Serializable;

/**
 * Created by must on 01.05.2016.
 */
public class Car implements Serializable{
    private static int TOTAL = 0;
    private int id;
    private String model;
    private String locationCity;
    private String type;
    private int price;

    public Car(){
        id = ++TOTAL;
        price = (id * 10) % 7;
    }

    public Car(int id, String model, String city, String type){
        this.id = id;
        this.model = model;
        this.locationCity = city;
        this.type = type;
        price = (id * 10) % 7;
    }

    public void setPrice(int price){
        this.price = price;
    }

    public int getPrice(){
        return price;
    }

    public int getId(){
        return id;
    }

    public void setId(int id){
        this.id = id;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getLocationCity() {
        return locationCity;
    }

    public void setLocationCity(String locationCity) {
        this.locationCity = locationCity;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

}
