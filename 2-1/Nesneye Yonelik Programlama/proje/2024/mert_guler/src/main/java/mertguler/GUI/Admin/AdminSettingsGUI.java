package mertguler.GUI.Admin;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.Spinner;
import javafx.scene.control.SpinnerValueFactory;
import javafx.scene.paint.Color;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import static mertguler.CRS.CRS.MAX_RENDEZVOUS_PER_PATIENT;
import static mertguler.CRS.CRS.RENDEZVOUS_DAY_LIMIT;
import static mertguler.GUI.Gui.crs;

public class AdminSettingsGUI implements Initializable {

    private SpinnerValueFactory<Integer> patientFactory = new SpinnerValueFactory.IntegerSpinnerValueFactory(5, 20, MAX_RENDEZVOUS_PER_PATIENT);

    private SpinnerValueFactory<Integer> dayLimitFactory = new SpinnerValueFactory.IntegerSpinnerValueFactory(15, 364, RENDEZVOUS_DAY_LIMIT);


    @FXML
    private Spinner<Integer> perPatientSpinner;

    @FXML
    private Spinner<Integer> dayLimitSpinner;

    @FXML
    private Label dataLabel;


    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        perPatientSpinner.setValueFactory(patientFactory);
        dayLimitSpinner.setValueFactory(dayLimitFactory);
    }

    public void saveToSystem(){
        MAX_RENDEZVOUS_PER_PATIENT = perPatientSpinner.getValue();
        RENDEZVOUS_DAY_LIMIT = dayLimitSpinner.getValue();
        dataLabel.setText("Settings are successfully saved to System");
        dataLabel.setTextFill(Color.DARKGREEN);
    }

    public void loadDefaults(){
        MAX_RENDEZVOUS_PER_PATIENT = 5;
        RENDEZVOUS_DAY_LIMIT = 30;
        patientFactory.setValue(5);
        dayLimitFactory.setValue(30);
        dataLabel.setText("Settings are successfully changed to defaults");
        dataLabel.setTextFill(Color.DARKGREEN);
    }

    public void saveToFile(){
        try {
            MAX_RENDEZVOUS_PER_PATIENT = perPatientSpinner.getValue();
            RENDEZVOUS_DAY_LIMIT = dayLimitSpinner.getValue();
            crs.saveSettings();
            dataLabel.setText("Settings are successfully saved");
            dataLabel.setTextFill(Color.DARKGREEN);
        } catch (IOException e){
            MAX_RENDEZVOUS_PER_PATIENT = 5;
            RENDEZVOUS_DAY_LIMIT = 30;
            dataLabel.setText(e.getMessage());
            dataLabel.setTextFill(Color.RED);
        }
    }

    public void loadFromFile(){
        try {
            crs.loadSettings();
            dataLabel.setText("Settings are successfully loaded");
            dataLabel.setTextFill(Color.DARKGREEN);
            patientFactory.setValue(MAX_RENDEZVOUS_PER_PATIENT);
            dayLimitFactory.setValue(RENDEZVOUS_DAY_LIMIT);
        } catch (IOException e){
            dataLabel.setText(e.getMessage());
            dataLabel.setTextFill(Color.RED);
        } catch (ArrayIndexOutOfBoundsException e) {
            dataLabel.setText(e.getMessage());
            dataLabel.setTextFill(Color.RED);
        }
    }
}
