public class Filo {
    private final Vehicle[] vehicles;
    private int vehicleCount;
    private int serialCounter;

    public Filo(int capacity) {
        vehicles = new Vehicle[capacity];
        vehicleCount = 0;
        serialCounter = 0;
    }

    public void addVehicle(Vehicle v) {
        if (vehicleCount == vehicles.length) {
            System.out.println("Full");
            return;
        }
        vehicles[vehicleCount] = v;
        vehicleCount++;
    }

    public Car createCar(String brand, String model, int year, int doors, double trunkLiters) {
        Car car =  new Car(brand, model, year, doors, trunkLiters, serialCounter);
        serialCounter++;
        return car;
    }

    public Motorcycle createMotorcycle(String brand, String model, int year, int engineCC, boolean hasSideCar) {
        Motorcycle moto = new Motorcycle(brand, model, year, engineCC, hasSideCar, serialCounter);
        serialCounter++;
        return moto;
    }

    public void printAllVehicles() {
        for (Vehicle v : vehicles) {
            System.out.println(v);
        }
    }

    public void printAvailable() {
        for (Vehicle v : vehicles) {
            if(v.isAvailable()) {
                System.out.println(v);
            }
        }
    }

    public void printAvailableByType(String typeName) {
        for (Vehicle v : vehicles) {
            if(v.getTypeName().equals(typeName) && v.isAvailable()) {
                System.out.println(v);
            }
        }
    }

    public Vehicle findByID(String id) {
        for (Vehicle v : vehicles) {
            if (v.getUniqueId().equals(id)) {
                return v;
            }
        }
        return null;
    }

    public boolean rentById(String id) {
        for (Vehicle v : vehicles) {
            if (v.getUniqueId().equals(id)) {
                v.rent();
                return true;
            }
        }
        return false;
    }

    public boolean returnById(String id) {
        for (Vehicle v : vehicles) {
            if (v.getUniqueId().equals(id)) {
                v.giveBack();
                return true;
            }
        }
        return false;
    }
}
