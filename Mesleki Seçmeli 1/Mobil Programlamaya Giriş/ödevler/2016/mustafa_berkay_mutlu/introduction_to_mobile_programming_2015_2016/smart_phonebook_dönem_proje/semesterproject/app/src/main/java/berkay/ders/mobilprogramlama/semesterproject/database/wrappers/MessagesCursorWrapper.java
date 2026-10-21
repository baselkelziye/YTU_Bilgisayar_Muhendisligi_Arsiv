package berkay.ders.mobilprogramlama.semesterproject.database.wrappers;

import android.database.Cursor;
import android.database.CursorWrapper;

import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract.MessagesContract;
import berkay.ders.mobilprogramlama.semesterproject.model.Message;

/**
 * Created by mberk on 25.12.2015.
 */
public class MessagesCursorWrapper extends CursorWrapper {

    public MessagesCursorWrapper(Cursor cursor) {
        super(cursor);
    }

    public Message getMessage(){
        long messageID = getLong(getColumnIndex(MessagesContract.COLUMN_NAME_MESSAGE_ID));
        String remotePhoneNumber = getString(getColumnIndex(MessagesContract.COLUMN_NAME_REMOTE_PHONE_NUMBER));
        boolean isFromMe = getInt(getColumnIndex(MessagesContract.COLUMN_NAME_IS_FROM_ME)) == 1;
        String text = getString(getColumnIndex(MessagesContract.COLUMN_NAME_MESSAGE_TEXT));
        long date = getLong(getColumnIndex(MessagesContract.COLUMN_NAME_MESSAGE_DATE));

        Message message = new Message();
        message.setMessageID(messageID);
        message.setRemotePhoneNumber(remotePhoneNumber);
        message.setIsFromMe(isFromMe);
        message.setText(text);
        message.setDate(date);

        return message;
    }
}
