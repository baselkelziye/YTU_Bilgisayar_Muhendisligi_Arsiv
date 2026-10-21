package berkay.ders.mobilprogramlama.semesterproject.model;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Locale;

/**
 * Created by mberk on 25.12.2015.
 */
public class Message {
    private long messageID;
    private String remotePhoneNumber;
    private boolean isFromMe;
    private String text;
    private long date;

    public long getMessageID() {
        return messageID;
    }

    public void setMessageID(long messageID) {
        this.messageID = messageID;
    }

    public String getRemotePhoneNumber() {
        return remotePhoneNumber;
    }

    public void setRemotePhoneNumber(String remotePhoneNumber) {
        this.remotePhoneNumber = remotePhoneNumber;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public long getDate() {
        return date;
    }

    public void setDate(long date) {
        this.date = date;
    }

    public boolean isFromMe() {
        return isFromMe;
    }

    public void setIsFromMe(boolean isFromMe) {
        this.isFromMe = isFromMe;
    }

    public String getDateDisplayString(){
        SimpleDateFormat dateFormat1 = new SimpleDateFormat("dd-MM-yyyy");
        SimpleDateFormat dateFormat2 = new SimpleDateFormat("h:mm a");

        Calendar calToday = Calendar.getInstance();
        // set the calendar to start of today
        calToday.set(Calendar.HOUR_OF_DAY, 0);
        calToday.set(Calendar.MINUTE, 0);
        calToday.set(Calendar.SECOND, 0);
        calToday.set(Calendar.MILLISECOND, 0);

        Date date = new Date(this.date);
        Calendar calDate = Calendar.getInstance();
        calDate.setTime(date);

        if(date.before(calToday.getTime())){
            Calendar calAWeekAgo = Calendar.getInstance();
            calAWeekAgo.add(Calendar.DATE, -7); // Set one week ago.
            //calAWeekAgo.set(Calendar.WEEK_OF_YEAR, calToday.get(Calendar.WEEK_OF_YEAR) - 1);

            if(date.before(calAWeekAgo.getTime())){
                return dateFormat1.format(date);
            } else{
                return calDate.getDisplayName(Calendar.DAY_OF_WEEK, Calendar.LONG, Locale.ENGLISH);
            }

        } else{
            return dateFormat2.format(date);
        }

    }
}
