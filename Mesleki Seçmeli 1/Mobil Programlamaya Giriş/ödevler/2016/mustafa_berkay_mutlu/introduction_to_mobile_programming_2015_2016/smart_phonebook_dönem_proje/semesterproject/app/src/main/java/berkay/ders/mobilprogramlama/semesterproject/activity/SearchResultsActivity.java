package berkay.ders.mobilprogramlama.semesterproject.activity;

import android.app.SearchManager;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;

import java.util.ArrayList;

import berkay.ders.mobilprogramlama.semesterproject.R;
import berkay.ders.mobilprogramlama.semesterproject.adapter.ContactsAdapter;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseOperations;
import berkay.ders.mobilprogramlama.semesterproject.model.Contact;

public class SearchResultsActivity extends AppCompatActivity {

    private Toolbar toolbar;
    private DatabaseOperations mDatabaseOperations;
    private ListView listView_contacts;
    private String mSearchQuery;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_search_results);

        toolbar = (Toolbar) findViewById(R.id.toolbar_mainActivity);
        setSupportActionBar(toolbar);

        mDatabaseOperations = DatabaseOperations.get(getApplicationContext());
        listView_contacts = (ListView) findViewById(R.id.listView_searchResultsActivity_contacts);
        listView_contacts.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Intent singleContact = new Intent();
                singleContact.setClass(getApplicationContext(), SingleContactActivity.class);
                singleContact.putExtra(DatabaseContract.ContactsContract.COLUMN_NAME_CONTACT_ID, id);
                startActivity(singleContact);
            }
        });

        handleIntent(getIntent());

        ActionBar actionBar = getSupportActionBar();
        if(actionBar != null) {
            actionBar.setDisplayHomeAsUpEnabled(true);

            if(mSearchQuery != null)
                actionBar.setTitle(mSearchQuery);
        }

    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case android.R.id.home:
                this.finish();
                //NavUtils.navigateUpFromSameTask(this);
                return true;
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onNewIntent(Intent intent) {
        handleIntent(intent);
    }

    private void handleIntent(Intent intent) {

        if (Intent.ACTION_SEARCH.equals(intent.getAction())) {
            mSearchQuery = intent.getStringExtra(SearchManager.QUERY);

            ArrayList<Contact> searchResults = mDatabaseOperations.search(mSearchQuery);
            listView_contacts.setAdapter(new ContactsAdapter(getApplicationContext(), searchResults));
        }
    }

}
