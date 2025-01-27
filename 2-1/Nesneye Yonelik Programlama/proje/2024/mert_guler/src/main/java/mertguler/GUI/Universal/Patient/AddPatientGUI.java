package mertguler.GUI.Universal.Patient;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.stage.Stage;
import mertguler.Exceptions.DuplicateInfoException;
import mertguler.Person.Patient;

import java.net.URL;
import java.time.LocalDate;
import java.util.Optional;
import java.util.ResourceBundle;

import static mertguler.CRS.DateManager.getYearDifference;
import static mertguler.GUI.Gui.*;


public class AddPatientGUI implements Initializable{
    private String name;
    private long nationalID;
    private LocalDate birthdate;
    private boolean unknownDate = false;

    // Printing purposes only
    private String age;

    @FXML
    private TextField nameField;

    @FXML
    private TextField nationalIDField;

    @FXML
    private DatePicker datePicker;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        // FUTURE DATE BLOCKER
        datePicker.setDayCellFactory(param -> new DateCell() {
            @Override
            public void updateItem(LocalDate date, boolean empty) {
                super.updateItem(date, empty);
                setDisable(empty || date.compareTo(LocalDate.now()) > 0 );
            }
        });
    }

    public void changeUnknownDate(){
        if (unknownDate){
            unknownDate = false;
        } else {
            unknownDate = true;
        }
    }

    public void check() {
        name = nameField.getText();

        if (name.isBlank()){
            showError("Name cant be empty!");
            return;
        }

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

        if (unknownDate){
            birthdate = null;
            // Printing purposes only
            age = "Unknown";
        } else {
            birthdate = datePicker.getValue();
            // Printing purposes only
            age = String.valueOf(getYearDifference(birthdate));
        }

        try {
            crs.getPatientManager().checkPatientDuplication(nationalID);
        } catch (DuplicateInfoException e) {
            showError(e.getMessage());
            return;
        }

        showSuccess();

    }

    public void showSuccess() {
        // Printing purposes only
        // Doesn't change the logic
        if (age.equals(String.valueOf(0))){
            age = "0 or Unknown";
        }

        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        Stage stage = (Stage) alert.getDialogPane().getScene().getWindow();
        stage.getIcons().add(app_image);
        alert.setTitle("Confirmation");
        alert.setHeaderText("Name: " + name + "\n"
                + "National ID: " + nationalID + "\n"
                + "Age: " + age + "\n");
        alert.setContentText("Patient is available to add. Please confirm the data. Confirm or Cancel");
        ButtonType confirmButton = new ButtonType("Confirm", ButtonBar.ButtonData.OK_DONE);
        ButtonType cancelButton = new ButtonType("Cancel", ButtonBar.ButtonData.CANCEL_CLOSE);
        alert.getButtonTypes().setAll(confirmButton, cancelButton);

        Optional<ButtonType> result = alert.showAndWait();
        if (result.get() == confirmButton) {
            crs.getPatients().put(nationalID, new Patient(name, nationalID, birthdate));
            System.out.println("Patient: " + name + ", ID: " + nationalID + ", Age: " + age + " is created");
            Alert successAlert = new Alert(Alert.AlertType.INFORMATION);
            successAlert.setTitle("Success");
            successAlert.setHeaderText(null);
            successAlert.setContentText("Patient is successfully created!");
            Stage stage2 = (Stage) successAlert.getDialogPane().getScene().getWindow();
            stage2.getIcons().add(app_image);
            successAlert.show();
        }
    }

}
