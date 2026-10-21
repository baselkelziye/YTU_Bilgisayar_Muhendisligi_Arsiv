package nasrullahtoprak;

public class Filo {
    private final Vehicle[] vehicles;
    private int vehicleCount;
    private int serialCounter;

    public Filo(int capacity){
        this.vehicles = new Vehicle[capacity];
        this.vehicleCount=0;
        this.serialCounter=1000;
    }

    public void addVehicle(Vehicle v){
        if(vehicles.length==vehicleCount){
            System.out.println("UYARI: kapasite dolu " + v.getUniqueId());
            return;
        }
        vehicles[vehicleCount] = v;
        vehicleCount++;
    }

    public Car createCar(String brand, String model, int year, int doors, int trunkLiters){
        Car c = new Car(brand,model,year,doors,trunkLiters,serialCounter);
        c.generateUniqueIdBody(serialCounter);
        c.rented=false;
        serialCounter++;
        return c;
    }

    public Motorcycle createMotorcycle(String brand, String model, int year, int engineCC, boolean hasSideCar){
        Motorcycle m = new Motorcycle(brand,model,year,engineCC,hasSideCar,serialCounter);
        m.generateUniqueIdBody(serialCounter);
        m.rented=false;
        serialCounter++;
        return m;
    }

    public void printAllVehicles(){
        System.out.println("===FILO (Tumu)===");
        for(int i=0;i<vehicleCount;i++){
            System.out.print(vehicles[i].getTypeName() + "==>" + vehicles[i].toString() + " | " + vehicles[i].getUniqueId() + " | " + " Durum: " );
            if(!vehicles[i].isRented()) System.out.println("Musait");
            else System.out.println("Musait degil");
        }
    }

    public void printAvailable(){
        for(int i=0;i<vehicleCount;i++){
            if(!vehicles[i].isRented()){
                System.out.println(vehicles[i].getTypeName() + "==>" + vehicles[i].toString() + " | " + vehicles[i].getUniqueId() + " | " + " Durum: Musait" );
            }
        }
    }

    public void printAvailableByType(String typeName){
        for(int i=0;i<vehicleCount;i++){
            if(!vehicles[i].isRented() && vehicles[i].getTypeName().equalsIgnoreCase(typeName)){
                System.out.println(vehicles[i].getTypeName() + "==>" + vehicles[i].toString() + " | " + vehicles[i].getUniqueId() + " | " + " Durum: Musait" );
            }
        }
    }

    public Vehicle findById(String id){
        for(int i=0;i<vehicleCount;i++){
            if(vehicles[i].getUniqueId().equalsIgnoreCase(id)){
                return vehicles[i];
            }
        }
        return null;
    }

    public boolean rentById(String id){
        for(int i=0;i<vehicleCount;i++){
            if(vehicles[i].getUniqueId().equalsIgnoreCase(id) && !vehicles[i].rented){
                vehicles[i].rented=true;
                System.out.println(id + " kiralandi");
                return true;
            }
        }
        return false;
    }

    public boolean returnById(String id){
        for(int i=0;i<vehicleCount;i++){
            if(vehicles[i].getUniqueId().equalsIgnoreCase(id) && vehicles[i].rented){
                vehicles[i].rented=false;
                System.out.println(id + " iade edildi");
                return false;
            }
        }
        return true;
    }
}
