package yusufsafakoksal;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        try {
            List<Staff> staffList = FileUtility.readStaffFromFile("staff.txt");

            SalaryIncreaseThread thread = new SalaryIncreaseThread(staffList, 10.0);
            Thread t = new Thread(thread);
            t.start();
            t.join();

            FileUtility.writeStaffToFile(staffList, "updated_staff.txt");

            System.out.println("İşlem tamamlandı. Güncellenen personel bilgileri dosyaya yazıldı.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
