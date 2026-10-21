package distributor;

public class DateInfo implements java.io.Serializable {
    private static final long serialVersionUID = 1L;
    private int startMonth;
    private int endMonth;
    private int startYear;
    private int endYear;

    public DateInfo(int startMonth, int startYear) {
        this.startMonth = startMonth;
        this.endMonth = (startMonth != 1) ? (startMonth + 11) % 12 : 12;
        this.startYear = startYear;
        this.endYear = (startMonth == 1) ? startYear : startYear + 1;
    }

    public boolean betweenDate(int month, int year){
        return (year == this.startYear && month >= this.startMonth) ||
                (year == this.endYear && month <= this.endMonth);
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

    public int getEndYear() {
        return endYear;
    }

    @Override
    public String toString() {
        return "DateInfo{" +
                "startMonth=" + startMonth +
                ", endMonth=" + endMonth +
                ", startYear=" + startYear +
                ", endYear=" + endYear +
                '}';
    }
}
