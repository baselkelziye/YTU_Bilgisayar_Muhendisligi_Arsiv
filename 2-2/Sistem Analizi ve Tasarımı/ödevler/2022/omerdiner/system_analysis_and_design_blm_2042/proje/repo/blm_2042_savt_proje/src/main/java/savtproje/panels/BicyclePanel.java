package savtproje.panels;


import javafx.geometry.Pos;
import javafx.scene.Parent;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.Separator;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Region;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import savtproje.MainApplication;
import savtproje.database.JsonDatabase;
import savtproje.database.entities.Bicycle;
import savtproje.database.entities.Rent;
import savtproje.database.entities.Review;
import savtproje.database.entities.Student;

import javax.print.attribute.standard.JobHoldUntil;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Random;
import java.util.UUID;

import static savtproje.Utils.*;

public class BicyclePanel {

    private final MainApplication mainApplication;
    private final JsonDatabase jsonDatabase;
    private final int ID;
    private final boolean isStudent;

    VBox root;
    static int index = 0;

    public BicyclePanel(MainApplication mainApplication, JsonDatabase jsonDatabase, boolean isStudent, int ID) {
        this.mainApplication = mainApplication;
        this.jsonDatabase = jsonDatabase;
        this.ID = ID;
        this.isStudent = isStudent;

        refreshList();
    }

