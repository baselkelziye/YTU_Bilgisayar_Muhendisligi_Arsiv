package nasrullahtoprak;

import java.util.HashMap;

public class FoodDeliveryPlatform {
    private HashMap<String, Seliable> products;

    public FoodDeliveryPlatform(){
        products = new HashMap<String, Seliable>();
    }

    public void addProduct(Seliable product){
        if(products.containsValue(product)){
            System.out.println("This already exists!!");
            return;
        }
        products.put(product.getId(),product);
    }

    public Seliable getProduct(String id){
        if(!products.containsKey(id)){
            System.out.println("Product not found!");
            return null;
        }
        return products.get(id);
    }

    public void listProducts(){
        for(Seliable m: products.values()){
            System.out.println(m.toString());
        }
    }

    public void searchByPriceRange(double min, double max){
        for(Seliable m: products.values()){
            if(m.getPrice()>=min && m.getPrice()<=max){
                System.out.println(m.toString());
            }
        }
    }
}
