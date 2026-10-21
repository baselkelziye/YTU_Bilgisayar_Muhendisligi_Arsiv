package com.barissemerci.sanaldolabim;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class CekmeceleriGor extends AppCompatActivity {
    CekmeceleriGorAdapter cekmeceleriGorAdapter;
    String nereden;
private CekmeceleriGorAdapter.RecyclerViewClickListener recyclerViewClickListener;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cekmeceleri_gor);
        Intent intent=getIntent();
        EtkinlikActivity.secilenKiyafet=-1;
        nereden=intent.getStringExtra("nereden");
        setOnClickListener();
        RecyclerView recyclerView= findViewById(R.id.recyclerViewCekmeceleriGor);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
         cekmeceleriGorAdapter= new CekmeceleriGorAdapter(MainActivity.cekmeceler,recyclerViewClickListener);
         recyclerView.setAdapter(cekmeceleriGorAdapter);
        cekmeceleriGorAdapter.notifyDataSetChanged();
    }

    private void setOnClickListener() {
    recyclerViewClickListener= new CekmeceleriGorAdapter.RecyclerViewClickListener() {

    @Override
    public void onClick(View v, int position) {
        Intent intent;
        if(nereden.equals("main")){
             intent= new Intent(getApplicationContext(),CekmeceActivity.class);

        }
        else{
             intent= new Intent(getApplicationContext(),CekmecedekiKiyafetler.class);
            intent.putExtra("nereden",nereden);

        }

        startActivity(intent);
        MainActivity.secilenCekmece=MainActivity.cekmeceler.get(position);
        finish();
    }
};


    }







}