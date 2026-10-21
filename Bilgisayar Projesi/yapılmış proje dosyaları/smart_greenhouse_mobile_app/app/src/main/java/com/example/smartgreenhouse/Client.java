package com.example.smartgreenhouse;

import android.os.AsyncTask;
import android.util.Log;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

import static android.net.Uri.encode;

public class Client extends AsyncTask<Void, Void, Void> {

    private int HEADER_SIZE = 64;

    private Socket s;
    private String ip;
    private int port;

    private boolean shouldLoop;
    private boolean shouldQuit;
    private boolean active;
    private int waitForResponse = 0;
    private int waitResponseFor = 0;
    private int waitForACK = 0;

    private String message = "";
    private boolean shouldSend = false;

    BufferedReader in;
    PrintWriter pw;

    public int gCode = -1;
    public int temperature = -1;
    public int goal = -1;


    @Override
    protected Void doInBackground(Void... voids) {
        try {
            s = new Socket(ip, port);
        } catch (IOException e) {
            e.printStackTrace();
            Log.i("[SMARTGREENHOUSE]", "COULD NOT CONNECT");
            return null;
        }

        while (shouldLoop) {
            //Log.i("[SMARTGREENHOUSE]", "LOOP STARTS");

            try {
                in = new BufferedReader(new InputStreamReader (s.getInputStream()), 64);
                //Log.i("[SMARTGREENHOUSE]", "HOLDING");
                String fromServer = in.readLine();
                //Log.i("[SMARTGREENHOUSE]", "PASSED");
                if (fromServer.length()>0){
                    Log.i("[SMARTGREENHOUSE]", "RECEIVED " + fromServer);
                    if (!fromServer.equals("RCVD")){
                        //Log.i("[SMARTGREENHOUSE]", "PARSING " + fromServer);
                        parseServerResponse(fromServer);
                        if ((waitForResponse>0)&&(waitResponseFor==gCode)){
                            waitForResponse -= 1;
                        }
                        Log.i("[SMARTGREENHOUSE]", "PARSED " + fromServer);
                    } else{
                        if (waitForACK > 0) {
                            waitForACK -= 1;
                        }
                    }
                }
            }
            catch (Exception e) {
                Log.i("[SMARTGREENHOUSE]", "ERROR [2]");
                e.printStackTrace();
            }


            try {
                if (shouldSend){
                    pw = new PrintWriter(s.getOutputStream());
                    String sendLength = encode(String.valueOf(message.length()));
                    String blanks = "";
                    int i;
                    for (i = 0; i < (HEADER_SIZE - sendLength.length()); i++) {
                        blanks = blanks + " ";
                    }
                    sendLength = sendLength + blanks;
                    pw.write(sendLength);
                    pw.flush();
                    pw = new PrintWriter(s.getOutputStream());
                    pw.write(message);
                    pw.flush();
                    Log.i("[SMARTGREENHOUSE]", "SENDING " + message);
                    shouldSend = false;
                    if (shouldQuit) {
                        shouldLoop = false;
                    }
                }
            } catch (Exception e) {
                Log.i("[SMARTGREENHOUSE]", "ERROR [1]");
                e.printStackTrace();
            }
        }
        try{
            in.close();
            pw.close();
            s.close();
        } catch (Exception e){
            Log.i("[SMARTGREENHOUSE]", "IMPORTANT ERROR [3]");
            e.printStackTrace();
        }
        this.active = false;
        return null;
    }

    public void parseServerResponse(String msg){
        String grCode = "";
        String goal = "";
        String temp = "";
        int idx = 0;
        Character c = msg.charAt(idx);
        while (c != '.'){
            grCode = grCode + c;
            idx += 1;
            c = msg.charAt(idx);
        }
        idx += 1;
        c = msg.charAt(idx);
        while (c != '.'){
            goal = goal + c;
            idx += 1;
            c = msg.charAt(idx);
        }
        idx += 1;
        c = msg.charAt(idx);
        while (c != '-'){
            temp = temp + c;
            idx += 1;
            c = msg.charAt(idx);
        }
        this.gCode = Integer.parseInt(grCode);
        this.temperature = Integer.parseInt(temp);
        this.goal = Integer.parseInt(goal);
    }


    public void setPortIp(String ip, String port) {
        this.ip = ip;
        this.port = Integer.parseInt(port);
    }

    public void send(String message){
        this.message = encode(message);
        this.shouldSend = true;
    }

    public void turnOn() {
        this.shouldLoop = true;
        this.active = true;
    }

    public void turnOff() {
        this.shouldSend = true;
        this.message = encode("!DISCONNECT");
        this.shouldQuit = true;
    }

    public boolean isActive(){
        return this.active;
    }

    public void waitRespond(int gh){
        this.waitResponseFor = gh;
        this.waitForResponse = 1;
    }

    public boolean isWaitingResponse(){
        return (waitForResponse == 1);
    }

    public void waitACK(){
        this.waitForACK = 1;
    }

    public boolean isWaitingACK(){
        return (waitForACK == 1);
    }

    public String getMessage() {
        return message;
    }
}
