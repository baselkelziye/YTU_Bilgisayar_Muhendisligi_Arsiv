package Entities;

import Database.CustomerOperations;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Customer extends Person{
    private ArrayList<Car> cars;
    private String carNames;
    private double totalDebt;

    public Customer(String name, String surname, String TC, String birthDate) {
        super(name, surname, TC, birthDate);
        cars = new ArrayList<>();
        totalDebt = 0;
    }

    public static List<Customer> setList() {
        CustomerOperations sl = new CustomerOperations();
        return sl.setList();
    }
    public ArrayList<Car> getCars() {
        return cars;
    }

    public void setCars(ArrayList<Car> cars) {
        this.cars = cars;
    }

    public double getTotalDebt() {
        return totalDebt;
    }

    public void setTotalDebt(double totalDebt) {
        this.totalDebt = totalDebt;
    }


    public String getCarNames() {
        return carNames;
    }

    public void setCarNames(String carNames) {
        this.carNames = carNames;
    }

    public Object[] getObjects() {
        Object[] data = {getName(),getSurname(),getTC(),getBirthDate(),carNames,totalDebt};
        return data;
    }

    public Object[] getRentalObjects() {
        Object[] data = {getName(),getSurname(),getTC(),getBirthDate()};
        return data;
    }
}
