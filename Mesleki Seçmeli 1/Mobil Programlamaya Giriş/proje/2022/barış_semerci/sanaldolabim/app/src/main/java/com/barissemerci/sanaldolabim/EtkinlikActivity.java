package com.barissemerci.sanaldolabim;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.util.Base64;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import com.google.android.material.snackbar.Snackbar;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

import static com.barissemerci.sanaldolabim.R.layout;

public class EtkinlikActivity extends AppCompatActivity {
    Etkinlik etkinlik;
    int resimSirasi = -1;
    int etkinlikGuncelle=0;
    public int guncellemeMi = 0;
    public static int secilenKiyafet = -1;
    ImageView imageViewIlk;
    ImageView imageViewIkinci;
    ImageView imageViewUcuncu;
    ImageView imageViewDorduncu;
    ImageView imageViewBesinci;
    ImageView imageViewEtkinligeKiyafetEkle;
    EditText editTextEtkinlikAdi;
    EditText editTextEtkinlikTuru;
    EditText editTextEtkinlikTarihi;
    EditText editTextEtkinlikLokasyonu;
    ImageView degisecekKiyafet;
    private ImageView[] resimler = new ImageView[5];
    private String[] id;
    int etkinlikNumarasi;
    Button buttonEtkinlikEkle;
    public static int etkinlikGormeMi=0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(layout.activity_etkinlik);
        _declare();
        etkinlik = new Etkinlik();

        Intent intent=getIntent();
        etkinlikNumarasi=intent.getIntExtra("etkinlikNumarasi",-1);
        if (etkinlikGormeMi == 1 && etkinlikNumarasi>=0) {
            etkinlik = MainActivity.etkinlikler.get(etkinlikNumarasi);
        }
        int temp;
        id = new String[]{"imageViewIlk", "imageViewIkinci", "imageViewUcuncu", "imageViewDorduncu", "imageViewBesinci"};


        for (int i = 0; i < id.length; i++) {
            temp = getResources().getIdentifier(id[i], "id", getPackageName());
            resimler[i] = findViewById(temp);
        }

