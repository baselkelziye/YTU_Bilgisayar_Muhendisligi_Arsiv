package uyg2;

public class OgrenciKartı extends Kart {
    
    private double bonus;

    public OgrenciKartı(int id, String Sahip, double Bakiye) {
        super(id, Sahip, Bakiye);
        this.bonus = 0;
    }
    
    @Override
    public boolean odemeYap(double fiyat){
        if(getBakiye() >= fiyat){
            setBakiye(getBakiye() - fiyat);
            bonus += fiyat * 0.2;
            return true;
        }        
        else if (getBonus() >= fiyat){
            System.out.println("Bonuslar ile Ã¶deme gerÃ§ekleÅŸti.");
            setBonus(getBonus() - fiyat);
            return true;
        }
        return false;
    }
    
    public double getBonus() {
        return bonus;
    }

    public void setBonus(double bonus) {
        this.bonus = bonus;
    }

	@Override
	public String toString() {
		return super.toString() + "OgrenciKartı [bonus=" + bonus + "]";
	}

	

    }


    
    
    

