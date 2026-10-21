package com.barissemerci.sanaldolabim;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class KombinleriGor extends AppCompatActivity {
    KombinleriGorAdapter kombinleriGorAdapter;
    private KombinleriGorAdapter.RecyclerViewClickListener recyclerViewClickListener;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_kombin_paylasma);
        RecyclerView recyclerView=findViewById(R.id.recyclerViewKombinleriGor);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        setOnClickListener();
         kombinleriGorAdapter= new KombinleriGorAdapter(MainActivity.kombinler,recyclerViewClickListener);
         recyclerView.setAdapter(kombinleriGorAdapter);
        kombinleriGorAdapter.notifyDataSetChanged();
    }

    private void setOnClickListener() {
        recyclerViewClickListener= new KombinleriGorAdapter.RecyclerViewClickListener() {
            @Override
            public void onClick(View v, int position) {
                Intent intent= new Intent(getApplicationContext(),KabinActivity.class);
                intent.putExtra("kombinNumarasi",position);
                KabinActivity.ilkMi=-1;
                KabinActivity.kombinGuncellemeMi=1;
                startActivity(intent);
                finish();
            }
        };
    }
}