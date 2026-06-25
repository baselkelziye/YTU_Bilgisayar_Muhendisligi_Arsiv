package mertguler.GUI.Admin.Hospital;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Dialog;
import javafx.scene.control.TextField;
import javafx.scene.control.TextInputDialog;
import javafx.stage.Stage;
import mertguler.Exceptions.IDException;
import mertguler.Hospital.Hospital;

import java.util.Optional;

import static mertguler.GUI.Gui.*;

public class RenameHospitalGUI {
    private int hospitalID;

    @FXML
    private TextField idField;

    public void check() {
        try {
            hospitalID = Integer.valueOf(idField.getText());
        } catch (NumberFormatException e) {
            showError("Invalid ID! Please enter a valid number");
            return;
        }

        if (hospitalID <= 0){
            showError("Hospital ID, must be greater than 0");
            return;
        }

        try {
            crs.getHospitalManager().checkHospitalID(hospitalID);
            System.out.println("Hospital with ID: " + hospitalID + ", is found");
            showSuccess();
        } catch (IDException e) {
            System.out.println(e.getMessage());
            showError(e.getMessage());
        }

    }

    public void showSuccess() {
        Hospital hospital = crs.getHospitalManager().getHospitalWithID(hospitalID);

        Dialog dialog = new TextInputDialog();
        Stage stage = (Stage) dialog.getDialogPane().getScene().getWindow();
        stage.getIcons().add(app_image);
        dialog.setTitle("Rename");
        dialog.setHeaderText("Enter new name for Hospital: " + hospital.getName());
        dialog.setContentText("New name:");

        Optional<String> result = dialog.showAndWait();
        if (result.isPresent()){
            String newName = result.get();
            if (newName.isBlank()){
                showError("New name cant be empty!");
            } else {
                hospital.setName(newName);
                System.out.println("Hospital with ID: " + hospitalID + " is successfully renamed to: " + newName);
                Alert successAlert = new Alert(Alert.AlertType.INFORMATION);
                successAlert.setTitle("Success");
                successAlert.setHeaderText(null);
                successAlert.setContentText("Hospital with ID: " + hospitalID + " is successfully renamed!\n" +
                        "New name: " + newName);
                Stage stage2 = (Stage) successAlert.getDialogPane().getScene().getWindow();
                stage2.getIcons().add(app_image);
                successAlert.show();
            }
        }

    }
}
