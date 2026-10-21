package berkay.ders.mobilprogramlama.semesterproject.database;

import android.content.ContentResolver;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import com.google.i18n.phonenumbers.NumberParseException;
import com.google.i18n.phonenumbers.PhoneNumberUtil;
import com.google.i18n.phonenumbers.Phonenumber;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;

import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract.CallsContract;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract.ContactsContract;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract.MessagesContract;
import berkay.ders.mobilprogramlama.semesterproject.database.wrappers.CallsCursorWrapper;
import berkay.ders.mobilprogramlama.semesterproject.database.wrappers.ContactsCursorWrapper;
import berkay.ders.mobilprogramlama.semesterproject.database.wrappers.MessagesCursorWrapper;
import berkay.ders.mobilprogramlama.semesterproject.model.Call;
import berkay.ders.mobilprogramlama.semesterproject.model.Contact;
import berkay.ders.mobilprogramlama.semesterproject.model.Message;

/**
 * Created by mberk on 14.12.2015.
 */
public class DatabaseOperations {
    private static DatabaseOperations sDatabaseOperations;

    private Context mContext;
    private SQLiteDatabase mDatabase;
    private static PhoneNumberUtil mPhoneUtil;

    public static DatabaseOperations get(Context context) {
        if (sDatabaseOperations == null) {
            sDatabaseOperations = new DatabaseOperations(context);
        }
        return sDatabaseOperations;
    }

    private DatabaseOperations(Context context) {
        mContext = context.getApplicationContext();
        mDatabase = new UserDatabaseHelper(mContext).getWritableDatabase();
        mPhoneUtil = PhoneNumberUtil.getInstance();
    }

    public ArrayList<Contact> getAllContacts() {
        ArrayList<Contact> contacts = new ArrayList<>();

        ContactsCursorWrapper cursor = queryContacts(
                null,
                null,
                ContactsContract.COLUMN_NAME_CONTACT_FIRST_NAME + ", " + ContactsContract.COLUMN_NAME_CONTACT_SURNAME
        );

        cursor.moveToFirst();
        while (!cursor.isAfterLast()) {
            contacts.add(cursor.getContact());
            cursor.moveToNext();
        }
        cursor.close();

        return contacts;
    }

    public ArrayList<Contact> getAllSpeedDialContacts() {
        ArrayList<Contact> contacts = new ArrayList<>();

        ContactsCursorWrapper cursor = queryContacts(
                ContactsContract.COLUMN_NAME_CONTACT_IS_IN_SPEED_DIAL + " = ?",
                new String[]{String.valueOf(1)},
                ContactsContract.COLUMN_NAME_CONTACT_FIRST_NAME + ", " + ContactsContract.COLUMN_NAME_CONTACT_SURNAME
        );

        cursor.moveToFirst();
        while (!cursor.isAfterLast()) {
            contacts.add(cursor.getContact());
            cursor.moveToNext();
        }
        cursor.close();

        return contacts;
    }

    public Contact getContact(long contactID){
        ContactsCursorWrapper cursor = queryContacts(
                ContactsContract.COLUMN_NAME_CONTACT_ID + " = ?",
                new String[]{
                        String.valueOf(contactID)
                },
                null
        );

        try {
            if (cursor.getCount() == 0) {
                return null;
            }

            cursor.moveToFirst();
            return cursor.getContact();
        } finally {
            cursor.close();
        }
    }

    public Contact getContact(String phoneNumber){
        phoneNumber = formatPhoneNumber(phoneNumber);

        ContactsCursorWrapper cursor = queryContacts(
                ContactsContract.COLUMN_NAME_CONTACT_PHONE_NUMBER + " = ?",
                new String[]{
                        String.valueOf(phoneNumber)
                },
                null
        );

        try {
            if (cursor.getCount() == 0) {
                return null;
            }

            cursor.moveToFirst();
            return cursor.getContact();
        } finally {
            cursor.close();
        }
    }

