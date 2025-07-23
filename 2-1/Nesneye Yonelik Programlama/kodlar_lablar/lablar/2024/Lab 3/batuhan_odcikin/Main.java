package batuhanodcikin;

import java.util.*;

public class Main {
    public static void main(String[] args) {

        List<Customer> customers = Customer.createCustomerList();
        List<Product> products = Product.createProductList();

        System.out.println("****** Customers ******");
        Customer.showListCustomer(customers);

        System.out.println("\n****** Products ******");
        Product.printInventoryWithIds(products);

        System.out.println("\n****** Orders ******");
        Market.simulatePurchases(customers, products);

        System.out.println("\n****** Shipping Status ******");
        Shipping shipping = new Shipping();
        shipping.simulateShipping(customers);

        System.out.println("\n****** Market Inventory ******");
        Product.printInventoryWithIds(products);

        System.out.println("\n****** Customer Spendings ******");
        Market.printCustomerSpending(customers);

        System.out.println("\n****** Total Income ******");
        Market.printTotalIncome(customers);
    }
}