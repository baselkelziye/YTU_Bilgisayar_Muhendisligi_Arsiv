package mertguler.CRS;

import java.time.DateTimeException;
import java.time.LocalDate;
import java.time.Period;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;

import static mertguler.CRS.CRS.RENDEZVOUS_DAY_LIMIT;

public class DateManager {
    // Text UI Only
    public static String datePattern = "dd-MM-yyyy";
    public static DateTimeFormatter dateFormatter = DateTimeFormatter.ofPattern(datePattern);

    public DateManager(String newDatePattern){
        datePattern = newDatePattern;
    }

    public static LocalDate getCurrentDate(){
        LocalDate currentDate = LocalDate.now();
        return currentDate;
    }

    public static String getFormatedDate(LocalDate date){
        return date.format(dateFormatter);
    }

    // Used constant CRS: RENDEZVOUS_DAY_LIMIT
    public static LocalDate getLastDate(){
        LocalDate lastRendezvousDate = getCurrentDate().plusDays(RENDEZVOUS_DAY_LIMIT);
        return lastRendezvousDate;
    }

    // Text UI Only. Date format checker.
    public static LocalDate isValidDate(String date) throws DateTimeParseException {
        LocalDate checkedDate = null;

        checkedDate = LocalDate.parse(date, dateFormatter);
        return checkedDate;
    }

    // For calculating Person's Age.
    public static int getYearDifference(LocalDate localDate){
        if ((localDate != null)) {
            return Period.between(localDate, DateManager.getCurrentDate()).getYears();
        } else {
            return 0;
        }
    }

    // Rendezvous Date Range management.
    public static void checkDateRange(LocalDate desiredDate) throws DateTimeException {
        if (desiredDate == null){
            throw new DateTimeException("Date is null");
        }

        if (desiredDate.isAfter(getLastDate())){
            throw new DateTimeException("Date is after last available rendezvous date");
        }

        if (desiredDate.isBefore(getCurrentDate())){
            throw new DateTimeException("Date is before current date");
        }
    }


}
