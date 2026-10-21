package ce.yildiz.android.util;

@SuppressWarnings("WeakerAccess")
public final class Constants {
    public static final int MIN_PASSWORD_LENGTH = 6;

    public static final String MAP_BASE_URL = "https://www.google.com/maps/search/?api=1&query=";
    public static final int PERMISSION_ID = 44;

    public static final int DEFAULT_HEIGHT = 170;
    public static final int DEFAULT_WEIGHT = 80;
    public static final int DEFAULT_AGE = 18;

    public static final String GITHUB_BASE_URL = "https://github.com/";
    public static final String IMAGE_EXTENSION = ".png";
    public static final float EPSILON = 1.0F;
    public static final long DISCONNECT_TIMEOUT = 5000;
    public static final int MAX_CONTENT_LENGTH = 10;

    public static final class AppThemes {
        public static final String DARK = "Dark";
        public static final String LIGHT = "Light";
    }

    public static final class SettingsFields {
        public static final String GENDER = "gender";
        public static final String HEIGHT = "height";
        public static final String WEIGHT = "weight";
        public static final String AGE = "age";
        public static final String THEME = "theme";
    }

    @SuppressWarnings("unused")
    public static final class GenderOptions {
        public static final String MALE = "Male";
        public static final String FEMALE = "Female";
        public static final String NON_BINARY = "Non-binary";
    }
}
