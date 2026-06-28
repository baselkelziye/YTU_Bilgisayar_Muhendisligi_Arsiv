package Uyg2;

public class Mage extends Character {
    private int magePower;
    private int healPower;

    public Mage(String name, int health, int damage) {
        super(name, health);
        this.magePower = damage;
        this.healPower = health;
    }

    public int getHealPower() {
        return healPower;
    }

    @Override
    public void attack(Character target) {
        target.defend(magePower);
    }

    @Override
    public void defend(int damage) {
        reduceHealth(damage);
    }

    public void healAlly(Character ally) {
        ally.heal(getHealPower());
    }

    public void healAlly(Character ally, int amount) {

    }
}
