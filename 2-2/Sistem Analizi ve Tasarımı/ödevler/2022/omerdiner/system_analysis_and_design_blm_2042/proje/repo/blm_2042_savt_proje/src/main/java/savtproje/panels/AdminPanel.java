package savtproje.panels;

import javafx.scene.Parent;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.*;
import javafx.scene.text.Font;
import savtproje.MainApplication;
import savtproje.database.JsonDatabase;
import savtproje.database.entities.Review;
import savtproje.database.entities.Student;

import java.text.SimpleDateFormat;
import java.util.LinkedList;

import static savtproje.Utils.*;

public class AdminPanel {

    private final MainApplication mainApplication;
    private final JsonDatabase jsonDatabase;
    private final int adminID;

    private final BorderPane root;

    public AdminPanel(MainApplication mainApplication, JsonDatabase jsonDatabase, int adminID) {
        this.mainApplication = mainApplication;
        this.jsonDatabase = jsonDatabase;
        this.adminID = adminID;

        this.root = new BorderPane();

        Label lbName = new Label("B.O.S. Sistemi yonetici girisi: " + jsonDatabase.adminTable.getFullnameOf(adminID));
        lbName.setFont(Font.font(25d));

        Button btnListStudents = new Button("Ogrenci Listesi");
        Button btnListBicycles = new Button("Bisiklet Listesi");
        Button btnSignOut = new Button("Cikis Yap");
        for(Button b : new Button[]{ btnListStudents, btnListBicycles, btnSignOut }) {
            b.setMinWidth(200);
            b.setMinHeight(50);
            b.setFont(Font.font(20d));
        }

        btnListStudents.setOnMouseClicked(this::btnListStudents);
        btnListBicycles.setOnMouseClicked(e -> {
            BicyclePanel bicyclePanel = new BicyclePanel(mainApplication, jsonDatabase, false, adminID);
            mainApplication.switchSceneTo(bicyclePanel.getRoot());
        });
        btnSignOut.setOnMouseClicked(e -> {
            Parent newRoot = new InitialPanel(mainApplication).getRoot();
            mainApplication.switchSceneTo(newRoot);
        });

        Region reg1 = new Region();
        VBox.setVgrow(reg1, Priority.ALWAYS);
        Region reg2 = new Region();
        VBox.setVgrow(reg2, Priority.ALWAYS);

        VBox vbox = new VBox(
                reg1, new BorderPane(lbName), new BorderPane(btnListStudents),
                new BorderPane(btnListBicycles), new BorderPane(btnSignOut), reg2
        );
        vbox.setSpacing(20d);
        root.setCenter(vbox);
    }


