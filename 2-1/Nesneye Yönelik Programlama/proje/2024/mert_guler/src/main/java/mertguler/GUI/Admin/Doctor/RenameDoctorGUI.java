package mertguler.GUI.Admin.Doctor;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Dialog;
import javafx.scene.control.TextInputDialog;
import javafx.stage.Stage;
import mertguler.Hospital.Hospital;
import mertguler.Hospital.Section;
import mertguler.Person.Doctor;

import java.net.URL;
import java.util.Optional;
import java.util.ResourceBundle;

import static mertguler.GUI.Gui.*;

public class RenameDoctorGUI implements Initializable {
    private Hospital hospital;
    private Section section;
    private Doctor doctor;

    @FXML
    private ComboBox<Hospital> hospitalBox;

    @FXML
    private ComboBox<Section> sectionBox;

    @FXML
    private ComboBox<Doctor> doctorBox;

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

    public void setDoctorBox(){
        section = sectionBox.getValue();
        if (section == null){
            return;
        }
        doctorBox.setItems(FXCollections.observableArrayList(section.getDoctors()));
    }


    public void check() {
        doctor = doctorBox.getValue();

        if (hospital == null) {
            showError("Please select a hospital");
            return;
        }
        if (section == null) {
            showError("Please select a section");
            return;
        }
        if (doctor == null) {
            showError("Please select a doctor");
            return;
        }

        showSuccess();

    }


    public void showSuccess() {
        Dialog dialog = new TextInputDialog();
        Stage stage = (Stage) dialog.getDialogPane().getScene().getWindow();
        stage.getIcons().add(app_image);
        dialog.setTitle("Rename");
        dialog.setHeaderText("Enter new name for Doctor: " + doctor);
        dialog.setContentText("New name:");

        Optional<String> result = dialog.showAndWait();
        if (result.isPresent()){
            String newName = result.get();
            if (newName.isBlank()){
                showError("New name cant be empty!");
            } else {
                doctor.setName(newName);
                System.out.println("Doctor with Diploma ID: " + doctor.getDiploma_id() + " is successfully renamed to: " + newName);
                Alert successAlert = new Alert(Alert.AlertType.INFORMATION);
                successAlert.setTitle("Success");
                successAlert.setHeaderText(null);
                successAlert.setContentText("Doctor with ID: " + doctor.getDiploma_id() + " is successfully renamed!\n" +
                        "New name: " + newName);
                Stage stage2 = (Stage) successAlert.getDialogPane().getScene().getWindow();
                stage2.getIcons().add(app_image);
                successAlert.show();
            }
        }
    }
}
