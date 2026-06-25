package mertguler.TextUI.Menu;

import mertguler.CRS.CRS;
import mertguler.Exceptions.DuplicateInfoException;
import mertguler.Exceptions.IDException;
import mertguler.Hospital.Hospital;
import mertguler.Hospital.Section;

import java.util.Comparator;
import java.util.Scanner;

import static mertguler.TextUI.TextUI.*;

public class SectionMenu {
    private Scanner scanner;
    private CRS crs;
    private Hospital hospital;
    private HospitalMenu hospitalMenu;

    public SectionMenu(Scanner scanner, CRS crs, HospitalMenu hospitalMenu){
        this.scanner = scanner;
        this.crs = crs;
        this.hospitalMenu = hospitalMenu;
    }

    public void setHospital(Hospital hospital){
        this.hospital = hospital;
    }

    public void sectionManager() {
        hospital = hospitalMenu.hospitalSelector();
        if (hospital == null){
            return;
        }

        while (true) {
            clear();
            header();
            int input = 9;
            System.out.println("\nHospital: " + hospital.getName() + ", ID: " + hospital.getId() + "\n");
            System.out.println("Add Section: 1");
            System.out.println("Delete Section: 2");
            System.out.println("Rename Section: 3");
            System.out.println("List Sections: 4");
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
            } else if (input == 1){
                sectionAdder();
            } else if (input == 2){
                sectionDeleter();
            } else if (input == 3){
                sectionRenamer();
            } else if (input == 4){
                sectionLister();
            }
        }
    }

    public boolean sectionLister(){
        clear();
        header();
        if (hospital.getSections().isEmpty()){
            System.out.println("\nSection list is empty.");
            returner(scanner);
            return false;
        }

        Comparator<Section> comparator = Comparator
                .comparing(Section::getId);

        System.out.println();

        hospital.getSections().stream()
                .sorted(comparator)
                .forEach(System.out::println);

        returner(scanner);
        return true;
    }

    public boolean sectionRenamer(){
        while (true) {
            clear();
            header();
            int id = 9;
            String name = "";

            System.out.println("Enter Section ID: ");

            try {
                id = Integer.valueOf(scanner.nextLine());
            } catch (Exception e) {
                System.out.println("Please enter only valid numbers within range");
                returner(scanner);
                return false;
            }

            if (hospital.getSection(id) == null){
                System.out.println("Section with ID: " + id + " is not found");
                returner(scanner);
                return false;
            }

            System.out.println("Enter the new name: ");

            try {
                name = scanner.nextLine();
            } catch (Exception e) {
                System.out.println("Please enter only valid characters");
                returner(scanner);
                return false;
            }

            hospital.getSection(id).setName(name);
            return true;
        }
    }

    public boolean sectionAdder(){
        while (true) {
            clear();
            header();
            int id = 9;
            String name = "";
            System.out.println("Enter Section Name: ");

            try {
                name = scanner.nextLine();
            } catch (Exception e) {
                System.out.println("Please enter only valid characters");
                returner(scanner);
                continue;
            }

            if (name.isBlank()){
                System.out.println("Name cant be empty");
                returner(scanner);
                return false;
            }

            try {
                hospital.addSection(new Section(name, hospital, false));
                System.out.println("Selection is successfully added.");
                returner(scanner);
                return true;
            } catch (DuplicateInfoException e){
                System.out.println("Section with this id is already exists");
                returner(scanner);
                return false;
            }
        }
    }

    public boolean sectionDeleter(){
        while (true) {
            clear();
            header();
            int sectionId = 9;
            System.out.println("Enter Section ID: ");

            try {
                sectionId = Integer.valueOf(scanner.nextLine());
            } catch (Exception e) {
                System.out.println("Please enter only valid numbers within range");
                returner(scanner);
                return false;
            }

            try {
                crs.getHospitalManager().getSectionManager().deleteSection(hospital.getId(), sectionId);
                System.out.println("Section is successfully deleted.");
                returner(scanner);
                return true;
            } catch (IDException e){
                System.out.println(e.getMessage());
                returner(scanner);
                return false;
            }
        }
    }

    public Section sectionSelector(){
        // useless
        if (hospital == null){
            return null;
        }

        if(hospital.getSections().isEmpty()){
            clear();
            header();
            System.out.println("\nNo Section found for Hospital: " + hospital);
            returner(scanner);
            return null;
        }

        while (true){
            clear();
            header();
            int input = 9;
            System.out.println("\n" + hospital);
            System.out.println("Select a Section to continue with next menu.\n");
            System.out.println("Select Section with id: 1");
            System.out.println("Select Section with name: 2");
            System.out.println("List Sections: 3");
            System.out.println("Return to main menu: 0");
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
                return getSectionWithId();
            } else if (input == 2){
                return getSectionWithName();
            } else if (input == 3){
                clear();
                header();
                sectionLister();
            }
        }
    }

    public Section getSectionWithId(){
        while (true){
            clear();
            header();
            int id = 9;

            System.out.println("Enter Section ID: ");

            try {
                id = Integer.valueOf(scanner.nextLine());
            } catch (Exception e) {
                System.out.println("Please enter only valid numbers");
                returner(scanner);
                return null;
            }

            Section section = hospital.getSection(id);

            if (section == null){
                System.out.println("Section with ID: " + id + " is not found");
                returner(scanner);
                return null;
            } else {
                return section;
            }

        }
    }

    public Section getSectionWithName(){
        while (true){
            clear();
            header();
            String name = "";

            System.out.println("Enter Section Name: ");

            try {
                name = scanner.nextLine();
            } catch (Exception e) {
                System.out.println("Please enter only valid numbers");
                returner(scanner);
                return null;
            }

            Section section = hospital.getSection(name);
            if (section == null){
                System.out.println("Section with name: " + name + " is not found");
                returner(scanner);
                return null;
            } else {
                return section;
            }

        }
    }
    

}
