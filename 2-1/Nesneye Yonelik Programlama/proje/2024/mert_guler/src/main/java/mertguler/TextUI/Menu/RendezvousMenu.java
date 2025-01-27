package mertguler.TextUI.Menu;

import mertguler.CRS.CRS;
import mertguler.CRS.DateManager;
import mertguler.Exceptions.DailyLimitException;
import mertguler.Exceptions.IDException;
import mertguler.Exceptions.RendezvousLimitException;
import mertguler.Hospital.Hospital;
import mertguler.Hospital.Rendezvous;
import mertguler.Hospital.Section;
import mertguler.Person.Doctor;
import mertguler.Person.Patient;

import java.time.DateTimeException;
import java.time.LocalDate;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.Scanner;

import static mertguler.CRS.CRS.RENDEZVOUS_DAY_LIMIT;
import static mertguler.TextUI.TextUI.*;

public class RendezvousMenu {
    private Scanner scanner;
    private CRS crs;
    private HospitalMenu hospitalMenu;
    private SectionMenu sectionMenu;
    private DoctorMenu doctorMenu;

    public RendezvousMenu(Scanner scanner, CRS crs, HospitalMenu hospitalMenu, SectionMenu sectionMenu,
                          DoctorMenu doctorMenu){
        this.scanner = scanner;
        this.crs = crs;
        this.hospitalMenu = hospitalMenu;
        this.sectionMenu = sectionMenu;
        this.doctorMenu = doctorMenu;
    }

    public void rendezvousManager(){
        while (true){
            clear();
            header();
            int input = 9;

            System.out.println("\nAdd Appointment: 1");
            System.out.println("Delete Appointment: 2");
            System.out.println("Check Appointment Info: 3");
            System.out.println("List All Appointment: 4");
            System.out.println("Return to last menu: 0");
            System.out.println("\nSelect operating mode (1-4):");

            try {
                input = Integer.valueOf(scanner.nextLine());
            } catch (Exception e) {
                System.out.println("Please enter only valid numbers within range");
                returner(scanner);;
                continue;
            }

            if (input == 0){
                return;
            } else if (input == 1){
                rendezvousAdder();
            } else if (input == 2){
                rendezvousDeleter();
            } else if (input == 3){
                rendezvousInfoChecker();
            } else if (input == 4){
                rendezvousLister();
            }
        }
    }

    public boolean rendezvousInfoChecker(){
        clear();
        header();
        long national_id = nationalIDSelector(scanner);

        if (national_id == 0){
            System.out.println("\nNational ID can`t be 0");
            returner(scanner);
            return false;
        }

        Patient patient;

        try {
            patient = crs.getPatientManager().getPatient(national_id);
        } catch (IDException e){
            System.out.println(e.getMessage()) ;
            returner(scanner);;
            clear();
            return false;
        }

        ArrayList<Rendezvous> rendezvousList = patient.getRendezvouses();

        if(!(rendezvousLister(rendezvousList, patient))){
            return false;
        }

        System.out.println("\nWhich Appointment to check? Enter Appointment ID from list above:");

        Rendezvous rendezvous;
        int input = 0;

        try {
            input = Integer.valueOf(scanner.nextLine()) - 1;
            rendezvous = rendezvousList.get(input);
        } catch (Exception e){
            System.out.println("\nEnter valid numbers only\n");
            returner(scanner);
            clear();
            return false;
        }

        clear();
        header();
        System.out.println("\nAppointment Info: ");
        System.out.println("Patient Name: " + patient.getName());
        System.out.println("Patient ID: " + patient.getNational_id());
        System.out.println("Doctor Name: " + rendezvous.getDoctor().getName());
        System.out.println("Section: " + rendezvous.getSection());
        System.out.println("Hospital: " + rendezvous.getHospital());
        System.out.println("Date: " + rendezvous.getDate());
        System.out.println("Expired: " + rendezvous.isExpired());
        returner(scanner);
        clear();
        return true;
    }