    private void btnListStudents(MouseEvent event) {
        VBox scrollPaneContent = new VBox(reg());
        scrollPaneContent.setSpacing(20d);

        Label hFullname = new Label("AD SOYAD");
        Label hID = new Label("ID");
        Label hPassword = new Label("SIFRE");
        Label hAge = new Label("YAS");
        Label hDelStudent = new Label("ISLEMLER");
        hFullname.setMinWidth(150); hFullname.setMaxWidth(150); hFullname.setPrefWidth(150);
        hID.setMinWidth(75); hID.setMaxWidth(75); hID.setPrefWidth(75);
        hPassword.setMinWidth(75); hPassword.setMaxWidth(75); hPassword.setPrefWidth(75);
        hAge.setMinWidth(50); hAge.setMaxWidth(50); hAge.setPrefWidth(50);
        hDelStudent.setMinWidth(100); hDelStudent.setMaxWidth(100); hDelStudent.setPrefWidth(100);
        for(Label h : new Label[]{ hID, hFullname, hPassword, hDelStudent, hAge }) {
            h.setFont(Font.font(20));
            h.setMinHeight(50);
        }

        HBox h = new HBox();
        h.setSpacing(30d);
        h.getChildren().addAll(
                reg(), vsep(), hFullname, vsep(), hID, vsep(), hPassword,
                vsep(), hAge, vsep(), new VBox(reg(), hDelStudent, reg()), vsep(), reg()
        );
        scrollPaneContent.getChildren().add(h);

        // Add students in rows
        LinkedList<Student> students = jsonDatabase.studentTable.getAllRows();
        for(Student student : students) {
            HBox row = new HBox();
            row.setSpacing(30d);

            Label lbFullname = new Label(student.fullname);
            Label lbID = new Label(String.valueOf(student.ID));
            Label lbPassword = new Label(student.password);
            Label lbAge = new Label(String.valueOf(student.age));

            for(Label lb : new Label[]{ lbFullname, lbID, lbPassword, lbAge }) {
                lb.setMinHeight(200);
                lb.setFont(Font.font(15d));
            }
            lbFullname.setMinWidth(150); lbFullname.setMaxWidth(150); lbFullname.setPrefWidth(150);
            lbID.setMinWidth(75); lbID.setMaxWidth(75); lbID.setPrefWidth(75);
            lbPassword.setMinWidth(75); lbPassword.setMaxWidth(75); lbPassword.setPrefWidth(75);
            lbAge.setMinWidth(50); lbAge.setMaxWidth(50); lbAge.setPrefWidth(50);

            Button btnDelStudent = new Button("Uyeyi Sil");
            Button btnRentHistory = new Button("Kiralamalar");
            Button btnReviewHistory = new Button("Yorumlar");
            VBox ops = new VBox(reg(), btnDelStudent, hsep(), btnReviewHistory, hsep(), btnRentHistory, reg());
            ops.setSpacing(3d);

            for(Button b : new Button[]{ btnDelStudent, btnReviewHistory, btnRentHistory }) {
                b.setMinWidth(100);
                b.setMaxWidth(100);
                b.setMinHeight(40);
                b.setMaxHeight(40);
                b.setFont(Font.font(15));
            }

            btnRentHistory.setOnMouseClicked(e -> {
                String content = jsonDatabase.getRentHistoryStringOf(student.ID);
                if(content.isBlank()) content = "Kiralama gecmisi bulunmamaktadir";
                giveFeedback(true, content, 15);
            });
            btnReviewHistory.setOnMouseClicked(e -> {
                LinkedList<Review> reviews = jsonDatabase.reviewTable.getAllReviewsOfStudent(student.ID);
                reviews.sort((o1, o2) -> o1.date.compareTo(o2.date));

                StringBuilder sb = new StringBuilder();
                for(Review rw : reviews) {
                    sb.append(String.format(
                            "- [%s] Bisiklet: %d, Reytingler: bisiklet %d, surus %d, genel %d\n\n",
                            new SimpleDateFormat("dd:MM:yyyy HH:mm").format(rw.date),
                            rw.bicycleID, rw.bicycleRating, rw.drivingRating, rw.overallRating
                    ));
                }
                String content = sb.toString();
                if(content.isBlank()) content = "Yorum gecmisi bulunmamaktadir";

                giveFeedback(true, content, 15);
            });

            btnDelStudent.setOnMouseClicked(e -> {
                if(jsonDatabase.deleteStudent(student.ID)) {
                    scrollPaneContent.getChildren().remove(row);
                }
            });

            row.getChildren().addAll(
                reg(), vsep(), lbFullname, vsep(), lbID, vsep(), lbPassword,
                vsep(), lbAge, vsep(), ops, vsep(), reg()
            );
            scrollPaneContent.getChildren().add(row);
        }

        Button btnSignOut = new Button("Listeyi Kapat");
        btnSignOut.setMinWidth(200);
        btnSignOut.setMinHeight(50);
        btnSignOut.setFont(Font.font(15));
        btnSignOut.setOnMouseClicked(e -> mainApplication.switchSceneTo(this.root));


        VBox vbox = new VBox(
            reg(),
            new HBox(reg(), new ScrollPane(scrollPaneContent), reg()),
            new HBox(reg(), btnSignOut, reg()),
            reg()
        );
        vbox.setSpacing(20d);

        mainApplication.switchSceneTo(vbox);
    }


    public Parent getRoot() {
        return root;
    }

}
