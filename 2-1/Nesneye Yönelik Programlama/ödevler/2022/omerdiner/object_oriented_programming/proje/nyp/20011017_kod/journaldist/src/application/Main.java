package application;

public class Main {
    public static void main(String[] args) {

        Thread thread1 = new Thread(new main_gui_thread());

        Thread thread2 = new Thread(new report_gui_thread());

        thread1.start();
        thread2.start();

        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            System.out.println("Hata : ");
            e.printStackTrace();
            throw new RuntimeException(e);
        }


    }
}
