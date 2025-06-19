package com.savt.listopia.model;

import com.savt.listopia.exception.APIException;
import lombok.Getter;

import java.util.List;
import java.util.stream.Stream;

@Getter
public enum Category {
    all("all"),
    users("users"),
    movies("movies");

    private final String name;

    Category(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return this.name;
    }

    public static Category fromString(String name) {
        for (Category category : Category.values()) {
            if (category.name.equalsIgnoreCase(name)) {
                return category;
            }
        }
        throw new APIException("invalid_category");
    }

    public static List<Category> all() {
        return Stream.of(Category.values())
                .filter(category -> category != Category.all)
                .toList();
    }

}
