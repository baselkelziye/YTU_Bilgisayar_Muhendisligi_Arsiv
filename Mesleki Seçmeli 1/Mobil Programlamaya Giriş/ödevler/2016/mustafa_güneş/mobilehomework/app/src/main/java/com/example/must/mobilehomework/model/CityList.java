package com.example.must.mobilehomework.model;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by must on 01.05.2016.
 */
public class CityList {
    private List<String> cityList;

    public CityList(){
        cityList = new ArrayList<>();
        cityList.add("İstanbul");
        cityList.add("Ankara");
        cityList.add("İzmir");
        cityList.add("Bursa");
        cityList.add("Kırklareli");
        cityList.add("Edirne");
        cityList.add("Trabzon");
        cityList.add("Sivas");
    }

    public List<String> getList(){
        return cityList;
    }
}
