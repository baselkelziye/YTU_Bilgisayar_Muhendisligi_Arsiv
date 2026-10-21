package berkay.ders.mobilprogramlama.semesterproject.database.wrappers;

import android.database.Cursor;
import android.database.CursorWrapper;

import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract.ContactsContract;
import berkay.ders.mobilprogramlama.semesterproject.model.Contact;

/**
 * Created by mberk on 14.12.2015.
 */
public class ContactsCursorWrapper extends CursorWrapper {

    public ContactsCursorWrapper(Cursor cursor) {
        super(cursor);
    }

    public Contact getContact(){
        long contactID = getLong(getColumnIndex(ContactsContract.COLUMN_NAME_CONTACT_ID));
        String name = getString(getColumnIndex(ContactsContract.COLUMN_NAME_CONTACT_FIRST_NAME));
        String surname = getString(getColumnIndex(ContactsContract.COLUMN_NAME_CONTACT_SURNAME));
        String phone_number = getString(getColumnIndex(ContactsContract.COLUMN_NAME_CONTACT_PHONE_NUMBER));
        String email = getString(getColumnIndex(ContactsContract.COLUMN_NAME_CONTACT_EMAIL));
        double longitude = getDouble(getColumnIndex(ContactsContract.COLUMN_NAME_CONTACT_LONGITUDE));
        double latitude = getDouble(getColumnIndex(ContactsContract.COLUMN_NAME_CONTACT_LATITUDE));
        long totalIncomingDuration = getLong(getColumnIndex(ContactsContract.COLUMN_NAME_CONTACT_TOTAL_INCOMING_DURATION));
        long totalOutgoingDuration = getLong(getColumnIndex(ContactsContract.COLUMN_NAME_CONTACT_TOTAL_OUTGOING_DURATION));
        int missingCalls = getInt(getColumnIndex(ContactsContract.COLUMN_NAME_CONTACT_MISSING_CALLS));
        int sentMessages = getInt(getColumnIndex(ContactsContract.COLUMN_NAME_CONTACT_SENT_MESSAGES));
        int receivedMessages = getInt(getColumnIndex(ContactsContract.COLUMN_NAME_CONTACT_RECEIVED_MESSAGES));

        Contact contact = new Contact();

        contact.setContactID(contactID);
        contact.setName(name);
        contact.setSurname(surname);
        contact.setPhoneNumber(phone_number);
        contact.seteMail(email);
        contact.setLongitude(longitude);
        contact.setLatitude(latitude);
        contact.setTotalIncomingDuration(totalIncomingDuration);
        contact.setTotalOutgoingDuration(totalOutgoingDuration);
        contact.setMissingCalls(missingCalls);
        contact.setSentMessageCount(sentMessages);
        contact.setReceivedMessageCount(receivedMessages);

        return contact;
    }

}
