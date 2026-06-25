package mertguler.Hospital;

import mertguler.CRS.HospitalManager;
import mertguler.Enums.City;
import mertguler.Exceptions.DuplicateInfoException;
import mertguler.Exceptions.IDException;

import java.io.Serial;
import java.io.Serializable;
import java.util.ArrayList;

public class Hospital implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;

    private String name;
    private final int id;
    private City city;
    private final ArrayList<Section> sections;
    private int allTimeSectionCount;

    // Needed for GUI. Usage: Creating temp hospital for List Tree Root. Check for Initialize methods of gui list creators.
    public Hospital(String name, int id, City city){
        this.name = name;
        this.id = id;
        sections = new ArrayList<>();
        this.city = city;
    }

    public Hospital(String name, City city){
        this.name = name;
        HospitalManager.hospitalCount++;
        id = HospitalManager.hospitalCount;
        sections = new ArrayList<>();
        this.city = city;
        allTimeSectionCount = 0;
    }

    public void addSection(Section section) throws DuplicateInfoException {
        if (sections.contains(section)){
            throw new DuplicateInfoException("Section with Name: " + section.getName() + ", is already exist");
        }

        sections.add(section);
    }

    public Section getSection(int id) throws IDException {
        if (sections.isEmpty()){
            throw new IDException("No section is found for Hospital: " + getName());
        }

        for (Section section: sections){
            if (section.getId() == id){
                return section;
            }
        }

        throw new IDException("Section with ID: " + id + " is not found");
    }

    // Text UI only
    public Section getSection(String name) throws IDException {
        if (sections.isEmpty()){
            throw new IDException("No section is found for Hospital: " + getName());
        }

        name = name.trim();
        for (Section section: sections){
            if (section.getName().trim().equalsIgnoreCase(name)){
                return section;
            }
        }

        throw new IDException("Section with name: " + name + " is not found");
    }

    public boolean deleteSection(int id) throws IDException{
        Section section = getSection(id);
        if (section == null){
            return false;
        }

        return sections.remove(section);
    }

    // Counters
    public int countAllRendezvouses(){
        int count = 0;

        for (Section section: sections){
            count += section.countAllRendezvouses();
        }

        return count;
    }

    public int countAllDoctors(){
        int count = 0;

        for (Section section: sections){
            count += section.getDoctors().size();
        }

        return  count;
    }

    // For adjusting Section ID
    public void increaseAllTimeSectionCount(){
        allTimeSectionCount++;
    }

    // Getters & Setters

    public void setName(String name){
        this.name = name;
    }

    public String getName(){
        return name;
    }

    public int getId(){
        return id;
    }

    public City getCity(){
        return city;
    }

    public int getAllTimeSectionCount(){
        return allTimeSectionCount;
    }

    public ArrayList<Section> getSections(){
        return sections;
    }


    @Override
    public boolean equals(Object object){
        if (this == object){
            return true;
        }

        if (!(object instanceof Hospital)){
            return false;
        }

        Hospital comparedHospital = (Hospital) object;

        if (this.name.trim().equalsIgnoreCase(comparedHospital.name.trim()) && this.city == comparedHospital.city){
            return true;
        }

        return false;
    }

    @Override
    public String toString(){
        return name + ", " + city + ", ID: " + id;
    }
}


