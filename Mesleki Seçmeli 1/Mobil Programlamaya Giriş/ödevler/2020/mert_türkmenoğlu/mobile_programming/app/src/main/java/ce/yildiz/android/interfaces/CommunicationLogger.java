package ce.yildiz.android.interfaces;

import android.content.Context;

import androidx.annotation.NonNull;

public interface CommunicationLogger {
    void writeContent(@NonNull Context context, @NonNull String file, String content);
}
