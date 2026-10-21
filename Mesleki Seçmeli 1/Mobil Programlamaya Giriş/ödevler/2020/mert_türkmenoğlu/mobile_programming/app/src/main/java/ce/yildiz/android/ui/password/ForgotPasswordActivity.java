package ce.yildiz.android.ui.password;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import ce.yildiz.android.R;
import ce.yildiz.android.models.User;
import ce.yildiz.android.models.UserContract;
import ce.yildiz.android.databinding.ActivityForgotPasswordBinding;
import ce.yildiz.android.util.DBHelper;

public class ForgotPasswordActivity extends AppCompatActivity {
    private ActivityForgotPasswordBinding binding;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityForgotPasswordBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        binding.forgotPasswordResetPasswordBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String loginText = binding.forgotPasswordLoginEt.getText().toString();

                if (loginText.isEmpty()) {
                    Toast.makeText(ForgotPasswordActivity.this,
                            R.string.invalid_email_or_username_message, Toast.LENGTH_SHORT).show();
                } else {
                    User user = findUser(loginText);

                    if (user != null) {
                        Intent passwordResetIntent = new Intent(ForgotPasswordActivity.this,
                                PasswordResetActivity.class);

                        passwordResetIntent.putExtra("username", user.getUsername());
                        startActivity(passwordResetIntent);
                    } else {
                        Toast.makeText(ForgotPasswordActivity.this,
                                R.string.user_not_exist_message, Toast.LENGTH_SHORT).show();
                    }
                }
            }
        });
    }

    private User findUser(String loginText) {
        DBHelper dbHelper = new DBHelper(this);
        SQLiteDatabase db = dbHelper.getReadableDatabase();

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
            String dbUserName = cursor.getString(cursor.getColumnIndex(UserContract.UserEntry.COLUMN_USER_NAME));
            String dbEmail = cursor.getString(cursor.getColumnIndex(UserContract.UserEntry.COLUMN_EMAIL));
            String dbPassword = cursor.getString(cursor.getColumnIndex(UserContract.UserEntry.COLUMN_PASSWORD));
            String dbImageURL = cursor.getString(cursor.getColumnIndex(UserContract.UserEntry.COLUMN_IMAGE_URL));

            if (dbUserName.equals(loginText) || dbEmail.equals(loginText)) {
                cursor.close();
                return new User(dbUserName, dbEmail, dbPassword, dbImageURL);
            }
        }

        cursor.close();
        return null;
    }
}
