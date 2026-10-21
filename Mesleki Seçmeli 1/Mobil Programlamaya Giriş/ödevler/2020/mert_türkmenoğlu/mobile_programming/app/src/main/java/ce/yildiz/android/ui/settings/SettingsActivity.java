package ce.yildiz.android.ui.settings;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import java.util.Arrays;
import java.util.List;

import ce.yildiz.android.R;
import ce.yildiz.android.databinding.ActivitySettingsBinding;
import ce.yildiz.android.ui.navigation.NavigationActivity;
import ce.yildiz.android.util.Constants;
import ce.yildiz.android.util.SharedPreferencesUtil;

public class SettingsActivity extends AppCompatActivity {
    private ActivitySettingsBinding binding;
    private SharedPreferences sharedPreferences;
    private String mUsername;
    private String mEmail;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        if (SharedPreferencesUtil.getTheme().equals(Constants.AppThemes.DARK)) {
            setTheme(R.style.DarkTheme);
        } else {
            setTheme(R.style.AppTheme);
        }

        super.onCreate(savedInstanceState);
        binding = ActivitySettingsBinding.inflate(getLayoutInflater());
        View root = binding.getRoot();
        setContentView(root);

        Intent comingIntent = getIntent();

        if (comingIntent == null) return;

        // Email is needed to return to NavigationActivity
        // after saving settings
        mUsername = comingIntent.getStringExtra("username");
        mEmail = comingIntent.getStringExtra("email");

        if (mUsername == null || mEmail == null) {
            Toast.makeText(this,
                    R.string.invalid_intent_error_message, Toast.LENGTH_SHORT).show();
            finish();
            return;
        }

        binding.settingsUsernameTextView.setText(mUsername);

        ArrayAdapter<CharSequence> genderAdapter = ArrayAdapter.createFromResource(
                this,
                R.array.gender_array,
                android.R.layout.simple_spinner_item
        );

        genderAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        binding.settingsGenderSpinner.setAdapter(genderAdapter);

        binding.settingsAgePicker.setMinValue(18);
        binding.settingsAgePicker.setMaxValue(120);
        binding.settingsAgePicker.setWrapSelectorWheel(true);

        sharedPreferences = getApplicationContext()
                .getSharedPreferences(mUsername, Context.MODE_PRIVATE);

        final String gender = sharedPreferences.getString(Constants.SettingsFields.GENDER,
                Constants.GenderOptions.NON_BINARY);

        final int height = sharedPreferences.getInt(Constants.SettingsFields.HEIGHT,
                Constants.DEFAULT_HEIGHT);

        final int weight = sharedPreferences.getInt(Constants.SettingsFields.WEIGHT,
                Constants.DEFAULT_WEIGHT);

        final int age = sharedPreferences.getInt(Constants.SettingsFields.AGE,
                Constants.DEFAULT_AGE);

        final String theme = sharedPreferences.getString(Constants.SettingsFields.THEME,
                Constants.AppThemes.LIGHT);

        List<String> genderChoices = Arrays.asList(
                getResources().getStringArray(R.array.gender_array)
        );

        binding.settingsGenderSpinner.setSelection(genderChoices.indexOf(gender));
        binding.settingsHeightEt.setText(String.valueOf(height));
        binding.settingsWeightEt.setText(String.valueOf(weight));
        binding.settingsAgePicker.setValue(age);

        if (theme.equals(Constants.AppThemes.DARK)) {
            binding.settingDarkRadioBtn.toggle();
        } else {
            binding.settingsLightRadioBtn.toggle();
        }

        binding.settingsSaveBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                save();
            }
        });
    }

    private void save() {
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.clear();

        editor.putString(Constants.SettingsFields.GENDER,
                (String) binding.settingsGenderSpinner.getSelectedItem());

        editor.putInt(Constants.SettingsFields.HEIGHT,
                Integer.parseInt(binding.settingsHeightEt.getText().toString()));

        editor.putInt(Constants.SettingsFields.WEIGHT,
                Integer.parseInt(binding.settingsWeightEt.getText().toString()));

        editor.putInt(Constants.SettingsFields.AGE, binding.settingsAgePicker.getValue());

        if (binding.settingDarkRadioBtn.isChecked()) {
            editor.putString(Constants.SettingsFields.THEME, Constants.AppThemes.DARK);
            SharedPreferencesUtil.saveApplicationTheme(SettingsActivity.this, mUsername, Constants.AppThemes.DARK);
        } else {
            editor.putString(Constants.SettingsFields.THEME, Constants.AppThemes.LIGHT);
            SharedPreferencesUtil.saveApplicationTheme(SettingsActivity.this, mUsername, Constants.AppThemes.LIGHT);
        }

        editor.apply();


        Intent navigationIntent = new Intent(SettingsActivity.this,
                NavigationActivity.class);

        navigationIntent.putExtra("username", mUsername);
        navigationIntent.putExtra("email", mEmail);
        navigationIntent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TASK);

        startActivity(navigationIntent);
        finish();
    }
}
