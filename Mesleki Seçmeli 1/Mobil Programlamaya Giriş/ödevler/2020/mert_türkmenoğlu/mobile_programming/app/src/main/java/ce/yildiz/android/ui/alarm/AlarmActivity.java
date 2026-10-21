package ce.yildiz.android.ui.alarm;

import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.text.DateFormat;
import java.util.Calendar;

import ce.yildiz.android.R;
import ce.yildiz.android.databinding.ActivityAlarmBinding;
import ce.yildiz.android.util.Constants;
import ce.yildiz.android.util.NotificationUtil;
import ce.yildiz.android.util.SharedPreferencesUtil;

public class AlarmActivity extends AppCompatActivity {
    public static final int REQUEST_CODE = 1;
    private static boolean isAlarmActive = false;
    private ActivityAlarmBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        if (SharedPreferencesUtil.getTheme().equals(Constants.AppThemes.DARK)) {
            setTheme(R.style.DarkTheme);
        } else {
            setTheme(R.style.AppTheme);
        }

        super.onCreate(savedInstanceState);
        binding = ActivityAlarmBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        binding.alarmAddAlarm.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                addButtonClick();
            }
        });

        binding.alarmCancelButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                cancelButtonClick();
            }
        });
    }

    private void addButtonClick() {
        if (isAlarmActive) {
            Toast.makeText(AlarmActivity.this,
                    R.string.alarm_add_error_message, Toast.LENGTH_SHORT).show();
            return;
        }

        final int hour = binding.alarmTimePicker.getHour();
        final int minute = binding.alarmTimePicker.getMinute();

        Calendar c = Calendar.getInstance();
        c.set(Calendar.HOUR_OF_DAY, hour);
        c.set(Calendar.MINUTE, minute);
        c.set(Calendar.SECOND, 0);

        isAlarmActive = NotificationUtil.startSound(AlarmActivity.this, c, REQUEST_CODE);

        if (isAlarmActive) {
            updateAlarmStatusText(c);
        } else {
            updateAlarmStatusText(getString(R.string.alarm_set_error_message));
        }
    }

    private void cancelButtonClick() {
        if (!isAlarmActive) {
            Toast.makeText(AlarmActivity.this, R.string.alarm_cancel_error_message, Toast.LENGTH_SHORT).show();
            return;
        }

        isAlarmActive = false;

        NotificationUtil.cancelSound(AlarmActivity.this, REQUEST_CODE);
        updateAlarmStatusText(getString(R.string.alarm_set_error_message));
    }

    private void updateAlarmStatusText(String status) {
        binding.alarmStatusText.setText(status);
    }

    private void updateAlarmStatusText(Calendar c) {
        String formattedTime = DateFormat.getTimeInstance(DateFormat.SHORT).format(c.getTime());
        String status = getString(R.string.alarm) + ":" + " " + formattedTime;

        binding.alarmStatusText.setText(status);
    }
}
