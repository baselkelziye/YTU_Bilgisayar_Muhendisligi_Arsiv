package com.kaansonmezoz.blm3520.notebook.Manager;

public class RequestCodeManager {
    public RequestCodeManager(){

    }

    public int getRequestCodeFor(String request){
        if(request.equals("FILE_EXPLORER")){
            return 1;
        }

        return 0;
    }
}

