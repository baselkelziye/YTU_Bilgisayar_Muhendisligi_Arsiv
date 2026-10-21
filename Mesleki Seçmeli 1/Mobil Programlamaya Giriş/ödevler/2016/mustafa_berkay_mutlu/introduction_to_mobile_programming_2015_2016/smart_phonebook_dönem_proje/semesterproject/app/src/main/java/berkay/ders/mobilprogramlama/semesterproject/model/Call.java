package berkay.ders.mobilprogramlama.semesterproject.model;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Locale;

/**
 * Created by mberk on 29.12.2015.
 */
public class Call {

    private long callID;
    private String phoneNumber;
    private boolean isFromMe;
    private boolean isAnswered;
    private Date callDate;
    private int duration; // Call duration in seconds.

    public long getCallID() {
        return callID;
    }

    public void setCallID(long callID) {
        this.callID = callID;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public boolean isFromMe() {
        return isFromMe;
    }

    public void setIsFromMe(boolean isFromMe) {
        this.isFromMe = isFromMe;
    }

    public boolean isAnswered() {
        return isAnswered;
    }

    public void setIsAnswered(boolean isAnswered) {
        this.isAnswered = isAnswered;
    }

    public Date getCallDate() {
        return callDate;
    }

    public void setCallDate(Date callDate) {
        this.callDate = callDate;
    }

    public int getDuration() {
        return duration;
    }

    public void setDuration(int duration) {
        this.duration = duration;
    }

    public String getDisplayCallDate(){
        SimpleDateFormat dateFormat1 = new SimpleDateFormat("dd-MM-yyyy");
        SimpleDateFormat dateFormat2 = new SimpleDateFormat("h:mm a");

        Calendar calToday = Calendar.getInstance();
        // set the calendar to start of today
        calToday.set(Calendar.HOUR_OF_DAY, 0);
        calToday.set(Calendar.MINUTE, 0);
        calToday.set(Calendar.SECOND, 0);
        calToday.set(Calendar.MILLISECOND, 0);

        Calendar calDate = Calendar.getInstance();
        calDate.setTime(callDate);

        if(callDate.before(calToday.getTime())){
            Calendar calAWeekAgo = Calendar.getInstance();
            calAWeekAgo.add(Calendar.DATE, -7); // Set one week ago.
            //calAWeekAgo.set(Calendar.WEEK_OF_YEAR, calToday.get(Calendar.WEEK_OF_YEAR) - 1);

            if(callDate.before(calAWeekAgo.getTime())){
                return dateFormat1.format(callDate);
            } else{
                return calDate.getDisplayName(Calendar.DAY_OF_WEEK, Calendar.LONG, Locale.ENGLISH);
            }

        } else{
            return dateFormat2.format(callDate);
        }

    }
}
