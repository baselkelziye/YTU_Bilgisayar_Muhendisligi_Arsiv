package ce.yildiz.android.services;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.widget.Toast;

import androidx.annotation.NonNull;

import java.io.FileOutputStream;
import java.text.DateFormat;
import java.util.Calendar;

import ce.yildiz.android.R;
import ce.yildiz.android.interfaces.CommunicationLogger;

public class PhoneCallReceiver extends BroadcastReceiver implements CommunicationLogger {
    private static final String PHONE_CALL_ACTION = "android.intent.action.PHONE_STATE";
    private static final String TAG = PhoneCallReceiver.class.getSimpleName();
    private static final String OUTPUT_FILE = PhoneCallReceiver.class.getSimpleName() + ".txt";

    @Override
    public void onReceive(Context context, Intent intent) {
        String action = intent.getAction();

        if (action == null) {
            Toast.makeText(context,
                    R.string.invalid_intent_error_message, Toast.LENGTH_LONG).show();
            return;
        }

        if (action.equals(PHONE_CALL_ACTION)) {
            try {
                Bundle bundle = intent.getExtras();

                if (bundle == null) return;

                String phoneNumber = bundle.getString("incoming_number");
                String state = intent.getExtras().getString(TelephonyManager.EXTRA_STATE);

                if (phoneNumber == null || state == null) return;

                if (state.equals(TelephonyManager.EXTRA_STATE_RINGING)) {
                    Calendar c = Calendar.getInstance();
                    String dateFormatted = DateFormat
                            .getDateInstance(DateFormat.DEFAULT).format(c.getTime());

                    String msg = "Phone Number: " + phoneNumber;
                    msg += "Date: " + dateFormatted;

                    Toast.makeText(context, msg, Toast.LENGTH_LONG).show();
                    Log.d(TAG, "onReceive: " + msg);
                    writeContent(context, OUTPUT_FILE, msg);
                }

                return;
            } catch (Exception e) {
                Toast.makeText(context, R.string.exception, Toast.LENGTH_LONG).show();
                e.printStackTrace();
            }
        }

        Log.e(TAG, "onReceive: Phone call toast message failed");
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
