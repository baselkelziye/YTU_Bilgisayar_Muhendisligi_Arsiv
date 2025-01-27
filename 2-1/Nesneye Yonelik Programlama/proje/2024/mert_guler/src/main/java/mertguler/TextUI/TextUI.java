package mertguler.TextUI;

import mertguler.CRS.CRS;
import mertguler.TextUI.Menu.AdminMenu;
import mertguler.TextUI.Menu.UserMenu;

import java.io.IOException;
import java.util.Scanner;

import static mertguler.CRS.CRS.MAX_RENDEZVOUS_PER_PATIENT;
import static mertguler.CRS.CRS.RENDEZVOUS_DAY_LIMIT;

public class TextUI {
    private Scanner scanner;
    private CRS crs;
    private AdminMenu adminMenu;
    private UserMenu userMenu;

    public TextUI(Scanner scanner, CRS crs) {
        this.scanner = scanner;
        this.crs = crs;
    }

    public void start() {
        adminMenu = new AdminMenu(scanner, crs);
        userMenu = new UserMenu(scanner, crs);
        defaultsMenu();
        mainMenu();
    }

    public void defaultsMenu(){
        while (true) {
            clear();
            header();
            int input = 9;
            System.out.println("\n\nWARNING! TextUI is outdated!\n\nDefaults:");
            System.out.println("Max Appointment Per Patient: " + MAX_RENDEZVOUS_PER_PATIENT);
            System.out.println("Appointment Day Limit: " + RENDEZVOUS_DAY_LIMIT + " days");

            System.out.println("\nChange Defaults: 0");
            System.out.println("Continue with Defaults: 1");

            try {
                input = Integer.valueOf(scanner.nextLine());
            } catch (Exception e) {
                System.out.println("Please enter a valid number");
                returner(scanner);
                continue;
            }

            if (input == 0){
                while (true){
                    clear();
                    header();
                    System.out.println("\nEnter new value for `Max Appointment Per Patient`");

                    try {
                        input = Integer.valueOf(scanner.nextLine());
                    } catch (Exception e) {
                        System.out.println("Please enter a valid number");
                        returner(scanner);
                        continue;
                    }

                    if (input <= 0){
                        System.out.println("Please enter a valid number higher than 0");
                        returner(scanner);
                        clear();
                    }

                    crs.setMaxRendezvousPerPatient(input);

                    System.out.println("Max Appointment Per Patient is set to: " + input);
                    System.out.println("\nEnter new value for `Appointment Day Limit`");

                    try {
                        input = Integer.valueOf(scanner.nextLine());
                    } catch (Exception e) {
                        System.out.println("Please enter a valid number");
                        returner(scanner);
                        continue;
                    }

                    if (input <= 0){
                        System.out.println("Please enter a valid number higher than 0");
                        returner(scanner);
                        clear();
                    }

                    crs.setRendezvousDayLimit(input);

                    System.out.println("Appointment Day Limit is set to: " + input);
                    returner(scanner);
                    break;
                }
            }

            break;
        }
    }

    public void mainMenu() {
        while (true) {
            clear();
            header();
            int input = 9;
            System.out.println("\n\nWARNING! TextUI is outdated!\n\nAdmin Mode: 0");
            System.out.println("User Mode: 1");
            System.out.println("Save Default Settings: 2");
            System.out.println("Load Default Settings: 3");


            System.out.println("\nSelect operating mode (0-3):");

            try {
                input = Integer.valueOf(scanner.nextLine());
            } catch (Exception e) {
                System.out.println("Please enter only 0 or 1.");
                returner(scanner);
                continue;
            }

            if (input == 0) {
                adminMenu.start();
            } else if (input == 1){
                userMenu.start();
            } else if (input == 2){
                try {
                    crs.saveSettings();
                } catch (IOException e){
                    System.out.println(e.getMessage());
                    returner(scanner);
                }
                returner(scanner);
            } else if (input == 3){
                try {
                    crs.loadSettings();
                } catch (IOException e){
                    System.out.println(e.getMessage());
                    returner(scanner);
                } catch (ArrayIndexOutOfBoundsException ae){
                    System.out.println(ae.getMessage());
                    returner(scanner);
                }
                returner(scanner);
            }
        }
    }

    public static void header() {
        System.out.println("Hospital Appointment System - Text UI V1.2");
    }

    public static void clear() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    public static long nationalIDSelector(Scanner scanner) {
        clear();
        header();
        long national_id = 0;

        System.out.println("\nEnter National ID: ");

        try {
            national_id = Long.valueOf(scanner.nextLine());
        } catch (Exception e) {
            System.out.println("\nPlease enter only valid numbers\n");
            returner(scanner);
            clear();
            return 0;
        }

        return national_id;
    }

    public static void returner(Scanner scanner) {
        System.out.println("Press anything to return");
        scanner.nextLine();
    }

}
