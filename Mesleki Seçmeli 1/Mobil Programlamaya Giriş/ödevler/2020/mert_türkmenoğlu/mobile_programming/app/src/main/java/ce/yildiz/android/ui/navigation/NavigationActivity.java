package ce.yildiz.android.ui.navigation;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import ce.yildiz.android.R;
import ce.yildiz.android.databinding.ActivityNavigationBinding;
import ce.yildiz.android.ui.alarm.AlarmActivity;
import ce.yildiz.android.ui.communication.CommunicationMonitorActivity;
import ce.yildiz.android.ui.download.DownloadActivity;
import ce.yildiz.android.ui.email.EmailComposeActivity;
import ce.yildiz.android.ui.location.LocationActivity;
import ce.yildiz.android.ui.notes.NoteListActivity;
import ce.yildiz.android.ui.sensor.SensorActivity;
import ce.yildiz.android.ui.settings.SettingsActivity;
import ce.yildiz.android.ui.user.UserListActivity;
import ce.yildiz.android.util.Constants;
import ce.yildiz.android.util.SharedPreferencesUtil;

public class NavigationActivity extends AppCompatActivity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        if (SharedPreferencesUtil.getTheme().equals(Constants.AppThemes.DARK)) {
            setTheme(R.style.DarkTheme);
        } else {
            setTheme(R.style.AppTheme);
        }

        super.onCreate(savedInstanceState);
        ActivityNavigationBinding binding = ActivityNavigationBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        Intent intent = getIntent();

        if (intent == null) return;

        final String email = intent.getStringExtra("email");
        final String username = intent.getStringExtra("username");

        if (email == null || username == null) {
            Toast.makeText(NavigationActivity.this,
                    R.string.invalid_intent_error_message, Toast.LENGTH_SHORT).show();
            finish();
            return;
        }

        binding.navigationSendEmailBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent emailComposeIntent = new Intent(NavigationActivity.this,
                        EmailComposeActivity.class);
                emailComposeIntent.putExtra("email", email);
                startActivity(emailComposeIntent);
            }
        });

        binding.navigationListUsers.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent userListIntent = new Intent(NavigationActivity.this,
                        UserListActivity.class);
                startActivity(userListIntent);
            }
        });

        binding.navigationSettings.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent settingsIntent = new Intent(NavigationActivity.this,
                        SettingsActivity.class);

                settingsIntent.putExtra("username", username);
                settingsIntent.putExtra("email", email);

                startActivity(settingsIntent);
            }
        });

        binding.navigationNotes.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent noteListIntent = new Intent(NavigationActivity.this,
                        NoteListActivity.class);
                startActivity(noteListIntent);
            }
        });

        binding.navigationSensors.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent sensorListIntent = new Intent(NavigationActivity.this,
                        SensorActivity.class);
                startActivity(sensorListIntent);
            }
        });

        binding.navigationAlarm.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent alarmIntent = new Intent(NavigationActivity.this,
                        AlarmActivity.class);
                startActivity(alarmIntent);
            }
        });

        binding.navigationDownload.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent downloadIntent = new Intent(NavigationActivity.this,
                        DownloadActivity.class);
                startActivity(downloadIntent);
            }
        });

        binding.navigationLocation.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent locationIntent = new Intent(NavigationActivity.this,
                        LocationActivity.class);
                startActivity(locationIntent);
            }
        });

        binding.navigationMonitor.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent monitorIntent = new Intent(NavigationActivity.this,
                        CommunicationMonitorActivity.class);
                startActivity(monitorIntent);
            }
        });
    }
}
