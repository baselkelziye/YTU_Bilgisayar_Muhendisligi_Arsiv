package mertguler;

import java.util.ArrayList;

public class RentACarCompany {
    private String name;
    private ArrayList<Car> carList;
    private ArrayList<CustomerCompany> customerList;


    public RentACarCompany(String name) {
        this.name = name;
        this.carList = new ArrayList<>();
        this.customerList = new ArrayList<>();
    }

    public ArrayList<Car> getCarList() {
        return carList;
    }

    public ArrayList<Car> getCarlist() {
        return carList;
    }

    public void rentCar(CustomerCompany customer, Car car){
        if (customer == null){
            System.out.println("Customer is null.");
            return;
        }

        if (car == null){
            System.out.println("Car is null.");
            return;
        }

        if (!(customerList.contains(customer))){
            customerList.add(customer);
        }

        if (!(customer.getRentedCars().contains(car))){
            customer.getRentedCars().add(car);
        }

    }

    public String mostFrequentCustomer() {
        if (customerList.isEmpty()) {
            return "No customers found.";
        }

        CustomerCompany mostFrequentCustomer = customerList.getFirst();
        for (CustomerCompany customer : customerList) {
            if (customer.getRentalCount() > mostFrequentCustomer.getRentalCount()) {
                mostFrequentCustomer = customer;
            }
        }

            return mostFrequentCustomer.getName() + " with " + mostFrequentCustomer.getRentalCount() + " Cars.";
    }

    public void calculateTotalCosts(int rentalDays){
        for (CustomerCompany customer : customerList) {
            double totalCost = 0;
            for (Car car: customer.getRentedCars()){
                totalCost += car.dailyRentalPrice * rentalDays;
            }
            System.out.println("Company " + customer.getName() + "'s total cost for " + rentalDays + " days:" + totalCost + " TL");
        }
    }

}
