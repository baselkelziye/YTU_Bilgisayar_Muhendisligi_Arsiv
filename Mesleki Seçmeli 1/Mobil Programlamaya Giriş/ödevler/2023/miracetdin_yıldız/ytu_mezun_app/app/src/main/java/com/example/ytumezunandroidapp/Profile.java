package com.example.ytumezunandroidapp;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.view.Window;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.io.File;
import java.util.HashMap;

public class Profile extends AppCompatActivity {

    TextView name, surname, enrollmentYear, graduationYear, email, password, bachelor,
            master, phd, country, city, company, linkedin, twitter, emailAddress, phoneNumber;
    ImageView profilePhoto;
    Button updateInfo;
    private FirebaseAuth mAuth;
    private DatabaseReference mReference;
    private HashMap<String, Object> mData;
    private FirebaseUser mUser;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_profile);

        name = (TextView) findViewById(R.id.profile_tv_name);
        surname = (TextView) findViewById(R.id.profile_tv_surname);
        enrollmentYear = (TextView) findViewById(R.id.profile_tv_enrollmentYear);
        graduationYear = (TextView) findViewById(R.id.profile_tv_graduationYear);
        email = (TextView) findViewById(R.id.profile_tv_email);
        password = (TextView) findViewById(R.id.profile_tv_password);
        bachelor = (TextView) findViewById(R.id.profile_tv_bachelor);
        master = (TextView) findViewById(R.id.profile_tv_master);
        phd = (TextView) findViewById(R.id.profile_tv_phd);
        country = (TextView) findViewById(R.id.profile_tv_country);
        city = (TextView) findViewById(R.id.profile_tv_city);
        company = (TextView) findViewById(R.id.profile_tv_company);
        linkedin = (TextView) findViewById(R.id.profile_tv_linkedin);
        twitter = (TextView) findViewById(R.id.profile_tv_twitter);
        emailAddress = (TextView) findViewById(R.id.profile_tv_emailAddress);
        phoneNumber = (TextView) findViewById(R.id.profile_tv_phone);

        profilePhoto = (ImageView) findViewById(R.id.profile_iv_photo);

        updateInfo = (Button) findViewById(R.id.profile_bt_updateInfo);

        mAuth = FirebaseAuth.getInstance();

        updateInfo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(),UpdateInfo.class);
                startActivity(intent);
            }
        });
    }

    @Override
    protected void onStart() {
        super.onStart();
        viewUserInfo();
    }

    public void viewUserInfo(){
        mUser = mAuth.getCurrentUser();

        assert mUser != null;
        mReference = FirebaseDatabase.getInstance().getReference("Kullanicilar").child(mUser.getUid());
        mReference.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                for(DataSnapshot data: snapshot.getChildren()){
                    assert data.getKey() != null;
                    assert data.getValue() != null;

                    if(data.getKey().equals("isim")){
                        name.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("soyisim")){
                        surname.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("giris_yili")){
                        enrollmentYear.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("mezuniyet_yili")){
                        graduationYear.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("email_address")){
                        email.setText(data.getValue().toString());
                        emailAddress.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("sifre")){
                        password.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("lisans")){
                        bachelor.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("yuksek_lisans")){
                        master.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("doktora")){
                        phd.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("ulke")){
                        country.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("sehir")){
                        city.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("firma")){
                        company.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("linkedin")){
                        linkedin.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("twitter")){
                        twitter.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("telefon")){
                        phoneNumber.setText(data.getValue().toString());
                    }
                    else if(data.getKey().equals("profile_photo")){
                        File f = new File(data.getValue().toString());
                        profilePhoto.setImageURI(Uri.fromFile(f));
                    }
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {
                Toast.makeText(Profile.this, error.getMessage(), Toast.LENGTH_SHORT).show();
            }
        });
    }
}
