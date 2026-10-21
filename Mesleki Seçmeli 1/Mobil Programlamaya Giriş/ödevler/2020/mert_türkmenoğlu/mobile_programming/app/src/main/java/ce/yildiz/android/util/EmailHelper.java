package ce.yildiz.android.util;

import android.content.ActivityNotFoundException;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.util.Log;


public class EmailHelper {
    private static final String TAG = EmailHelper.class.getSimpleName();

    private Context mContext;

    public EmailHelper(Context context) {
        this.mContext = context;
    }

    public void send(String[] to, String subject, String message, Uri file) {
        Intent emailIntent = new Intent(Intent.ACTION_SEND);

        emailIntent.setType("message/rfc822");
        emailIntent.putExtra(Intent.EXTRA_SUBJECT, subject);
        emailIntent.putExtra(Intent.EXTRA_EMAIL, to);
        emailIntent.putExtra(Intent.EXTRA_TEXT, message);

        if (file != null) {
            emailIntent.putExtra(Intent.EXTRA_STREAM, file);
        }

        try {
            mContext.startActivity(Intent.createChooser(emailIntent, "E-MAIL"));
        } catch (ActivityNotFoundException e) {
            Log.e(TAG, "No intent matcher found");
        }
    }
}
