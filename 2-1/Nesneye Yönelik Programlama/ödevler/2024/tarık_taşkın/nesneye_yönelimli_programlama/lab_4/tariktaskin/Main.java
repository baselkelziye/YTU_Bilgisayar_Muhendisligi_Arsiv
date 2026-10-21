package tariktaskin;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        try {
            List<Employee> employees = FileUtility.readEmployeesFromFile("employees.txt");
            List<Employee> managers = FileUtility.readEmployeesFromFile("managers.txt");
            System.out.println(employees);
            System.out.println(managers);
            Thread thread1 = new Thread(new SalaryIncreaseThread(employees, 10.0));
            Thread thread2 = new Thread(new SalaryIncreaseThread(managers, 10.0));
            
            
            thread1.start();
            thread2.start();
            
            
            thread1.join();
            thread2.join();
            //System.out.println(employees);
            //System.out.println(managers);
            FileUtility.writeEmployeesToFile(employees, "updated_employees.txt");
            FileUtility.writeEmployeesToFile(managers, "updated_managers.txt");

            System.out.println("İşlem tamamlandı. Güncellenen çalışan bilgileri dosyalara yazıldı.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
