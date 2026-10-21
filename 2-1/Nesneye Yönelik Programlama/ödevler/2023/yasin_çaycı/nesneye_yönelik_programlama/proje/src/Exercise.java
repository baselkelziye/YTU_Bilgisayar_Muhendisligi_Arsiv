package a;

import java.io.Serializable;
import java.util.ArrayList;

public class Exercise implements Serializable{

	private static final long serialVersionUID = 1L;
	private String startTime;
	private String endTime;
	private double point;
	private ArrayList<Question> questions;
	
	public Exercise(String startTime, String endTime, ArrayList<Question> questions) {
		this.startTime = startTime;
		this.endTime = endTime;
		this.questions = questions;
		point = 0;
	}

	public String getStartTime() {
		return startTime;
	}

	public void setStartTime(String startTime) {
		this.startTime = startTime;
	}

	public String getEndTime() {
		return endTime;
	}

	public void setEndTime(String endTime) {
		this.endTime = endTime;
	}

	public ArrayList<Question> getQuestions() {
		return questions;
	}

	public void setQuestions(ArrayList<Question> questions) {
		this.questions = questions;
	}

	public double getPoint() {
		return point;
	}

	public void setPoint(double point) {
		this.point = point;
	}

	

	
	
}
