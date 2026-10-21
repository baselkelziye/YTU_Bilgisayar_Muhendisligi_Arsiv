package AutoparkProject;

public class Time {
	private int minute;
	private int hour;
	public Time(int minute, int hour) {//Exceptions lar yazılmalı
		if(minute<61 && minute>0) {
			this.minute = minute;
		}
		if(hour<25 && hour>0) {
			this.hour = hour;
		}
	}
	public int getMinute() {
		return minute;
	}
	public void setMinute(int minute) {
		this.minute = minute;
	}
	public int getHour() {
		return hour;
	}
	public void setHour(int hour) {
		this.hour = hour;
	}
	public int getDifference(Time other) { //ne ile karşılaştıracağız?
		//getParkingDuration için kullanılacak muhtemelen ama 2 Time parameter alması gerekir?
		int time1 = getHour()*60 + getMinute();
		int time2 = other.getHour()*60 + other.getMinute();
		return time2-time1;
	}
	
}
