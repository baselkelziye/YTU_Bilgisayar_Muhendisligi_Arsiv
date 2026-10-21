package com.example.ytumezunandroidapp;

import android.Manifest;
import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.provider.MediaStore;
import android.text.TextUtils;
import android.view.View;
import android.view.Window;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.core.content.FileProvider;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.FirebaseDatabase;

import java.io.File;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;

public class CreateAnnouncement extends AppCompatActivity {

    public static final int CAMERA_PERM_CODE = 101;
    public static final int CAMERA_REQUEST_CODE = 102;
    String currentPhotoPath;
    EditText head, text;
    ImageView photo;
    Button takePhoto, share;

    private FirebaseAuth mAuth;
    private FirebaseDatabase mReference;
    private HashMap<String, Object> mData;
    private FirebaseUser mUser;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_createannouncement);

        head = (EditText) findViewById(R.id.createannouncement_et_head);
        text = (EditText) findViewById(R.id.createannouncement_et_text);
        photo = (ImageView) findViewById(R.id.createannounce_iv_photo);

        takePhoto = (Button) findViewById(R.id.createannouncement_bt_takePhoto);
        share = (Button) findViewById(R.id.createannouncemenet_bt_share);

        mAuth = FirebaseAuth.getInstance();
        mReference = FirebaseDatabase.getInstance();

        share.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                shareAnnouncement(v);
            }
        });

        takePhoto.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                verifyPermissions();
            }
        });
    }

    private void verifyPermissions() {
        String[] permissions = {
                android.Manifest.permission.READ_EXTERNAL_STORAGE,
                android.Manifest.permission.WRITE_EXTERNAL_STORAGE,
                Manifest.permission.CAMERA
        };

        if(ContextCompat.checkSelfPermission(this.getApplicationContext(), permissions[0]) == PackageManager.PERMISSION_GRANTED
                && ContextCompat.checkSelfPermission(this.getApplicationContext(), permissions[1]) == PackageManager.PERMISSION_GRANTED
                && ContextCompat.checkSelfPermission(this.getApplicationContext(), permissions[2]) == PackageManager.PERMISSION_GRANTED) {
            dispatchTakePictureIntent();
        }
        else {
            ActivityCompat.requestPermissions(this, permissions, CAMERA_PERM_CODE);
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if(requestCode == CAMERA_PERM_CODE) {
            if(grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED){
                dispatchTakePictureIntent();
            }else {
                Toast.makeText(this, "Kamerayı kullanmak için izin gerekmektedir!", Toast.LENGTH_SHORT).show();
            }
        }
    }

    private void dispatchTakePictureIntent() {
        Intent takePıctureIntent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);

        if(takePıctureIntent.resolveActivity(getPackageManager()) != null) {
            File photoFile = null;

            try {
                photoFile = createImageFile();
            }
            catch (IOException exception) {
                Toast.makeText(this, "Fotoğraf dosyası oluşturulamadı!", Toast.LENGTH_SHORT).show();
            }

            if(photoFile != null) {
                Uri photoUri = FileProvider.getUriForFile(this, "com.example.ytumezunandroidapp", photoFile);
                takePıctureIntent.putExtra(MediaStore.EXTRA_OUTPUT, photoUri);
                startActivityForResult(takePıctureIntent, CAMERA_REQUEST_CODE);
            }
        }
    }

    private File createImageFile() throws IOException {
        String timeStamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(new Date());
        String imageFileName = "YTU_Mezun_" + timeStamp + "_";
        File storageDir = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
        File image = File.createTempFile(imageFileName, ".jpg", storageDir);

        currentPhotoPath = image.getAbsolutePath();

        return image;
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if(requestCode == CAMERA_REQUEST_CODE) {
            if(resultCode == Activity.RESULT_OK) {
                File f = new File(currentPhotoPath);
                photo.setImageURI(Uri.fromFile(f));
            }
        }
    }

    public void shareAnnouncement(View view){
        if(!TextUtils.isEmpty(head.getText().toString()) && !TextUtils.isEmpty(text.getText().toString())){
            mUser = mAuth.getCurrentUser();

            Date currentDate = Calendar.getInstance().getTime();

            assert mUser != null;
            Announcement.announcementList.add(new AnnouncementModel(R.drawable.announcement, head.getText().toString(),
                    text.getText().toString(), currentDate.toString(), mUser.getEmail()));

            mData = new HashMap<>();
            mUser = mAuth.getCurrentUser();

            mData.put("baslik", head.getText().toString());
            mData.put("metin", text.getText().toString());
            mData.put("fotograf", currentPhotoPath.toString());
            mData.put("tarih", currentDate.toString());
            mData.put("kullanici", mUser.getEmail());


            mReference.getReference().child("Duyurular").child(head.getText().toString()).setValue(mData)
                    .addOnCompleteListener(CreateAnnouncement.this, new OnCompleteListener<Void>() {
                        @Override
                        public void onComplete(@NonNull Task<Void> task) {
                            if(task.isSuccessful()){
                                Toast.makeText(CreateAnnouncement.this, "Duyuru Paylaşma İşlemi Başarılı!", Toast.LENGTH_SHORT).show();
                                Intent intent = new Intent(getApplicationContext(), Login.class);
                            }
                            else{
                                Toast.makeText(CreateAnnouncement.this, task.getException().getMessage(), Toast.LENGTH_SHORT).show();
                            }
                        }
                    });

            Intent intent = new Intent(getApplicationContext(), Announcement.class);
            startActivity(intent);
        }
        else{
            Toast.makeText(CreateAnnouncement.this, "Başlık ve Metin Alanları Boş Bırakılmaz!", Toast.LENGTH_SHORT).show();
        }
    }
}
