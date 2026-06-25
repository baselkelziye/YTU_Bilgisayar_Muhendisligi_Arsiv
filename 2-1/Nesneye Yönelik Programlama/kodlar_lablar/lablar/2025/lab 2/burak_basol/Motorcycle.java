public class Motorcycle extends Vehicle {
    private int engineCC;
    private boolean hasSidecar;

    public Motorcycle(String brand, String model, int year, int engineCC, boolean hasSidecar, int serial) {
        super(brand, model, year);
        this.engineCC = engineCC;
        this.hasSidecar = hasSidecar;
        this.uniqueId = generateUniqueIdBody(serial);
    }

    protected String generateUniqueIdBody(int serial) {
        return "MOTO-" + this.brand.toUpperCase() + "-" + this.engineCC + "-" + (serial + 1000);
    }

    public String getTypeName() {
        return "Motorcycle";
    }

    public int getEngineCC() {
        return engineCC;
    }

    public boolean hasSidecar() {
        return hasSidecar;
    }

}
