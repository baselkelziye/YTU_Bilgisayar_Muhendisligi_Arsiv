package com.kaansonmezoz.blm3520.notebook.Database.Converter;

import android.arch.persistence.room.TypeConverter;

import java.util.Date;

public class DateConverter {
    @TypeConverter
    public static Date toDate(Long dateLong){
        return dateLong == null ? new Date(): new Date(dateLong);
    }

    @TypeConverter
    public static Long fromDate(Date date){
        return date == null ? new Date().getTime() : date.getTime();
    }
}
