package mertguler.CRS;

import mertguler.Exceptions.*;
import mertguler.Hospital.Hospital;
import mertguler.Hospital.Rendezvous;
import mertguler.Hospital.Section;
import mertguler.Person.Doctor;
import mertguler.Person.Patient;

import java.io.*;
import java.nio.file.Paths;
import java.time.DateTimeException;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

import static mertguler.CRS.DateManager.checkDateRange;

public class CRS {
    private HashMap<Long, Patient> patients;
    private ArrayList<Rendezvous> rendezvouses;
    private HashMap<Integer, Hospital> hospitals;

    private final PatientManager patientManager;
    private final HospitalManager hospitalManager;

    // App wide settings
    public static int MAX_RENDEZVOUS_PER_PATIENT = 5;
    public static int RENDEZVOUS_DAY_LIMIT = 30;
    public static String dataPath = "data.ser";


    public CRS(){
        patients = new HashMap<>();
        rendezvouses = new ArrayList<>();
        hospitals = new HashMap<>();
        hospitalManager = new HospitalManager(hospitals, this);
        patientManager = new PatientManager(patients, this);
    }

    // Might be used in the future.
    // I am not using it because my application checks info step by step
    // Every exception is checked in GUI & Text UI.
    public boolean makeRendezvous(long patientID, int hospitalID, int sectionID, int diplomaID,
                                  LocalDate desiredDate) throws IDException, DailyLimitException,
            RendezvousLimitException, DateTimeException, ChildOnlyException{

        // DateTimeException
        checkDateRange(desiredDate);

        // ID Exception
        Patient patient = patientManager.getPatient(patientID);

        // RendezvousLimitException
        patient.checkActiveRendezvousCount();

        // ID Exceptions
        Hospital hospital = hospitalManager.getHospitalWithID(hospitalID);
        Section section = hospital.getSection(sectionID);

        // Child Only Exception
        checkChildSection(patient, section);

        // ID Exception
        Doctor doctor = section.getDoctor(diplomaID);

        // DailyLimitException
        doctor.getSchedule().checkDailyLimit(desiredDate);

        Rendezvous rendezvous = new Rendezvous(desiredDate, doctor, patient, hospital, section);

        // Duplicate Info Exception
        doctor.getSchedule().addRendezvous(rendezvous);

        patient.addRendezvous(rendezvous);
        rendezvouses.add(rendezvous);
        return true;
    }

    // Use if you check everything in the Text UI and GUI
    public void addRendezvous(Doctor doctor, Rendezvous rendezvous, Patient patient)
            throws DateTimeException, IDException, DailyLimitException, DuplicateInfoException {

        doctor.getSchedule().addRendezvous(rendezvous);
        patient.addRendezvous(rendezvous);
        rendezvouses.add(rendezvous);
    }

    // GUI Only
    public void checkValidity(long patientID, Doctor doctor, LocalDate desiredDate)
            throws IDException, RendezvousLimitException, DuplicateInfoException{

        // ID Exception
        patientManager.checkPatientID(patientID);

        Patient patient = patientManager.getPatient(patientID);

        // RendezvousLimitException
        // Validates maximum rendezvous count for patient
        patient.checkActiveRendezvousCount();
        // DailyLimitException
        doctor.getSchedule().checkDailyLimit(desiredDate);
    }



    public void checkChildSection(Patient patient, Section section) throws ChildOnlyException {
        if (section.isChildSection()){
            if (patient.getAge() > 18){
                throw new ChildOnlyException("This section is only for children! Patient: " + patient + " is over Age 18");
            }
        }
    }

    public void deleteRendezvous(Rendezvous rendezvous) throws NullPointerException{
        if (rendezvous == null) {
            throw new NullPointerException("Rendezvous is null");
        }

        Doctor doctor = rendezvous.getDoctor();
        Patient patient = rendezvous.getPatient();

        doctor.getSchedule().deleteRendezvous(rendezvous);
        patient.deleteRendezvous(rendezvous);
        rendezvouses.remove(rendezvous);
    }


