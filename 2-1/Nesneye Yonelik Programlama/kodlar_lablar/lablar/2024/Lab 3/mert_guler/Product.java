package mertguler;

import java.util.ArrayList;
import java.util.List;

public class Product implements IProduct{
    private static int idCounter = 1;
    private final int id;
    private final String name;
    private final double price;
    private int stock;

    public Product(String name, double price){
        this.id = idCounter;
        idCounter++;
        this.name = name;
        this.price = price;
        stock = 100;
    }

    public int getId(){
        return id;
    }

    @Override
    public String getName(){
        return name;
    }

    @Override
    public double getPrice(){
        return price;
    }

    public int getStock(){
        return stock;
    }

    public static List<Product> createProductList(){
        List<Product> list = new ArrayList<Product>();
        list.add(new Product("Grain", 125));
        list.add(new Product("Steel", 300));
        list.add(new Product("Plastic", 100));
        list.add(new Product("Gold", 1000));
        list.add(new Product("Cotton", 350));
        list.add(new Product("Olive", 250));

        return list;
    }

    public static void printInventoryWithIds(List<Product> products){
        for (Product product : products){
            System.out.println(product.toString());
        }
    }

    public void reduceStock(int quantity) throws InsufficentStockError{
        if (quantity <= 0){
            return;
        }

        if (stock >= quantity){
            stock = stock - quantity;
        } else if (stock < quantity){
            throw new InsufficentStockError("Insufficent stock for Product: " + name + ". " + "Only " + stock + " units are available. Remaining stock has been provided");
        }
    }

    @Override
    public String toString(){
        return "Product ID: " + id + ", " + name + ", " + "Remaining Stock: " + stock;
    }




}
