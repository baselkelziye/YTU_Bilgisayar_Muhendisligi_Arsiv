package mertguler.CRS;

import mertguler.Enums.City;
import mertguler.Exceptions.DuplicateInfoException;
import mertguler.Exceptions.IDException;
import mertguler.Hospital.Hospital;
import mertguler.Hospital.Section;

import java.util.HashMap;

public class HospitalManager {
    private HashMap<Integer, Hospital> hospitals;
    private CRS crs;
    private SectionManager sectionManager;
    public static int hospitalCount = 0;

    public HospitalManager(HashMap<Integer, Hospital> hospitals, CRS crs) {
        this.hospitals = hospitals;
        sectionManager = new SectionManager();
        hospitalCount = hospitals.size();
        this.crs = crs;
    }

    public SectionManager getSectionManager() {
        return sectionManager;
    }

    public void updateHospitalMap(HashMap<Integer, Hospital> hospitals) {
        this.hospitals = hospitals;
        hospitalCount = hospitals.size();
    }

    public void createHospital(String name, City city) throws DuplicateInfoException {
        Hospital hospital = new Hospital(name, city);
        checkHospitalDuplication(name, city);
        hospitals.put(hospital.getId(), hospital);
    }

    public void deleteHospital(int id) throws IDException {
        checkHospitalID(id);
        crs.getRendezvouses().removeIf(rendezvous -> (rendezvous.getHospital().getId() == id));
        hospitals.remove(id);
    }

    public Hospital getHospitalWithID(int id) throws IDException {
        checkHospitalID(id);
        return hospitals.get(id);
    }

    // Text UI Only
    public Hospital getHospitalWithName(String name) throws IDException {
        if (hospitals.isEmpty()) {
            throw new IDException("No hospital found!");
        }

        name = name.trim();
        for (Hospital hospital : hospitals.values()) {
            if (hospital.getName().trim().equalsIgnoreCase(name)) {
                return hospital;
            }
        }

        throw new IDException("Hospital with name: " + name + " is not found");
    }

    public void checkHospitalDuplication(String name, City city) throws DuplicateInfoException {
        for (Hospital hospital: hospitals.values()) {
            if (hospital.getName().trim().equalsIgnoreCase(name.trim()) && hospital.getCity() == city){
                throw new DuplicateInfoException(name + ", " + city + " is already exist");
            }
        }
    }

    public void checkHospitalID(int hospital_id) throws IDException {
        if (!hospitals.containsKey(hospital_id)) {
            throw new IDException("No hospital found with Hospital ID: " + hospital_id);
        }
    }

    public HashMap<Integer, Hospital> getHospitals() {
        return hospitals;
    }


    // Counter for Admin Dashboard
    public int countAllSections() {
        int count = 0;

        if (hospitals.isEmpty()) {
            return count;
        }

        for (Hospital hospital : hospitals.values()) {
            count += hospital.getSections().size();
        }

        return count;
    }

    // Counter for Admin Dashboard
    public int countAllDoctors() {
        int count = 0;

        for (Hospital hospital : hospitals.values()) {
            for (Section section : hospital.getSections()) {
                count += section.getDoctors().size();
            }
        }
        return count;
    }

    // Inner Class of Hospital Manager
    public class SectionManager {
        private DoctorManager doctorManager = new DoctorManager();

        public DoctorManager getDoctorManager() {
            return doctorManager;
        }

        public void checkSectionID(int hospital_id, int section_id) throws IDException {
            if (hospitals.get(hospital_id).getSection(section_id) == null) {
                throw new IDException("No section found with Section ID: " + section_id);
            }
        }

        public void deleteSection(int hospital_id, int section_id) throws IDException {
            Hospital hospital = getHospitalWithID(hospital_id);
            crs.getRendezvouses().removeIf(rendezvous -> (rendezvous.getSection().getId() == section_id));
            hospital.deleteSection(section_id);
        }

        public class DoctorManager {
            public void checkDoctorID(int hospital_id, int section_id, int diploma_id) throws IDException {
                if (hospitals.get(hospital_id).getSection(section_id).getDoctor(diploma_id) == null) {
                    throw new IDException("No doctor found with Diploma ID: " + diploma_id);
                }
            }

            public void deleteDoctor(int hospital_id, int section_id, int diploma_id) throws IDException {
                Hospital hospital = getHospitalWithID(hospital_id);
                Section section = hospital.getSection(section_id);
                crs.getRendezvouses().removeIf(rendezvous -> (rendezvous.getDoctor().getDiploma_id() == diploma_id));
                section.deleteDoctor(diploma_id);
            }
        }
    }

}

