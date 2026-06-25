package mertguler.GUI.Admin.Hospital;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonBar;
import javafx.scene.control.ButtonType;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import mertguler.Exceptions.IDException;
import mertguler.Hospital.Hospital;

import java.util.Optional;

import static mertguler.GUI.Gui.*;

public class DeleteHospitalGUI {
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

        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        Stage stage = (Stage) alert.getDialogPane().getScene().getWindow();
        stage.getIcons().add(app_image);
        alert.setTitle("Confirmation");
        alert.setHeaderText("Hospital: " + hospital.getName() + ", " + hospital.getCity() + ", ID: " + hospital.getId()
                        + " is found.");
        alert.setContentText("Please confirm deletion. This action cannot be undone.");
        ButtonType confirmButton = new ButtonType("Delete", ButtonBar.ButtonData.OK_DONE);
        ButtonType cancelButton = new ButtonType("Cancel", ButtonBar.ButtonData.CANCEL_CLOSE);
        alert.getButtonTypes().setAll(confirmButton, cancelButton);

        Optional<ButtonType> result = alert.showAndWait();
        if (result.get() == confirmButton) {
            crs.getHospitalManager().deleteHospital(hospitalID);
            System.out.println("Hospital with ID: " + hospitalID + " is successfully deleted");
            Alert successAlert = new Alert(Alert.AlertType.INFORMATION);
            successAlert.setTitle("Success");
            successAlert.setHeaderText(null);
            successAlert.setContentText("Hospital is permanently deleted!\nHospital ID: " + hospitalID);
            Stage stage2 = (Stage) successAlert.getDialogPane().getScene().getWindow();
            stage2.getIcons().add(app_image);
            successAlert.show();
        }
    }
}
