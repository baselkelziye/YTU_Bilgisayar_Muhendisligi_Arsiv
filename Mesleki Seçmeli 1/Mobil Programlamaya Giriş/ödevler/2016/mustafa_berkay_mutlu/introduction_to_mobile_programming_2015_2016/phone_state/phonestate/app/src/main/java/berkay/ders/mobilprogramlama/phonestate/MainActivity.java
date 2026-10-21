package berkay.ders.mobilprogramlama.phonestate;

import android.content.Intent;
import android.os.Handler;
import android.os.ResultReceiver;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import java.text.SimpleDateFormat;
import java.util.Locale;

public class MainActivity extends AppCompatActivity {
    private ImageView imageView_statusIcon;
    private TextView textView_activeTime;
    private TextView textView_passiveTime;
    private SensorResultReceiver mSensorResultReceiver;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mSensorResultReceiver = new SensorResultReceiver(null);

        imageView_statusIcon = (ImageView) findViewById(R.id.imageView_mainActivity_statusIcon);
        textView_activeTime = (TextView) findViewById(R.id.textView_mainActivity_activeTime);
        textView_passiveTime = (TextView) findViewById(R.id.textView_mainActivity_passiveTime);

        justUpdateUI();
    }

    public void button_mainActivity_start_onClick(View view){
        Intent mainServiceIntent = new Intent(this, MainService.class);
        mainServiceIntent.setAction(Config.ACTION_SERVICE_START_LISTENING);
        mainServiceIntent.putExtra(Config.TAG_SENSOR_RESULT_RECEIVER, mSensorResultReceiver);
        startService(mainServiceIntent);
    }

    public void button_mainActivity_stop_onClick(View view){
        Intent mainServiceIntent = new Intent(this, MainService.class);
        mainServiceIntent.setAction(Config.ACTION_SERVICE_STOP_LISTENING);
        mainServiceIntent.putExtra(Config.TAG_SENSOR_RESULT_RECEIVER, mSensorResultReceiver);
        startService(mainServiceIntent);
    }

    public void justUpdateUI(){
        Intent mainServiceIntent = new Intent(this, MainService.class);
        mainServiceIntent.setAction(Config.ACTION_SERVICE_JUST_UPDATE_UI);
        mainServiceIntent.putExtra(Config.TAG_SENSOR_RESULT_RECEIVER, mSensorResultReceiver);
        startService(mainServiceIntent);
    }


    public class SensorResultReceiver extends ResultReceiver{

        public SensorResultReceiver(Handler handler) {
            super(handler);
        }

        @Override
        protected void onReceiveResult(int resultCode, Bundle resultData) {
            if(resultCode == Config.RESULT_CODE_OK){
                long activeTime = resultData.getLong(Config.TAG_ACTIVE_TIME);
                long passiveTime = resultData.getLong(Config.TAG_PASSIVE_TIME);
                float accelerometerValue = resultData.getFloat(Config.TAG_ACCELEROMETER_VALUE);

                runOnUiThread(new UpdateUI(activeTime, passiveTime, accelerometerValue));
            }
        }
    }


    private class UpdateUI implements Runnable{
        long activeTime, passiveTime;
        float accelerometerValue;
        SimpleDateFormat dateFormat = new SimpleDateFormat("s", Locale.ENGLISH);

        public UpdateUI(long activeTime, long passiveTime, float accelerometerValue) {
            this.activeTime = activeTime;
            this.passiveTime = passiveTime;
            this.accelerometerValue = accelerometerValue;
        }

        public void run() {
            textView_activeTime.setText(String.format("%d " + getString(R.string.seconds_short), Integer.parseInt(dateFormat.format(activeTime))));
            textView_passiveTime.setText(String.format("%d " + getString(R.string.seconds_short), Integer.parseInt(dateFormat.format(passiveTime))));

            if(accelerometerValue < Config.ACTIVE_THRESHOLD ){
                imageView_statusIcon.setBackgroundResource(R.drawable.standing);
            } else if(accelerometerValue < Config.VERY_ACTIVE_THRESHOLD ){
                imageView_statusIcon.setBackgroundResource(R.drawable.moving);
            } else{
                imageView_statusIcon.setBackgroundResource(R.drawable.dancing);
            }
        }
    }


}
