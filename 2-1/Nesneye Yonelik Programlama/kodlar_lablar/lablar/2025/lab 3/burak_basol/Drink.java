public class Drink implements Sellable{
    private String id;
    private String name;
    private double price;
    private String size;

    public Drink(String id, String name, double price, String size) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.size = size;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    @Override
    public String toString() {
        return "Drink id=" + id + ", name=" + name + ", price=" + price + ", size=" + size;
    }
}
