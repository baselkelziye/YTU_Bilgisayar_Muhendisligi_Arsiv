package berkay.ders.mobilprogramlama.semesterproject.activity;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.telephony.SmsManager;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.Date;

import berkay.ders.mobilprogramlama.semesterproject.Config;
import berkay.ders.mobilprogramlama.semesterproject.R;
import berkay.ders.mobilprogramlama.semesterproject.adapter.MessagesAdapter;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract.MessagesContract;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseOperations;
import berkay.ders.mobilprogramlama.semesterproject.model.Contact;
import berkay.ders.mobilprogramlama.semesterproject.model.Message;

public class MessageActivity extends AppCompatActivity {
    private Toolbar toolbar;
    private DatabaseOperations mDatabaseOperations;
    private String mRemotePhoneNumber;
    private ListView listView_messages;
    private EditText editText_phoneNumber, editText_messageInput;
    private Contact mContact;
    private MessagesAdapter mMessagesAdapter;

    private BroadcastReceiver smsEventReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            refreshListView();
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_message);

        listView_messages = (ListView) findViewById(R.id.listView_messageActivity_messages);
        editText_phoneNumber = (EditText) findViewById(R.id.editText_messageActivity_phoneNumber);
        editText_messageInput = (EditText) findViewById(R.id.editText_messageActivity_messageInput);

        toolbar = (Toolbar) findViewById(R.id.toolbar_messageActivity);
        setSupportActionBar(toolbar);

        mDatabaseOperations = DatabaseOperations.get(getApplicationContext());
        boolean isNewSms = getIntent().getBooleanExtra(Config.TAG_IS_NEW_MESSAGE, true);

        if(isNewSms){
            editText_phoneNumber.setVisibility(EditText.VISIBLE);

            mMessagesAdapter = new MessagesAdapter(getApplicationContext(), new ArrayList<Message>());
        } else{
            editText_phoneNumber.setVisibility(EditText.GONE);
            mRemotePhoneNumber = getIntent().getStringExtra(MessagesContract.COLUMN_NAME_REMOTE_PHONE_NUMBER);
            mContact = mDatabaseOperations.getContact(mRemotePhoneNumber);

            mMessagesAdapter = new MessagesAdapter(getApplicationContext(), mDatabaseOperations.getMessagesFrom(mRemotePhoneNumber));

        }

        listView_messages.setAdapter(mMessagesAdapter);

        ActionBar actionBar = getSupportActionBar();
        if (actionBar != null) {
            if(!isNewSms){
                if(mContact != null)
                    actionBar.setTitle(mContact.getName() + " " + mContact.getSurname());
                else
                    actionBar.setTitle(mRemotePhoneNumber);
            } else {
                actionBar.setTitle(getString(R.string.action_bar_title_send_new_sms));
            }

            actionBar.setDisplayHomeAsUpEnabled(true);
        }

        registerReceiver(smsEventReceiver, new IntentFilter(Config.CustomEvents.SmsEventOccurred.toString()));
    }

    @Override
    protected void onStart() {
        super.onStart();

        scrollMyListViewToBottom();
    }

    @Override
    protected void onDestroy() {
        unregisterReceiver(smsEventReceiver);

        super.onDestroy();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.message_activity_menu, menu);

        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case android.R.id.home:
                //NavUtils.navigateUpFromSameTask(this);
                this.finish();
                return true;

            case R.id.menu_messageActivity_delete_all_messages:
                mDatabaseOperations.deleteAllMessagesWithThisContact(mRemotePhoneNumber);

                this.finish();

                // Broadcast an Intent for updating the UI.
                Intent smsEventOccurred = new Intent();
                smsEventOccurred.setAction(Config.CustomEvents.SmsEventOccurred.toString());
                sendBroadcast(smsEventOccurred);

                return true;
        }

        return super.onOptionsItemSelected(item);
    }

    public void button_messageActivity_send_onClick(View view){
        Message message = new Message();

        message.setIsFromMe(true);
        message.setText(editText_messageInput.getText().toString().trim());
        message.setRemotePhoneNumber(mRemotePhoneNumber);
        message.setDate(new Date().getTime());

        editText_messageInput.setText("");

        SmsManager smsManager = SmsManager.getDefault();
        smsManager.sendTextMessage(message.getRemotePhoneNumber(), null, message.getText(), null, null);

        // TODO mesaj "aliciya iletildiginde" veritabanina eklenecek.
        // bunun icin sendTextMessage(..) metodundaki PendingIntentlerden faydalanacagiz.
        mDatabaseOperations.addNewMessage(message);

        // Update the contact if it has record in the phonebook
        Contact contact = mDatabaseOperations.getContact(mRemotePhoneNumber);
        if(contact != null){
            contact.setSentMessageCount(contact.getSentMessageCount() + 1);
            mDatabaseOperations.updateContact(contact);
        }

        // Broadcast an Intent for updating the UI.
        Intent smsEventOccurred = new Intent();
        smsEventOccurred.setAction(Config.CustomEvents.SmsEventOccurred.toString());
        sendBroadcast(smsEventOccurred);
    }

    private void refreshListView(){
        mMessagesAdapter.updateItems(mDatabaseOperations.getMessagesFrom(mRemotePhoneNumber));
        scrollMyListViewToBottom();
    }

    private void scrollMyListViewToBottom() {
        listView_messages.post(new Runnable() {
            @Override
            public void run() {
                // Select the last row so it will scroll into view...
                listView_messages.setSelection(listView_messages.getCount() - 1);
            }
        });
    }

}
