package javaapplication5;

public class KrediKart extends Kart {

    private double Limit;

    public KrediKart(int Id, String Sahip, double Bakiye, double Limit) {
        super(Id, Sahip, Bakiye);
        this.Limit = Limit;
    }

    public KrediKart(int Id, String Sahip, double Bakiye) {
        super(Id, Sahip, Bakiye);
        this.Limit = 1000;
    }

    public KrediKart(int Id, String Sahip) {
        super(Id, Sahip);
        this.Limit = 1000;
    }

    public double getLimit() {
        return Limit;
    }

    public void setLimit(double Limit) {
        this.Limit = Limit;
    }
    
        public boolean paraCek(double miktar){
        if (getBakiye() + getLimit() >= miktar)
        {
            setBakiye(getBakiye() - miktar);
            return true;
        }
        else
        {
            System.out.println("Bakiye ve Limit Yetersiz.");
            return false;
            
        }
        }
    
    
    @Override
    public boolean odemeYap(double miktar) {
        
        if (getBakiye() + getLimit() >= miktar)
        {
            paraCek(miktar);
            return true;
        }
        System.out.println("Ödeme Yapilamadi.");
        return false;
             
    }

    @Override
    public String toString() {
        return super.toString() + "KrediKart{" + "Limit=" + Limit + '}';
    }

    
    
}
