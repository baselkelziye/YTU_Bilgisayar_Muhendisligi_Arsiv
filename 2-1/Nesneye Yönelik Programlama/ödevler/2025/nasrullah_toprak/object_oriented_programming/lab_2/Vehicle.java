package nasrullahtoprak;

public abstract class Vehicle {
    protected String brand;
    protected String model;
    protected int year;
    protected String uniqueId;
    protected boolean rented;

    public Vehicle(String brand, String model, int year){
        this.brand=brand;
        this.model=model;
        this.year=year;
    }

    protected abstract String generateUniqueIdBody(int serial);

    public String getUniqueId() {
        return uniqueId;
    }

    public boolean isRented() {
        return rented;
    }

    public boolean isAvailable(){
        if(isRented()) return false;
        return true;
    }

    public void rent(){
        if(rented){
            System.out.println("It is already rented");
        }
        System.out.println("It is rented");
        rented = true;
    }

    public void giveBack(){
        if(rented) rented=false;
        else{
            System.out.println("It is not already rented by anyone");
        }
    }

    public abstract String getTypeName();

    public String toString(){
        return "Brand: " + brand + " Model: " + model + " year " + year;
    }
}
