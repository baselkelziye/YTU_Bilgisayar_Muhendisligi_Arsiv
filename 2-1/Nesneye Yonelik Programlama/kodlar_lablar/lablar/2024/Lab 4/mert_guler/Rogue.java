package mertguler;

public class Rogue extends Character {
    public Rogue(String name, int intelligence, int strength, int dexterity) {
        super(name, intelligence, strength, dexterity);
    }

    @Override
    public int calculatePower(){
        return 5 * getDexterity() + 2 * getStrength() + 2 * getIntelligence();
    }
}
