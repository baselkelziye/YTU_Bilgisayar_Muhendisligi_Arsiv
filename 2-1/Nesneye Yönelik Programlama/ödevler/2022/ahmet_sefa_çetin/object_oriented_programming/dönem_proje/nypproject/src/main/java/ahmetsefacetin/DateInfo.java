package ahmetsefacetin;

import java.io.Serializable;

public class DateInfo implements Serializable {

    private static final long serialVersionUID = 1L;
    private int startMonth;
    private int endMonth;
    private int startYear;
    private int endYear;

    public DateInfo(int startMonth, int endMonth, int startYear, int endYear) {
        this.startMonth = startMonth;
        this.endMonth = endMonth;
        this.startYear = startYear;
        this.endYear = endYear;
    }

    public int getStartMonth() {
        return startMonth;
    }

    public void setStartMonth(int startMonth) {
        this.startMonth = startMonth;
    }

    public int getEndMonth() {
        return endMonth;
    }

    public void setEndMonth(int endMonth) {
        this.endMonth = endMonth;
    }

    public int getStartYear() {
        return startYear;
    }

    public void setStartYear(int startYear) {
        this.startYear = startYear;
    }

    public int getEndYear() {
        return endYear;
    }

    public void setEndYear(int endYear) {
        this.endYear = endYear;
    }

    @Override
    public String toString() {
        return "DateInfo{" + "startMonth=" + startMonth + ", endMonth=" + endMonth + ", startYear=" + startYear + '}';
    }

}
