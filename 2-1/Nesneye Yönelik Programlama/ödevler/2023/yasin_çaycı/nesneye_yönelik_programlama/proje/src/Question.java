package a;

import java.io.Serializable;

public class Question implements Serializable {
	private static final long serialVersionUID = 1L;
	
	private double answerTime;
	private int q1;
	private int q2;
	private boolean truth;
	
	public Question(double answerTime, int q1, int q2, boolean truth) {
		super();
		this.answerTime = answerTime;
		this.q1 = q1;
		this.q2 = q2;
		this.truth = truth;
	}

	public int getQ1() {
		return q1;
	}

	public int getQ2() {
		return q2;
	}

	public double getAnswerTime() {
		return answerTime;
	}

	public void setAnswerTime(double answerTime) {
		this.answerTime = answerTime;
	}

	public boolean isTruth() {
		return truth;
	}

	public void setTruth(boolean truth) {
		this.truth = truth;
	}
	
	public boolean getTruth() {
		return truth;
	}
 
}
