package tr.com.berkaytutal.beslenmedanismani;

import android.os.Bundle;
import android.support.v4.widget.SwipeRefreshLayout;
import android.support.v7.widget.SearchView;
import android.view.View;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.Adapters.UserListingAdapter;
import tr.com.berkaytutal.beslenmedanismani.Utils.BaseDrawerActivity;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.PublicVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.TrainerPOJO;

public class AllUsersActivity extends BaseDrawerActivity implements SwipeRefreshLayout.OnRefreshListener, SearchView.OnQueryTextListener {

    private ListView listView;
    private SwipeRefreshLayout swipeRefreshLayout;
    private UserListingAdapter ula;

    @Override
    protected void onResume() {
        super.onResume();
        ula.notifyDataSetChanged();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_all_listings);

        overridePendingTransition(R.anim.slide_from_right, R.anim.slide_to_left);


        setFilterButtonVisibility(true);
        setFilterButtonListener(PublicVariables.FILTER_BUTTON_TYPE_USER);

        ArrayList<TrainerPOJO> allUsers = ((GlobalVariables)getApplicationContext()).getAllUsers();
        

//        searchView.setVisibility(View.VISIBLE);
//        searchView.setIconified(false);

        searchView.setOnQueryTextListener(this);



        listView = (ListView) findViewById(R.id.allProgramsListView);


        swipeRefreshLayout = (SwipeRefreshLayout) findViewById(R.id.swipeRefreshLayout);


        swipeRefreshLayout.setOnRefreshListener(this);
        swipeRefreshLayout.setColorSchemeColors(getResources().getColor(android.R.color.holo_blue_bright),
                getResources().getColor(android.R.color.holo_green_light),
                getResources().getColor(android.R.color.holo_orange_light),
                getResources().getColor(android.R.color.holo_red_light));

//        swipeRefreshLayout.setRefreshing(true);


        ula = new UserListingAdapter(this, allUsers);
        listView.setAdapter(ula);

        View empty = findViewById(R.id.empty);
        listView.setEmptyView(empty);


    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);
    }




    @Override
    public void onRefresh() {

        //Toast.makeText(this, "Refresh yapıldı", Toast.LENGTH_SHORT).show();
        swipeRefreshLayout.setRefreshing(false);

    }


    @Override
    public boolean onQueryTextSubmit(String query) {

        //Toast.makeText(this,query,Toast.LENGTH_SHORT).show();
        return false;
    }

    @Override
    public boolean onQueryTextChange(String newText) {
        return false;
    }
}
