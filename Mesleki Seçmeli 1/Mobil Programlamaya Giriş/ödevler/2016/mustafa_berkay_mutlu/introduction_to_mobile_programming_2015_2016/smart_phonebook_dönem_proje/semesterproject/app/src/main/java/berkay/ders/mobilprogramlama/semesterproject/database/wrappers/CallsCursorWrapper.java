package berkay.ders.mobilprogramlama.semesterproject.database.wrappers;

import android.database.Cursor;
import android.database.CursorWrapper;

import java.util.Date;

import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract.CallsContract;
import berkay.ders.mobilprogramlama.semesterproject.model.Call;

/**
 * Created by mberk on 2.01.2016.
 */
public class CallsCursorWrapper extends CursorWrapper {

    public CallsCursorWrapper(Cursor cursor) {
        super(cursor);
    }

    public Call getCall(){
        long callID = getLong(getColumnIndex(CallsContract.COLUMN_NAME_CALL_ID));
        String remotePhoneNumber = getString(getColumnIndex(CallsContract.COLUMN_NAME_REMOTE_PHONE_NUMBER));
        boolean isFromMe = getInt(getColumnIndex(CallsContract.COLUMN_NAME_IS_FROM_ME)) != 0;
        boolean isAnswered = getInt(getColumnIndex(CallsContract.COLUMN_NAME_IS_ANSWERED)) != 0;
        Date callDate = new Date();
        callDate.setTime(getLong(getColumnIndex(CallsContract.COLUMN_NAME_CALL_DATE)));
        int duration = getInt(getColumnIndex(CallsContract.COLUMN_NAME_CALL_DURATION));

        Call call = new Call();

        call.setCallID(callID);
        call.setPhoneNumber(remotePhoneNumber);
        call.setIsFromMe(isFromMe);
        call.setIsAnswered(isAnswered);
        call.setCallDate(callDate);
        call.setDuration(duration);

        return call;
    }
}
