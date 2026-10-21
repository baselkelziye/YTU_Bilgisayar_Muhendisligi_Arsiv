package com.example.mezunuyg;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.bumptech.glide.Glide;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class MezunDetay extends AppCompatActivity {

    TextView detayUserName,detayPhone,detayYear,detayCompany,detayCity,detayEducation;
    private  String tmpPhone;
    ImageView detayImg;
    Button ulasBtn, geriBtn;
    FirebaseUser currUser;
    DatabaseReference dbRef;
    Intent intent;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mezun_detay);
        detayUserName=findViewById(R.id.detayUserNameID);
        detayPhone=findViewById(R.id.detayPhoneID2);
        detayYear=findViewById(R.id.detayYearID2);
        detayCompany=findViewById(R.id.detayCompanyID2);
        detayCity=findViewById(R.id.detayCityID2);
        detayEducation=findViewById(R.id.detayEducatıonID2);
        detayImg=findViewById(R.id.detayImg);
        ulasBtn=findViewById(R.id.reachBtn);
        geriBtn=findViewById(R.id.anaDonusBtnDetay);

        intent=getIntent();
        String userId=intent.getStringExtra("userID");
        currUser= FirebaseAuth.getInstance().getCurrentUser();
        dbRef= FirebaseDatabase.getInstance().getReference("Users").child(userId);
        dbRef.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                User user=snapshot.getValue(User.class);
                tmpPhone=user.getPhone();
                detayUserName.setText(user.getUsername());
                detayCity.setText(user.getCity());
                detayCompany.setText(user.getCompany());
                detayEducation.setText(user.getEducation());
                detayPhone.setText(user.getPhone());
                detayYear.setText(user.getYear());
                if(user.getImageURL().equals("default")){
                     detayImg.setImageResource(R.mipmap.ic_launcher);
                }
                else{
                    Glide.with(MezunDetay.this)
                            .load(user.getImageURL())
                            .into(detayImg);
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });


        geriBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i=new Intent(MezunDetay.this,MainActivity.class);
                startActivity(i);
            }
        });
        ulasBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Uri callUri = Uri.parse("tel:" + tmpPhone);
                Intent callIntent = new Intent(Intent.ACTION_DIAL, callUri);
                Intent chooserIntent = Intent.createChooser(callIntent, "Uygulama Seç");
                startActivity(chooserIntent);
            }
        });


    }

}