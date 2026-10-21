package uyg2;

public class KitaplıkYonetim {
    
    private Kitaplık kitaplık;

    public KitaplıkYonetim(Kitaplık kitaplık) {
        this.kitaplık = kitaplık;
    }
    
    public boolean kitapSat(Kitap ktp, Kart krt){
        int rafNo = kitaplık.kitapAra(ktp.getAd());
        
        if(rafNo == -1){
            System.out.println("Kitap Yok.");
            return false;
        }
        
        else if (krt.odemeYap(ktp.getFiyat())){            
            System.out.println("SatÄ±ÅŸ GerÃ§ekleÅŸti.");
            kitaplık.kitapSil(rafNo,ktp);
            return true;
        }
        
        else{            
            System.out.println("Bakiye Yetersiz.");
            return false;
        }
        
    }    
    
    
}
