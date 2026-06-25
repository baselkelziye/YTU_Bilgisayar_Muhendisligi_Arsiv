package mertguler.TextUI.Menu;

import mertguler.CRS.CRS;
import mertguler.CRS.HospitalManager;
import mertguler.Exceptions.DuplicateInfoException;
import mertguler.Exceptions.IDException;
import mertguler.Hospital.Hospital;
import mertguler.Hospital.Section;
import mertguler.Person.Doctor;

import java.util.ArrayList;
import java.util.Scanner;

import static mertguler.TextUI.TextUI.*;

public class DoctorMenu {
    private Scanner scanner;
    private CRS crs;
    private Section section;
    private HospitalMenu hospitalMenu;
    private SectionMenu sectionMenu;
    private HospitalManager hospitalManager;
    private Hospital hospital;

    public DoctorMenu(Scanner scanner, CRS crs, HospitalMenu hospitalMenu, SectionMenu sectionMenu){
        this.scanner = scanner;
        this.crs = crs;
        this.hospitalMenu = hospitalMenu;
        this.sectionMenu = sectionMenu;
        this.hospitalManager = crs.getHospitalManager();
    }

    public void doctorManager(){
        hospital = hospitalMenu.hospitalSelector();
        sectionMenu.setHospital(hospital);
        section = sectionMenu.sectionSelector();

        if (section == null){
            return;
        }

        while (true) {
            clear();
            header();
            int input = 9;
            System.out.println("\n" + "Hospital:" + hospital.getName() + ", ID: " + hospital.getId());
            System.out.println("Section: " + section.getName() + ", ID: " + section.getId() + "\n");
            System.out.println("Add Doctor: 1");
            System.out.println("Delete Doctor: 2");
            System.out.println("List Doctors: 3");
            System.out.println("Return to last menu: 0");
            System.out.println("\nSelect operating mode (1-3):");
            try {
                input = Integer.valueOf(scanner.nextLine());
            } catch (Exception e) {
                System.out.println("Please enter only valid numbers within range");
                returner(scanner);
                continue;
            }

            if (input == 0) {
                break;
            } else if (input == 1){
                doctorAdder();
            } else if (input == 2){
                doctorDeleter();
            } else if (input == 3) {
                clear();
                header();
                section.listDoctors();
                returner(scanner);
            }
        }
    }

    public Doctor doctorSelector(Section section){
        while (true){
            clear();
            header();
            int diploma_id = 0;
            int input = 9;

            System.out.println("Select Doctor with Diploma ID: 1");
            System.out.println("Select Doctor with Name: 2");
            System.out.println("List Doctors: 3");
            System.out.println("Return to last menu: 0");
            System.out.println("\nSelect operating mode (1-3):");

            try{
                input = Integer.valueOf(scanner.nextLine());
            } catch (Exception e){
                System.out.println("Enter valid numbers only");
                returner(scanner);
                return null;
            }

            if (input == 0){
                return null;
            } else if (input == 1){
                return searchDoctorWithId(section);
            } else if (input == 2){
                return searchDoctorWithName(section);
            } else if (input == 3){
                clear();
                header();
                section.listDoctors();
                returner(scanner);
            }
        }
    }

    public Doctor searchDoctorWithId(Section section){
        while (true){
            clear();
            header();
            int diploma_id = 0;

            System.out.println("\nEnter Diploma ID: ");

            try{
                diploma_id = Integer.valueOf(scanner.nextLine());
            } catch (Exception e){
                System.out.println("Enter valid numbers only");
                returner(scanner);
                clear();
                return null;
            }

            Doctor doctor = section.getDoctor(diploma_id);
            if (doctor == null){
                System.out.println("Doctor is not found");
                returner(scanner);
                clear();
                return null;
            }

            return doctor;
        }
    }

    public Doctor searchDoctorWithName(Section section){
        while (true){
            clear();
            header();
            String name = "";

            System.out.println("\nEnter Name: ");

            try{
                name = scanner.nextLine();
            } catch (Exception e){
                System.out.println("Enter valid characters only");
                returner(scanner);
                clear();
                return null;
            }

            ArrayList<Doctor> searchedDoctorList = section.getDoctor(name);

            if (searchedDoctorList == null){
                System.out.println("No Doctor is found with name: " + name);
                returner(scanner);
                clear();
                return null;
            }

            if (searchedDoctorList.size() == 1){
                return searchedDoctorList.getFirst();
            } else {
                clear();
                header();
                System.out.println("Multiple Doctors are found with this name");
                System.out.println("Please select a doctor from below by entering Diploma ID:");
                System.out.println("Return to last menu: 0\n");

                System.out.println("Found doctors: ");
                for (Doctor doctor: searchedDoctorList){
                    System.out.println(doctor);
                }

                int id = 0;
                try {
                    id = Integer.valueOf(scanner.nextLine());
                } catch (Exception e){
                    System.out.println("Enter valid numbers only");
                }

                if (id == 0){
                    return null;
                }

                Doctor doctor = section.getDoctor(id);
                if (doctor == null){
                    clear();
                    header();
                    System.out.println("\nDoctor with Diploma ID: " + id + " is not found");
                    returner(scanner);
                    return null;
                }

                return doctor;
            }

        }
    }

    public boolean doctorAdder(){
        while (true){
            clear();
            header();
            String name = "";
            long national_id = 0;
            int diploma_id = 0;

            System.out.println("Enter National ID: ");

            try {
                national_id = Long.valueOf(scanner.nextLine());
            } catch (Exception e){
                System.out.println("Enter valid numbers only");
                returner(scanner);
                return false;
            }

            System.out.println("Enter Diploma ID: ");

            try{
                diploma_id = Integer.valueOf(scanner.nextLine());
            } catch (Exception e){
                System.out.println("Enter valid numbers only");
                returner(scanner);
                return false;
            }

            System.out.println("Enter Name: ");

            try{
                name = scanner.nextLine();
            } catch (Exception e){
                System.out.println("Enter valid characters only");
                returner(scanner);
                return false;
            }

            if (name.isBlank()){
                System.out.println("Name cant be empty");
                returner(scanner);
                return false;
            }

            try{
                section.addDoctor(new Doctor(name, national_id, diploma_id));
                System.out.println("Doctor is successfully added");
                returner(scanner);
                return true;
            } catch (DuplicateInfoException e) {
                System.out.println(e.getMessage());
                returner(scanner);
                return false;
            }
        }
    }

    public boolean doctorDeleter(){
        while (true){
            clear();
            header();
            int diploma_id = 0;

            System.out.println("Enter Diploma ID: ");

            try{
                diploma_id = Integer.valueOf(scanner.nextLine());
            } catch (Exception e){
                System.out.println("Enter valid numbers only");
                returner(scanner);
                return false;
            }

            try {
                hospitalManager.getSectionManager().getDoctorManager().deleteDoctor(hospital.getId(), section.getId(), diploma_id);
                System.out.println("Doctor is successfully deleted");
                returner(scanner);
                return true;
            } catch (IDException e){
                System.out.println(e.getMessage());
                returner(scanner);
                return false;
            }

        }
    }

}
