package mertguler.GUI.Doctor;

import javafx.application.Application;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.XYChart;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.text.Text;
import javafx.stage.Modality;
import mertguler.CRS.DateManager;
import mertguler.Hospital.Rendezvous;
import mertguler.Main;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.TemporalField;
import java.time.temporal.WeekFields;
import java.util.ArrayList;
import java.util.ResourceBundle;
import java.util.concurrent.atomic.AtomicInteger;

import static mertguler.GUI.Doctor.SelectDoctorGUI.doctorOfMenu;
import static mertguler.GUI.Gui.*;

public class DoctorModeGUI implements Initializable {
    private int[] weeklyRendezvouses = new int[6];
    public static LocalDate searchDate;

    @FXML
    private Button themeChanger;

    @FXML
    private ImageView themeIcon;

    @FXML
    private ImageView loadIcon;

    @FXML
    private Text welcomeText;

    @FXML
    private Label uiDate;

    @FXML
    private Label totalRendezvousCount;

    @FXML
    private Label activeRendezvousCount;

    @FXML
    private LineChart<String, Number> patientVisitsChart;

    @FXML
    private Label currentMonth;

    @FXML
    private DatePicker datePicker;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        setCurrentDate();
        welcomeText.setText(doctorOfMenu.getName() + ", Welcome to Hospital Rendezvous System!");
        setTotalRendezvousCount();
        setActiveRendezvousCount();
        XYChart.Series series = new XYChart.Series();
        series.setName("Total Appointment Count");
        series.getData().add(new XYChart.Data("Week 1", weeklyRendezvouses[0]));
        series.getData().add(new XYChart.Data("Week 2", weeklyRendezvouses[1]));
        series.getData().add(new XYChart.Data("Week 3", weeklyRendezvouses[2]));
        series.getData().add(new XYChart.Data("Week 4", weeklyRendezvouses[3]));
        series.getData().add(new XYChart.Data("Week 5", weeklyRendezvouses[4]));
        patientVisitsChart.getData().add(series);
        currentMonth.setText(String.valueOf(DateManager.getCurrentDate().getMonth().toString()));

        LocalDate minDate = LocalDate.now();
        LocalDate maxDate = DateManager.getLastDate();
        datePicker.setDayCellFactory(d ->
                new DateCell() {
                    @Override public void updateItem(LocalDate item, boolean empty) {
                        super.updateItem(item, empty);
                        setDisable(item.isAfter(maxDate) || item.isBefore(minDate));
                    }});
    }

    public void setCurrentDate() {
        String date = DateManager.getCurrentDate().format(DateTimeFormatter.ofPattern("dd/MM/yyyy"));
        uiDate.setText(date);
    }

    public void setTotalRendezvousCount() {
        totalRendezvousCount.setText(String.valueOf(doctorOfMenu.getSchedule().getRendezvousCount()));
    }

    private synchronized void increaseWeeklyRendezvousCount(int index){
        weeklyRendezvouses[index]++;
    }

    public void setActiveRendezvousCount(){
        TemporalField weekGetter = WeekFields.ISO.weekOfWeekBasedYear();

        ArrayList<Rendezvous> rendezvouses = doctorOfMenu.getSchedule().getSessions();
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
                Rendezvous rendezvous1 = rendezvouses.get(i);
                if (!(rendezvous1.isExpired())) {
                    count1.incrementAndGet();
                    int weekNumber = rendezvous1.getDate().get(weekGetter);
                        increaseWeeklyRendezvousCount(weekNumber - 1);
                }
            }
        };

        Runnable task2 = () ->
        {
            //Thread.currentThread().setName("secondQuarter");
            for (int i = quarter; i < half; i++) {
                Rendezvous rendezvous2 = rendezvouses.get(i);
                if (!(rendezvous2.isExpired())) {
                    count2.incrementAndGet();
                    int weekNumber = rendezvous2.getDate().get(weekGetter);
                    increaseWeeklyRendezvousCount(weekNumber - 1);
                }
            }
        };

        Runnable task3 = () ->
        {
            //Thread.currentThread().setName("thirdQuarter");
            for (int i = half; i < threeQuarter; i++) {
                Rendezvous rendezvous3 = rendezvouses.get(i);
                if (!(rendezvous3.isExpired())) {
                    count2.incrementAndGet();
                    int weekNumber = rendezvous3.getDate().get(weekGetter);
                    increaseWeeklyRendezvousCount(weekNumber - 1);
                }
            }
        };

        Runnable task4 = () ->
        {
            //Thread.currentThread().setName("forthQuarter");
            for (int i = threeQuarter; i < size; i++) {
                Rendezvous rendezvous4 = rendezvouses.get(i);
                if (!(rendezvous4.isExpired())) {
                    count2.incrementAndGet();
                    int weekNumber = rendezvous4.getDate().get(weekGetter);
                    increaseWeeklyRendezvousCount(weekNumber - 1);
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
    public void refreshDashboard() throws IOException {
        changeScene("doctor-dashboard.fxml");
    }

    @FXML
    public void goBack() throws IOException{
        changeScene("mode-select-menu.fxml");
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

    @FXML
    public void view() throws IOException{
        searchDate = datePicker.getValue();

        if (searchDate == null){
            showError("Please select a date");
        } else {
            showRendezvousesWithDateWindow();
        }
    }

    @FXML
    public void showRendezvousesWithDateWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/appointment.png");
        Image image = new Image(is);
        showWindow("doctor-rendezvouses-with-date.fxml", "My Appointments For Date: " + searchDate, Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showMyRendezvousesListWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/appointment.png");
        Image image = new Image(is);
        showWindow("doctors-rendezvous-list.fxml", "Appointment List", Modality.APPLICATION_MODAL, image);
    }

    @FXML
    public void showCheckRendezvousListWindow() throws IOException {
        InputStream is = Main.class.getResourceAsStream("/images/appointment.png");
        Image image = new Image(is);
        showWindow("doctor-select-patient.fxml", "Select Patient", Modality.APPLICATION_MODAL, image);
    }
}
