package com.kaansonmezoz.blm3520.notebook.Activities.MainActivity.Model;

public class NoteItem { //TODO: Bunlar hep genisletilecek
    private int id;
    private String title;
    private String lastUpdatedDate;
    private String truncatedWords;

    public NoteItem(){}

    public NoteItem(int id, String title, String lastUpdatedDate, String truncatedWords) {
        this.id = id;
        this.title = title;
        this.lastUpdatedDate = lastUpdatedDate;
        this.truncatedWords = truncatedWords;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getLastUpdatedDate() {
        return lastUpdatedDate;
    }

    public void setLastUpdatedDate(String lastUpdatedDate) {
        this.lastUpdatedDate = lastUpdatedDate;
    }

    public String getTruncatedWords() {
        return truncatedWords;
    }

    public void setTruncatedWords(String truncatedWords) {
        this.truncatedWords = truncatedWords;
    }
}
