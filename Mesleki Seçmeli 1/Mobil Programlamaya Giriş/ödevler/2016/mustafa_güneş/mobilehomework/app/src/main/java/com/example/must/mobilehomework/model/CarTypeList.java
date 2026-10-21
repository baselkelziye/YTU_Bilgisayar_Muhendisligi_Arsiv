package com.example.must.mobilehomework.model;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by must on 01.05.2016.
 */
public class CarTypeList {
    private List<String> carTypeList;

    public CarTypeList(){
        carTypeList = new ArrayList<>();
        carTypeList.add("Ekonomik");
        carTypeList.add("Standart");
        carTypeList.add("Lüks");
    }

    public List<String> getCarTypeList(){
        return carTypeList;
    }
}
