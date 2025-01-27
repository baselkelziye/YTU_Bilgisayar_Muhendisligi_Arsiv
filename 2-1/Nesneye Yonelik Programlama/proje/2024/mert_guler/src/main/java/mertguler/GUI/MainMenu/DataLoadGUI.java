package mertguler.GUI.MainMenu;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.paint.Color;
import mertguler.CRS.CRS;

import java.io.IOException;

import static mertguler.CRS.CRS.dataPath;
import static mertguler.GUI.Gui.changeScene;
import static mertguler.GUI.Gui.crs;

public class DataLoadGUI {

    @FXML
    private Label label;

    public void loadData() throws IOException {
        if (crs.loadTablesFromDisk()) {
            label.setText("Successfully loaded data from file: `" + dataPath + "`");
            label.setTextFill(Color.GREEN);
            switchModeSelectMenu();
        } else {
            label.setText("Failed to load data from file: `" + dataPath + "`");
            label.setTextFill(Color.RED);
        }
    }

    public void switchDataLoadMenu() throws IOException {
        changeScene("data-load-menu.fxml");
    }

    public void switchModeSelectMenu() throws IOException {
        changeScene("mode-select-menu.fxml");
    }

    public void freshStart() throws IOException{
        crs = new CRS();
        switchModeSelectMenu();
    }

}
