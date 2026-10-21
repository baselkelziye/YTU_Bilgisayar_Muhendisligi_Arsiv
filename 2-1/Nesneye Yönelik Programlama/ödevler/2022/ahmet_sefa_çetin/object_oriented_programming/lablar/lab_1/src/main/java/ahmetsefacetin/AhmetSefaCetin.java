package ahmetsefacetin;

public class AhmetSefaCetin {

    public static void main(String[] args) {
        Exam ex = new Exam("01-07-2023");
        
        Class c1 = new Class("Painting", 3, "Mehmet Er");
        
        Student s1 = new Student(101, "Ali Demir", 34);
        Student s2 = new Student(102, "Veli Sur", 56);
        Student s3 = new Student(103, "Mert Yurt", 25);
        
        s1.setExamScore(ex, 65);
        
        System.out.println(s1);
        
        c1.addStudent(s1);
        c1.addStudent(s2);
        c1.addStudent(s3);
        c1.classInfo();
        
        s1.calculateDiscount();
        System.out.println(s1.getDiscountPercentage());
        
    }
}
