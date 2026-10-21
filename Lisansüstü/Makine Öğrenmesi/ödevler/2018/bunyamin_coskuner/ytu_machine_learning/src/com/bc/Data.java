package com.bc;

import java.util.List;

public class Data {
    private int docId;
    private int wordId;
    private int count;

    public Data() {
    }

    public Data(List<Integer> row) {
        this.docId = row.get(0);
        this.wordId = row.get(1);
        this.count = row.get(2);
    }

    public int getDocId() {
        return docId;
    }

    public void setDocId(int docId) {
        this.docId = docId;
    }

    public int getWordId() {
        return wordId;
    }

    public void setWordId(int wordId) {
        this.wordId = wordId;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }
}
