package tariktaskin;

public class Exam {
	private String date;
	private double score;

	public Exam(String date) {
		this.date = date;
	}

	public double getScore() {
		return score;
	}

	public void setScore(double score) {
		this.score = score;
	}

	@Override
	public String toString() {
		return "Exam [score=" + score + "]";
	}
	
}