    public void addNewContact(Contact contact){
        contact.setPhoneNumber(formatPhoneNumber(contact.getPhoneNumber()));
        ContentValues values = getContactContentValues(contact);
        values.remove(ContactsContract.COLUMN_NAME_CONTACT_ID);
        mDatabase.insert(
                ContactsContract.TABLE_NAME,
                null,
                values
        );
    }

    public void addNewContact(ArrayList<Contact> contactList){
        for(Contact contact : contactList) {
            ContentValues values = getContactContentValues(contact);
            values.remove(ContactsContract.COLUMN_NAME_CONTACT_ID);
            mDatabase.insert(
                    ContactsContract.TABLE_NAME,
                    null,
                    values
            );
        }
    }

    public void addContactToSpeedDial(long contactID){
        ContentValues contentValues = new ContentValues();
        contentValues.put(ContactsContract.COLUMN_NAME_CONTACT_IS_IN_SPEED_DIAL, true);
        mDatabase.update(
                ContactsContract.TABLE_NAME, contentValues,
                ContactsContract.COLUMN_NAME_CONTACT_ID + " = ?",
                new String[]{String.valueOf(contactID)}
        );
    }

    public void removeContactFromSpeedDial(long contactID) {
        ContentValues contentValues = new ContentValues();
        contentValues.put(ContactsContract.COLUMN_NAME_CONTACT_IS_IN_SPEED_DIAL, false);
        mDatabase.update(
                ContactsContract.TABLE_NAME, contentValues,
                ContactsContract.COLUMN_NAME_CONTACT_ID + " = ?",
                new String[]{String.valueOf(contactID)}
        );
    }

    public void updateContact(Contact contact) {
        ContentValues values = getContactContentValues(contact);
        values.remove(ContactsContract.COLUMN_NAME_CONTACT_ID);
        mDatabase.update(
                ContactsContract.TABLE_NAME, values,
                ContactsContract.COLUMN_NAME_CONTACT_ID + " = ?",
                new String[]{String.valueOf(contact.getContactID())}
        );
    }

    public void deleteContact(long contactID) {
        mDatabase.delete(
                ContactsContract.TABLE_NAME,
                ContactsContract.COLUMN_NAME_CONTACT_ID + " = ?",
                new String[]{String.valueOf(contactID)}
        );
    }

    public boolean isThisContactIsInSpeedDial(long contactID){
        ContactsCursorWrapper cursor = queryContacts(
                ContactsContract.COLUMN_NAME_CONTACT_ID + " = ? AND " +
                        ContactsContract.COLUMN_NAME_CONTACT_IS_IN_SPEED_DIAL + " = 1",
                new String[]{String.valueOf(contactID)},
                null
        );

        int count = cursor.getCount();

        return count > 0;
    }

