package mertguler;

import java.io.Serializable;

public abstract class Character implements Serializable {
    // final olabilir fakat umlde belirtilmemis
    private int intelligence;
    private String name;
    private int strength;
    private int dexterity;

    public Character(String name,int intelligence, int strength, int dexterity) {
        this.intelligence = intelligence;
        this.name = name;
        this.strength = strength;
        this.dexterity = dexterity;
    }

    public abstract int calculatePower();

    public int getIntelligence() {
        return intelligence;
    }

    public int getStrength() {
        return strength;
    }

    public int getDexterity() {
        return dexterity;
    }

}