    private void refreshList() {
        VBox scrollPaneContent = new VBox(reg());
        final int BIG_WID = 100;
        final int SM_WID = 50;

        // Headers
        index = 0;
        {
            HBox row1 = new HBox();
            Label lbIndex = new Label("#"),
                    lbID = new Label("ID"),
                    lbBrand = new Label("MARKA"),
                    lbModel = new Label("MODEL"),
                    lbYear = new Label("YIL"),
                    lbCostPerMinute = new Label("TL/dk");
            for(Label lb : new Label[]{ lbIndex, lbYear, lbCostPerMinute }) {
                lb.setMinSize(SM_WID, 50);
                lb.setAlignment(Pos.CENTER);
                lb.setFont(Font.font(15));
            }
            for(Label lb : new Label[]{ lbID, lbBrand, lbModel }) {
                lb.setMinSize(BIG_WID, 50);
                lb.setAlignment(Pos.CENTER);
                lb.setFont(Font.font(15));
            }

            row1.setSpacing(30);
            row1.getChildren().addAll(reg(), lbIndex, lbID, lbBrand, lbModel, lbYear, lbCostPerMinute, reg());
            scrollPaneContent.getChildren().add(row1);
        }

        jsonDatabase.bicycleTable.getAllRows().forEach(bicycle -> {
            Separator rowHsep = hsep(20);
            HBox row1 = new HBox();

            Label lbIndex = new Label(String.valueOf(index++)),
                    lbID = new Label(String.valueOf(bicycle.ID)),
                    lbBrand = new Label(bicycle.brand),
                    lbModel = new Label(bicycle.model),
                    lbYear = new Label(String.valueOf(bicycle.year)),
                    lbCostPerMinute = new Label(String.valueOf(bicycle.costPerMinute));

            for(Label lb : new Label[]{ lbIndex, lbYear, lbCostPerMinute }) {
                lb.setMinSize(SM_WID, 50);
                lb.setAlignment(Pos.CENTER);
                lb.setFont(Font.font(15));
            }
            for(Label lb : new Label[]{ lbID, lbBrand, lbModel }) {
                lb.setMinSize(BIG_WID, 50);
                lb.setAlignment(Pos.CENTER);
                lb.setFont(Font.font(15));
            }

            row1.setSpacing(30);
            row1.getChildren().addAll(reg(), lbIndex, lbID, lbBrand, lbModel, lbYear, lbCostPerMinute, reg());
            scrollPaneContent.getChildren().addAll(row1);

            LinkedList<Review> previousReviews = jsonDatabase.reviewTable.getAllReviewsOfBicycle(bicycle.ID);
            previousReviews.sort(Comparator.comparing(o -> o.date));
            LinkedList<HBox> rowReviews = new LinkedList<>();
            for(Review review : previousReviews) {
                HBox rowReview = new HBox();
                rowReview.setSpacing(30);

                Label lbShift = new Label("=>");
                Label lbBicycleRating = new Label("Bisiklet: " + review.bicycleRating + "/10");
                Label lbDrivingRating = new Label("Surus: " + review.drivingRating + "/10");
                Label lbOverallRating = new Label("Genel: " + review.overallRating + "/10");
                for(Label lb : new Label[]{ lbShift, lbBicycleRating, lbDrivingRating, lbOverallRating }) {
                    lb.setMinSize(BIG_WID, 50);
                    lb.setAlignment(Pos.CENTER);
                    lb.setFont(Font.font(15));
                }
                lbShift.setMinSize(SM_WID, 50);

                rowReview.getChildren().addAll(reg(), lbShift, lbBicycleRating, lbDrivingRating, lbOverallRating);

                if(!isStudent) {
                    Button btnDeleteReview = new Button("SIL");
                    btnDeleteReview.setMinWidth(SM_WID);
                    btnDeleteReview.setAlignment(Pos.CENTER);
                    btnDeleteReview.setFont(Font.font(15));
                    btnDeleteReview.setOnMouseClicked(e -> {
                        jsonDatabase.reviewTable.deleteReview(review.ID);
                        scrollPaneContent.getChildren().removeAll(rowReview);
                    });
                    rowReview.getChildren().addAll(new VBox(reg(), btnDeleteReview, reg()));
                }

                rowReview.getChildren().addAll(reg());

                scrollPaneContent.getChildren().addAll(rowReview);
                rowReviews.add(rowReview);
            }

            if(!isStudent) {
                Button btnDelBicycle = new Button("Bisikleti veritabanindan sil");
                btnDelBicycle.setAlignment(Pos.CENTER);
                btnDelBicycle.setFont(Font.font(15));
                HBox hBox = new HBox(reg(), new VBox(reg(), btnDelBicycle, reg()), reg());
                scrollPaneContent.getChildren().addAll(hBox);

                btnDelBicycle.setOnMouseClicked(e -> {
                    jsonDatabase.deleteBicycle(bicycle);
                    scrollPaneContent.getChildren().removeAll(row1, hBox, rowHsep);
                    scrollPaneContent.getChildren().removeAll(rowReviews);
                });
            }

            if(isStudent) {
                Button btnRentBicycle = new Button("Bisikleti kirala");
                btnRentBicycle.setAlignment(Pos.CENTER);
                btnRentBicycle.setFont(Font.font(15));

                HBox hBox = new HBox(reg(), new VBox(reg(), btnRentBicycle, reg()), reg());
                scrollPaneContent.getChildren().addAll(hBox);

                btnRentBicycle.setOnMouseClicked(e -> {
                    Integer minsInteger = askForRentingInfo();
                    if(minsInteger == null) return;
                    int mins = minsInteger;
                    if(mins <= 0) return;
                    final int totalCost = bicycle.costPerMinute * mins;
                    int balance = jsonDatabase.studentTable.getBalanceOf(ID);
                    if(balance < totalCost) {
                        giveFeedback(false, "Yeterli bakiyeniz bulunmamaktadir.");
                        return;
                    }
                    jsonDatabase.studentTable.addBalanceTo(ID, -totalCost);
                    jsonDatabase.rentTable.createNewRent(ID, bicycle.ID, mins);

                    scrollPaneContent.getChildren().removeAll(row1, hBox, rowHsep);
                    scrollPaneContent.getChildren().removeAll(rowReviews);
                });
            }


            /* TODO
                =>  admin: addBicycle     (veritabanına bisiklet ekleyebilir)
            */
            scrollPaneContent.getChildren().addAll(rowHsep);
        });

        scrollPaneContent.getChildren().add(reg());
        ScrollPane scrollPane = new ScrollPane(scrollPaneContent);

        Button btnSignOut = new Button("Listeyi Kapat");
        btnSignOut.setMinWidth(200);
        btnSignOut.setMinHeight(50);
        btnSignOut.setFont(Font.font(15));
        btnSignOut.setOnMouseClicked(e -> {
            Parent parent = isStudent ? new StudentPanel(mainApplication, jsonDatabase, ID).getRoot()
                    : new AdminPanel(mainApplication, jsonDatabase, ID).getRoot();
            mainApplication.switchSceneTo(parent);
        });

        Button btnAddBicycle = new Button("Yeni Bisiklet Ekle");
        btnAddBicycle.setMinWidth(200);
        btnAddBicycle.setMinHeight(50);
        btnAddBicycle.setFont(Font.font(15));
        btnAddBicycle.setOnMouseClicked(e -> {
            String[] bicycleInfo = askForBicycleInfo();
            String bicycleBrand = bicycleInfo[0];
            String bicycleModel = bicycleInfo[1];
            int bicycleYear = strToInt(bicycleInfo[2]);
            int bicycleCost = strToInt(bicycleInfo[3]);
            if(bicycleYear <= 1900 || bicycleCost <= 0) return;

            jsonDatabase.bicycleTable.addNewBicycle(bicycleBrand, bicycleModel, bicycleYear, bicycleCost);
            giveFeedback(true, "Yeni bisiklet tanimlandi");
            refreshList();
        });


        HBox ops = new HBox(reg());
        ops.setSpacing(50);
        if(!isStudent) ops.getChildren().add(btnAddBicycle);
        ops.getChildren().addAll(btnSignOut, reg());

        root = new VBox(
                reg(),
                new HBox(reg(), scrollPane, reg()),
                reg(),
                ops,
                reg()
        );
        root.setSpacing(20d);
        mainApplication.switchSceneTo(root);
    }


    public Parent getRoot() {
        return root;
    }

}
