import Database.CarOperations;
import Database.FinanceOperations;
import GUI.MainMenu;

public class Main {
    public static void main(String[] args) {
        Database.CarOperations carUpd = new CarOperations();
        Database.FinanceOperations finUpd = new FinanceOperations();
        carUpd.updateCars();
        finUpd.updateStatus();
        GUI.MainMenu mm = new MainMenu();

        // Bir gelir-gider sınıfı ve sql table'ı oluşturulacak
        // Tarih , açıklama , para bilgisi tutulacak
        // Bu güncellemeler :
        // Müşteri için ödemeler anlık olarak kiralama sırasında db'ye kaydedilecek
        // Vergiler -eğer ayın 1'iyse- main aşamasında update fonksiyonu ile güncellenecek.
        // JTABLE diğer listelerde olduğu gibi tutulacak.

        // class-
        // sql db-
        // vergi aktar-
        // ücret aktar-
    }
}