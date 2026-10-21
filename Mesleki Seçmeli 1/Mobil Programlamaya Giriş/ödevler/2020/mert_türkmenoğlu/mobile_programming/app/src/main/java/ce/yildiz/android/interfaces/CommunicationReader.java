package ce.yildiz.android.interfaces;

import android.content.Context;

import androidx.annotation.NonNull;

public interface CommunicationReader {
    String readContent(@NonNull Context context, @NonNull String file);
}
