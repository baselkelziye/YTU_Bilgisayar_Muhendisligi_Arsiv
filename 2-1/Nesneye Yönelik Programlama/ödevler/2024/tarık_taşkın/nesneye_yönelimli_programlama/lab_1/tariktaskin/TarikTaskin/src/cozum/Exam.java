package cozum;

public class Exam {
	private String date;
	private double score;
	
	
	public Exam(String date) {
		this.date = date;
	}

	

	@Override
	public String toString() {
		return "Exam [score=" + score + "]";
	}



	public String getDate() {
		return date;
	}


	public void setDate(String date) {
		this.date = date;
	}


	public double getScore() {
		return score;
	}


	public void setScore(double score) {
		this.score = score;
	}
	
	
	

}
