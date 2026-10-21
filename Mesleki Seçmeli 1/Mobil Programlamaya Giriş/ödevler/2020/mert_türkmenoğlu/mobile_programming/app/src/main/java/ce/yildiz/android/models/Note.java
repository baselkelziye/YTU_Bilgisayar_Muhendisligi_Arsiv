package ce.yildiz.android.models;

@SuppressWarnings("unused")
public class Note {
    private String noteName;
    private String content;

    public Note(String noteName, String content) {
        this.noteName = noteName;
        this.content = content;
    }

    public String getNoteName() {
        return noteName;
    }

    public void setNoteName(String noteName) {
        this.noteName = noteName;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }
}
