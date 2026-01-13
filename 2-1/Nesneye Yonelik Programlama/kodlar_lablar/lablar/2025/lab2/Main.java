
public class Main {
    public static void main(String[] args) {

        // Filo 4 araç kapasiteli olarak başlatılıyor
        Filo filo = new Filo(4); 

        // Filo'nun yardımcı metotları kullanılarak araçlar oluşturulur ve diziye eklenir.
        filo.addVehicle(filo.createCar("Toyota", "Corolla", 2020, 4, 470)); // ID: CAR-TOY-2020-1000
        filo.addVehicle(filo.createCar("BMW", "320i", 2022, 4, 480));       // ID: CAR-BMW-2022-1001
        filo.addVehicle(filo.createMotorcycle("Honda", "CBR", 2019, 600, false)); // ID: MOTO-HO-600-1002
        filo.addVehicle(filo.createMotorcycle("Yamaha", "MT-07", 2021, 689, false)); // ID: MOTO-YA-689-1003

        filo.printAllVehicles();

        // Müsait tüm araçlar:
        System.out.println("Müsait tüm araçlar:");
        filo.printAvailable();
        System.out.println();

        // Müsait sadece CAR:
        System.out.println("Müsait sadece CAR:");
        filo.printAvailableByType("Car");
        System.out.println();

        // Kiralama testi
        String idToRent = "CAR-BMW-2022-1001"; // İkinci aracı kiralayalım
        
        System.out.println("Kiralama denemesi: " + idToRent);
        filo.rentById(idToRent);

        System.out.println("\nKiralama sonrası müsait CAR:");
        filo.printAvailableByType("Car");

        // İade testi
        System.out.println("\nİade denemesi: " + idToRent);
        filo.returnById(idToRent);

        System.out.println("\nİade sonrası müsait CAR:");
        filo.printAvailableByType("Car");
        
        // Dizi doluluk testi
        filo.addVehicle(filo.createCar("Mercedes", "C200", 2023, 4, 500)); // Kapasite doldu uyarısı beklenir.
    }
}