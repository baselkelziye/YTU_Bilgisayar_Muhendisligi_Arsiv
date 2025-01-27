package mertguler.TextUI.Menu;

import mertguler.CRS.CRS;

import java.util.Scanner;

import static mertguler.TextUI.TextUI.*;

public class UserMenu {
    private Scanner scanner;
    private CRS crs;
    private HospitalMenu hospitalMenu;
    private SectionMenu sectionMenu;
    private DoctorMenu doctorMenu;
    private PatientMenu patientMenu;
    private RendezvousMenu rendezvousMenu;

    public UserMenu(Scanner scanner, CRS crs){
        this.scanner = scanner;
        this.crs = crs;
        hospitalMenu = new HospitalMenu(scanner, crs);
        sectionMenu = new SectionMenu(scanner, crs, hospitalMenu);
        doctorMenu = new DoctorMenu(scanner, crs, hospitalMenu, sectionMenu);
        patientMenu = new PatientMenu(scanner, crs);
        rendezvousMenu = new RendezvousMenu(scanner, crs, hospitalMenu, sectionMenu, doctorMenu);
    }

    public void start() {
        while (true) {
            clear();
            header();
            int input = 9;
            System.out.println("\nPatient Management: 1");
            System.out.println("Appointment Management: 2");
            System.out.println("Save Data: 3");
            System.out.println("Load Data: 4");
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
            } else if (input == 1) {
                patientMenu.patientManager();
            } else if (input == 2) {
                rendezvousMenu.rendezvousManager();
            } else if (input == 3) {
                crs.saveTablesToDisk();
                returner(scanner);
            } else if (input == 4) {
                crs.loadTablesFromDisk();
                returner(scanner);
            }
        }
    }

}
