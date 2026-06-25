package mertguler.GUI.Universal.Rendezvous;

import javafx.beans.property.SimpleStringProperty;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.input.Clipboard;
import javafx.scene.input.ClipboardContent;
import javafx.scene.input.KeyCode;
import mertguler.GUI.Gui;
import mertguler.Hospital.Rendezvous;
import mertguler.Person.Patient;

import java.net.URL;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.ResourceBundle;

import static mertguler.GUI.Universal.Rendezvous.CheckRendezvousGUI.patientForPatientRendezvousList;

public class PatientRendezvousListGUI implements Initializable {
    @FXML
    public TreeTableView<Object> rendezvousesTable;

    @FXML
    public TreeTableColumn<Object, String> doctorNameColumn;

    @FXML
    public TreeTableColumn<Object, String> sectionNameColumn;

    @FXML
    public TreeTableColumn<Object, String> hospitalNameColumn;

    @FXML
    public TreeTableColumn<Object, String> dateColumn;

    @FXML
    public Label windowLabel;



    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        windowLabel.setText(patientForPatientRendezvousList.getName() + "'s Appointments");
        ArrayList<Rendezvous> rendezvouses = patientForPatientRendezvousList.getRendezvouses();

        TreeItem<Object> rendezvousRoot = new TreeItem<>(new Patient("tempRendezvous",-1, null));

        for (Rendezvous rendezvous: rendezvouses){
            TreeItem<Object> tempRendezvous = new TreeItem<>(rendezvous);
            rendezvousRoot.getChildren().add(tempRendezvous);
        }


        doctorNameColumn.setCellValueFactory(param -> {
            TreeItem<Object> cellData = param.getValue();
            if (cellData != null && cellData.getValue() instanceof Rendezvous) {
                Rendezvous rendezvous = (Rendezvous) cellData.getValue();
                return new SimpleStringProperty(rendezvous.getDoctor().getName());
            } else {
                return null;
            }
        });

        sectionNameColumn.setCellValueFactory(param -> {
            TreeItem<Object> cellData = param.getValue();
            if (cellData != null && cellData.getValue() instanceof Rendezvous) {
                Rendezvous rendezvous = (Rendezvous) cellData.getValue();
                return new SimpleStringProperty(rendezvous.getSection().getName());
            } else {
                return null;
            }
        });

        hospitalNameColumn.setCellValueFactory(param -> {
            TreeItem<Object> cellData = param.getValue();
            if (cellData != null && cellData.getValue() instanceof Rendezvous) {
                Rendezvous rendezvous = (Rendezvous) cellData.getValue();
                return new SimpleStringProperty(rendezvous.getHospital().getName());
            } else {
                return null;
            }
        });
        dateColumn.setCellValueFactory(param -> {
            TreeItem<Object> cellData = param.getValue();
            if (cellData != null && cellData.getValue() instanceof Rendezvous) {
                Rendezvous rendezvous = (Rendezvous) cellData.getValue();
                return new SimpleStringProperty(rendezvous.getDate().format(DateTimeFormatter.ofPattern("dd/MM/yyyy")));
            } else {
                return null;
            }
        });

        rendezvousesTable.setRoot(rendezvousRoot);
        rendezvousesTable.setShowRoot(false);
        rendezvousesTable.getSelectionModel().setCellSelectionEnabled(true);
        rendezvousesTable.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);

        rendezvousesTable.setOnKeyPressed(e -> {
            if (e.getCode() == KeyCode.C && e.isControlDown()) {
                StringBuilder clipboardString = new StringBuilder();

                ObservableList<TreeTablePosition<Object, ?>> positionList = rendezvousesTable.getSelectionModel().getSelectedCells();

                int prevRow = -1;

                for (TreeTablePosition<Object, ?> position : positionList) {

                    int row = position.getRow();
                    int col = position.getColumn();


                    Object cell = (Object) rendezvousesTable.getColumns().get(col).getCellData(row);

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
        Gui.copy(rendezvousesTable);
    }
}
