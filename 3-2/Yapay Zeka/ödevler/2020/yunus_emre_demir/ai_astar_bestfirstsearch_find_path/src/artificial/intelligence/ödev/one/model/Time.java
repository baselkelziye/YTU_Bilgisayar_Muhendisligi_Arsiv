package artificial.intelligence.assignment.one.model;

public class Time {
	private int min;
	private int sec;
	private int millisec;

	public Time(long millisec) {
		super();

		float use = millisec / 60000f;
		this.min = (int) use;

		use = (use - min) * 60;
		this.sec = (int) use;

		this.millisec = (int) ((use - this.sec) * 1000);
	}

	public Time() {
		super();
	}

	public int getMin() {
		return min;
	}

	public void setMin(int min) {
		this.min = min;
	}

	public int getSec() {
		return sec;
	}

	public void setSec(int sec) {
		this.sec = sec;
	}

	public int getMillisec() {
		return millisec;
	}

	public void setMillisec(int millisec) {
		this.millisec = millisec;
	}

	@Override
	public String toString() {
		return "[Minute: " + min + " Second: " + sec + " Millisecond: " + millisec + "]";
	}

}
