package yazilim.classes;

public class VehicleStock {
    private int vehicleId;
    private int stock;

    public VehicleStock(int vehicleId, int stock) {
        this.vehicleId = vehicleId;
        this.stock = stock;
    }

    public int getVehicleId() {
        return vehicleId;
    }

    public int getStock() {
        return stock;
    }

    public void setVehicleId(int vehicleId) {
        this.vehicleId = vehicleId;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }
}
