package com.example.mykeep.models;

public class NoteModel {

    public String noteTitle;
    public String noteContent;
    public String noteReminder;
    public boolean isReminderSetted;
    public String noteTime;


    public NoteModel() {

    }


    public NoteModel(String noteTitle, String noteContent, String noteReminder, boolean isReminderSetted, String noteTime) {
        this.noteTitle = noteTitle;
        this.noteContent = noteContent;
        this.noteReminder = noteReminder;
        this.isReminderSetted = isReminderSetted;
        this.noteTime = noteTime;
    }

    public String getNoteTitle() {
        return noteTitle;
    }

    public void setNoteTitle(String noteTitle) {
        this.noteTitle = noteTitle;
    }

    public String getNoteTime() {
        return noteTime;
    }

    public void setNoteTime(String noteTime) {
        this.noteTime = noteTime;
    }

    public String getNoteContent() {
        return noteContent;
    }

    public void setNoteContent(String noteContent) {
        this.noteContent = noteContent;
    }

    public String getNoteReminder() {
        return noteReminder;
    }

    public void setNoteReminder(String noteReminder) {
        this.noteReminder = noteReminder;
    }

    public boolean isReminderSetted() {
        return isReminderSetted;
    }

    public void setReminderSetted(boolean reminderSetted) {
        isReminderSetted = reminderSetted;
    }
}
