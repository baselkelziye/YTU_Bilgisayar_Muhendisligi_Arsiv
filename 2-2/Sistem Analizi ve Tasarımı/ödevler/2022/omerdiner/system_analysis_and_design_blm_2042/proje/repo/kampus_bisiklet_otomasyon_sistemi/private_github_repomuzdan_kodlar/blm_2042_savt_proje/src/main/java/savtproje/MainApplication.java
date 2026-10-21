package savtproje;

import javafx.application.*;
import javafx.stage.*;
import javafx.scene.*;
import savtproje.panels.*;
import savtproje.database.JsonDatabase;


public class MainApplication extends Application {

    private final JsonDatabase jsonDatabase = new JsonDatabase();
    private Scene scene;


    @Override
    public void start(Stage stage) {
        stage.setWidth(1000);
        stage.setHeight(600);

        InitialPanel initialPanel = new InitialPanel(this);
        this.scene = new Scene(initialPanel.getRoot());
        stage.setScene(scene);

        stage.show();
    }


    public void switchSceneTo(Parent parent) {
        this.scene.setRoot(parent);
    }


    @Override
    public void stop() {
        Platform.exit();
        System.exit(0);
    }

    public JsonDatabase getTempDatabase() {
        return jsonDatabase;
    }
}
