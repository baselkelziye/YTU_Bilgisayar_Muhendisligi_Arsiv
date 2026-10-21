package com.barissemerci.sanaldolabim;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.ImageDecoder;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.Base64;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class KiyafetSec extends AppCompatActivity {
    ImageView imageViewKiyafet;
    EditText editTextRenk;
    EditText editTextDesen;
    EditText editTextFiyat;
    EditText editTextTarih;
    EditText editTextKiyafetTuru;

    Button buttonKiyafetKaydet;
    Bitmap selectedImage;
    Kiyafet kiyafet;
    int yeniMi=-1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Intent intent= getIntent();
        kiyafet= new Kiyafet();
        yeniMi=intent.getIntExtra("yeniMi",-1);
        setContentView(R.layout.activity_kiyafet_sec);
        _declare();
        if(yeniMi!=-1){
            kiyafet=MainActivity.secilenCekmece.getKiyafetler().get(yeniMi);
            byte[] decodedString = Base64.decode(kiyafet.getFoto(), Base64.DEFAULT);
            Bitmap decodedByte = BitmapFactory.decodeByteArray(decodedString, 0, decodedString.length);
            imageViewKiyafet.setImageBitmap(decodedByte);
            editTextRenk.setText(kiyafet.renk);
            editTextDesen.setText(kiyafet.desen);
            editTextFiyat.setText(kiyafet.fiyat);
            editTextTarih.setText(kiyafet.tarih);
            editTextKiyafetTuru.setText(kiyafet.tur);


            selectedImage=decodedByte;
            buttonKiyafetKaydet.setText("Kıyafeti Güncelle");
        }
        else{
            buttonKiyafetKaydet.setText("Kıyafeti Kaydet");
        }


    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater menuInflater = getMenuInflater();
        menuInflater.inflate(R.menu.kiyafet_menu, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        if (item.getItemId() == R.id.kiyafetiSil) {
            if(yeniMi==-1){
                Toast.makeText(getApplicationContext(), "Kıyafet henüz eklenmedi.", Toast.LENGTH_LONG).show();
            }
            else{
                MainActivity.secilenCekmece.getKiyafetler().remove(yeniMi);
                finish();
                Toast.makeText(getApplicationContext(), "Kıyafet silindi.", Toast.LENGTH_LONG).show();
            }


        }

        return super.onOptionsItemSelected(item);
    }
    private void _declare() {
        imageViewKiyafet=findViewById(R.id.imageViewKiyafet);
        editTextRenk=findViewById(R.id.editTextRenk);
        editTextDesen=findViewById(R.id.editTextDesen);
        editTextFiyat=findViewById(R.id.editTextFiyat);
        editTextTarih=findViewById(R.id.editTextTarih);

        editTextKiyafetTuru=findViewById(R.id.editTextKiyafetTuru);
        buttonKiyafetKaydet=findViewById(R.id.buttonKiyafetKaydet);
    }

    public void cekmeceyeGeriDon() {
        Intent intent=new Intent(getApplicationContext(),CekmeceActivity.class);
        startActivity(intent);
        finish();
    }


    public void kiyafetSec(View view) {
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.READ_EXTERNAL_STORAGE}, 1);
        } else {
            Intent intentToGallery = new Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
            startActivityForResult(intentToGallery, 2);
        }





    }
    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        if (requestCode == 1) {
            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                Intent intentToGallery = new Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
                startActivityForResult(intentToGallery, 2);
            }

        }
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        if (requestCode == 2 && resultCode == RESULT_OK && data != null) {
            Uri imageData = data.getData();
            try {
                if (Build.VERSION.SDK_INT >= 28) {
                    ImageDecoder.Source source = ImageDecoder.createSource(this.getContentResolver(), imageData);
                    selectedImage = ImageDecoder.decodeBitmap(source);
                    imageViewKiyafet.setImageBitmap(selectedImage);

                } else {
                    selectedImage = MediaStore.Images.Media.getBitmap(this.getContentResolver(), imageData);
                    imageViewKiyafet.setImageBitmap(selectedImage);

                }

            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        super.onActivityResult(requestCode, resultCode, data);
    }





    public void kiyafetKaydet(View view) {

        kiyafet.setDesen(editTextDesen.getText().toString());
        kiyafet.setFiyat(editTextFiyat.getText().toString());
        kiyafet.setRenk(editTextRenk.getText().toString());
        kiyafet.setTarih(editTextTarih.getText().toString());
        kiyafet.setTur(editTextKiyafetTuru.getText().toString());
        ByteArrayOutputStream stream = new ByteArrayOutputStream();
        selectedImage.compress(Bitmap.CompressFormat.PNG, 100, stream);
        byte[] byteArray = stream.toByteArray();
        String encoded = Base64.encodeToString(byteArray, Base64.DEFAULT);
        kiyafet.setFoto(encoded);

        System.out.println(kiyafet.toString());
        if(yeniMi==-1){
            MainActivity.secilenCekmece.getKiyafetler().add(kiyafet);
            Toast.makeText(getApplicationContext(),"Yeni kıyafet kaydedildi.",Toast.LENGTH_LONG).show();
        }
        else{
            Toast.makeText(getApplicationContext(),"Kıyafet güncellendi.",Toast.LENGTH_LONG).show();
        }

        cekmeceyeGeriDon();


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