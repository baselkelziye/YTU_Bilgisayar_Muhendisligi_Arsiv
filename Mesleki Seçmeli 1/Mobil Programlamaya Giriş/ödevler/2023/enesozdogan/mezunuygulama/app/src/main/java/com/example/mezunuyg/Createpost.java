package com.example.mezunuyg;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;
import com.google.firebase.storage.UploadTask;

import com.google.firebase.Timestamp;

import java.util.Date;

public class Createpost extends AppCompatActivity {

    private static final int GALLERY_CODE = 1;
    Button saveBtn,cancelBtn;
    ProgressBar progressBar;
    ImageView postImg;
    EditText titleET;
    EditText duyuruET;
    TextView  currUserTxt;

    FirebaseAuth firebaseAuth;
    FirebaseAuth.AuthStateListener authStateListener;
    FirebaseUser currUser;

    DatabaseReference dbRefPosts,dbRefUser;
    StorageReference storageReference;
    Uri imgUri;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_createpost);

        storageReference= FirebaseStorage.getInstance().getReference();
        firebaseAuth=FirebaseAuth.getInstance();


        progressBar=findViewById(R.id.postprogressBar);
        titleET=findViewById(R.id.postTitleET);
        duyuruET=findViewById(R.id.duyuruET);
        currUserTxt=findViewById(R.id.currUserTxt);
        postImg=findViewById(R.id.postImg);
        saveBtn=findViewById(R.id.postSaveBtn);
        cancelBtn=findViewById(R.id.postCancelBtn);
        progressBar.setVisibility(View.INVISIBLE);

        currUser=firebaseAuth.getCurrentUser();

        dbRefUser=FirebaseDatabase.getInstance().getReference("Users").child(currUser.getUid());
        dbRefUser.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                User user=snapshot.getValue(User.class);
                currUserTxt.setText(user.getUsername());
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });

        cancelBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i=new Intent(Createpost.this,MainActivity.class);
                startActivity(i);
                finish();
            }
        });
        saveBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                SaveandPublish();
            }
        });
        postImg.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent galeryIntent=new Intent(Intent.ACTION_GET_CONTENT);
                galeryIntent.setType("image/*");
                startActivityForResult(galeryIntent,GALLERY_CODE);
            }
        });
    }
    private void SaveandPublish() {
        final String title = titleET.getText().toString().trim();
        final String duyuru = duyuruET.getText().toString().trim();
        progressBar.setVisibility(View.VISIBLE);
        if (!TextUtils.isEmpty(duyuru) && !TextUtils.isEmpty(title) && imgUri != null) {
            final StorageReference filePath = storageReference
                    .child("PostImages")
                    .child("my_image_" +Timestamp.now().getSeconds() );

            filePath.putFile(imgUri)
                    .addOnSuccessListener(new OnSuccessListener<UploadTask.TaskSnapshot>() {
                        @Override
                        public void onSuccess(UploadTask.TaskSnapshot taskSnapshot) {
                            filePath.getDownloadUrl().addOnSuccessListener(new OnSuccessListener<Uri>() {
                                @Override
                                public void onSuccess(Uri uri) {
                                    String imgUrl=uri.toString();
                                    PostModel postModel=new PostModel();
                                    postModel.setTitle(title);
                                    postModel.setDuyuru(duyuru);
                                    postModel.setImgUrl(imgUrl);
                                    postModel.setUserName(currUserTxt.getText().toString());
                                    postModel.setUserId( currUser.getUid());

                                    //Database
                                    dbRefPosts= FirebaseDatabase.getInstance().getReference("Posts").push();
                                    dbRefPosts.setValue(postModel)
                                            .addOnSuccessListener(new OnSuccessListener<Void>() {
                                                @Override
                                                public void onSuccess(Void aVoid) {
                                                    startActivity(new Intent(Createpost.this,MainActivity.class));
                                                    finish();
                                                }
                                            })
                                            .addOnFailureListener(new OnFailureListener() {
                                                @Override
                                                public void onFailure(@NonNull Exception e) {
                                                    Toast.makeText(getApplicationContext(),"Basarisiz "+e.getMessage(),Toast.LENGTH_SHORT).show();
                                                }
                                            });

                                }
                            }).addOnFailureListener(new OnFailureListener() {
                                @Override
                                public void onFailure(@NonNull Exception e) {
                                    progressBar.setVisibility(View.INVISIBLE);
                                }
                            });
                        }
                    });
        }
        else{
            progressBar.setVisibility(View.INVISIBLE);
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode==GALLERY_CODE && resultCode== Activity.RESULT_OK){
            if(data!=null){
                imgUri=data.getData();
                postImg.setImageURI(imgUri);
            }
        }
    }


}