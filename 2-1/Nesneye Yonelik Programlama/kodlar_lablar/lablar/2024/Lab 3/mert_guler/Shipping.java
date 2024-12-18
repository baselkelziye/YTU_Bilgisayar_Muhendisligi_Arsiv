package mertguler;

import java.text.ParseException;
import java.util.List;
import java.util.Random;

public class Shipping {
    private final Random random;

    public Shipping() {
        random = new Random();
    }

    private boolean shipProduct(String productName, String customerName) throws ProductShippingError{
        double successRate = random.nextInt(4);
        if (successRate == 0){
            throw new ProductShippingError(productName + " could not be shipped to " + customerName);
        } else {
            return true;
        }
    }

    public void simulateShipping(List<Customer> customers){
        for (Customer customer : customers) {
            int successCount = 0;
            for (Product product: customer.getPurchasedProducts().keySet()){
                try {
                    if (shipProduct(product.getName(), customer.getName())){
                        successCount++;
                    }
                } catch (ProductShippingError e) {
                    System.out.println(e.getMessage());
                }
            }
            if (successCount == customer.getPurchasedProducts().size()){
                System.out.println("All orders have been successfully shipped to " + customer.getName());
            }
        }
    }
}
