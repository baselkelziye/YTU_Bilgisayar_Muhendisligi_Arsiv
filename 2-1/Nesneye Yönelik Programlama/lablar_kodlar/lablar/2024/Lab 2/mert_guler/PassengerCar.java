package mertguler;

public class PassengerCar extends Car {
    private double fuelCost = 0.05;

    public PassengerCar(int id, String brand, String model, double dailyRentalPrice) {
        super(id, brand, model, dailyRentalPrice);
    }

    public double calculateFuelCost(int distance, double price){
        return ((double) distance * fuelCost) * price;
    }
}
