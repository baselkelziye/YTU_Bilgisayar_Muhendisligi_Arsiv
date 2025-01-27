package mertguler.GUI.Admin.Doctor;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.stage.Stage;
import mertguler.Exceptions.DuplicateInfoException;
import mertguler.Exceptions.IDException;
import mertguler.Hospital.Hospital;
import mertguler.Hospital.Section;
import mertguler.Person.Doctor;

import java.net.URL;
import java.util.Optional;
import java.util.ResourceBundle;

import static mertguler.GUI.Gui.*;


public class AddDoctorGUI implements Initializable {
    private String name;
    private long nationalID;
    private int diplomaID;
    private Hospital hospital;
    private Section section;

    @FXML
    private TextField nameField;

    @FXML
    private TextField nationalIDField;

    @FXML
    private TextField diplomaIDField;

    @FXML
    private ComboBox<Hospital> hospitalBox;

    @FXML
    private ComboBox<Section> sectionBox;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        hospitalBox.setItems(FXCollections.observableArrayList(crs.getHospitals().values()));
    }

    public void setSectionBox(){
        hospital = hospitalBox.getValue();
        if (hospital == null){
            return;
        }
        sectionBox.setItems(FXCollections.observableArrayList(hospital.getSections()));
    }

    public void check() {
        section = sectionBox.getValue();
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

        try {
            diplomaID = Integer.valueOf(diplomaIDField.getText());
        } catch (NumberFormatException e) {
            showError("Please enter a valid Diploma ID");
            return;
        }

        if (nationalID <= 0) {
            showError("National ID, must be greater than 0");
            return;
        }

        if (diplomaID <= 0) {
            showError("Diploma ID, must be greater than 0");
            return;
        }

        if (hospital == null) {
            showError("Please select a hospital");
            return;
        }
        if (section == null) {
            showError("Please select a section");
            return;
        }

        try {
            section.checkDoctorDuplication(diplomaID);
            showSuccess();
        } catch (DuplicateInfoException e) {
            showError("Doctor is already exist in Section: " + section);
        }

    }

    public void showSuccess() {
        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        Stage stage = (Stage) alert.getDialogPane().getScene().getWindow();
        stage.getIcons().add(app_image);
        alert.setTitle("Confirmation");
        alert.setHeaderText("Hospital: " + hospital + "\n"
        + "Section: " + section + "\n"
        + "Doctor Name: " + name + "\n"
        + "National ID: " + nationalID + "\n"
        + "Diploma ID: " + diplomaID);
        alert.setContentText("Doctor is available to add. Please confirm the data.");
        ButtonType confirmButton = new ButtonType("Confirm", ButtonBar.ButtonData.OK_DONE);
        ButtonType cancelButton = new ButtonType("Cancel", ButtonBar.ButtonData.CANCEL_CLOSE);
        alert.getButtonTypes().setAll(confirmButton, cancelButton);

        Optional<ButtonType> result = alert.showAndWait();
        if (result.get() == confirmButton) {
            Doctor doctor = new Doctor(name, nationalID, diplomaID);
            section.addDoctor(doctor);
            System.out.println("Doctor: " + doctor + " is created");
            Alert successAlert = new Alert(Alert.AlertType.INFORMATION);
            successAlert.setTitle("Success");
            successAlert.setHeaderText(null);
            successAlert.setContentText("Doctor is successfully created!");
            Stage stage2 = (Stage) successAlert.getDialogPane().getScene().getWindow();
            stage2.getIcons().add(app_image);
            successAlert.show();
        }
    }

}
