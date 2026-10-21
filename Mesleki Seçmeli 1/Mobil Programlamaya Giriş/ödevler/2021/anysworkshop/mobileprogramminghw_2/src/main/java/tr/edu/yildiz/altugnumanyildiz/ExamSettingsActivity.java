package tr.edu.yildiz.altugnumanyildiz;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

public class ExamSettingsActivity extends AppCompatActivity {

    EditText editDurationText;
    EditText editMarkText;
    SharedPreferences sharedPreferences;
    Button saveButton;
    int storedDuration;
    int storedMark;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_exam_settings);

        editDurationText = (EditText) findViewById(R.id.editTextNumberDecimal);
        editMarkText = (EditText) findViewById(R.id.editTextNumberDecimal2);
        saveButton = (Button) findViewById(R.id.saveSettings);

        sharedPreferences = this.getSharedPreferences("ExamSettingsActivity", Context.MODE_PRIVATE);

/*
        storedDuration = sharedPreferences.getInt("storedDuration",0);
        storedMark = sharedPreferences.getInt("storedMark",0);*/

        editDurationText.setText(String.valueOf(sharedPreferences.getInt("storedDuration",0)));
        editMarkText.setText(String.valueOf(sharedPreferences.getInt("storedMark",0)));

        saveButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                    storedDuration = Integer.parseInt(editDurationText.getText().toString());
                    storedMark = Integer.parseInt(editDurationText.getText().toString());

                    SharedPreferences.Editor editing = sharedPreferences.edit();

                    editing.putInt("storedDuration",storedDuration);
                    editing.putInt("storedMark",storedMark);
                    editing.commit();
                    editDurationText.setText("");
                    editMarkText.setText("");
            }
        });

        if(storedDuration == 0){
            editDurationText.setText("");
        } else{
            editDurationText.setText(storedDuration);
        }

        if(storedMark == 0){
            editMarkText.setText("");
        } else{
            editMarkText.setText(storedMark);
        }

    }


}