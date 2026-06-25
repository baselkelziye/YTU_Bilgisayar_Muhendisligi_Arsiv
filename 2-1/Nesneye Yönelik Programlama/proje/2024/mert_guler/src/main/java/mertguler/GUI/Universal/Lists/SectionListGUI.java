package mertguler.GUI.Universal.Lists;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.input.Clipboard;
import javafx.scene.input.ClipboardContent;
import javafx.scene.input.KeyCode;
import mertguler.Enums.City;
import mertguler.GUI.Gui;
import mertguler.Hospital.Hospital;
import mertguler.Hospital.Section;

import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.ResourceBundle;

import static mertguler.GUI.Gui.crs;

public class SectionListGUI implements Initializable {

    @FXML
    public TreeTableView<Object> sectionsTable;

    @FXML
    public TreeTableColumn<Object, String> nameColumn;

    @FXML
    public TreeTableColumn<Object, Number> idColumn;

    @FXML
    public TreeTableColumn<Object, String> childColumn;


    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        HashMap<Integer, Hospital> hospitals = crs.getHospitals();
        TreeItem<Object> hospitalRoot = new TreeItem<>(new Hospital("Temp Hospital", 0, City.ISTANBUL));

        for (Hospital hospital: hospitals.values()){
            ArrayList<Section> sections = hospital.getSections();
            TreeItem<Object> tempHospital = new TreeItem<>(hospital);
            for (Section section: sections){
                tempHospital.getChildren().add((new TreeItem<>(section)));
            }
            hospitalRoot.getChildren().add(tempHospital);
        }

        nameColumn.setCellValueFactory(param -> {
            TreeItem<Object> cellData = param.getValue();
            if (cellData != null) {
                if (cellData.getValue() instanceof Hospital) {
                    Hospital hospital = (Hospital) cellData.getValue();
                    return new SimpleStringProperty(hospital.getName());
                } else if (cellData.getValue() instanceof Section) {
                    Section section = (Section) cellData.getValue();
                    return new SimpleStringProperty(section.getName());
                }
            }
            return null;
        });

        idColumn.setCellValueFactory(param -> {
            TreeItem<Object> cellData = param.getValue();
            if (cellData != null) {
                if (cellData.getValue() instanceof Hospital) {
                    Hospital hospital = (Hospital) cellData.getValue();
                    return new SimpleIntegerProperty(hospital.getId());
                } else if (cellData.getValue() instanceof Section) {
                    Section section = (Section) cellData.getValue();
                    return new SimpleIntegerProperty(section.getId());
                }
            }
            return null;
        });

        childColumn.setCellValueFactory(param -> {
            TreeItem<Object> cellData = param.getValue();
            if (cellData != null) {
                if (cellData.getValue() instanceof Hospital) {
                    Hospital hospital = (Hospital) cellData.getValue();
                    return new SimpleStringProperty("");
                } else if (cellData.getValue() instanceof Section) {
                    Section section = (Section) cellData.getValue();
                    return new SimpleStringProperty(String.valueOf(section.isChildSection()));
                }
            }
            return null;
        });

        sectionsTable.setRoot(hospitalRoot);
        sectionsTable.setShowRoot(false);
        sectionsTable.getSelectionModel().setCellSelectionEnabled(true);
        sectionsTable.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);

        sectionsTable.setOnKeyPressed(e -> {
            if (e.getCode() == KeyCode.C && e.isControlDown()) {
                StringBuilder clipboardString = new StringBuilder();

                ObservableList<TreeTablePosition<Object, ?>> positionList = sectionsTable.getSelectionModel().getSelectedCells();

                int prevRow = -1;

                for (TreeTablePosition<Object, ?> position : positionList) {

                    int row = position.getRow();
                    int col = position.getColumn();


                    Object cell = (Object) sectionsTable.getColumns().get(col).getCellData(row);

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
        Gui.copy(sectionsTable);
    }
}
