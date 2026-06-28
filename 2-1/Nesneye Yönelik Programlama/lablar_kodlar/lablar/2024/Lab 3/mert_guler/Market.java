package mertguler;

import java.util.List;
import java.util.Random;

public class Market {

    public static void simulatePurchases(List<Customer> customers, List<Product> products) {
        Random random = new Random();
        for (Customer customer : customers) {
            int productBuyCount = random.nextInt(3) + 1;
            for (int i = 0; i < productBuyCount; i++) {
                int randomProductIndex = random.nextInt(products.size());
                Product product = products.get(randomProductIndex);
                int buyAmount = random.nextInt(24, 50) + 1;
                try {
                    product.reduceStock(buyAmount);
                    customer.purchaseProduct(product, buyAmount);
                    System.out.println(customer.getName() + " purcashed " + buyAmount + " of " + product.getName());
                } catch (InsufficentStockError e) {
                    int insufficentStock = product.getStock();
                    if (insufficentStock == 0) {
                        System.out.println("Insufficent stock for Product: " + product.getName() + ". Available stock is 0. Couldn't provide any stock to " + customer.getName());
                    } else {
                        customer.purchaseProduct(product, insufficentStock);
                        product.reduceStock(insufficentStock);
                        System.out.println(e.getMessage() + " to " + customer.getName());
                    }
                }
            }
            System.out.println();
        }
    }

    public static void printCustomerSpending(List<Customer> customers){
        for (Customer customer : customers) {
            double totalSpending = 0;

            for (Product product: customer.getPurchasedProducts().keySet()){
                totalSpending += customer.getPurchasedProducts().get(product) * product.getPrice();
            }

            System.out.println("Customer: " + customer.getName() + ", " + "Total Spending: " + "$" + totalSpending);
        }
    }

    public static void printTotalIncome(List<Customer> customers){
        double totalIncome = 0;

        for (Customer customer : customers) {
            for (Product product: customer.getPurchasedProducts().keySet()){
                totalIncome += customer.getPurchasedProducts().get(product) * product.getPrice();
            }

        }

        System.out.println("Total Market Income: " + "$" + totalIncome);
    }
}
