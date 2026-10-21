package ce.yildiz.android.models;

import android.provider.BaseColumns;

public class UserContract {
    private UserContract() {

    }

    public static final class UserEntry implements BaseColumns {
        public static final String TABLE_NAME = "users";
        public static final String COLUMN_USER_NAME = "username";
        public static final String COLUMN_EMAIL = "email";
        public static final String COLUMN_PASSWORD = "password";
        public static final String COLUMN_IMAGE_URL = "image_url";
    }
}
