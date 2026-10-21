package berkay.ders.mobilprogramlama.semesterproject.database;

import android.provider.BaseColumns;

/**
 * Created by mberk on 14.12.2015.
 */
public class DatabaseContract {

    public DatabaseContract() {
    }

    /* Inner class that defines the table contents */
    public static abstract class ContactsContract implements BaseColumns {
        public static final String TABLE_NAME = "contacts";
        public static final String COLUMN_NAME_CONTACT_ID = "contact_id";
        public static final String COLUMN_NAME_CONTACT_FIRST_NAME = "contact_name";
        public static final String COLUMN_NAME_CONTACT_SURNAME = "contact_surname";
        public static final String COLUMN_NAME_CONTACT_PHONE_NUMBER = "contact_phone_number";
        public static final String COLUMN_NAME_CONTACT_EMAIL = "contact_email";
        public static final String COLUMN_NAME_CONTACT_LONGITUDE = "contact_longitude";
        public static final String COLUMN_NAME_CONTACT_LATITUDE = "contact_latitude";
        public static final String COLUMN_NAME_CONTACT_TOTAL_INCOMING_DURATION = "contact_incoming_duration";
        public static final String COLUMN_NAME_CONTACT_TOTAL_OUTGOING_DURATION = "contact_outgoing_duration";
        public static final String COLUMN_NAME_CONTACT_MISSING_CALLS = "contact_missing_calls";
        public static final String COLUMN_NAME_CONTACT_SENT_MESSAGES = "contact_sent_messages";
        public static final String COLUMN_NAME_CONTACT_RECEIVED_MESSAGES = "contact_received_messages";
        public static final String COLUMN_NAME_CONTACT_IS_IN_SPEED_DIAL = "is_in_speed_dial";
    }

    public static abstract class MessagesContract implements BaseColumns {
        public static final String TABLE_NAME = "messages";
        public static final String COLUMN_NAME_MESSAGE_ID = "message_id";
        public static final String COLUMN_NAME_REMOTE_PHONE_NUMBER = "remote_phone_number";
        public static final String COLUMN_NAME_IS_FROM_ME = "is_from_me";
        public static final String COLUMN_NAME_MESSAGE_TEXT = "message_text";
        public static final String COLUMN_NAME_MESSAGE_DATE = "message_date";
    }

    public static abstract class CallsContract implements BaseColumns {
        public static final String TABLE_NAME = "calls";
        public static final String COLUMN_NAME_CALL_ID = "call_id";
        public static final String COLUMN_NAME_REMOTE_PHONE_NUMBER = "remote_phone_number";
        public static final String COLUMN_NAME_IS_FROM_ME = "is_from_me";
        public static final String COLUMN_NAME_IS_ANSWERED = "is_answered";
        public static final String COLUMN_NAME_CALL_DATE = "call_date";
        public static final String COLUMN_NAME_CALL_DURATION = "call_duration";
    }


}
