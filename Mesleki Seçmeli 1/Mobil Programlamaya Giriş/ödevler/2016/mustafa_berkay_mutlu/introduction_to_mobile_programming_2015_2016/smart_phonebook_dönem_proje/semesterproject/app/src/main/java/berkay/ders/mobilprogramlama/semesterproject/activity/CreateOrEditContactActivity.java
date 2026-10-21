package berkay.ders.mobilprogramlama.semesterproject.activity;

import android.app.AlertDialog;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;

import berkay.ders.mobilprogramlama.semesterproject.Config;
import berkay.ders.mobilprogramlama.semesterproject.R;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseOperations;
import berkay.ders.mobilprogramlama.semesterproject.model.Contact;

public class CreateOrEditContactActivity extends AppCompatActivity implements OnMapReadyCallback, GoogleMap.OnMapClickListener {
    private Toolbar toolbar;
    private Contact mContact = null;
    private DatabaseOperations mDatabaseOperations;
    private EditText editText_name;
    private EditText editText_surname;
    private EditText editText_phoneNumber;
    private EditText editText_email;
    private GoogleMap mGoogleMap;
    private Marker mLastSelectedMarker;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_create_or_edit_contact);

        toolbar = (Toolbar) findViewById(R.id.toolbar_createOrEditContactActivity);
        setSupportActionBar(toolbar);

        mDatabaseOperations = DatabaseOperations.get(getApplicationContext());
        long contactId = getIntent().getLongExtra(DatabaseContract.ContactsContract.COLUMN_NAME_CONTACT_ID, -1);

        if(contactId != -1) {
            mContact = mDatabaseOperations.getContact(contactId);
        }

        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager().findFragmentById(R.id.map_createOrEditContactActivity);
        mapFragment.getMapAsync(this);

        editText_name = (EditText) findViewById(R.id.editText_createOrEditContactActivity_name);
        editText_surname = (EditText) findViewById(R.id.editText_createOrEditContactActivity_surname);
        editText_phoneNumber = (EditText) findViewById(R.id.editText_createOrEditContactActivity_phoneNumber);
        editText_email = (EditText) findViewById(R.id.editText_createOrEditContactActivity_email);

        ActionBar actionBar = getSupportActionBar();
        if(actionBar != null) {
            actionBar.setTitle(getString(R.string.add_new_contact));
            actionBar.setDisplayHomeAsUpEnabled(true);
        }

    }

    @Override
    protected void onStart() {
        super.onStart();

        if(mContact != null) {
            ActionBar actionBar = getSupportActionBar();
            if(actionBar != null) {
                actionBar.setTitle(getString(R.string.action_bar_title_edit_contact));
            }

            editText_name.setText(mContact.getName());
            editText_surname.setText(mContact.getSurname());
            editText_phoneNumber.setText(mContact.getPhoneNumber());
            editText_email.setText(mContact.geteMail());
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

    public void button_createOrEditContactActivity_saveContact_onClick(View view){

        if(editText_name.getText().toString().isEmpty() || editText_surname.getText().toString().isEmpty()
                || editText_phoneNumber.getText().toString().isEmpty()
                || editText_email.getText().toString().isEmpty() || mLastSelectedMarker == null){

            AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(CreateOrEditContactActivity.this);

            alertDialogBuilder
                    .setTitle(getString(R.string.missing_fields))
                    .setMessage(getString(R.string.create_or_edit_contact_missing_fields_message))
                    .setPositiveButton(getString(R.string.ok), null);

            AlertDialog alertDialog = alertDialogBuilder.create();
            alertDialog.show();

        } else{
            Contact contact = new Contact();

            contact.setName(editText_name.getText().toString().trim());
            contact.setSurname(editText_surname.getText().toString().trim());
            contact.setPhoneNumber(editText_phoneNumber.getText().toString().trim());
            contact.seteMail(editText_email.getText().toString().trim());
            contact.setLatitude(mLastSelectedMarker.getPosition().latitude);
            contact.setLongitude(mLastSelectedMarker.getPosition().longitude);

            if(mContact != null){
                contact.setContactID(mContact.getContactID());

                mDatabaseOperations.updateContact(contact);

                // Broadcast an Intent for updating the UI.
                Intent contactUpdated = new Intent();
                contactUpdated.setAction(Config.CustomEvents.ContactUpdated.toString());
                sendBroadcast(contactUpdated);
            }
            else{
                mDatabaseOperations.addNewContact(contact);
            }

            // Broadcast an Intent for updating the UI.
            Intent contactsListChangedEvent = new Intent();
            contactsListChangedEvent.setAction(Config.CustomEvents.ContactsListChanged.toString());
            sendBroadcast(contactsListChangedEvent);

            finish();
        }

    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        mGoogleMap = googleMap;

        if(mContact != null) {
            mLastSelectedMarker = mGoogleMap.addMarker(new MarkerOptions()
                    .position(new LatLng(mContact.getLatitude(), mContact.getLongitude()))
                    .title(getString(R.string.home_of) + mContact.getName()));
        }

        googleMap.setMyLocationEnabled(true);
        googleMap.setTrafficEnabled(false);
        googleMap.setMapType(GoogleMap.MAP_TYPE_NORMAL);
        googleMap.getUiSettings().setZoomGesturesEnabled(true);
        googleMap.getUiSettings().setScrollGesturesEnabled(true);
        googleMap.getUiSettings().setMyLocationButtonEnabled(true);
        googleMap.getUiSettings().setMapToolbarEnabled(true);
        googleMap.getUiSettings().setCompassEnabled(true);
        googleMap.getUiSettings().setTiltGesturesEnabled(true);
        googleMap.setOnMapClickListener(this);

        if(mLastSelectedMarker != null){
            mGoogleMap.animateCamera(CameraUpdateFactory.newLatLng(mLastSelectedMarker.getPosition()));
        }

    }

    @Override
    public void onMapClick(LatLng latLng) {
        mGoogleMap.animateCamera(CameraUpdateFactory.newLatLng(latLng));

        if(mLastSelectedMarker != null){
            mLastSelectedMarker.remove();
        }

        mLastSelectedMarker = mGoogleMap.addMarker(new MarkerOptions()
                .position(latLng)
                .title(getString(R.string.home_of) + editText_name.getText().toString())
        );

    }
}
