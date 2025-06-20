package com.savt.listopia.model.user;

public enum UserRole {
    ADMIN(2),
    MODERATOR(1),
    USER(0);

    private final int level;

    UserRole(int level) {
        this.level = level;
    }

    public int getLevel() {
        return level;
    }

    public boolean hasAtLeast(UserRole required) {
        return this.level >= required.level;
    }

}
