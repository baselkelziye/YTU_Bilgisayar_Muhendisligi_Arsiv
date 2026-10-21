package savtproje;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.scene.text.Font;
import savtproje.database.entities.Bicycle;
import savtproje.database.entities.Rent;
import savtproje.database.tables.BicycleTable;

import java.nio.file.Files;
import java.nio.file.Path;
import java.text.SimpleDateFormat;
import java.util.Optional;

public class Utils {


    public static String[] askForLoginInfo() {
        Dialog<String[]> dialog = new Dialog<>();
        dialog.setTitle("Sisteme giris");
        dialog.setHeaderText("Lutfen numaranizi ve sifrenizi giriniz:");
        ButtonType loginButtonType = new ButtonType("Giris Yap", ButtonBar.ButtonData.OK_DONE);
        ButtonType cancelButtonType = new ButtonType("Menuye Don", ButtonBar.ButtonData.CANCEL_CLOSE);
        dialog.getDialogPane().getButtonTypes().addAll(loginButtonType, cancelButtonType);

        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20, 150, 10, 10));

        TextField username = new TextField(), password = new PasswordField();

        grid.add(new Label("Numara:"), 0, 0); grid.add(username, 1, 0);
        grid.add(new Label("Sifre:"), 0, 1); grid.add(password, 1, 1);
        dialog.getDialogPane().setContent(grid);
        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == loginButtonType) {
                return new String[]{username.getText(), password.getText()};
            }
            return null;
        });

        username.requestFocus();
        Optional<String[]> result = dialog.showAndWait();
        if(result.isPresent()) return result.get();
        return null;
    }

    public static <K> K readJsonFile(String path, Class<K> clazz) {
        try {
            Gson gson = new GsonBuilder().setPrettyPrinting().serializeNulls().create();
            String jsonContent = Files.readString(Path.of(path));
            return gson.fromJson(jsonContent, clazz);
        }
        catch (Exception ignored){ return null; }
    }

    public static String[] askForBicycleInfo() {
        Dialog<String[]> dialog = new Dialog<>();
        dialog.setTitle("Bisiklet Bilgileri");
        dialog.setHeaderText("Lutfen bisiklet markasini, modelini, yilini ve maliyetini giriniz:");
        ButtonType addButtonType = new ButtonType("Ekle", ButtonBar.ButtonData.OK_DONE);
        ButtonType cancelButtonType = new ButtonType("Iptal", ButtonBar.ButtonData.CANCEL_CLOSE);
        dialog.getDialogPane().getButtonTypes().addAll(addButtonType, cancelButtonType);

        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20, 150, 10, 10));

        TextField brand = new TextField(), model = new TextField(), year = new TextField(), cost = new TextField();

        grid.add(new Label("Marka:"), 0, 0); grid.add(brand, 1, 0);
        grid.add(new Label("Model:"), 0, 1); grid.add(model, 1, 1);
        grid.add(new Label("Yil:"), 0, 2); grid.add(year, 1, 2);
        grid.add(new Label("Maliyet:"), 0, 3); grid.add(cost, 1, 3);

        dialog.getDialogPane().setContent(grid);
        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == addButtonType) {
                return new String[] { brand.getText(), model.getText(), year.getText(), cost.getText() };
            }
            return null;
        });

        brand.requestFocus();
        Optional<String[]> result = dialog.showAndWait();
        if(result.isPresent()) return result.get();
        return null;
    }


    public static String[] askForRegistrationInfo() {
        Dialog<String[]> dialog = new Dialog<>();
        dialog.setTitle("Kayit ol");
        dialog.setHeaderText("Lutfen numaranizi, sifrenizi, adinizi, soyadinizi ve yasinizi giriniz:");
        ButtonType loginButtonType = new ButtonType("Giris Yap", ButtonBar.ButtonData.OK_DONE);
        ButtonType cancelButtonType = new ButtonType("Menuye don", ButtonBar.ButtonData.CANCEL_CLOSE);
        dialog.getDialogPane().getButtonTypes().addAll(loginButtonType, cancelButtonType);

        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20, 150, 10, 10));

        TextField username = new TextField(), fullname = new TextField(), age = new TextField();
        PasswordField password = new PasswordField();

        grid.add(new Label("Ogrenci numarasi:"), 0, 0); grid.add(username, 1, 0);
        grid.add(new Label("Sifre:"), 0, 1); grid.add(password, 1, 1);
        grid.add(new Label("Ad soyad:"), 0, 2); grid.add(fullname, 1, 2);
        grid.add(new Label("Yas:"), 0, 3); grid.add(age, 1, 3);

        dialog.getDialogPane().setContent(grid);
        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == loginButtonType) {
                return new String[] {username.getText(), password.getText(), fullname.getText(), age.getText()};
            }
            return null;
        });

        username.requestFocus();
        Optional<String[]> result = dialog.showAndWait();
        if(result.isPresent()) return result.get();
        return null;
    }

    public static Integer askForBalance() {
        Dialog<Integer> dialog = new Dialog<>();
        dialog.setTitle("Bakiye Yukleme");
        dialog.setHeaderText("Lutfen yuklemek istediginiz bakiye miktarini giriniz:");

        ButtonType loginButtonType = new ButtonType("Yukle", ButtonBar.ButtonData.OK_DONE);
        ButtonType cancelButtonType = new ButtonType("Iptal", ButtonBar.ButtonData.CANCEL_CLOSE);
        dialog.getDialogPane().getButtonTypes().addAll(loginButtonType, cancelButtonType);

        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20, 150, 10, 10));

        TextField balance = new TextField();
        grid.add(new Label("Bakiye:"), 0, 0); grid.add(balance, 1, 0);

        dialog.getDialogPane().setContent(grid);

        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == loginButtonType) {
                try { return strToInt(balance.getText()); }
                catch (NumberFormatException e) { return null; }
            }
            return 0;
        });

        balance.requestFocus();
        Optional<Integer> result = dialog.showAndWait();
        if(result.isPresent()) return result.get();
        return null;
    }

    public static void giveFeedback(boolean success, String text) {
        Alert alert = new Alert(success ? Alert.AlertType.INFORMATION : Alert.AlertType.ERROR);
        alert.setTitle(success ? "Bilgi" : "Hata");
        alert.setHeaderText(null);
        alert.setContentText(text);
        alert.showAndWait();
    }

    public static void giveFeedback(boolean success, String text, int fontSize) {
        Alert alert = new Alert(success ? Alert.AlertType.INFORMATION : Alert.AlertType.ERROR);
        alert.setTitle(success ? "Bilgi" : "Hata");
        alert.setHeaderText(null);

        Label label = new Label(text);
        label.setFont(Font.font(fontSize));
        alert.getDialogPane().setContent(label);

        alert.showAndWait();
    }

    public static Separator vsep() {
        return new Separator(Orientation.VERTICAL);
    }

    public static Separator hsep() {
        return new Separator(Orientation.HORIZONTAL);
    }

    public static Separator hsep(int pad) {
        Separator separator = new Separator(Orientation.HORIZONTAL);
        separator.setPadding(new Insets(pad, 0, 0, 0));
        return separator;
    }

    public static Integer askForRentingInfo() {
        Dialog<Integer> dialog = new Dialog<>();
        dialog.setTitle("Kiralama Islemi");
        dialog.setHeaderText("Lutfen bisikleti kac dakika icin kiralamak istediginizi giriniz:");

        ButtonType loginButtonType = new ButtonType("Tamam", ButtonBar.ButtonData.OK_DONE);
        ButtonType cancelButtonType = new ButtonType("Iptal", ButtonBar.ButtonData.CANCEL_CLOSE);
        dialog.getDialogPane().getButtonTypes().addAll(loginButtonType, cancelButtonType);

        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20, 150, 10, 10));

        TextField hours = new TextField();
        grid.add(new Label("Dakika:"), 0, 0); grid.add(hours, 1, 0);

        dialog.getDialogPane().setContent(grid);

        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == loginButtonType) {
                try { return strToInt(hours.getText()); }
                catch (NumberFormatException e) { return null; }
            }
            return 0;
        });

        hours.requestFocus();
        Optional<Integer> result = dialog.showAndWait();
        if(result.isPresent()) return result.get();
        return null;
    }

    public static Region reg() {
        Region reg = new Region();
        HBox.setHgrow(reg, Priority.ALWAYS);
        VBox.setVgrow(reg, Priority.ALWAYS);
        return reg;
    }

    public static int strToInt(String intString) {
        try { return Integer.parseInt(intString); }
        catch (Exception ignored) { return -1; }
    }

}
