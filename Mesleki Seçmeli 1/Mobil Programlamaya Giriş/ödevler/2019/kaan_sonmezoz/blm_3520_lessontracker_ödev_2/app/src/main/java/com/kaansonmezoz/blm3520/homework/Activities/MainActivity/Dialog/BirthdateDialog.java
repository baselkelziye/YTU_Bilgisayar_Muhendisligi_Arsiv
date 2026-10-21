package com.kaansonmezoz.blm3520.homework.Activities.MainActivity.Dialog;

import android.app.Activity;
import android.app.DatePickerDialog;
import android.view.View;
import android.widget.DatePicker;
import android.widget.EditText;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Locale;

public class BirthdateDialog{
    public void createDatePicker(final Activity activity, final EditText dateText){
        final Calendar calendar = Calendar.getInstance();

        final DatePickerDialog.OnDateSetListener datePicker = new DatePickerDialog.OnDateSetListener(){
            @Override
            public void onDateSet(DatePicker view, int year, int month, int day){
                calendar.set(Calendar.YEAR, year);
                calendar.set(Calendar.MONTH, month);
                calendar.set(Calendar.YEAR, year);

                String dateFormat = "dd MMMM yyyy";
                SimpleDateFormat simpleDateFormat = new SimpleDateFormat(dateFormat, Locale.US);

                dateText.setText(simpleDateFormat.format(calendar.getTime()));
            }
        };

        dateText.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                new DatePickerDialog(activity, datePicker,
                        calendar.get(Calendar.YEAR),
                        calendar.get(Calendar.MONTH),
                        calendar.get(Calendar.DAY_OF_MONTH)
                ).show();
            }
        });
    }
}
