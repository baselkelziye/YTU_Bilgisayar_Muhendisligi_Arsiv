package mertguler;

import java.util.ArrayList;

public class CustomerCompany {
    private String name;
    private ArrayList<Car> rentedCars;

    public CustomerCompany(String name) {
        this.name = name;
        this.rentedCars = new ArrayList<>();
    }

    public void rentCar(Car car) {
        if (car == null){
            System.out.println("Car is null.");
        }

        if (!(rentedCars.contains(car))) {
            rentedCars.add(car);
        }
    }

    public int getRentalCount(){
        return rentedCars.size();
    }

    public String getName(){
        return name;
    }

    public ArrayList<Car> getRentedCars(){
        return rentedCars;
    }
}
