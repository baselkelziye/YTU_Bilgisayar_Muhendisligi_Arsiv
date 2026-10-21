package com.example.roommateproject;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.bumptech.glide.Glide;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.util.HashMap;

public class OgrDetay extends AppCompatActivity {

    TextView detayUserName,detayPhone,detayDist,detayGrade,detayStatus,detayDuration,detayDep;
    private  String tmpPhone;
    private String currState="nothing";
    ImageView detayImg;
    Button eslesBtn, geriBtn,btnReddet,btnCom;
    FirebaseUser currUser;
    DatabaseReference dbRef,reqRef,friendRef,currDb;
    Intent intent;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ogr_detay);
        detayUserName=findViewById(R.id.detayUserNameID1);
        detayPhone=findViewById(R.id.detayPhoneID);
        detayDep=findViewById(R.id.detayBolumID);
        detayGrade=findViewById(R.id.detaySınıfID);
        detayDist=findViewById(R.id.detayDisID);
        detayStatus=findViewById(R.id.detayStatusID);
        detayDuration=findViewById(R.id.detayDurationID);
        detayImg=findViewById(R.id.detayImg1);
        eslesBtn=findViewById(R.id.davetBtn);
        geriBtn=findViewById(R.id.backBtn);
        btnReddet=findViewById(R.id.btnReddet);
        btnCom=findViewById(R.id.btnCom);
        intent=getIntent();
        String userId=intent.getStringExtra("userID");
        currUser= FirebaseAuth.getInstance().getCurrentUser();
        dbRef= FirebaseDatabase.getInstance().getReference("Users").child(userId);
        currDb= FirebaseDatabase.getInstance().getReference("Users").child(currUser.getUid());
        friendRef= FirebaseDatabase.getInstance().getReference("friends");
        reqRef= FirebaseDatabase.getInstance().getReference("Reqs");
        dbRef.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                User user=snapshot.getValue(User.class);
                tmpPhone=user.getPhone();
                detayUserName.setText(user.getUsername());
                detayDep.setText(user.getDepartment());
                detayGrade.setText(user.getGrade());
                detayDist.setText(user.getDistance());
                detayPhone.setText(user.getPhone());
                detayStatus.setText(user.getStatus());
                detayDuration.setText(user.getDuration());
                if(user.getImageURL().equals("default")){
                    detayImg.setImageResource(R.mipmap.ic_launcher);
                }
                else{
                    Glide.with(OgrDetay.this)
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
                Intent i=new Intent(OgrDetay.this,MainActivity.class);
                startActivity(i);
            }
        });
        eslesBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                SendInvite(userId);
