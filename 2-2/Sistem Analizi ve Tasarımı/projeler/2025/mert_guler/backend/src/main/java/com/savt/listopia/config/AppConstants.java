package com.savt.listopia.config;

import java.time.Duration;

public class AppConstants {
    public static final String PAGE_NUMBER = "0";
    public static final String PAGE_SIZE = "30";
    public static final String SORT_MOVIES_BY = "popularity";
    public static final String SORT_DIR = "dsc";

    public static final Duration SESSION_EXPIRY_DURATION = Duration.ofDays(7);
    public static final Long SESSION_EXPIRY_TIME = SESSION_EXPIRY_DURATION.toMillis();
    public static final Float RECAPTCHA_SCORE = 0.5F;
}
