package com.example.mykeep;

import android.content.Intent;
import android.content.res.Resources;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.StaggeredGridLayoutManager;
import android.util.Log;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;


import com.example.mykeep.models.NoteModel;
import com.example.mykeep.viewholders.NoteViewHolder;
import com.firebase.ui.database.FirebaseRecyclerAdapter;
import com.firebase.ui.database.FirebaseRecyclerOptions;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.Query;
import com.google.firebase.database.ValueEventListener;

public class NotesFragment extends Fragment {

    private FirebaseAuth fAuth;
    private RecyclerView mNotesList;
    private StaggeredGridLayoutManager gridLayoutManager;

    private DatabaseReference fNotesDatabase;
    private FirebaseRecyclerAdapter<NoteModel, NoteViewHolder> firebaseRecyclerAdapter;

    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setHasOptionsMenu(true);

        ((HomeActivity) getActivity())
                .getSupportActionBar().setTitle("Notes");
    }

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_notes, container, false);

        mNotesList = (RecyclerView) v.findViewById(R.id.notes_list);

        gridLayoutManager = new StaggeredGridLayoutManager(2, StaggeredGridLayoutManager.VERTICAL);

        //mNotesList.setHasFixedSize(true);
        mNotesList.setLayoutManager(gridLayoutManager);

        mNotesList.addItemDecoration(new GridSpacingItemDecoration(2, dpToPx(10), true));

        fAuth = FirebaseAuth.getInstance();

        updateUI();

        if (fAuth.getCurrentUser() != null) {
            fNotesDatabase = FirebaseDatabase.getInstance().getReference().child("notes").child(fAuth.getCurrentUser().getUid());
            loadData();


        }

        return v;
    }

    @Override
    public void onStart() {
        super.onStart();
        loadData();
        firebaseRecyclerAdapter.startListening();

    }

    @Override
    public void onStop() {
        super.onStop();
        firebaseRecyclerAdapter.stopListening();
    }

    private void updateUI(){

        if (fAuth.getCurrentUser() != null){
            Log.i("MainActivity", "fAuth != null");
        } else {
            Intent startIntent = new Intent(getActivity(), StartActivity.class);
            startActivity(startIntent);
            getActivity().finish();
            Log.i("MainActivity", "fAuth == null");
        }
    }

    private void loadData() {
        Query query = fNotesDatabase.orderByValue();

        FirebaseRecyclerOptions noteOptions = new FirebaseRecyclerOptions.Builder<NoteModel>().setQuery(query, NoteModel.class).build();
        firebaseRecyclerAdapter = new FirebaseRecyclerAdapter<NoteModel, NoteViewHolder>(
                noteOptions) {
            @NonNull
            @Override
            public NoteViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int i) {
                View view = LayoutInflater.from(parent.getContext())
                        .inflate(R.layout.single_note_layout, parent, false);

                return new NoteViewHolder(view);
            }

            @Override
            protected void onBindViewHolder(final NoteViewHolder viewHolder, int position, @NonNull NoteModel model) {
                final String noteId = getRef(position).getKey();

                fNotesDatabase.child(noteId).addValueEventListener(new ValueEventListener() {
                    @Override
                    public void onDataChange(DataSnapshot dataSnapshot) {
                        if (dataSnapshot.hasChild("title") && dataSnapshot.hasChild("timestamp")) {
                            String title = dataSnapshot.child("title").getValue().toString();
                            String content = dataSnapshot.child("content").getValue().toString();
                            String timestamp = dataSnapshot.child("timestamp").getValue().toString();
                            String reminder = dataSnapshot.child("reminder").getValue().toString();

                            viewHolder.setNoteTitle(title);
                            viewHolder.setNoteContent(content);

                            //TimeInfo getTimeAgo = new TimeInfo();
                            viewHolder.setNoteReminder(reminder);
                            viewHolder.setNoteTime(TimeInfo.getTimeAgo(Long.parseLong(timestamp)));

                            viewHolder.getNoteCard().setOnClickListener(new View.OnClickListener() {
                                @Override
                                public void onClick(View view) {
                                    Intent intent = new Intent(getActivity(), NoteActivity.class);
                                    intent.putExtra("noteId", noteId);
                                    startActivity(intent);
                                }
                            });
                        }

                    }

                    @Override
                    public void onCancelled(DatabaseError databaseError) {

                    }
                });
            }
        };
        mNotesList.setAdapter(firebaseRecyclerAdapter);
        //firebaseRecyclerAdapter.startListening();


    }
    @Override
    public void onCreateOptionsMenu(Menu menu, MenuInflater inflater) {
        inflater.inflate(R.menu.main_menu, menu);
        super.onCreateOptionsMenu(menu, inflater);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        super.onOptionsItemSelected(item);

        switch (item.getItemId()) {
            case R.id.main_new_note_btn:
                Intent newIntent = new Intent(getActivity(), NoteActivity.class);
                startActivity(newIntent);
                break;
        }

        return true;
    }

    private int dpToPx(int dp) {
        Resources r = getResources();
        return Math.round(TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, dp, r.getDisplayMetrics()));
    }
}
