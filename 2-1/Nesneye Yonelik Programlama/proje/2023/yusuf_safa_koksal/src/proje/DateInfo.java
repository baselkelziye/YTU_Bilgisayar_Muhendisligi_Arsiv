package proje;

import java.io.Serializable;

public class DateInfo implements Serializable{
	private static final long serialVersionUID = 6412520690958925621L;
	private int startMonth;
	private int endMonth;
	private int startYear;
	
	public DateInfo(int startMonth, int startYear) {
		this.startMonth = startMonth;
		this.startYear = startYear;
		setEndMonth(startMonth);
	}
	
	private void setEndMonth(int startMonth) {
		if(startMonth==1)
			endMonth=12;
		else
			endMonth=startMonth-1;
	}

	public int getStartMonth() {
		return startMonth;
	}

	public int getEndMonth() {
		return endMonth;
	}

	public int getStartYear() {
		return startYear;
	}
}
