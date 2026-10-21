package berkay.ders.mobilprogramlama.semesterproject.receiver;


import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.telephony.SmsMessage;
import android.util.Log;

import berkay.ders.mobilprogramlama.semesterproject.Config;
import berkay.ders.mobilprogramlama.semesterproject.R;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseOperations;
import berkay.ders.mobilprogramlama.semesterproject.model.Contact;
import berkay.ders.mobilprogramlama.semesterproject.model.Message;

/**
 * Created by mberk on 23.12.2015.
 */
public class SMSReceiver extends BroadcastReceiver {
    private static final String LOG_TAG = "SMSReceiver";

    @Override
    public void onReceive(Context context, Intent intent) {

        DatabaseOperations databaseOperations = DatabaseOperations.get(context);

        Bundle bundle = intent.getExtras();

        Object[] pdus = (Object[]) bundle.get("pdus");

        // TODO createFromPdu icerisinde format da olacak.
        SmsMessage message = SmsMessage.createFromPdu((byte[]) pdus[0]);

        PendingIntent pendingIntent = PendingIntent.getActivity(context, 0, intent, PendingIntent.FLAG_ONE_SHOT);

        String content = String.format("%s: %s", context.getString(R.string.incoming_sms_notification_ticker), message.getDisplayMessageBody());
        Log.d(LOG_TAG, content);

        Notification noti = new Notification.Builder(context)
                .setContentTitle(context.getString(R.string.app_name))
                .setContentText(content)
                .setSmallIcon(R.drawable.ic_launcher)
                .setTicker(content.length() > 100 ? (content.substring(0, 100) + "...") : content)
                .setContentIntent(pendingIntent)
                .setAutoCancel(true)
                .build();

        NotificationManager mNotificationManager =
                (NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);
        mNotificationManager.notify(Config.NOTIFICATION_ID, noti);

        Message message1 = new Message();
        message1.setRemotePhoneNumber(message.getOriginatingAddress());
        message1.setIsFromMe(false);
        message1.setText(message.getMessageBody());
        message1.setDate(message.getTimestampMillis());

        databaseOperations.addNewMessage(message1);

        // Update the contact if it has record in the phonebook
        Contact contact = databaseOperations.getContact(message.getOriginatingAddress());
        if(contact != null){
            contact.setReceivedMessageCount(contact.getReceivedMessageCount() + 1);
            databaseOperations.updateContact(contact);
        }

        // Broadcast an Intent for updating the UI.
        Intent smsEventOccurred = new Intent();
        smsEventOccurred.setAction(Config.CustomEvents.SmsEventOccurred.toString());
        context.sendBroadcast(smsEventOccurred);
    }
}
