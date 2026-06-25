package Uyg4;

public class WriteMain {
    public static void main(String[] args) throws Exception {
        new Bank("Temp").createDataFile("data.txt");
        System.out.println("Dosya oluşturuldu (tek thread sonucu = +10)");
    }
}
