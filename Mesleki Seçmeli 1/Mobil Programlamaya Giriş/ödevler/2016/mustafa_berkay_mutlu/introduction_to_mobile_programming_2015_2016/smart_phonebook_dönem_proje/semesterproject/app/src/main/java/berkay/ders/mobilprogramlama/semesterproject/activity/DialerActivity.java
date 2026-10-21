package berkay.ders.mobilprogramlama.semesterproject.activity;

import android.Manifest;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.ActivityCompat;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import berkay.ders.mobilprogramlama.semesterproject.R;
import mehdi.sakout.fancybuttons.FancyButton;

public class DialerActivity extends Activity {
    TextView phoneNumber;
    FancyButton button1, button2, button3, button4, button5, button6,
            button7, button8, button9, button0, buttonAsterisk, buttonSharp;

    View.OnClickListener dialerButtonsOnCLick;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dialer);

        phoneNumber = (TextView) findViewById(R.id.editText_dialerActivity_phoneNumber);
        button1 = (FancyButton) findViewById(R.id.button_dialerActivity_dialButton1);
        button2 = (FancyButton) findViewById(R.id.button_dialerActivity_dialButton2);
        button3 = (FancyButton) findViewById(R.id.button_dialerActivity_dialButton3);
        button4 = (FancyButton) findViewById(R.id.button_dialerActivity_dialButton4);
        button5 = (FancyButton) findViewById(R.id.button_dialerActivity_dialButton5);
        button6 = (FancyButton) findViewById(R.id.button_dialerActivity_dialButton6);
        button7 = (FancyButton) findViewById(R.id.button_dialerActivity_dialButton7);
        button8 = (FancyButton) findViewById(R.id.button_dialerActivity_dialButton8);
        button9 = (FancyButton) findViewById(R.id.button_dialerActivity_dialButton9);
        button0 = (FancyButton) findViewById(R.id.button_dialerActivity_dialButton0);
        buttonAsterisk = (FancyButton) findViewById(R.id.button_dialerActivity_dialButtonAsterisk);
        buttonSharp = (FancyButton) findViewById(R.id.button_dialerActivity_dialButtonSharp);

        dialerButtonsOnCLick = new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                FancyButton button = (FancyButton) v;

                phoneNumber.setText(String.format("%s%s", phoneNumber.getText().toString(), button.getText().toString()));

            }
        };

        Button button_dialerActivity_clear = (Button) findViewById(R.id.button_dialerActivity_clear);
        button_dialerActivity_clear.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                phoneNumber.setText("");
                return true;
            }
        });

        button1.setOnClickListener(dialerButtonsOnCLick);
        button2.setOnClickListener(dialerButtonsOnCLick);
        button3.setOnClickListener(dialerButtonsOnCLick);
        button4.setOnClickListener(dialerButtonsOnCLick);
        button5.setOnClickListener(dialerButtonsOnCLick);
        button6.setOnClickListener(dialerButtonsOnCLick);
        button7.setOnClickListener(dialerButtonsOnCLick);
        button8.setOnClickListener(dialerButtonsOnCLick);
        button9.setOnClickListener(dialerButtonsOnCLick);
        button0.setOnClickListener(dialerButtonsOnCLick);
        buttonAsterisk.setOnClickListener(dialerButtonsOnCLick);
        buttonSharp.setOnClickListener(dialerButtonsOnCLick);

    }

    public void button_dialerActivity_clear_onClick(View view) {
        String previous = phoneNumber.getText().toString();
        phoneNumber.setText(previous.substring(0, previous.length()-1));
    }

    public void button_dialerActivity_call_onClick(View view) {
        try {
            Intent dial = new Intent(Intent.ACTION_CALL, Uri.parse("tel:" + phoneNumber.getText().toString().trim()));
            startActivity(dial);
        }catch (Exception e){
            e.printStackTrace();
            Toast.makeText(getApplicationContext(), getString(R.string.toast_call_failed), Toast.LENGTH_SHORT).show();
        }
    }

}
