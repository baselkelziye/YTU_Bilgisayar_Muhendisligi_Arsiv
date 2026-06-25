package mertguler.GUI.Universal.Rendezvous;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.stage.Stage;
import mertguler.CRS.DateManager;
import mertguler.Exceptions.*;
import mertguler.Hospital.Hospital;
import mertguler.Hospital.Rendezvous;
import mertguler.Hospital.Section;
import mertguler.Person.Doctor;
import mertguler.Person.Patient;

import java.net.URL;
import java.time.LocalDate;
import java.util.Optional;
import java.util.ResourceBundle;

import static mertguler.GUI.Gui.*;

public class AddRendezvousGUI implements Initializable {
    private long nationalID;
    private Hospital hospital;
    private Section section;
    private Doctor doctor;
    private Patient patient;
    private LocalDate desiredDate;
    private Rendezvous rendezvous;

    @FXML
    private TextField nationalIDField;

    @FXML
    private ComboBox<Hospital> hospitalBox;

    @FXML
    private ComboBox<Section> sectionBox;

    @FXML
    private ComboBox<Doctor> doctorBox;

    @FXML
    private DatePicker datePicker;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        hospitalBox.setItems(FXCollections.observableArrayList(crs.getHospitals().values()));

        LocalDate minDate = LocalDate.now();
        LocalDate maxDate = DateManager.getLastDate();
        datePicker.setDayCellFactory(d ->
                new DateCell() {
                    @Override public void updateItem(LocalDate item, boolean empty) {
                        super.updateItem(item, empty);
                        setDisable(item.isAfter(maxDate) || item.isBefore(minDate));
                    }});
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

        if (doctor == null){
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

        desiredDate = datePicker.getValue();

        if (desiredDate == null){
            showError("Please select a date");
            return;
        }

        try {
            crs.checkValidity(nationalID, doctor, desiredDate);
            patient = crs.getPatientManager().getPatient(nationalID);
            crs.checkChildSection(patient, section);
            rendezvous = new Rendezvous(desiredDate, doctor, patient, hospital, section);
            doctor.getSchedule().checkRendezvousDuplication(rendezvous);
            showSuccess();
        } catch (IDException ie) {
            System.out.println(ie.getMessage());
            showError(ie.getMessage());
            return;
        } catch (RendezvousLimitException rle){
            System.out.println(rle.getMessage());
            showError(rle.getMessage());
            return;
        } catch (DailyLimitException dle){
            System.out.println(dle.getMessage());
            showError(dle.getMessage());
        } catch (DuplicateInfoException die){
            System.out.println(die.getMessage());
            showError(die.getMessage());
        } catch (ChildOnlyException coe){
            System.out.println(coe.getMessage());
            showError(coe.getMessage());
        }

    }

    public void showSuccess() {
        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        Stage stage = (Stage) alert.getDialogPane().getScene().getWindow();
        stage.getIcons().add(app_image);
        alert.setTitle("Confirmation");
        alert.setHeaderText("Patient: " + patient.getName() +
                "\nHospital: " + hospital +
                "\nSection: " + section +
                "\nDoctor Name: " + doctor.getName() +
                "\nDate: " + desiredDate);
        alert.setContentText("Appointment is available. Please confirm.");
        ButtonType confirmButton = new ButtonType("Confirm", ButtonBar.ButtonData.OK_DONE);
        ButtonType cancelButton = new ButtonType("Cancel", ButtonBar.ButtonData.CANCEL_CLOSE);
        alert.getButtonTypes().setAll(confirmButton, cancelButton);

        Optional<ButtonType> result = alert.showAndWait();
        if (result.get() == confirmButton) {
            crs.addRendezvous(doctor, rendezvous, patient);
            System.out.println("Appointment: " + rendezvous + " is created");
            Alert successAlert = new Alert(Alert.AlertType.INFORMATION);
            successAlert.setTitle("Success");
            successAlert.setHeaderText(null);
            successAlert.setContentText("Appointment is successfully made!");
            Stage stage2 = (Stage) successAlert.getDialogPane().getScene().getWindow();
            stage2.getIcons().add(app_image);
            successAlert.show();
        }
    }
}
