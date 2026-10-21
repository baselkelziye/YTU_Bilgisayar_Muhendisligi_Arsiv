package ahmetsefacetin;

public class Exam {

    private String date;
    private double score;

    public Exam(String date) {
        this.date = date;
    }

    /**
     * @return the score
     */
    public double getScore() {
        return score;
    }

    /**
     * @param score the score to set
     */
    public void setScore(double score) {
        this.score = score;
    }

    @Override
    public String toString() {
        return "exam=Exam [score=" + score + "]";
    }

    

}
