package mertguler.GUI.Admin.Doctor;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;
import javafx.stage.Stage;
import mertguler.Exceptions.IDException;
import mertguler.Hospital.Hospital;
import mertguler.Hospital.Section;
import mertguler.Person.Doctor;

import java.net.URL;
import java.util.ResourceBundle;

import static mertguler.GUI.Gui.*;

public class DeleteDoctorGUI implements Initializable {
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

        try {
            section.deleteDoctor(doctor.getDiploma_id());
            showSuccess("Doctor: " + doctor.getName() + ", Diploma ID: " + doctor.getDiploma_id() + "\nis successfully deleted!");
        } catch (IDException e) {
            System.out.println(e.getMessage());
            showError(e.getMessage());
        }

    }

    public void showSuccess(String content) {
        Alert successAlert = new Alert(Alert.AlertType.INFORMATION);
        successAlert.setTitle("Success");
        successAlert.setHeaderText(null);
        successAlert.setContentText(content);
        Stage stage2 = (Stage) successAlert.getDialogPane().getScene().getWindow();
        stage2.getIcons().add(app_image);
        successAlert.showAndWait();
        doctorBox.getScene().getWindow().hide();
    }
}
