package com.savt.listopia.util;

import org.springframework.context.EnvironmentAware;
import org.springframework.core.env.Environment;
import org.springframework.stereotype.Component;

@Component
public class SpringEnvironment implements EnvironmentAware {
    private static Environment environment;

    @Override
    public void setEnvironment(Environment env) {
        environment = env;
    }

    public static boolean isProduction() {
        for (String profile : environment.getActiveProfiles()) {
            if ("prod".equalsIgnoreCase(profile)) {
                return true;
            }
        }
        return false;
    }
}
