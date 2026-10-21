package mobil.prog.music_app;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.Manifest;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.View;
import android.widget.TextView;

import java.io.File;
import java.util.ArrayList;

public class SongslistActivity extends AppCompatActivity {

    RecyclerView recyclerView;
    TextView noMusicTextView;
    ArrayList<AudioModel> songsList = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_songslist);
        //----------------------------------------------
        recyclerView = findViewById(R.id.recycler_view);
        noMusicTextView = findViewById(R.id.no_songs_found);

        // izin verilmemişse return
        if(checkPermission() == false){
            requestPermission();
            return;
        }

        String[] projection = {
                MediaStore.Audio.Media.TITLE,
                MediaStore.Audio.Media.DATA,
                MediaStore.Audio.Media.DURATION
        };

        String selection = MediaStore.Audio.Media.IS_MUSIC + " != 0";


        // şarkıları çekme ve alfabetik sıralama
        Cursor cursor = getContentResolver().query(MediaStore.Audio.Media.EXTERNAL_CONTENT_URI, projection, selection, null, "TITLE ASC");
        while(cursor.moveToNext()){
            AudioModel songData = new AudioModel(cursor.getString(1), cursor.getString(0),cursor.getString(2));
            if(new File(songData.getPath()).exists())
                songsList.add(songData);
        }

        if(songsList.size()==0){
            noMusicTextView.setVisibility(View.VISIBLE);
        }
        else{
            // RecyclerView
            recyclerView.setLayoutManager(new LinearLayoutManager(this));
            recyclerView.setAdapter(new MusicListAdapter(songsList, getApplicationContext()));
        }

    }

    // izin yoksa iptal
    boolean checkPermission(){
        int result = ContextCompat.checkSelfPermission(SongslistActivity.this, Manifest.permission.READ_EXTERNAL_STORAGE);
        if(result == PackageManager.PERMISSION_GRANTED){
            return true;
        }
        else{
            return false;
        }
    }


    // izin isteme
    void requestPermission(){
        ActivityCompat.requestPermissions(SongslistActivity.this, new String[] {Manifest.permission.READ_EXTERNAL_STORAGE}, 123);
    }


}