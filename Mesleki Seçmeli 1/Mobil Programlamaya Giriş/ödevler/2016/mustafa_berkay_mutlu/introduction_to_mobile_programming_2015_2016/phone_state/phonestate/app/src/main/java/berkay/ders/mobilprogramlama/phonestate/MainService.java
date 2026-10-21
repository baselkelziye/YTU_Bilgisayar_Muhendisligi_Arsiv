package berkay.ders.mobilprogramlama.phonestate;

import android.app.Notification;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.content.res.Resources;
import android.graphics.BitmapFactory;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.os.IBinder;
import android.os.ResultReceiver;
import android.util.Log;

import java.util.Timer;
import java.util.TimerTask;

/**
 * Created by mberk on 21.12.2015.
 */
public class MainService extends Service implements SensorEventListener {
    private boolean isListening;
    private SensorManager senSensorManager;
    private Sensor senAccelerometer;
    private long lastUpdate;
    private float last_x, last_y, last_z;
    private Timer mTimer;
    private long mActiveTime, mPassiveTime;
    private float mSpeed;
    private ResultReceiver mSensorResultReceiver;
    private UpdateUITimerTask updateUITimerTask;


    @Override
    public void onCreate() {
        super.onCreate();

        senSensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        senAccelerometer = senSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
    }


    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {

        if(intent != null && intent.getAction() != null) {
            mSensorResultReceiver = intent.getParcelableExtra(Config.TAG_SENSOR_RESULT_RECEIVER);

            String action = intent.getAction();
            if (action.equals(Config.ACTION_SERVICE_START_LISTENING))
                startListening();
            else if (action.equals(Config.ACTION_SERVICE_STOP_LISTENING))
                stopListening();
            else if (action.equals(Config.ACTION_SERVICE_JUST_UPDATE_UI))
                justUpdateUI();

        }

        Intent intent2 = new Intent(this, MainActivity.class);
        intent2.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);
        PendingIntent pendingIntent = PendingIntent.getActivity(this, 0, intent2, 0);

        Resources res = getApplicationContext().getResources();

        Notification noti = new Notification.Builder(getApplicationContext())
                .setContentTitle(getString(R.string.app_name))
                .setContentText(getString(R.string.notification_ticker))
                .setLargeIcon(BitmapFactory.decodeResource(res, R.drawable.dancing))
                .setSmallIcon(R.drawable.dancing)
                .setTicker(getString(R.string.notification_message))
                .setContentIntent(pendingIntent)
                .setAutoCancel(false)
                .build();

        startForeground(Config.NOTIFICATION_ID, noti);

        return START_NOT_STICKY;
    }

    private void justUpdateUI() {
        Log.d("MainService", "Just updating the UI. IsListening: " + String.valueOf(isListening));
    }

    private void startListening() {
        if (!isListening) {
            updateUITimerTask = new UpdateUITimerTask();
            mTimer = new Timer();
            lastUpdate = System.currentTimeMillis();
            senSensorManager.registerListener(this, senAccelerometer, SensorManager.SENSOR_DELAY_NORMAL);
            mTimer.scheduleAtFixedRate(updateUITimerTask, 0, Config.UI_UPDATE_INTERVAL);
            isListening = true;

            Log.d("MainService", "Started listening the accelerometer sensor. ");
        }
    }

    private void stopListening() {
        if(isListening) {
            senSensorManager.unregisterListener(this);
            updateUITimerTask.cancel();
            mTimer.cancel();
            mActiveTime = 0;
            mPassiveTime = 0;
            isListening = false;
            stopSelf();

            Log.d("MainService", "Stopped listening the accelerometer sensor. ");
        }
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        senSensorManager.unregisterListener(this);
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onSensorChanged(SensorEvent sensorEvent) {
        float x = sensorEvent.values[0];
        float y = sensorEvent.values[1];
        float z = sensorEvent.values[2];

        long curTime = System.currentTimeMillis();

        long diffTime = (curTime - lastUpdate);
        lastUpdate = curTime;

        double euclideanDistance = Math.sqrt(Math.pow((x - last_x), 2)
                + Math.pow((y - last_y), 2)
                + Math.pow((z - last_z), 2));

        Log.d("Euclidean Distance", String.valueOf(euclideanDistance));

        if (euclideanDistance > Config.ACTIVE_THRESHOLD) {
            mActiveTime += diffTime;
            mSpeed = (float) euclideanDistance;
        }
        else{
            mPassiveTime += diffTime;
            mSpeed = (float) euclideanDistance;
        }

        last_x = x;
        last_y = y;
        last_z = z;
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {
        Log.d("MainService", "onAccuracyChanged");
    }

    private class UpdateUITimerTask extends TimerTask
    {
        @Override
        public void run() {
            Bundle bundle = new Bundle();
            bundle.putLong(Config.TAG_ACTIVE_TIME, mActiveTime);
            bundle.putLong(Config.TAG_PASSIVE_TIME, mPassiveTime);
            bundle.putFloat(Config.TAG_ACCELEROMETER_VALUE, mSpeed);
            mSensorResultReceiver.send(Config.RESULT_CODE_OK, bundle);
        }
    }
}
