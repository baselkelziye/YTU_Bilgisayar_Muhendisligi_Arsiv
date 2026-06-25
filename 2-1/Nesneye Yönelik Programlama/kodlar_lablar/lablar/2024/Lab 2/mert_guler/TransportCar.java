package mertguler;

public class TransportCar extends Car {
    private double fuelCost = 0.2;
    private int passangerCapacity;

    public TransportCar(int id, String brand, String model, double dailyRentalPrice, int passangerCapacity) {
        super(id, brand, model, dailyRentalPrice);
        this.passangerCapacity = passangerCapacity;
    }

    public double calculateFuelCost(int distance, double price){
        return ((double) distance * fuelCost) * price;
    }
}
