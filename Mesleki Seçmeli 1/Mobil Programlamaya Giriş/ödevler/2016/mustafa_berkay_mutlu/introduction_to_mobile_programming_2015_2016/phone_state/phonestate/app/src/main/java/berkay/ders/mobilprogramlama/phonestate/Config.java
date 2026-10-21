package berkay.ders.mobilprogramlama.phonestate;

/**
 * Created by mberk on 22.12.2015.
 */
public class Config {
    public static final String APP_PACKAGE_NAME = "berkay.ders.mobilprogramlama.phonestate";
    public static final int NOTIFICATION_ID = 5500;

    public static final String ACTION_SERVICE_START_LISTENING = APP_PACKAGE_NAME + ".StartListening";
    public static final String ACTION_SERVICE_STOP_LISTENING = APP_PACKAGE_NAME + ".StopListening";
    public static final String ACTION_SERVICE_JUST_UPDATE_UI = APP_PACKAGE_NAME + ".JustUpdateUI";


    public static final String TAG_SENSOR_RESULT_RECEIVER = "SensorResultReceiver";
    public static final String TAG_ACTIVE_TIME = "active_time";
    public static final String TAG_PASSIVE_TIME = "passive_time";
    public static final String TAG_ACCELEROMETER_VALUE = "accelerometer_value";

    public static final int RESULT_CODE_OK = 200;

    public static final int UI_UPDATE_INTERVAL = 200;

    public static final int ACTIVE_THRESHOLD = 3;
    public static final int VERY_ACTIVE_THRESHOLD = 6;


}
