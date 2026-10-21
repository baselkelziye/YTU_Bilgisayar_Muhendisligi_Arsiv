package ce.yildiz.android.ui.download;

import android.annotation.SuppressLint;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.View;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;

import java.util.Calendar;
import java.util.Random;

import ce.yildiz.android.R;
import ce.yildiz.android.databinding.ActivityDownloadBinding;
import ce.yildiz.android.ui.download.fragments.DownloadCompleteDialogFragment;
import ce.yildiz.android.util.Constants;
import ce.yildiz.android.util.NotificationUtil;
import ce.yildiz.android.util.SharedPreferencesUtil;

public class DownloadActivity extends AppCompatActivity {
    public static final int MAX_PROGRESS = 100;
    public static final int MIN_PROGRESS = 0;
    private ActivityDownloadBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        if (SharedPreferencesUtil.getTheme().equals(Constants.AppThemes.DARK)) {
            setTheme(R.style.DarkTheme);
        } else {
            setTheme(R.style.AppTheme);
        }

        super.onCreate(savedInstanceState);
        binding = ActivityDownloadBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        binding.downloadProgressBar.setMax(MAX_PROGRESS);

        binding.downloadDownloadButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                binding.downloadProgressBar.setProgress(MIN_PROGRESS);
                download();
            }
        });
    }

    private void download() {
        new DummyBackgroundTask().execute(MAX_PROGRESS);
    }

    private void showDownloadCompleteDialog() {
        FragmentManager fm = getSupportFragmentManager();
        DownloadCompleteDialogFragment downloadCompleteDialogFragment =
                DownloadCompleteDialogFragment.newInstance(R.drawable.ic_file_download_accent_48dp);

        downloadCompleteDialogFragment.show(fm,
                DownloadCompleteDialogFragment.class.getSimpleName());
    }

    @SuppressLint("StaticFieldLeak")
    public class DummyBackgroundTask extends AsyncTask<Integer, Integer, Integer> {
        private static final int REQUEST_CODE = 1;
        private static final int DELAY_MILLIS = 3000;
        private static final int SLEEP_MILLIS = 1000;
        private static final int MAX_BOUND = 10;
        private final String TAG = DummyBackgroundTask.class.getSimpleName();
        private int progress;

        @Override
        protected void onPreExecute() {
            super.onPreExecute();
            progress = 0;
        }

        @Override
        protected Integer doInBackground(Integer... args) {
            final int progressLimit = args[0];

            while (progress <= progressLimit) {
                try {
                    Log.d(TAG, "doInBackground: Progress " + progress + "%");
                    Thread.sleep(SLEEP_MILLIS);
                    publishProgress(progress);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                progress += new Random().nextInt(MAX_BOUND);
            }

            return progress;
        }

        @Override
        protected void onProgressUpdate(Integer... values) {
            super.onProgressUpdate(values);

            String status = "Download: " + values[0] + "%";

            binding.downloadStatusText.setText(status);
            binding.downloadProgressBar.setProgress(progress);
        }

        @Override
        protected void onPostExecute(Integer result) {
            super.onPostExecute(result);
            Calendar c = Calendar.getInstance();
            c.set(Calendar.MINUTE, c.get(Calendar.MINUTE) + 1);

            NotificationUtil.startSound(DownloadActivity.this, c, REQUEST_CODE);

            new Handler().postDelayed(new Runnable() {
                @Override
                public void run() {
                    NotificationUtil.cancelSound(DownloadActivity.this, REQUEST_CODE);
                }
            }, DELAY_MILLIS);

            String status = "Download: " + MAX_PROGRESS + "%";

            binding.downloadStatusText.setText(status);
            binding.downloadProgressBar.setProgress(MAX_PROGRESS);
            
            showDownloadCompleteDialog();
        }
    }
}
