package backend;

import java.io.Serial;
import java.io.Serializable;

public class DateInfo implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;
    private int startMonth;
    private int endMonth;
    private int startYear;

    public DateInfo(int startMonth, int endMonth, int startYear) {
        this.startMonth = startMonth;
        this.endMonth = endMonth;
        this.startYear = startYear;
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

    @Override
    public String toString() {
        return "DateInfo{" +
                "startMonth=" + startMonth +
                ", endMonth=" + endMonth +
                ", startYear=" + startYear +
                '}';
    }
}
