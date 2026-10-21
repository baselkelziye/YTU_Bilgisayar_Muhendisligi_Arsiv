package com.bariscanyilmaz.musicplayer.view.ui.main;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProvider;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.bariscanyilmaz.musicplayer.R;
import com.bariscanyilmaz.musicplayer.databinding.PlayListBottomSheetDialogBinding;
import com.bariscanyilmaz.musicplayer.model.PlayList;
import com.bariscanyilmaz.musicplayer.model.PlaySong;
import com.bariscanyilmaz.musicplayer.model.Song;
import com.google.android.material.bottomsheet.BottomSheetDialogFragment;

import java.util.List;


public class PlayListBottomSheetDialogFragment extends BottomSheetDialogFragment {

    //use live data again
    private MediaPlayerViewModel mpViewModel;

    private PlayListBottomSheetDialogBinding binding;
    private PlayList playList;
    private List<PlayList> playLists;
    public PlayListBottomSheetDialogFragment(PlayList playList) {
        // Required empty public constructor
        this.playList=playList;
    }

    RecyclerView recyclerView;
    PlayListBottomSheetDataAdapter dataAdapter;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        mpViewModel=new ViewModelProvider(getActivity()).get(MediaPlayerViewModel.class);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        binding=PlayListBottomSheetDialogBinding.inflate(inflater,container,false);


        recyclerView=binding.bottomSheetRecyclerView;
        dataAdapter=new PlayListBottomSheetDataAdapter(this.playList.songList, new PlayListBottomSheetDataAdapter.OnItemClickListener<PlaySong>() {
            @Override
            public void onItemClick(PlaySong data) {
                mpViewModel.setChosenSong(data);
            }
        });
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));
        recyclerView.setAdapter(dataAdapter);

        // Inflate the layout for this fragment
        View root=binding.getRoot();

        return root;

    }
}