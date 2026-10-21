package ce.yildiz.android.ui.register;

import android.content.ContentValues;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import ce.yildiz.android.R;
import ce.yildiz.android.models.UserContract;
import ce.yildiz.android.databinding.ActivitySignUpBinding;
import ce.yildiz.android.ui.login.LoginActivity;
import ce.yildiz.android.util.Constants;
import ce.yildiz.android.util.DBHelper;
import ce.yildiz.android.util.StringUtil;

public class RegisterActivity extends AppCompatActivity {
    private SQLiteDatabase db;
    private ActivitySignUpBinding binding;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivitySignUpBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        DBHelper dbHelper = new DBHelper(this);
        db = dbHelper.getWritableDatabase();

        binding.signUpButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                final String username = binding.signUpUsernameEt.getText().toString();
                final String email = binding.signUpEmailEt.getText().toString();
                final String password = binding.signUpPasswordEt.getText().toString();
                final String githubUsername = binding.signUpGithubUsernameEt.getText().toString();
                String imageURL = StringUtil.composeImageUrl(githubUsername);

                if (username.isEmpty() || email.isEmpty()
                        || password.length() < Constants.MIN_PASSWORD_LENGTH
                        || imageURL.isEmpty()) {
                    Toast.makeText(RegisterActivity.this,
                            R.string.enter_credentials, Toast.LENGTH_SHORT).show();
                } else {
                    if (!userExist(username, email)) {
                        saveUser(username, email, password, imageURL);
                        Intent loginIntent = new Intent(RegisterActivity.this,
                                LoginActivity.class);

                        loginIntent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TASK);
                        startActivity(loginIntent);
                    } else {
                        Toast.makeText(RegisterActivity.this,
                                R.string.user_exist_error_message, Toast.LENGTH_SHORT).show();
                    }

                }
            }
        });
    }

    private void saveUser(String username, String email, String password, String imageURL) {
        ContentValues cv = new ContentValues();

        cv.put(UserContract.UserEntry.COLUMN_USER_NAME, username);
        cv.put(UserContract.UserEntry.COLUMN_EMAIL, email);
        cv.put(UserContract.UserEntry.COLUMN_PASSWORD, password);
        cv.put(UserContract.UserEntry.COLUMN_IMAGE_URL, imageURL);

        db.insert(UserContract.UserEntry.TABLE_NAME, null, cv);
    }

    private boolean userExist(String username, String email) {
        DBHelper dbHelper = new DBHelper(this);
        SQLiteDatabase db = dbHelper.getWritableDatabase();

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
            String dbEmail = cursor.getString(cursor.getColumnIndex(UserContract.UserEntry.COLUMN_EMAIL));
            String dbUserName = cursor.getString(cursor.getColumnIndex(UserContract.UserEntry.COLUMN_USER_NAME));

            if (dbEmail.equals(email) || dbUserName.equals(username)) {
                cursor.close();
                return true;
            }
        }

        cursor.close();
        return false;
    }
}
