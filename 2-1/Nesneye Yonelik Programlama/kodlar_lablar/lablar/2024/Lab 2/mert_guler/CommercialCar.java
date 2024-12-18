package mertguler;

public class CommercialCar extends Car {
    private double fuelCost = 0.1;

    public CommercialCar(int id, String brand, String model, double dailyRentalPrice) {
        super(id, brand, model, dailyRentalPrice);
    }

    public double calculateFuelCost(int distance, double price){
        return ((double) distance * fuelCost) * price;
    }
}
