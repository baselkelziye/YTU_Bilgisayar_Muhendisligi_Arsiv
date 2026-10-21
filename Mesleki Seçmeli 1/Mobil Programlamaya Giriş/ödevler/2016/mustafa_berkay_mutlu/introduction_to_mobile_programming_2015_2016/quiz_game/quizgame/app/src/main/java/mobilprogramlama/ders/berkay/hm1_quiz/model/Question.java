package mobilprogramlama.ders.berkay.hm1_quiz.model;

/**
 * Created by mberk on 18.11.2015.
 */
public class Question {
    private long questionID;
    private String question;
    private boolean answer;

    public Question(String question, boolean answer){
        this.question = question;
        this.answer = answer;
    }

    public Question(long questionID, String question, boolean answer){
        this.questionID = questionID;
        this.question = question;
        this.answer = answer;
    }

    public long getQuestionID() {
        return questionID;
    }

    public void setQuestionID(long questionID) {
        this.questionID = questionID;
    }

    public String getQuestion() {
        return question;
    }

    public void setQuestion(String question) {
        this.question = question;
    }

    public boolean getAnswer() {
        return answer;
    }

    public void setAnswer(boolean answer) {
        this.answer = answer;
    }
}
