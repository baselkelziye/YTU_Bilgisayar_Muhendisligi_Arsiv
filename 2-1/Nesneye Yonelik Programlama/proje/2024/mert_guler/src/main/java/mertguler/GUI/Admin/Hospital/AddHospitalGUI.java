package mertguler.GUI.Admin.Hospital;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.stage.Stage;
import mertguler.Enums.City;
import mertguler.Exceptions.DuplicateInfoException;

import java.net.URL;
import java.util.Optional;
import java.util.ResourceBundle;

import static mertguler.GUI.Gui.*;


public class AddHospitalGUI implements Initializable {
    private String name;
    private City city;

    @FXML
    private TextField nameField;

    @FXML
    private ComboBox<City> cityBox;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        cityBox.setItems(FXCollections.observableArrayList(City.values()));
    }

    public void check() {
        name = nameField.getText();

        if (name.isBlank()) {
            showError("Name cant be empty");
            return;
        }

        try{
            city = City.valueOf(String.valueOf(cityBox.getValue()).toUpperCase());
        } catch (IllegalArgumentException e){
            showError("Please enter a valid city name");
            return;
        }

        try {
            crs.getHospitalManager().checkHospitalDuplication(name, city);
            System.out.println("Hospital Name: " + name + ", " + city + " is available");
            showSuccess();
        } catch (DuplicateInfoException e) {
            System.out.println(e.getMessage());
            showError(e.getMessage());
        }

    }

    public void showSuccess() {
        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        Stage stage = (Stage) alert.getDialogPane().getScene().getWindow();
        stage.getIcons().add(app_image);
        alert.setTitle("Confirmation");
        alert.setHeaderText("Name: " + name
                + "\nCity: " + city);
        alert.setContentText("Hospital is available to add. Please confirm the data.");
        ButtonType confirmButton = new ButtonType("Confirm", ButtonBar.ButtonData.OK_DONE);
        ButtonType cancelButton = new ButtonType("Cancel", ButtonBar.ButtonData.CANCEL_CLOSE);
        alert.getButtonTypes().setAll(confirmButton, cancelButton);

        Optional<ButtonType> result = alert.showAndWait();
        if (result.get() == confirmButton) {
            crs.getHospitalManager().createHospital(name, city);
            System.out.println("Hospital: " + name + ", " + city + " is created");
            Alert successAlert = new Alert(Alert.AlertType.INFORMATION);
            successAlert.setTitle("Success");
            successAlert.setHeaderText(null);
            successAlert.setContentText("Hospital is successfully created!\nHospital Name: " + name + ", City: " + city);
            Stage stage2 = (Stage) successAlert.getDialogPane().getScene().getWindow();
            stage2.getIcons().add(app_image);
            successAlert.show();
        }
    }

}
