package tr.com.berkaytutal.beslenmedanismani;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.v4.widget.SwipeRefreshLayout;
import android.support.v7.app.AlertDialog;
import android.support.v7.widget.SearchView;
import android.view.View;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.Adapters.ProgramListingAdapter;
import tr.com.berkaytutal.beslenmedanismani.Utils.BaseDrawerActivity;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.PublicVariables;

public class AllListingsActivity extends BaseDrawerActivity implements SwipeRefreshLayout.OnRefreshListener, SearchView.OnQueryTextListener {

    private ListView listView;
    private SwipeRefreshLayout swipeRefreshLayout;


    private String searchQueryString = "";
    private String trainerQueryString = "";


    private int catPos = 0;
    private int diffPos = 0;
    private int sortPos = 0;
    private boolean isFiltered = false;

    private ProgramListingAdapter pla;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_all_listings);

        overridePendingTransition(R.anim.slide_from_right, R.anim.slide_to_left);


        setFilterButtonVisibility(true);
        setFilterButtonListener(PublicVariables.FILTER_BUTTON_TYPE_PROGRAM);
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

        ArrayList<ProgramPOJO> allPrograms = ((GlobalVariables)getApplicationContext()).getAllPrograms();

        Intent resultIntent = getIntent();
        if(resultIntent!=null){
            ArrayList<ProgramPOJO> filteredPrograms = (ArrayList<ProgramPOJO>) resultIntent.getSerializableExtra("filterResults");
            if(filteredPrograms!=null){
                allPrograms = filteredPrograms;
                searchQueryString = resultIntent.getStringExtra("searchQueryString");
                trainerQueryString = resultIntent.getStringExtra("trainerQueryString");
                catPos = resultIntent.getIntExtra("catPos",0);
                diffPos = resultIntent.getIntExtra("diffPos",0);
                sortPos = resultIntent.getIntExtra("sortPos",0);

                searchIntent.putExtra("searchQueryString",searchQueryString);
                searchIntent.putExtra("trainerQueryString",trainerQueryString);
                searchIntent.putExtra("catPos",catPos);
                searchIntent.putExtra("diffPos",diffPos);
                searchIntent.putExtra("sortPos",sortPos);
                isFiltered = true;
            }




        }

        pla = new ProgramListingAdapter(this, allPrograms);
        listView.setAdapter(pla);
        View empty = findViewById(R.id.empty);
        listView.setEmptyView(empty);

    }

    @Override
    protected void onResume() {
        super.onResume();
        pla.notifyDataSetChanged();
    }

    @Override
    public void onBackPressed() {
        if(isFiltered){
            DialogInterface.OnClickListener dialogClickListener = new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    switch (which){
                        case DialogInterface.BUTTON_POSITIVE:
                            AllListingsActivity.super.onBackPressed();
                            overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);
                            break;

                        case DialogInterface.BUTTON_NEGATIVE:
                            //No button clicked
                            break;
                    }
                }
            };

            AlertDialog.Builder builder = new AlertDialog.Builder(this);
            builder.setMessage("All filters are going to be disappear if you go back").setTitle("Are you sure?").setPositiveButton("Yes", dialogClickListener)
                    .setNegativeButton("No", dialogClickListener).show();
        }
        else{
            super.onBackPressed();
            overridePendingTransition(R.anim.slide_from_left, R.anim.slide_to_right);
        }

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
