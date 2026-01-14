public class Car extends Vehicle {
    private int door;
    private double trunkLiters;

    public Car(String brand, String model, int year, int door, double trunkLiters, int serial) {
        super(brand, model, year);
        this.door = door;
        this.trunkLiters = trunkLiters;
        this.uniqueId = generateUniqueIdBody(serial);
    }

    protected String generateUniqueIdBody(int serial) {
        return "CAR-" + this.brand.toUpperCase() + "-" + this.year + "-" + (serial + 1000);
    }

    public String getTypeName() {
        return "Car";
    }

    public int getDoor() {
        return door;
    }

    public double getTrunkLiters() {
        return trunkLiters;
    }
}
