package mobilprogramlama.ders.berkay.hm1_quiz.model;

/**
 * Created by mberk on 18.11.2015.
 */
public class PlayerAnswer {
    private long playerAnswerID;
    private long questionID;
    private long playerID;
    private boolean playerAnswer;

    public PlayerAnswer(long questionID, long playerID, boolean playerAnswer){
        this.questionID = questionID;
        this.playerID = playerID;
        this.playerAnswer = playerAnswer;
    }

    public PlayerAnswer(long playerAnswerID, long questionID, long playerID, boolean playerAnswer){
        this.playerAnswerID = playerAnswerID;
        this.questionID = questionID;
        this.playerID = playerID;
        this.playerAnswer = playerAnswer;
    }

    public long getPlayerAnswerID() {
        return playerAnswerID;
    }

    public void setPlayerAnswerID(long playerAnswerID) {
        this.playerAnswerID = playerAnswerID;
    }

    public long getQuestionID() {
        return questionID;
    }

    public void setQuestionID(long questionID) {
        this.questionID = questionID;
    }

    public long getPlayerID() {
        return playerID;
    }

    public void setPlayerID(long playerID) {
        this.playerID = playerID;
    }

    public boolean getPlayerAnswer() {
        return playerAnswer;
    }

    public void setPlayerAnswer(boolean playerAnswer) {
        this.playerAnswer = playerAnswer;
    }
}
