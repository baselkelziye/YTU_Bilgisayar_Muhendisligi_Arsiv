package mertguler;

import java.io.Serializable;

public class Team  implements Runnable, Serializable {
    private String name;
    private Mage mage;
    private Warrior warrior;
    private Rogue rogue;
    private int totalPower;

    public Team(String name, Mage mage, Warrior warrior, Rogue rogue) {
        this.name = name;
        this.mage = mage;
        this.warrior = warrior;
        this.rogue = rogue;
        totalPower = 0;
    }

    // Belirtilmedigi icin Team classini runnable yaptim
    public void run(){
        calculateTotalPower();
    }

    // Bu fonksiyonun Integer dondurmesi istendi neden bilmiyorum herhangi bir return kullanimi yok.
    public Integer calculateTotalPower() {
        totalPower = mage.calculatePower() + warrior.calculatePower() + rogue.calculatePower();
        return totalPower;
    }

    public String getName() {
        return name;
    }


    public Mage getMage() {
        return mage;
    }


    public Warrior getWarrior() {
        return warrior;
    }


    public Rogue getRogue() {
        return rogue;
    }

    public int getTotalPower() {
        return totalPower;
    }

    @Override
    public String toString() {
        return name + ": " + totalPower;
    }
}
