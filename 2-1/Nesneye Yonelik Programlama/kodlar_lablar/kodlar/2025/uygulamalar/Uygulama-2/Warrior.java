package Uyg2;

public class Warrior extends Character {
    
    private int damage;

    public Warrior(String name, int health, int damage) {
        super(name, health);
        this.damage = damage;
    }

    @Override
    public void attack(Character target) {
        System.out.println(getName() + " bir saldırı yapıyor! (" + damage + " hasar)");
        target.defend(damage);
    }

    public void attack(Character target, int multiplier) {
        int totalDamage = damage * multiplier;
        System.out.println(getName() + " güçlü bir saldırı yaptı! (x" + multiplier + " güç, " + totalDamage + " hasar)");
        target.defend(totalDamage);
    }
    
    @Override
    public void defend(int damage) {
        int reducedDamage = damage / 2;
        System.out.println(getName() + " savundu. Alınan hasar: " + reducedDamage);
        reduceHealth(reducedDamage);
    }


 
}