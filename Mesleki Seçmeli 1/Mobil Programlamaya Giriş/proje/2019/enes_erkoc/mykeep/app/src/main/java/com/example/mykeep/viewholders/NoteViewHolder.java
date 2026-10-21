package com.example.mykeep.viewholders;

import android.support.annotation.NonNull;
import android.support.v7.widget.CardView;
import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.widget.TextView;

import com.example.mykeep.R;

/**
 * Created by SUDA on 08-09-2017.
 */

public class NoteViewHolder extends RecyclerView.ViewHolder {

    private View mView;

    private TextView textTitle, textContent, textTime, textReminder;
    private CardView noteCard;

    public NoteViewHolder(View itemView) {
        super(itemView);

        mView = itemView;

        textTitle = mView.findViewById(R.id.note_title);
        textContent = mView.findViewById(R.id.note_content);
        textTime = mView.findViewById(R.id.note_time);
        textReminder = mView.findViewById(R.id.note_reminder);
        noteCard = mView.findViewById(R.id.note_card);

    }

    public TextView getTextTitle() {
        return textTitle;
    }

    public void setTextTitle(TextView textTitle) {
        this.textTitle = textTitle;
    }

    public TextView getTextContent() {
        return textContent;
    }

    public void setTextContent(TextView textContent) {
        this.textContent = textContent;
    }

    public TextView getTextTime() {
        return textTime;
    }

    public void setTextTime(TextView textTime) {
        this.textTime = textTime;
    }

    public TextView getTextReminder() {
        return textReminder;
    }

    public void setTextReminder(TextView textReminder) {
        this.textReminder = textReminder;
    }

    public CardView getNoteCard() {
        return noteCard;
    }

    public void setNoteCard(CardView noteCard) {
        this.noteCard = noteCard;
    }

    public void setNoteTitle(String title) {
        textTitle.setText(title);
    }

    public void setNoteContent(String content) {
        textContent.setText(content);
    }


    public void setNoteTime(String time) {
        textTime.setText(time);
    }
    public void setNoteReminder(String reminder) {
        textTime.setText(reminder);
    }



}
