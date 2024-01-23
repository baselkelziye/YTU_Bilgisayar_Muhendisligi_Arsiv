

public class Main {

    public static void main(String[] args) {
        ProcessManager PM = new ProcessManager(10);
        User u1 = new User("u1");
        User u2 = new User("u2");
        User u3 = new User("u3");

        PM.add_process(u1, "Process1", 2);
        PM.add_process(u1, "Process4", 2);
        PM.add_process(u2, "Process2", 6);

        

        PM.add_process(u3, "Process3", 3);
        PM.add_process(u1, "Process6", 7);
        PM.add_process(u2, "Process2", 4); // Ayný isimde process olduðu için iki listeyede eklemez. Process isimleri unique olmalý.
        PM.add_process(u2, "Process5", 1);

        System.out.println("1-Process -----------------");
        PM.print_processes();
        System.out.println("1-Waiting Process -----------------");
        PM.print_waiting_processes();

        try {
            PM.remove_process("Process2"); // Catch'e girmez çünkü process mevcut.
        } 
        catch (Exception ex) {
            System.out.println(ex);
        }

        System.out.println("After Process2 Removed");

        System.out.println("2-Process -----------------");
        PM.print_processes();
        System.out.println("2-Waiting Process -----------------");
        PM.print_waiting_processes();

        System.out.println(PM.getUsed_memory_size());

        try {
            PM.remove_process("OlmayanProcess"); // Catch'e girer process mevcut deðil.
        } 
        catch (Exception ex) {
            System.out.println(ex);
        }

    }

}
