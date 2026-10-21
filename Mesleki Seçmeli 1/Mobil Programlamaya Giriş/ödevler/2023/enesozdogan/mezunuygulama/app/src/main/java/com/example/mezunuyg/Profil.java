package com.example.mezunuyg;

import android.app.Activity;
import android.app.ProgressDialog;
import android.content.ContentResolver;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.webkit.MimeTypeMap;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.bumptech.glide.Glide;
import com.google.android.gms.tasks.Continuation;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;
import com.google.firebase.storage.StorageTask;
import com.google.firebase.storage.UploadTask;

import java.util.HashMap;


public class Profil extends Fragment {

    EditText username,city,year,phone,company,education;
    ImageView profilPic;
    Button saveBTN;
    //Database
    DatabaseReference dbRef;
    FirebaseUser currUser;

    StorageReference storageReference;
    private static final int IMAGE_REQUEST=1;
    private Uri imageUri;
    private StorageTask uploadTask;
    String imgURL;
    public Profil() {
        // Required empty public constructor
    }



    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view=inflater.inflate(R.layout.fragment_profil,container,false);
        username=view.findViewById(R.id.userNameETprofil);
        city=view.findViewById(R.id.cityETprofil);
        year=view.findViewById(R.id.yearETprofil);
        phone=view.findViewById(R.id.phoneETprofil);
        company=view.findViewById(R.id.companyETprofil);
        education=view.findViewById(R.id.educationETprofil);
        profilPic=view.findViewById(R.id.profilPic);
        saveBTN=view.findViewById(R.id.saveProfileBtn);

        storageReference= FirebaseStorage.getInstance().getReference("uploads");
        currUser= FirebaseAuth.getInstance().getCurrentUser();
        dbRef= FirebaseDatabase.getInstance().getReference("Users").child(currUser.getUid());

        dbRef.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                User user=snapshot.getValue(User.class);
                username.setText(user.getUsername());
                city.setText(user.getCity());
                year.setText(user.getYear());
                phone.setText(user.getPhone());
                company.setText(user.getCompany());
                education.setText(user.getEducation());
                imgURL=user.getImageURL();
                if(user.getImageURL().equals("default")){
                    profilPic.setImageResource(R.mipmap.ic_launcher);
                }
                else{

                    Glide.with(getContext()).load(user.getImageURL()).into(profilPic);
                }

            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });

        saveBTN.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                HashMap<String,Object> regMap=new HashMap<>();
                regMap.put("username",username.getText().toString());
                regMap.put("imageURL",imgURL);
                regMap.put("year",year.getText().toString());
                regMap.put("city",city.getText().toString());
                regMap.put("phone",phone.getText().toString());
                regMap.put("Company",company.getText().toString());
                regMap.put("Education",education.getText().toString());

                dbRef.updateChildren(regMap).addOnCompleteListener(new OnCompleteListener<Void>() {
                    @Override
                    public void onComplete(@NonNull Task<Void> task) {
                        if(task.isSuccessful()){
                            Toast.makeText(getContext(), "Guncelleme basarili", Toast.LENGTH_SHORT).show();
                        }
                    }
                });


            }

        });

        profilPic.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                SelectImage();
            }
        });
        return view;
    }
    private void SelectImage(){
        Intent i =new Intent();
        i.setType("image/*");
        i.setAction(Intent.ACTION_GET_CONTENT);
        startActivityForResult(i,IMAGE_REQUEST);
    }

    private String getFileExtension(Uri uri){
        ContentResolver contentResolver=getContext().getContentResolver();
        MimeTypeMap mimeTypeMap=MimeTypeMap.getSingleton();
        return mimeTypeMap.getExtensionFromMimeType(contentResolver.getType(uri));
    }
    private void UploadImage(){
        final ProgressDialog progressDialog=new ProgressDialog(getContext());
        progressDialog.setMessage("Yükleniyor");
        progressDialog.show();

        if(imageUri!=null){
            final StorageReference fileRef=storageReference.child(System.currentTimeMillis()
            +"."+getFileExtension(imageUri));
            uploadTask=fileRef.putFile(imageUri);
            uploadTask.continueWithTask(new Continuation<UploadTask.TaskSnapshot,Task<Uri>>() {
                @Override
                public Task<Uri> then(@NonNull Task<UploadTask.TaskSnapshot> task) throws Exception {
                    if(!task.isSuccessful()){
                        throw task.getException();
                    }
                    return fileRef.getDownloadUrl();
                }
            }).addOnCompleteListener(new OnCompleteListener<Uri>() {
                @Override
                public void onComplete(@NonNull Task<Uri> task) {
                    if(task.isSuccessful()){
                        Uri downloadUri=task.getResult();
                        String mUri=downloadUri.toString();
                        dbRef=FirebaseDatabase.getInstance().getReference("Users").child(currUser.getUid());
                        HashMap<String,Object> map=new HashMap<>();
                        map.put("imageURL",mUri);
                        dbRef.updateChildren(map);
                        progressDialog.dismiss();
                    }
                    else{
                        Toast.makeText(getContext(),"Basarisiz",Toast.LENGTH_SHORT).show();
                    }
                }
            }).addOnFailureListener(new OnFailureListener() {
                @Override
                public void onFailure(@NonNull Exception e) {
                    Toast.makeText(getContext(),e.getMessage(),Toast.LENGTH_SHORT).show();
                    progressDialog.dismiss();
                }
            });
        }else{
            Toast.makeText(getContext(), "Resim Yok", Toast.LENGTH_SHORT).show();
        }

    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode==IMAGE_REQUEST && resultCode== Activity.RESULT_OK && data!=null && data.getData()!=null){
                imageUri= data.getData();
                if(uploadTask!=null && uploadTask.isInProgress()){
                    Toast.makeText(getContext(), "Yukleniyor..", Toast.LENGTH_SHORT).show();
                }
                else{
                    UploadImage();
                }
        }
    }
}