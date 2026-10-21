package com.bariscanyilmaz.musicplayer.view.ui.main;

import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProvider;

import android.os.Handler;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.SeekBar;
import android.widget.TextView;

import com.bariscanyilmaz.musicplayer.R;
import com.bariscanyilmaz.musicplayer.databinding.FragmentPlayerBinding;
import com.bariscanyilmaz.musicplayer.model.PlaySong;
import com.bariscanyilmaz.musicplayer.model.Song;
import com.bariscanyilmaz.musicplayer.utils.MediaPlayerController;
import com.bariscanyilmaz.musicplayer.utils.TimeConverter;
import com.bariscanyilmaz.musicplayer.view.MainActivity;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link PlayerFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class PlayerFragment extends Fragment {

    private FragmentPlayerBinding binding;

    private MediaPlayerViewModel mpViewModel;
    private PlaySong playSong;
    MediaPlayer mediaPlayer= MediaPlayerController.getInstance();

    TextView currentTime,totalTime,musicName,artistName;
    SeekBar seekBar;
    ImageButton playPause,next,prev;
    public static PlayerFragment newInstance() {
        PlayerFragment fragment = new PlayerFragment();

        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mpViewModel=new ViewModelProvider(getActivity()).get(MediaPlayerViewModel.class);

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        binding= FragmentPlayerBinding.inflate(inflater,container,false);

        currentTime=binding.playerCurrentTime;
        totalTime=binding.playerTotalTime;
        artistName=binding.playerArtist;
        musicName=binding.playerSong;
        currentTime.setText("0:00");
        seekBar=binding.playerSeekBar;

        View root = binding.getRoot();


        mpViewModel.getChosenSong().observe(getViewLifecycleOwner(), new Observer<PlaySong>() {

            @Override
            public void onChanged(PlaySong playSong) {
                PlayerFragment.this.playSong=playSong;
                Song song= playSong.songs.get(playSong.index);
                totalTime.setText(TimeConverter.convertToMMSS(song.duration));
                musicName.setText(song.name);
                artistName.setText(song.artist);
                currentTime.setText("0:00");
                seekBar.setMax(Integer.parseInt(song.duration));

            }

        });

        seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                //change player time
                if (mediaPlayer!=null && fromUser){
                    mediaPlayer.seekTo(progress);

                    currentTime.setText(TimeConverter.convertToMMSS(Integer.toString(mediaPlayer.getCurrentPosition())));
                }


            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

        playPause=binding.playerPlayPause;
        next=binding.playerNext;
        prev=binding.playerPrevious;

        playPause.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(mediaPlayer==null) return;

                if (mediaPlayer.isPlaying()){
                    mediaPlayer.pause();
                }else {
                    mediaPlayer.start();
                }

            }
        });

        return root;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        getActivity().runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if(mediaPlayer!=null && playSong!=null){
                    seekBar.setProgress(mediaPlayer.getCurrentPosition());
                    currentTime.setText(TimeConverter.convertToMMSS(mediaPlayer.getCurrentPosition()+""));

                    if(mediaPlayer.isPlaying()){
                        playPause.setImageResource(R.drawable.ic_baseline_pause_24);
                    }else{
                        playPause.setImageResource(R.drawable.ic_baseline_play_arrow);

                    }

                }
                new Handler().postDelayed(this,100);
            }
        });
    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();
        binding=null;
    }


}