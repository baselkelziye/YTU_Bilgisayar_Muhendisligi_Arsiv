package com.example.ytumezunandroidapp;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.view.Window;
import android.widget.Button;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.DefaultItemAnimator;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.gms.tasks.Task;
import com.google.android.play.core.integrity.p;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.ChildEventListener;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;

public class Announcement extends AppCompatActivity {

    public static ArrayList<AnnouncementModel> announcementList = new ArrayList<>();

    private FirebaseAuth mAuth;
    private DatabaseReference mReference;
    private DatabaseReference mReference2;
    private HashMap<String, Object> mData;
    private FirebaseUser mUser;

    String head, text, user, date, photoPath;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_announcement);


        // Duyuru listesinin oluşturulması

        announcementList.add(new AnnouncementModel(R.drawable.announcement, "Header 1", "text1", "16.03.2023", "deneme"));
        /*
        announcementList.add(new AnnouncementModel(R.drawable.ytu_logo, "Header 2", "text2", "19.03.2023", "deneme"));
        announcementList.add(new AnnouncementModel(R.drawable.announcement, "Header 3", "text 3", "24.03.2023", "deneme"));
        announcementList.add(new AnnouncementModel(R.drawable.ytu_logo, "Header 4", "text4", "31.03.2023", "deneme"));
        announcementList.add(new AnnouncementModel(R.drawable.ytu_logo, "Header 5", "text5", "02.04.2023", "deneme"));
        */
        AnnouncementAdapter adapter = new AnnouncementAdapter(announcementList, this);
        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(this, RecyclerView.VERTICAL, false);
        RecyclerView recyclerView = (RecyclerView) findViewById(R.id.announcement_recycler_view);

        recyclerView.setLayoutManager(linearLayoutManager);
        recyclerView.setItemAnimator(new DefaultItemAnimator());
        recyclerView.setAdapter(adapter);

        viewAnnouncements();
    }

    public void viewAnnouncements(){
        //mUser = mAuth.getCurrentUser();

        //assert mUser != null;
        mReference = FirebaseDatabase.getInstance().getReference("Duyurular");
        mReference.child("baslik").addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                announcementList.clear();
                for(DataSnapshot data: snapshot.getChildren()){
                    assert data.getKey() != null;
                    assert data.getValue() != null;

                    if(data.getKey().equals("baslik")){
                        head = data.child("baslik").getValue(AnnouncementModel.class).header.toString();
                    }
                    else if(data.getKey().equals("metin")){
                        text = data.child("metin").getValue(AnnouncementModel.class).text.toString();
                    }
                    else if(data.getKey().equals("tarih")){
                        date = data.child("tarih").getValue(AnnouncementModel.class).date.toString();
                    }
                    else if(data.getKey().equals("kullanici")){
                        user = data.child("kullanici").getValue(AnnouncementModel.class).user.toString();
                    }
                    else if(data.getKey().equals("fotograf")) {
                        photoPath = data.child("baslik").getValue(AnnouncementModel.class).toString();
                    }

                    announcementList.add(new AnnouncementModel(R.drawable.announcement, head, text, date, user));
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {
                Toast.makeText(Announcement.this, error.getMessage(), Toast.LENGTH_SHORT).show();
            }
        });
    }
}