    // Updates Expired Status of Rendezvouses
    // Using 4 threads
    public void updateExpired(){
        int size = rendezvouses.size();
        int quarter = size / 4;
        int half = quarter * 2;
        int threeQuarter = quarter + half;

        Runnable task1 = () ->
        {
            for (int i = 0; i < quarter; i++){
                rendezvouses.get(i).updateExpired();
            }
        };

        Runnable task2 = () ->
        {
            for (int i = quarter; i < half; i++){
                rendezvouses.get(i).updateExpired();
            }
        };

        Runnable task3 = () ->
        {
            for (int i = half; i < threeQuarter; i++){
                rendezvouses.get(i).updateExpired();
            }
        };

        Runnable task4 = () ->
        {
            for (int i = threeQuarter; i < size; i++){
                rendezvouses.get(i).updateExpired();
            }
        };

        Thread thread1 = new Thread(task1);
        Thread thread2 = new Thread(task2);
        Thread thread3 = new Thread(task3);
        Thread thread4 = new Thread(task4);
        thread1.start();
        thread2.start();
        thread3.start();
        thread4.start();

        try {
            thread1.join();
            thread2.join();
            thread3.join();
            thread4.join();
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

    // Serialization
    public boolean saveTablesToDisk(){
        try {
            FileOutputStream fileOut = new FileOutputStream(dataPath);
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
            out.writeObject(hospitals);
            out.writeObject(patients);
            out.writeObject(rendezvouses);
            out.close();
            fileOut.close();
            System.out.printf("\nSerialized data is saved to " + dataPath + " file.");
            return true;
        } catch (IOException e) {
            System.out.println("\n" + e.getMessage());
            return false;
        }
    }

    // Deserialization
    public boolean loadTablesFromDisk(){
        try {
            FileInputStream fileIn = new FileInputStream(dataPath);
            ObjectInputStream in = new ObjectInputStream(fileIn);
            hospitals = (HashMap<Integer, Hospital>) in.readObject();
            patients = (HashMap<Long, Patient>) in.readObject();
            rendezvouses = (ArrayList<Rendezvous>) in.readObject();
            in.close();
            fileIn.close();
            System.out.printf("\nSerialized data is read from " + dataPath + " file.");
            hospitalManager.updateHospitalMap(hospitals);
            patientManager.updatePatientsMap(patients);
            updateExpired();
            return true;
        } catch (IOException i) {
            System.out.println("\n" + i.getMessage());
            return false;
        } catch (ClassNotFoundException c) {
            System.out.println("\n\n" + c.getMessage());
            return false;
        }
    }

    // GUI Only
    public void saveSettings() throws IOException{
        String path = "settings.txt";
        try {
            FileWriter fileWriter = new FileWriter(path);
            fileWriter.write(String.valueOf(MAX_RENDEZVOUS_PER_PATIENT));
            fileWriter.write(",");
            fileWriter.write(String.valueOf(RENDEZVOUS_DAY_LIMIT));

            fileWriter.close();
            System.out.println("\nSettings are saved to " + path + "\n");
        } catch (IOException e) {
            throw new IOException(e.getMessage());
        }
    }

    // GUI Only
    public void loadSettings() throws IOException, ArrayIndexOutOfBoundsException{
        String path = "settings.txt";
        try {
            Scanner fileScanner = new Scanner(Paths.get(path));
            String settingsText = fileScanner.nextLine();
            String[] settings = settingsText.split(",");

            MAX_RENDEZVOUS_PER_PATIENT = Integer.valueOf(settings[0]);
            RENDEZVOUS_DAY_LIMIT = Integer.valueOf(settings[1]);

            System.out.println("\nSettings are loaded from: " + path + "\n");
        } catch (IOException e) {
            throw new IOException(e.getMessage());
        } catch (ArrayIndexOutOfBoundsException indexE){
            throw new ArrayIndexOutOfBoundsException("\nSettings file is corrupted");
        }
    }

    // Getters

    public ArrayList<Rendezvous> getRendezvouses(){
        return rendezvouses;
    }

    public HashMap<Integer, Hospital> getHospitals(){
        return hospitals;
    }

    public HashMap<Long, Patient> getPatients(){
        return patients;
    }

    public HospitalManager getHospitalManager(){
        return hospitalManager;
    }

    public PatientManager getPatientManager(){
        return patientManager;
    }

    public int getRendezvousCount(){
        return rendezvouses.size();
    }

    public int getPatientCount(){
        return patients.size();
    }

    public int getHospitalCount(){
        return hospitals.size();
    }

    // Setters

    public void setMaxRendezvousPerPatient(int newLimit){
        MAX_RENDEZVOUS_PER_PATIENT = newLimit;
    }

    public void setRendezvousDayLimit(int newLimit){
        RENDEZVOUS_DAY_LIMIT = newLimit;
    }

}
