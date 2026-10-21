package com.barissemerci.sanaldolabim;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.util.Base64;
import android.view.View;
import android.widget.ImageView;


import com.barissemerci.sanaldolabim.R;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class CekmecedekiKiyafetler extends AppCompatActivity {

    ImageView imageViewKabin1;
    ImageView imageViewKabin2;
    ImageView imageViewKabin3;
    ImageView imageViewKabin4;
    ImageView imageViewKabin5;
    ImageView imageViewKabin6;
    ImageView imageViewKabin7;
    ImageView imageViewKabin8;
    ImageView imageViewKabin9;
    ImageView imageViewKabin10;
    ImageView imageViewKabin11;
    ImageView imageViewKabin12;
    String nereden;

    private ImageView[] resimler = new ImageView[12];
    private String[] id;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cekmecedeki_kiyafetler);
        _declare();
        EtkinlikActivity.secilenKiyafet=-1;
        Intent intent = getIntent();
        nereden=intent.getStringExtra("nereden");

        int temp;
        id = new String[]{"imageViewKabin1", "imageViewKabin2", "imageViewKabin3", "imageViewKabin4"
                , "imageViewKabin5", "imageViewKabin6", "imageViewKabin7", "imageViewKabin8"
                , "imageViewKabin9", "imageViewKabin10", "imageViewKabin11", "imageViewKabin12"};


        for (int i = 0; i < id.length; i++) {
            temp = getResources().getIdentifier(id[i], "id", getPackageName());
            resimler[i] = findViewById(temp);
        }


        if (MainActivity.secilenCekmece.getKiyafetler().size() != 0) {
            for (int i = 0; i < MainActivity.secilenCekmece.getKiyafetler().size(); i++) {
                resimler[i].setVisibility(View.VISIBLE);
                byte[] decodedString = Base64.decode(MainActivity.secilenCekmece.getKiyafetler().get(i).getFoto(), Base64.DEFAULT);
                Bitmap decodedByte = BitmapFactory.decodeByteArray(decodedString, 0, decodedString.length);
                resimler[i].setImageBitmap(decodedByte);
            }

        }


    }

    private void _declare() {
        imageViewKabin1 = findViewById(R.id.imageViewKabin1);
        imageViewKabin2 = findViewById(R.id.imageViewKabin2);
        imageViewKabin3 = findViewById(R.id.imageViewKabin3);
        imageViewKabin4 = findViewById(R.id.imageViewKabin4);
        imageViewKabin5 = findViewById(R.id.imageViewKabin5);
        imageViewKabin6 = findViewById(R.id.imageViewKabin6);
        imageViewKabin7 = findViewById(R.id.imageViewKabin7);
        imageViewKabin8 = findViewById(R.id.imageViewKabin8);
        imageViewKabin9 = findViewById(R.id.imageViewKabin9);
        imageViewKabin10 = findViewById(R.id.imageViewKabin10);
        imageViewKabin11 = findViewById(R.id.imageViewKabin11);
        imageViewKabin12 = findViewById(R.id.imageViewKabin12);


    }

    public void kabineKiyafetEkle(View view) {

        if(nereden.equals("etkinlik")){


            switch (view.getId()) {
                case R.id.imageViewKabin1:

                    EtkinlikActivity.secilenKiyafet = 0;

                    break;
                case R.id.imageViewKabin2:
                    EtkinlikActivity.secilenKiyafet = 1;
                    break;
                case R.id.imageViewKabin3:
                    EtkinlikActivity.secilenKiyafet = 2;
                    break;
                case R.id.imageViewKabin4:
                    EtkinlikActivity.secilenKiyafet = 3;
                    break;
                case R.id.imageViewKabin5:
                    EtkinlikActivity.secilenKiyafet = 4;
                    break;
                case R.id.imageViewKabin6:
                    EtkinlikActivity.secilenKiyafet = 5;
                    break;
                case R.id.imageViewKabin7:
                    EtkinlikActivity.secilenKiyafet = 6;
                    break;
                case R.id.imageViewKabin8:
                    EtkinlikActivity.secilenKiyafet = 7;
                    break;
                case R.id.imageViewKabin9:
                    EtkinlikActivity.secilenKiyafet = 8;
                    break;
                case R.id.imageViewKabin10:
                    EtkinlikActivity.secilenKiyafet = 9;
                    break;
                case R.id.imageViewKabin11:
                    EtkinlikActivity.secilenKiyafet = 10;
                    break;
                case R.id.imageViewKabin12:
                    EtkinlikActivity.secilenKiyafet = 11;
                    break;


            }
finish();








        }
else{


            KabinActivity.ilkMi = 0;
            switch (view.getId()) {
                case R.id.imageViewKabin1:

                    KabinActivity.secilenKiyafet = 0;

                    break;
                case R.id.imageViewKabin2:
                    KabinActivity.secilenKiyafet = 1;
                    break;
                case R.id.imageViewKabin3:
                    KabinActivity.secilenKiyafet = 2;
                    break;
                case R.id.imageViewKabin4:
                    KabinActivity.secilenKiyafet = 3;
                    break;
                case R.id.imageViewKabin5:
                    KabinActivity.secilenKiyafet = 4;
                    break;
                case R.id.imageViewKabin6:
                    KabinActivity.secilenKiyafet = 5;
                    break;
                case R.id.imageViewKabin7:
                    KabinActivity.secilenKiyafet = 6;
                    break;
                case R.id.imageViewKabin8:
                    KabinActivity.secilenKiyafet = 7;
                    break;
                case R.id.imageViewKabin9:
                    KabinActivity.secilenKiyafet = 8;
                    break;
                case R.id.imageViewKabin10:
                    KabinActivity.secilenKiyafet = 9;
                    break;
                case R.id.imageViewKabin11:
                    KabinActivity.secilenKiyafet = 10;
                    break;
                case R.id.imageViewKabin12:
                    KabinActivity.secilenKiyafet = 11;
                    break;
            }
            finish();


        }
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

            for (Cekmece i : MainActivity.cekmeceler) {
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

            for (Kombin i : MainActivity.kombinler) {
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

            for (Etkinlik i : MainActivity.etkinlikler) {
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