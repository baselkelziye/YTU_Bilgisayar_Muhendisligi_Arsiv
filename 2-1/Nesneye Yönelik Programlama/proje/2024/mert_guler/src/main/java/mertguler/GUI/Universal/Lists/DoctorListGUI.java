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
import mertguler.Hospital.Hospital;
import mertguler.Hospital.Section;
import mertguler.Person.Doctor;

import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.ResourceBundle;

import static mertguler.GUI.Gui.crs;

public class DoctorListGUI implements Initializable {
    @FXML
    public TreeTableView<Object> doctorsTable;

    @FXML
    public TreeTableColumn<Object, String> nameColumn;

    @FXML
    public TreeTableColumn<Object, Number> rendezvousColumn;

    @FXML
    public TreeTableColumn<Object, Number> idColumn;


    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        TreeItem<Object> doctorRoot = new TreeItem<>(new Doctor("tempDoctor",0, 0));

        HashMap<Integer, Hospital> hospitals = crs.getHospitals();
        ArrayList<Doctor> doctors = new ArrayList<>();
        for (Hospital hospital: hospitals.values()){
            ArrayList<Section> sections = hospital.getSections();
            for (Section section: sections){
                for (Doctor doctor: section.getDoctors()){
                    TreeItem<Object> tempDoctor = new TreeItem<>(doctor);
                    doctorRoot.getChildren().add(tempDoctor);
                }
            }
        }
        
        //////////////////////////////////////////////////////////////////////////////

        nameColumn.setCellValueFactory(param -> {
            TreeItem<Object> cellData = param.getValue();
            if (cellData != null && cellData.getValue() instanceof Doctor) {
                Doctor doctor = (Doctor) cellData.getValue();
                return new SimpleStringProperty(doctor.getName());
            } else {
                return null;
            }
        });

        idColumn.setCellValueFactory(param -> {
            TreeItem<Object> cellData = param.getValue();
            if (cellData != null && cellData.getValue() instanceof Doctor) {
                Doctor doctor = (Doctor) cellData.getValue();
                return new SimpleLongProperty(doctor.getDiploma_id());
            } else {
                return null;
            }
        });


        rendezvousColumn.setCellValueFactory(param -> {
            TreeItem<Object> cellData = param.getValue();
            if (cellData != null && cellData.getValue() instanceof Doctor) {
                Doctor doctor = (Doctor) cellData.getValue();
                return new SimpleIntegerProperty(doctor.getSchedule().getRendezvousCount());
            } else {
                return null;
            }
        });

        doctorsTable.setRoot(doctorRoot);
        doctorsTable.setShowRoot(false);
        doctorsTable.getSelectionModel().setCellSelectionEnabled(true);
        doctorsTable.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);

        doctorsTable.setOnKeyPressed(e -> {
            if (e.getCode() == KeyCode.C && e.isControlDown()) {
                StringBuilder clipboardString = new StringBuilder();

                ObservableList<TreeTablePosition<Object, ?>> positionList = doctorsTable.getSelectionModel().getSelectedCells();

                int prevRow = -1;

                for (TreeTablePosition<Object, ?> position : positionList) {

                    int row = position.getRow();
                    int col = position.getColumn();


                    Object cell = (Object) doctorsTable.getColumns().get(col).getCellData(row);

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
        Gui.copy(doctorsTable);
    }
}
