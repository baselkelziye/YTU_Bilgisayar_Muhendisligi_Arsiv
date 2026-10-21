package com.example.must.mobilehomework.model;

import java.util.ArrayList;
import java.util.List;

public class DateSelection {
    private List<String> monthList;
    private List<String> dayList;

    public DateSelection(){
        monthList = new ArrayList<>();
        monthList.add("Ocak");
        monthList.add("Şubat");
        monthList.add("Mart");
        monthList.add("Nisan");
        monthList.add("Mayıs");
        monthList.add("Haziran");
        monthList.add("Temmuz");
        monthList.add("Ağustos");
        monthList.add("Eylül");
        monthList.add("Ekim");
        monthList.add("Kasım");
        monthList.add("Aralık");

        dayList = new ArrayList<>();
        for(int i=1; i<31; i++){
            dayList.add(""+i);
        }
    }

    public List<String> getMonthList(){
        return monthList;
    }

    public List<String> getDayList(){
        return dayList;
    }

    //String olarak aldığı ayı int tipinde döndürür
    public int getMonthNumber(String month){
        int number = 0;

        switch (month){
            case "Ocak": number = 1; break;
            case "Şubat": number = 2; break;
            case "Mart": number = 3; break;
            case "Nisan": number = 4; break;
            case "Mayıs": number = 5; break;
            case "Haziran": number = 6; break;
            case "Temmuz": number = 7; break;
            case "Ağustos": number = 8; break;
            case "Eylül": number = 9; break;
            case "Ekim": number = 10; break;
            case "Kasım": number = 11; break;
            case "Aralık": number = 12; break;
        }

        return number;
    }
}
