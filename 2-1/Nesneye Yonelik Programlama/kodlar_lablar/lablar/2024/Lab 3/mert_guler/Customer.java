package mertguler;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Customer{
    private final String name;
    private final String location;
    private final HashMap<Product, Integer> purchasedProducts;

    public Customer(String name, String location){
        this.name = name;
        this.location = location;
        purchasedProducts = new HashMap<>();
    }

    public static List<Customer> createCustomerList(){
        List<Customer> customers = new ArrayList<>();
        customers.add(new Customer("Allan", "Washington"));
        customers.add(new Customer("Jhon", "NYC"));
        customers.add(new Customer("Lily", "Kansas"));
        customers.add(new Customer("Arthur", "Detroit"));
        customers.add(new Customer("Frank", "NYC"));
        customers.add(new Customer("Joe", "Seattle"));
        return customers;
    }

    public String getName(){
        return name;
    }

    public String getLocation(){
        return location;
    }

    public Map<Product, Integer> getPurchasedProducts(){
        return purchasedProducts;
    }

    public void purchaseProduct(Product product, int quantity){
        purchasedProducts.put(product, quantity);
    }

    public static void showListCustomer(List<Customer> customers){
        for (Customer customer: customers){
            System.out.println(customer);
        }
    }

    @Override
    public String toString(){
        return "Customer Name: " + name + ", " + "Location: " + location;
    }

}
