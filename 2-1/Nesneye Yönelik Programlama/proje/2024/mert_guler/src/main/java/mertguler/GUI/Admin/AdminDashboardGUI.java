package mertguler.GUI.Admin;

import javafx.application.Application;
import javafx.beans.binding.Bindings;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.PieChart;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.Modality;
import javafx.stage.Stage;
import mertguler.CRS.DateManager;
import mertguler.Hospital.Hospital;
import mertguler.Hospital.Rendezvous;
import mertguler.Hospital.Section;
import mertguler.Main;
import mertguler.Person.Doctor;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.ResourceBundle;
import java.util.concurrent.atomic.AtomicInteger;

import static mertguler.GUI.Gui.*;


public class AdminDashboardGUI implements Initializable {
    private Stage stage;
    private Scene scene;
    private Parent root;
    private int[] monthlyRendezvouses = new int[12];
    private Hospital hospital;


    @FXML
    private Button themeChanger;

    @FXML
    private ImageView saveIcon;

    @FXML
    private ImageView loadIcon;

    @FXML
    private ImageView themeIcon;

    @FXML
    private Label currentYear;

    @FXML
    private Label patientCount;

    @FXML
    private Label doctorCount;

    @FXML
    private Label hospitalCount;

    @FXML
    private Label sectionCount;

    @FXML
    private Label totalRendezvousCount;

    @FXML
    private Label activeRendezvousCount;

    @FXML
    private ComboBox<Hospital> hospitalBox;

    @FXML
    private PieChart pieChart;

    @FXML
    private Label uiDate;

    @FXML
    private Label activeHospital;

    @FXML
    private Label activeSection;

    @FXML
    private Label activeDoctor;

    @FXML
    private ImageView activeIconHospital;

    @FXML
    private ImageView activeIconSection;

    @FXML
    private ImageView activeIconDoctor;

    @FXML
    private LineChart<String, Number> patientVisitsChart;

    public void initialize(URL url, ResourceBundle resourceBundle) {
        setCurrentDate();
        setPatientCount();
        setDoctorCount();
        setHospitalCount();
        setSectionCount();
        setTotalRendezvousCount();
        setActiveRendezvousCount();
        XYChart.Series series = new XYChart.Series();
        series.setName("Total Appointment Count");
        series.getData().add(new XYChart.Data("Jan", monthlyRendezvouses[0]));
        series.getData().add(new XYChart.Data("Feb", monthlyRendezvouses[1]));
        series.getData().add(new XYChart.Data("March", monthlyRendezvouses[2]));
        series.getData().add(new XYChart.Data("April", monthlyRendezvouses[3]));
        series.getData().add(new XYChart.Data("May", monthlyRendezvouses[4]));
        series.getData().add(new XYChart.Data("June", monthlyRendezvouses[5]));
        series.getData().add(new XYChart.Data("July", monthlyRendezvouses[6]));
        series.getData().add(new XYChart.Data("Aug", monthlyRendezvouses[7]));
        series.getData().add(new XYChart.Data("Sep", monthlyRendezvouses[8]));
        series.getData().add(new XYChart.Data("Oct", monthlyRendezvouses[9]));
        series.getData().add(new XYChart.Data("Nov", monthlyRendezvouses[10]));
        series.getData().add(new XYChart.Data("Dec", monthlyRendezvouses[11]));
        patientVisitsChart.getData().add(series);

        currentYear.setText(String.valueOf(DateManager.getCurrentDate().getYear()));

        hospitalBox.setItems(FXCollections.observableArrayList(crs.getHospitals().values()));

        ObservableList<PieChart.Data> pieChartData =
                FXCollections.observableArrayList(
                        new PieChart.Data("Hospitals", crs.getHospitalManager().getHospitals().size()),
                        new PieChart.Data ("Sections", crs.getHospitalManager().countAllSections()),
                        new PieChart.Data("Doctors", crs.getHospitalManager().countAllDoctors()));
        pieChartData.forEach(data ->
                data.nameProperty().bind(
                        Bindings.concat(
                                data.getName(), ": ", data.pieValueProperty()
                        )
                )
        );
        pieChart.getData().addAll(pieChartData);
        HashMap<Integer, Hospital> hospitals = crs.getHospitals();
        Hospital mostActiveHospital = null;
        int maxRendezvousCount = 0;
        int rendezvousCount;
        for (Hospital hospital: hospitals.values()){
            rendezvousCount = hospital.countAllRendezvouses();
            if (rendezvousCount >= maxRendezvousCount){
                mostActiveHospital = hospital;
                maxRendezvousCount  = rendezvousCount;
            }
        }

        InputStream is = Main.class.getResourceAsStream("/images/activated.png");
        Image activatedIcon = new Image(is);

        if (mostActiveHospital != null){
            activeHospital.setText(mostActiveHospital.getName() + ": " + maxRendezvousCount + " Appointments");
            activeIconHospital.setImage(activatedIcon);
        }

        Section mostActiveSection = null;
        maxRendezvousCount = 0;
        rendezvousCount = 0;
        for (Hospital hospital: hospitals.values()){
            for (Section section: hospital.getSections()){
                rendezvousCount = section.countAllRendezvouses();
                if (rendezvousCount >= maxRendezvousCount){
                    mostActiveSection = section;
                    maxRendezvousCount  = rendezvousCount;
                }
            }
        }

        if (mostActiveSection != null){
            activeSection.setText(mostActiveSection.getName() + ", ID: " + mostActiveSection.getId() + ": " + maxRendezvousCount + " Appointments");
            activeIconSection.setImage(activatedIcon);
        }

        Doctor mostActiveDoctor = null;
        maxRendezvousCount = 0;
        rendezvousCount = 0;
        for (Hospital hospital: hospitals.values()){
            for (Section section: hospital.getSections()){
                for (Doctor doctor: section.getDoctors()){
                    rendezvousCount = doctor.getSchedule().getRendezvousCount();
                    if (rendezvousCount >= maxRendezvousCount){
                        mostActiveDoctor = doctor;
                        maxRendezvousCount  = rendezvousCount;
                    }
                }
            }
        }

        if (mostActiveDoctor != null){
            activeDoctor.setText(mostActiveDoctor.getName() + ": " + maxRendezvousCount + " Appointments");
            activeIconDoctor.setImage(activatedIcon);
        }

    }

