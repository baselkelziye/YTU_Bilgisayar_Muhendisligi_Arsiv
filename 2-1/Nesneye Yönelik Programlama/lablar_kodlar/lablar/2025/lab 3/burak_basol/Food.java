public class Food implements Sellable {
    private String id;
    private String name;
    private double price;
    private String restaurant;

    public Food(String id, String name, double price, String restaurant) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.restaurant = restaurant;
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
        return "Food  id=" + id + ", name=" + name + ", price=" + price + ", restaurant=" + restaurant;
    }
}
