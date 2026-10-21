package ahmetsefacetin;

public class Student {

    private int stdNo;
    private String name;
    private int age;
    private double discountPercentage;
    private Exam exam;

    public Student(int stdNo, String name, int age) {
        this.stdNo = stdNo;
        this.name = name;
        this.age = age;
    }

    /**
     * @return the age
     */
    public int getAge() {
        return age;
    }

    /**
     * @param exam the exam to set
     */
    public void setExam(Exam exam) {
        this.exam = exam;
    }

    public void setExamScore(Exam exam, int score) {
        this.exam = exam;
        this.exam.setScore(score);
    }

    public void calculateDiscount() {
        if (this.exam.getScore() >= 70) {
            discountPercentage = 20;
        } else if (this.exam.getScore() < 70 && this.exam.getScore() >= 50) {
            discountPercentage = 10;
        }
    }

    @Override
    public String toString() {
        return "Student [stdNo=" + stdNo + ", name=" + name + ", age=" + age + ", " + exam.toString() + "]";
    }

    /**
     * @return the discountPercentage
     */
    public double getDiscountPercentage() {
        return discountPercentage;
    }

}
