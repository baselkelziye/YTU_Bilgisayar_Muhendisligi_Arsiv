package nasrullahtoprak;

public class Car extends Vehicle {
    private int doors;
    private double trunkLiters;

    public Car(String brand, String model, int year, int doors, int trunkLiters, int serial){
        super(brand,model,year);
        this.doors=doors;
        this.trunkLiters=trunkLiters;
    }

    protected String generateUniqueIdBody(int serial){
        String c = brand.toUpperCase();
        uniqueId="CAR-" + c.charAt(0) + c.charAt(1) + c.charAt(2) + "-" + year + "-" + serial;
        return uniqueId;
    }

    public String getTypeName(){
        return "Car";
    }

    public int getDoors() {
        return doors;
    }

    public double getTrunkLiters() {
        return trunkLiters;
    }
}
