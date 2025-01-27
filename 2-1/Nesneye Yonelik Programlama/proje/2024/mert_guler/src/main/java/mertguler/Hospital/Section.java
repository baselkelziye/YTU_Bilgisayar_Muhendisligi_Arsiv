package mertguler.Hospital;

import mertguler.Exceptions.DuplicateInfoException;
import mertguler.Exceptions.IDException;
import mertguler.Person.Doctor;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Comparator;

public class Section implements Serializable {
    private static final long serialVersionUID = 1L;
    private final int id;
    private String name;
    private ArrayList<Doctor> doctors;
    private boolean isChildSection;

    // Don't forget to add section to hospital
    // It is intentional to leave that job to GUI and TextUI
    public Section(String name, Hospital hospital, boolean isChildSection){
        this.name = name;
        this.id = hospital.getId() * 1000 + hospital.getAllTimeSectionCount() + 1;
        hospital.increaseAllTimeSectionCount();
        doctors = new ArrayList<>();
        this.isChildSection = isChildSection;
    }

    public void addDoctor (Doctor doctor) throws DuplicateInfoException{
        if (doctors.contains(doctor)){
            throw new DuplicateInfoException("Doctor with Diploma ID: " + doctor.getDiploma_id() + " is already exists");
        }

        doctors.add(doctor);
    }

    public void deleteDoctor(int diploma_id) throws IDException{
        Doctor doctor = getDoctor(diploma_id);
        if (doctor == null){
            return;
        }

        doctors.remove(doctor);
    }

    public Doctor getDoctor(int diploma_id) throws IDException {
        if (doctors.isEmpty()){
            throw new IDException("No doctor is found for Section: " + getName());
        }


        for (Doctor doctor: doctors){
            if (doctor.getDiploma_id() == diploma_id){
                return doctor;
            }
        }

        throw new IDException("Doctor with ID: " + diploma_id + " is not found");
    }

    public void checkDoctorDuplication(int diploma_id) throws DuplicateInfoException{
        if (doctors.isEmpty()){
            return;
        }

        for (Doctor doctor: doctors){
            if (doctor.getDiploma_id() == diploma_id){
                throw new DuplicateInfoException("Doctor with ID: " + diploma_id + " is already exist");
            }
        }
    }

    // Text UI Only
    public void listDoctors(){
        if (doctors.isEmpty()){
            System.out.println("This section doesnt have any doctors");
            return;
        }

        Comparator<Doctor> comparator = Comparator
                .comparing(Doctor::getDiploma_id);

        System.out.println();

        doctors.stream()
                .sorted(comparator)
                .forEach(System.out::println);
    }

    // Text UI Only
    public ArrayList<Doctor> getDoctor(String name){
        if (doctors.isEmpty()){
            return null;
        }

        name = name.trim();
        ArrayList<Doctor> foundDoctors = new ArrayList<>();

        for (Doctor doctor: doctors){
            if (doctor.getName().trim().equalsIgnoreCase(name)){
                foundDoctors.add(doctor);
            }
        }

        if (!foundDoctors.isEmpty()){
            return foundDoctors;
        }

        return null;
    }

    // Counters
    public int countAllRendezvouses(){
        int count = 0;
        for (Doctor doctor: doctors){
            count += doctor.getSchedule().getRendezvousCount();
        }

        return count;
    }

    // Getters & Setters

    public boolean isChildSection(){
        return isChildSection;
    }

    public int getId(){
        return id;
    }

    public String getName(){
        return name;
    }

    public ArrayList<Doctor> getDoctors(){
        return doctors;
    }

    public void setName(String name){
        this.name = name;
    }

    @Override
    public boolean equals(Object object){
        if (this == object){
            return true;
        }

        if (!(object instanceof Section)){
            return false;
        }

        Section comparedSection = (Section) object;

        if (this.getName().trim().equalsIgnoreCase(comparedSection.name.trim())){
            return true;
        }

        return false;
    }

    @Override
    public String toString(){
        return name + ", ID: " + id + ", Child Only: " + isChildSection;
    }
}
