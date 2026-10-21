package berkay.ders.mobilprogramlama.semesterproject.activity;

import android.app.Dialog;
import android.app.SearchManager;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.graphics.Typeface;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.TabLayout;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;
import android.support.v4.content.ContextCompat;
import android.support.v4.view.ViewPager;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.SearchView;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.Window;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import berkay.ders.mobilprogramlama.semesterproject.Config;
import berkay.ders.mobilprogramlama.semesterproject.R;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseOperations;
import berkay.ders.mobilprogramlama.semesterproject.fragment.CallsFragment;
import berkay.ders.mobilprogramlama.semesterproject.fragment.ContactsFragment;
import berkay.ders.mobilprogramlama.semesterproject.fragment.SmsFragment;
import berkay.ders.mobilprogramlama.semesterproject.fragment.SpeedDialFragment;

public class MainActivity extends AppCompatActivity {

    private static final int CREATE_CONTACT_REQUEST_CODE = 1;
    private String mActiveFragment = Fragments.Contacts.getName();
    private Toolbar toolbar;
    private TabLayout tabLayout;
    private ViewPager viewPager;
    private FloatingActionButton fab;
    private HashMap<String, Fragment> mFragments;

    private enum Fragments{
        Contacts("Contacts"), SpeedDial("Speed Dial"), Calls("Calls"), Sms("SMS");
        String name;

        Fragments(String name){
            this.name = name;
        }

        public String getName() {
            return name;
        }
    }

