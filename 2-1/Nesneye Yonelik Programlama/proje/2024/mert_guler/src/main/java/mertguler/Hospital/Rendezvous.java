package mertguler.Hospital;

import mertguler.CRS.DateManager;
import mertguler.Person.Doctor;
import mertguler.Person.Patient;

import java.io.Serial;
import java.io.Serializable;
import java.time.LocalDate;


public class Rendezvous implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;

    private final LocalDate date;
    private Doctor doctor;
    private Patient patient;
    private Hospital hospital;
    private Section section;
    private boolean expired;

    public Rendezvous(LocalDate desiredDate, Doctor doctor, Patient patient, Hospital hospital, Section section){
        date = desiredDate;
        this.doctor = doctor;
        this.patient = patient;
        this.section = section;
        this.hospital = hospital;
        expired = false;
    }

    public void updateExpired(){
        if (date.isBefore(DateManager.getCurrentDate())){
            expired = true;
        }
    }

    // Getters & Setters

    public LocalDate getDate(){
        return date;
    }

    public Doctor getDoctor(){
        return doctor;
    }

    public Patient getPatient(){
        return patient;
    }

    public Hospital getHospital(){
        return hospital;
    }

    public Section getSection(){
        return section;
    }

    public boolean isExpired(){
        return expired;
    }


    @Override
    public boolean equals(Object object){
        if (this == object){
            return true;
        }

        if (!(object instanceof Rendezvous)){
            return false;
        }

        Rendezvous checkedRendezvous = (Rendezvous) object;

        if (this.date == checkedRendezvous.date && this.doctor == checkedRendezvous.doctor && this.patient == checkedRendezvous.patient){
            return true;
        }

        return false;
    }

    @Override
    public String toString(){
        return patient.getName() + ", " + hospital.getName() + ", " + section.getName() + ", " + doctor.getName() + ", " + date;
    }

}
