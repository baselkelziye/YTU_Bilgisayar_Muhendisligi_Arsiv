package tr.com.berkaytutal.beslenmedanismani.Utils;

import android.content.Intent;
import android.content.SharedPreferences;
import android.support.annotation.LayoutRes;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.widget.SearchView;
import android.util.Log;
import android.view.View;
import android.support.design.widget.NavigationView;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.ViewStub;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import tr.com.berkaytutal.beslenmedanismani.AddMoneyActivity;
import tr.com.berkaytutal.beslenmedanismani.AllListingsActivity;
import tr.com.berkaytutal.beslenmedanismani.AllUsersActivity;
import tr.com.berkaytutal.beslenmedanismani.HomepageActivity;
import tr.com.berkaytutal.beslenmedanismani.LoginActivity;
import tr.com.berkaytutal.beslenmedanismani.MyProgramsActivity;
import tr.com.berkaytutal.beslenmedanismani.ProfileActivity;
import tr.com.berkaytutal.beslenmedanismani.R;
import tr.com.berkaytutal.beslenmedanismani.ProgramSearchFilterActivity;

import static android.view.View.GONE;

public class BaseDrawerActivity extends AppCompatActivity
        implements NavigationView.OnNavigationItemSelectedListener {


    protected FloatingActionButton filterButton;
    protected SearchView searchView;
    private TextView textViewUserName;
    private ImageView userProfileImageView;
    private LinearLayout moneyLinearLayout;
    protected TextView moneyText;
    protected Intent searchIntent;
    protected boolean isTrainer = false;
    private UserDataPOJO userDataPOJO;
    private ImageView addMoneyImageView;

    @Override
    public void setContentView(@LayoutRes int layoutID) {
        super.setContentView(R.layout.activity_base_drawer);
        onCreateDrawer(layoutID);

        searchView = (SearchView) findViewById(R.id.searchView);
        searchIntent = new Intent(getApplicationContext(), ProgramSearchFilterActivity.class);


    }

    protected void onCreateDrawer(@LayoutRes int layoutID) {


        ViewStub stub = (ViewStub) this.findViewById(R.id.myViewStub);
        stub.setLayoutResource(layoutID);
//        stub.setVisibility(View.VISIBLE);
        View inflated = stub.inflate();
//inflated.setVisibility(View.VISIBLE);


        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);


        filterButton = (FloatingActionButton) findViewById(R.id.fab);


        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);

        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.setDrawerListener(toggle);
        toggle.syncState();

        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);


        View header = navigationView.getHeaderView(0);
        textViewUserName = (TextView) header.findViewById(R.id.nav_user_name);
        userProfileImageView = (ImageView) header.findViewById(R.id.imageView);
        moneyLinearLayout = (LinearLayout) header.findViewById(R.id.navDraverMoneyLinearLayout);
        moneyText = (TextView) header.findViewById(R.id.nav_user_money);
        addMoneyImageView = (ImageView) header.findViewById(R.id.headerAddMoney);


        userDataPOJO = ((GlobalVariables) getApplicationContext()).getUserDataPOJO();

        if (userDataPOJO != null) {
            isTrainer = userDataPOJO.isTrainer();
        } else {
            navigationView.getMenu().findItem(R.id.icon_logout).setVisible(false);
            navigationView.getMenu().findItem(R.id.icon_my_programs).setVisible(false);
            navigationView.getMenu().findItem(R.id.icon_profil).setVisible(false);
        }

        if (!((GlobalVariables) getApplicationContext()).isOnline()) {
            navigationView.getMenu().findItem(R.id.icon_home).setVisible(false);
            navigationView.getMenu().findItem(R.id.icon_all_trainers).setVisible(false);
            navigationView.getMenu().findItem(R.id.icon_all_programs).setVisible(false);


        }


        if (isTrainer) {
            drawer.setDrawerLockMode(DrawerLayout.LOCK_MODE_LOCKED_CLOSED);
            toggle.onDrawerStateChanged(DrawerLayout.LOCK_MODE_LOCKED_CLOSED);
            toggle.setDrawerIndicatorEnabled(false);
            toggle.syncState();

        }


    }

    @Override
    protected void onResume() {
        userDataPOJO = ((GlobalVariables) getApplicationContext()).getUserDataPOJO();
        try {
            textViewUserName.setText(((GlobalVariables) getApplicationContext()).getUserDataPOJO().getName());

        } catch (Exception e) {
            textViewUserName.setText("Welcome !");
        }
        try {
            userProfileImageView.setImageBitmap(userDataPOJO.getPhoto());
        } catch (Exception e) {
            e.printStackTrace();
        }

        try {
            int money = userDataPOJO.getMoney();
            moneyLinearLayout.setVisibility(View.VISIBLE);
            moneyText.setText(money + " TL");
            addMoneyImageView.setVisibility(View.VISIBLE);
            addMoneyImageView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    startActivity(new Intent(getApplicationContext(), AddMoneyActivity.class));
                }
            });

            if(!((GlobalVariables) getApplicationContext()).isOnline()){
                addMoneyImageView.setVisibility(GONE);
            }


        } catch (Exception e) {
            e.printStackTrace();
        }
        super.onResume();
    }

    @Override
    public void onBackPressed() {
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        } else {
            super.onBackPressed();
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.base_drawer, menu);

        return true;
    }

    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {
        if (isTrainer) {
            MenuItem profileButton = menu.findItem(R.id.appBarProfileButton);
            profileButton.setVisible(false);
        }


        return super.onPrepareOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {


        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();


        //noinspection SimplifiableIfStatement
        if (id == R.id.appBarProfileButton) {
//            Toast.makeText(getApplicationContext(), "Profiiiiil", Toast.LENGTH_SHORT).show();
            Intent i = new Intent(this, LoginActivity.class);
            startActivity(i);
            return true;
        }
        if (id == R.id.appBarLogoutButton) {
            //// TODO : 4.07.2017  dialog


            Toast.makeText(getApplicationContext(), "Signed out", Toast.LENGTH_SHORT).show();
            SharedPreferences userDetails = getApplicationContext().getSharedPreferences("userdetails", MODE_PRIVATE);
            SharedPreferences.Editor edit = userDetails.edit();
            edit.clear();
            edit.putString("userEmail", "");
            edit.putString("userPass", "");
            edit.commit();

//            DBHelper dbHelper = new DBHelper(getApplicationContext());
//            dbHelper.deleteUser(((GlobalVariables) getApplicationContext()).getUserDataPOJO().getUser_ID());

            ((GlobalVariables) getApplicationContext()).setUserDataPOJO(null);

            if (((GlobalVariables) getApplicationContext()).isOnline()) {

                Intent i = new Intent(this, HomepageActivity.class);
                startActivity(i);

            } else {
                int pid = android.os.Process.myPid();
                android.os.Process.killProcess(pid);
            }
            finish();
            return true;
        }


        return super.onOptionsItemSelected(item);
    }

    @SuppressWarnings("StatementWithEmptyBody")
    @Override
    public boolean onNavigationItemSelected(MenuItem item) {
        // Handle navigation view item clicks here.
        int id = item.getItemId();

        if (id == R.id.icon_home) {
            Intent i = new Intent(getApplicationContext(), HomepageActivity.class);
            i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TASK);
            startActivity(i);

        } else if (id == R.id.icon_all_trainers) {
            Intent i = new Intent(getApplicationContext(), AllUsersActivity.class);
            startActivity(i);
        } else if (id == R.id.icon_all_programs) {
            Intent i = new Intent(getApplicationContext(), AllListingsActivity.class);
            startActivity(i);
        } else if (id == R.id.icon_profil) {
            Intent i = new Intent(getApplicationContext(), ProfileActivity.class);
            startActivity(i);
        } else if (id == R.id.icon_my_programs) {
            Intent i = new Intent(getApplicationContext(), MyProgramsActivity.class);
            startActivity(i);
        } else if (id == R.id.icon_logout) {
            //// TODO: 4.07.2017  dialog
            Toast.makeText(getApplicationContext(), "Signed out", Toast.LENGTH_SHORT).show();
            SharedPreferences userDetails = getApplicationContext().getSharedPreferences("userdetails", MODE_PRIVATE);
            SharedPreferences.Editor edit = userDetails.edit();
            edit.clear();
            edit.putString("userEmail", "");
            edit.putString("userPass", "");
            edit.commit();

//            DBHelper dbHelper = new DBHelper(getApplicationContext());
//            dbHelper.deleteUser(((GlobalVariables) getApplicationContext()).getUserDataPOJO().getUser_ID());

            ((GlobalVariables) getApplicationContext()).setUserDataPOJO(null);


            if (((GlobalVariables) getApplicationContext()).isOnline()) {

                Intent i = new Intent(this, LoginActivity.class);
                startActivity(i);

            } else {
                int pid = android.os.Process.myPid();
                android.os.Process.killProcess(pid);
            }
            finish();
        }

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }

    protected void setFilterButtonVisibility(boolean visibility) {
        if (visibility) {
            filterButton.setVisibility(View.VISIBLE);
        } else {
            filterButton.setVisibility(GONE);
        }

    }

    protected void setFilterButtonListener(int type) {
        if (type == PublicVariables.FILTER_BUTTON_TYPE_PROGRAM) {
            filterButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {


                    startActivity(searchIntent);
//                overridePendingTransition(R.anim.slide_up, R.anim.slide_down);


//                    Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
//                            .setAction("Action", null).show();
                }
            });
        } else if (type == PublicVariables.FILTER_BUTTON_TYPE_USER) {
            filterButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {

                    //TODO buraya özel searchfilter eklenecek

                    Intent intent = new Intent(getApplicationContext(), ProgramSearchFilterActivity.class);
                    startActivity(intent);
//                overridePendingTransition(R.anim.slide_up, R.anim.slide_down);


                    Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                            .setAction("Action", null).show();
                }
            });
        }

    }


}

