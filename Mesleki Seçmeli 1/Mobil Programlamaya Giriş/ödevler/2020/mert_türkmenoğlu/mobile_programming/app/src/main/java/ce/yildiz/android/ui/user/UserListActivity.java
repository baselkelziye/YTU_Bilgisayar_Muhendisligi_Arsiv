package ce.yildiz.android.ui.user;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.text.method.HideReturnsTransformationMethod;
import android.text.method.PasswordTransformationMethod;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.cardview.widget.CardView;
import androidx.recyclerview.widget.ItemTouchHelper;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import androidx.swiperefreshlayout.widget.SwipeRefreshLayout;

import java.util.ArrayList;
import java.util.List;

import ce.yildiz.android.R;
import ce.yildiz.android.databinding.ActivityUserListBinding;
import ce.yildiz.android.interfaces.RecyclerViewClickListener;
import ce.yildiz.android.models.User;
import ce.yildiz.android.models.UserContract;
import ce.yildiz.android.ui.user.adapters.UserListAdapter;
import ce.yildiz.android.util.Constants;
import ce.yildiz.android.util.DBHelper;
import ce.yildiz.android.util.SharedPreferencesUtil;

public class UserListActivity extends AppCompatActivity {
    private static final int USER_DETAIL_REQUEST_CODE = 2;
    private ActivityUserListBinding binding;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        if (SharedPreferencesUtil.getTheme().equals(Constants.AppThemes.DARK)) {
            setTheme(R.style.DarkTheme);
        } else {
            setTheme(R.style.AppTheme);
        }

        super.onCreate(savedInstanceState);
        binding = ActivityUserListBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        final List<User> users = getUsersFromDatabase();

        RecyclerView.LayoutManager layoutManager = new LinearLayoutManager(this);
        binding.userListRecyclerView.setLayoutManager(layoutManager);

        RecyclerViewClickListener listener = new RecyclerViewClickListener() {
            @Override
            public void onClick(View view, int position) {
                TextView password = view.findViewById(R.id.user_list_item_password);
                CardView cardView = view.findViewById(R.id.user_list_item_card_view);
                LinearLayout layout = view.findViewById(R.id.user_list_item_container);

                if (password.getTransformationMethod().equals(PasswordTransformationMethod.getInstance())) {
                    password.setTransformationMethod(HideReturnsTransformationMethod.getInstance());
                    cardView.setCardBackgroundColor(getColor(android.R.color.holo_red_light));
                    layout.setBackgroundColor(getColor(android.R.color.holo_red_light));
                } else {
                    password.setTransformationMethod(PasswordTransformationMethod.getInstance());
                    cardView.setCardBackgroundColor(getColor(R.color.cardview_dark_background));
                    layout.setBackgroundColor(getColor(R.color.cardview_dark_background));
                }
            }
        };

        UserListAdapter adapter = new UserListAdapter(this, users, listener);
        binding.userListRecyclerView.setAdapter(adapter);

        ItemTouchHelper itemTouchHelper = new ItemTouchHelper(new SwipeToDeleteCallback(adapter));
        itemTouchHelper.attachToRecyclerView(binding.userListRecyclerView);

        final SwipeRefreshLayout swipeRefresh = findViewById(R.id.user_list_swipe_refresh);
        swipeRefresh.setColorSchemeColors(getColor(R.color.colorPrimary));
        swipeRefresh.setOnRefreshListener(new SwipeRefreshLayout.OnRefreshListener() {
            @Override
            public void onRefresh() {
                users.clear();
                users.addAll(getUsersFromDatabase());

                RecyclerView.Adapter a = binding.userListRecyclerView.getAdapter();
                if (a != null) {
                    a.notifyDataSetChanged();
                }

                swipeRefresh.setRefreshing(false);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (resultCode == RESULT_OK) {
            if (requestCode == USER_DETAIL_REQUEST_CODE) {
                RecyclerView.Adapter adapter = binding.userListRecyclerView.getAdapter();
                if (adapter != null) {
                    adapter.notifyDataSetChanged();
                }
            }
        }
    }

    private List<User> getUsersFromDatabase() {
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

        ArrayList<User> users = new ArrayList<>();

        while (cursor.moveToNext()) {
            String dbUsername = cursor.getString(cursor.getColumnIndex(UserContract.UserEntry.COLUMN_USER_NAME));
            String dbEmail = cursor.getString(cursor.getColumnIndex(UserContract.UserEntry.COLUMN_EMAIL));
            String dbPassword = cursor.getString(cursor.getColumnIndex(UserContract.UserEntry.COLUMN_PASSWORD));
            String dbImageURL = cursor.getString(cursor.getColumnIndex(UserContract.UserEntry.COLUMN_IMAGE_URL));

            User user = new User(dbUsername, dbEmail, dbPassword, dbImageURL);
            users.add(user);
        }

        cursor.close();
        return users;
    }
}
