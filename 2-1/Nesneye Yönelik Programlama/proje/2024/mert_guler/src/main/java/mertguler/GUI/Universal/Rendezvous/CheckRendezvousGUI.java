package mertguler.GUI.Universal.Rendezvous;

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

public class CheckRendezvousGUI {
    private int nationalID;
    public static Patient patientForPatientRendezvousList;

    @FXML
    private TextField nationalIDFIeld;

    public void check() throws IOException{
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
            patientForPatientRendezvousList = crs.getPatientManager().getPatient(nationalID);
            System.out.println("Patient with ID: " + nationalID + ", is found");
            if (patientForPatientRendezvousList.getRendezvousCount() == 0){
                System.out.println("No rendezvous found for Patient: " + patientForPatientRendezvousList.getName());
                showError("No appointment found for Patient: " + patientForPatientRendezvousList.getName());
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
            showWindow("patient-rendezvous-list.fxml", "Appointment List for Patient: " + patientForPatientRendezvousList.getName(), Modality.APPLICATION_MODAL, image);
    }


}
