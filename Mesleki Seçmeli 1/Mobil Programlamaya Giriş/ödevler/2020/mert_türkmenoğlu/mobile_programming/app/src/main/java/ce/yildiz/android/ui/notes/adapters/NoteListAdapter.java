package ce.yildiz.android.ui.notes.adapters;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

import ce.yildiz.android.R;
import ce.yildiz.android.models.Note;
import ce.yildiz.android.interfaces.RecyclerViewClickListener;

public class NoteListAdapter extends RecyclerView.Adapter<NoteListAdapter.NoteViewHolder> {
    private List<Note> mNotes;
    private RecyclerViewClickListener mListener;

    static class NoteViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener {
        TextView noteNameTV;
        RecyclerViewClickListener mListener;

        NoteViewHolder(View view, RecyclerViewClickListener listener) {
            super(view);
            mListener = listener;
            view.setOnClickListener(this);

            noteNameTV = view.findViewById(R.id.note_list_item_note_name);
        }

        @Override
        public void onClick(View v) {
            mListener.onClick(v, getAdapterPosition());
        }
    }

    public NoteListAdapter(List<Note> notes, RecyclerViewClickListener listener) {
        this.mNotes = notes;
        this.mListener = listener;
    }

    @NonNull
    @Override
    public NoteViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View itemView = LayoutInflater
                .from(parent.getContext())
                .inflate(R.layout.note_list_item, parent, false);

        return new NoteViewHolder(itemView, mListener);
    }

    @Override
    public void onBindViewHolder(@NonNull NoteViewHolder holder, int position) {
        Note note = mNotes.get(position);
        holder.noteNameTV.setText(note.getNoteName());
    }

    @Override
    public int getItemCount() {
        return mNotes.size();
    }
}
