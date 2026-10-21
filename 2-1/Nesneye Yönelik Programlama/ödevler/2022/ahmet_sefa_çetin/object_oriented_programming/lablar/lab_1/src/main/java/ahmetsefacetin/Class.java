package ahmetsefacetin;

public class Class {

    private String name;
    private int duration;
    private String instructor;
    private Student st[];

    public Class(String name, int duration, String instructor) {
        this.name = name;
        this.duration = duration;
        this.instructor = instructor;
        st = new Student[2];
    }

    public void addStudent(Student student) {
        int i = 0;
        while (i < st.length && st[i] != null) {
            i++;
        }
        if (i != st.length) {
            st[i] = student;
        } else {
            System.out.println("Course capacity is full");
        }
    }

    public void classInfo() {
        int i = 0;
        while (i < st.length && st[i] != null) {
            i++;
        }
        double averageAge = 0;
        for (int j = 0; j < i; j++) {
            averageAge += st[j].getAge();
        }
        if (i != 0) {
            averageAge /= i;
        }
        
        System.out.println("Class name:" + name + " Number of students: " + i + " Avarage age:" + averageAge);
    }
}
