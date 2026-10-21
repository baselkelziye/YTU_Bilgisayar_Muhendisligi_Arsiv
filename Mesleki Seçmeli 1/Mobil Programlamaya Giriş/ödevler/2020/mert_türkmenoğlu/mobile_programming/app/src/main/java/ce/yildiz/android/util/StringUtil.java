package ce.yildiz.android.util;

import androidx.annotation.NonNull;

public class StringUtil {
    public static String composeImageUrl(@NonNull String username) {
        return Constants.GITHUB_BASE_URL  + username + Constants.IMAGE_EXTENSION;
    }
}
