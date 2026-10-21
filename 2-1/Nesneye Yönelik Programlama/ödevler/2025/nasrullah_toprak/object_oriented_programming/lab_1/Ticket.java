package nasrullahtoprak;

public class Ticket {
    private String departure;
    private String arrival;
    private String airlineCompany;
    private double price;

    public Ticket(String arrival, String departure, String airlineCompany, double price){
        this.departure=departure;
        this.arrival=arrival;
        this.airlineCompany=airlineCompany;
        this.price=price;
    }

    public String getDeparture() {
        return departure;
    }

    public String getArrival() {
        return arrival;
    }

    public String getAirlineCompany() {
        return airlineCompany;
    }

    public double getPrice() {
        return price;
    }
}