    public boolean rendezvousAdder(){
        while (true){
            clear();
            header();
            long national_id = nationalIDSelector(scanner);
            
            if (national_id == 0){
                System.out.println("\nNational ID can`t be 0");
                returner(scanner);
                return false;
            }

            Patient patient;

            try {
                patient = crs.getPatientManager().getPatient(national_id);
            } catch (IDException e){
                System.out.println("\n" + e.getMessage());
                returner(scanner);
                return false;
            }

            try {
                patient.checkActiveRendezvousCount();
            } catch (RendezvousLimitException e) {
                System.out.println(e.getMessage());
                returner(scanner);
                return false;
            }

            Hospital hospital = hospitalMenu.hospitalSelector();

            // Check this part
            if (hospital == null){
                return false;
            }

            sectionMenu.setHospital(hospital);

            Section section = sectionMenu.sectionSelector();

            // Check this part
            if (section == null){
                return false;
            }

            Doctor doctor = doctorMenu.doctorSelector(section);

            if (doctor == null){
                return false;
            }

            LocalDate currentDate = DateManager.getCurrentDate();
            LocalDate lastRendezvousDate = DateManager.getLastDate();

            System.out.println("\nHospital: " + hospital);
            System.out.println("Section: " + section);
            System.out.println("Doctor: " + doctor);
            System.out.println("Current Time: " + DateManager.getFormatedDate(currentDate));

            System.out.println("\nYou can book appointment for next " + RENDEZVOUS_DAY_LIMIT + " days");
            System.out.println("Last Date: " + DateManager.getFormatedDate(lastRendezvousDate));

            System.out.println("\nPlease enter desired date as dd-mm-yyyy format");
            System.out.println("Enter date within the day limit");

            String desiredDateStr = "";

            try {
                desiredDateStr = scanner.nextLine();
            } catch (Exception e){
                System.out.println("\nEnter valid characters only");
                returner(scanner);;
                clear();
                return false;
            }

            LocalDate desiredDate = null;

            try {
                desiredDate = DateManager.isValidDate(desiredDateStr);
            } catch (DateTimeParseException e){
                System.out.println(e.getMessage());
                returner(scanner);;
                clear();
                return false;
            }

            try {
                DateManager.checkDateRange(desiredDate);
            } catch (DateTimeException e){
                System.out.println(e.getMessage());
                returner(scanner);;
                clear();
                return false;
            }

            try {
                // DailyLimitException
                doctor.getSchedule().checkDailyLimit(desiredDate);
            } catch (DailyLimitException e) {
                System.out.println(e.getMessage());
                returner(scanner);
            }

            Rendezvous rendezvous = new Rendezvous(desiredDate, doctor, patient, hospital, section);
                crs.addRendezvous(doctor, rendezvous, patient);
                clear();
                header();
                System.out.println("\nAppointment is successfully made\n");
                System.out.println("Patient Name: " + patient.getName());
                System.out.println("Patient National ID: " + patient.getNational_id());
                System.out.println("Doctor Name: " + doctor.getName());
                System.out.println("Section: " + section.getName());
                System.out.println("Hospital: " + hospital.getName());
                System.out.println("Date: " + desiredDateStr + "\n");
                returner(scanner);;
                clear();
                return true;

        }
    }

    public boolean rendezvousDeleter(){
        while (true){
            clear();
            header();
            long national_id = nationalIDSelector(scanner);

            if (national_id == 0){
                System.out.println("\nNational ID can`t be 0");
                returner(scanner);
                return false;
            }

            Patient patient;

            try {
                patient = crs.getPatientManager().getPatient(national_id);
            } catch (IDException e){
                System.out.println(e.getMessage()) ;
                returner(scanner);;
                clear();
                return false;
            }

            ArrayList<Rendezvous> rendezvousList = patient.getRendezvouses();
            rendezvousLister(rendezvousList, patient);

            System.out.println("\nWhich Appointment to delete? Enter Appointment ID from list above:");

            Rendezvous rendezvous;
            int input = 0;

            try {
                input = Integer.valueOf(scanner.nextLine()) - 1;
                rendezvous = rendezvousList.get(input);
            } catch (Exception e){
                System.out.println("\nEnter valid numbers only\n");
                returner(scanner);
                clear();
                return false;
            }

            crs.deleteRendezvous(rendezvous);
            System.out.println("\nAppointment is successfully deleted");
            returner(scanner);
            return true;
        }
    }



    public boolean rendezvousLister(){
        ArrayList<Rendezvous> rendezvouses = crs.getRendezvouses();
        if (rendezvouses.isEmpty()){
            System.out.println("No appointment is found in system");
            returner(scanner);
            clear();
            return false;
        }


        int index = 0;
        for (Rendezvous rendezvous: rendezvouses){
            index++;
            System.out.println(rendezvous.getPatient().getName() + ", " + rendezvous.getDoctor().getName() + ", " + rendezvous.getHospital().getName() + ", " + rendezvous.getSection().getName() + ", ID: " + index);
        }

        returner(scanner);
        clear();
        return true;
    }

    public boolean rendezvousLister(ArrayList<Rendezvous> rendezvousList, Patient patient) throws NoSuchElementException {
        if (rendezvousList.isEmpty()){
            System.out.println("\nThis patient doesnt have any appointments");
            returner(scanner);
            clear();
            return false;
        }

        clear();
        header();
        System.out.println("\nAppointment List for Patient: " + patient);

        int index = 0;
        for (Rendezvous rendezvous: rendezvousList){
            index++;
            System.out.println(rendezvous.getHospital().getName() + ", " + rendezvous.getSection().getName() + ", ID: " + index);
        }
        return true;
    }
}
