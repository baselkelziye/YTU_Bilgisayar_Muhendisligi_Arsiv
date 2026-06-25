package mertguler.GUI.Universal.Rendezvous;


import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.stage.Stage;
import mertguler.Exceptions.IDException;
import mertguler.Hospital.Rendezvous;
import mertguler.Person.Patient;

import java.util.ArrayList;
import java.util.Optional;

import static mertguler.GUI.Gui.*;

public class DeleteRendezvousGUI {
    private long nationalID;
    private Patient patient;
    private Rendezvous rendezvous;

    @FXML
    private TextField nationalIDField;

    @FXML
    private ComboBox<Rendezvous> rendezvousBox;

    @FXML
    private Button button;


    public void setRendezvousBox(){
        try {
            nationalID = Integer.valueOf(nationalIDField.getText());
        } catch (NumberFormatException e) {
            showError("Please enter a valid National ID");
            return;
        }

        if (nationalID <= 0) {
            showError("National ID, must be greater than 0");
            return;
        }

        try {
            patient = crs.getPatientManager().getPatient(nationalID);
        } catch (IDException e) {
            System.out.println(e.getMessage());
            showError(e.getMessage());
            return;
        }

        ArrayList<Rendezvous> rendezvouses = patient.getRendezvouses();

        if (rendezvouses.isEmpty()){
            System.out.println("No rendezvous found for Patient: " + patient);
            showError("No rendezvous found for:\nPatient: " + patient);
            return;
        }

        rendezvousBox.setItems(FXCollections.observableArrayList(patient.getRendezvouses()));
        button.setText("Cancel");
    }


    public void check() {
        if (button.getText().equals("Check")){
            setRendezvousBox();
        } else {
            showSuccess();
        }
    }

    public void showSuccess() {
        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        Stage stage = (Stage) alert.getDialogPane().getScene().getWindow();
        stage.getIcons().add(app_image);
        alert.setTitle("Confirmation");
        alert.setHeaderText(null);
        alert.setContentText("Are you sure? Please confirm the cancellation. This action cannot be undone.");
        ButtonType confirmButton = new ButtonType("Confirm", ButtonBar.ButtonData.OK_DONE);
        ButtonType cancelButton = new ButtonType("Keep Appointment", ButtonBar.ButtonData.CANCEL_CLOSE);
        alert.getButtonTypes().setAll(confirmButton, cancelButton);

        Optional<ButtonType> result = alert.showAndWait();
        if (result.get() == confirmButton) {
            rendezvous = rendezvousBox.getValue();
            crs.deleteRendezvous(rendezvous);
            System.out.println("Appointment: " + rendezvous + " is cancelled");
        }

        Alert success = new Alert(Alert.AlertType.INFORMATION);
        Stage stage1 = (Stage) success.getDialogPane().getScene().getWindow();
        stage1.getIcons().add(app_image);
        success.setTitle("Appointment successfully cancelled");
        success.setHeaderText(null);
        success.setContentText("Appointment is successfully cancelled");
        success.showAndWait();
        rendezvousBox.getScene().getWindow().hide();

    }
}
