package mertguler.CRS;

import mertguler.Exceptions.DuplicateInfoException;
import mertguler.Exceptions.IDException;
import mertguler.Person.Patient;

import java.util.HashMap;

public class PatientManager {
    private HashMap<Long, Patient> patients;
    private CRS crs;


    public PatientManager(HashMap<Long, Patient> patients, CRS crs){
        this.patients = patients;
        this.crs = crs;
    }

    public boolean updatePatientsMap(HashMap<Long, Patient> patients){
        this.patients = patients;
        return true;
    }

    public void checkPatientDuplication(long national_id) throws DuplicateInfoException {
        if (patients.containsKey(national_id)){
            throw new DuplicateInfoException("Patient with National ID: " + national_id + " is already exist");
        }
    }

    public void checkPatientID(long national_id) throws IDException {
        if (!(patients.containsKey(national_id))){
            throw new IDException("No patient found with National ID: " + national_id);
        }
    }

    // Already checks for existence
    public Patient getPatient(long national_id) throws IDException{
        checkPatientID(national_id);
        return patients.get(national_id);
    }

    // Already checks for existence
    public void patientDeleter(long national_id) throws IDException{
        Patient patient = getPatient(national_id);
        crs.getRendezvouses().removeIf(rendezvous -> (rendezvous.getPatient().getNational_id() == national_id));
        patients.remove(national_id);
    }

}
