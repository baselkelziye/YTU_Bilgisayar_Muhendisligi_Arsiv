package com.kaansonmezoz.blm3520.notebook.Activities.MainActivity.Adapter;

import android.app.Activity;
import android.app.Application;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.ContextMenu;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.kaansonmezoz.blm3520.notebook.Activities.MainActivity.AlertDialog.ReminderAlertDialog;
import com.kaansonmezoz.blm3520.notebook.Database.Repository.Note.NoteRepository;
import com.kaansonmezoz.blm3520.notebook.Database.Repository.NoteInfo.NoteInfoRepository;
import com.kaansonmezoz.blm3520.notebook.R;
import com.kaansonmezoz.blm3520.notebook.ViewModel.NoteWithInfoViewModel;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.List;
import java.util.concurrent.ExecutionException;

public class NoteAdapter extends RecyclerView.Adapter<NoteAdapter.NoteViewHolder> {
    private  List<NoteWithInfoViewModel> noteItems;
    private Application application;
    private Activity activity;

    public NoteAdapter(Application application, Activity activity){
        this.application = application;
        this.activity = activity;
    }

    public NoteAdapter(List<NoteWithInfoViewModel> noteItems){
        this.noteItems = noteItems;
    }

    public NoteAdapter.NoteViewHolder onCreateViewHolder(ViewGroup parent, int viewType){
        final View itemView = LayoutInflater.from(parent.getContext()).inflate(R.layout.recycler_view_note_item, parent, false);

        itemView.setOnClickListener(new View.OnClickListener(){
            public void onClick(View view){
                //TODO: Note details should be opened in a different activity
                Log.d("MainActivity", "Note details clicked");
            }
        });

        return new NoteViewHolder(itemView, parent);
    }

    public void onBindViewHolder(NoteViewHolder holder, int position){
        NoteWithInfoViewModel noteItem = noteItems.get(position);

        String pattern = "MM/dd/yyyy HH:mm:ss";
        DateFormat dateFormat = new SimpleDateFormat(pattern);

        holder.firstCharacters.setText(noteItem.getNote().priority);
        holder.title.setText(noteItem.getNote().title);
        holder.lastUpdateDate.setText(dateFormat.format(noteItem.getNoteInfo().lastUpdatedDate));
    }

    public int getItemCount(){
        return noteItems != null ? noteItems.size(): 0;
    }

    public void removeAt(int position) {
        NoteWithInfoViewModel noteItem  = noteItems.get(position);

        NoteRepository noteRepository = new NoteRepository(application);
        NoteInfoRepository noteInfoRepository = new NoteInfoRepository(application);

        try {
            noteInfoRepository.deleteNoteInfoById(noteItem.getNoteInfo().id);
            noteRepository.deleteNoteById(noteItem.getNote().id);
        } catch (ExecutionException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }


        noteItems.remove(position);
        notifyItemRemoved(position);
        notifyItemRangeChanged(position, noteItems.size());



    }

    public void setNoteItems(List<NoteWithInfoViewModel> noteItems){
        this.noteItems = noteItems;
        notifyDataSetChanged();
    }

    public class NoteViewHolder extends RecyclerView.ViewHolder{
        public TextView title;
        public TextView lastUpdateDate;
        public TextView firstCharacters;

        public NoteViewHolder(View view,final ViewGroup parent){
            super(view);
            //TODO: ContextMenu yerine belki de popup olusturmak daha mantikli olabilir ?
            //todo: kod acayip bir sekilde cirkinlesmeye basladi bunu bir guzel refactor etmek lazim

            view.setOnCreateContextMenuListener(new View.OnCreateContextMenuListener(){     //TODO: Bunun alternatiflerine de bakmak da yarar var
                public void onCreateContextMenu(ContextMenu menu, final View view, ContextMenu.ContextMenuInfo menuInfo){
                    menu.add("Delete").setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
                        @Override
                        public boolean onMenuItemClick(MenuItem menuItem) {
                            int position = getAdapterPosition();
                            removeAt(position);
                            Log.d("MainActivity", "Delete clicked");
                            return false;
                        }
                    });
                    menu.add("Set Reminder").setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
                        @Override
                        public boolean onMenuItemClick(MenuItem menuItem) {
                            Log.d("MainActivity", "Set Reminder clicked");
                            String alarmTitle = noteItems.get(getAdapterPosition()).getNote().title;
                            ReminderAlertDialog alertDialog = new ReminderAlertDialog(activity, alarmTitle);
                            alertDialog.showAlertDialog();
                            return false;
                        }
                    });
                    menu.add("Share").setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
                        @Override
                        public boolean onMenuItemClick(MenuItem menuItem) {
                            Log.d("MainActivity", "Share clicked");
                            return false;
                        }
                    });
                }
            });

            title = view.findViewById(R.id.note_title);
            lastUpdateDate = view.findViewById(R.id.note_last_update_date);
            firstCharacters = view.findViewById(R.id.note_content);
        }
    }
}
