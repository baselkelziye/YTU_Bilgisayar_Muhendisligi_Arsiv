package com.savt.listopia.model.movie.image;

public enum MovieImageType {
    BACKDROP(1),
    POSTER(2),
    LOGO(3),
    PROFILES(4);

    private final int id;

    MovieImageType(int id){
        this.id = id;
    }

    public int getId() {
        return id;
    }
}
