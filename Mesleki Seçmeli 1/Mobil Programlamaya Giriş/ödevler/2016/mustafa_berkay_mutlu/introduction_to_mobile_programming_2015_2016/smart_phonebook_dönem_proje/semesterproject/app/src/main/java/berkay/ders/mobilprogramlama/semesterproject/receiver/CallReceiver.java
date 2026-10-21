package berkay.ders.mobilprogramlama.semesterproject.receiver;

import android.content.Context;
import android.content.Intent;

import java.util.Date;

import berkay.ders.mobilprogramlama.semesterproject.Config;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseOperations;
import berkay.ders.mobilprogramlama.semesterproject.model.Call;
import berkay.ders.mobilprogramlama.semesterproject.model.Contact;

/**
 * Created by mberk on 5.01.2016.
 */
public class CallReceiver extends PhoneCallReceiver {

    @Override
    public void onReceive(Context context, Intent intent) {
        super.onReceive(context, intent);

        // Broadcast an Intent for updating the UI.
        Intent callEventOccurred = new Intent();
        callEventOccurred.setAction(Config.CustomEvents.CallEventOccurred.toString());
        context.sendBroadcast(callEventOccurred);
    }

    @Override
    protected void onIncomingCallEnded(Context context, String number, Date start, Date end) {
        Call call = new Call();
        call.setPhoneNumber(number);
        call.setCallDate(start);
        call.setIsAnswered(true);
        call.setIsFromMe(false);
        call.setDuration((int) (end.getTime() - start.getTime()) / 1000);

        DatabaseOperations databaseOperations = DatabaseOperations.get(context);
        databaseOperations.addNewCall(call);

        // Update the contact if it has record in the phonebook
        Contact contact = databaseOperations.getContact(number);
        if(contact != null){
            contact.setTotalIncomingDuration(contact.getTotalIncomingDuration()+call.getDuration());
            databaseOperations.updateContact(contact);
        }
    }

    @Override
    protected void onOutgoingCallEnded(Context context, String number, Date start, Date end) {
        Call call = new Call();
        call.setPhoneNumber(number);
        call.setCallDate(start);
        call.setIsAnswered(true);
        call.setIsFromMe(true);
        call.setDuration((int) (end.getTime() - start.getTime()) / 1000);

        DatabaseOperations databaseOperations = DatabaseOperations.get(context);
        databaseOperations.addNewCall(call);

        // Update the contact if it has record in the phonebook
        Contact contact = databaseOperations.getContact(number);
        if(contact != null){
            contact.setTotalOutgoingDuration(contact.getTotalOutgoingDuration() + call.getDuration());
            databaseOperations.updateContact(contact);
        }
    }

    @Override
    protected void onMissedCall(Context context, String number, Date start) {
        Call call = new Call();
        call.setPhoneNumber(number);
        call.setCallDate(start);
        call.setIsAnswered(false);
        call.setIsFromMe(false);
        call.setDuration(0);

        DatabaseOperations databaseOperations = DatabaseOperations.get(context);
        databaseOperations.addNewCall(call);

        // Update the contact if it has record in the phonebook
        Contact contact = databaseOperations.getContact(number);
        if (contact != null) {
            contact.setMissingCalls(contact.getMissingCalls()+1);
            databaseOperations.updateContact(contact);
        }
    }

}
