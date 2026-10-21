package mobilprogramlama.ders.berkay.hm1_quiz.activity;

import android.app.Activity;
import android.app.DialogFragment;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import mobilprogramlama.ders.berkay.hm1_quiz.R;
import mobilprogramlama.ders.berkay.hm1_quiz.database.DatabaseContract;
import mobilprogramlama.ders.berkay.hm1_quiz.fragment.TimePickerFragment;

public class RegisterActivity extends Activity {

    private EditText mUsername;
    private Button mPickBirthday;
    private TextView mDateDisplay;
    private String pickedBirthday;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        mUsername = (EditText) findViewById(R.id.edtText_registerActivity_name);
        mPickBirthday = (Button) findViewById(R.id.btn_registerActivity_pickBirthday);
        mDateDisplay = (TextView) findViewById(R.id.txtView_registerActivity_birthday);
    }

    @Override
    protected void onStart() {
        super.onStart();

        // Set the current date to the screen.
        Calendar cal = Calendar.getInstance();
        cal.setTime(new Date());
        SetDate(cal);
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);

        // Save the birthday information to Bundle using.
        outState.putString(DatabaseContract.PlayersContract.COLUMN_NAME_PLAYER_BIRTHDAY, pickedBirthday);
    }

    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);

        // Saved instance is restored in onRestoreInstanceState because it is called after onStart() method.
        pickedBirthday = savedInstanceState.getString(DatabaseContract.PlayersContract.COLUMN_NAME_PLAYER_BIRTHDAY);
        mDateDisplay.setText(pickedBirthday);
    }

    public void btn_registerActivity_pickBirthday_onClick(View view){
        DialogFragment newFragment = new TimePickerFragment();
        newFragment.show(getFragmentManager(), "timePicker");
    }

    public void btn_registerActivity_start_onClick(View view) {

        if(!mUsername.getText().toString().isEmpty()){
            Intent menuIntent = new Intent(this, MenuActivity.class);

            String name = mUsername.getText().toString();

            menuIntent.putExtra(DatabaseContract.PlayersContract.COLUMN_NAME_PLAYER_NAME, name);
            menuIntent.putExtra(DatabaseContract.PlayersContract.COLUMN_NAME_PLAYER_BIRTHDAY, pickedBirthday);

            // Clear the Activity from Activity stack.
            menuIntent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_NEW_TASK);
            startActivity(menuIntent);
            this.finish();
        } else{
            Toast.makeText(this, getString(R.string.toast_enter_name), Toast.LENGTH_SHORT).show();
        }

    }

    /**
     * Sets the date on the screen and the {@link RegisterActivity#pickedBirthday} string.
     * @param calendar {@link Calendar} object that holds the date information.
     */
    public void SetDate(Calendar calendar){
        SimpleDateFormat format1 = new SimpleDateFormat("dd-MM-yyyy");
        String formatted = format1.format(calendar.getTime());
        mDateDisplay.setText(formatted);
        pickedBirthday = formatted;
    }

}
