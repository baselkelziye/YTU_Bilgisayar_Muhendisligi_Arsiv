package mertguler.GUI;

import javafx.application.Application;
import javafx.collections.ObservableList;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Rectangle2D;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.TreeTablePosition;
import javafx.scene.control.TreeTableView;
import javafx.scene.image.Image;
import javafx.scene.input.Clipboard;
import javafx.scene.input.ClipboardContent;
import javafx.stage.Modality;
import javafx.stage.Screen;
import javafx.stage.Stage;
import mertguler.CRS.CRS;
import mertguler.Main;

import java.io.IOException;
import java.io.InputStream;
import java.util.Objects;


public class Gui extends Application {
    public static CRS crs;
    private static Stage primaryStage;
    public static InputStream app_icon = Main.class.getResourceAsStream("/images/app_icon.png");
    public static Image app_image = new Image(app_icon);

    @Override
    public void start(Stage stage) throws IOException {
        crs = new CRS();
        primaryStage = stage;
        // Can it improve text quality??
        System.setProperty("prism.lcdtext", "false");
        Application.setUserAgentStylesheet(Main.class.getResource("mac-light.css").toExternalForm());
        Parent root = FXMLLoader.load(Main.class.getResource("login-menu.fxml"));

        stage.setTitle("Hospital Rendezvous System");

        InputStream is = Main.class.getResourceAsStream("/images/app_icon.png");
        Image image = new Image(is);
        stage.getIcons().add(image);

        Rectangle2D screenBounds = Screen.getPrimary().getBounds();

        double x = 1280;
        double y = 720;

        if (screenBounds.getMaxX() < 1280 || screenBounds.getMaxY() < 720){
            x = screenBounds.getMaxX() * 0.8;
            y = screenBounds.getMaxY() * 0.8;
        }

        Scene scene =  new Scene(root, x, y);

        stage.setScene(scene);
        stage.show();
    }

    public static void showError(String text) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        Stage stage = (Stage) alert.getDialogPane().getScene().getWindow();
        stage.getIcons().add(app_image);
        alert.setTitle("Error");
        alert.setHeaderText(null);
        alert.setContentText(text);
        alert.show();
    }


    public static void changeScene(String fxml) throws IOException {
        Parent pane = FXMLLoader.load(Objects.requireNonNull(Main.class.getResource(fxml)));
        primaryStage.getScene().setRoot(pane);
    }

    public static void showWindow(String fxml, String title, Modality modality, Image image) throws IOException{
        Parent root = FXMLLoader.load(Objects.requireNonNull(Main.class.getResource(fxml)));
        Stage stage = new Stage();
        stage.setTitle(title);
        Scene scene =  new Scene(root);
        if (image != null){
            stage.getIcons().add(image);
        }
        stage.setScene(scene);
        stage.initModality(modality);
        stage.show();
    }

    public static void copy(TreeTableView<Object> table){
        StringBuilder clipboardString = new StringBuilder();

        ObservableList<TreeTablePosition<Object, ?>> positionList = table.getSelectionModel().getSelectedCells();

        int prevRow = -1;

        for (TreeTablePosition<Object, ?> position : positionList) {

            int row = position.getRow();
            int col = position.getColumn();


            Object cell = (Object) table.getColumns().get(col).getCellData(row);

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

    public static void main(String[] args) {
        launch();
    }
}