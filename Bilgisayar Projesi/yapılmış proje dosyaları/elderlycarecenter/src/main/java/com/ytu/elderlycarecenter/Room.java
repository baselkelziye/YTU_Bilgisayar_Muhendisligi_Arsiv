/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.ytu.elderlycarecenter;

/**
 *
 * @author ohkam
 */
public class Room {
    int id;
    int room_number;

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Room{id=").append(id);
        sb.append(", room_number=").append(room_number);
        sb.append('}');
        return sb.toString();
    }

    public Room(int id, int room_number) {
        this.id = id;
        this.room_number = room_number;
    }

    public Room(int room_number) {
        this.room_number = room_number;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getRoom_number() {
        return room_number;
    }

    public void setRoom_number(int room_number) {
        this.room_number = room_number;
    }
}

