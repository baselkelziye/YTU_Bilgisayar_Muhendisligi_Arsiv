package com.example.mezunuyg;

import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;

import java.util.ArrayList;
import java.util.List;


public class Gonderiler extends Fragment {

    private FirebaseAuth firebaseAuth;
    private FirebaseAuth.AuthStateListener authStateListener;
    private FirebaseUser currUser;
    private DatabaseReference dbRefUser;
    private DatabaseReference dbRefPost;

    private StorageReference storageReference;
    private List<PostModel> postList;
    private RecyclerView recyclerView;
    private PostRecyclerAdapter  postRecyclerAdapter;

    public Gonderiler() {
        // Required empty public constructor
    }



    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view=inflater.inflate(R.layout.fragment_gonderiler,container,false);
        //Database
        storageReference= FirebaseStorage.getInstance().getReference("PostImages");
        currUser= FirebaseAuth.getInstance().getCurrentUser();
        firebaseAuth=FirebaseAuth.getInstance();
        //Views
        recyclerView=view.findViewById(R.id.postRecyclerView);
        recyclerView.setHasFixedSize(true);
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));
        postList=new ArrayList<>();


        return view;
    }

    @Override
    public void onStart() {
        super.onStart();
        dbRefPost= FirebaseDatabase.getInstance().getReference().child("Posts");
        dbRefPost.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                if(snapshot.exists()){
                    for(DataSnapshot post: snapshot.getChildren()){
                        PostModel postModel=post.getValue(PostModel.class);
                        postList.add(postModel);
                    }
                    //Adapter
                    postRecyclerAdapter= new PostRecyclerAdapter(getContext(),postList);
                    recyclerView.setAdapter(postRecyclerAdapter);
                    postRecyclerAdapter.notifyDataSetChanged();

                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {
                Toast.makeText(getContext(),"Basarisiz",Toast.LENGTH_SHORT).show();
            }
        });
    }
}