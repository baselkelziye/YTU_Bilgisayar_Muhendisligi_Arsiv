package mertguler.GUI.Admin.Section;

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

import java.net.URL;
import java.util.Optional;
import java.util.ResourceBundle;

import static mertguler.GUI.Gui.*;

public class RenameSectionGUI implements Initializable {
    private String name;
    private Hospital hospital;
    private Section section;

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
        sectionBox.setItems(FXCollections.observableArrayList(hospital.getSections()));
    }


    public void check() {
        section = sectionBox.getValue();

        if (hospital == null) {
            showError("Please select a hospital");
            return;
        }
        if (section == null) {
            showError("Please select a section");
            return;
        }

        showSuccess();

    }



    public void showSuccess() {
        Dialog dialog = new TextInputDialog();
        Stage stage = (Stage) dialog.getDialogPane().getScene().getWindow();
        stage.getIcons().add(app_image);
        dialog.setTitle("Rename");
        dialog.setHeaderText("Enter new name for Section: " + section.getName());
        dialog.setContentText("New name:");

        Optional<String> result = dialog.showAndWait();
        if (result.isPresent()){
            String newName = result.get();
            if (newName.isBlank()){
                showError("New name cant be empty!");
            } else {
                section.setName(newName);
                System.out.println("Section with ID: " + section.getId() + " is successfully renamed to: " + newName);
                Alert successAlert = new Alert(Alert.AlertType.INFORMATION);
                successAlert.setTitle("Success");
                successAlert.setHeaderText(null);
                successAlert.setContentText("Section with ID: " + section.getId() + " is successfully renamed!\n" +
                        "New name: " + newName);
                Stage stage2 = (Stage) successAlert.getDialogPane().getScene().getWindow();
                stage2.getIcons().add(app_image);
                successAlert.show();
            }
        }
    }
}
