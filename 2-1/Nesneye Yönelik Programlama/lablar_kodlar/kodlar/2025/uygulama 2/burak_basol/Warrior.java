package Uyg2;

public class Warrior extends Character {
    private int damage;

    public Warrior(String name, int health, int damage) {
        super(name, health);
        this.damage = damage;
    }

    @Override
    public void attack(Character target) {

    }

    public void attack(Character target, int multiplier) {

    }

    @Override
    public void defend(int damage) {

    }
}