    public void setCurrentDate() {
        String date = DateManager.getCurrentDate().format(DateTimeFormatter.ofPattern("dd/MM/yyyy"));
        uiDate.setText(date);
    }

    public void initializePieChart(){
        Hospital hospital = hospitalBox.getValue();
        pieChart.getData().clear();
        ObservableList<PieChart.Data> pieChartData =
                FXCollections.observableArrayList(
                        new PieChart.Data("Appt", hospital.countAllRendezvouses()),
                        new PieChart.Data ("Sections", hospital.getSections().size()),
                        new PieChart.Data("Doctors", hospital.countAllDoctors()));
        pieChartData.forEach(data ->
                data.nameProperty().bind(
                        Bindings.concat(
                                data.getName(), ": ", data.pieValueProperty()
                        )
                )
        );
        pieChart.getData().addAll(pieChartData);
    }

    public void setPatientCount() {
        patientCount.setText(String.valueOf(crs.getPatientCount()));
    }

    public void setHospitalCount() {
        hospitalCount.setText(String.valueOf(crs.getHospitalCount()));
    }

    public void setSectionCount() {
        sectionCount.setText(String.valueOf(crs.getHospitalManager().countAllSections()));
    }

    public void setDoctorCount() {
        doctorCount.setText(String.valueOf(crs.getHospitalManager().countAllDoctors()));
    }

    public void setTotalRendezvousCount() {
        totalRendezvousCount.setText(String.valueOf(crs.getRendezvousCount()));
    }

    private synchronized void increaseMonthlyRendezvousCount(int index){
        monthlyRendezvouses[index]++;
    }

    public void setActiveRendezvousCount(){
        ArrayList<Rendezvous> rendezvouses = crs.getRendezvouses();
        int[] monthlyRendezvouses = new int[12];
        AtomicInteger count1 = new AtomicInteger();
        AtomicInteger count2 = new AtomicInteger();
        AtomicInteger count3 = new AtomicInteger();
        AtomicInteger count4 = new AtomicInteger();

        int size = rendezvouses.size();
        int quarter = size / 4;
        int half = quarter * 2;
        int threeQuarter = quarter + half;

        Runnable task1 = () ->
        {
            //Thread.currentThread().setName("firstQuarter");
            for (int i = 0; i < quarter; i++) {
                if (!(rendezvouses.get(i).isExpired())) {
                    count1.incrementAndGet();
                }
                if (rendezvouses.get(i).getDate().getYear() == DateManager.getCurrentDate().getYear()){
                    increaseMonthlyRendezvousCount(rendezvouses.get(i).getDate().getMonthValue() - 1);
                }
            }
        };

        Runnable task2 = () ->
        {
            //Thread.currentThread().setName("secondQuarter");
            for (int i = quarter; i < half; i++) {
                if (!(rendezvouses.get(i).isExpired())) {
                    count2.incrementAndGet();
                }
                if (rendezvouses.get(i).getDate().getYear() == DateManager.getCurrentDate().getYear()){
                    increaseMonthlyRendezvousCount(rendezvouses.get(i).getDate().getMonthValue() - 1);
                }
            }
        };

        Runnable task3 = () ->
        {
            //Thread.currentThread().setName("thirdQuarter");
            for (int i = half; i < threeQuarter; i++) {
                if (!(rendezvouses.get(i).isExpired())) {
                    count3.incrementAndGet();
                }
                if (rendezvouses.get(i).getDate().getYear() == DateManager.getCurrentDate().getYear()){
                    increaseMonthlyRendezvousCount(rendezvouses.get(i).getDate().getMonthValue() - 1);
                }
            }
        };

        Runnable task4 = () ->
        {
            //Thread.currentThread().setName("forthQuarter");
            for (int i = threeQuarter; i < size; i++) {
                if (!(rendezvouses.get(i).isExpired())) {
                    count4.incrementAndGet();
                }
                if (rendezvouses.get(i).getDate().getYear() == DateManager.getCurrentDate().getYear()){
                    increaseMonthlyRendezvousCount(rendezvouses.get(i).getDate().getMonthValue() - 1);
                }
            }
        };

        Thread thread1 = new Thread(task1);
        Thread thread2 = new Thread(task2);
        Thread thread3 = new Thread(task3);
        Thread thread4 = new Thread(task4);
        thread1.start();
        thread2.start();
        thread3.start();
        thread4.start();

        try {
            thread1.join();
            thread2.join();
            thread3.join();
            thread4.join();
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }

        count1.getAndAdd(count2.get());
        count1.getAndAdd(count3.get());
        count1.getAndAdd(count4.get());
        activeRendezvousCount.setText(String.valueOf(count1));
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
