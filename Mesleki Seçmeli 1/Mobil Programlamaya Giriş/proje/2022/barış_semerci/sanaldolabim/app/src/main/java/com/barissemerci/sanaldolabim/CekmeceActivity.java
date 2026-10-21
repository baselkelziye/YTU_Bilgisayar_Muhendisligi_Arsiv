package com.barissemerci.sanaldolabim;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.util.Base64;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import com.google.android.material.snackbar.Snackbar;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class CekmeceActivity extends AppCompatActivity {
    EditText editTextCekmeceAdi;
    ImageView imageViewBirinciKiyafet;
    ImageView imageViewIkinciKiyafet;
    ImageView imageViewUcuncuKiyafet;
    ImageView imageViewDorduncuKiyafet;
    ImageView imageViewBesinciKiyafet;
    ImageView imageViewAltinciKiyafet;
    ImageView imageViewYedinciKiyafet;
    ImageView imageViewSekizinciKiyafet;
    ImageView imageViewDokuzuncuKiyafet;
    ImageView imageViewOnuncuKiyafet;
    ImageView imageViewOnBirinciKiyafet;
    ImageView imageViewOnIkinciKiyafet;
    private ImageView[] resimler = new ImageView[12];
    private String[] id;
    Cekmece cekmece;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cekmece);
        _declare();
        cekmece = MainActivity.secilenCekmece;
        if(cekmece.getIsim()==null){
            editTextCekmeceAdi.setText("Benim Çekmecem");
        }
        else{
            editTextCekmeceAdi.setText(cekmece.getIsim());
        }



        int temp;
        id = new String[]{"imageViewBirinciKiyafet", "imageViewIkinciKiyafet", "imageViewUcuncuKiyafet", "imageViewDorduncuKiyafet"
                , "imageViewBesinciKiyafet", "imageViewAltinciKiyafet", "imageViewYedinciKiyafet", "imageViewSekizinciKiyafet"
                , "imageViewDokuzuncuKiyafet", "imageViewOnuncuKiyafet", "imageViewOnBirinciKiyafet", "imageViewOnIkinciKiyafet"};


        for (int i = 0; i < id.length; i++) {
            temp = getResources().getIdentifier(id[i], "id", getPackageName());
            resimler[i] = findViewById(temp);
        }




        System.out.println(cekmece.getKiyafetler().size());
        if (cekmece.getKiyafetler().size() != 0) {
            for (int i = 0; i < cekmece.getKiyafetler().size(); i++) {
                resimler[i].setVisibility(View.VISIBLE);
                byte[] decodedString = Base64.decode(cekmece.getKiyafetler().get(i).getFoto(), Base64.DEFAULT);
                Bitmap decodedByte = BitmapFactory.decodeByteArray(decodedString, 0, decodedString.length);
                resimler[i].setImageBitmap(decodedByte);
            }

        }


    }

    public void _declare() {
        editTextCekmeceAdi = findViewById(R.id.editTextCekmeceAdi);
        imageViewBirinciKiyafet = findViewById(R.id.imageViewBirinciKiyafet);
        imageViewIkinciKiyafet = findViewById(R.id.imageViewIkinciKiyafet);
        imageViewUcuncuKiyafet = findViewById(R.id.imageViewUcuncuKiyafet);
        imageViewDorduncuKiyafet = findViewById(R.id.imageViewDorduncuKiyafet);
        imageViewBesinciKiyafet = findViewById(R.id.imageViewBesinciKiyafet);
        imageViewAltinciKiyafet = findViewById(R.id.imageViewAltinciKiyafet);
        imageViewYedinciKiyafet = findViewById(R.id.imageViewYedinciKiyafet);
        imageViewSekizinciKiyafet = findViewById(R.id.imageViewSekizinciKiyafet);
        imageViewDokuzuncuKiyafet = findViewById(R.id.imageViewDokuzuncuKiyafet);
        imageViewOnuncuKiyafet = findViewById(R.id.imageViewOnuncuKiyafet);
        imageViewOnBirinciKiyafet = findViewById(R.id.imageViewOnBirinciKiyafet);
        imageViewOnIkinciKiyafet = findViewById(R.id.imageViewOnIkinciKiyafet);


    }


    public void kiyafetSecGit(View view) {
        cekmece.setIsim(editTextCekmeceAdi.getText().toString());
        Intent intent = new Intent(getApplicationContext(), KiyafetSec.class);
        intent.putExtra("yeniMi", -1);
        startActivity(intent);
        finish();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater menuInflater = getMenuInflater();
        menuInflater.inflate(R.menu.cekmece_menu, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        if (item.getItemId() == R.id.cekmeceyiSil) {
            MainActivity.cekmeceler.remove(cekmece);
            finish();
            Toast.makeText(getApplicationContext(), "Çekmece silindi.", Toast.LENGTH_LONG).show();
        }

        return super.onOptionsItemSelected(item);
    }

    public void kiyafeteGit(View view) {
      int hangi=-1;

        switch (view.getId()) {
            case R.id.imageViewBirinciKiyafet:
                hangi=0;
                break;
            case R.id.imageViewIkinciKiyafet:
                hangi=1;
                break;
            case R.id.imageViewUcuncuKiyafet:
                hangi=2;
                break;
            case R.id.imageViewDorduncuKiyafet:
                hangi=3;
                break;
            case R.id.imageViewBesinciKiyafet:
                hangi=4;
                break;
            case R.id.imageViewAltinciKiyafet:
                hangi=5;
                break;
            case R.id.imageViewYedinciKiyafet:
                hangi=6;
                break;
            case R.id.imageViewSekizinciKiyafet:
                hangi=7;
                break;
            case R.id.imageViewDokuzuncuKiyafet:
                hangi=8;
                break;
            case R.id.imageViewOnuncuKiyafet:
                hangi=9;
                break;
            case R.id.imageViewOnBirinciKiyafet:
                hangi=10;
                break;
            case R.id.imageViewOnIkinciKiyafet:
                hangi=11;
                break;
        }
        Intent intent = new Intent(getApplicationContext(), KiyafetSec.class);

        intent.putExtra("yeniMi", hangi);

        startActivity(intent);
        finish();


    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        cekmece.setIsim(editTextCekmeceAdi.getText().toString());





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