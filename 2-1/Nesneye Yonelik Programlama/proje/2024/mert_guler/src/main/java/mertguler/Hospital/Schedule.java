package mertguler.Hospital;

import mertguler.Exceptions.DailyLimitException;
import mertguler.Exceptions.DuplicateInfoException;
import mertguler.Exceptions.IDException;
import mertguler.Person.Doctor;

import java.io.Serial;
import java.io.Serializable;
import java.time.LocalDate;
import java.util.ArrayList;

public class Schedule implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;

    private ArrayList<Rendezvous> sessions;
    private int maxPatientPerDay;
    private Doctor doctor;

    public Schedule(int maxPatientPerDay){
        this.maxPatientPerDay = maxPatientPerDay;
        sessions = new ArrayList<>();
    }

    // Already checks for duplication
    public void addRendezvous(Rendezvous rendezvous) throws DuplicateInfoException {
        checkRendezvousDuplication(rendezvous);
        sessions.add(rendezvous);
    }

    // Already checks for contains
    public void deleteRendezvous(Rendezvous rendezvous) throws IDException{
        if (!(sessions.contains(rendezvous))){
            throw new IDException("Rendezvous is not found");
        }

        sessions.remove(rendezvous);
    }

    public void checkRendezvousDuplication(Rendezvous rendezvous) throws DuplicateInfoException{
        if (sessions.contains(rendezvous)){
            throw new DuplicateInfoException("Rendezvous: " + rendezvous + " is already exist");
        }
    }

    // Daily Patient Limit Checker
    public void checkDailyLimit(LocalDate desiredDate) throws DailyLimitException {
        int countForDay = 0;

        for (Rendezvous rendezvous: sessions){
            if (rendezvous.getDate().getMonthValue() == desiredDate.getMonthValue() &&
                    rendezvous.getDate().getDayOfMonth() == desiredDate.getDayOfMonth()){
                countForDay++;
            }
        }

        if (countForDay == maxPatientPerDay){
            throw new DailyLimitException("Doctor: " + doctor + " has reached daily rendezvous limit for date: " + desiredDate);
        }
    }

    public void setDoctor(Doctor doctor){
        if (doctor == null){
            return;
        }

        this.doctor = doctor;
    }

    public int getRendezvousCount(){
        return sessions.size();
    }

    public Doctor getDoctor(){
        return doctor;
    }

    public ArrayList<Rendezvous> getSessions(){
        return sessions;
    }

}
