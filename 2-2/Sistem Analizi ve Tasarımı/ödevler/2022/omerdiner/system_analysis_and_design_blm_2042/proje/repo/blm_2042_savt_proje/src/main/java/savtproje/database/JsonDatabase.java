package savtproje.database;


import java.text.SimpleDateFormat;
import java.util.Comparator;
import java.util.LinkedList;

import savtproje.database.entities.*;
import savtproje.database.tables.*;
import static savtproje.Utils.readJsonFile;


public class JsonDatabase {

    public final BicycleTable bicycleTable;
    public final StudentTable studentTable;
    public final RentTable rentTable;
    public final ReviewTable reviewTable;
    public final AdminTable adminTable;


    public JsonDatabase() {
//        generateDummyJsonFiles();

        this.bicycleTable = readJsonFile(BicycleTable.JSON_PATH, BicycleTable.class);
        this.studentTable = readJsonFile(StudentTable.JSON_PATH, StudentTable.class);
        this.reviewTable = readJsonFile(ReviewTable.JSON_PATH, ReviewTable.class);
        this.adminTable = readJsonFile(AdminTable.JSON_PATH, AdminTable.class);
        this.rentTable = readJsonFile(RentTable.JSON_PATH, RentTable.class);
    }


    private void generateDummyJsonFiles() {
        StudentTable studentTable = new StudentTable();
        studentTable.add(new Student(19052025, "Oguzhan Topaloglu", "1234", 23));
        studentTable.add(new Student(20052092, "Buse Savin", "1234", 20));
        studentTable.add(new Student(123, "John Doe", "123", 60));
        studentTable.save();

        BicycleTable bicycleTable = new BicycleTable();
        bicycleTable.add(new Bicycle(615574894, "brand6", "model6", 2018+6, 600*6));
        bicycleTable.add(new Bicycle(188156516, "brand1", "model1", 2018+1, 600*1));
        bicycleTable.add(new Bicycle(894102165, "brand8", "model8", 2018+8, 600*8));
        bicycleTable.add(new Bicycle(222222264, "brand2", "model2", 2018+2, 600*2));
        bicycleTable.save();

        AdminTable adminTable = new AdminTable();
        adminTable.add(new Admin(1, "Yunus Emre Cay", "1"));
        adminTable.add(new Admin(9999, "Omer Diner", "9999"));
        adminTable.save();

        ReviewTable reviewTable = new ReviewTable();
        reviewTable.add(new Review(12, 19052025, 615574894, 5, 9, 10));
        reviewTable.add(new Review(21, 19052025, 188156516, 1, 3, 1));
        reviewTable.add(new Review(23, 19052025, 894102165, 5, 2, 1));
        reviewTable.add(new Review(32, 19052025, 222222264, 10, 10, 10));
        reviewTable.add(new Review(34, 20052092, 615574894, 5, 9, 10));
        reviewTable.save();

        RentTable rentTable = new RentTable();
        rentTable.add(new Rent(12, 19052025, 615574894, 55));
        rentTable.add(new Rent(21, 19052025, 188156516, 42));
        rentTable.add(new Rent(23, 19052025, 894102165, 50));
        rentTable.add(new Rent(32, 19052025, 222222264, 21));
        rentTable.add(new Rent(34, 20052092, 615574894, 92));
        rentTable.save();

    }


    public String getRentHistoryStringOf(int studentID) {
        StringBuilder sb = new StringBuilder();
        LinkedList<Rent> rents = rentTable.findAll(r -> r.studentID == studentID);
        rents.sort(Comparator.comparing(o -> o.date));
        for (Rent rent : rents) {
            Bicycle bicycle = bicycleTable.find(x -> x.ID == rent.bicycleID);
            sb.append(String.format(
                    "- [%s] %d ID'li, %s markali ve %s modelli bisiklet; %d dakikaligina kiralandi. " +
                            "(Tutar: %d dk * %d TL/dk = %d TL)\n\n",
                    new SimpleDateFormat("dd:MM:yyyy HH:mm").format(rent.date),
                    rent.bicycleID, bicycle.brand, bicycle.model, rent.totalTimeInMinutes,
                    rent.totalTimeInMinutes, bicycle.costPerMinute, rent.totalTimeInMinutes * bicycle.costPerMinute
            ));
        }

        return sb.toString();
    }


    public void deleteBicycle(Bicycle bicycle) {
        LinkedList<Rent> rents = rentTable.findAll(rent -> rent.bicycleID == bicycle.ID);
        rentTable.removeAll(rents);

        LinkedList<Review> reviews = reviewTable.findAll(review -> review.bicycleID == bicycle.ID);
        reviewTable.removeAll(reviews);

        bicycleTable.remove(bicycle);

        rentTable.save();
        reviewTable.save();
        bicycleTable.save();
    }

    public boolean deleteStudent(int studentID) {
        Student student = studentTable.find(x -> x.ID == studentID);
        if(student == null) return false;

        LinkedList<Rent> rents = rentTable.findAll(rent -> rent.studentID == studentID);
        rentTable.removeAll(rents);

        LinkedList<Review> reviews = reviewTable.findAll(review -> review.studentID == studentID);
        reviewTable.removeAll(reviews);

        studentTable.remove(student);

        rentTable.save();
        reviewTable.save();
        studentTable.save();
        return true;
    }


}
