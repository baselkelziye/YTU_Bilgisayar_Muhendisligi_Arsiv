package AutoparkProject;

import java.text.SimpleDateFormat;
import java.util.Calendar;

public class Date {//Exceptions lar yazılmalı
	private int day;
	private int month;
	private int year;
	public Date(int day, int month, int year) {
		if(day<32 && day>0) {
			this.day = day;
		}
		if(month<13 && month>0) {
			this.month = month;
		}
		if(year<2100 && year>2018) {
			this.month = month;
		}
	}
	
	public int getDay() {
		return day;
	}
	public void setDay(int day) {
		this.day = day;
	}
	public int getMonth() {
		return month;
	}
	public void setMonth(int month) {
		this.month = month;
	}
	public int getYear() {
		return year;
	}
	public void setYear(int year) {
		this.year = year;
	}

//	public boolean isAfterThan(Date other) {
//
//	}
//	public boolean isBeforeThan(Date other) {
//
//	}
//	public boolean isEqualThan(Date other) {
//
//	}

	public Date getToday() {
		//Getting current date
		Calendar calendar = Calendar.getInstance();
		SimpleDateFormat dateFormat = new SimpleDateFormat("ddMMyyyy");
		String current = dateFormat.format(calendar.getTime()); 
		//Spliting String to int
		int intDate = Integer.parseInt(current); 
		int year = intDate / 10000;
		int month = (intDate / 100) % 100;
		int day = intDate % 100;
		Date today = new Date(day,year,month);
		return today;
	}
	

	

}
