package com.barissemerci.sanaldolabim;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class EtkinlikleriGor extends AppCompatActivity {
    EtkinlikleriGorAdapter etkinlikleriGorAdapter;
    private EtkinlikleriGorAdapter.RecyclerViewClickListener recyclerViewClickListener;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_etkinlikleri_gor);

        RecyclerView recyclerView=findViewById(R.id.recyclerViewEtkinlikleriGor);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        setOnClickListener();
        etkinlikleriGorAdapter= new EtkinlikleriGorAdapter(MainActivity.etkinlikler,recyclerViewClickListener);
        recyclerView.setAdapter(etkinlikleriGorAdapter);
        etkinlikleriGorAdapter.notifyDataSetChanged();
    }

    private void setOnClickListener() {

        recyclerViewClickListener=new EtkinlikleriGorAdapter.RecyclerViewClickListener() {
            @Override
            public void onClick(View v, int position) {
                Intent intent= new Intent(getApplicationContext(),EtkinlikActivity.class);
                intent.putExtra("etkinlikNumarasi",position);
                startActivity(intent);
                finish();
            }
        };

    }
}