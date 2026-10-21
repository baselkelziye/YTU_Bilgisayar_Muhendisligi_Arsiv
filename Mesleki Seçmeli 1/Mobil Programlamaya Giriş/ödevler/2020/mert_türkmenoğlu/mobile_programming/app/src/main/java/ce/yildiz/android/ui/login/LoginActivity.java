package ce.yildiz.android.ui.login;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import ce.yildiz.android.R;
import ce.yildiz.android.models.User;
import ce.yildiz.android.models.UserContract;
import ce.yildiz.android.databinding.ActivityLoginBinding;
import ce.yildiz.android.ui.navigation.NavigationActivity;
import ce.yildiz.android.ui.password.ForgotPasswordActivity;
import ce.yildiz.android.ui.register.RegisterActivity;
import ce.yildiz.android.util.Constants;
import ce.yildiz.android.util.DBHelper;
import ce.yildiz.android.util.SharedPreferencesUtil;

public class LoginActivity extends AppCompatActivity {
    private SQLiteDatabase db;
    private ActivityLoginBinding binding;
    private static int invalidLoginAttemptCount = 0;

    @Override
    protected void onResume() {
        super.onResume();
        invalidLoginAttemptCount = 0;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityLoginBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        DBHelper dbHelper = new DBHelper(this);
        db = dbHelper.getWritableDatabase();

        binding.loginForgotPasswordText.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent forgotPasswordIntent = new Intent(LoginActivity.this,
                        ForgotPasswordActivity.class);
                startActivity(forgotPasswordIntent);
            }
        });

        binding.loginSignUpText.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent signUpIntent = new Intent(LoginActivity.this,
                        RegisterActivity.class);
                startActivity(signUpIntent);
            }
        });

        binding.loginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String loginText = binding.loginLoginEt.getText().toString().trim();
                String password = binding.loginPasswordEt.getText().toString().trim();

                if (loginText.isEmpty() || password.length() < Constants.MIN_PASSWORD_LENGTH) {
                    invalidLoginAttemptCount++;

                    if (invalidLoginAttemptCount >= 3) {
                        Toast.makeText(LoginActivity.this,
                                R.string.login_attempt_error_text, Toast.LENGTH_SHORT).show();

                        finish();
                    } else {
                        Toast.makeText(LoginActivity.this,
                                    R.string.invalid_credentials, Toast.LENGTH_SHORT).show();
                    }
                } else {
                    User user = login(loginText, password);

                    if (user != null) {
                        Toast.makeText(LoginActivity.this,
                                R.string.login_ok_message, Toast.LENGTH_SHORT).show();

                        Intent navigationIntent = new Intent(LoginActivity.this,
                                NavigationActivity.class);

                        navigationIntent.putExtra("email", user.getEmail());
                        navigationIntent.putExtra("username", user.getUsername());

                        SharedPreferencesUtil.loadApplicationTheme(LoginActivity.this,
                                user.getUsername());

                        startActivity(navigationIntent);
                    } else {
                        Toast
                            .makeText(LoginActivity.this,
                                    R.string.invalid_credentials, Toast.LENGTH_SHORT)
                            .show();
                    }
                }
            }
        });
    }

    private User login(String loginText, String password) {
        Cursor cursor = db.query(
                UserContract.UserEntry.TABLE_NAME,
                null,
                null,
                null,
                null,
                null,
                null
        );

        while (cursor.moveToNext()) {
            try {
                String dbUserName = cursor.getString(cursor.getColumnIndex(UserContract.UserEntry.COLUMN_USER_NAME));
                String dbEmail = cursor.getString(cursor.getColumnIndex(UserContract.UserEntry.COLUMN_EMAIL));
                String dbPassword = cursor.getString(cursor.getColumnIndex(UserContract.UserEntry.COLUMN_PASSWORD));
                String dbImageURL = cursor.getString(cursor.getColumnIndex(UserContract.UserEntry.COLUMN_IMAGE_URL));

                if ((dbUserName.equals(loginText) || dbEmail.equals(loginText)) && dbPassword.equals(password)) {
                    cursor.close();
                    return new User(dbUserName, dbEmail, dbPassword, dbImageURL);
                }
            } catch (Exception ignored) {

            }
        }

        cursor.close();
        return null;
    }
}
