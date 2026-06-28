
package javaapplication5;

public class BankKart extends Kart {

    public BankKart(int Id, String Sahip, double Bakiye) {
        super(Id, Sahip, Bakiye);
    }

    public BankKart(int Id, String Sahip) {
        super(Id, Sahip);
    }
    
    
    
    
    public boolean odemeYap(double miktar) {
        if (getBakiye() >= miktar)
        {
            paraCek(miktar);
            return true;
        }
        else{
            System.out.println("Ödeme Yapilamadi.");
            return false;
        }
    }

//    @Override
//    public boolean odemeYap(double miktar) {
//        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
//    }

    
    
    
    
}
