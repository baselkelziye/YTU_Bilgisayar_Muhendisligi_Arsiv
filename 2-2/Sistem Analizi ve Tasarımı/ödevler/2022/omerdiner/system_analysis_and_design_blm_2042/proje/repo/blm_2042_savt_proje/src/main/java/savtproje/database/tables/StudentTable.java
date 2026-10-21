package savtproje.database.tables;

import savtproje.database.AbstractTable;
import savtproje.database.entities.*;

import java.util.LinkedList;


public class StudentTable extends AbstractTable<Student> {

    public static final String JSON_PATH = "database/students.json";

    public StudentTable() {
        super(JSON_PATH);
    }

    public boolean isValidIDAndPassword(int studentNumber, String password) {
        Student student = find(x -> x.ID == studentNumber);
        if(student == null) return false; // studentNumber doesnt exist
        return student.password.equals(password);
    }

    public String getFullnameOf(int studentNumber) {
        return find(x -> x.ID == studentNumber).fullname;
    }

    public int getBalanceOf(int studentNumber) {
        return find(x -> x.ID == studentNumber).getBalance();
    }

    public boolean registerNewStudent(int studentNumber, String fullname, String password, int age) {
        if(find(x -> x.ID == studentNumber) == null) { // id doesnt already exist
            table.add(new Student(studentNumber, fullname, password, age));
            save();
            return true;
        }

        return false;
    }

    public int addBalanceTo(int studentID, int balanceIncrement) {
        Student student = find(x -> x.ID == studentID);
        student.setBalance(student.getBalance() + balanceIncrement);
        save();
        return student.getBalance();
    }


}