    private BroadcastReceiver smsEventOccurredReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            ((SmsFragment)mFragments.get(Fragments.Sms.getName())).refreshListView();
        }
    };

    private BroadcastReceiver callEventOccurredReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            ((CallsFragment)mFragments.get(Fragments.Calls.getName())).refreshListView();
        }
    };

    private BroadcastReceiver contactsListUpdatedReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            ((ContactsFragment)mFragments.get(Fragments.Contacts.getName())).refreshListView();
        }
    };

    private BroadcastReceiver speedDialUpdatedReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            ((SpeedDialFragment)mFragments.get(Fragments.SpeedDial.getName())).refreshListView();
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        toolbar = (Toolbar) findViewById(R.id.toolbar_mainActivity);
        setSupportActionBar(toolbar);

        TextView toolbar_title = (TextView) toolbar.findViewById(R.id.toolbar_title);
        Typeface custom_font = Typeface.createFromAsset(getAssets(), "DancingScript-Bold.ttf");
        toolbar_title.setTypeface(custom_font);

        ActionBar actionBar = getSupportActionBar();
        if(actionBar != null) {
            actionBar.setDisplayHomeAsUpEnabled(false);
            actionBar.setDisplayShowTitleEnabled(false);
        }

        viewPager = (ViewPager) findViewById(R.id.viewpager);
        setupViewPager(viewPager);
        viewPager.addOnPageChangeListener(new DetailOnPageChangeListener());

        tabLayout = (TabLayout) findViewById(R.id.tabs);
        tabLayout.setupWithViewPager(viewPager);

        fab = (FloatingActionButton) findViewById(R.id.fab);

        registerReceiver(contactsListUpdatedReceiver, new IntentFilter(Config.CustomEvents.ContactsListChanged.toString()));
        registerReceiver(smsEventOccurredReceiver, new IntentFilter(Config.CustomEvents.SmsEventOccurred.toString()));
        registerReceiver(callEventOccurredReceiver, new IntentFilter(Config.CustomEvents.CallEventOccurred.toString()));
        registerReceiver(speedDialUpdatedReceiver, new IntentFilter(Config.CustomEvents.SpeedDialUpdated.toString()));
    }

    private void setupViewPager(ViewPager viewPager) {
        ViewPagerAdapter adapter = new ViewPagerAdapter(getSupportFragmentManager());

        mFragments = new HashMap<>();

        mFragments.put(Fragments.Contacts.getName(), new ContactsFragment());
        mFragments.put(Fragments.SpeedDial.getName(), new SpeedDialFragment());
        mFragments.put(Fragments.Calls.getName(), new CallsFragment());
        mFragments.put(Fragments.Sms.getName(), new SmsFragment());

        adapter.addFragment(mFragments.get(Fragments.Contacts.getName()), Fragments.Contacts.getName());
        adapter.addFragment(mFragments.get(Fragments.SpeedDial.getName()), Fragments.SpeedDial.getName());
        adapter.addFragment(mFragments.get(Fragments.Calls.getName()), Fragments.Calls.getName());
        adapter.addFragment(mFragments.get(Fragments.Sms.getName()), Fragments.Sms.getName());

        viewPager.setAdapter(adapter);
    }

    private class ViewPagerAdapter extends FragmentPagerAdapter {
        private final List<Fragment> mFragmentList = new ArrayList<>();
        private final List<String> mFragmentTitleList = new ArrayList<>();

        public ViewPagerAdapter(FragmentManager manager) {
            super(manager);
        }

        @Override
        public Fragment getItem(int position) {
            return mFragmentList.get(position);
        }

        @Override
        public int getCount() {
            return mFragmentList.size();
        }

        public void addFragment(Fragment fragment, String title) {
            mFragmentList.add(fragment);
            mFragmentTitleList.add(title);
        }

        @Override
        public CharSequence getPageTitle(int position) {
            return mFragmentTitleList.get(position);
        }
    }

    private class DetailOnPageChangeListener extends ViewPager.SimpleOnPageChangeListener{
        @Override
        public void onPageSelected(int position) {
            MainActivity.this.mActiveFragment = Fragments.values()[position].getName();

            if(Fragments.values()[position].getName().equals(Fragments.Sms.getName())){
                fab.setImageDrawable(ContextCompat.getDrawable(getApplicationContext(), R.drawable.ic_textsms_white_48dp));
            } else{
                fab.setImageDrawable(ContextCompat.getDrawable(getApplicationContext(), R.drawable.ic_dialpad_white_48dp));
            }
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.main_activity_menu, menu);

        SearchManager searchManager = (SearchManager) getSystemService(Context.SEARCH_SERVICE);
        SearchView searchView = (SearchView) menu.findItem(R.id.menu_mainActivity_search).getActionView();
        ComponentName cn = new ComponentName(this, SearchResultsActivity.class);
        searchView.setSearchableInfo(searchManager.getSearchableInfo(cn));

        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.menu_mainActivity_add_new_contact:
                OpenAddNewContactActivity();
                return true;
            case R.id.menu_mainActivity_import_from_default_phonebook:
                new ImportFromDefaultPhoneBookAsync().execute();
                return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onDestroy() {
        unregisterReceiver(contactsListUpdatedReceiver);
        unregisterReceiver(smsEventOccurredReceiver);
        unregisterReceiver(callEventOccurredReceiver);
        unregisterReceiver(speedDialUpdatedReceiver);

        super.onDestroy();
    }

    private void OpenAddNewContactActivity() {
        Intent openCreateContactIntent = new Intent();
        openCreateContactIntent.setClass(getApplicationContext(), CreateOrEditContactActivity.class);
        startActivityForResult(openCreateContactIntent, CREATE_CONTACT_REQUEST_CODE);
    }

    public void fab_onClick(View view){
        if(mActiveFragment.equals(Fragments.Sms.getName())){
            Intent messageActivity = new Intent();
            messageActivity.setClass(getApplicationContext(), MessageActivity.class);
            messageActivity.putExtra(Config.TAG_IS_NEW_MESSAGE, true);
            startActivity(messageActivity);
        } else{
            Intent dialerIntent = new Intent();
            dialerIntent.setClass(getApplicationContext(), DialerActivity.class);
            startActivity(dialerIntent);
        }
    }

    private class ImportFromDefaultPhoneBookAsync extends AsyncTask<Void, Integer, Void>{
        Dialog circleProgressDialog;

        public ImportFromDefaultPhoneBookAsync(){
            circleProgressDialog = new Dialog(MainActivity.this);
            circleProgressDialog.requestWindowFeature(Window.FEATURE_NO_TITLE);
            circleProgressDialog.setContentView(R.layout.dialog_circle_progress);
            circleProgressDialog.setCancelable(false);
            circleProgressDialog.setCanceledOnTouchOutside(false);
        }

        @Override
        protected void onPreExecute() {
            super.onPreExecute();

            circleProgressDialog.show();

        }

        @Override
        protected Void doInBackground(Void... params) {
            DatabaseOperations databaseOperations = DatabaseOperations.get(getApplicationContext());
            databaseOperations.addNewContact(databaseOperations.readContactsFromDefaultPhoneBook());

            return null;
        }

        @Override
        protected void onPostExecute(Void aVoid) {
            super.onPostExecute(aVoid);

            // Broadcast an Intent for updating the UI.
            Intent contactsListUpdatedEvent = new Intent();
            contactsListUpdatedEvent.setAction(Config.CustomEvents.ContactsListChanged.toString());
            MainActivity.this.sendBroadcast(contactsListUpdatedEvent);

            circleProgressDialog.dismiss();
        }
    }

}
