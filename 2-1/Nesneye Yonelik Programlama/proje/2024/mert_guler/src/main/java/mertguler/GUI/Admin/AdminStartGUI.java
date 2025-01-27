package mertguler.GUI.Admin;

import javafx.application.Application;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.Modality;
import mertguler.CRS.DateManager;
import mertguler.Main;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.time.format.DateTimeFormatter;
import java.util.ResourceBundle;

import static mertguler.GUI.Gui.*;

public class AdminStartGUI implements Initializable {

    @FXML
    private Button themeChanger;

    @FXML
    private ImageView themeIcon;

    @FXML
    private ImageView saveIcon;

    @FXML
    private ImageView loadIcon;


    @FXML
    private Label uiDate;

    public void initialize(URL url, ResourceBundle resourceBundle) {
        setCurrentDate();
    }

    public void setCurrentDate() {
        String date = DateManager.getCurrentDate().format(DateTimeFormatter.ofPattern("dd/MM/yyyy"));
        uiDate.setText(date);
    }

    @FXML
    public void switchAdminDashboard() throws IOException {
        changeScene("admin-dashboard.fxml");
    }

    @FXML
    public void showHospitalListWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/hospital.png");
        Image image = new Image(is);
        showWindow("hospital-list.fxml", "Hospital List", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showPatientListWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/patients.png");
        Image image = new Image(is);
        showWindow("patient-list.fxml", "Patient List", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showDoctorListWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/doctor-menu.png");
        Image image = new Image(is);
        showWindow("doctor-list.fxml", "Doctor List", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showSectionListWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/sections.png");
        Image image = new Image(is);
        showWindow("section-list.fxml", "Section List", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showRendezvousListWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/appointment.png");
        Image image = new Image(is);
        showWindow("rendezvous-list.fxml", "Appointment List", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showAddHospitalWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/add.png");
        Image image = new Image(is);
        showWindow("add-hospital.fxml", "Add Hospital", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showDeleteHospitalWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/delete.png");
        Image image = new Image(is);
        showWindow("delete-hospital.fxml", "Delete Hospital", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showRenameHospitalWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/rename.png");
        Image image = new Image(is);
        showWindow("rename-hospital.fxml", "Rename Hospital", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showAddSectionWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/add.png");
        Image image = new Image(is);
        showWindow("add-section.fxml", "Add Section", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showDeleteSectionWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/delete.png");
        Image image = new Image(is);
        showWindow("delete-section.fxml", "Delete Section", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showRenameSectionWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/rename.png");
        Image image = new Image(is);
        showWindow("rename-section.fxml", "Rename Section", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showAddDoctorWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/add.png");
        Image image = new Image(is);
        showWindow("add-doctor.fxml", "Add Doctor", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showDeleteDoctorWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/delete.png");
        Image image = new Image(is);
        showWindow("delete-doctor.fxml", "Delete Doctor", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showRenameDoctorWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/rename.png");
        Image image = new Image(is);
        showWindow("rename-doctor.fxml", "Rename Doctor", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showAddPatientWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/add.png");
        Image image = new Image(is);
        showWindow("add-patient.fxml", "Add Patient", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showDeletePatientWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/delete.png");
        Image image = new Image(is);
        showWindow("delete-patient.fxml", "Delete Patient", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showRenamePatientWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/rename.png");
        Image image = new Image(is);
        showWindow("rename-patient.fxml", "Rename Patient", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showMakeRendezvousWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/appointment.png");
        Image image = new Image(is);
        showWindow("add-rendezvous.fxml", "Make Appointment", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showCancelRendezvousWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/delete.png");
        Image image = new Image(is);
        showWindow("delete-rendezvous.fxml", "Cancel Appointment", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showCheckRendezvousWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/search.png");
        Image image = new Image(is);
        showWindow("check-rendezvous.fxml", "Check Appointment", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showAdminSettingsWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/settings.png");
        Image image = new Image(is);
        showWindow("admin-settings.fxml", "Settings", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void turnOffTheLights(){
        if (Application.getUserAgentStylesheet().equals(Main.class.getResource("mac-light.css").toExternalForm())){
            Application.setUserAgentStylesheet(Main.class.getResource("mac-dark.css").toExternalForm());
            themeChanger.setText("Light Mode");
            InputStream is = Main.class.getResourceAsStream("/images/lightmode.png");
            Image image = new Image(is);
            themeIcon.setImage(image);
        } else {
            Application.setUserAgentStylesheet(Main.class.getResource("mac-light.css").toExternalForm());
            themeChanger.setText("Dark Mode");
            InputStream is = Main.class.getResourceAsStream("/images/darkmode.png");
            Image image = new Image(is);
            themeIcon.setImage(image);
        }
    }

    @FXML
    public void goBack() throws IOException{
        changeScene("mode-select-menu.fxml");
    }

    @FXML
    public void save(){
        if (crs.saveTablesToDisk()){
            InputStream is = Main.class.getResourceAsStream("/images/save-success.png");
            Image image = new Image(is);
            saveIcon.setImage(image);
        } else {
            InputStream is = Main.class.getResourceAsStream("/images/save-failed.png");
            Image image = new Image(is);
            saveIcon.setImage(image);
        }
    }

    @FXML
    public void load(){
        if (crs.loadTablesFromDisk()){
            InputStream is = Main.class.getResourceAsStream("/images/load-success.png");
            Image image = new Image(is);
            loadIcon.setImage(image);
        } else {
            InputStream is = Main.class.getResourceAsStream("/images/load-failed.png");
            Image image = new Image(is);
            loadIcon.setImage(image);
        }
    }



}
