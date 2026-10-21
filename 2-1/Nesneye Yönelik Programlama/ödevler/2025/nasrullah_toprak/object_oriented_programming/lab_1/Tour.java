package nasrullahtoprak;

public class Tour {
    private String tourName;
    private String city;
    private double price;

    public Tour(String tourName, String city, double price){
        this.tourName=tourName;
        this.city=city;
        this.price=price;
    }

    public String getTourName() {
        return tourName;
    }

    public String getCity() {
        return city;
    }

    public double getPrice() {
        return price;
    }
}
