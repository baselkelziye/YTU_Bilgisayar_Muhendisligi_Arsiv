
public class Time {
	private int hour,minute;

	/*
	 * GETTERS
	 */
	public int getHour() {
		return hour;
	}

	public int getMinute() {
		return minute;
	}

	/*
	 * SETTERS
	 */
	public void setHour(int hour) {
		if(hour<24)
			this.hour = hour;
	}

	public void setMinute(int minute) {
		if(minute<60)
			this.minute = minute;
	}
	
	/*
	 * CONSTRUCTORS
	 */
	public Time(int hour, int minute) {
		if(hour<24 && minute<60) {
			this.hour = hour;
			this.minute = minute;
		}	
	}
	
	/*
	 * Functions from UML
	 */
	public int getDifference(Time other) {
		return other.hour-this.hour;
	}
}
