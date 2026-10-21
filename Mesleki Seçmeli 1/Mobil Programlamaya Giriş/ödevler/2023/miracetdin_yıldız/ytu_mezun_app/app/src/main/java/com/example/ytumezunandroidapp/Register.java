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
import com.google.android.play.integrity.internal.m;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.FirebaseDatabase;

import java.io.File;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;

public class Register extends AppCompatActivity {

    public static final int CAMERA_PERM_CODE = 101;
    public static final int CAMERA_REQUEST_CODE = 102;
    EditText name, surname, email, enrollmentYear, graduationYear, password, password2;
    ImageView photo;
    Button register, takePhoto;
    String currentPhotoPath;

    private FirebaseAuth mAuth;
    private FirebaseDatabase mReference;
    private HashMap<String, Object> mData;
    private FirebaseUser mUser;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_register);

        name = (EditText) findViewById(R.id.register_et_name);
        surname = (EditText) findViewById(R.id.register_et_surname);
        email = (EditText) findViewById(R.id.register_et_email);
        enrollmentYear = (EditText) findViewById(R.id.register_et_enrollmentYear);
        graduationYear = (EditText) findViewById(R.id.register_et_graduationYear);
        password = (EditText) findViewById(R.id.register_et_password);
        password2 = (EditText) findViewById(R.id.register_et_password2);

        photo = (ImageView) findViewById(R.id.register_iv_profilePhoto);


        register = (Button) findViewById(R.id.register_bt_register);
        takePhoto = (Button) findViewById(R.id.register_bt_takePhoto);

        register.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(password.getText().toString().equals(password2.getText().toString())) {
                    if(!TextUtils.isEmpty(name.getText().toString()) && !TextUtils.isEmpty(surname.getText().toString())
                        && !TextUtils.isEmpty(email.getText().toString()) && !TextUtils.isEmpty(password.getText().toString())){
                        register_user(v);
                    }
                    else{
                        Toast.makeText(Register.this, "Ad, Soyad, E-posta ve Şifre Alanları Boş Bırakılamaz!", Toast.LENGTH_SHORT).show();
                    }
                    //Toast.makeText(Register.this, "Kayıt başarılı bir şekilde gerçekleşmiştir. Giriş yapınız.", Toast.LENGTH_LONG).show();
                    // Kayıt ekranında alınan bilgilerle kullanıcı oluşturma
                    /*
                    user = new User(name.toString(), surname.toString(), email.toString(), password.toString(),
                            enrollmentYear.toString(), graduationYear.toString(), currentPhotoPath);
                    Intent intent = new Intent(getApplicationContext(), Login.class);
                    startActivity(intent);

                     */
                }
                else{
                    Toast.makeText(Register.this, "Girilen Şifreler Aynı Değil!", Toast.LENGTH_SHORT).show();
                }
            }
        });

        takePhoto.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                verifyPermissions();
            }
        });

        mAuth = FirebaseAuth.getInstance();
        mReference = FirebaseDatabase.getInstance();
    }

    private void verifyPermissions() {
        String[] permissions = {
                Manifest.permission.READ_EXTERNAL_STORAGE,
                Manifest.permission.WRITE_EXTERNAL_STORAGE,
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

    public void register_user(View view){
        if(!TextUtils.isEmpty(email.getText().toString()) && !TextUtils.isEmpty(password.getText().toString())){
            if(password.getText().toString().equals(password2.getText().toString())){
                mAuth.createUserWithEmailAndPassword(email.getText().toString(), password.getText().toString())
                        .addOnCompleteListener(this, new OnCompleteListener<AuthResult>() {
                            @Override
                            public void onComplete(@NonNull Task<AuthResult> task) {
                                if(task.isSuccessful()){
                                    mData = new HashMap<>();
                                    mUser = mAuth.getCurrentUser();

                                    mData.put("id", mUser.getUid());
                                    mData.put("isim", name.getText().toString());
                                    mData.put("soyisim", surname.getText().toString());
                                    mData.put("giris_yili", enrollmentYear.getText().toString());
                                    mData.put("mezuniyet_yili", graduationYear.getText().toString());
                                    mData.put("email_address", email.getText().toString());
                                    mData.put("profile_photo", currentPhotoPath.toString());
                                    mData.put("sifre", password.getText().toString());
                                    mData.put("lisans", "");
                                    mData.put("yuksek_lisans", "");
                                    mData.put("doktora", "");
                                    mData.put("ulke", "");
                                    mData.put("sehir", "");
                                    mData.put("firma", "");
                                    mData.put("linkedin", "");
                                    mData.put("twitter", "");
                                    mData.put("telefon", "");

                                    mReference.getReference().child("Kullanicilar").child(mUser.getUid()).setValue(mData)
                                            .addOnCompleteListener(Register.this, new OnCompleteListener<Void>() {
                                                @Override
                                                public void onComplete(@NonNull Task<Void> task) {
                                                    if(task.isSuccessful()){
                                                        Toast.makeText(Register.this, "Kayıt İşlemi Başarılı, Giriş Yapınız.", Toast.LENGTH_SHORT).show();
                                                        Intent intent = new Intent(getApplicationContext(), Login.class);
                                                        startActivity(intent);
                                                    }
                                                    else{
                                                        Toast.makeText(Register.this, task.getException().getMessage(), Toast.LENGTH_SHORT).show();
                                                    }
                                                }
                                            });
                                }
                                else{
                                    Toast.makeText(Register.this, task.getException().getMessage(), Toast.LENGTH_SHORT).show();
                                }
                            }
                        });
            }else{
                Toast.makeText(this, "Şifreler Aynı Değil!", Toast.LENGTH_SHORT).show();
            }
        }else{
            Toast.makeText(this, "Email ve Şifre Alanları Boş Olamaz!", Toast.LENGTH_SHORT).show();
        }
    }
}