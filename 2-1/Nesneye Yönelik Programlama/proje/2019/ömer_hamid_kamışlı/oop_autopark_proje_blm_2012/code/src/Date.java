import java.time.LocalDateTime;

public class Date {
	private int day;
	private int month;
	private int year;
	
	
	/*
	 * GETTERS
	 */
	public int getDay() {
		return day;
	}

	public int getMonth() {
		return month;
	}

	public int getYear() {
		return year;
	}

	/*
	 * SETTERS
	 */
	public void setDay(int day) {
		if(day<32)
			this.day = day;
	}

	public void setMonth(int month) {
		if(month<13)
			this.month = month;
	}

	public void setYear(int year) {
		if(2019<year && year<2100)
			this.year = year;
	}
	
	/*
	 * CONSTRUCTORS
	 */
	public Date(int day, int month, int year) {
		if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
			if(day<32) {
				this.day = day;
				this.month = month;
				this.year = year;
			}
		}
		else if(month == 2) {
			if((year%4) == 0) {
				if(day<29) {
					this.day = day;
					this.month = month;
					this.year = year;
				}
			} else {
				if(day<28) {
					this.day = day;
					this.month = month;
					this.year = year;
				}
			}
		} else if( month==4 || month==6 || month==9 || month==11) {
			if(day<31) {
				this.day = day;
				this.month = month;
				this.year = year;
			}
		}
	}

	/*
	 * Functions from UML
	 */
	public boolean isAfterThan(Date date) {
		if(date.year > this.year) {
			return true;
		} else {
			if(date.year == this.year && date.month > this.month) {
				return true;
			} else {
				if(date.month == this.month && date.day > this.day) {
					return true;
				} 
			}
		}
		return false;
	}

	public boolean isBeforeThan(Date date) {
		if(date.year < this.year) {
			return true;
		} else {
			if(date.year == this.year && date.month < this.month) {
				return true;
			} else {
				if(date.month == this.month && date.day < this.day) {
					return true;
				} 
			}
		}
		return false;
	}
	
	public boolean isEqualWith(Date date) {
		if(this.year == date.year && this.month == date.month && this.day == date.day)
			return true;
		return false;
	}
	
	public static Date getToday() {
		LocalDateTime now= LocalDateTime.now();
		Date today = new Date(now.getDayOfMonth(),now.getMonthValue(),now.getYear());
		return today;
	}
}
