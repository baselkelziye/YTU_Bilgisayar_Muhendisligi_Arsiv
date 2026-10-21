package ce.yildiz.android.ui.user;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.bumptech.glide.Glide;

import ce.yildiz.android.R;
import ce.yildiz.android.databinding.ActivityUserDetailBinding;
import ce.yildiz.android.models.UserContract;
import ce.yildiz.android.util.Constants;
import ce.yildiz.android.util.DBHelper;
import ce.yildiz.android.util.SharedPreferencesUtil;

public class UserDetailActivity extends AppCompatActivity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        if (SharedPreferencesUtil.getTheme().equals(Constants.AppThemes.DARK)) {
            setTheme(R.style.DarkTheme);
        } else {
            setTheme(R.style.AppTheme);
        }

        super.onCreate(savedInstanceState);
        ActivityUserDetailBinding binding = ActivityUserDetailBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        Intent incomingIntent = getIntent();

        if (incomingIntent == null)  {
            return;
        }

        String imageURL = incomingIntent.getStringExtra("image_url");
        final String username = incomingIntent.getStringExtra("username");
        final String email = incomingIntent.getStringExtra("email");
        String password = incomingIntent.getStringExtra("password");

        if (imageURL == null || username == null || email == null || password == null) {
            Toast.makeText(UserDetailActivity.this,
                    R.string.invalid_values, Toast.LENGTH_SHORT).show();
            return;
        }

        Glide.with(this)
                .load(imageURL)
                .error(R.drawable.ic_adb_black_24dp)
                .placeholder(R.drawable.ic_person_accent_24dp)
                .override(125, 125)
                .into(binding.userDetailImage);

        binding.userDetailUsername.setText(username);
        binding.userDetailEmail.setText(email);
        binding.userDetailPassword.setText(password);

        binding.userDetailDeleteUserBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new AlertDialog.Builder(UserDetailActivity.this)
                        .setTitle(R.string.delete_user)
                        .setMessage(R.string.delete_user_message)
                        .setIcon(R.drawable.ic_warning_accent_24dp)
                        .setPositiveButton(android.R.string.yes, new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                removeFromDatabase(username);
                                setResult(RESULT_OK);
                                finish();
                            }

                            private void removeFromDatabase(String username) {
                                try {
                                    SQLiteDatabase db = new DBHelper(UserDetailActivity.this).getWritableDatabase();
                                    db.delete(UserContract.UserEntry.TABLE_NAME,
                                            UserContract.UserEntry.COLUMN_USER_NAME + "='" + username + "'", null);
                                } catch (Exception e) {
                                    e.printStackTrace();
                                }
                            }
                        })
                        .setNegativeButton(android.R.string.no, null)
                        .show();
            }
        });
    }
}
