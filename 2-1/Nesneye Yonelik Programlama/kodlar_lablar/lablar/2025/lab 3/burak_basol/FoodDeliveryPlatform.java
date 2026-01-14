import java.util.HashMap;

public class FoodDeliveryPlatform {
    private HashMap<String, Sellable> products;

    public FoodDeliveryPlatform() {
        this.products = new HashMap<>();
    }

    public void addProduct(Sellable product) {
        products.put(product.getId(), product);
    }

    public Sellable getProduct(String id) {
        return products.get(id);
    }

    public void listProducts() {
        for(Sellable product : products.values()) {
            System.out.println(product.toString());
        }
    }

    public void searchByPriceRange(double min, double max) {
        for(Sellable product : products.values()) {
            if(product.getPrice() >= min && product.getPrice() <= max) {
                System.out.println(product.toString());
            }
        }
    }

}