    public ArrayList<Contact> readContactsFromDefaultPhoneBook(){
        ArrayList<Contact> contacts = new ArrayList<>();

        ContentResolver cr = mContext.getContentResolver();

        Cursor cursor = cr.query(
                android.provider.ContactsContract.Contacts.CONTENT_URI,
                new String[]{android.provider.ContactsContract.Contacts._ID, android.provider.ContactsContract.Contacts.HAS_PHONE_NUMBER},
                android.provider.ContactsContract.Contacts.HAS_PHONE_NUMBER + " = ?",
                new String[]{"1"},
                null
        );

        if(cursor != null) {
            int contactsCount = cursor.getCount();

            if (contactsCount > 0) {
                while (cursor.moveToNext()) {
                    Contact contact = new Contact();
                    String id = cursor.getString(cursor.getColumnIndex(android.provider.ContactsContract.Contacts._ID));

                    Cursor nameCur = cr.query(
                            android.provider.ContactsContract.Data.CONTENT_URI,
                            new String[]{ android.provider.ContactsContract.CommonDataKinds.StructuredName.GIVEN_NAME,
                                    android.provider.ContactsContract.CommonDataKinds.StructuredName.FAMILY_NAME },
                            android.provider.ContactsContract.Data.CONTACT_ID + " = ?" + " AND " + android.provider.ContactsContract.Data.MIMETYPE + " = ?",
                            new String[]{id, android.provider.ContactsContract.CommonDataKinds.StructuredName.CONTENT_ITEM_TYPE},
                            null
                    );

                    if(nameCur.getCount() < 1)
                        continue;

                    nameCur.moveToFirst();
                    String name = nameCur.getString(nameCur.getColumnIndex(android.provider.ContactsContract.CommonDataKinds.StructuredName.GIVEN_NAME));
                    String surname = nameCur.getString(nameCur.getColumnIndex(android.provider.ContactsContract.CommonDataKinds.StructuredName.FAMILY_NAME));
                    nameCur.close();

                    if(name == null && surname == null)
                        continue;

                    contact.setName(name == null ? "" : name);
                    contact.setSurname(surname == null ? "" : surname);

                    boolean hasPhone = cursor.getString(cursor.getColumnIndex(android.provider.ContactsContract.Contacts.HAS_PHONE_NUMBER)).equals("1");
                    if (hasPhone) {
                        Cursor phoneCur = cr.query(
                                android.provider.ContactsContract.CommonDataKinds.Phone.CONTENT_URI,
                                new String[]{android.provider.ContactsContract.CommonDataKinds.Phone.NUMBER},
                                android.provider.ContactsContract.CommonDataKinds.Phone.CONTACT_ID + " = ?",
                                new String[]{id},
                                null
                        );

                        phoneCur.moveToFirst();
                        String phone = phoneCur.getString(
                                phoneCur.getColumnIndex(android.provider.ContactsContract.CommonDataKinds.Phone.NUMBER));
                        phone = formatPhoneNumber(phone);
                        contact.setPhoneNumber(phone);
                        phoneCur.close();
                    }

                    Cursor emailCur = cr.query(
                            android.provider.ContactsContract.CommonDataKinds.Email.CONTENT_URI,
                            new String[]{android.provider.ContactsContract.CommonDataKinds.Email.DATA},
                            android.provider.ContactsContract.CommonDataKinds.Email.CONTACT_ID + " = ?",
                            new String[]{id},
                            null
                    );

                    if(emailCur.getCount() > 0) {
                        emailCur.moveToFirst();
                        String email = emailCur.getString(
                                emailCur.getColumnIndex(android.provider.ContactsContract.CommonDataKinds.Email.DATA));

                        contact.seteMail(email);
                    }
                    emailCur.close();

                    contacts.add(contact);
                }

                cursor.close();
            }
        }

        return contacts;
    }

    public ArrayList<Contact> search(String query){
        ArrayList<Contact> searchResults = new ArrayList<>();
        String[] arguments = new String[4];

        Arrays.fill(arguments, '%' + query + '%');

        ContactsCursorWrapper cursor = queryContacts(
                ContactsContract.COLUMN_NAME_CONTACT_FIRST_NAME + " LIKE ? OR " + ContactsContract.COLUMN_NAME_CONTACT_SURNAME + " LIKE ? OR "
                        + ContactsContract.COLUMN_NAME_CONTACT_EMAIL + " LIKE ? OR " + ContactsContract.COLUMN_NAME_CONTACT_PHONE_NUMBER + " LIKE ?",
                arguments,
                null
        );

        cursor.moveToFirst();
        while (!cursor.isAfterLast()) {
            searchResults.add(cursor.getContact());
            cursor.moveToNext();
        }
        cursor.close();

        return searchResults;
    }

    public ArrayList<Message> getAllMessagesOverview(){
        ArrayList<Message> messageOverview = new ArrayList<>();

        MessagesCursorWrapper cursor = queryMessages(
                null,
                null,
                MessagesContract.COLUMN_NAME_REMOTE_PHONE_NUMBER,
                MessagesContract.COLUMN_NAME_MESSAGE_DATE + " DESC"
        );

        cursor.moveToFirst();
        while (!cursor.isAfterLast()) {
            messageOverview.add(cursor.getMessage());
            cursor.moveToNext();
        }
        cursor.close();

        return messageOverview;
    }

