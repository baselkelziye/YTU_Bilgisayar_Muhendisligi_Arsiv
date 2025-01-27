package mertguler.TextUI.Menu;

import mertguler.CRS.CRS;
import mertguler.CRS.PatientManager;
import mertguler.Exceptions.DuplicateInfoException;
import mertguler.Exceptions.IDException;
import mertguler.Person.Patient;

import java.util.Comparator;
import java.util.Scanner;

import static mertguler.TextUI.TextUI.*;

public class PatientMenu {
    private Scanner scanner;
    private CRS crs;
    private PatientManager patientManager;

    public PatientMenu(Scanner scanner, CRS crs){
        this.scanner = scanner;
        this.crs = crs;
        patientManager = crs.getPatientManager();
    }

    public void patientManager(){
        while (true){
            clear();
            header();
            int input = 9;
            System.out.println("\nAdd Patient: 1");
            System.out.println("Delete Patient: 2");
            System.out.println("Rename Patient: 3");
            System.out.println("List Patients: 4");
            System.out.println("Return to last menu: 0");
            System.out.println("\nSelect operating mode (1-4):");

            try {
                input = Integer.valueOf(scanner.nextLine());
            } catch (Exception e){
                System.out.println("Please enter valid numbers only");
                returner(scanner);
                continue;
            }

            if (input == 0){
                return;
            } else if (input == 1) {
                patientAdder();
            } else if (input == 2) {
                patientDeleter();
            } else if (input == 3){
                patientRenamer();
            } else if (input == 4){
                patientLister();
                returner(scanner);
            }
        }
    }

    public boolean patientAdder(){
        while (true){
            clear();
            header();
            long national_id = 0;
            String name = "";

            System.out.println("Enter National ID: ");

            try{
                national_id = Long.valueOf(scanner.nextLine());
            } catch (Exception e){
                System.out.println("Enter valid numbers only");
                returner(scanner);
                return false;
            }

            try {
                patientManager.checkPatientDuplication(national_id);
            } catch (DuplicateInfoException e){
                System.out.println(e.getMessage());
                returner(scanner);
                return false;
            }

            System.out.println("Enter name:");

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


            crs.getPatients().put(national_id, new  Patient(name , national_id, null));
            System.out.println("Patient: " + name + " with National ID: " + national_id + " is successfully added");
            returner(scanner);
            return true;
        }
    }

    public boolean patientDeleter(){
        while (true){
            clear();
            header();
            long national_id = 0;

            System.out.println("Enter National ID: ");

            try{
                national_id = Long.valueOf(scanner.nextLine());
            } catch (Exception e){
                System.out.println("Enter valid numbers only");
                returner(scanner);
                return false;
            }

            try {
                patientManager.checkPatientID(national_id);
            } catch (IDException e){
                System.out.println(e.getMessage());
                returner(scanner);
                return false;
            }


            try {
                patientManager.patientDeleter(national_id);
                System.out.println("Patient with National ID: " + national_id + " is successfully deleted");
                returner(scanner);
                return true;
            } catch (IDException e){
                System.out.println(e.getMessage());
                returner(scanner);
                return false;
            }
        }
    }

    public boolean patientRenamer(){
        while (true){
            clear();
            header();
            long national_id = 0;
            String name = "";

            System.out.println("Enter Patient`s National ID: ");

            try{
                national_id = Long.valueOf(scanner.nextLine());
            } catch (Exception e){
                System.out.println("Enter valid numbers only");
                returner(scanner);
                return false;
            }


            try {
                patientManager.checkPatientID(national_id);
            } catch (IDException e){
                System.out.println(e.getMessage());
                returner(scanner);
                return false;
            }

            System.out.println("Enter name:");

            try{
                name = scanner.nextLine();
            } catch (Exception e){
                System.out.println("Enter valid characters only");
                returner(scanner);
                return false;
            }


            patientManager.getPatient(national_id).setName(name);
            System.out.println("Patient with National ID: " + national_id + " is successfully renamed");
            returner(scanner);
            return true;
        }
    }

    public boolean patientLister(){
        clear();
        header();
        System.out.println();

        if (crs.getPatients().isEmpty()){
            System.out.println("No patient is found");
            return false;
        }

        Comparator<Patient> comparator = Comparator
                .comparing(Patient::getName);

       crs.getPatients().values().stream()
                .sorted(comparator)
                .forEach(System.out::println);
        return true;
    }
    
}
