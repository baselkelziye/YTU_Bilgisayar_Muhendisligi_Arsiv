package mertguler.TextUI.Menu;

import mertguler.CRS.CRS;
import mertguler.CRS.HospitalManager;
import mertguler.Enums.City;
import mertguler.Exceptions.DuplicateInfoException;
import mertguler.Exceptions.IDException;
import mertguler.Hospital.Hospital;

import java.util.Comparator;
import java.util.Locale;
import java.util.Scanner;

import static mertguler.TextUI.TextUI.*;

public class HospitalMenu {
    private CRS crs;
    private Scanner scanner;
    private HospitalManager hospitalManager;

    public HospitalMenu(Scanner scanner, CRS crs){
        this.crs = crs;
        this.scanner = scanner;
        hospitalManager = crs.getHospitalManager();
    }

    public void hospitalManager() {
        while (true) {
            clear();
            header();
            int input = 9;
            System.out.println("\nAdd Hospital: 1");
            System.out.println("Delete Hospital: 2");
            System.out.println("Rename Hospital: 3");
            System.out.println("List Hospitals: 4");
            System.out.println("Return to last menu: 0");

            System.out.println("\nSelect operating mode (1-4):");
            try {
                input = Integer.valueOf(scanner.nextLine());
            } catch (Exception e) {
                System.out.println("Please enter only valid numbers within range");
                returner(scanner);
                continue;
            }

            if (input == 0) {
                break;
            }

            if (input == 1) {
                hospitalAdder();
            } else if (input == 2) {
                hospitalDeleter();
            } else if (input == 3) {
                hospitalRenamer();
            } else if (input == 4) {
                hospitalLister();
            }
        }
    }

    public void hospitalAdder(){
        clear();
        header();
        int id = 0;
        System.out.println("\nEnter name: ");
        String name = "";

        try{
            name = scanner.nextLine();
        } catch (Exception e){
            System.out.println("Enter valid characters only");
            returner(scanner);
            return;
        }

        if (name.isBlank()){
            System.out.println("Name cant be empty");
            returner(scanner);
            return;
        }

        /*
        System.out.println("Enter ID");

        try {
            id = Integer.valueOf(scanner.nextLine());
        } catch (NumberFormatException e){
            System.out.println("Please enter only valid numbers");
            returner(scanner);
            return;
        }

         */

        System.out.println("Enter city name (Turkey cities and English characters only): ");
        City city;
        try {
            city = City.valueOf(scanner.nextLine().toUpperCase(Locale.ROOT));
        } catch (Exception e){
            System.out.println("please enter valid names only");
            returner(scanner);
            return;
        }

        try {
            hospitalManager.createHospital(name, city);
            System.out.println("Hospital successfully added.");
        } catch (DuplicateInfoException e) {
            System.out.println(e.getMessage());
        }

        returner(scanner);
    }

    public void hospitalDeleter(){
        clear();
        header();
        int id = 0;
        System.out.println("Enter the ID: ");

        try {
            id = Integer.valueOf(scanner.nextLine());
        } catch (NumberFormatException e){
            System.out.println("Please enter only valid numbers");
            returner(scanner);
            return;
        }

        try{
            hospitalManager.deleteHospital(id);
            System.out.println("Hospital is successfully deleted.");
            returner(scanner);
        } catch (IDException e){
            System.out.println(e.getMessage());
            returner(scanner);
        }
    }

    public void hospitalRenamer(){
        clear();
        header();
        int id = 0;
        System.out.println("\nEnter the ID: ");

        try {
            id = Integer.valueOf(scanner.nextLine());
        } catch (NumberFormatException e){
            System.out.println("Please enter only valid numbers");
            returner(scanner);
            return;
        }

        if(!(hospitalManager.getHospitals().containsKey(id))){
            System.out.println("Hospital with ID: " + id + " is not found.");
            returner(scanner);
            return;
        }

        System.out.println("Enter new name: ");
        String name = scanner.nextLine();

        hospitalManager.getHospitals().get(id).setName(name);
        System.out.println("Hospital successfully renamed to: " + name);
        returner(scanner);
    }

    public Hospital hospitalSelector(){
        if (hospitalManager.getHospitals().isEmpty()){
            clear();
            header();
            System.out.println("\nHospital list is empty");
            returner(scanner);
            return null;
        }

        while (true){
            clear();
            header();
            int input = 9;
            System.out.println("\nSelect a Hospital to continue with next menu.\n");
            System.out.println("Select hospital with id: 1");
            System.out.println("Select hospital with name: 2");
            System.out.println("List hospitals: 3");
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
                return null;
            } else if (input == 1){
                return getHospitalWithID();
            } else if (input == 2){
                return getHospitalWithName();
            } else if (input == 3){
                clear();
                header();
                hospitalLister();
            }

        }
    }

    public Hospital getHospitalWithID(){
        while (true){
            clear();
            header();
            int id = 9;
            System.out.println("Enter Hospital ID: ");

            try {
                id = Integer.valueOf(scanner.nextLine());
            } catch (Exception e) {
                System.out.println("Please enter only valid numbers");
                returner(scanner);
                return null;
            }

            try{
                return hospitalManager.getHospitalWithID(id);
            } catch (IDException e){
                System.out.println(e.getMessage());
                returner(scanner);
                return null;
            }

        }
    }

    public Hospital getHospitalWithName(){
        while (true){
            clear();
            header();
            String name = "";
            System.out.println("Enter Hospital Name: ");

            try {
                name = scanner.nextLine();
            } catch (Exception e) {
                System.out.println("Please enter only valid numbers");
                returner(scanner);
                return null;
            }

            try {
                return hospitalManager.getHospitalWithName(name);
            } catch (IDException e){
                System.out.println(e.getMessage());
                returner(scanner);
                return null;
            }

        }
    }

    public boolean hospitalLister(){
        clear();
        header();
        if (hospitalManager.getHospitals().isEmpty()){
            System.out.println("\nHospital list is empty.");
            returner(scanner);
            return false;
        }

        Comparator<Hospital> comparator = Comparator
                .comparing(Hospital::getCity)
                        .thenComparing((Hospital::getId));

        System.out.println();

        hospitalManager.getHospitals().values().stream()
                .sorted(comparator)
                .forEach(System.out::println);

        returner(scanner);
        return true;
    }
    
}
