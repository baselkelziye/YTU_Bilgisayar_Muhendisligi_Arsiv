package javaapplication5;

public class GencKart extends BankKart {

    private double Bonus;

    public GencKart(int Id, String Sahip, double Bakiye) {
        super(Id, Sahip, Bakiye);
        this.Bonus = 0;
    }

    public GencKart(int Id, String Sahip) {
        super(Id, Sahip);
        this.Bonus = 0;
    }

    public double getBonus() {
        return Bonus;
    }

    public void setBonus(double Bonus) {
        this.Bonus = Bonus;
    }

    public boolean odemeYap(double miktar) {
        if (getBakiye() >= miktar) {
            paraCek(miktar);
            setBonus(getBonus() + miktar * 0.10);
            return true;
        } else if (getBonus() >= miktar) {
            setBonus(getBonus() - miktar);
            return true;
        } else {
            System.out.println("Ödeme Yapilamadi.");
            return false;
        }
    }

    @Override
    public String toString() {
        return super.toString() + "GencKart{" + "Bonus=" + Bonus + '}';
    }
    
    

}
