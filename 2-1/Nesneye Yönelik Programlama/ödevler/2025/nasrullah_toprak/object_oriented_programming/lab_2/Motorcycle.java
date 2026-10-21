package nasrullahtoprak;

public class Motorcycle extends Vehicle {
    private int engineCC;
    private boolean hasSideCar;

    public Motorcycle(String brand, String model, int year, int engineCC, boolean hasSideCar, int serial){
        super(brand,model,year);
        this.engineCC=engineCC;
        this.hasSideCar=hasSideCar;
    }

    public String getTypeName(){
        return "Motorcycle";
    }

    protected String generateUniqueIdBody(int serial){
        String c = brand.toUpperCase();
        uniqueId="CAR-" + c.charAt(0) + c.charAt(1) + "-" + engineCC + "-" + serial;
        return uniqueId;
    }

    public int getEngineCC() {
        return engineCC;
    }

    public boolean hasSideCar() {
        return hasSideCar;
    }
}
