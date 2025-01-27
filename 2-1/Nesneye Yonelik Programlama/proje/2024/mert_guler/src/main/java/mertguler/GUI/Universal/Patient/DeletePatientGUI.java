package mertguler.GUI.Universal.Patient;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonBar;
import javafx.scene.control.ButtonType;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import mertguler.Exceptions.IDException;
import mertguler.Person.Patient;

import java.util.Optional;

import static mertguler.GUI.Gui.*;

public class DeletePatientGUI {
    private int nationalID;

    @FXML
    private TextField idField;

    public void check() {
        try {
            nationalID = Integer.valueOf(idField.getText());
        } catch (NumberFormatException e) {
            showError("Invalid ID! Please enter a valid number");
            return;
        }

        if (nationalID <= 0){
            showError("National ID, must be greater than 0");
            return;
        }

        try {
            crs.getPatientManager().checkPatientID(nationalID);
            System.out.println("Patient with National ID: " + nationalID + ", is found");
            showSuccess();
        } catch (IDException e) {
            System.out.println(e.getMessage());
            showError(e.getMessage());
        }

    }


    public void showSuccess() {
        Patient patient = crs.getPatientManager().getPatient(nationalID);
        // Printing purposes only
        // No change in logic. Does not change anything in Patient class.
        String age = "Unknown";
        int checkedAge = patient.getAge();
        if (checkedAge > 0){
            age = String.valueOf(checkedAge);
        }

        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        Stage stage = (Stage) alert.getDialogPane().getScene().getWindow();
        stage.getIcons().add(app_image);
        alert.setTitle("Confirmation");
        alert.setHeaderText("Patient: " + patient.getName() + ", National ID: " + patient.getNational_id()
               + ", Age: " + age + " is found.");
        alert.setContentText("Please confirm deletion. This action cannot be undone.");
        ButtonType confirmButton = new ButtonType("Delete", ButtonBar.ButtonData.OK_DONE);
        ButtonType cancelButton = new ButtonType("Cancel", ButtonBar.ButtonData.CANCEL_CLOSE);
        alert.getButtonTypes().setAll(confirmButton, cancelButton);

        Optional<ButtonType> result = alert.showAndWait();
        if (result.get() == confirmButton) {
            crs.getPatientManager().patientDeleter(nationalID);
            System.out.println("Patient with ID: " + nationalID + " is successfully deleted");
            Alert successAlert = new Alert(Alert.AlertType.INFORMATION);
            successAlert.setTitle("Success");
            successAlert.setHeaderText(null);
            successAlert.setContentText("Patient is permanently deleted!\n" +
                    "Patient Name: " + patient.getName() +
                    "\nID: " + nationalID +
                    "\nAge: " + age);
            Stage stage2 = (Stage) successAlert.getDialogPane().getScene().getWindow();
            stage2.getIcons().add(app_image);
            successAlert.show();
        }
    }
}