    public void addNewMessage(Message message){
        message.setRemotePhoneNumber(formatPhoneNumber(message.getRemotePhoneNumber()));
        ContentValues values = getMessagesContentValues(message);
        values.remove(MessagesContract.COLUMN_NAME_MESSAGE_ID);
        mDatabase.insert(
                MessagesContract.TABLE_NAME,
                null,
                values
        );
    }

    public Message getMessage(long messageID){
        MessagesCursorWrapper cursor = queryMessages(
                MessagesContract.COLUMN_NAME_MESSAGE_ID + " = ?",
                new String[]{
                        String.valueOf(messageID)
                },
                null,
                null
        );

        try {
            if (cursor.getCount() == 0) {
                return null;
            }

            cursor.moveToFirst();
            return cursor.getMessage();
        } finally {
            cursor.close();
        }
    }

    public ArrayList<Message> getMessagesFrom(String phoneNumber){
        ArrayList<Message> messages = new ArrayList<>();

        phoneNumber = formatPhoneNumber(phoneNumber);

        MessagesCursorWrapper cursor = queryMessages(
                MessagesContract.COLUMN_NAME_REMOTE_PHONE_NUMBER + " = ?",
                new String[]{phoneNumber},
                null,
                MessagesContract.COLUMN_NAME_MESSAGE_DATE
        );

        cursor.moveToFirst();
        while (!cursor.isAfterLast()) {
            messages.add(cursor.getMessage());
            cursor.moveToNext();
        }
        cursor.close();

        return messages;
    }

    public void deleteAllMessagesWithThisContact(String phoneNumber){
        phoneNumber = formatPhoneNumber(phoneNumber);

        mDatabase.delete(
                MessagesContract.TABLE_NAME,
                MessagesContract.COLUMN_NAME_REMOTE_PHONE_NUMBER + " = ?",
                new String[]{phoneNumber}
        );
    }

    public void addNewCall(Call call){
        call.setPhoneNumber(formatPhoneNumber(call.getPhoneNumber()));
        ContentValues values = getCallsContentValues(call);
        values.remove(CallsContract.COLUMN_NAME_CALL_ID);
        mDatabase.insert(
                CallsContract.TABLE_NAME,
                null,
                values
        );
    }

    public ArrayList<Call> getAllCalls(){
        ArrayList<Call> calls = new ArrayList<>();

        Calendar calAMonthAgo = Calendar.getInstance();
        calAMonthAgo.add(Calendar.DATE, -60); // Set two months ago.

        CallsCursorWrapper cursor = queryCalls(
                CallsContract.COLUMN_NAME_CALL_DATE + " < ?", // WHERE clause,
                new String[]{calAMonthAgo.getTime().toString()},
                CallsContract.COLUMN_NAME_CALL_DATE + " DESC"
        );

        cursor.moveToFirst();
        while (!cursor.isAfterLast()) {
            calls.add(cursor.getCall());
            cursor.moveToNext();
        }
        cursor.close();

        return calls;
    }

    private static ContentValues getContactContentValues(Contact contact) {
        ContentValues values = new ContentValues();

        values.put(ContactsContract.COLUMN_NAME_CONTACT_ID, contact.getContactID());
        values.put(ContactsContract.COLUMN_NAME_CONTACT_FIRST_NAME, contact.getName());
        values.put(ContactsContract.COLUMN_NAME_CONTACT_SURNAME, contact.getSurname());
        values.put(ContactsContract.COLUMN_NAME_CONTACT_PHONE_NUMBER, contact.getPhoneNumber());
        values.put(ContactsContract.COLUMN_NAME_CONTACT_EMAIL, contact.geteMail());
        values.put(ContactsContract.COLUMN_NAME_CONTACT_LONGITUDE, contact.getLongitude());
        values.put(ContactsContract.COLUMN_NAME_CONTACT_LATITUDE, contact.getLatitude());
        values.put(ContactsContract.COLUMN_NAME_CONTACT_TOTAL_INCOMING_DURATION, contact.getTotalIncomingDuration());
        values.put(ContactsContract.COLUMN_NAME_CONTACT_TOTAL_OUTGOING_DURATION, contact.getTotalOutgoingDuration());
        values.put(ContactsContract.COLUMN_NAME_CONTACT_MISSING_CALLS, contact.getMissingCalls());
        values.put(ContactsContract.COLUMN_NAME_CONTACT_SENT_MESSAGES, contact.getSentMessageCount());
        values.put(ContactsContract.COLUMN_NAME_CONTACT_RECEIVED_MESSAGES, contact.getReceivedMessageCount());
        values.put(ContactsContract.COLUMN_NAME_CONTACT_IS_IN_SPEED_DIAL, contact.isInSpeedDial());

        return values;
    }

