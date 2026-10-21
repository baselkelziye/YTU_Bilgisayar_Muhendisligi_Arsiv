package com.example.mezunuyg;

import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.text.Editable;
import android.text.TextWatcher;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;

import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;


public class Mezunlar extends Fragment {

    private EditText aramaET;
    private RecyclerView recyclerView;
    private MezunAdapter mezunAdapter;
    private List<User> mezunList;

    public Mezunlar() {
        // Required empty public constructor
    }




    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view=inflater.inflate(R.layout.fragment_mezunlar,container,false);
        recyclerView=view.findViewById(R.id.recyclerView);
        recyclerView.setHasFixedSize(true);
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));
        mezunList=new ArrayList<>();
        ReadMezun();
        return view;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        //Arama Cubugu

        aramaET= view.findViewById(R.id.searchET);
        aramaET.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

            }

            @Override
            public void afterTextChanged(Editable s) {
                filtrele(s.toString());
            }
        });
    }

    private void filtrele(String text){
        ArrayList<User> filtreliListe=new ArrayList<>();
        for(User user:mezunList){
            if(user.getUsername().toLowerCase().contains(text.toLowerCase())){
                filtreliListe.add(user);
            }
        }
        mezunAdapter.mezunFiltrele(filtreliListe);
    }
    private void ReadMezun(){
        final FirebaseUser firebaseUser= FirebaseAuth.getInstance().getCurrentUser();
        DatabaseReference dbRef= FirebaseDatabase.getInstance().getReference("Users");
        dbRef.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                mezunList.clear();
                for (DataSnapshot snapshot : dataSnapshot.getChildren()){
                    System.out.println(snapshot);
                    User user=snapshot.getValue(User.class);
                    System.out.println("Kullanici Adi: "+user.getUsername() );

                    assert user!=null;
                    if(!user.getId().equals(firebaseUser.getUid())){
                        mezunList.add(user);
                    }


                }
                System.out.println(mezunList);
                mezunAdapter=new MezunAdapter(getContext(),mezunList);
                recyclerView.setAdapter(mezunAdapter);


            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });
    }
}