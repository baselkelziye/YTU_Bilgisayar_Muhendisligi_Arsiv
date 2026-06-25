package mertguler.GUI.Doctor.PatientWork;

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

import static mertguler.GUI.Doctor.PatientWork.SelectPatientGUI.checkedDoctorsPatient;
import static mertguler.GUI.Doctor.SelectDoctorGUI.doctorOfMenu;

public class RendezvousesWithPatientGUI implements Initializable {

    @FXML
    public TreeTableView<Object> rendezvousesTable;

    @FXML
    public Label label;

    @FXML
    public TreeTableColumn<Object, String> dateColumn;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        label.setText(checkedDoctorsPatient.getName() + "'s Appointments");
        ArrayList<Rendezvous> checkedRendezvousList = checkedDoctorsPatient.getRendezvouses();
        ArrayList<Rendezvous> rendezvouses = new ArrayList<>();

        for (Rendezvous rendezvous: checkedRendezvousList){
            if (rendezvous.getDoctor() == doctorOfMenu){
                rendezvouses.add(rendezvous);
            }
        }


        TreeItem<Object> rendezvousRoot = new TreeItem<>(new Patient("tempRendezvous",-1, null));

        for (Rendezvous rendezvous: rendezvouses) {
            TreeItem<Object> tempRendezvous = new TreeItem<>(rendezvous);
            rendezvousRoot.getChildren().add(tempRendezvous);
        }

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