    private static ContentValues getMessagesContentValues(Message message){
        ContentValues values = new ContentValues();

        values.put(MessagesContract.COLUMN_NAME_MESSAGE_ID, message.getMessageID());
        values.put(MessagesContract.COLUMN_NAME_REMOTE_PHONE_NUMBER, message.getRemotePhoneNumber());
        values.put(MessagesContract.COLUMN_NAME_IS_FROM_ME, message.isFromMe());
        values.put(MessagesContract.COLUMN_NAME_MESSAGE_TEXT, message.getText());
        values.put(MessagesContract.COLUMN_NAME_MESSAGE_DATE, message.getDate());

        return values;
    }

    private static ContentValues getCallsContentValues(Call call){
        ContentValues values = new ContentValues();

        values.put(CallsContract.COLUMN_NAME_CALL_ID, call.getCallID());
        values.put(CallsContract.COLUMN_NAME_REMOTE_PHONE_NUMBER, call.getPhoneNumber());
        values.put(CallsContract.COLUMN_NAME_IS_FROM_ME, call.isFromMe());
        values.put(CallsContract.COLUMN_NAME_IS_ANSWERED, call.isAnswered());
        values.put(CallsContract.COLUMN_NAME_CALL_DATE, call.getCallDate().getTime());
        values.put(CallsContract.COLUMN_NAME_CALL_DURATION, call.getDuration());

        return values;
    }

    private ContactsCursorWrapper queryContacts(String whereClause, String[] whereArgs, String orderBy) {
        Cursor cursor = mDatabase.query(
                ContactsContract.TABLE_NAME,
                null, // Columns - null selects all columns
                whereClause,
                whereArgs,
                null, // groupBy
                null, // having
                orderBy  // orderBy
        );

        return new ContactsCursorWrapper(cursor);
    }

    private MessagesCursorWrapper queryMessages(String whereClause, String[] whereArgs,
                                                String groupBy, String orderBy) {
        Cursor cursor = mDatabase.query(
                MessagesContract.TABLE_NAME,
                null, // Columns - null selects all columns
                whereClause,
                whereArgs,
                groupBy, // groupBy
                null, // having
                orderBy  // orderBy
        );

        return new MessagesCursorWrapper(cursor);
    }

    private CallsCursorWrapper queryCalls(String whereClause, String[] whereArgs, String orderBy) {
        Cursor cursor = mDatabase.query(
                CallsContract.TABLE_NAME,
                null, // Columns - null selects all columns
                whereClause,
                whereArgs,
                null, // groupBy
                null, // having
                orderBy  // orderBy
        );

        return new CallsCursorWrapper(cursor);
    }

    private static String formatPhoneNumber(String phoneNumber){
        try {
            Phonenumber.PhoneNumber parsedPhoneNumber = mPhoneUtil.parse(phoneNumber, "TR");
            phoneNumber = mPhoneUtil.format(parsedPhoneNumber, PhoneNumberUtil.PhoneNumberFormat.INTERNATIONAL);
        } catch (NumberParseException e) {
            System.err.println("NumberParseException was thrown: " + e.toString());
        }

        // Couldn't format the phone number, pass the original one.
        return phoneNumber;
    }

}
