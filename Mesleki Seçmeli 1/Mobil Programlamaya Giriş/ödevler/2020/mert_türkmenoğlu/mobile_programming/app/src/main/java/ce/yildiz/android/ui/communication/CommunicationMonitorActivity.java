package ce.yildiz.android.ui.communication;

import android.content.Context;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

import ce.yildiz.android.R;
import ce.yildiz.android.databinding.ActivityCommunicationMonitorBinding;
import ce.yildiz.android.interfaces.CommunicationReader;
import ce.yildiz.android.services.SmsReceiver;
import ce.yildiz.android.util.Constants;
import ce.yildiz.android.util.SharedPreferencesUtil;

public class CommunicationMonitorActivity extends AppCompatActivity implements CommunicationReader {
    private static final String INPUT_FILE = SmsReceiver.class.getSimpleName() + ".txt";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        if (SharedPreferencesUtil.getTheme().equals(Constants.AppThemes.DARK)) {
            setTheme(R.style.DarkTheme);
        } else {
            setTheme(R.style.AppTheme);
        }

        super.onCreate(savedInstanceState);

        ActivityCommunicationMonitorBinding binding =
                ActivityCommunicationMonitorBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        String content = readContent(this, INPUT_FILE);

        if (content == null) {
            binding.communicationContent.setText(R.string.no_sms_message);
        } else {
            binding.communicationContent.setText(content);
        }
    }

    @Override
    public String readContent(@NonNull Context context, @NonNull String file) {
        try{
            FileInputStream stream = context.openFileInput(file);
            BufferedReader reader = new BufferedReader(new InputStreamReader(stream));
            StringBuilder content = new StringBuilder();

            String line;

            while((line=reader.readLine()) != null){
                content.append(line).append("\n");
            }

            stream.close();

            return content.toString();
        } catch (Exception e){
            e.printStackTrace();
        }

        return null;
    }
}
