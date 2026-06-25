package mertguler.Person;

import mertguler.CRS.DateManager;
import mertguler.Exceptions.RendezvousLimitException;
import mertguler.Hospital.Rendezvous;

import java.time.LocalDate;
import java.time.Period;
import java.util.ArrayList;

import static mertguler.CRS.CRS.MAX_RENDEZVOUS_PER_PATIENT;

public class Patient extends Person {
    private final ArrayList<Rendezvous> rendezvouses;
    private LocalDate birthDate;

    // If birthdate is unknown, put null.
    public Patient(String name, long national_id, LocalDate birthDate) {
        super(name, national_id);
        rendezvouses = new ArrayList<>();
        this.birthDate = birthDate;
    }

    public void addRendezvous(Rendezvous rendezvous){
        rendezvouses.add(rendezvous);
    }

    public void deleteRendezvous(Rendezvous rendezvous){
        rendezvouses.remove(rendezvous);
    }

    public void checkActiveRendezvousCount() throws RendezvousLimitException{
        int activeCount = 0;

        for (Rendezvous rendezvous: rendezvouses){
            if (!(rendezvous.isExpired())){
                activeCount++;
            }
        }

        if (activeCount >= MAX_RENDEZVOUS_PER_PATIENT) {
            throw new RendezvousLimitException("Patient: " + this + " has more rendezvouses than limit: " + MAX_RENDEZVOUS_PER_PATIENT);
        }
    }

    // Getters & Setters

    // 0 is for unknown.
    public int getAge(){
        if ((birthDate != null)) {
            return Period.between(birthDate, DateManager.getCurrentDate()).getYears();
        } else {
            return 0;
        }
    }

    public int getRendezvousCount() {
        return rendezvouses.size();
    }

    public ArrayList<Rendezvous> getRendezvouses() {
        return rendezvouses;
    }

    @Override
    public String toString(){
        return getName() + ", National ID: " + getNational_id();
    }

}
