package ce.yildiz.android.util;

import android.app.AlarmManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.widget.Toast;

import java.util.Calendar;

import ce.yildiz.android.R;
import ce.yildiz.android.services.SoundAlertReceiver;

public class NotificationUtil {
    public static boolean startSound(Context ctx, Calendar c, int requestCode) {
        AlarmManager alarmManager = (AlarmManager) ctx.getSystemService(Context.ALARM_SERVICE);
        Intent intent = new Intent(ctx, SoundAlertReceiver.class);
        PendingIntent pendingIntent = PendingIntent.getBroadcast(
                ctx,
                requestCode,
                intent,
                0
        );

        if (c.before(Calendar.getInstance())) {
            Toast.makeText(ctx, R.string.invalid_time, Toast.LENGTH_SHORT).show();
            return false;
        }

        if (alarmManager == null) return false;

        alarmManager.setExact(AlarmManager.RTC_WAKEUP, c.getTimeInMillis(), pendingIntent);
        return true;
    }

    public static void cancelSound(Context ctx, int requestCode) {
        AlarmManager alarmManager = (AlarmManager) ctx.getSystemService(Context.ALARM_SERVICE);
        Intent intent = new Intent(ctx, SoundAlertReceiver.class);
        PendingIntent pendingIntent = PendingIntent.getBroadcast(
                ctx,
                requestCode,
                intent,
                0
        );

        if (alarmManager == null) return;

        alarmManager.cancel(pendingIntent);
    }
}
