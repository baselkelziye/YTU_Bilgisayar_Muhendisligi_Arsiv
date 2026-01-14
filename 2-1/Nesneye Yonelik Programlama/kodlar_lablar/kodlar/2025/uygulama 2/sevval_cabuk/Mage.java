package Uyg2;

public class Mage extends Character {
    
    private int magicPower;
    private int healPower;
    
    public Mage(String name, int health, int magicPower, int healPower) {
        super(name, health);
        this.magicPower = magicPower;
        this.healPower = healPower;
    }


    
    public int getHealPower() {
		return healPower;
	}


	@Override
    public void attack(Character target) {
        System.out.println(getName() + " saldırıyor! (" + magicPower + " hasar)");
        target.defend(magicPower);
    }

    @Override
    public void defend(int damage) {
        System.out.println(getName() + " savunuyor. Alınan hasar: " + damage);
        reduceHealth(damage);
    }
    
    public void healAlly(Character ally) {
        System.out.println(getName() + " " + ally.getName() + " karakterini " + getHealPower() + " iyileştiriyor...");
        ally.heal(getHealPower());
    }

    // Overload
    public void healAlly(Character ally, int amount) {
        System.out.println(getName() + " özel bir iyileştirme yapıyor: " + ally.getName() + " +" + amount);
        ally.heal(amount);
    }
    
}
