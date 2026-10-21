package com.example.blm3520_hw1;

import android.content.SharedPreferences;

import java.util.Comparator;

public class User {

    private int id;

    public int getId() { return id; }

    public void setId(int id) { this.id = id; }

    private String name, description, image;

    public User(int id, String name, String description, String image) {
        this.id = id;
        this.name = name;
        this.description = description;
        this.image = image;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }

    public static final Comparator<User> BY_NAME_ASCENDING = new Comparator<User>() {
        @Override
        public int compare(User o1, User o2) {
            return o1.getName().compareTo(o2.getName());
        }
    };

    public static final Comparator<User> BY_NAME_DESCENDING = new Comparator<User>() {
        @Override
        public int compare(User o1, User o2) {
            return o2.getName().compareTo(o1.getName());
        }
    };
}
