package tr.edu.yildiz.payci.soner.model;

import java.io.Serializable;

public class QuestionMedia implements Serializable {
    private long id;
    private long questionId;
    private String contentType;
    private byte[] content;

    public QuestionMedia(long id, long questionId, String contentType, byte[] content) {
        this.id = id;
        this.questionId = questionId;
        this.contentType = contentType;
        this.content = content;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public long getQuestionId() {
        return questionId;
    }

    public void setQuestionId(long questionId) {
        this.questionId = questionId;
    }

    public String getContentType() {
        return contentType;
    }

    public void setContentType(String contentType) {
        this.contentType = contentType;
    }

    public byte[] getContent() {
        return content;
    }

    public void setContent(byte[] content) {
        this.content = content;
    }
}
