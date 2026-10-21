package savtproje.database.entities;

public class Student {
    public final String fullname, password;
    public final int ID; // studentID yani öğrenci numarası "19052025" gibi
    public final int age; // age final çünkü 1 yıl boyunca uygulama açık kalacak değil :P
    private int balance;

    public Student(int ID, String fullname, String password, int age) {
        this.ID = ID;
        this.fullname = fullname;
        this.password = password;
        this.age = age;
    }

    public void setBalance(int balance) { this.balance = balance; }
    public int getBalance() { return balance; }
}