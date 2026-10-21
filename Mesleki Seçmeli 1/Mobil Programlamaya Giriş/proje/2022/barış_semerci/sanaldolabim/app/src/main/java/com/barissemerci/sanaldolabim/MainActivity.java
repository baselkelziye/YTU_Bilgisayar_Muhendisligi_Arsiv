package com.barissemerci.sanaldolabim;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    public static ArrayList<Cekmece> cekmeceler= new ArrayList<>();
    public static ArrayList<Kombin> kombinler= new ArrayList<>();
    public static ArrayList<Etkinlik> etkinlikler= new ArrayList<>();
    Cekmece cekmece;
    public static Cekmece secilenCekmece;
    public static Kombin suAnkiKombin;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        try {
            FileInputStream fileIn = new FileInputStream(getFilesDir() + "/cekmeceler.dat");
            ObjectInputStream objectIn = new ObjectInputStream(fileIn);
            boolean keepReading = true;
            try {
                while (keepReading) {
                    Cekmece cekmece1 = (Cekmece) objectIn.readObject();
                    cekmeceler.add(cekmece1);


                    objectIn = new ObjectInputStream(fileIn);

                }
                objectIn.close();
                fileIn.close();
            } catch (EOFException e) {
                keepReading = false;
            }
        } catch (Exception ex) {
            ex.printStackTrace();

        }





        try {
            FileInputStream fileIn = new FileInputStream(getFilesDir() + "/kombinler.dat");
            ObjectInputStream objectIn = new ObjectInputStream(fileIn);
            boolean keepReading = true;
            try {
                while (keepReading) {
                    Kombin kombin = (Kombin) objectIn.readObject();
                    kombinler.add(kombin);


                    objectIn = new ObjectInputStream(fileIn);

                }
                objectIn.close();
                fileIn.close();
            } catch (EOFException e) {
                keepReading = false;
            }
        } catch (Exception ex) {
            ex.printStackTrace();

        }


        try {
            FileInputStream fileIn = new FileInputStream(getFilesDir() + "/etkinlikler.dat");
            ObjectInputStream objectIn = new ObjectInputStream(fileIn);
            boolean keepReading = true;
            try {
                while (keepReading) {
                    Etkinlik etkinlik = (Etkinlik) objectIn.readObject();
                    etkinlikler.add(etkinlik);


                    objectIn = new ObjectInputStream(fileIn);

                }
                objectIn.close();
                fileIn.close();
            } catch (EOFException e) {
                keepReading = false;
            }
        } catch (Exception ex) {
            ex.printStackTrace();

        }




    }



    public void cekmeceEkle(View view) {
        cekmece=new Cekmece();
        cekmeceler.add(cekmece);
        secilenCekmece=cekmece;
        Intent intent=new Intent(getApplicationContext(),CekmeceActivity.class);
        startActivity(intent);
    }

    public void cekmeceGoster(View view) {
       Intent intent=new Intent(getApplicationContext(),CekmeceleriGor.class);
       intent.putExtra("nereden","main");
        startActivity(intent);
    }

    public void kabineGit(View view) {
        KabinActivity.ilkMi=1;
        KabinActivity.kombinGuncellemeMi=0;
        Intent intent=new Intent(getApplicationContext(),KabinActivity.class);
        startActivity(intent);
    }

    public void etkinligeGit(View view) {
        Intent intent=new Intent(getApplicationContext(),EtkinlikActivity.class);
        EtkinlikActivity.secilenKiyafet=-1;
        startActivity(intent);
    }

    public void kombinlerimiGostereGit(View view) {
        Intent intent=new Intent(getApplicationContext(), KombinleriGor.class);
        startActivity(intent);

    }

    public void etkinlikleriGoster(View view) {
        Intent intent= new Intent(getApplicationContext(), EtkinlikleriGor.class);
        EtkinlikActivity.etkinlikGormeMi=1;
        startActivity(intent);
    }








    @Override
    protected void onStop() {
        super.onStop();
        File f = new File(getFilesDir() + "/cekmeceler.dat");
        f.delete();
        FileOutputStream outStream = null;
        try {

            f = new File(getFilesDir() + "/cekmeceler.dat");

            outStream = new FileOutputStream(f, true);
            ObjectOutputStream objectOutStream = new ObjectOutputStream(outStream);

            for (Cekmece i : cekmeceler) {
                objectOutStream.writeObject(i);
            }

            objectOutStream.close();
        } catch (FileNotFoundException e1) {
            e1.printStackTrace();
        } catch (IOException e1) {
            e1.printStackTrace();
        }


         f = new File(getFilesDir() + "/kombinler.dat");
        f.delete();
        FileOutputStream outStream1 = null;
        try {

            f = new File(getFilesDir() + "/kombinler.dat");

            outStream1 = new FileOutputStream(f, true);
            ObjectOutputStream objectOutStream = new ObjectOutputStream(outStream1);

            for (Kombin i : kombinler) {
                objectOutStream.writeObject(i);
            }

            objectOutStream.close();
        } catch (FileNotFoundException e1) {
            e1.printStackTrace();
        } catch (IOException e1) {
            e1.printStackTrace();
        }


         f = new File(getFilesDir() + "/etkinlikler.dat");
        f.delete();
        FileOutputStream outStream2 = null;
        try {

            f = new File(getFilesDir() + "/etkinlikler.dat");

            outStream2 = new FileOutputStream(f, true);
            ObjectOutputStream objectOutStream = new ObjectOutputStream(outStream2);

            for (Etkinlik i : etkinlikler) {
                objectOutStream.writeObject(i);
            }

            objectOutStream.close();
        } catch (FileNotFoundException e1) {
            e1.printStackTrace();
        } catch (IOException e1) {
            e1.printStackTrace();
        }
























    }
}