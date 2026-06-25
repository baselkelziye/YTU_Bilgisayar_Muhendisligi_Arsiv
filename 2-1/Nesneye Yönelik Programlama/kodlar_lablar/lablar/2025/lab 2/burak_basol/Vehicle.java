public abstract class Vehicle {
    protected String brand;
    protected String model;
    protected int year;
    protected String uniqueId;
    protected boolean rented;

    public Vehicle(String brand, String model, int year) {
        this.brand = brand;
        this.model = model;
        this.year = year;
    }

    protected abstract String generateUniqueIdBody(int serial);

    public String getUniqueId() {
        return uniqueId;
    }

    public void setUniqueId(String uniqueId) {
        this.uniqueId = uniqueId;
    }

    public boolean isRented() {
        return rented;
    }

    public boolean isAvailable() {
        return !rented;
    }

    public void rent() {
        this.rented = true;
    }

    public void giveBack() {
        this.rented = false;
    }

    public abstract String getTypeName();

    public String toString() {
        return brand + " " + model + " " + year + " " + uniqueId + (isAvailable() ? " Müsait" : " Müsait Değil");
    }
}
