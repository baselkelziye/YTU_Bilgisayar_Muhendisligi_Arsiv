package ce.yildiz.android.util;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.SharedPreferences;

public class SharedPreferencesUtil {
    private static String theme;

    public static void loadApplicationTheme(Context ctx, String username) {
        final SharedPreferences sharedPreferences = ctx.getSharedPreferences(username,
                Context.MODE_PRIVATE);

        theme = sharedPreferences.getString("theme", Constants.AppThemes.LIGHT);
    }

    @SuppressLint("ApplySharedPref")
    public static void saveApplicationTheme(Context ctx, String username, String theme) {
        final SharedPreferences sharedPreferences = ctx.getSharedPreferences(username, Context.MODE_PRIVATE);
        final SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.clear();
        editor.putString("theme", theme);
        editor.commit();
        loadApplicationTheme(ctx, username);
    }

    public static String getTheme() {
        return theme;
    }
}
