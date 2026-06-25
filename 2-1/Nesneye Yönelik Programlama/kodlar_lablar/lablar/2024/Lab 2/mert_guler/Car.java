package mertguler;

public abstract class Car {
    protected int id;
    protected String brand;
    protected String model;
    protected double dailyRentalPrice;

    public Car(int id, String brand, String model, double dailyRentalPrice) {
        this.id = id;
        this.brand = brand;
        this.model = model;
        this.dailyRentalPrice = dailyRentalPrice;
    }

    abstract public double calculateFuelCost(int distance, double price);

}
