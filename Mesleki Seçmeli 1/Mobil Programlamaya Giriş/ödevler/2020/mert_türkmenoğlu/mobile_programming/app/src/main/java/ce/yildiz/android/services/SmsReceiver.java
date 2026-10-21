package ce.yildiz.android.services;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.telephony.SmsMessage;
import android.util.Log;
import android.widget.Toast;

import androidx.annotation.NonNull;

import java.io.FileOutputStream;
import java.text.DateFormat;
import java.util.ArrayList;
import java.util.Calendar;

import ce.yildiz.android.R;
import ce.yildiz.android.interfaces.CommunicationLogger;
import ce.yildiz.android.util.Constants;

public class SmsReceiver extends BroadcastReceiver implements CommunicationLogger {
    private static final String SMS_ACTION = "android.provider.Telephony.SMS_RECEIVED";
    private static final String TAG = SmsReceiver.class.getSimpleName();
    private static final String OUTPUT_FILE = SmsReceiver.class.getSimpleName() + ".txt";

    @SuppressWarnings("deprecation")
    @Override
    public void onReceive(Context context, Intent intent) {
        String action = intent.getAction();

        if (action == null) {
            Toast.makeText(context,
                    R.string.invalid_intent_error_message, Toast.LENGTH_LONG).show();
            return;
        }

        if (action.equals(SMS_ACTION)) {
            Bundle bundle = intent.getExtras();
            Log.d(TAG, context.getString(R.string.sms_receive_ok_message));

            if (bundle == null) return;

            Object[] pduArr = (Object[]) bundle.get("pdus");

            if (pduArr == null) return;

            ArrayList<SmsMessage> smsMessages = new ArrayList<>(pduArr.length);

            for (int i = 0; i < pduArr.length; i++) {
                smsMessages.add(SmsMessage.createFromPdu((byte[]) pduArr[i]));
                Calendar c = Calendar.getInstance();

                String dateStr = DateFormat.getDateInstance(DateFormat.DEFAULT).format(c.getTime());

                String msg = "Phone Number: "
                        + smsMessages.get(i).getDisplayOriginatingAddress();

                String smsBody = smsMessages.get(i).getMessageBody();

                msg += "\nMessage: " + smsBody.substring(0,
                        Math.min(smsBody.length() - 1, Constants.MAX_CONTENT_LENGTH));

                msg += "...";
                msg += "\nDate: " + dateStr;

                Toast.makeText(context, msg, Toast.LENGTH_LONG).show();
                Log.d(TAG, "onReceive: " + msg);
                writeContent(context, OUTPUT_FILE, msg);
            }

            return;
        }

        Log.e(TAG, "onReceive: Sms receive toast message failed");
    }

    @Override
    public void writeContent(@NonNull Context context, @NonNull String file, String content) {
        try{
            FileOutputStream stream = context.openFileOutput(file, Context.MODE_APPEND);
            stream.write((content + "\n").getBytes());
            stream.close();
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
