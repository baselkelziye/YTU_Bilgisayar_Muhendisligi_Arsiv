package savtproje.panels;

import javafx.geometry.Insets;
import javafx.scene.Parent;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Priority;
import javafx.scene.layout.Region;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import savtproje.MainApplication;
import savtproje.database.JsonDatabase;


import static savtproje.Utils.*;

public class InitialPanel {

    // references
    private final MainApplication mainApplication;
    private final JsonDatabase jsonDatabase;

    private final BorderPane root;


    public InitialPanel(MainApplication mainApplication) {
        this.mainApplication = mainApplication; // reference
        this.jsonDatabase = mainApplication.getTempDatabase();
        this.root = new BorderPane();

        Label labelBos = new Label("Bisiklet Otomasyon Sistemi - B.O.S.");
        labelBos.setFont(Font.font(30d));
        labelBos.setPadding(new Insets(50, 0, 50, 0));

        Button btnStudent = new Button("Ogrenci Girisi");
        Button btnAdmin = new Button("Yonetici Girisi");
        Button btnRegister = new Button("Kayit ol");
        for(Button b : new Button[]{ btnStudent, btnAdmin, btnRegister }) {
            b.setMinWidth(200);
            b.setMinHeight(50);
            b.setFont(Font.font(20d));
        }

        btnStudent.setOnMouseClicked(this::btnStudent);
        btnAdmin.setOnMouseClicked(this::btnAdmin);
        btnRegister.setOnMouseClicked(this::btnRegister);

        Region reg1 = new Region();
        VBox.setVgrow(reg1, Priority.ALWAYS);

        Region reg2 = new Region();
        VBox.setVgrow(reg2, Priority.ALWAYS);
        VBox vbox = new VBox(
            reg1, new BorderPane(labelBos), new BorderPane(btnStudent),
            new BorderPane(btnAdmin), new BorderPane(btnRegister), reg2
        );
        vbox.setSpacing(20d);
        vbox.setPadding(new Insets(-60d, 0d, 0d, 0d));

        root.setCenter(vbox);
    }


    private void btnRegister(MouseEvent event) {
        String[] result = askForRegistrationInfo();
        if(result == null) return;
        int id = strToInt(result[0]), age = strToInt(result[3]);
        String password = result[1], fullname = result[2];
        if(id == -1 || age == -1) return;

        boolean success = jsonDatabase.studentTable.registerNewStudent(id, fullname, password, age);
        giveFeedback(success, success ? "Kaydiniz yapilmistir." : "Bu ogrenci numarasi kullanimda bulunmaktadir");
    }


    private void btnAdmin(MouseEvent event) {
        String[] result = askForLoginInfo();
        if(result == null) return;
        int id = strToInt(result[0]);
        String password = result[1];
        if(password.isBlank() || id == -1) return;

        if(!jsonDatabase.adminTable.isValidIDAndPassword(id, password)) {
            giveFeedback(false, "Gecersiz numara veya sifre, lutfen tekrar deneyin.");
            return;
        }

        AdminPanel adminPanel = new AdminPanel(mainApplication, jsonDatabase, id);
        mainApplication.switchSceneTo(adminPanel.getRoot());
    }


    private void btnStudent(MouseEvent event) {
        String[] result = askForLoginInfo();
        if(result == null) return;
        int id = strToInt(result[0]);
        String password = result[1];
        if(password.isBlank() || id == -1) return;

        if(!jsonDatabase.studentTable.isValidIDAndPassword(id, password)) {
            giveFeedback(false, "Gecersiz numara veya sifre, lutfen tekrar deneyiniz.");
            return;
        }

        StudentPanel studentPanel = new StudentPanel(mainApplication, jsonDatabase, id);
        mainApplication.switchSceneTo(studentPanel.getRoot());
    }


    public Parent getRoot() { return this.root; }

}
