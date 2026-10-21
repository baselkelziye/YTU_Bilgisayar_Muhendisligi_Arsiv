package nasrullahtoprak;

public class Drink implements Seliable{
    private String id;
    private String name;
    private double price;
    private String size;

    public Drink(String id, String name, double price, String size){
        this.name=name;
        this.id=id;
        this.price=price;
        this.size=size;
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
        return "Drink [id= " + id + ", name= " + name + ", price=" + price + ", size= " + size + "]";
    }
}
