package mertguler.GUI.Admin.Section;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;
import javafx.stage.Stage;
import mertguler.Exceptions.IDException;
import mertguler.Hospital.Hospital;
import mertguler.Hospital.Section;

import java.net.URL;
import java.util.ResourceBundle;

import static mertguler.GUI.Gui.*;

public class DeleteSectionGUI implements Initializable {
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

        try {
            hospital.deleteSection(section.getId());
            showSuccess("Section: " + section.getName() + ", ID: " + section.getId() + "\nis successfully deleted!");
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
        sectionBox.getScene().getWindow().hide();
    }
}
