package com.example.shared_data;

public class TokenData {
    private static TokenData instance;
    private String[] tokens;

    private TokenData() {}

    public static TokenData getInstance() {
        if (instance == null) {
            instance = new TokenData();
        }
        return instance;
    }

    public String[] getSharedData() {
        return tokens;
    }

    public void setSharedData(String[] tokens) {
        this.tokens = tokens;
    }
}
