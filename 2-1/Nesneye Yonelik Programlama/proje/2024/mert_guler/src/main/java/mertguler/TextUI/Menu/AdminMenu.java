package mertguler.TextUI.Menu;

import mertguler.CRS.CRS;

import java.util.Scanner;

import static mertguler.TextUI.TextUI.*;

public class AdminMenu {
    private Scanner scanner;
    private CRS crs;
    private HospitalMenu hospitalMenu;
    private SectionMenu sectionMenu;
    private DoctorMenu doctorMenu;
    private PatientMenu patientMenu;
    private RendezvousMenu rendezvousMenu;

    public AdminMenu(Scanner scanner, CRS crs){
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
            System.out.println("\nHospital Management: 1");
            System.out.println("Section Management: 2");
            System.out.println("Doctor Management: 3");
            System.out.println("Patient Management: 4");
            System.out.println("Appointment Management: 5");
            System.out.println("Save Data: 6");
            System.out.println("Load Data: 7");
            System.out.println("Return to last menu: 0");
            System.out.println("\nSelect operating mode (1-5):");
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
                hospitalMenu.hospitalManager();
            } else if (input == 2){
                sectionMenu.sectionManager();
            } else if (input == 3){
                doctorMenu.doctorManager();
            } else if (input == 4){
                patientMenu.patientManager();
            } else if (input == 5){
                rendezvousMenu.rendezvousManager();
            } else if (input == 6){
                crs.saveTablesToDisk();
                returner(scanner);
            } else if (input == 7){
                crs.loadTablesFromDisk();
                returner(scanner);
            }
        }

    }

}
