repackage javaapplication5;

public abstract class Kart {
    private int Id;
    private String Sahip;
    private double Bakiye;

    public Kart(int Id, String Sahip, double Bakiye) {
        this.Id = Id;
        this.Sahip = Sahip;
        this.Bakiye = Bakiye;
    }
    
    public Kart(int Id, String Sahip) {
        this.Id = Id;
        this.Sahip = Sahip;
        this.Bakiye = 0;
    }

    public int getId() {
        return Id;
    }

    public void setId(int Id) {
        this.Id = Id;
    }

    public String getSahip() {
        return Sahip;
    }

    public void setSahip(String Sahip) {
        this.Sahip = Sahip;
    }

    public double getBakiye() {
        return Bakiye;
    }

    public void setBakiye(double Bakiye) {
        this.Bakiye = Bakiye;
    }
    
    public void paraYatir(double miktar){
        setBakiye(getBakiye() + miktar);
    }
    
    public boolean paraCek(double miktar){
        if (getBakiye() >= miktar)
        {
            setBakiye(getBakiye() - miktar);
            return true;
        }
        else
        {
//            System.out.println("Bakiye Yetersiz.");
            return false;
            
        }
    }
    
    public boolean paraGonder(Kart diger, double miktar)
    {
        if (paraCek(miktar))
        {
            diger.paraYatir(miktar);
            return true;
        }
        else
        {
            return false;
        }
        
    }

    @Override
    public String toString() {
        return "Kart{" + "Id=" + Id + ", Sahip=" + Sahip + ", Bakiye=" + Bakiye + '}';
    }
    
    
    public abstract boolean odemeYap(double miktar);
    
    
}
