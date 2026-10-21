package com.barissemerci.sanaldolabim;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.os.StrictMode;
import android.text.InputType;
import android.util.Base64;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class KabinActivity extends AppCompatActivity {
    ImageView imageViewGozluk;
    ImageView imageViewSapka;
    ImageView imageViewAyakkabiSol;
    ImageView imageViewAyakkabiSag;
    ImageView imageViewTshirt;
    ImageView imageViewPantolon;
    Kombin kombin;
    Bitmap ekranGoruntusu;
    int kombinNumarasi;
    private String m_Text = "";
    public static int secilenKiyafet;
    public static int ilkMi = 1;
    public static int kombinGuncellemeMi;
    int hangi = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_kabin);
        _declare();
        kombin = new Kombin();
        Kiyafet kiyafetBasustu=new Kiyafet();
        Kiyafet kiyafetSurat=new Kiyafet();
        Kiyafet kiyafetAyak=new Kiyafet();
        Kiyafet kiyafetUstBeden=new Kiyafet();
        Kiyafet kiyafetAltBeden=new Kiyafet();

        ByteArrayOutputStream stream = new ByteArrayOutputStream();
        Bitmap icon = BitmapFactory.decodeResource(getApplicationContext().getResources(), R.drawable.sapka);
        icon.compress(Bitmap.CompressFormat.PNG, 100, stream);
       byte[] byteArray = stream.toByteArray();
         String encoded = Base64.encodeToString(byteArray, Base64.DEFAULT);
         kombin.setBasustu(kiyafetBasustu);
       kombin.getBasustu().setFoto(encoded);

         stream = new ByteArrayOutputStream();
         icon = BitmapFactory.decodeResource(getApplicationContext().getResources(), R.drawable.gozluk);
        icon.compress(Bitmap.CompressFormat.PNG, 100, stream);
        byteArray = stream.toByteArray();
         encoded = Base64.encodeToString(byteArray, Base64.DEFAULT);
         kombin.setSurat(kiyafetSurat);
        kombin.getSurat().setFoto(encoded);

         stream = new ByteArrayOutputStream();
         icon = BitmapFactory.decodeResource(getApplicationContext().getResources(), R.drawable.tshirt);
        icon.compress(Bitmap.CompressFormat.PNG, 100, stream);
         byteArray = stream.toByteArray();
         encoded = Base64.encodeToString(byteArray, Base64.DEFAULT);
         kombin.setUstBeden(kiyafetUstBeden);
        kombin.getUstBeden().setFoto(encoded);

         stream = new ByteArrayOutputStream();
         icon = BitmapFactory.decodeResource(getApplicationContext().getResources(), R.drawable.pantolon);
        icon.compress(Bitmap.CompressFormat.PNG, 100, stream);
        byteArray = stream.toByteArray();
         encoded = Base64.encodeToString(byteArray, Base64.DEFAULT);
         kombin.setAltBeden(kiyafetAltBeden);
        kombin.getAltBeden().setFoto(encoded);

         stream = new ByteArrayOutputStream();
         icon = BitmapFactory.decodeResource(getApplicationContext().getResources(), R.drawable.ayakkabi);
        icon.compress(Bitmap.CompressFormat.PNG, 100, stream);
        byteArray = stream.toByteArray();
        encoded = Base64.encodeToString(byteArray, Base64.DEFAULT);
        kombin.setAyak(kiyafetAyak);
        kombin.getAyak().setFoto(encoded);










        Intent intent = getIntent();
        kombinNumarasi = intent.getIntExtra("kombinNumarasi", -1);

        if (kombinGuncellemeMi == 1) {
            kombin = MainActivity.kombinler.get(kombinNumarasi);
        }
        MainActivity.suAnkiKombin = kombin;
    }


    private void _declare() {
        imageViewSapka = findViewById(R.id.imageViewSapka);
        imageViewPantolon = findViewById(R.id.imageViewPantolon);
        imageViewTshirt = findViewById(R.id.imageViewTshirt);
        imageViewAyakkabiSag = findViewById(R.id.imageViewAyakkabiSag);
        imageViewAyakkabiSol = findViewById(R.id.imageViewAyakkabiSol);
        imageViewGozluk = findViewById(R.id.imageViewGozluk);

    }

    @Override
    protected void onResume() {
        super.onResume();
        System.out.println("ilkMi" + ilkMi);
        if (ilkMi == 0) {
            byte[] decodedString = Base64.decode(MainActivity.secilenCekmece.getKiyafetler().get(KabinActivity.secilenKiyafet).getFoto(), Base64.DEFAULT);
            Bitmap decodedByte = BitmapFactory.decodeByteArray(decodedString, 0, decodedString.length);
            switch (hangi) {
                case 0:

                    imageViewSapka.setImageBitmap(decodedByte);
                    kombin.setBasustu(MainActivity.secilenCekmece.getKiyafetler().get(secilenKiyafet));
                    break;
                case 1:

                    imageViewPantolon.setImageBitmap(decodedByte);
                    kombin.setAltBeden(MainActivity.secilenCekmece.getKiyafetler().get(secilenKiyafet));
                    break;
                case 2:

                    imageViewTshirt.setImageBitmap(decodedByte);
                    kombin.setUstBeden(MainActivity.secilenCekmece.getKiyafetler().get(secilenKiyafet));
                    break;
                case 3:

                    imageViewAyakkabiSag.setImageBitmap(decodedByte);
                    imageViewAyakkabiSol.setImageBitmap(decodedByte);

                    kombin.setAyak(MainActivity.secilenCekmece.getKiyafetler().get(secilenKiyafet));
                    break;
                case 4:

                    imageViewAyakkabiSol.setImageBitmap(decodedByte);
                    imageViewAyakkabiSag.setImageBitmap(decodedByte);
                    kombin.setAyak(MainActivity.secilenCekmece.getKiyafetler().get(secilenKiyafet));
                    break;
                case 5:

                    imageViewGozluk.setImageBitmap(decodedByte);
                    kombin.setSurat(MainActivity.secilenCekmece.getKiyafetler().get(secilenKiyafet));
                    break;
            }
        } else if (ilkMi == -1) {
            byte[] decodedString = Base64.decode(MainActivity.kombinler.get(kombinNumarasi).getSurat().getFoto(), Base64.DEFAULT);
            Bitmap decodedByte = BitmapFactory.decodeByteArray(decodedString, 0, decodedString.length);
            imageViewGozluk.setImageBitmap(decodedByte);

            byte[] decodedString1 = Base64.decode(MainActivity.kombinler.get(kombinNumarasi).getAyak().getFoto(), Base64.DEFAULT);
            Bitmap decodedByte1 = BitmapFactory.decodeByteArray(decodedString1, 0, decodedString1.length);
            imageViewAyakkabiSol.setImageBitmap(decodedByte1);
            imageViewAyakkabiSag.setImageBitmap(decodedByte1);


            byte[] decodedString3 = Base64.decode(MainActivity.kombinler.get(kombinNumarasi).getUstBeden().getFoto(), Base64.DEFAULT);
            Bitmap decodedByte3 = BitmapFactory.decodeByteArray(decodedString3, 0, decodedString3.length);
            imageViewTshirt.setImageBitmap(decodedByte3);

            byte[] decodedString4 = Base64.decode(MainActivity.kombinler.get(kombinNumarasi).getAltBeden().getFoto(), Base64.DEFAULT);
            Bitmap decodedByte4 = BitmapFactory.decodeByteArray(decodedString4, 0, decodedString4.length);
            imageViewPantolon.setImageBitmap(decodedByte4);

            byte[] decodedString5 = Base64.decode(MainActivity.kombinler.get(kombinNumarasi).getBasustu().getFoto(), Base64.DEFAULT);
            Bitmap decodedByte5 = BitmapFactory.decodeByteArray(decodedString5, 0, decodedString5.length);
            imageViewSapka.setImageBitmap(decodedByte5);

        }


    }

    public void kabinKiyafetSec(View view) {


        if (MainActivity.secilenCekmece == null) {
            Toast.makeText(getApplicationContext(), "Hiç kıyafetiniz yok!", Toast.LENGTH_LONG).show();
        } else {
            Intent intent = new Intent(getApplicationContext(), CekmeceleriGor.class);
            ilkMi = 1;
            intent.putExtra("nereden", "kabin");
            startActivity(intent);


            switch (view.getId()) {
                case R.id.imageViewSapka:
                    hangi = 0;
                    kombin.setBasustu(MainActivity.secilenCekmece.getKiyafetler().get(secilenKiyafet));
                    break;
                case R.id.imageViewPantolon:
                    kombin.setAltBeden(MainActivity.secilenCekmece.getKiyafetler().get(secilenKiyafet));
                    hangi = 1;
                    break;
                case R.id.imageViewTshirt:
                    kombin.setUstBeden(MainActivity.secilenCekmece.getKiyafetler().get(secilenKiyafet));
                    hangi = 2;
                    break;
                case R.id.imageViewAyakkabiSag:
                    kombin.setAyak(MainActivity.secilenCekmece.getKiyafetler().get(secilenKiyafet));
                    hangi = 3;
                    break;
                case R.id.imageViewAyakkabiSol:
                    kombin.setAyak(MainActivity.secilenCekmece.getKiyafetler().get(secilenKiyafet));
                    hangi = 4;
                    break;
                case R.id.imageViewGozluk:
                    kombin.setSurat(MainActivity.secilenCekmece.getKiyafetler().get(secilenKiyafet));
                    hangi = 5;
                    break;

            }


        }


    }

    public void save(View view) {
        System.out.println("ilkMi= " + ilkMi);
        if (kombinGuncellemeMi != 1) {
            AlertDialog.Builder builder = new AlertDialog.Builder(this);
            builder.setTitle("Kombinin ismi ne olsun?");

// Set up the input
            final EditText input = new EditText(this);
// Specify the type of input expected; this, for example, sets the input as a password, and will mask the text
            input.setInputType(InputType.TYPE_CLASS_TEXT);
            builder.setView(input);

// Set up the buttons
            builder.setPositiveButton("Kaydet", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    m_Text = input.getText().toString();
                    kombin.setIsim(m_Text);
                    MainActivity.kombinler.add(kombin);
                    Toast.makeText(getApplicationContext(), "Harika seçim!", Toast.LENGTH_LONG).show();
                    finish();
                }
            });
            builder.setNegativeButton("İptal", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    dialog.cancel();
                }
            });

            builder.show();


        } else {
            MainActivity.kombinler.set(kombinNumarasi, kombin);



            Toast.makeText(getApplicationContext(), "Kombininiz güncellendi!", Toast.LENGTH_LONG).show();


        }


    }

    public  void kombiniPaylas(View view) {


            ekranGoruntusu=takescreenshotOfRootView(view);


        StrictMode.VmPolicy.Builder builder = new StrictMode.VmPolicy.Builder();
        StrictMode.setVmPolicy(builder.build());
        File f =  new File(getExternalCacheDir()+"/"+getResources().getString(R.string.app_name)+".png");
        Intent shareIntent;


        try {
            FileOutputStream outputStream = new FileOutputStream(f);
            ekranGoruntusu.compress(Bitmap.CompressFormat.PNG,100,outputStream);

            outputStream.flush();
            outputStream.close();
            shareIntent = new Intent(Intent.ACTION_SEND);
            shareIntent.setType("image/*");
            shareIntent.putExtra(Intent.EXTRA_STREAM, Uri.fromFile(f));
            shareIntent.putExtra(Intent.EXTRA_TEXT,"Hey! Şu kombinime bak... Nasıl olmuş sence?");
            shareIntent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);


        }catch (Exception e){
            throw new RuntimeException(e);
        }
        startActivity(Intent.createChooser(shareIntent,"Kombini paylaş..."));




    }



    public  Bitmap takescreenshot(View v) {
        v.setDrawingCacheEnabled(true);
        v.buildDrawingCache(true);
        Bitmap b = Bitmap.createBitmap(v.getDrawingCache());
        v.setDrawingCacheEnabled(false);
        return b;
    }

    public Bitmap takescreenshotOfRootView(View v) {
        return takescreenshot(v.getRootView());
    }


    public void kombiniSil(View view) {

        MainActivity.kombinler.remove(kombin);
        finish();
        Toast.makeText(getApplicationContext(), "Kombin silindi.", Toast.LENGTH_LONG).show();







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