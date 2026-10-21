package com.example.ytumezunandroidapp;

public class AnnouncementModel {

    // Her duyuru; görsel, başlık ve tarih içermektedir
    public int image;
    public String header;
    public String text;
    public String date;
    public String user;

    public AnnouncementModel(int image, String header, String text, String date, String user){
        this.image = image;
        this.header = header;
        this.text = text;
        this.date = date;
        this.user = user;
    }
}