package mertguler.GUI.Universal.Lists;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleLongProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.input.Clipboard;
import javafx.scene.input.ClipboardContent;
import javafx.scene.input.KeyCode;
import mertguler.GUI.Gui;
import mertguler.Person.Patient;

import java.net.URL;
import java.util.HashMap;
import java.util.ResourceBundle;

import static mertguler.GUI.Gui.crs;

public class PatientListGUI implements Initializable {

    @FXML
    public TreeTableView<Object> patientsTable;

    @FXML
    public TreeTableColumn<Object, String> nameColumn;
    @FXML
    public TreeTableColumn<Object, String> ageColumn;

    @FXML
    public TreeTableColumn<Object, Number> rendezvousColumn;

    @FXML
    public TreeTableColumn<Object, Number> idColumn;


    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        HashMap<Long, Patient> patients = crs.getPatients();
        TreeItem<Object> patientRoot = new TreeItem<>(new Patient("tempPatient",0, null));

        for (Patient patient: patients.values()){
            TreeItem<Object> tempPatient = new TreeItem<>(patient);
            patientRoot.getChildren().add(tempPatient);
        }

        nameColumn.setCellValueFactory(param -> {
            TreeItem<Object> cellData = param.getValue();
            if (cellData != null && cellData.getValue() instanceof Patient) {
                Patient patient = (Patient) cellData.getValue();
                return new SimpleStringProperty(patient.getName());
            } else {
                return null;
            }
        });

        idColumn.setCellValueFactory(param -> {
            TreeItem<Object> cellData = param.getValue();
            if (cellData != null && cellData.getValue() instanceof Patient) {
                Patient patient = (Patient) cellData.getValue();
                return new SimpleLongProperty(patient.getNational_id());
            } else {
                return null;
            }
        });

        ageColumn.setCellValueFactory(param -> {
            TreeItem<Object> cellData = param.getValue();
            if (cellData != null && cellData.getValue() instanceof Patient) {
                Patient patient = (Patient) cellData.getValue();
                int age = patient.getAge();
                if (age == 0){
                    return new SimpleStringProperty("0 or Unknown");
                } else {
                    return new SimpleStringProperty(String.valueOf(age));
                }
            } else {
                return null;
            }
        });

        rendezvousColumn.setCellValueFactory(param -> {
            TreeItem<Object> cellData = param.getValue();
            if (cellData != null && cellData.getValue() instanceof Patient) {
                Patient patient = (Patient) cellData.getValue();
                return new SimpleIntegerProperty(patient.getRendezvousCount());
            } else {
                return null;
            }
        });

        patientsTable.setRoot(patientRoot);
        patientsTable.setShowRoot(false);
        patientsTable.getSelectionModel().setCellSelectionEnabled(true);
        patientsTable.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);

        patientsTable.setOnKeyPressed(e -> {
            if (e.getCode() == KeyCode.C && e.isControlDown()) {
                StringBuilder clipboardString = new StringBuilder();

                ObservableList<TreeTablePosition<Object, ?>> positionList = patientsTable.getSelectionModel().getSelectedCells();

                int prevRow = -1;

                for (TreeTablePosition<Object, ?> position : positionList) {

                    int row = position.getRow();
                    int col = position.getColumn();


                    Object cell = (Object) patientsTable.getColumns().get(col).getCellData(row);

                    // null-check: provide empty string for nulls
                    if (cell == null) {
                        cell = "";
                    }

                    // determine whether we advance in a row (tab) or a column
                    // (newline).
                    if (prevRow == row) {

                        clipboardString.append('\t');

                    } else if (prevRow != -1) {

                        clipboardString.append('\n');

                    }

                    // create string from cell
                    String text = cell.toString();

                    // add new item to clipboard
                    clipboardString.append(text);

                    // remember previous
                    prevRow = row;
                }

                // create clipboard content
                final ClipboardContent clipboardContent = new ClipboardContent();
                clipboardContent.putString(clipboardString.toString());

                // set clipboard content
                Clipboard.getSystemClipboard().setContent(clipboardContent);
            }

        });

    }

    @FXML
    public void copy(){
        Gui.copy(patientsTable);
    }
}
