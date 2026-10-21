package com.bariscanyilmaz.musicplayer.view.ui.main;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProvider;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import androidx.room.Room;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;

import com.bariscanyilmaz.musicplayer.R;
import com.bariscanyilmaz.musicplayer.databinding.FragmentPlayListBinding;
import com.bariscanyilmaz.musicplayer.model.PlayList;
import com.bariscanyilmaz.musicplayer.model.PlaySong;
import com.bariscanyilmaz.musicplayer.model.Song;
import com.bariscanyilmaz.musicplayer.roomdb.AppDatabase;
import com.bariscanyilmaz.musicplayer.roomdb.PlayListDao;
import com.bariscanyilmaz.musicplayer.roomdb.SongListDataConverter;
import com.bariscanyilmaz.musicplayer.utils.AppSettings;
import com.bariscanyilmaz.musicplayer.utils.SaveSystem;
import com.bariscanyilmaz.musicplayer.view.MainActivity;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link PlayListFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class PlayListFragment extends Fragment {

    private AppDatabase db;
    private PlayListDao playListDao;
    private FragmentPlayListBinding binding;

    private PlayListViewModel playListViewModel;
    RecyclerView playListRecyclerView;
    PlayListDataAdapter playListDataAdapter;

    private SongViewModel songViewModel;
    private List<Song> songs;
    private SharedPreferences sharedPreferences;
    private List<PlayList> playLists=new ArrayList<>();

    public static PlayListFragment newInstance() {
        PlayListFragment fragment = new PlayListFragment();

        return fragment;
    }



    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        playListViewModel=new ViewModelProvider(getActivity()).get(PlayListViewModel.class);
        songViewModel=new ViewModelProvider(getActivity()).get(SongViewModel.class);
        db= Room.databaseBuilder(getActivity(), AppDatabase.class,"app-db").allowMainThreadQueries().build();
        playListDao=db.playListDao();
        sharedPreferences=getActivity().getSharedPreferences(AppSettings.APP_SHARED_PREFS, Context.MODE_PRIVATE);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        binding=FragmentPlayListBinding.inflate(inflater,container,false);

        playListViewModel.getPlayLists().observe(getViewLifecycleOwner(), new Observer<List<PlayList>>() {
            @Override
            public void onChanged(List<PlayList> playLists) {

                PlayListFragment.this.playLists=playLists;

                playListDataAdapter.setPlayLists(playLists);
                playListRecyclerView.setAdapter(playListDataAdapter);
            }
        });

        songViewModel.getSongs().observe(getViewLifecycleOwner(), new Observer<List<Song>>() {
            @Override
            public void onChanged(List<Song> songs) {
                PlayListFragment.this.songs=songs;
            }
        });

        playListRecyclerView=binding.playlistRecyclerView;
        playListDataAdapter=new PlayListDataAdapter(getActivity(),deleteList);

        //set playlist here
        playListRecyclerView.setAdapter(playListDataAdapter);

        playListRecyclerView.setLayoutManager(new LinearLayoutManager(getContext()));

        View root=binding.getRoot();

        binding.playListAddNewButton.setOnClickListener(addNewPlayListListener);

        return root;
    }

    private PlayListDataAdapter.OnItemClickListener<PlayList> deleteList=new PlayListDataAdapter.OnItemClickListener<PlayList>() {
        @Override
        public void onItemClick(PlayList data) {

            //show approval
            AlertDialog.Builder alert=new AlertDialog.Builder(getActivity());
            alert.setTitle("Delete List");
            alert.setMessage("Confirm "+data.name+" will be deleted");
            alert.setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialogInterface, int i) {

                    playLists.remove(data);
                    SaveSystem.savePlayList(sharedPreferences,playLists);
                    playListViewModel.setPlayLists(playLists);
                    dialogInterface.dismiss();
                }
            });

            //
            alert.setNegativeButton("No", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialogInterface, int i) {
                    dialogInterface.cancel();
                }
            });

            alert.show();
        }
    };



    private View.OnClickListener addNewPlayListListener=new View.OnClickListener() {

        @Override
        public void onClick(View view) {
            AlertDialog.Builder builder=new AlertDialog.Builder(getContext());

            builder.setTitle("New Play List");

            final EditText input=new EditText(getContext());

            builder.setView(input);

            positiveButtonHandler(builder,input);

            builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialogInterface, int i) {
                    dialogInterface.cancel();
                }
            });

            builder.show();
        }
    };

    private void positiveButtonHandler(AlertDialog.Builder builder,EditText input){

        builder.setPositiveButton("Add", new DialogInterface.OnClickListener() {

            @Override
            public void onClick(DialogInterface dialogInterface, int a) {

                String playListName= input.getText().toString();
                boolean[] checkedItems=new boolean[songs.size()];
                String[] s=new String[songs.size()];

                for (int k=0;k<s.length;k++) {
                    s[k]=(songs.get(k).name);
                }

                AlertDialog.Builder builder=new AlertDialog.Builder(getContext());
                builder.setMultiChoiceItems(s, checkedItems, new DialogInterface.OnMultiChoiceClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int choiceIndex, boolean b) {
                        checkedItems[choiceIndex]=b;
                    }
                });

                builder.setPositiveButton("Add", new DialogInterface.OnClickListener() {

                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                        ArrayList<Song> chosens=new ArrayList<>();
                        for (int j=0;j<checkedItems.length;j++){
                            if(checkedItems[j]){
                                chosens.add(PlayListFragment.this.songs.get(j));
                            }
                        }
                        addChosensToList(chosens,playListName);
                    }
                });

                builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                        dialogInterface.cancel();
                    }
                });
                builder.show();
            }
        });
    }

    private void addChosensToList(List<Song> songs,String listName){

            PlayList list= new PlayList(listName);
            list.songList=songs;
            this.playLists.add(list);

            SaveSystem.savePlayList(sharedPreferences,playLists);
            playListViewModel.setPlayLists(this.playLists);

    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();
        binding=null;
    }
}