//                Uri callUri = Uri.parse("tel:" + tmpPhone);
//                Intent callIntent = new Intent(Intent.ACTION_DIAL, callUri);
//                Intent chooserIntent = Intent.createChooser(callIntent, "Uygulama Seç");
//                startActivity(chooserIntent);
            }
        });
        CheckUserState(userId);
        btnReddet.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                RemoveMate(userId);
            }
        });
        btnCom.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                CanReach();
            }
        });

    }

    private void CanReach() {
        if(currState.equals("roomMate")){
            Uri callUri = Uri.parse("tel:" + tmpPhone);
            Intent callIntent = new Intent(Intent.ACTION_DIAL, callUri);
            Intent chooserIntent = Intent.createChooser(callIntent, "Uygulama Seç");
            startActivity(chooserIntent);
        }
        else{
            Toast.makeText(this, "Oda arkadasi degilsiniz", Toast.LENGTH_SHORT).show();
        }
      
    }

    private void RemoveMate(String userId){
        if(currState.equals("roomMate")){
            friendRef.child(currUser.getUid()).child(userId).removeValue().addOnCompleteListener(new OnCompleteListener<Void>() {
                @Override
                public void onComplete(@NonNull Task<Void> task) {
                    if(task.isSuccessful()){
                        friendRef.child(userId).child(currUser.getUid()).removeValue().addOnCompleteListener(new OnCompleteListener<Void>() {
                            @Override
                            public void onComplete(@NonNull Task<Void> task) {
                                Toast.makeText(OgrDetay.this, "Oda arkadasligi sona erdi", Toast.LENGTH_SHORT).show();
                                currState="nothing";
                                eslesBtn.setText("Eşleş");
                                btnReddet.setVisibility(View.GONE);
                            }
                        });
                    }
                }
            });

        }
        if(currState.equals("hPending")){
            reqRef.child(currUser.getUid()).child(userId).removeValue().addOnCompleteListener(new OnCompleteListener() {
                @Override
                public void onComplete(@NonNull Task task) {
                    currState="nothing";
                    eslesBtn.setVisibility(View.VISIBLE);
                    eslesBtn.setText("Eşleş");
                    btnReddet.setVisibility(View.GONE);
                }
            });
            reqRef.child(userId).child(currUser.getUid()).removeValue().addOnCompleteListener(new OnCompleteListener() {
                @Override
                public void onComplete(@NonNull Task task) {
                    currState="nothing";
                    eslesBtn.setVisibility(View.VISIBLE);
                    eslesBtn.setText("Eşleş");
                    btnReddet.setVisibility(View.GONE);
                }
            });

            HashMap reqMap=new HashMap();
            reqMap.put("status","decline");
            reqRef.child(currUser.getUid()).child(userId).updateChildren(reqMap).addOnCompleteListener(new OnCompleteListener() {
                @Override
                public void onComplete(@NonNull Task task) {
                    if(task.isSuccessful()){
                        Toast.makeText(OgrDetay.this, "Reddedildi", Toast.LENGTH_SHORT).show();
                        currState="Idecline";
                        eslesBtn.setVisibility(View.GONE);
                        btnReddet.setVisibility(View.GONE);
                    }
                }
            });

        }
    }
    private void CheckUserState(String userId) {
        friendRef.child(currUser.getUid()).child(userId).addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                if(snapshot.exists()){
                    currState="roomMate";
                    eslesBtn.setVisibility(View.VISIBLE);
                    btnReddet.setText("Çıkar");
                    btnReddet.setVisibility(View.VISIBLE);
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });
        friendRef.child(userId).child(currUser.getUid()).addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                if(snapshot.exists()){
                    currState="roomMate";
                    eslesBtn.setText("Ekli");
                    btnReddet.setText("Çıkar");
                    btnReddet.setVisibility(View.VISIBLE);
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });
        reqRef.child(currUser.getUid()).child(userId).addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                if(snapshot.exists()){

                    if(snapshot.child("status").getValue().toString().equals("pending")){
                        currState="Ipending";
                        eslesBtn.setText("IPTAL");
                        btnReddet.setVisibility(View.GONE);
                    }

                    if(snapshot.child("status").getValue().toString().equals("decline")){
                        currState="Idecline";
                        eslesBtn.setText("IPTAL");
                        btnReddet.setVisibility(View.GONE);
                    }
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });
        reqRef.child(userId).child(currUser.getUid()).addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                if(snapshot.exists()){

                    if(snapshot.child("status").getValue().toString().equals("pending")){
                        currState="hPending";
                        eslesBtn.setText("KABUL ET");
                        btnReddet.setText("REDDET");
                        btnReddet.setVisibility(View.VISIBLE);
                    }
                    if(snapshot.child("status").getValue().toString().equals("decline")){
                        currState="Idecline";
                        eslesBtn.setText("IPTAL");
                        btnReddet.setVisibility(View.GONE);
                    }


                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });
        if(currState.equals("nothing")){
            currState="nothing";
            eslesBtn.setText("Eşleş");
            btnReddet.setText("REDDET");
            btnReddet.setVisibility(View.GONE);
        }

    }

    private void SendInvite(String userId){
        if(currState.equals("nothing")){
            HashMap reqMap=new HashMap();
            reqMap.put("status","pending");
            reqRef.child(currUser.getUid()).child(userId).updateChildren(reqMap).addOnCompleteListener(new OnCompleteListener() {
                @Override
                public void onComplete(@NonNull Task task) {
                    if(task.isSuccessful()){
                        Toast.makeText(OgrDetay.this, "Davetiye yollandi", Toast.LENGTH_SHORT).show();
                        btnReddet.setVisibility(View.GONE);
                        currState="Ipending";
                        eslesBtn.setText("Iptal");
                    }
                    else{
                        Toast.makeText(OgrDetay.this, "Davetiye Basarisiz", Toast.LENGTH_SHORT).show();
                    }
                }
            });
        }
        if((currState.equals("Ipending"))|| (currState.equals("Idecline"))){
            reqRef.child(currUser.getUid()).child(userId).removeValue().addOnCompleteListener(new OnCompleteListener<Void>() {
                @Override
                public void onComplete(@NonNull Task<Void> task) {
                    if(task.isSuccessful()){
                        Toast.makeText(OgrDetay.this, "Davetiye Iptal edildi", Toast.LENGTH_SHORT).show();
                        currState="nothing";
                        eslesBtn.setText("Eşleş");
                        btnReddet.setVisibility(View.GONE);
                    }
                    else{
                        Toast.makeText(OgrDetay.this, "Iptal basarisiz", Toast.LENGTH_SHORT).show();
                    }
                }
            });
        }
        if(currState.equals("hPending")){
            reqRef.child(userId).child(currUser.getUid()).removeValue().addOnCompleteListener(new OnCompleteListener<Void>() {
                @Override
                public void onComplete(@NonNull Task<Void> task) {
                    if(task.isSuccessful()){
                        HashMap friendMap=new HashMap();
                        friendMap.put("Status","RoomMate");
                       // friendMap.put("userName",detayUserName.getText().toString());
                       if(detayUserName!=null){
                           friendRef.child(currUser.getUid()).child(userId).updateChildren(friendMap).addOnCompleteListener(new OnCompleteListener() {
                               @Override
                               public void onComplete(@NonNull Task task) {
                                   if(task.isSuccessful()){
                                       friendRef.child(userId).child(currUser.getUid()).updateChildren(friendMap).addOnCompleteListener(new OnCompleteListener() {
                                           @Override
                                           public void onComplete(@NonNull Task task) {
                                               Toast.makeText(OgrDetay.this, "Ev arkadasi eklendi", Toast.LENGTH_SHORT).show();
                                               currState="roomMate";
                                               eslesBtn.setVisibility(View.GONE);
                                               btnReddet.setText("IPTAL");
                                               btnReddet.setVisibility(View.VISIBLE);
                                           }
                                       });
                                   }
                               }
                           });
                       }

                    }
                }
            });
//            currDb.child("status").setValue("Aramiyor").addOnCompleteListener(new OnCompleteListener() {
//                @Override
//                public void onComplete(@NonNull Task task) {
//                    if(task.isSuccessful()){
//                        Toast.makeText(OgrDetay.this, "Profil Guncllendi", Toast.LENGTH_SHORT).show();
//                    }
//                }
//            });
//            dbRef.child("status").setValue("Aramiyor").addOnCompleteListener(new OnCompleteListener() {
//                @Override
//                public void onComplete(@NonNull Task task) {
//                    if(task.isSuccessful()){
//                        //Toast.makeText(OgrDetay.this, "Profil Guncllendi", Toast.LENGTH_SHORT).show();
//                    }
//                }
//            });
        }
        if(currState.equals("roomMate")){
            //
        }
    }

}