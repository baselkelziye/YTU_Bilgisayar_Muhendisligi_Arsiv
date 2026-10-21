package com.kaansonmezoz.blm3520.homework.Settings;

public class RequestSettings {
    public RequestSettings(){}

    public final int getRequestCodeFor(String request){
        switch(request){
            case "CAMERA":
                return 1;
            case "ALBUM":
                return 2;
            case "PHONE_CALL":
                return 3;
            case "SEND_EMAIL":
                return 4;
            default:
                return 0;
        }
    }
}
