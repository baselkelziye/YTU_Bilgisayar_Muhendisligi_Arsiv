package berkay.ders.mobilprogramlama.semesterproject.activity;

import android.Manifest;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.location.Location;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.GoogleMap.OnMapClickListener;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;

import berkay.ders.mobilprogramlama.semesterproject.Config;
import berkay.ders.mobilprogramlama.semesterproject.R;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseOperations;
import berkay.ders.mobilprogramlama.semesterproject.model.Contact;

public class SingleContactActivity extends AppCompatActivity implements OnMapReadyCallback, OnMapClickListener {
    private Contact mContact;
    private Toolbar toolbar;
    private DatabaseOperations mDatabaseOperations;
    private GoogleMap mGoogleMap;

    private TextView firstName, lastName, phoneNumber, eMailAddress1, eMailAddress2,
            incomingCallDuration, outgoingCallDuration, missingCallCount,
            sentMessageCount, receivedMessageCount;

    private BroadcastReceiver contactUpdatedReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            finish();
            startActivity(getIntent());
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_single_contact);

        toolbar = (Toolbar) findViewById(R.id.toolbar_singleContact);
        setSupportActionBar(toolbar);

        mDatabaseOperations = DatabaseOperations.get(getApplicationContext());
        long contactID = getIntent().getLongExtra(DatabaseContract.ContactsContract.COLUMN_NAME_CONTACT_ID, 0);
        mContact = mDatabaseOperations.getContact(contactID);

        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager().findFragmentById(R.id.map_singleContactActivity);
        mapFragment.getMapAsync(this);

        ActionBar actionBar = getSupportActionBar();
        if (actionBar != null) {
            actionBar.setTitle(String.format("%s %s", mContact.getName(), mContact.getSurname()));
            actionBar.setDisplayHomeAsUpEnabled(true);
        }

        firstName = (TextView) findViewById(R.id.textView_singleContactActivity_firstName);
        lastName = (TextView) findViewById(R.id.textView_singleContactActivity_lastName);
        phoneNumber = (TextView) findViewById(R.id.textView_singleContactActivity_phoneNumber);
        eMailAddress1 = (TextView) findViewById(R.id.textView_singleContactActivity_eMailAdress1);
        eMailAddress2 = (TextView) findViewById(R.id.textView_singleContactActivity_eMailAdress2);
        incomingCallDuration = (TextView) findViewById(R.id.textView_singleContactActivity_incomingCallDuration);
        outgoingCallDuration = (TextView) findViewById(R.id.textView_singleContactActivity_outgoingCallDuration);
        missingCallCount = (TextView) findViewById(R.id.textView_singleContactActivity_missingCallCount);
        sentMessageCount = (TextView) findViewById(R.id.textView_singleContactActivity_sentMessageCount);
        receivedMessageCount = (TextView) findViewById(R.id.textView_singleContactActivity_receivedMessageCount);

        registerReceiver(contactUpdatedReceiver, new IntentFilter(Config.CustomEvents.ContactUpdated.toString()));
    }

    @Override
    protected void onStart() {
        super.onStart();

        firstName.setText(mContact.getName());
        lastName.setText(mContact.getSurname());
        phoneNumber.setText(mContact.getPhoneNumber());
        eMailAddress1.setText(mContact.geteMail());
        eMailAddress2.setText(mContact.geteMail());
        incomingCallDuration.setText(String.format("%s %s", String.valueOf(mContact.getTotalIncomingDuration()), getString(R.string.seconds)));
        outgoingCallDuration.setText(String.format("%s %s", String.valueOf(mContact.getTotalOutgoingDuration()), getString(R.string.seconds)));
        missingCallCount.setText(String.valueOf(mContact.getMissingCalls()));
        sentMessageCount.setText(String.valueOf(mContact.getSentMessageCount()));
        receivedMessageCount.setText(String.valueOf(mContact.getReceivedMessageCount()));
    }

    @Override
    protected void onDestroy() {
        unregisterReceiver(contactUpdatedReceiver);

        super.onDestroy();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.single_contact_activity_menu, menu);

        if (mDatabaseOperations.isThisContactIsInSpeedDial(mContact.getContactID())) {
            menu.findItem(R.id.menu_singleContactActivity_addToSpeedDial).setIcon(R.drawable.ic_star_white_48dp);
        } else {
            menu.findItem(R.id.menu_singleContactActivity_addToSpeedDial).setIcon(R.drawable.ic_star_border_white_48dp);
        }

        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case android.R.id.home:
                //NavUtils.navigateUpFromSameTask(this);
                this.finish();
                return true;
            case R.id.menu_singleContactActivity_addToSpeedDial:
                if (mDatabaseOperations.isThisContactIsInSpeedDial(mContact.getContactID())) {
                    mDatabaseOperations.removeContactFromSpeedDial(mContact.getContactID());
                    item.setIcon(R.drawable.ic_star_border_white_48dp);
                    Toast.makeText(getApplicationContext(), mContact.getName() + getString(R.string.toast_removed_from_speed_dial), Toast.LENGTH_LONG).show();
                } else {
                    mDatabaseOperations.addContactToSpeedDial(mContact.getContactID());
                    item.setIcon(R.drawable.ic_star_white_48dp);
                    Toast.makeText(getApplicationContext(), mContact.getName() + getString(R.string.toast_added_to_speed_dial), Toast.LENGTH_LONG).show();
                }

                // Broadcast an Intent for updating the UI.
                Intent speedDialUpdatedEvent = new Intent();
                speedDialUpdatedEvent.setAction(Config.CustomEvents.SpeedDialUpdated.toString());
                sendBroadcast(speedDialUpdatedEvent);

                return true;
            case R.id.menu_singleContactActivity_edit_contact:
                Intent editContact = new Intent();
                editContact.setClass(getApplicationContext(), CreateOrEditContactActivity.class);
                editContact.putExtra(DatabaseContract.ContactsContract.COLUMN_NAME_CONTACT_ID, mContact.getContactID());
                startActivity(editContact);
                return true;

            case R.id.menu_singleContactActivity_delete_contact:
                mDatabaseOperations.deleteContact(mContact.getContactID());

                // Broadcast an Intent for updating the UI.
                Intent contactsListChangedEvent = new Intent();
                contactsListChangedEvent.setAction(Config.CustomEvents.ContactsListChanged.toString());
                sendBroadcast(contactsListChangedEvent);

                this.finish();
                return true;
        }

        return super.onOptionsItemSelected(item);
    }

    public void textView_singleContactActivity_phoneNumber_onClick(View view) {
        Intent callIntent = new Intent(Intent.ACTION_CALL, Uri.parse("tel:" + mContact.getPhoneNumber()));
        startActivity(callIntent);
    }

    public void linearLayout_singleContactActivity_eMail_onClick(View view){
        Intent intent = new Intent(Intent.ACTION_SEND);
        intent.setType("plain/text");
        intent.putExtra(Intent.EXTRA_EMAIL, new String[] { mContact.geteMail() });
        startActivity(Intent.createChooser(intent, getString(R.string.send_an_email_to) + mContact.getName()));
    }

    public void imageView_singleContactActivity_sendSms_onClick(View view){
        Intent messageActivity = new Intent();
        messageActivity.setClass(getApplicationContext(), MessageActivity.class);
        messageActivity.putExtra(DatabaseContract.MessagesContract.COLUMN_NAME_REMOTE_PHONE_NUMBER,
                mContact.getPhoneNumber());
        messageActivity.putExtra(Config.TAG_IS_NEW_MESSAGE, false);
        startActivity(messageActivity);
    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        mGoogleMap = googleMap;
        mGoogleMap.setOnMapClickListener(this);

        googleMap.setMyLocationEnabled(true);
        googleMap.setTrafficEnabled(false);
        googleMap.setMapType(GoogleMap.MAP_TYPE_NORMAL);
        googleMap.getUiSettings().setZoomGesturesEnabled(false);
        googleMap.getUiSettings().setScrollGesturesEnabled(false);
        googleMap.getUiSettings().setMyLocationButtonEnabled(false);
        googleMap.getUiSettings().setMapToolbarEnabled(false);
        googleMap.getUiSettings().setCompassEnabled(false);
        googleMap.getUiSettings().setTiltGesturesEnabled(false);

        LatLng position = new LatLng(mContact.getLatitude(), mContact.getLongitude());

        mGoogleMap.addMarker(new MarkerOptions()
                .position(position)
                .title(getString(R.string.home_of) + mContact.getName()));

        googleMap.moveCamera(CameraUpdateFactory.newLatLngZoom(position, 15));
        // Zoom in, animating the camera.
        googleMap.animateCamera(CameraUpdateFactory.zoomIn());
        // Zoom out to zoom level 10, animating with a duration of 2 seconds.
        googleMap.animateCamera(CameraUpdateFactory.zoomTo(15), 2000, null);
    }

    @Override
    public void onMapClick(LatLng latLng) {
        Location currentLocation = mGoogleMap.getMyLocation();

        if(currentLocation != null){
            Intent intent = new Intent(android.content.Intent.ACTION_VIEW,
                    Uri.parse("http://maps.google.com/maps?saddr=" + currentLocation.getLatitude()
                            + "," + currentLocation.getLongitude() + "&daddr=" + String.valueOf(mContact.getLatitude()) + ","
                            + String.valueOf(mContact.getLongitude()) ));

            startActivity(intent);
        } else{
            Toast.makeText(getApplicationContext(), getString(R.string.toast_error_cant_get_location), Toast.LENGTH_SHORT).show();
        }

    }
}
