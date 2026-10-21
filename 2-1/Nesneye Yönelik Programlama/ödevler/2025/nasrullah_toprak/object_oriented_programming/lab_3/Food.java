package nasrullahtoprak;

public class Food implements Seliable{
    private String id;
    private String name;
    private double price;
    private String restaurant;

    public Food(String id, String name, double price, String restaurant){
        this.name=name;
        this.id=id;
        this.price=price;
        this.restaurant=restaurant;
    }

    @Override
    public String getId() {
        return id;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public double getPrice() {
        return price;
    }

    public String toString() {
        return "Food  [id= " + id + ", name= " + name + ", price=" + price + ", restaurant= " + restaurant + "]";
    }
}
