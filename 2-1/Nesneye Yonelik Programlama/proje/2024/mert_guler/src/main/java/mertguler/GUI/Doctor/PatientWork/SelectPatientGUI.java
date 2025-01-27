package mertguler.GUI.Doctor.PatientWork;

import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.stage.Modality;
import mertguler.Exceptions.IDException;
import mertguler.Main;
import mertguler.Person.Patient;

import java.io.IOException;
import java.io.InputStream;

import static mertguler.GUI.Gui.*;

public class SelectPatientGUI {
    private int nationalID;
    public static Patient checkedDoctorsPatient;

    @FXML
    private TextField nationalIDFIeld;

    public void check() throws IOException {
        try {
            nationalID = Integer.valueOf(nationalIDFIeld.getText());
        } catch (NumberFormatException e) {
            showError("Invalid ID! Please enter a valid number");
            return;
        }

        if (nationalID <= 0){
            showError("National ID, must be greater than 0");
            return;
        }

        try {
            checkedDoctorsPatient = crs.getPatientManager().getPatient(nationalID);
            System.out.println("Patient with ID: " + nationalID + ", is found");
            if (checkedDoctorsPatient.getRendezvousCount() == 0){
                System.out.println("No rendezvous is found for Patient: " + checkedDoctorsPatient.getName());
                showError("No appointment is found for Patient: " + checkedDoctorsPatient.getName());
            } else {
                showSuccess();

            }

        } catch (IDException e) {
            System.out.println(e.getMessage());
            showError(e.getMessage());
        }

    }


    public void showSuccess() throws IOException{
        InputStream is = Main.class.getResourceAsStream("/images/appointment.png");
        Image image = new Image(is);
        showWindow("doctor-rendezvouses-with-patient.fxml", "Your Appointments with Patient: " + checkedDoctorsPatient.getName(), Modality.APPLICATION_MODAL, image);
    }
}
