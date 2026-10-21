package savtproje.database.entities;

public class Bicycle {
    public final int ID, year, costPerMinute;
    public final String brand, model;

    public Bicycle(int ID, String brand, String model, int year, int costPerMinute) {
        this.costPerMinute = costPerMinute;
        this.brand = brand;
        this.model = model;
        this.year = year;
        this.ID = ID;
    }
}
