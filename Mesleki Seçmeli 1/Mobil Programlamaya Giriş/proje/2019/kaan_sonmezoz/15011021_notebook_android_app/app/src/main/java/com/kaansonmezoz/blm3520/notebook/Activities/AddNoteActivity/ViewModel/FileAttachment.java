package com.kaansonmezoz.blm3520.notebook.Activities.AddNoteActivity.ViewModel;

import android.net.Uri;

public class FileAttachment {
    private String fileName;
    private String filePath;

    public FileAttachment(String fileName, String filePath) {
        this.fileName = fileName;
        this.filePath = filePath;
    }

    public String getFileName() {
        return fileName;
    }

    public void setFileName(String fileName) {
        this.fileName = fileName;
    }

    public String getFilePath() {
        return filePath;
    }

    public void setFilePath(String filePath) {
        this.filePath = filePath;
    }
}
