package mertguler.GUI.MainMenu;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;

import java.io.IOException;

import static mertguler.GUI.Gui.changeScene;

public class ModeSelectGUI {

    @FXML
    public void switchAdminMenu(ActionEvent event) throws IOException {
        changeScene("admin-start-menu.fxml");
    }

    @FXML
    public void switchReceptionistMenu(ActionEvent event) throws IOException {
        changeScene("receptionist.fxml");
    }

    @FXML
    public void switchDoctorMenu(ActionEvent event) throws IOException {
        changeScene("select-doctor.fxml");
    }

    @FXML
    public void goBack(ActionEvent event) throws IOException {
        changeScene("data-load-menu.fxml");
    }


}
