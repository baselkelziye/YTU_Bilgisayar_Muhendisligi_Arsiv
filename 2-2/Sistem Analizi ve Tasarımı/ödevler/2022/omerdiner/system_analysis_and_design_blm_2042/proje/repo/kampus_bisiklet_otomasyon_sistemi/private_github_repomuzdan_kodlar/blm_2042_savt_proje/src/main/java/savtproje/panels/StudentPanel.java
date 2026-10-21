package savtproje.panels;

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

public class StudentPanel {

    private final MainApplication mainApplication;
    private final JsonDatabase jsonDatabase;
    private final int studentID;

    private final Label lbBalance;
    private final BorderPane root;

    public StudentPanel(MainApplication mainApplication, JsonDatabase jsonDatabase, int studentID) {
        this.mainApplication = mainApplication;
        this.jsonDatabase = jsonDatabase;
        this.studentID = studentID;

        this.root = new BorderPane();

        Label lbName = new Label("B.O.S. Sistemine hosgeldin, " + jsonDatabase.studentTable.getFullnameOf(studentID));
        lbName.setFont(Font.font(25d));
        lbBalance = new Label("Guncel Bakiye: " + jsonDatabase.studentTable.getBalanceOf(studentID));
        lbName.setFont(Font.font(22d));

        Button btnBalance = new Button("Bakiye Yukle");
        Button btnRentBicycle = new Button("Kiralama Islemleri");
        Button btnRentHistory = new Button("Kiralama Gecmisi");
        Button btnSignOut = new Button("Cikis Yap");
        for(Button b : new Button[]{ btnBalance, btnRentBicycle, btnRentHistory, btnSignOut }) {
            b.setMinWidth(200);
            b.setMinHeight(50);
            b.setFont(Font.font(20d));
        }

        Region reg1 = new Region();
        VBox.setVgrow(reg1, Priority.ALWAYS);
        Region reg2 = new Region();
        VBox.setVgrow(reg2, Priority.ALWAYS);

        VBox vbox = new VBox(
                reg1, new BorderPane(lbName), new BorderPane(lbBalance), new BorderPane(btnBalance),
                new BorderPane(btnRentBicycle), new BorderPane(btnRentHistory), new BorderPane(btnSignOut), reg2
        );
        vbox.setSpacing(20d);
        root.setCenter(vbox);

        // ----------------- events ----------------- //

        btnRentBicycle.setOnMouseClicked(e -> {
            BicyclePanel bicyclePanel = new BicyclePanel(mainApplication, jsonDatabase, true, studentID);
            mainApplication.switchSceneTo(bicyclePanel.getRoot());
        });

        btnBalance.setOnMouseClicked(e -> {
            Integer balanceIncrementInteger = askForBalance();
            if(balanceIncrementInteger == null) return;
            int balanceIncrement = balanceIncrementInteger;
            if(balanceIncrement <= 0) return;

            int newBalance = jsonDatabase.studentTable.addBalanceTo(studentID, balanceIncrement);
            giveFeedback(true, "Bakiyeniz guncellenmistir, yeni bakiyeniz: " + newBalance);
            lbBalance.setText("Guncel Bakiye: " + newBalance);
        });

        btnRentHistory.setOnMouseClicked(e -> {
            String history = jsonDatabase.getRentHistoryStringOf(studentID);
            if(history.length() <= 0) {
                giveFeedback(true, "Herhangi bir kiralama gecmisi bulunmamaktadir.");
                return;
            }
            giveFeedback(true, history, 15);
        });

        btnSignOut.setOnMouseClicked(e -> {
            Parent newRoot = new InitialPanel(mainApplication).getRoot();
            mainApplication.switchSceneTo(newRoot);
        });

    }


    public Parent getRoot() {
        return root;
    }

}
