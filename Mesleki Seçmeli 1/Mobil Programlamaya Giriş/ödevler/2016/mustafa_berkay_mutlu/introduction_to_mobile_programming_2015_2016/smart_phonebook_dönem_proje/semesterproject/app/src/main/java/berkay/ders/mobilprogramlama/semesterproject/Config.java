package berkay.ders.mobilprogramlama.semesterproject;

/**
 * Created by mberk on 25.12.2015.
 */
public class Config {

    public static final int NOTIFICATION_ID = 1;

    public static final String TAG_IS_NEW_MESSAGE = "is_new_message";

    public static final String TAG_PACKAGE_NAME = "berkay.ders.mobilprogramlama.semesterproject";

    public enum CustomEvents{
        SmsEventOccurred("SmsEventOccurred"),
        CallEventOccurred("CallEventOccurred"),
        ContactUpdated("ContactUpdated"),
        ContactsListChanged("ContactsListChanged"),
        SpeedDialUpdated("SpeedDialUpdated");

        private String name;

        CustomEvents(String name){
            this.name = String.format("%s.%s", TAG_PACKAGE_NAME, name);
        }

        public String toString(){
            return name;
        }
    }

}