        registerForContextMenu(imageViewIlk);
        registerForContextMenu(imageViewBesinci);
        registerForContextMenu(imageViewDorduncu);
        registerForContextMenu(imageViewIkinci);
        registerForContextMenu(imageViewUcuncu);


    }

    public void _declare() {
        buttonEtkinlikEkle=findViewById(R.id.buttonEtkinlikEkle);
        imageViewIlk = findViewById(R.id.imageViewIlk);
        imageViewIkinci = findViewById(R.id.imageViewIkinci);
        imageViewUcuncu = findViewById(R.id.imageViewUcuncu);
        imageViewDorduncu = findViewById(R.id.imageViewDorduncu);
        imageViewBesinci = findViewById(R.id.imageViewBesinci);
        imageViewEtkinligeKiyafetEkle = findViewById(R.id.imageViewEtkinligeKiyafetEkle);
        editTextEtkinlikAdi = findViewById(R.id.editTextEtkinlikAdi);
        editTextEtkinlikTuru = findViewById(R.id.editTextEtkinlikTuru);
        editTextEtkinlikTarihi = findViewById(R.id.editTextEtkinlikTarihi);
        editTextEtkinlikLokasyonu = findViewById(R.id.editTextEtkinlikLokasyonu);
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (secilenKiyafet != -1 && etkinlikGormeMi!=1) {


            if (etkinlik.getKiyafetler().size() < 5) {
                if (guncellemeMi == 1) {
                    guncellemeMi=0;
                    etkinlik.getKiyafetler().set(resimSirasi, MainActivity.secilenCekmece.getKiyafetler().get(secilenKiyafet));

                } else {
                    etkinlik.getKiyafetler().add(MainActivity.secilenCekmece.getKiyafetler().get(secilenKiyafet));

                }
                for (int i = 0; i < etkinlik.getKiyafetler().size(); i++) {
                    System.out.print(etkinlik.getKiyafetler().get(i).getTur()+ " ");
                }

                System.out.println("Liste boyutu" + etkinlik.getKiyafetler().size());

                for (int i = 0; i <= etkinlik.getKiyafetler().size() - 1; i++) {
                    resimler[i].setVisibility(View.VISIBLE);
                    byte[] decodedString = Base64.decode(etkinlik.getKiyafetler().get(i).getFoto(), Base64.DEFAULT);
                    Bitmap decodedByte = BitmapFactory.decodeByteArray(decodedString, 0, decodedString.length);
                    resimler[i].setImageBitmap(decodedByte);
                }

            } else {
                Snackbar.make(findViewById(R.id.etkinlikActivity), "En fazla 5 kıyafet yükleyebilirsiniz.", Snackbar.LENGTH_LONG).show();
            }

        }
        if(etkinlikGormeMi==1){
            for (int i = 0; i <= etkinlik.getKiyafetler().size() - 1; i++) {
                resimler[i].setVisibility(View.VISIBLE);
                byte[] decodedString = Base64.decode(etkinlik.getKiyafetler().get(i).getFoto(), Base64.DEFAULT);
                Bitmap decodedByte = BitmapFactory.decodeByteArray(decodedString, 0, decodedString.length);
                resimler[i].setImageBitmap(decodedByte);
                etkinlikGormeMi=0;
            }
            editTextEtkinlikAdi.setText(etkinlik.getIsim());
            editTextEtkinlikLokasyonu.setText(etkinlik.getLokasyon());
            editTextEtkinlikTarihi.setText(etkinlik.getTarih());
            editTextEtkinlikTuru.setText(etkinlik.getTur());
            buttonEtkinlikEkle.setText("Güncelle");
            etkinlikGuncelle=1;
        }


    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater menuInflater = getMenuInflater();
        menuInflater.inflate(R.menu.etkinlik_menu, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        if (item.getItemId() == R.id.etkinligiSil) {
            MainActivity.etkinlikler.remove(etkinlik);
            finish();
            Toast.makeText(getApplicationContext(), "Etkinlik silindi.", Toast.LENGTH_LONG).show();
        }

        return super.onOptionsItemSelected(item);
    }

    public void etkinligeResimEkle(View view) {

        if (MainActivity.secilenCekmece == null) {
            Toast.makeText(getApplicationContext(), "Hiç kıyafetiniz yok!", Toast.LENGTH_LONG).show();
        } else {

            Intent intent = new Intent(getApplicationContext(), CekmeceleriGor.class);
            intent.putExtra("nereden", "etkinlik");
            startActivity(intent);
            for (int i = 0; i <= etkinlik.getKiyafetler().size() - 1; i++) {
                resimler[i].setVisibility(View.VISIBLE);
                byte[] decodedString = Base64.decode(etkinlik.getKiyafetler().get(i).getFoto(), Base64.DEFAULT);
                Bitmap decodedByte = BitmapFactory.decodeByteArray(decodedString, 0, decodedString.length);
                resimler[i].setImageBitmap(decodedByte);
            }
        }


    }

    @Override
    public boolean onContextItemSelected(@NonNull MenuItem item) {
        switch (degisecekKiyafet.getId()) {
            case R.id.imageViewIlk:
                resimSirasi = 0;
                break;
            case R.id.imageViewIkinci:
                resimSirasi = 1;
                break;
            case R.id.imageViewUcuncu:
                resimSirasi = 2;
                break;
            case R.id.imageViewDorduncu:
                resimSirasi = 3;
                break;
            case R.id.imageViewBesinci:
                resimSirasi = 4;
                break;
        }


        switch (item.getItemId()) {


            case R.id.etkinliktenKiyafetSil:
                if (MainActivity.secilenCekmece == null) {
                    Toast.makeText(getApplicationContext(), "Hiç kıyafetiniz yok!", Toast.LENGTH_LONG).show();
                } else {
                    Toast.makeText(getApplicationContext(), "Kyafet silindi.", Toast.LENGTH_LONG).show();
                    etkinlik.getKiyafetler().remove(resimSirasi);
                    for (int i = 0; i < etkinlik.getKiyafetler().size(); i++) {
                        System.out.println(etkinlik.getKiyafetler().get(i).getTur());
                    }
                    System.out.println("Liste boyutu" + etkinlik.getKiyafetler().size());

                    resimler[etkinlik.getKiyafetler().size()].setVisibility(View.INVISIBLE);
                    for (int i = 0; i <= etkinlik.getKiyafetler().size() - 1; i++) {
                        resimler[i].setVisibility(View.VISIBLE);
                        byte[] decodedString = Base64.decode(etkinlik.getKiyafetler().get(i).getFoto(), Base64.DEFAULT);
                        Bitmap decodedByte = BitmapFactory.decodeByteArray(decodedString, 0, decodedString.length);
                        resimler[i].setImageBitmap(decodedByte);
                    }
                }

                break;
            case R.id.etkinliktetiKiyafetiGuncelle:


                if (MainActivity.secilenCekmece == null) {
                    Toast.makeText(getApplicationContext(), "Hiç kıyafetiniz yok!", Toast.LENGTH_LONG).show();
                } else {
                    Intent intent = new Intent(getApplicationContext(), CekmeceleriGor.class);
                    intent.putExtra("nereden", "etkinlik");
                    startActivity(intent);
                    guncellemeMi = 1;
                    System.out.println("Liste boyutu" + etkinlik.getKiyafetler().size());
                    for (int i = 0; i < etkinlik.getKiyafetler().size(); i++) {
                        System.out.println(etkinlik.getKiyafetler().get(i).getTur());
                    }
                }
                break;
        }
        return super.onContextItemSelected(item);
    }

    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {

        super.onCreateContextMenu(menu, v, menuInfo);

        getMenuInflater().inflate(R.menu.kiyafeti_guncelle_sil_menu, menu);
        degisecekKiyafet = (ImageView) v;
    }


    public void etkinlikEkle(View view) {
        etkinlik.setIsim(editTextEtkinlikAdi.getText().toString());
        etkinlik.setLokasyon(editTextEtkinlikLokasyonu.getText().toString());
        etkinlik.setTarih(editTextEtkinlikTarihi.getText().toString());
        etkinlik.setTur(editTextEtkinlikTuru.getText().toString());
        if(etkinlikGuncelle==1){

            MainActivity.etkinlikler.set(etkinlikNumarasi,etkinlik);
            Toast.makeText(getApplicationContext(), "Etkinlik güncellendi!", Toast.LENGTH_LONG).show();

        }
        else{
            MainActivity.etkinlikler.add(etkinlik);
            Toast.makeText(getApplicationContext(), "Etkinlik eklendi!", Toast.LENGTH_LONG).show();
        }
        finish();
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